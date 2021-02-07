---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/ShortestPath/bfs_0_1.cpp\"\n#include <vector>\n\
    #include <deque>\n#include <optional>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/ShortestPath/bfs_0_1.cpp\"\
    \n\nnamespace haar_lib {\n  std::vector<std::optional<int64_t>> bfs_0_1(const\
    \ graph<int> &g, const std::vector<int> &src){\n    const int n = g.size();\n\
    \    std::vector<std::optional<int64_t>> ret(n);\n    std::vector<bool> visited(n);\n\
    \n    for(auto i : src) ret[i] = 0;\n    std::deque<int> dq(src.begin(), src.end());\n\
    \n    while(not dq.empty()){\n      int cur = dq.front(); dq.pop_front();\n\n\
    \      if(visited[cur]) continue;\n      visited[cur] = true;\n\n      for(auto\
    \ &e : g[cur]){\n        if(not ret[e.to] or *ret[e.to] > *ret[e.from] + e.cost){\n\
    \          ret[e.to] = *ret[e.from] + e.cost;\n\n          if(e.cost == 0) dq.push_front(e.to);\n\
    \          else dq.push_back(e.to);\n        }\n      }\n    }\n\n    return ret;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <deque>\n#include <optional>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  std::vector<std::optional<int64_t>>\
    \ bfs_0_1(const graph<int> &g, const std::vector<int> &src){\n    const int n\
    \ = g.size();\n    std::vector<std::optional<int64_t>> ret(n);\n    std::vector<bool>\
    \ visited(n);\n\n    for(auto i : src) ret[i] = 0;\n    std::deque<int> dq(src.begin(),\
    \ src.end());\n\n    while(not dq.empty()){\n      int cur = dq.front(); dq.pop_front();\n\
    \n      if(visited[cur]) continue;\n      visited[cur] = true;\n\n      for(auto\
    \ &e : g[cur]){\n        if(not ret[e.to] or *ret[e.to] > *ret[e.from] + e.cost){\n\
    \          ret[e.to] = *ret[e.from] + e.cost;\n\n          if(e.cost == 0) dq.push_front(e.to);\n\
    \          else dq.push_back(e.to);\n        }\n      }\n    }\n\n    return ret;\n\
    \  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/ShortestPath/bfs_0_1.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/ShortestPath/bfs_0_1.cpp
layout: document
title: 0-1 BFS
---

## Operations

## Requirements

## Notes

## Problems

## References
