---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
    title: test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/euler_tour_vertex.cpp\"\n#include\
    \ <vector>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 4 \"Mylib/Graph/TreeUtils/euler_tour_vertex.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class euler_tour_vertex {\n\
    \    int pos_ = 0;\n    std::vector<int> begin_, end_;\n\n    void dfs(int cur,\
    \ int par, const tree<T> &tr){\n      begin_[cur] = pos_++;\n\n      for(auto\
    \ &e : tr[cur]){\n        if(e.to == par) continue;\n        dfs(e.to, cur, tr);\n\
    \      }\n\n      end_[cur] = pos_;\n    }\n\n  public:\n    euler_tour_vertex(){}\n\
    \    euler_tour_vertex(const tree<T> &tr, int root):\n      begin_(tr.size()),\
    \ end_(tr.size()){\n      dfs(root, -1, tr);\n    }\n\n    template <typename\
    \ F> // F = std::function<void(int, int)>\n    void subtree_query(int i, const\
    \ F &f){\n      f(begin_[i], end_[i]);\n    }\n\n    template <typename F> //\
    \ F = std::function<void(int)>\n    void point_query(int i, const F &f){\n   \
    \   f(begin_[i]);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class euler_tour_vertex {\n\
    \    int pos_ = 0;\n    std::vector<int> begin_, end_;\n\n    void dfs(int cur,\
    \ int par, const tree<T> &tr){\n      begin_[cur] = pos_++;\n\n      for(auto\
    \ &e : tr[cur]){\n        if(e.to == par) continue;\n        dfs(e.to, cur, tr);\n\
    \      }\n\n      end_[cur] = pos_;\n    }\n\n  public:\n    euler_tour_vertex(){}\n\
    \    euler_tour_vertex(const tree<T> &tr, int root):\n      begin_(tr.size()),\
    \ end_(tr.size()){\n      dfs(root, -1, tr);\n    }\n\n    template <typename\
    \ F> // F = std::function<void(int, int)>\n    void subtree_query(int i, const\
    \ F &f){\n      f(begin_[i], end_[i]);\n    }\n\n    template <typename F> //\
    \ F = std::function<void(int)>\n    void point_query(int i, const F &f){\n   \
    \   f(begin_[i]);\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/euler_tour_vertex.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp
documentation_of: Mylib/Graph/TreeUtils/euler_tour_vertex.cpp
layout: document
title: Euler tour (Vertex)
---

## Operations

## Requirements

## Notes

## Problems

## References
