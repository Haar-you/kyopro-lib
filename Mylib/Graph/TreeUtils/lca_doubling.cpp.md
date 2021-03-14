---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C/main.doubling.test.cpp
    title: test/aoj/GRL_5_C/main.doubling.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/922/main.test.cpp
    title: test/yukicoder/922/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/lca_doubling.cpp\"\n#include <vector>\n\
    #include <cmath>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge(){}\n    edge(int from, int\
    \ to, T cost): from(from), to(to), cost(cost){}\n    edge(int from, int to, T\
    \ cost, int index): from(from), to(to), cost(cost), index(index){}\n  };\n\n \
    \ template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n    auto&\
    \ operator[](size_t i){return data[i];}\n    const auto& operator[](size_t i)\
    \ const {return data[i];}\n\n    auto begin() const {return data.begin();}\n \
    \   auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/TreeUtils/lca_doubling.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class lowest_common_ancestor_doubling\
    \ {\n    int n_, log2n_;\n    std::vector<std::vector<int>> parent_;\n    std::vector<int>\
    \ depth_;\n\n    void dfs(const tree<T> &tr, int cur, int par, int d){\n     \
    \ parent_[cur][0] = par;\n      depth_[cur] = d;\n\n      for(auto &e : tr[cur]){\n\
    \        if(e.to != par){\n          dfs(tr, e.to, cur, d + 1);\n        }\n \
    \     }\n    }\n\n  public:\n    lowest_common_ancestor_doubling(){}\n    lowest_common_ancestor_doubling(const\
    \ tree<T> &tr, int root):\n      n_(tr.size()), log2n_((int)ceil(log2(n_)) + 1),\
    \ parent_(n_, std::vector<int>(log2n_)), depth_(n_)\n    {\n      dfs(tr, root,\
    \ -1, 0);\n      for(int k = 0; k < log2n_ - 1; ++k){\n        for(int v = 0;\
    \ v < n_; ++v){\n          if(parent_[v][k] == -1) parent_[v][k + 1] = -1;\n \
    \         else parent_[v][k + 1] = parent_[parent_[v][k]][k];\n        }\n   \
    \   }\n    }\n\n    int lca(int a, int b) const {\n      if(depth_[a] >= depth_[b])\
    \ std::swap(a, b);\n      for(int k = 0; k < log2n_; ++k){\n        if((depth_[b]\
    \ - depth_[a]) >> k & 1) b = parent_[b][k];\n      }\n      if(a == b) return\
    \ a;\n      for(int k = log2n_; --k >= 0;){\n        if(parent_[a][k] != parent_[b][k]){a\
    \ = parent_[a][k]; b = parent_[b][k];}\n      }\n      return parent_[a][0];\n\
    \    }\n\n    int operator()(int a, int b) const {return lca(a, b);}\n\n    T\
    \ distance(int u, int v, const std::vector<T> &dist) const {\n      return dist[u]\
    \ + dist[v] - 2 * dist[lca(u, v)];\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cmath>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class lowest_common_ancestor_doubling\
    \ {\n    int n_, log2n_;\n    std::vector<std::vector<int>> parent_;\n    std::vector<int>\
    \ depth_;\n\n    void dfs(const tree<T> &tr, int cur, int par, int d){\n     \
    \ parent_[cur][0] = par;\n      depth_[cur] = d;\n\n      for(auto &e : tr[cur]){\n\
    \        if(e.to != par){\n          dfs(tr, e.to, cur, d + 1);\n        }\n \
    \     }\n    }\n\n  public:\n    lowest_common_ancestor_doubling(){}\n    lowest_common_ancestor_doubling(const\
    \ tree<T> &tr, int root):\n      n_(tr.size()), log2n_((int)ceil(log2(n_)) + 1),\
    \ parent_(n_, std::vector<int>(log2n_)), depth_(n_)\n    {\n      dfs(tr, root,\
    \ -1, 0);\n      for(int k = 0; k < log2n_ - 1; ++k){\n        for(int v = 0;\
    \ v < n_; ++v){\n          if(parent_[v][k] == -1) parent_[v][k + 1] = -1;\n \
    \         else parent_[v][k + 1] = parent_[parent_[v][k]][k];\n        }\n   \
    \   }\n    }\n\n    int lca(int a, int b) const {\n      if(depth_[a] >= depth_[b])\
    \ std::swap(a, b);\n      for(int k = 0; k < log2n_; ++k){\n        if((depth_[b]\
    \ - depth_[a]) >> k & 1) b = parent_[b][k];\n      }\n      if(a == b) return\
    \ a;\n      for(int k = log2n_; --k >= 0;){\n        if(parent_[a][k] != parent_[b][k]){a\
    \ = parent_[a][k]; b = parent_[b][k];}\n      }\n      return parent_[a][0];\n\
    \    }\n\n    int operator()(int a, int b) const {return lca(a, b);}\n\n    T\
    \ distance(int u, int v, const std::vector<T> &dist) const {\n      return dist[u]\
    \ + dist[v] - 2 * dist[lca(u, v)];\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/lca_doubling.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/922/main.test.cpp
  - test/aoj/GRL_5_C/main.doubling.test.cpp
documentation_of: Mylib/Graph/TreeUtils/lca_doubling.cpp
layout: document
title: Lowest common ancestor (Doubling)
---

## Operations

## Requirements

## Notes

## Problems

## References
