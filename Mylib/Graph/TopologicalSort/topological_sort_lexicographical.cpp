#pragma once
#include <vector>
#include <optional>
#include <queue>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title Topological sort (Lexicographically minimum)
 * @docs topological_sort_lexicographical.md
 */
template <typename T>
std::optional<std::vector<int>> topological_sort_lexicographical(const Graph<T> &g){
  const int n = g.size();
  std::vector<int> indeg(n);

  for(int i = 0; i < n; ++i){
    for(auto &e : g[i]){
      ++indeg[e.to];
    }
  }

  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  for(int i = 0; i < n; ++i){
    if(indeg[i] == 0) q.push(i);
  }

  std::vector<int> ret;
  while(not q.empty()){
    int cur = q.top(); q.pop();
    ret.push_back(cur);
    for(auto &e : g[cur]){
      --indeg[e.to];
      if(indeg[e.to] == 0){
        q.push(e.to);
      }
    }
  }

  if((int)ret.size() == n){
    return {ret};
  }else{
    return std::nullopt;
  }
}
