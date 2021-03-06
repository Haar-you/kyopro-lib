#pragma once
#include <optional>
#include <queue>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  std::vector<std::optional<int64_t>> bfs_shortest_path(const graph<T> &g, const std::vector<int> &src) {
    const int n = g.size();
    std::vector<std::optional<int64_t>> ret(n, std::nullopt);
    std::vector<bool> visited(n);
    std::queue<int> q;

    for (auto s : src) {
      ret[s] = 0;
      q.push(s);
    }

    while (not q.empty()) {
      const int cur = q.front();
      q.pop();

      if (visited[cur]) continue;
      visited[cur] = true;

      for (auto &e : g[cur]) {
        if (not ret[e.to] or *ret[e.to] > *ret[e.from] + 1) {
          ret[e.to] = *ret[e.from] + 1;
          q.push(e.to);
        }
      }
    }

    return ret;
  }
}  // namespace haar_lib
