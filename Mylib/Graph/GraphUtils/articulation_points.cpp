#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title 間接点列挙
 * @docs articulation_points.md
 */
template <typename T> std::vector<int> articulation_points(const Graph<T> &graph){
  int n = graph.size();
  std::vector<int> visit(n, -1), low(n, -1), ret;

  int v = 0;
  
  auto dfs =
    [&](auto &&dfs, int cur){
      if(visit[cur] != -1) return visit[cur];
      visit[cur] = v;

      int temp = v;
      std::vector<int> children;
      ++v;

      for(auto &e : graph[cur]){
        if(visit[e.to] == -1) children.push_back(e.to);
        int t = dfs(dfs, e.to);
        temp = std::min(temp, t);
      }

      low[cur] = temp;

      if((cur != 0 or children.size() >= 2) and std::any_of(children.begin(), children.end(), [&](int x){return low[x] >= visit[cur];})){
        ret.push_back(cur);
      }

      return low[cur];
    };

  
  for(int i = 0; i < n; ++i){
    if(visit[i] == -1){
      dfs(dfs, i);
    }
  }

  return ret;
}
