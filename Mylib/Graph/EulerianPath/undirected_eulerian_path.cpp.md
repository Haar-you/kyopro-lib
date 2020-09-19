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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp\"\n\
    #include <vector>\n#include <map>\n#include <optional>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp\"\
    \n\nnamespace haar_lib {\n  class undirected_eulerian_path {\n    const int n;\
    \ // node count\n    int edges = 0; // edge count\n    std::vector<std::map<int,\
    \ int>> graph;\n    std::vector<int> degree;\n\n    void del(int i, int j){\n\
    \      if(graph[i][j] == 1) graph[i].erase(j);\n      else --graph[i][j];\n\n\
    \      if(graph[j][i] == 1) graph[j].erase(i);\n      else --graph[j][i];\n  \
    \  }\n\n    void dfs(int cur, std::vector<int> &path){\n      if(not graph[cur].empty()){\n\
    \        int next = graph[cur].begin()->first;\n        del(cur, next);\n    \
    \    dfs(next, path);\n      }\n\n      while(not graph[cur].empty()){\n     \
    \   int next = graph[cur].begin()->first;\n        del(cur, next);\n        std::vector<int>\
    \ temp;\n        dfs(next, temp);\n        path.insert(path.end(), temp.begin(),\
    \ temp.end());\n      }\n\n      path.push_back(cur);\n    }\n\n  public:\n  \
    \  undirected_eulerian_path(int n): n(n), graph(n), degree(n){}\n\n    void add(int\
    \ i, int j){\n      ++graph[i][j];\n      ++graph[j][i];\n\n      ++degree[i];\n\
    \      ++degree[j];\n\n      ++edges;\n    }\n\n    std::optional<std::vector<int>>\
    \ build(){\n      std::vector<int> ret;\n\n      int odd = 0;\n      int start\
    \ = 0;\n      for(int i = 0; i < n; ++i){\n        if(degree[i] % 2 == 1){\n \
    \         ++odd;\n          start = i;\n        }\n      }\n\n      if(odd !=\
    \ 0 and odd != 2) return std::nullopt;\n\n      dfs(start, ret);\n\n      if((int)ret.size()\
    \ == edges + 1){\n        return {ret};\n      }else{\n        return std::nullopt;\n\
    \      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <map>\n#include <optional>\n#include\
    \ \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  class undirected_eulerian_path\
    \ {\n    const int n; // node count\n    int edges = 0; // edge count\n    std::vector<std::map<int,\
    \ int>> graph;\n    std::vector<int> degree;\n\n    void del(int i, int j){\n\
    \      if(graph[i][j] == 1) graph[i].erase(j);\n      else --graph[i][j];\n\n\
    \      if(graph[j][i] == 1) graph[j].erase(i);\n      else --graph[j][i];\n  \
    \  }\n\n    void dfs(int cur, std::vector<int> &path){\n      if(not graph[cur].empty()){\n\
    \        int next = graph[cur].begin()->first;\n        del(cur, next);\n    \
    \    dfs(next, path);\n      }\n\n      while(not graph[cur].empty()){\n     \
    \   int next = graph[cur].begin()->first;\n        del(cur, next);\n        std::vector<int>\
    \ temp;\n        dfs(next, temp);\n        path.insert(path.end(), temp.begin(),\
    \ temp.end());\n      }\n\n      path.push_back(cur);\n    }\n\n  public:\n  \
    \  undirected_eulerian_path(int n): n(n), graph(n), degree(n){}\n\n    void add(int\
    \ i, int j){\n      ++graph[i][j];\n      ++graph[j][i];\n\n      ++degree[i];\n\
    \      ++degree[j];\n\n      ++edges;\n    }\n\n    std::optional<std::vector<int>>\
    \ build(){\n      std::vector<int> ret;\n\n      int odd = 0;\n      int start\
    \ = 0;\n      for(int i = 0; i < n; ++i){\n        if(degree[i] % 2 == 1){\n \
    \         ++odd;\n          start = i;\n        }\n      }\n\n      if(odd !=\
    \ 0 and odd != 2) return std::nullopt;\n\n      dfs(start, ret);\n\n      if((int)ret.size()\
    \ == edges + 1){\n        return {ret};\n      }else{\n        return std::nullopt;\n\
    \      }\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/EulerianPath/undirected_eulerian_path.cpp
layout: document
title: Undirected Eulerian path
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #554 (Div. 2) E. Neko and Flashback](https://codeforces.com/contest/1152/problem/E)

## References

