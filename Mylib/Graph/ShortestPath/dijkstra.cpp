#pragma once
#include <functional>
#include <optional>
#include <queue>
#include <utility>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  auto dijkstra(const graph<T> &graph, std::vector<int> src) {
    using P = std::pair<T, int>;

    const int n = graph.size();
    std::vector<std::optional<T>> dist(n);

    std::vector<bool> check(n, false);
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    for (auto s : src) {
      dist[s] = 0;
      pq.emplace(0, s);
    }

    while (not pq.empty()) {
      const auto [d, i] = pq.top();
      pq.pop();

      if (check[i]) continue;
      check[i] = true;

      for (auto &e : graph[i]) {
        if (not dist[e.to]) {
          dist[e.to] = d + e.cost;
          pq.emplace(*dist[e.to], e.to);
        } else {
          if (*dist[e.to] > d + e.cost) {
            dist[e.to] = d + e.cost;
            if (not check[e.to]) pq.emplace(*dist[e.to], e.to);
          }
        }
      }
    }

    return dist;
  }
}  // namespace haar_lib
