#pragma once
#include <vector>
#include <tuple>
#include "Mylib/Graph/Flow/minimum_cost_flow.cpp"

/**
 * @title 重み付き二部マッチング
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2429
 */
template <typename T>
class WeightedBipartiteMatching{
public:
  const int left, right, s, t;
  MinimumCostFlow<int,T> f;
 
  WeightedBipartiteMatching(int left, int right):
    left(left), right(right), s(left+right), t(s+1), f(left+right+2)
  {
    for(int i = 0; i < left; ++i) f.add_edge(s, i, 1, 0);
    for(int i = 0; i < right; ++i) f.add_edge(left+i, t, 1, 0);
  }
 
  void add_edge(int from, int to, T cost){
    f.add_edge(from, left+to, 1, cost);
  }
 
  T solve(int flow){
    T ret;
    f.solve(s, t, flow, ret);
    return ret;
  }
 
  std::vector<std::tuple<int,int,T>> get_matching_edges(){
    auto g = f.get_graph();
    std::vector<std::tuple<int,int,T>> ret;
 
    for(int i = 0; i < left; ++i){
      for(auto &e : g[i]){
        if(not e.is_rev and e.to != t and e.cap == 0) ret.emplace_back(i, e.to-left, e.cost);
      }
    }
 
    return ret;
  }
};
