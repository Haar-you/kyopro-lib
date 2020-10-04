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
  bundledCode: "#line 2 \"Mylib/Graph/TopologicalSort/topological_sort_lexicographical.cpp\"\
    \n#include <vector>\n#include <optional>\n#include <queue>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/TopologicalSort/topological_sort_lexicographical.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<std::vector<int>>\
    \ topological_sort_lexicographical(const graph<T> &g){\n    const int n = g.size();\n\
    \    std::vector<int> indeg(n);\n\n    for(int i = 0; i < n; ++i){\n      for(auto\
    \ &e : g[i]){\n        ++indeg[e.to];\n      }\n    }\n\n    std::priority_queue<int,\
    \ std::vector<int>, std::greater<int>> q;\n    for(int i = 0; i < n; ++i){\n \
    \     if(indeg[i] == 0) q.push(i);\n    }\n\n    std::vector<int> ret;\n    while(not\
    \ q.empty()){\n      int cur = q.top(); q.pop();\n      ret.push_back(cur);\n\
    \      for(auto &e : g[cur]){\n        --indeg[e.to];\n        if(indeg[e.to]\
    \ == 0){\n          q.push(e.to);\n        }\n      }\n    }\n\n    if((int)ret.size()\
    \ == n){\n      return {ret};\n    }else{\n      return std::nullopt;\n    }\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <queue>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::optional<std::vector<int>> topological_sort_lexicographical(const\
    \ graph<T> &g){\n    const int n = g.size();\n    std::vector<int> indeg(n);\n\
    \n    for(int i = 0; i < n; ++i){\n      for(auto &e : g[i]){\n        ++indeg[e.to];\n\
    \      }\n    }\n\n    std::priority_queue<int, std::vector<int>, std::greater<int>>\
    \ q;\n    for(int i = 0; i < n; ++i){\n      if(indeg[i] == 0) q.push(i);\n  \
    \  }\n\n    std::vector<int> ret;\n    while(not q.empty()){\n      int cur =\
    \ q.top(); q.pop();\n      ret.push_back(cur);\n      for(auto &e : g[cur]){\n\
    \        --indeg[e.to];\n        if(indeg[e.to] == 0){\n          q.push(e.to);\n\
    \        }\n      }\n    }\n\n    if((int)ret.size() == n){\n      return {ret};\n\
    \    }else{\n      return std::nullopt;\n    }\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TopologicalSort/topological_sort_lexicographical.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/TopologicalSort/topological_sort_lexicographical.cpp
layout: document
title: Topological sort (Lexicographically minimum)
---

## Operations

## Requirements

## Notes

## Problems

- [天下一プログラマーコンテスト2016予選A C - 山田山本問題](https://atcoder.jp/contests/tenka1-2016-quala/tasks/tenka1_2016_qualA_c)

## References
