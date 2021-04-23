#pragma once
#include <optional>
#include <queue>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  std::optional<std::vector<int>> topological_sort_lexicographical(const graph<T> &g) {
    const int n = g.size();
    std::vector<int> indeg(n);

    for (int i = 0; i < n; ++i) {
      for (auto &e : g[i]) {
        ++indeg[e.to];
      }
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int i = 0; i < n; ++i) {
      if (indeg[i] == 0) q.push(i);
    }

    std::vector<int> ret;
    while (not q.empty()) {
      int cur = q.top();
      q.pop();
      ret.push_back(cur);
      for (auto &e : g[cur]) {
        --indeg[e.to];
        if (indeg[e.to] == 0) {
          q.push(e.to);
        }
      }
    }

    if ((int) ret.size() == n) {
      return {ret};
    } else {
      return std::nullopt;
    }
  }
}  // namespace haar_lib
