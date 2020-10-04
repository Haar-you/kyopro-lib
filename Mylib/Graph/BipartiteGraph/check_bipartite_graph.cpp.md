---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2370/main.test.cpp
    title: test/aoj/2370/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp\"\n\
    #include <vector>\n#include <optional>\n#include <stack>\n#include <utility>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 7 \"Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto check_bipartite_graph(const\
    \ graph<T> &g){\n    std::vector<std::optional<std::pair<std::vector<int>, std::vector<int>>>>\
    \ ret;\n\n    const int N = g.size();\n\n    std::vector<int> check(N, -1);\n\
    \    std::vector<bool> visit(N);\n\n    for(int i = 0; i < N; ++i){\n      if(visit[i])\
    \ continue;\n\n      std::vector<int> a, b;\n\n      bool res =\n        [&](){\n\
    \          std::stack<int> st;\n\n          st.push(i);\n          check[i] =\
    \ 0;\n          a.push_back(i);\n\n          while(not st.empty()){\n        \
    \    auto cur = st.top(); st.pop();\n            if(visit[cur]) continue;\n  \
    \          visit[cur] = true;\n\n            for(auto &e : g[cur]){\n        \
    \      if(check[e.to] == check[cur]) return false;\n\n              if(check[e.to]\
    \ == -1){\n                if(check[cur] == 0){\n                  check[e.to]\
    \ = 1;\n                  b.push_back(e.to);\n                }else{\n       \
    \           check[e.to] = 0;\n                  a.push_back(e.to);\n         \
    \       }\n\n                st.push(e.to);\n              }\n            }\n\
    \          }\n\n          return true;\n        }();\n\n      if(res){\n     \
    \   ret.emplace_back(std::make_pair(a, b));\n      }else{\n        ret.emplace_back();\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <stack>\n\
    #include <utility>\n#include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  auto check_bipartite_graph(const graph<T> &g){\n\
    \    std::vector<std::optional<std::pair<std::vector<int>, std::vector<int>>>>\
    \ ret;\n\n    const int N = g.size();\n\n    std::vector<int> check(N, -1);\n\
    \    std::vector<bool> visit(N);\n\n    for(int i = 0; i < N; ++i){\n      if(visit[i])\
    \ continue;\n\n      std::vector<int> a, b;\n\n      bool res =\n        [&](){\n\
    \          std::stack<int> st;\n\n          st.push(i);\n          check[i] =\
    \ 0;\n          a.push_back(i);\n\n          while(not st.empty()){\n        \
    \    auto cur = st.top(); st.pop();\n            if(visit[cur]) continue;\n  \
    \          visit[cur] = true;\n\n            for(auto &e : g[cur]){\n        \
    \      if(check[e.to] == check[cur]) return false;\n\n              if(check[e.to]\
    \ == -1){\n                if(check[cur] == 0){\n                  check[e.to]\
    \ = 1;\n                  b.push_back(e.to);\n                }else{\n       \
    \           check[e.to] = 0;\n                  a.push_back(e.to);\n         \
    \       }\n\n                st.push(e.to);\n              }\n            }\n\
    \          }\n\n          return true;\n        }();\n\n      if(res){\n     \
    \   ret.emplace_back(std::make_pair(a, b));\n      }else{\n        ret.emplace_back();\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2370/main.test.cpp
documentation_of: Mylib/Graph/BipartiteGraph/check_bipartite_graph.cpp
layout: document
title: Check bipartite graph
---

## Operations

## Requirements

## Notes

## Problems

- [Maximum-Cup 2018 C - 嘘つきな天使たち](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_c)
- [ARC 099 E - Independence](https://atcoder.jp/contests/arc099/tasks/arc099_c)

## References

