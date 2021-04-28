---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\n#include\
    \ <optional>\n#include <queue>\n#include <vector>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\
    \n#include <iostream>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct edge {\n    int from, to;\n  \
    \  T cost;\n    int index = -1;\n    edge() {}\n    edge(int from, int to, T cost)\
    \ : from(from), to(to), cost(cost) {}\n    edge(int from, int to, T cost, int\
    \ index) : from(from), to(to), cost(cost), index(index) {}\n  };\n\n  template\
    \ <typename T>\n  struct graph {\n    using weight_type = T;\n    using edge_type\
    \   = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n    auto& operator[](size_t\
    \ i) { return data[i]; }\n    const auto& operator[](size_t i) const { return\
    \ data[i]; }\n\n    auto begin() const { return data.begin(); }\n    auto end()\
    \ const { return data.end(); }\n\n    graph() {}\n    graph(int N) : data(N) {}\n\
    \n    bool empty() const { return data.empty(); }\n    int size() const { return\
    \ data.size(); }\n\n    void add_edge(int i, int j, T w, int index = -1) {\n \
    \     data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1) {\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M) {\n      for (int i = 0; i < M; ++i) {\n     \
    \   int u, v;\n        std::cin >> u >> v;\n        u -= I;\n        v -= I;\n\
    \        T w = 1;\n        if (WEIGHTED) std::cin >> w;\n        if (DIRECTED)\n\
    \          add_edge(u, v, w, i);\n        else\n          add_undirected(u, v,\
    \ w, i);\n      }\n    }\n  };\n\n  template <typename T>\n  using tree = graph<T>;\n\
    }  // namespace haar_lib\n#line 6 \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<std::vector<int>>\
    \ topological_sort(const graph<T> &g) {\n    const int n = g.size();\n    std::vector<int>\
    \ indeg(n);\n\n    for (int i = 0; i < n; ++i) {\n      for (auto &e : g[i]) {\n\
    \        ++indeg[e.to];\n      }\n    }\n\n    std::queue<int> q;\n    for (int\
    \ i = 0; i < n; ++i) {\n      if (indeg[i] == 0) q.push(i);\n    }\n\n    std::vector<int>\
    \ ret;\n    while (not q.empty()) {\n      int cur = q.front();\n      q.pop();\n\
    \      ret.push_back(cur);\n      for (auto &e : g[cur]) {\n        --indeg[e.to];\n\
    \        if (indeg[e.to] == 0) {\n          q.push(e.to);\n        }\n      }\n\
    \    }\n\n    if ((int) ret.size() == n) {\n      return {ret};\n    } else {\n\
    \      return std::nullopt;\n    }\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <optional>\n#include <queue>\n#include <vector>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::optional<std::vector<int>> topological_sort(const graph<T>\
    \ &g) {\n    const int n = g.size();\n    std::vector<int> indeg(n);\n\n    for\
    \ (int i = 0; i < n; ++i) {\n      for (auto &e : g[i]) {\n        ++indeg[e.to];\n\
    \      }\n    }\n\n    std::queue<int> q;\n    for (int i = 0; i < n; ++i) {\n\
    \      if (indeg[i] == 0) q.push(i);\n    }\n\n    std::vector<int> ret;\n   \
    \ while (not q.empty()) {\n      int cur = q.front();\n      q.pop();\n      ret.push_back(cur);\n\
    \      for (auto &e : g[cur]) {\n        --indeg[e.to];\n        if (indeg[e.to]\
    \ == 0) {\n          q.push(e.to);\n        }\n      }\n    }\n\n    if ((int)\
    \ ret.size() == n) {\n      return {ret};\n    } else {\n      return std::nullopt;\n\
    \    }\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TopologicalSort/topological_sort.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/TopologicalSort/topological_sort.cpp
layout: document
title: Topological sort
---

## Operations

## Requirements

## Notes

## Problems

## References
