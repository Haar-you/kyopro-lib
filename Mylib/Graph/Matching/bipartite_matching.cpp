#pragma once
#include <vector>
#include <utility>
#include <climits>
#include <cassert>

/**
 * @title 最大二部マッチング
 * @docs bipartite_matching.md
 */
template <typename MaxFlow>
class BipartiteMatching{
  int L, R;
  int s, t;
  MaxFlow f;
  
public:
  BipartiteMatching(int L, int R): L(L), R(R), s(L+R), t(s+1), f(L+R+2){
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
    auto g = f.get_graph();
    std::vector<std::pair<int,int>> ret;

    for(int i = 0; i < (int)g.size()-2; ++i){
      for(const auto &e : g[i]){
        if((not e.is_rev) and e.cap == 0 and e.to != t) ret.emplace_back(i, e.to - L);
      }
    }

    return ret;
  }
};
