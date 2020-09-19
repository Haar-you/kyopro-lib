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
  bundledCode: "#line 2 \"Mylib/Graph/EulerianPath/directed_eulerian_path.cpp\"\n\
    #include <vector>\n#include <map>\n#include <optional>\n#include <algorithm>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 7 \"Mylib/Graph/EulerianPath/directed_eulerian_path.cpp\"\
    \n\nnamespace haar_lib {\n  class directed_eulerian_path {\n    const int n; //\
    \ node count\n    int edges = 0; // edge count\n    std::vector<std::map<int,\
    \ int>> graph;\n    std::vector<int> indegree, outdegree;\n\n    void del(int\
    \ i, int j){\n      if(graph[i][j] == 1) graph[i].erase(j);\n      else --graph[i][j];\n\
    \    }\n\n    void dfs(int cur, std::vector<int> &path){\n      if(not graph[cur].empty()){\n\
    \        int next = graph[cur].begin()->first;\n        del(cur, next);\n    \
    \    dfs(next, path);\n      }\n\n      while(not graph[cur].empty()){\n     \
    \   int next = graph[cur].begin()->first;\n        del(cur, next);\n        std::vector<int>\
    \ temp;\n        dfs(next, temp);\n        path.insert(path.end(), temp.begin(),\
    \ temp.end());\n      }\n\n      path.push_back(cur);\n    }\n\n  public:\n  \
    \  directed_eulerian_path(int n): n(n), graph(n), indegree(n), outdegree(n){}\n\
    \n    void add(int i, int j){\n      ++graph[i][j];\n\n      ++outdegree[i];\n\
    \      ++indegree[j];\n\n      ++edges;\n    }\n\n    std::optional<std::vector<int>>\
    \ build(){\n      int in = 0, out = 0;\n      int start = 0;\n\n      for(int\
    \ i = 0; i < n; ++i){\n        int d = outdegree[i] - indegree[i];\n        if(std::abs(d)\
    \ > 1) return std::nullopt;\n        if(d == 1){\n          ++out;\n         \
    \ start = i;\n        }else if(d == -1){\n          ++in;\n        }\n      }\n\
    \n      if(not ((in == 0 and out == 0) or (in == 1 and out == 1))) return std::nullopt;\n\
    \n      std::vector<int> ret;\n\n      dfs(start, ret);\n      std::reverse(ret.begin(),\
    \ ret.end());\n      if((int)ret.size() == edges + 1){\n        return {ret};\n\
    \      }else{\n        return std::nullopt;\n      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <map>\n#include <optional>\n#include\
    \ <algorithm>\n#include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib\
    \ {\n  class directed_eulerian_path {\n    const int n; // node count\n    int\
    \ edges = 0; // edge count\n    std::vector<std::map<int, int>> graph;\n    std::vector<int>\
    \ indegree, outdegree;\n\n    void del(int i, int j){\n      if(graph[i][j] ==\
    \ 1) graph[i].erase(j);\n      else --graph[i][j];\n    }\n\n    void dfs(int\
    \ cur, std::vector<int> &path){\n      if(not graph[cur].empty()){\n        int\
    \ next = graph[cur].begin()->first;\n        del(cur, next);\n        dfs(next,\
    \ path);\n      }\n\n      while(not graph[cur].empty()){\n        int next =\
    \ graph[cur].begin()->first;\n        del(cur, next);\n        std::vector<int>\
    \ temp;\n        dfs(next, temp);\n        path.insert(path.end(), temp.begin(),\
    \ temp.end());\n      }\n\n      path.push_back(cur);\n    }\n\n  public:\n  \
    \  directed_eulerian_path(int n): n(n), graph(n), indegree(n), outdegree(n){}\n\
    \n    void add(int i, int j){\n      ++graph[i][j];\n\n      ++outdegree[i];\n\
    \      ++indegree[j];\n\n      ++edges;\n    }\n\n    std::optional<std::vector<int>>\
    \ build(){\n      int in = 0, out = 0;\n      int start = 0;\n\n      for(int\
    \ i = 0; i < n; ++i){\n        int d = outdegree[i] - indegree[i];\n        if(std::abs(d)\
    \ > 1) return std::nullopt;\n        if(d == 1){\n          ++out;\n         \
    \ start = i;\n        }else if(d == -1){\n          ++in;\n        }\n      }\n\
    \n      if(not ((in == 0 and out == 0) or (in == 1 and out == 1))) return std::nullopt;\n\
    \n      std::vector<int> ret;\n\n      dfs(start, ret);\n      std::reverse(ret.begin(),\
    \ ret.end());\n      if((int)ret.size() == edges + 1){\n        return {ret};\n\
    \      }else{\n        return std::nullopt;\n      }\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/EulerianPath/directed_eulerian_path.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/EulerianPath/directed_eulerian_path.cpp
layout: document
title: Directed Eulerian path
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #288 (Div. 2) D. Tanya and Password](https://codeforces.com/contest/508/problem/D)

## References

