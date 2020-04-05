#pragma once
#include <vector>
#include <utility>
#include <climits>
#include <cassert>
#include "Mylib/Graph/Flow/ford_fulkerson.cpp"

/**
 * @title 二部マッチング
 */
class BipartiteMatching{
  int x, y;
  FordFulkerson<int> f;
  int s, t;
  
public:
  BipartiteMatching(int x, int y): x(x), y(y), f(x+y+2), s(x+y), t(s+1){
    for(int i = 0; i < x; ++i) f.add_edge(s,i,1);
    for(int i = 0; i < y; ++i) f.add_edge(x+i,t,1);
  }

  void add_edge(int i, int j){
    assert(0 <= i and i < x and 0 <= j and j < y);
    f.add_edge(i,x+j,1);
  }

  int solve(){
    return f.solve(s, t);
  }

  std::vector<std::pair<int,int>> get_matching_edges(){
    auto g = f.get_graph();
    std::vector<std::pair<int,int>> ret;

    for(int i = 0; i < (int)g.size()-2; ++i){
      for(const auto &e : g[i]){
        if((not e.is_rev) and e.cap == 0 and e.to != t) ret.emplace_back(i, e.to-x);
      }
    }

    return ret;
  }
};
