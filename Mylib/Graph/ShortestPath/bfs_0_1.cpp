#pragma once
#include <vector>
#include <deque>
#include <optional>
#include "Mylib/Graph/Template/graph.cpp"

/**
 * @title 0-1 BFS
 * @docs bfs_0_1.md
 */
namespace haar_lib {
  std::vector<std::optional<int64_t>> bfs_0_1(const Graph<int> &g, const std::vector<int> &src){
    const int n = g.size();
    std::vector<std::optional<int64_t>> ret(n);
    std::vector<bool> visited(n);

    for(auto i : src) ret[i] = 0;
    std::deque<int> dq(src.begin(), src.end());

    while(not dq.empty()){
      int cur = dq.front(); dq.pop_front();

      if(visited[cur]) continue;
      visited[cur] = true;

      for(auto &e : g[cur]){
        if(not ret[e.to] or *ret[e.to] > *ret[e.from] + e.cost){
          ret[e.to] = *ret[e.from] + e.cost;

          if(e.cost == 0) dq.push_front(e.to);
          else dq.push_back(e.to);
        }
      }
    }

    return ret;
  }
}
