#pragma once
#include <vector>
#include <optional>
#include <queue>
#include "Mylib/Graph/graph_template.cpp"

/**
 * @title BFS shortest path
 * @docs bfs_shortest_path.md
 */
template <typename T>
std::vector<std::optional<int>> bfs_shortest_path(const Graph<T> &g, const std::vector<int> &src){
  const int n = g.size();
  std::vector<std::optional<int>> ret(n, std::nullopt);
  std::vector<bool> visited(n);
  std::queue<int> q;

  for(auto s : src){
    ret[s] = 0;
    q.push(s);
  }

  while(not q.empty()){
    const int cur = q.front(); q.pop();

    if(visited[cur]) continue;
    visited[cur] = true;

    for(auto &e : g[cur]){
      if(not ret[e.to] or *ret[e.to] > *ret[e.from] + 1){
        ret[e.to] = *ret[e.from] + 1;
        q.push(e.to);
      }
    }
  }

  return ret;
}
