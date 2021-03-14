---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C/main.hld.test.cpp
    title: test/aoj/GRL_5_C/main.hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/lca_hld.cpp\"\n#include <vector>\n\
    #include <utility>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/TreeUtils/lca_hld.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class lowest_common_ancestor_hld\
    \ {\n    int n_;\n    std::vector<int> sub_, par_, head_, id_;\n\n    int dfs_sub(int\
    \ cur, int p, tree<T> &tr){\n      par_[cur] = p;\n      int t = 0;\n      for(auto\
    \ &e : tr[cur]){\n        if(e.to == p) continue;\n        sub_[cur] += dfs_sub(e.to,\
    \ cur, tr);\n        if(sub_[e.to] > t){\n          t = sub_[e.to];\n        \
    \  std::swap(e, tr[cur][0]);\n        }\n      }\n      return sub_[cur];\n  \
    \  }\n\n    void dfs_build(int cur, int &i, tree<T> &tr){\n      id_[cur] = i;\n\
    \      ++i;\n\n      for(auto &e : tr[cur]){\n        if(e.to == par_[cur]) continue;\n\
    \        head_[e.to] = (e.to == tr[cur][0].to ? head_[cur] : e.to);\n        dfs_build(e.to,\
    \ i, tr);\n      }\n    }\n\n  public:\n    lowest_common_ancestor_hld(){}\n \
    \   lowest_common_ancestor_hld(tree<T> tr, int root):\n      n_(tr.size()), sub_(n_,\
    \ 1), par_(n_, -1), head_(n_), id_(n_){\n      dfs_sub(root, -1, tr);\n      int\
    \ i = 0;\n      dfs_build(root, i, tr);\n    }\n\n    int lca(int u, int v) const\
    \ {\n      while(1){\n        if(id_[u] > id_[v]) std::swap(u, v);\n        if(head_[u]\
    \ == head_[v]) return u;\n        v = par_[head_[v]];\n      }\n    }\n\n    int\
    \ operator()(int u, int v) const {return lca(u, v);}\n\n    T distance(int u,\
    \ int v, const std::vector<T> &dist) const {\n      return dist[u] + dist[v] -\
    \ 2 * dist[lca(u, v)];\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class lowest_common_ancestor_hld\
    \ {\n    int n_;\n    std::vector<int> sub_, par_, head_, id_;\n\n    int dfs_sub(int\
    \ cur, int p, tree<T> &tr){\n      par_[cur] = p;\n      int t = 0;\n      for(auto\
    \ &e : tr[cur]){\n        if(e.to == p) continue;\n        sub_[cur] += dfs_sub(e.to,\
    \ cur, tr);\n        if(sub_[e.to] > t){\n          t = sub_[e.to];\n        \
    \  std::swap(e, tr[cur][0]);\n        }\n      }\n      return sub_[cur];\n  \
    \  }\n\n    void dfs_build(int cur, int &i, tree<T> &tr){\n      id_[cur] = i;\n\
    \      ++i;\n\n      for(auto &e : tr[cur]){\n        if(e.to == par_[cur]) continue;\n\
    \        head_[e.to] = (e.to == tr[cur][0].to ? head_[cur] : e.to);\n        dfs_build(e.to,\
    \ i, tr);\n      }\n    }\n\n  public:\n    lowest_common_ancestor_hld(){}\n \
    \   lowest_common_ancestor_hld(tree<T> tr, int root):\n      n_(tr.size()), sub_(n_,\
    \ 1), par_(n_, -1), head_(n_), id_(n_){\n      dfs_sub(root, -1, tr);\n      int\
    \ i = 0;\n      dfs_build(root, i, tr);\n    }\n\n    int lca(int u, int v) const\
    \ {\n      while(1){\n        if(id_[u] > id_[v]) std::swap(u, v);\n        if(head_[u]\
    \ == head_[v]) return u;\n        v = par_[head_[v]];\n      }\n    }\n\n    int\
    \ operator()(int u, int v) const {return lca(u, v);}\n\n    T distance(int u,\
    \ int v, const std::vector<T> &dist) const {\n      return dist[u] + dist[v] -\
    \ 2 * dist[lca(u, v)];\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/lca_hld.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_C/main.hld.test.cpp
documentation_of: Mylib/Graph/TreeUtils/lca_hld.cpp
layout: document
title: Lowest common ancestor (HLD)
---

## Operations

## Requirements

## Notes

## Problems

## References
