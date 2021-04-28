---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_2_A/main.kruskal.test.cpp
    title: test/aoj/GRL_2_A/main.kruskal.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/manhattanmst/main.test.cpp
    title: test/yosupo-judge/manhattanmst/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\n#include\
    \ <algorithm>\n#include <vector>\n#line 3 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
    \n#include <numeric>\n#line 5 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n\
    \nnamespace haar_lib {\n  class unionfind {\n    int n_, count_;\n    mutable\
    \ std::vector<int> parent_;\n    std::vector<int> depth_, size_;\n\n  public:\n\
    \    unionfind() {}\n    unionfind(int n) : n_(n), count_(n), parent_(n), depth_(n,\
    \ 1), size_(n, 1) {\n      std::iota(parent_.begin(), parent_.end(), 0);\n   \
    \ }\n\n    int root_of(int i) const {\n      if (parent_[i] == i)\n        return\
    \ i;\n      else\n        return parent_[i] = root_of(parent_[i]);\n    }\n\n\
    \    bool is_same(int i, int j) const { return root_of(i) == root_of(j); }\n\n\
    \    int merge(int i, int j) {\n      const int ri = root_of(i), rj = root_of(j);\n\
    \      if (ri == rj)\n        return ri;\n      else {\n        --count_;\n  \
    \      if (depth_[ri] < depth_[rj]) {\n          parent_[ri] = rj;\n         \
    \ size_[rj] += size_[ri];\n          return rj;\n        } else {\n          parent_[rj]\
    \ = ri;\n          size_[ri] += size_[rj];\n          if (depth_[ri] == depth_[rj])\
    \ ++depth_[ri];\n          return ri;\n        }\n      }\n    }\n\n    int size_of(int\
    \ i) const { return size_[root_of(i)]; }\n\n    int count_groups() const { return\
    \ count_; }\n\n    auto get_groups() const {\n      std::vector<std::vector<int>>\
    \ ret(n_);\n\n      for (int i = 0; i < n_; ++i) {\n        ret[root_of(i)].push_back(i);\n\
    \      }\n\n      ret.erase(\n          std::remove_if(\n              ret.begin(),\
    \ ret.end(),\n              [](const auto &a) { return a.empty(); }),\n      \
    \    ret.end());\n\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n\
    #line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge() {}\n    edge(int from, int\
    \ to, T cost) : from(from), to(to), cost(cost) {}\n    edge(int from, int to,\
    \ T cost, int index) : from(from), to(to), cost(cost), index(index) {}\n  };\n\
    \n  template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n  \
    \  auto& operator[](size_t i) { return data[i]; }\n    const auto& operator[](size_t\
    \ i) const { return data[i]; }\n\n    auto begin() const { return data.begin();\
    \ }\n    auto end() const { return data.end(); }\n\n    graph() {}\n    graph(int\
    \ N) : data(N) {}\n\n    bool empty() const { return data.empty(); }\n    int\
    \ size() const { return data.size(); }\n\n    void add_edge(int i, int j, T w,\
    \ int index = -1) {\n      data[i].emplace_back(i, j, w, index);\n    }\n\n  \
    \  void add_undirected(int i, int j, T w, int index = -1) {\n      add_edge(i,\
    \ j, w, index);\n      add_edge(j, i, w, index);\n    }\n\n    template <size_t\
    \ I, bool DIRECTED = true, bool WEIGHTED = true>\n    void read(int M) {\n   \
    \   for (int i = 0; i < M; ++i) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n        u -= I;\n        v -= I;\n        T w = 1;\n        if (WEIGHTED)\
    \ std::cin >> w;\n        if (DIRECTED)\n          add_edge(u, v, w, i);\n   \
    \     else\n          add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 6 \"\
    Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<edge<T>> kruskal(const graph<T> &graph) {\n    const\
    \ int n = graph.size();\n    std::vector<edge<T>> edges;\n    for (auto &v : graph)\
    \ {\n      for (auto &e : v) {\n        edges.push_back(e);\n      }\n    }\n\n\
    \    std::sort(\n        edges.begin(), edges.end(),\n        [](const auto &a,\
    \ const auto &b) { return a.cost < b.cost; });\n\n    unionfind uf(n);\n\n   \
    \ std::vector<edge<T>> ret;\n\n    for (auto &e : edges) {\n      if (not uf.is_same(e.from,\
    \ e.to)) {\n        uf.merge(e.from, e.to);\n        ret.push_back(e);\n     \
    \ }\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
    \n#include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<edge<T>> kruskal(const graph<T> &graph) {\n    const\
    \ int n = graph.size();\n    std::vector<edge<T>> edges;\n    for (auto &v : graph)\
    \ {\n      for (auto &e : v) {\n        edges.push_back(e);\n      }\n    }\n\n\
    \    std::sort(\n        edges.begin(), edges.end(),\n        [](const auto &a,\
    \ const auto &b) { return a.cost < b.cost; });\n\n    unionfind uf(n);\n\n   \
    \ std::vector<edge<T>> ret;\n\n    for (auto &e : edges) {\n      if (not uf.is_same(e.from,\
    \ e.to)) {\n        uf.merge(e.from, e.to);\n        ret.push_back(e);\n     \
    \ }\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/MinimumSpanningTree/kruskal.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/manhattanmst/main.test.cpp
  - test/aoj/GRL_2_A/main.kruskal.test.cpp
documentation_of: Mylib/Graph/MinimumSpanningTree/kruskal.cpp
layout: document
title: Kruskal algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
