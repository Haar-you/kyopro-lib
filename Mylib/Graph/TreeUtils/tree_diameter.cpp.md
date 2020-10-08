---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_A/main.test.cpp
    title: test/aoj/GRL_5_A/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/tree_diameter/main.test.cpp
    title: test/yosupo-judge/tree_diameter/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/tree_diameter.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <stack>\n#include <algorithm>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 7 \"Mylib/Graph/TreeUtils/tree_diameter.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::pair<T, std::vector<int>>\
    \ tree_diameter(const tree<T> &tr){\n    const int N = tr.size();\n\n    std::vector<bool>\
    \ check(N);\n    std::vector<T> dp(N);\n    std::stack<int> st;\n\n    st.push(0);\n\
    \    while(st.size()){\n      int i = st.top(); st.pop();\n\n      check[i] =\
    \ true;\n\n      for(const auto &e : tr[i]){\n        if(not check[e.to]){\n \
    \         dp[e.to] = dp[i] + e.cost;\n          st.push(e.to);\n        }\n  \
    \    }\n    }\n\n    const int u = std::max_element(dp.begin(), dp.end()) - dp.begin();\n\
    \n    dp.assign(N, 0);\n    check.assign(N, false);\n\n    std::vector<int> prev(N);\n\
    \n    st.push(u);\n    while(st.size()){\n      int i = st.top(); st.pop();\n\n\
    \      check[i] = true;\n\n      for(const auto &e : tr[i]){\n        if(not check[e.to]){\n\
    \          dp[e.to] = dp[i] + e.cost;\n          st.push(e.to);\n          prev[e.to]\
    \ = i;\n        }\n      }\n    }\n\n    const int v = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n\n    std::vector<int> ret;\n\n    int cur = v;\n \
    \   while(1){\n      ret.push_back(cur);\n      if(cur == u) break;\n      cur\
    \ = prev[cur];\n    }\n\n    return std::make_pair(dp[v], ret);\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <stack>\n#include\
    \ <algorithm>\n#include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::pair<T, std::vector<int>> tree_diameter(const\
    \ tree<T> &tr){\n    const int N = tr.size();\n\n    std::vector<bool> check(N);\n\
    \    std::vector<T> dp(N);\n    std::stack<int> st;\n\n    st.push(0);\n    while(st.size()){\n\
    \      int i = st.top(); st.pop();\n\n      check[i] = true;\n\n      for(const\
    \ auto &e : tr[i]){\n        if(not check[e.to]){\n          dp[e.to] = dp[i]\
    \ + e.cost;\n          st.push(e.to);\n        }\n      }\n    }\n\n    const\
    \ int u = std::max_element(dp.begin(), dp.end()) - dp.begin();\n\n    dp.assign(N,\
    \ 0);\n    check.assign(N, false);\n\n    std::vector<int> prev(N);\n\n    st.push(u);\n\
    \    while(st.size()){\n      int i = st.top(); st.pop();\n\n      check[i] =\
    \ true;\n\n      for(const auto &e : tr[i]){\n        if(not check[e.to]){\n \
    \         dp[e.to] = dp[i] + e.cost;\n          st.push(e.to);\n          prev[e.to]\
    \ = i;\n        }\n      }\n    }\n\n    const int v = std::max_element(dp.begin(),\
    \ dp.end()) - dp.begin();\n\n    std::vector<int> ret;\n\n    int cur = v;\n \
    \   while(1){\n      ret.push_back(cur);\n      if(cur == u) break;\n      cur\
    \ = prev[cur];\n    }\n\n    return std::make_pair(dp[v], ret);\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/tree_diameter.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/tree_diameter/main.test.cpp
  - test/aoj/GRL_5_A/main.test.cpp
documentation_of: Mylib/Graph/TreeUtils/tree_diameter.cpp
layout: document
title: Tree diameter
---

## Operations

## Requirements

## Notes

## Problems

## References
