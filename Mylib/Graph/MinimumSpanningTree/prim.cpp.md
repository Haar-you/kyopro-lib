---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.binomial_heap.test.cpp
    title: test/aoj/2559/main.binomial_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.leftist_heap.test.cpp
    title: test/aoj/2559/main.leftist_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.skew_heap.test.cpp
    title: test/aoj/2559/main.skew_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A/main.prim.test.cpp
    title: test/aoj/GRL_2_A/main.prim.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/MinimumSpanningTree/prim.cpp\"\n#include <vector>\n\
    #include <queue>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/MinimumSpanningTree/prim.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<edge<T>> prim(const\
    \ graph<T> &graph){\n    const int n = graph.size();\n    std::vector<bool> visit(n,\
    \ false);\n    std::vector<edge<T>> ret;\n\n    auto cmp = [](const auto &a, const\
    \ auto &b){return a.cost > b.cost;};\n    std::priority_queue<edge<T>, std::vector<edge<T>>,\
    \ decltype(cmp)> pq(cmp);\n\n    visit[0] = true;\n    for(auto &e : graph[0])\
    \ pq.push(e);\n\n    while(not pq.empty()){\n      auto t = pq.top(); pq.pop();\n\
    \n      if(visit[t.from] == visit[t.to]) continue;\n\n      int i = visit[t.from]\
    \ ? t.to : t.from;\n      for(auto &e : graph[i]){\n        pq.push(e);\n    \
    \  }\n\n      visit[i] = true;\n      ret.push_back(t);\n    }\n\n    return ret;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<edge<T>> prim(const\
    \ graph<T> &graph){\n    const int n = graph.size();\n    std::vector<bool> visit(n,\
    \ false);\n    std::vector<edge<T>> ret;\n\n    auto cmp = [](const auto &a, const\
    \ auto &b){return a.cost > b.cost;};\n    std::priority_queue<edge<T>, std::vector<edge<T>>,\
    \ decltype(cmp)> pq(cmp);\n\n    visit[0] = true;\n    for(auto &e : graph[0])\
    \ pq.push(e);\n\n    while(not pq.empty()){\n      auto t = pq.top(); pq.pop();\n\
    \n      if(visit[t.from] == visit[t.to]) continue;\n\n      int i = visit[t.from]\
    \ ? t.to : t.from;\n      for(auto &e : graph[i]){\n        pq.push(e);\n    \
    \  }\n\n      visit[i] = true;\n      ret.push_back(t);\n    }\n\n    return ret;\n\
    \  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/MinimumSpanningTree/prim.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A/main.prim.test.cpp
  - test/aoj/2559/main.leftist_heap.test.cpp
  - test/aoj/2559/main.skew_heap.test.cpp
  - test/aoj/2559/main.binomial_heap.test.cpp
documentation_of: Mylib/Graph/MinimumSpanningTree/prim.cpp
layout: document
title: Prim algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
