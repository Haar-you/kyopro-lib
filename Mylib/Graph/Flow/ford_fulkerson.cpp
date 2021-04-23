#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

namespace haar_lib {
  namespace ford_fulkerson_impl {
    template <typename T>
    struct edge {
      int from, to, rev;
      T cap;
      bool is_rev;
      edge(int from, int to, int rev, T cap, bool is_rev) : from(from), to(to), rev(rev), cap(cap), is_rev(is_rev) {}
    };
  }  // namespace ford_fulkerson_impl

  template <typename T>
  class ford_fulkerson {
  public:
    using edge          = ford_fulkerson_impl::edge<T>;
    using capacity_type = T;

  private:
    int size_;
    std::vector<std::vector<edge>> g_;
    std::vector<bool> visit_;

    T dfs(int from, int to, T flow) {
      if (from == to) return flow;
      visit_[from] = true;

      for (auto &e : g_[from]) {
        if (not visit_[e.to] and e.cap > 0) {
          T d = dfs(e.to, to, std::min(flow, e.cap));
          if (d > 0) {
            e.cap -= d;
            g_[e.to][e.rev].cap += d;
            return d;
          }
        }
      }
      return 0;
    }

  public:
    ford_fulkerson() {}
    ford_fulkerson(int size) : size_(size), g_(size), visit_(size) {}

    void add_edge(int from, int to, T c) {
      assert(0 <= from and from < size_);
      assert(0 <= to and to < size_);
      g_[from].emplace_back(from, to, (int) g_[to].size(), c, false);
      g_[to].emplace_back(to, from, (int) g_[from].size() - 1, 0, true);
    }

    void reset_flow() {
      for (auto &v : g_) {
        for (auto &e : v) {
          if (e.is_rev) {
            g_[e.to][e.rev].cap += e.cap;
            e.cap = 0;
          }
        }
      }
    }

    T max_flow(int s, int t) {
      assert(0 <= s and s < size_);
      assert(0 <= t and t < size_);

      T ret = 0;

      while (1) {
        visit_.assign(size_, false);
        T flow = dfs(s, t, std::numeric_limits<T>::max());
        if (flow == 0) return ret;
        ret += flow;
      }
    }

    std::vector<edge> edges() const {
      std::vector<edge> ret;
      for (auto &v : g_) ret.insert(ret.end(), v.begin(), v.end());
      return ret;
    }
  };
}  // namespace haar_lib
