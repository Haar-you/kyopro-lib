---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/centroid_decomposition.cpp\"\n#include\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 4 \"Mylib/Graph/TreeUtils/centroid_decomposition.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class centroid_decomposition\
    \ {\n    int N_;\n    std::vector<int> parent_, subsize_;\n    std::vector<std::vector<int>>\
    \ children_;\n    std::vector<bool> check_;\n\n  public:\n    centroid_decomposition(){}\n\
    \    centroid_decomposition(const tree<T> &tr):\n      N_(tr.size()), parent_(N_),\
    \ subsize_(N_), children_(N_), check_(N_)\n    {\n      decompose(tr, 0, -1);\n\
    \    }\n\n  private:\n    void decompose(const tree<T> &tr, int cur, int par){\n\
    \      dfs_subsize(tr, cur, -1);\n      auto c = get_centroid(tr, cur, -1, subsize_[cur]);\n\
    \n      check_[c] = true;\n      parent_[c] = par;\n      if(par != -1) children_[par].push_back(c);\n\
    \n      for(auto &e : tr[c]){\n        if(check_[e.to]) continue;\n        decompose(tr,\
    \ e.to, c);\n      }\n    }\n\n    int get_centroid(const tree<T> &tr, int cur,\
    \ int par, int total_size){\n      for(auto &e : tr[cur]){\n        if(e.to ==\
    \ par or check_[e.to]) continue;\n\n        if(2 * subsize_[e.to] > total_size){\n\
    \          return get_centroid(tr, e.to, cur, total_size);\n        }\n      }\n\
    \n      return cur;\n    }\n\n    void dfs_subsize(const tree<T> &tr, int cur,\
    \ int par){\n      subsize_[cur] = 1;\n      for(auto &e : tr[cur]){\n       \
    \ if(e.to == par or check_[e.to]) continue;\n        dfs_subsize(tr, e.to, cur);\n\
    \        subsize_[cur] += subsize_[e.to];\n      }\n    }\n\n  public:\n    auto\
    \ bottom_up(int i) const {\n      std::vector<int> ret;\n      while(i >= 0){\n\
    \        ret.push_back(i);\n        i = parent_[i];\n      }\n      return ret;\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class centroid_decomposition\
    \ {\n    int N_;\n    std::vector<int> parent_, subsize_;\n    std::vector<std::vector<int>>\
    \ children_;\n    std::vector<bool> check_;\n\n  public:\n    centroid_decomposition(){}\n\
    \    centroid_decomposition(const tree<T> &tr):\n      N_(tr.size()), parent_(N_),\
    \ subsize_(N_), children_(N_), check_(N_)\n    {\n      decompose(tr, 0, -1);\n\
    \    }\n\n  private:\n    void decompose(const tree<T> &tr, int cur, int par){\n\
    \      dfs_subsize(tr, cur, -1);\n      auto c = get_centroid(tr, cur, -1, subsize_[cur]);\n\
    \n      check_[c] = true;\n      parent_[c] = par;\n      if(par != -1) children_[par].push_back(c);\n\
    \n      for(auto &e : tr[c]){\n        if(check_[e.to]) continue;\n        decompose(tr,\
    \ e.to, c);\n      }\n    }\n\n    int get_centroid(const tree<T> &tr, int cur,\
    \ int par, int total_size){\n      for(auto &e : tr[cur]){\n        if(e.to ==\
    \ par or check_[e.to]) continue;\n\n        if(2 * subsize_[e.to] > total_size){\n\
    \          return get_centroid(tr, e.to, cur, total_size);\n        }\n      }\n\
    \n      return cur;\n    }\n\n    void dfs_subsize(const tree<T> &tr, int cur,\
    \ int par){\n      subsize_[cur] = 1;\n      for(auto &e : tr[cur]){\n       \
    \ if(e.to == par or check_[e.to]) continue;\n        dfs_subsize(tr, e.to, cur);\n\
    \        subsize_[cur] += subsize_[e.to];\n      }\n    }\n\n  public:\n    auto\
    \ bottom_up(int i) const {\n      std::vector<int> ret;\n      while(i >= 0){\n\
    \        ret.push_back(i);\n        i = parent_[i];\n      }\n      return ret;\n\
    \    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/centroid_decomposition.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/TreeUtils/centroid_decomposition.cpp
layout: document
title: Centroid decomposition
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #199 (Div. 2) E. Xenia and Tree](https://codeforces.com/contest/342/problem/E)

## References

- [https://www.hamayanhamayan.com/entry/2017/12/19/152143](https://www.hamayanhamayan.com/entry/2017/12/19/152143)
- [http://techtipshoge.blogspot.com/2016/09/centroid-decomposition.html](http://techtipshoge.blogspot.com/2016/09/centroid-decomposition.html)
- [https://ferin-tech.hatenablog.com/entry/2020/03/06/162311](https://ferin-tech.hatenablog.com/entry/2020/03/06/162311)
