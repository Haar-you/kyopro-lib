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
  bundledCode: "#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  struct edge\
    \ {\n    int from, to;\n    T cost;\n    int index = -1;\n    edge() {}\n    edge(int\
    \ from, int to, T cost) : from(from), to(to), cost(cost) {}\n    edge(int from,\
    \ int to, T cost, int index) : from(from), to(to), cost(cost), index(index) {}\n\
    \  };\n\n  template <typename T>\n  struct graph {\n    using weight_type = T;\n\
    \    using edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\
    \n    auto& operator[](size_t i) { return data[i]; }\n    const auto& operator[](size_t\
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
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 3 \"\
    Mylib/Graph/TreeUtils/rooting.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  void rooting(tree<T> &tr, int cur, int par = -1) {\n    if (par != -1)\
    \ {\n      for (auto it = tr[cur].begin(); it != tr[cur].end(); ++it) {\n    \
    \    if (it->to == par) {\n          tr[cur].erase(it);\n          break;\n  \
    \      }\n      }\n    }\n\n    for (auto &e : tr[cur]) {\n      rooting(tr, e.to,\
    \ cur);\n    }\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  void rooting(tree<T> &tr, int cur, int par = -1)\
    \ {\n    if (par != -1) {\n      for (auto it = tr[cur].begin(); it != tr[cur].end();\
    \ ++it) {\n        if (it->to == par) {\n          tr[cur].erase(it);\n      \
    \    break;\n        }\n      }\n    }\n\n    for (auto &e : tr[cur]) {\n    \
    \  rooting(tr, e.to, cur);\n    }\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/rooting.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/TreeUtils/rooting.cpp
layout: document
title: Rooting
---

## Operations

## Requirements

## Notes

## Problems

## References
