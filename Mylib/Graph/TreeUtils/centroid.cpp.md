---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/centroid.cpp\"\n#include <vector>\n\
    #line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n\
    \    int index = -1;\n    edge(){}\n    edge(int from, int to, T cost): from(from),\
    \ to(to), cost(cost){}\n    edge(int from, int to, T cost, int index): from(from),\
    \ to(to), cost(cost), index(index){}\n  };\n\n  template <typename T>\n  struct\
    \ graph {\n    using weight_type = T;\n    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
    \ data;\n\n    auto& operator[](size_t i){return data[i];}\n    const auto& operator[](size_t\
    \ i) const {return data[i];}\n\n    auto begin() const {return data.begin();}\n\
    \    auto end() const {return data.end();}\n\n    graph(){}\n    graph(int N):\
    \ data(N){}\n\n    bool empty() const {return data.empty();}\n    int size() const\
    \ {return data.size();}\n\n    void add_edge(int i, int j, T w, int index = -1){\n\
    \      data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1){\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M){\n      for(int i = 0; i < M; ++i){\n        int\
    \ u, v; std::cin >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n\
    \        if(WEIGHTED) std::cin >> w;\n        if(DIRECTED) add_edge(u, v, w, i);\n\
    \        else add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 4 \"Mylib/Graph/TreeUtils/centroid.cpp\"\
    \n\nnamespace haar_lib {\n  namespace enumerate_centroids_impl {\n    template\
    \ <typename T>\n    void dfs(const tree<T> &tr, std::vector<int> &subtree, std::vector<int>\
    \ &ret, int N, int cur, int par){\n      subtree[cur] = 1;\n      bool check =\
    \ true;\n\n      for(auto &e : tr[cur]){\n        if(e.to == par) continue;\n\
    \        dfs(tr, subtree, ret, N, e.to, cur);\n\n        if(subtree[e.to] > N\
    \ / 2) check = false;\n        subtree[cur] += subtree[e.to];\n      }\n\n   \
    \   if(N - subtree[cur] > N / 2) check = false;\n\n      if(check) ret.push_back(cur);\n\
    \    }\n  }\n\n  template <typename T>\n  auto enumerate_centroids(const tree<T>\
    \ &tr){\n    const int N = tr.size();\n    std::vector<int> subtree(N), ret;\n\
    \    enumerate_centroids_impl::dfs(tr, subtree, ret, N, 0, -1);\n    return ret;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  namespace enumerate_centroids_impl {\n    template\
    \ <typename T>\n    void dfs(const tree<T> &tr, std::vector<int> &subtree, std::vector<int>\
    \ &ret, int N, int cur, int par){\n      subtree[cur] = 1;\n      bool check =\
    \ true;\n\n      for(auto &e : tr[cur]){\n        if(e.to == par) continue;\n\
    \        dfs(tr, subtree, ret, N, e.to, cur);\n\n        if(subtree[e.to] > N\
    \ / 2) check = false;\n        subtree[cur] += subtree[e.to];\n      }\n\n   \
    \   if(N - subtree[cur] > N / 2) check = false;\n\n      if(check) ret.push_back(cur);\n\
    \    }\n  }\n\n  template <typename T>\n  auto enumerate_centroids(const tree<T>\
    \ &tr){\n    const int N = tr.size();\n    std::vector<int> subtree(N), ret;\n\
    \    enumerate_centroids_impl::dfs(tr, subtree, ret, N, 0, -1);\n    return ret;\n\
    \  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/centroid.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/TreeUtils/centroid.cpp
layout: document
title: Enumerate centroids
---

## Operations

## Requirements

## Notes

## Problems

## References
