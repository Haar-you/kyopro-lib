---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_3_B/main.test.cpp
    title: test/aoj/GRL_3_B/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/GraphUtils/bridges.cpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
    #line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n    int index\
    \ = -1;\n    edge() {}\n    edge(int from, int to, T cost) : from(from), to(to),\
    \ cost(cost) {}\n    edge(int from, int to, T cost, int index) : from(from), to(to),\
    \ cost(cost), index(index) {}\n  };\n\n  template <typename T>\n  struct graph\
    \ {\n    using weight_type = T;\n    using edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
    \ data;\n\n    auto& operator[](size_t i) { return data[i]; }\n    const auto&\
    \ operator[](size_t i) const { return data[i]; }\n\n    auto begin() const { return\
    \ data.begin(); }\n    auto end() const { return data.end(); }\n\n    graph()\
    \ {}\n    graph(int N) : data(N) {}\n\n    bool empty() const { return data.empty();\
    \ }\n    int size() const { return data.size(); }\n\n    void add_edge(int i,\
    \ int j, T w, int index = -1) {\n      data[i].emplace_back(i, j, w, index);\n\
    \    }\n\n    void add_undirected(int i, int j, T w, int index = -1) {\n     \
    \ add_edge(i, j, w, index);\n      add_edge(j, i, w, index);\n    }\n\n    template\
    \ <size_t I, bool DIRECTED = true, bool WEIGHTED = true>\n    void read(int M)\
    \ {\n      for (int i = 0; i < M; ++i) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        u -= I;\n        v -= I;\n        T w = 1;\n        if (WEIGHTED)\
    \ std::cin >> w;\n        if (DIRECTED)\n          add_edge(u, v, w, i);\n   \
    \     else\n          add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 5 \"\
    Mylib/Graph/GraphUtils/bridges.cpp\"\n\nnamespace haar_lib {\n  namespace bridges_impl\
    \ {\n    template <typename T>\n    int dfs(\n        const graph<T> &graph,\n\
    \        int cur,\n        int par,\n        std::vector<int> &visit,\n      \
    \  std::vector<int> &low,\n        std::vector<edge<T>> &ret,\n        int &v)\
    \ {\n      if (visit[cur] != -1) return visit[cur];\n      visit[cur] = v;\n \
    \     int temp   = v;\n      ++v;\n      for (auto &e : graph[cur]) {\n      \
    \  if (e.to == par) continue;\n        int t = dfs(graph, e.to, cur, visit, low,\
    \ ret, v);\n        temp  = std::min(temp, t);\n        if (low[e.to] > visit[cur])\
    \ ret.push_back(e);\n      }\n      return low[cur] = temp;\n    }\n  }  // namespace\
    \ bridges_impl\n\n  template <typename T>\n  auto bridges(const graph<T> &graph)\
    \ {\n    const int n = graph.size();\n    std::vector<int> visit(n, -1), low(n,\
    \ -1);\n    std::vector<edge<T>> ret;\n    int v = 0;\n\n    for (int i = 0; i\
    \ < n; ++i)\n      if (visit[i] == -1) bridges_impl::dfs(graph, i, -1, visit,\
    \ low, ret, v);\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  namespace bridges_impl {\n    template <typename T>\n\
    \    int dfs(\n        const graph<T> &graph,\n        int cur,\n        int par,\n\
    \        std::vector<int> &visit,\n        std::vector<int> &low,\n        std::vector<edge<T>>\
    \ &ret,\n        int &v) {\n      if (visit[cur] != -1) return visit[cur];\n \
    \     visit[cur] = v;\n      int temp   = v;\n      ++v;\n      for (auto &e :\
    \ graph[cur]) {\n        if (e.to == par) continue;\n        int t = dfs(graph,\
    \ e.to, cur, visit, low, ret, v);\n        temp  = std::min(temp, t);\n      \
    \  if (low[e.to] > visit[cur]) ret.push_back(e);\n      }\n      return low[cur]\
    \ = temp;\n    }\n  }  // namespace bridges_impl\n\n  template <typename T>\n\
    \  auto bridges(const graph<T> &graph) {\n    const int n = graph.size();\n  \
    \  std::vector<int> visit(n, -1), low(n, -1);\n    std::vector<edge<T>> ret;\n\
    \    int v = 0;\n\n    for (int i = 0; i < n; ++i)\n      if (visit[i] == -1)\
    \ bridges_impl::dfs(graph, i, -1, visit, low, ret, v);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/GraphUtils/bridges.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_3_B/main.test.cpp
documentation_of: Mylib/Graph/GraphUtils/bridges.cpp
layout: document
title: Bridges
---

## Operations

## Requirements

## Notes

## Problems

## References
