---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_12_B/main.dial.test.cpp
    title: test/aoj/ALDS1_12_B/main.dial.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/ShortestPath/dial_algorithm.cpp\"\n#include\
    \ <optional>\n#include <stack>\n#include <vector>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\
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
    }  // namespace haar_lib\n#line 6 \"Mylib/Graph/ShortestPath/dial_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  auto dial_algorithm(const graph<int> &g, std::vector<int>\
    \ src, int MAX) {\n    const int N = g.size();\n    std::vector<std::stack<int>>\
    \ buckets(MAX + 1);\n    std::vector<std::optional<int>> ret(N);\n    std::vector<bool>\
    \ check(N);\n\n    for (int i : src) {\n      ret[i] = 0;\n      buckets[0].push(i);\n\
    \    }\n\n    for (int i = 0; i <= MAX; ++i) {\n      while (not buckets[i].empty())\
    \ {\n        int cur = buckets[i].top();\n        buckets[i].pop();\n\n      \
    \  if (check[cur]) continue;\n        check[cur] = true;\n\n        for (auto\
    \ &e : g[cur]) {\n          if (not ret[e.to] or *ret[cur] + e.cost < *ret[e.to])\
    \ {\n            ret[e.to] = *ret[cur] + e.cost;\n            buckets[*ret[e.to]\
    \ % (MAX + 1)].push(e.to);\n          }\n        }\n      }\n    }\n\n    return\
    \ ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <optional>\n#include <stack>\n#include <vector>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  auto dial_algorithm(const\
    \ graph<int> &g, std::vector<int> src, int MAX) {\n    const int N = g.size();\n\
    \    std::vector<std::stack<int>> buckets(MAX + 1);\n    std::vector<std::optional<int>>\
    \ ret(N);\n    std::vector<bool> check(N);\n\n    for (int i : src) {\n      ret[i]\
    \ = 0;\n      buckets[0].push(i);\n    }\n\n    for (int i = 0; i <= MAX; ++i)\
    \ {\n      while (not buckets[i].empty()) {\n        int cur = buckets[i].top();\n\
    \        buckets[i].pop();\n\n        if (check[cur]) continue;\n        check[cur]\
    \ = true;\n\n        for (auto &e : g[cur]) {\n          if (not ret[e.to] or\
    \ *ret[cur] + e.cost < *ret[e.to]) {\n            ret[e.to] = *ret[cur] + e.cost;\n\
    \            buckets[*ret[e.to] % (MAX + 1)].push(e.to);\n          }\n      \
    \  }\n      }\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/ShortestPath/dial_algorithm.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_12_B/main.dial.test.cpp
documentation_of: Mylib/Graph/ShortestPath/dial_algorithm.cpp
layout: document
title: Dial's algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References