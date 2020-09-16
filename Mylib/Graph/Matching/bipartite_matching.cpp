#pragma once
#include <vector>
#include <utility>
#include <climits>
#include <cassert>

namespace haar_lib {
  template <typename MaxFlow>
  class bipartite_matching {
    int L, R, s, t;
    MaxFlow f;

  public:
    bipartite_matching(int L, int R): L(L), R(R), s(L + R), t(s + 1), f(L + R + 2){
      for(int i = 0; i < L; ++i) f.add_edge(s, i, 1);
      for(int i = 0; i < R; ++i) f.add_edge(L + i, t, 1);
    }

    void add_edge(int i, int j){
      assert(0 <= i and i < L and 0 <= j and j < R);
      f.add_edge(i, L + j, 1);
    }

    int solve(){
      return f.solve(s, t);
    }

    auto get_matching(){
      const auto g = f.edges();
      std::vector<std::pair<int, int>> ret;

      for(auto &e : g){
        if(not e.is_rev and e.cap == 0 and e.from != s and e.to != t){
          ret.emplace_back(e.from, e.to - L);
        }
      }

      return ret;
    }
  };
}
