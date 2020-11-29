---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_2_A/main.test.cpp
    title: test/aoj/DPL_2_A/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/travelling_salesman_problem.cpp\"\n#include\
    \ <vector>\n#include <optional>\n#include <algorithm>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/travelling_salesman_problem.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<T> travelling_salesman_problem(const\
    \ graph<T> &g, int src){\n    const int n = g.size();\n\n    std::vector<std::vector<std::optional<T>>>\
    \ dp(n, std::vector<std::optional<T>>(1 << n));\n\n    for(auto &e : g[src]){\n\
    \      if(not dp[e.to][1 << e.to]){\n        dp[e.to][1 << e.to] = e.cost;\n \
    \     }else{\n        dp[e.to][1 << e.to] = std::min(*dp[e.to][1 << e.to], e.cost);\n\
    \      }\n    }\n\n    for(int s = 1; s < (1 << n); ++s){\n      for(int i = 0;\
    \ i < n; ++i){\n        if(not (s & (1 << i))) continue;\n\n        for(auto &e\
    \ : g[i]){\n          if(s & (1 << e.to)) continue;\n\n          if(dp[i][s]){\n\
    \            if(not dp[e.to][s | (1 << e.to)]){\n              dp[e.to][s | (1\
    \ << e.to)] = *dp[i][s] + e.cost;\n            }else{\n              dp[e.to][s\
    \ | (1 << e.to)] = std::min(*dp[e.to][s | (1 << e.to)], *dp[i][s] + e.cost);\n\
    \            }\n          }\n        }\n      }\n    }\n\n    return dp[src][(1\
    \ << n) - 1];\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <algorithm>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::optional<T> travelling_salesman_problem(const graph<T>\
    \ &g, int src){\n    const int n = g.size();\n\n    std::vector<std::vector<std::optional<T>>>\
    \ dp(n, std::vector<std::optional<T>>(1 << n));\n\n    for(auto &e : g[src]){\n\
    \      if(not dp[e.to][1 << e.to]){\n        dp[e.to][1 << e.to] = e.cost;\n \
    \     }else{\n        dp[e.to][1 << e.to] = std::min(*dp[e.to][1 << e.to], e.cost);\n\
    \      }\n    }\n\n    for(int s = 1; s < (1 << n); ++s){\n      for(int i = 0;\
    \ i < n; ++i){\n        if(not (s & (1 << i))) continue;\n\n        for(auto &e\
    \ : g[i]){\n          if(s & (1 << e.to)) continue;\n\n          if(dp[i][s]){\n\
    \            if(not dp[e.to][s | (1 << e.to)]){\n              dp[e.to][s | (1\
    \ << e.to)] = *dp[i][s] + e.cost;\n            }else{\n              dp[e.to][s\
    \ | (1 << e.to)] = std::min(*dp[e.to][s | (1 << e.to)], *dp[i][s] + e.cost);\n\
    \            }\n          }\n        }\n      }\n    }\n\n    return dp[src][(1\
    \ << n) - 1];\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/travelling_salesman_problem.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_2_A/main.test.cpp
documentation_of: Mylib/Graph/travelling_salesman_problem.cpp
layout: document
title: Travelling salesman problem
---

## Operations

- `travelling_salesman_problem(g, int src)`
	- `src`始点の全頂点を丁度一度だけ通る最小閉路の距離を返す。
	- Time complexity $O(n^2 2^n)$

## Requirements

## Notes

## Problems

- [AOJ DPL_2_A Traveling Salesman Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A)

## References

- [https://ja.wikipedia.org/wiki/%E5%B7%A1%E5%9B%9E%E3%82%BB%E3%83%BC%E3%83%AB%E3%82%B9%E3%83%9E%E3%83%B3%E5%95%8F%E9%A1%8C](https://ja.wikipedia.org/wiki/%E5%B7%A1%E5%9B%9E%E3%82%BB%E3%83%BC%E3%83%AB%E3%82%B9%E3%83%9E%E3%83%B3%E5%95%8F%E9%A1%8C)
