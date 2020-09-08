#pragma once
#include <vector>
#include <tuple>

/**
 * @title Weighted maximum bipartite matching
 * @docs weighted_bipartite_matching.md
 */
namespace haar_lib {
  template <typename T, typename MinCostFlow, bool MIN_MATCHING = false>
  class weighted_bipartite_matching {
  public:
    int L, R, s, t;
    MinCostFlow f;

    weighted_bipartite_matching(int L, int R, bool arbitrary_flow = false):
      L(L), R(R), s(L + R), t(s + 1), f(L + R + 2)
    {
      for(int i = 0; i < L; ++i) f.add_edge(s, i, 1, 0);
      for(int i = 0; i < R; ++i) f.add_edge(L + i, t, 1, 0);
      if(arbitrary_flow) f.add_edge(s, t, std::numeric_limits<int>::max(), 0);
    }

    void add_edge(int from, int to, T gain){
      f.add_edge(from, L + to, 1, gain * (MIN_MATCHING ? 1 : -1));
    }

    T solve(int flow){
      T ret;
      f.solve(s, t, flow, ret);
      return ret * (MIN_MATCHING ? 1 : -1);
    }

    auto get_matching(){
      auto g = f.get_graph();
      std::vector<std::tuple<int, int, T>> ret;

      for(int i = 0; i < L; ++i){
        for(auto &e : g[i]){
          if(not e.is_rev and e.to != t and e.cap == 0){
            ret.emplace_back(i, e.to - L, e.cost * (MIN_MATCHING ? 1 : -1));
          }
        }
      }

      return ret;
    }
  };
}
