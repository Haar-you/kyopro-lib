---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Cycle/directed_shortest_cycle.cpp\"\n#include\
    \ <vector>\n#include <optional>\n#include <queue>\n#include <algorithm>\n#include\
    \ <climits>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 8 \"Mylib/Graph/Cycle/directed_shortest_cycle.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<std::vector<int>>\
    \ direct_shortest_cycle(const graph<T> &g, int src){\n    std::optional<std::vector<int>>\
    \ ret;\n    const int N = g.size();\n    int min_len = INT_MAX;\n    std::queue<int>\
    \ q;\n    q.push(src);\n\n    std::vector<int> dist(N), pre(N);\n    std::vector<bool>\
    \ visited(N);\n\n    while(not q.empty()){\n      int cur = q.front(); q.pop();\n\
    \n      if(visited[cur]) continue;\n      visited[cur] = true;\n\n      for(auto\
    \ &e : g[cur]){\n        if(e.to == src){\n          if(dist[cur] < min_len){\n\
    \            min_len = dist[cur];\n            ret = std::vector<int>();\n\n \
    \           int j = cur;\n            while(1){\n              (*ret).push_back(j);\n\
    \              if(j == src) break;\n\n              j = pre[j];\n            }\n\
    \n            std::reverse((*ret).begin(), (*ret).end());\n          }\n\n   \
    \       return ret;\n        }\n\n        if(not visited[e.to]){\n          dist[e.to]\
    \ = dist[cur] + 1;\n          pre[e.to] = cur;\n          q.push(e.to);\n    \
    \    }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <queue>\n\
    #include <algorithm>\n#include <climits>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<std::vector<int>>\
    \ direct_shortest_cycle(const graph<T> &g, int src){\n    std::optional<std::vector<int>>\
    \ ret;\n    const int N = g.size();\n    int min_len = INT_MAX;\n    std::queue<int>\
    \ q;\n    q.push(src);\n\n    std::vector<int> dist(N), pre(N);\n    std::vector<bool>\
    \ visited(N);\n\n    while(not q.empty()){\n      int cur = q.front(); q.pop();\n\
    \n      if(visited[cur]) continue;\n      visited[cur] = true;\n\n      for(auto\
    \ &e : g[cur]){\n        if(e.to == src){\n          if(dist[cur] < min_len){\n\
    \            min_len = dist[cur];\n            ret = std::vector<int>();\n\n \
    \           int j = cur;\n            while(1){\n              (*ret).push_back(j);\n\
    \              if(j == src) break;\n\n              j = pre[j];\n            }\n\
    \n            std::reverse((*ret).begin(), (*ret).end());\n          }\n\n   \
    \       return ret;\n        }\n\n        if(not visited[e.to]){\n          dist[e.to]\
    \ = dist[cur] + 1;\n          pre[e.to] = cur;\n          q.push(e.to);\n    \
    \    }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/Cycle/directed_shortest_cycle.cpp
  requiredBy: []
  timestamp: '2020-10-03 19:28:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/Cycle/directed_shortest_cycle.cpp
layout: document
title: Directed shortest cycle
---

## Operations

## Requirements

## Notes

## Problems

- [ABC 142 F - Pure](https://atcoder.jp/contests/abc142/tasks/abc142_f)

## References
