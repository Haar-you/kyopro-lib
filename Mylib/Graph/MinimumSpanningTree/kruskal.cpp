#pragma once
#include <algorithm>
#include <vector>
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include "Mylib/Graph/Template/graph.cpp"

namespace haar_lib {
  template <typename T>
  std::vector<edge<T>> kruskal(const graph<T> &graph) {
    const int n = graph.size();
    std::vector<edge<T>> edges;
    for (auto &v : graph) {
      for (auto &e : v) {
        edges.push_back(e);
      }
    }

    std::sort(
        edges.begin(), edges.end(),
        [](const auto &a, const auto &b) { return a.cost < b.cost; });

    unionfind uf(n);

    std::vector<edge<T>> ret;

    for (auto &e : edges) {
      if (not uf.is_same(e.from, e.to)) {
        uf.merge(e.from, e.to);
        ret.push_back(e);
      }
    }

    return ret;
  }
}  // namespace haar_lib
