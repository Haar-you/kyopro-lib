---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Graph/TreeUtils/tree_height.cpp
    title: Tree height
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_B/main.test.cpp
    title: test/aoj/GRL_5_B/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/922/main.test.cpp
    title: test/yukicoder/922/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/tree_distance.cpp\"\n#include <stack>\n\
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
    Mylib/Graph/TreeUtils/tree_distance.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<T> tree_distance(const tree<T> &tr, int root) {\n\
    \    const int n = tr.size();\n    std::vector<T> ret(n);\n    std::vector<bool>\
    \ visited(n);\n\n    std::stack<int> st;\n    st.push(root);\n    ret[root] =\
    \ 0;\n\n    while (not st.empty()) {\n      int cur = st.top();\n      st.pop();\n\
    \      visited[cur] = true;\n\n      for (auto &e : tr[cur]) {\n        if (not\
    \ visited[e.to]) {\n          ret[e.to] = ret[cur] + e.cost;\n          st.push(e.to);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <stack>\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> tree_distance(const\
    \ tree<T> &tr, int root) {\n    const int n = tr.size();\n    std::vector<T> ret(n);\n\
    \    std::vector<bool> visited(n);\n\n    std::stack<int> st;\n    st.push(root);\n\
    \    ret[root] = 0;\n\n    while (not st.empty()) {\n      int cur = st.top();\n\
    \      st.pop();\n      visited[cur] = true;\n\n      for (auto &e : tr[cur])\
    \ {\n        if (not visited[e.to]) {\n          ret[e.to] = ret[cur] + e.cost;\n\
    \          st.push(e.to);\n        }\n      }\n    }\n\n    return ret;\n  }\n\
    }  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/tree_distance.cpp
  requiredBy:
  - Mylib/Graph/TreeUtils/tree_height.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_5_B/main.test.cpp
  - test/yukicoder/922/main.test.cpp
documentation_of: Mylib/Graph/TreeUtils/tree_distance.cpp
layout: document
title: Tree distance
---

## Operations

## Requirements

## Notes

## Problems

## References