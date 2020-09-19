---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':question:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
    title: Manhattan distance MST
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_2_A/main.kruskal.test.cpp
    title: test/aoj/GRL_2_A/main.kruskal.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/manhattanmst/main.test.cpp
    title: test/yosupo-judge/manhattanmst/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\n#include\
    \ <algorithm>\n#include <vector>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n\
    #include <iostream>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
    \n#include <numeric>\n#line 5 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n\
    \nnamespace haar_lib {\n  class unionfind {\n    int n;\n    mutable std::vector<int>\
    \ parent;\n    std::vector<int> depth, size;\n    int count;\n\n  public:\n  \
    \  unionfind(){}\n    unionfind(int n): n(n), parent(n), depth(n, 1), size(n,\
    \ 1), count(n){\n      std::iota(parent.begin(), parent.end(), 0);\n    }\n\n\
    \    int root_of(int i) const {\n      if(parent[i] == i) return i;\n      else\
    \ return parent[i] = root_of(parent[i]);\n    }\n\n    bool is_same(int i, int\
    \ j) const {return root_of(i) == root_of(j);}\n\n    int merge(int i, int j){\n\
    \      const int ri = root_of(i), rj = root_of(j);\n      if(ri == rj) return\
    \ ri;\n      else{\n        --count;\n        if(depth[ri] < depth[rj]){\n   \
    \       parent[ri] = rj;\n          size[rj] += size[ri];\n          return rj;\n\
    \        }else{\n          parent[rj] = ri;\n          size[ri] += size[rj];\n\
    \          if(depth[ri] == depth[rj]) ++depth[ri];\n          return ri;\n   \
    \     }\n      }\n    }\n\n    int size_of(int i) const {return size[root_of(i)];}\n\
    \n    int count_groups() const {return count;}\n\n    auto get_groups() const\
    \ {\n      std::vector<std::vector<int>> ret(n);\n\n      for(int i = 0; i < n;\
    \ ++i){\n        ret[root_of(i)].push_back(i);\n      }\n\n      ret.erase(\n\
    \        std::remove_if(\n          ret.begin(), ret.end(),\n          [](const\
    \ auto &a){return a.empty();}\n        ),\n        ret.end()\n      );\n\n   \
    \   return ret;\n    }\n  };\n}\n#line 6 \"Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<edge<T>> kruskal(const\
    \ graph<T> &graph){\n    const int n = graph.size();\n    std::vector<edge<T>>\
    \ edges;\n    for(auto &v : graph){\n      for(auto &e : v){\n        edges.push_back(e);\n\
    \      }\n    }\n\n    std::sort(edges.begin(), edges.end(), [](const auto &a,\
    \ const auto &b){return a.cost < b.cost;});\n\n    unionfind uf(n);\n\n    std::vector<edge<T>>\
    \ ret;\n\n    for(auto &e : edges){\n      if(!uf.is_same(e.from, e.to)){\n  \
    \      uf.merge(e.from, e.to);\n        ret.push_back(e);\n      }\n    }\n\n\
    \    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n#include \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<edge<T>> kruskal(const graph<T> &graph){\n\
    \    const int n = graph.size();\n    std::vector<edge<T>> edges;\n    for(auto\
    \ &v : graph){\n      for(auto &e : v){\n        edges.push_back(e);\n      }\n\
    \    }\n\n    std::sort(edges.begin(), edges.end(), [](const auto &a, const auto\
    \ &b){return a.cost < b.cost;});\n\n    unionfind uf(n);\n\n    std::vector<edge<T>>\
    \ ret;\n\n    for(auto &e : edges){\n      if(!uf.is_same(e.from, e.to)){\n  \
    \      uf.merge(e.from, e.to);\n        ret.push_back(e);\n      }\n    }\n\n\
    \    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  isVerificationFile: false
  path: Mylib/Graph/MinimumSpanningTree/kruskal.cpp
  requiredBy:
  - Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_2_A/main.kruskal.test.cpp
  - test/yosupo-judge/manhattanmst/main.test.cpp
documentation_of: Mylib/Graph/MinimumSpanningTree/kruskal.cpp
layout: document
title: Kruskal algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
