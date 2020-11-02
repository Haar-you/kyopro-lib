---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp
    title: Chu-Liu/Edmonds algorithm
  - icon: ':x:'
    path: Mylib/Graph/two_sat.cpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_B/main.test.cpp
    title: test/aoj/GRL_2_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C/main.test.cpp
    title: test/aoj/GRL_3_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/scc/main.test.cpp
    title: test/yosupo-judge/scc/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/two_sat/main.test.cpp
    title: test/yosupo-judge/two_sat/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n#include <vector>\n#include <algorithm>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto strongly_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<int> ret(n), low(n,\
    \ -1), ord(n, -1), S;\n    std::vector<bool> check(n);\n    S.reserve(n);\n  \
    \  int t = 0;\n    int k = 0;\n\n    auto dfs =\n      [&](auto &dfs, int cur)\
    \ -> void {\n        low[cur] = ord[cur] = t++;\n        S.push_back(cur);\n \
    \       check[cur] = true;\n\n        for(auto &e : g[cur]){\n          if(ord[e.to]\
    \ == -1){\n            dfs(dfs, e.to);\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }else if(check[e.to]){\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }\n        }\n\n        if(low[cur] == ord[cur]){\n \
    \         while(true){\n            int u = S.back(); S.pop_back();\n        \
    \    check[u] = false;\n            ret[u] = k;\n            if(cur == u) break;\n\
    \          }\n          ++k;\n        }\n      };\n\n    for(int i = 0; i < n;\
    \ ++i){\n      if(ord[i] == -1){\n        t = 0;\n        dfs(dfs, i);\n     \
    \ }\n    }\n\n    for(auto &x : ret) x = k - 1 - x;\n\n    return std::make_pair(ret,\
    \ k);\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto strongly_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<int> ret(n), low(n,\
    \ -1), ord(n, -1), S;\n    std::vector<bool> check(n);\n    S.reserve(n);\n  \
    \  int t = 0;\n    int k = 0;\n\n    auto dfs =\n      [&](auto &dfs, int cur)\
    \ -> void {\n        low[cur] = ord[cur] = t++;\n        S.push_back(cur);\n \
    \       check[cur] = true;\n\n        for(auto &e : g[cur]){\n          if(ord[e.to]\
    \ == -1){\n            dfs(dfs, e.to);\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }else if(check[e.to]){\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }\n        }\n\n        if(low[cur] == ord[cur]){\n \
    \         while(true){\n            int u = S.back(); S.pop_back();\n        \
    \    check[u] = false;\n            ret[u] = k;\n            if(cur == u) break;\n\
    \          }\n          ++k;\n        }\n      };\n\n    for(int i = 0; i < n;\
    \ ++i){\n      if(ord[i] == -1){\n        t = 0;\n        dfs(dfs, i);\n     \
    \ }\n    }\n\n    for(auto &x : ret) x = k - 1 - x;\n\n    return std::make_pair(ret,\
    \ k);\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
  requiredBy:
  - Mylib/Graph/two_sat.cpp
  - Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp
  timestamp: '2020-09-21 06:13:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_3_C/main.test.cpp
  - test/aoj/GRL_2_B/main.test.cpp
  - test/yosupo-judge/two_sat/main.test.cpp
  - test/yosupo-judge/scc/main.test.cpp
documentation_of: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
layout: document
title: Strongly connected components
---

## Operations

## Requirements

## Notes

## Problems

## References
