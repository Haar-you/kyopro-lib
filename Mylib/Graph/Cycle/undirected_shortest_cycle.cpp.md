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
  bundledCode: "#line 2 \"Mylib/Graph/Cycle/undirected_shortest_cycle.cpp\"\n#include\
    \ <vector>\n#include <queue>\n#include <optional>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/Cycle/undirected_shortest_cycle.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<int> shortest_cycle(const\
    \ graph<T> &g, const int src){\n    for(auto &e : g[src]){\n      if(e.to == src)\
    \ return 1; // self loop\n    }\n\n    if(g[src].size() <= 1) return {};\n\n \
    \   const int N = g.size();\n    std::vector<int> visit(N);\n    std::vector<int>\
    \ dist(N);\n\n    visit[src] = -1;\n\n    std::queue<int> q;\n    for(int i =\
    \ 0; i < (int)g[src].size(); ++i){\n      int j = g[src][i].to;\n      if(visit[j])\
    \ return 2; // multiple edges\n      q.push(j);\n      visit[j] = i + 1;\n   \
    \   dist[j] = 1;\n    }\n\n    while(not q.empty()){\n      int i = q.front();\
    \ q.pop();\n\n      for(auto &e : g[i]){\n        if(not visit[e.to]){\n     \
    \     visit[e.to] = visit[i];\n          dist[e.to] = dist[i] + 1;\n         \
    \ q.push(e.to);\n        }else{\n          if(e.to != src and visit[e.from] !=\
    \ visit[e.to]){\n            return dist[e.from] + dist[e.to] + 1;\n         \
    \ }\n        }\n      }\n    }\n\n    return {};\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <optional>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::optional<int> shortest_cycle(const graph<T> &g, const int\
    \ src){\n    for(auto &e : g[src]){\n      if(e.to == src) return 1; // self loop\n\
    \    }\n\n    if(g[src].size() <= 1) return {};\n\n    const int N = g.size();\n\
    \    std::vector<int> visit(N);\n    std::vector<int> dist(N);\n\n    visit[src]\
    \ = -1;\n\n    std::queue<int> q;\n    for(int i = 0; i < (int)g[src].size();\
    \ ++i){\n      int j = g[src][i].to;\n      if(visit[j]) return 2; // multiple\
    \ edges\n      q.push(j);\n      visit[j] = i + 1;\n      dist[j] = 1;\n    }\n\
    \n    while(not q.empty()){\n      int i = q.front(); q.pop();\n\n      for(auto\
    \ &e : g[i]){\n        if(not visit[e.to]){\n          visit[e.to] = visit[i];\n\
    \          dist[e.to] = dist[i] + 1;\n          q.push(e.to);\n        }else{\n\
    \          if(e.to != src and visit[e.from] != visit[e.to]){\n            return\
    \ dist[e.from] + dist[e.to] + 1;\n          }\n        }\n      }\n    }\n\n \
    \   return {};\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/Cycle/undirected_shortest_cycle.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/Cycle/undirected_shortest_cycle.cpp
layout: document
title: Undirected shortest cycle
---

## Operations

- `shortest_cycle(g, src)`
	- `src`始点の最小閉路を検出する。
	- Time complexity $O(E)$

## Requirements

## Notes

## Problems

- [Codeforces Round #628 (Div. 2) E. Ehab's REAL Number Theory Problem](https://codeforces.com/contest/1325/problem/E)

## References
