---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0558/main.graph.test.cpp
    title: test/aoj/0558/main.graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/ShortestPath/bfs_shortest_path.cpp\"\n#include\
    \ <vector>\n#include <optional>\n#include <queue>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/ShortestPath/bfs_shortest_path.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<std::optional<int64_t>>\
    \ bfs_shortest_path(const graph<T> &g, const std::vector<int> &src){\n    const\
    \ int n = g.size();\n    std::vector<std::optional<int64_t>> ret(n, std::nullopt);\n\
    \    std::vector<bool> visited(n);\n    std::queue<int> q;\n\n    for(auto s :\
    \ src){\n      ret[s] = 0;\n      q.push(s);\n    }\n\n    while(not q.empty()){\n\
    \      const int cur = q.front(); q.pop();\n\n      if(visited[cur]) continue;\n\
    \      visited[cur] = true;\n\n      for(auto &e : g[cur]){\n        if(not ret[e.to]\
    \ or *ret[e.to] > *ret[e.from] + 1){\n          ret[e.to] = *ret[e.from] + 1;\n\
    \          q.push(e.to);\n        }\n      }\n    }\n\n    return ret;\n  }\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <queue>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<std::optional<int64_t>> bfs_shortest_path(const\
    \ graph<T> &g, const std::vector<int> &src){\n    const int n = g.size();\n  \
    \  std::vector<std::optional<int64_t>> ret(n, std::nullopt);\n    std::vector<bool>\
    \ visited(n);\n    std::queue<int> q;\n\n    for(auto s : src){\n      ret[s]\
    \ = 0;\n      q.push(s);\n    }\n\n    while(not q.empty()){\n      const int\
    \ cur = q.front(); q.pop();\n\n      if(visited[cur]) continue;\n      visited[cur]\
    \ = true;\n\n      for(auto &e : g[cur]){\n        if(not ret[e.to] or *ret[e.to]\
    \ > *ret[e.from] + 1){\n          ret[e.to] = *ret[e.from] + 1;\n          q.push(e.to);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/ShortestPath/bfs_shortest_path.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0558/main.graph.test.cpp
documentation_of: Mylib/Graph/ShortestPath/bfs_shortest_path.cpp
layout: document
title: BFS shortest path
---

## Operations

## Requirements

## Notes

## Problems

## References
