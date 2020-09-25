#pragma once
#include <vector>
#include <optional>
#include <queue>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  std::optional<std::vector<std::optional<T>>> spfa(const graph<T> &g, int src){
    const int N = g.size();

    std::vector<std::optional<T>> dist(N);
    std::vector<bool> check(N);
    std::vector<int> count(N);
    std::queue<int> q;

    q.push(src);
    dist[src] = 0;
    check[src] = true;
    count[src] = 1;

    while(not q.empty()){
      auto cur = q.front(); q.pop();
      check[cur] = false;

      for(auto &e : g[cur]){
        if(not dist[e.to] or dist[cur].value() + e.cost < dist[e.to].value()){
          dist[e.to] = dist[cur].value() + e.cost;
          if(not check[e.to]){
            count[e.to] += 1;
            if(count[e.to] >= N) return std::nullopt;
            q.push(e.to);
          }
        }
      }
    }

    return dist;
  };
}
