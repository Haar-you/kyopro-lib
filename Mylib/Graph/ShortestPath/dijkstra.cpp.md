---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0575/main.test.cpp
    title: test/aoj/0575/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A/main.test.cpp
    title: test/aoj/GRL_1_A/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/ShortestPath/dijkstra.cpp\"\n#include <vector>\n\
    #include <optional>\n#include <queue>\n#include <utility>\n#include <functional>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 8 \"Mylib/Graph/ShortestPath/dijkstra.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto dijkstra(const graph<T>\
    \ &graph, std::vector<int> src){\n    using P = std::pair<T, int>;\n\n    const\
    \ int n = graph.size();\n    std::vector<std::optional<T>> dist(n);\n\n    std::vector<bool>\
    \ check(n, false);\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n    for(auto s : src){\n      dist[s] = 0;\n      pq.emplace(0, s);\n\
    \    }\n\n    while(not pq.empty()){\n      const auto [d, i] = pq.top(); pq.pop();\n\
    \n      if(check[i]) continue;\n      check[i] = true;\n\n      for(auto &e :\
    \ graph[i]){\n        if(not dist[e.to]){\n          dist[e.to] = d + e.cost;\n\
    \          pq.emplace(*dist[e.to], e.to);\n        }else{\n          if(*dist[e.to]\
    \ > d + e.cost){\n            dist[e.to] = d + e.cost;\n            if(not check[e.to])\
    \ pq.emplace(*dist[e.to], e.to);\n          }\n        }\n      }\n    }\n\n \
    \   return dist;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <queue>\n\
    #include <utility>\n#include <functional>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto dijkstra(const graph<T>\
    \ &graph, std::vector<int> src){\n    using P = std::pair<T, int>;\n\n    const\
    \ int n = graph.size();\n    std::vector<std::optional<T>> dist(n);\n\n    std::vector<bool>\
    \ check(n, false);\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n    for(auto s : src){\n      dist[s] = 0;\n      pq.emplace(0, s);\n\
    \    }\n\n    while(not pq.empty()){\n      const auto [d, i] = pq.top(); pq.pop();\n\
    \n      if(check[i]) continue;\n      check[i] = true;\n\n      for(auto &e :\
    \ graph[i]){\n        if(not dist[e.to]){\n          dist[e.to] = d + e.cost;\n\
    \          pq.emplace(*dist[e.to], e.to);\n        }else{\n          if(*dist[e.to]\
    \ > d + e.cost){\n            dist[e.to] = d + e.cost;\n            if(not check[e.to])\
    \ pq.emplace(*dist[e.to], e.to);\n          }\n        }\n      }\n    }\n\n \
    \   return dist;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/ShortestPath/dijkstra.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0575/main.test.cpp
  - test/aoj/GRL_1_A/main.test.cpp
documentation_of: Mylib/Graph/ShortestPath/dijkstra.cpp
layout: document
title: Dijkstra algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
