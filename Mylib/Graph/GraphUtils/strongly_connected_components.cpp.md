---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Graph/two_sat.cpp
    title: 2-SAT
  - icon: ':x:'
    path: Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp
    title: Chu-Liu/Edmonds algorithm
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_2_B/main.test.cpp
    title: test/aoj/GRL_2_B/main.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_3_C/main.test.cpp
    title: test/aoj/GRL_3_C/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/two_sat/main.test.cpp
    title: test/yosupo-judge/two_sat/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/scc/main.test.cpp
    title: test/yosupo-judge/scc/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
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
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<bool> visit(n);\n\
    \    std::vector<int> check(n);\n    std::vector<int> result(n, -1);\n\n    auto\
    \ dfs =\n      [&](auto &f, int cur) -> void {\n        visit[cur] = true;\n \
    \       for(const auto &e : g[cur]){\n          if(not visit[e.to]) f(f, e.to);\n\
    \        }\n        check.push_back(cur);\n      };\n\n    for(int i = 0; i <\
    \ n; ++i) if(not visit[i]) dfs(dfs, i);\n\n    std::reverse(check.begin(), check.end());\n\
    \n    graph<T> rg(n);\n\n    auto rdfs =\n      [&](auto &f, int cur, int i) ->\
    \ void {\n        result[cur] = i;\n        for(const auto &e : rg[cur]){\n  \
    \        if(result[e.to] == -1) f(f, e.to, i);\n        }\n      };\n\n    for(int\
    \ i = 0; i < n; ++i) for(const auto &e : g[i]) rg[e.to].emplace_back(e.to, e.from,\
    \ e.cost);\n\n    int i = 0;\n    for(auto c : check) if(result[c] == -1) rdfs(rdfs,\
    \ c, i), ++i;\n\n    return std::make_pair(result, i);\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto strongly_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<bool> visit(n);\n\
    \    std::vector<int> check(n);\n    std::vector<int> result(n, -1);\n\n    auto\
    \ dfs =\n      [&](auto &f, int cur) -> void {\n        visit[cur] = true;\n \
    \       for(const auto &e : g[cur]){\n          if(not visit[e.to]) f(f, e.to);\n\
    \        }\n        check.push_back(cur);\n      };\n\n    for(int i = 0; i <\
    \ n; ++i) if(not visit[i]) dfs(dfs, i);\n\n    std::reverse(check.begin(), check.end());\n\
    \n    graph<T> rg(n);\n\n    auto rdfs =\n      [&](auto &f, int cur, int i) ->\
    \ void {\n        result[cur] = i;\n        for(const auto &e : rg[cur]){\n  \
    \        if(result[e.to] == -1) f(f, e.to, i);\n        }\n      };\n\n    for(int\
    \ i = 0; i < n; ++i) for(const auto &e : g[i]) rg[e.to].emplace_back(e.to, e.from,\
    \ e.cost);\n\n    int i = 0;\n    for(auto c : check) if(result[c] == -1) rdfs(rdfs,\
    \ c, i), ++i;\n\n    return std::make_pair(result, i);\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
  requiredBy:
  - Mylib/Graph/two_sat.cpp
  - Mylib/Graph/MinimumSpanningTree/chu_liu_edmonds.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_2_B/main.test.cpp
  - test/aoj/GRL_3_C/main.test.cpp
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
