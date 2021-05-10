---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2891/main.test.cpp
    title: test/aoj/2891/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/GraphUtils/decompose_pseudotree.cpp\"\n#include\
    \ <queue>\n#include <vector>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include\
    \ <iostream>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n\
    \    int index = -1;\n    edge() {}\n    edge(int from, int to, T cost) : from(from),\
    \ to(to), cost(cost) {}\n    edge(int from, int to, T cost, int index) : from(from),\
    \ to(to), cost(cost), index(index) {}\n  };\n\n  template <typename T>\n  struct\
    \ graph {\n    using weight_type = T;\n    using edge_type   = edge<T>;\n\n  \
    \  std::vector<std::vector<edge<T>>> data;\n\n    auto& operator[](size_t i) {\
    \ return data[i]; }\n    const auto& operator[](size_t i) const { return data[i];\
    \ }\n\n    auto begin() const { return data.begin(); }\n    auto end() const {\
    \ return data.end(); }\n\n    graph() {}\n    graph(int N) : data(N) {}\n\n  \
    \  bool empty() const { return data.empty(); }\n    int size() const { return\
    \ data.size(); }\n\n    void add_edge(int i, int j, T w, int index = -1) {\n \
    \     data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1) {\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M) {\n      for (int i = 0; i < M; ++i) {\n     \
    \   int u, v;\n        std::cin >> u >> v;\n        u -= I;\n        v -= I;\n\
    \        T w = 1;\n        if (WEIGHTED) std::cin >> w;\n        if (DIRECTED)\n\
    \          add_edge(u, v, w, i);\n        else\n          add_undirected(u, v,\
    \ w, i);\n      }\n    }\n  };\n\n  template <typename T>\n  using tree = graph<T>;\n\
    }  // namespace haar_lib\n#line 5 \"Mylib/Graph/GraphUtils/decompose_pseudotree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class pseudo_tree {\n   \
    \ int n_;\n    std::vector<bool> in_loop_;\n    std::vector<int> group_;\n\n \
    \   void dfs(int cur, int par, const graph<T> &g) {\n      group_[cur] = group_[par];\n\
    \n      for (auto &e : g[cur]) {\n        if (e.to == par) continue;\n       \
    \ dfs(e.to, cur, g);\n      }\n    }\n\n  public:\n    pseudo_tree() {}\n    pseudo_tree(const\
    \ graph<T> &g) : n_(g.size()), in_loop_(n_, true), group_(n_) {\n      std::vector<int>\
    \ indeg(n_);\n      std::vector<bool> visited(n_);\n      std::queue<int> q;\n\
    \n      for (int i = 0; i < n_; ++i) {\n        for (auto &e : g[i]) {\n     \
    \     ++indeg[e.to];\n        }\n      }\n\n      for (int i = 0; i < n_; ++i)\
    \ {\n        if (indeg[i] == 1) {\n          q.push(i);\n        }\n      }\n\n\
    \      while (not q.empty()) {\n        int cur = q.front();\n        q.pop();\n\
    \n        in_loop_[cur] = false;\n\n        if (visited[cur]) continue;\n    \
    \    visited[cur] = true;\n\n        for (auto &e : g[cur]) {\n          if (not\
    \ visited[e.to]) {\n            --indeg[e.to];\n            if (indeg[e.to] ==\
    \ 1) {\n              q.push(e.to);\n            }\n          }\n        }\n \
    \     }\n\n      for (int i = 0; i < n_; ++i) {\n        if (in_loop_[i]) {\n\
    \          group_[i] = i;\n          for (auto &e : g[i]) {\n            if (not\
    \ in_loop_[e.to]) {\n              dfs(e.to, i, g);\n            }\n         \
    \ }\n        }\n      }\n    }\n\n    bool in_loop(int i) const { return in_loop_[i];\
    \ }\n    int group(int i) const { return group_[i]; }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class pseudo_tree {\n   \
    \ int n_;\n    std::vector<bool> in_loop_;\n    std::vector<int> group_;\n\n \
    \   void dfs(int cur, int par, const graph<T> &g) {\n      group_[cur] = group_[par];\n\
    \n      for (auto &e : g[cur]) {\n        if (e.to == par) continue;\n       \
    \ dfs(e.to, cur, g);\n      }\n    }\n\n  public:\n    pseudo_tree() {}\n    pseudo_tree(const\
    \ graph<T> &g) : n_(g.size()), in_loop_(n_, true), group_(n_) {\n      std::vector<int>\
    \ indeg(n_);\n      std::vector<bool> visited(n_);\n      std::queue<int> q;\n\
    \n      for (int i = 0; i < n_; ++i) {\n        for (auto &e : g[i]) {\n     \
    \     ++indeg[e.to];\n        }\n      }\n\n      for (int i = 0; i < n_; ++i)\
    \ {\n        if (indeg[i] == 1) {\n          q.push(i);\n        }\n      }\n\n\
    \      while (not q.empty()) {\n        int cur = q.front();\n        q.pop();\n\
    \n        in_loop_[cur] = false;\n\n        if (visited[cur]) continue;\n    \
    \    visited[cur] = true;\n\n        for (auto &e : g[cur]) {\n          if (not\
    \ visited[e.to]) {\n            --indeg[e.to];\n            if (indeg[e.to] ==\
    \ 1) {\n              q.push(e.to);\n            }\n          }\n        }\n \
    \     }\n\n      for (int i = 0; i < n_; ++i) {\n        if (in_loop_[i]) {\n\
    \          group_[i] = i;\n          for (auto &e : g[i]) {\n            if (not\
    \ in_loop_[e.to]) {\n              dfs(e.to, i, g);\n            }\n         \
    \ }\n        }\n      }\n    }\n\n    bool in_loop(int i) const { return in_loop_[i];\
    \ }\n    int group(int i) const { return group_[i]; }\n  };\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/GraphUtils/decompose_pseudotree.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2891/main.test.cpp
documentation_of: Mylib/Graph/GraphUtils/decompose_pseudotree.cpp
layout: document
title: Decompose pseudotree
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://en.wikipedia.org/wiki/Pseudoforest](https://en.wikipedia.org/wiki/Pseudoforest)
