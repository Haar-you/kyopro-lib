---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/enumerate_triangles/main.test.cpp
    title: test/yosupo-judge/enumerate_triangles/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/enumerate_triangles.cpp\"\n#include <vector>\n\
    #include <tuple>\n#include <unordered_set>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
    \n#include <iostream>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ edge {\n    int from, to;\n    T cost;\n    int index = -1;\n    edge(){}\n\
    \    edge(int from, int to, T cost): from(from), to(to), cost(cost){}\n    edge(int\
    \ from, int to, T cost, int index): from(from), to(to), cost(cost), index(index){}\n\
    \  };\n\n  template <typename T>\n  struct graph {\n    using weight_type = T;\n\
    \    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\
    \n    auto& operator[](size_t i){return data[i];}\n    const auto& operator[](size_t\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/enumerate_triangles.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<std::tuple<int,\
    \ int, int>> enumerate_triangles(const graph<T> &g){\n    const int N = g.size();\n\
    \    std::vector<std::tuple<int, int, int>> ret;\n\n    std::vector<std::unordered_set<int>>\
    \ adjacent(N);\n\n    for(int i = 0; i < N; ++i){\n      for(auto &e : g[i]){\n\
    \        if(g[e.from].size() < g[e.to].size()){\n          adjacent[e.from].insert(e.to);\n\
    \        }else if(g[e.from].size() == g[e.to].size()){\n          if(e.from <\
    \ e.to){\n            adjacent[e.from].insert(e.to);\n          }\n        }\n\
    \      }\n    }\n\n    for(int i = 0; i < N; ++i){\n      for(int j : adjacent[i]){\n\
    \        for(int k : adjacent[j]){\n          if(adjacent[i].find(k) != adjacent[i].end()){\n\
    \            ret.emplace_back(i, j, k);\n          }\n        }\n      }\n   \
    \ }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include <unordered_set>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<std::tuple<int, int, int>> enumerate_triangles(const\
    \ graph<T> &g){\n    const int N = g.size();\n    std::vector<std::tuple<int,\
    \ int, int>> ret;\n\n    std::vector<std::unordered_set<int>> adjacent(N);\n\n\
    \    for(int i = 0; i < N; ++i){\n      for(auto &e : g[i]){\n        if(g[e.from].size()\
    \ < g[e.to].size()){\n          adjacent[e.from].insert(e.to);\n        }else\
    \ if(g[e.from].size() == g[e.to].size()){\n          if(e.from < e.to){\n    \
    \        adjacent[e.from].insert(e.to);\n          }\n        }\n      }\n   \
    \ }\n\n    for(int i = 0; i < N; ++i){\n      for(int j : adjacent[i]){\n    \
    \    for(int k : adjacent[j]){\n          if(adjacent[i].find(k) != adjacent[i].end()){\n\
    \            ret.emplace_back(i, j, k);\n          }\n        }\n      }\n   \
    \ }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/enumerate_triangles.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/enumerate_triangles/main.test.cpp
documentation_of: Mylib/Graph/enumerate_triangles.cpp
layout: document
title: Enumerate triangles
---

## Operations

## Requirements

## Notes

## Problems

## References
