---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_2_B/main.test.cpp
    title: test/aoj/DPL_2_B/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/chinese_postman_problem.cpp\"\n#include <vector>\n\
    #include <algorithm>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/chinese_postman_problem.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T chinese_postman_problem(const\
    \ graph<T> &g){\n    const int n = g.size();\n    T ret = 0;\n\n    // \u9802\u70B9\
    \u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u3002\n    std::vector<std::vector<int>>\
    \ dist(n, std::vector<T>(n, -1));\n\n    for(int i = 0; i < n; ++i) dist[i][i]\
    \ = 0;\n\n    for(int i = 0; i < n; ++i){\n      for(auto &e : g[i]){\n      \
    \  if(dist[e.from][e.to] == -1) dist[e.from][e.to] = e.cost;\n        else dist[e.from][e.to]\
    \ = std::min(dist[e.from][e.to], e.cost);\n      }\n    }\n\n    for(int k = 0;\
    \ k < n; ++k){\n      for(int i = 0; i < n; ++i){\n        for(int j = 0; j <\
    \ n; ++j){\n          if(dist[i][k] >= 0 and dist[k][j] >= 0){\n            if(dist[i][j]\
    \ == -1) dist[i][j] = dist[i][k] + dist[k][j];\n            else dist[i][j] =\
    \ std::min(dist[i][j], dist[i][k] + dist[k][j]);\n          }\n        }\n   \
    \   }\n    }\n\n    // \u5947\u6570\u6B21\u6570\u306E\u9802\u70B9\u3092\u5217\u6319\
    \n    std::vector<int> odd;\n    for(int i = 0; i < n; ++i){\n      if(g[i].size()\
    \ % 2) odd.push_back(i);\n    }\n\n    const int m = odd.size();\n\n    // \u5947\
    \u6570\u6B21\u6570\u306E\u9802\u70B9\u9593\u306E\u6700\u5C0F\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u3092\u6C42\u3081\u308B\u3002\n    std::vector<T> dp(1 << m, -1);\n\
    \    dp[0] = 0;\n\n    for(int i = 0; i < (1 << m); ++i){\n      for(int j = 0;\
    \ j < m; ++j){\n        for(int k = 0; k < j; ++k){\n          if((i & (1 << j))\
    \ and (i & (1 << k))){\n            if(dp[i] == -1) dp[i] = dp[i ^ (1 << j) ^\
    \ (1 << k)] + dist[odd[j]][odd[k]];\n            else dp[i] = std::min(dp[i],\
    \ dp[i ^ (1 << j) ^ (1 << k)] + dist[odd[j]][odd[k]]);\n          }\n        }\n\
    \      }\n    }\n\n    // \u8FD4\u308A\u5024\u3092\u8A08\u7B97\n    for(int i\
    \ = 0; i < n; ++i){\n      for(auto &e : g[i]) if(e.from <= e.to) ret += e.cost;\n\
    \    }\n\n    ret += dp[(1 << m) - 1];\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T chinese_postman_problem(const\
    \ graph<T> &g){\n    const int n = g.size();\n    T ret = 0;\n\n    // \u9802\u70B9\
    \u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u3002\n    std::vector<std::vector<int>>\
    \ dist(n, std::vector<T>(n, -1));\n\n    for(int i = 0; i < n; ++i) dist[i][i]\
    \ = 0;\n\n    for(int i = 0; i < n; ++i){\n      for(auto &e : g[i]){\n      \
    \  if(dist[e.from][e.to] == -1) dist[e.from][e.to] = e.cost;\n        else dist[e.from][e.to]\
    \ = std::min(dist[e.from][e.to], e.cost);\n      }\n    }\n\n    for(int k = 0;\
    \ k < n; ++k){\n      for(int i = 0; i < n; ++i){\n        for(int j = 0; j <\
    \ n; ++j){\n          if(dist[i][k] >= 0 and dist[k][j] >= 0){\n            if(dist[i][j]\
    \ == -1) dist[i][j] = dist[i][k] + dist[k][j];\n            else dist[i][j] =\
    \ std::min(dist[i][j], dist[i][k] + dist[k][j]);\n          }\n        }\n   \
    \   }\n    }\n\n    // \u5947\u6570\u6B21\u6570\u306E\u9802\u70B9\u3092\u5217\u6319\
    \n    std::vector<int> odd;\n    for(int i = 0; i < n; ++i){\n      if(g[i].size()\
    \ % 2) odd.push_back(i);\n    }\n\n    const int m = odd.size();\n\n    // \u5947\
    \u6570\u6B21\u6570\u306E\u9802\u70B9\u9593\u306E\u6700\u5C0F\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u3092\u6C42\u3081\u308B\u3002\n    std::vector<T> dp(1 << m, -1);\n\
    \    dp[0] = 0;\n\n    for(int i = 0; i < (1 << m); ++i){\n      for(int j = 0;\
    \ j < m; ++j){\n        for(int k = 0; k < j; ++k){\n          if((i & (1 << j))\
    \ and (i & (1 << k))){\n            if(dp[i] == -1) dp[i] = dp[i ^ (1 << j) ^\
    \ (1 << k)] + dist[odd[j]][odd[k]];\n            else dp[i] = std::min(dp[i],\
    \ dp[i ^ (1 << j) ^ (1 << k)] + dist[odd[j]][odd[k]]);\n          }\n        }\n\
    \      }\n    }\n\n    // \u8FD4\u308A\u5024\u3092\u8A08\u7B97\n    for(int i\
    \ = 0; i < n; ++i){\n      for(auto &e : g[i]) if(e.from <= e.to) ret += e.cost;\n\
    \    }\n\n    ret += dp[(1 << m) - 1];\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/chinese_postman_problem.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_2_B/main.test.cpp
documentation_of: Mylib/Graph/chinese_postman_problem.cpp
layout: document
title: Chinese postman problem
---

## Operations

- `chinese_postman_problem(g)`
	- すべての辺を一度以上通る閉路の最小距離を返す。
	- Time complexity $O(n^2 2^n)$

## Requirements

## Notes

## Problems

- [AOJ DPL_2_B Chinese Postman Problem](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_B)

## References

- [https://ja.wikipedia.org/wiki/%E4%B8%AD%E5%9B%BD%E4%BA%BA%E9%83%B5%E4%BE%BF%E9%85%8D%E9%81%94%E5%95%8F%E9%A1%8C](https://ja.wikipedia.org/wiki/%E4%B8%AD%E5%9B%BD%E4%BA%BA%E9%83%B5%E4%BE%BF%E9%85%8D%E9%81%94%E5%95%8F%E9%A1%8C)
