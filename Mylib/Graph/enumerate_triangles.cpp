#pragma once
#include <tuple>
#include <unordered_set>
#include <vector>
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  std::vector<std::tuple<int, int, int>> enumerate_triangles(const graph<T> &g) {
    const int N = g.size();
    std::vector<std::tuple<int, int, int>> ret;

    std::vector<std::unordered_set<int>> adjacent(N);

    for (int i = 0; i < N; ++i) {
      for (auto &e : g[i]) {
        if (g[e.from].size() < g[e.to].size()) {
          adjacent[e.from].insert(e.to);
        } else if (g[e.from].size() == g[e.to].size()) {
          if (e.from < e.to) {
            adjacent[e.from].insert(e.to);
          }
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int j : adjacent[i]) {
        for (int k : adjacent[j]) {
          if (adjacent[i].find(k) != adjacent[i].end()) {
            ret.emplace_back(i, j, k);
          }
        }
      }
    }

    return ret;
  }
}  // namespace haar_lib
