---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/922/main.test.cpp
    title: test/yukicoder/922/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/forest.cpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <utility>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/TreeUtils/forest.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct forest {\n    std::vector<tree<T>>\
    \ trees;\n    std::vector<int> tree_id;\n    std::vector<int> vertex_id;\n   \
    \ std::vector<std::vector<int>> rid;\n\n    forest(const graph<T> &g){\n     \
    \ const int N = g.size();\n\n      tree_id.resize(N);\n      vertex_id.resize(N);\n\
    \n      std::vector<bool> check(N);\n\n      auto dfs =\n        [&](auto &dfs,\
    \ int cur, std::vector<int> &vertices, std::vector<edge<T>> &edges) -> void {\n\
    \          check[cur] = true;\n          vertices.push_back(cur);\n\n        \
    \  for(auto &e : g[cur]){\n            edges.push_back(e);\n\n            if(not\
    \ check[e.to]){\n              dfs(dfs, e.to, vertices, edges);\n            }\n\
    \          }\n        };\n\n      for(int i = 0; i < N; ++i){\n        if(not\
    \ check[i]){\n          std::vector<int> vertices;\n          std::vector<edge<T>>\
    \ edges;\n          dfs(dfs, i, vertices, edges);\n\n          const int m = vertices.size();\n\
    \          const int k = trees.size();\n\n          rid.emplace_back(m);\n\n \
    \         for(int i = 0; i < (int)vertices.size(); ++i){\n            tree_id[vertices[i]]\
    \ = k;\n            vertex_id[vertices[i]] = i;\n            rid[k][i] = vertices[i];\n\
    \          }\n\n          trees.push_back(m);\n\n          for(auto &e : edges){\n\
    \            trees[k].add_edge(vertex_id[e.from], vertex_id[e.to], e.cost);\n\
    \          }\n        }\n      }\n    }\n\n    bool in_same_tree(int i, int j)\
    \ const {\n      return tree_id[i] == tree_id[j];\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <utility>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  struct forest {\n    std::vector<tree<T>> trees;\n    std::vector<int>\
    \ tree_id;\n    std::vector<int> vertex_id;\n    std::vector<std::vector<int>>\
    \ rid;\n\n    forest(const graph<T> &g){\n      const int N = g.size();\n\n  \
    \    tree_id.resize(N);\n      vertex_id.resize(N);\n\n      std::vector<bool>\
    \ check(N);\n\n      auto dfs =\n        [&](auto &dfs, int cur, std::vector<int>\
    \ &vertices, std::vector<edge<T>> &edges) -> void {\n          check[cur] = true;\n\
    \          vertices.push_back(cur);\n\n          for(auto &e : g[cur]){\n    \
    \        edges.push_back(e);\n\n            if(not check[e.to]){\n           \
    \   dfs(dfs, e.to, vertices, edges);\n            }\n          }\n        };\n\
    \n      for(int i = 0; i < N; ++i){\n        if(not check[i]){\n          std::vector<int>\
    \ vertices;\n          std::vector<edge<T>> edges;\n          dfs(dfs, i, vertices,\
    \ edges);\n\n          const int m = vertices.size();\n          const int k =\
    \ trees.size();\n\n          rid.emplace_back(m);\n\n          for(int i = 0;\
    \ i < (int)vertices.size(); ++i){\n            tree_id[vertices[i]] = k;\n   \
    \         vertex_id[vertices[i]] = i;\n            rid[k][i] = vertices[i];\n\
    \          }\n\n          trees.push_back(m);\n\n          for(auto &e : edges){\n\
    \            trees[k].add_edge(vertex_id[e.from], vertex_id[e.to], e.cost);\n\
    \          }\n        }\n      }\n    }\n\n    bool in_same_tree(int i, int j)\
    \ const {\n      return tree_id[i] == tree_id[j];\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/forest.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/922/main.test.cpp
documentation_of: Mylib/Graph/TreeUtils/forest.cpp
layout: document
title: Decompose forest
---

## Operations

## Requirements

## Notes

## Problems

## References
