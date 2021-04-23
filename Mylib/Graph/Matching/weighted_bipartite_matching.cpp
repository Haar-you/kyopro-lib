#pragma once
#include <cassert>
#include <tuple>
#include <vector>

namespace haar_lib {
  template <typename T, typename MinCostFlow, bool MIN_MATCHING = false>
  class weighted_bipartite_matching {
    int L_, R_, s_, t_;
    MinCostFlow f_;

  public:
    weighted_bipartite_matching() {}
    weighted_bipartite_matching(int L, int R, bool arbitrary_flow = false) : L_(L), R_(R), s_(L + R), t_(s_ + 1), f_(L + R + 2) {
      for (int i = 0; i < L_; ++i) f_.add_edge(s_, i, 1, 0);
      for (int i = 0; i < R_; ++i) f_.add_edge(L_ + i, t_, 1, 0);
      if (arbitrary_flow) f_.add_edge(s_, t_, std::numeric_limits<int>::max(), 0);
    }

    void add_edge(int from, int to, T gain) {
      assert(0 <= from and from < L_);
      assert(0 <= to and to < R_);
      f_.add_edge(from, L_ + to, 1, gain * (MIN_MATCHING ? 1 : -1));
    }

    T match(int flow) {
      T ret = f_.min_cost_flow(s_, t_, flow).second;
      return ret * (MIN_MATCHING ? 1 : -1);
    }

    auto get_matching() {
      const auto g = f_.edges();
      std::vector<std::tuple<int, int, T>> ret;

      for (auto &e : g) {
        if (not e.is_rev and e.from != s_ and e.to != t_ and e.cap == 0) {
          ret.emplace_back(e.from, e.to - L_, e.cost * (MIN_MATCHING ? 1 : -1));
        }
      }

      return ret;
    }
  };
}  // namespace haar_lib
