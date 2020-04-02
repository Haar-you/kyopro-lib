#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 橋列挙
 */
template <typename T>
auto bridges(const Graph<T> &graph){
  const int n = graph.size();
  std::vector<int> visit(n,-1), low(n,-1);
  std::vector<Edge<T>> ret;
  int v = 0;
  auto dfs =
    [&](auto &dfs, int cur, int par) -> int{
      if(visit[cur] != -1) return visit[cur];
      visit[cur] = v;
      int temp = v;
      ++v;
      for(auto &e : graph[cur]){
        if(e.to == par) continue;
        int t = dfs(dfs, e.to, cur);
        temp = std::min(temp, t);
        if(low[e.to] > visit[cur]) ret.push_back(e);
      }  
      return low[cur] = temp;
    };

  for(int i = 0; i < n; ++i) if(visit[i] == -1) dfs(dfs, i, -1);
  return ret;
}
