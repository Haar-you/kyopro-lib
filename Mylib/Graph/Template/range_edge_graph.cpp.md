---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Template/range_edge_graph.cpp\"\n#include <utility>\n\
    #include <cassert>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include <vector>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/Template/range_edge_graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class range_edge_graph :\
    \ public graph<T> {\n    using super = graph<T>;\n\n    int k_, N_;\n\n    int\
    \ calc_size(int N) const {\n      int ret = 1;\n      while(ret < N) ret *= 2;\n\
    \      return ret;\n    }\n\n  public:\n    range_edge_graph(){}\n    range_edge_graph(int\
    \ N): graph<T>(5 * (k_ = (calc_size(N)))), N_(N){\n      for(int i = 2; i < 2\
    \ * k_; ++i){\n        super::add_edge(k_ + (i >> 1), k_ + i, 0);\n        super::add_edge(3\
    \ * k_ + i, 3 * k_ + (i >> 1), 0);\n      }\n\n      for(int i = 0; i < N_; ++i){\n\
    \        super::add_edge(2 * k_ + i, i, 0);\n        super::add_edge(i, 4 * k_\
    \ + i, 0);\n      }\n    }\n\n    void add_edge(int i, int j, T w){\n      super::add_edge(i,\
    \ j, w);\n    }\n\n    void add_edge(int i, std::pair<int, int> p, T w){\n   \
    \   auto [l, r] = p;\n      for(l += k_, r += k_; l < r; l >>= 1, r >>= 1){\n\
    \        if(l & 1) super::add_edge(i, l + k_, w), ++l;\n        if(r & 1) --r,\
    \ super::add_edge(i, r + k_, w);\n      }\n    }\n\n    void add_edge(std::pair<int,\
    \ int> p, int i, T w){\n      auto [l, r] = p;\n      for(l += k_, r += k_; l\
    \ < r; l >>= 1, r >>= 1){\n        if(l & 1) super::add_edge(l + 3 * k_, i, w),\
    \ ++l;\n        if(r & 1) --r, super::add_edge(r + 3 * k_, i, w);\n      }\n \
    \   }\n\n    void add_edge(std::pair<int, int> p, std::pair<int, int> q, T w){\n\
    \      int x = super::size();\n      super::ds.emplace_back();\n      int y =\
    \ super::size();\n      super::ds.emplace_back();\n\n      add_edge(p, x, 0);\n\
    \      add_edge(x, y, w);\n      add_edge(y, q, 0);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <utility>\n#include <cassert>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class range_edge_graph :\
    \ public graph<T> {\n    using super = graph<T>;\n\n    int k_, N_;\n\n    int\
    \ calc_size(int N) const {\n      int ret = 1;\n      while(ret < N) ret *= 2;\n\
    \      return ret;\n    }\n\n  public:\n    range_edge_graph(){}\n    range_edge_graph(int\
    \ N): graph<T>(5 * (k_ = (calc_size(N)))), N_(N){\n      for(int i = 2; i < 2\
    \ * k_; ++i){\n        super::add_edge(k_ + (i >> 1), k_ + i, 0);\n        super::add_edge(3\
    \ * k_ + i, 3 * k_ + (i >> 1), 0);\n      }\n\n      for(int i = 0; i < N_; ++i){\n\
    \        super::add_edge(2 * k_ + i, i, 0);\n        super::add_edge(i, 4 * k_\
    \ + i, 0);\n      }\n    }\n\n    void add_edge(int i, int j, T w){\n      super::add_edge(i,\
    \ j, w);\n    }\n\n    void add_edge(int i, std::pair<int, int> p, T w){\n   \
    \   auto [l, r] = p;\n      for(l += k_, r += k_; l < r; l >>= 1, r >>= 1){\n\
    \        if(l & 1) super::add_edge(i, l + k_, w), ++l;\n        if(r & 1) --r,\
    \ super::add_edge(i, r + k_, w);\n      }\n    }\n\n    void add_edge(std::pair<int,\
    \ int> p, int i, T w){\n      auto [l, r] = p;\n      for(l += k_, r += k_; l\
    \ < r; l >>= 1, r >>= 1){\n        if(l & 1) super::add_edge(l + 3 * k_, i, w),\
    \ ++l;\n        if(r & 1) --r, super::add_edge(r + 3 * k_, i, w);\n      }\n \
    \   }\n\n    void add_edge(std::pair<int, int> p, std::pair<int, int> q, T w){\n\
    \      int x = super::size();\n      super::ds.emplace_back();\n      int y =\
    \ super::size();\n      super::ds.emplace_back();\n\n      add_edge(p, x, 0);\n\
    \      add_edge(x, y, w);\n      add_edge(y, q, 0);\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/Template/range_edge_graph.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/Template/range_edge_graph.cpp
layout: document
title: Range edge graph
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #406 (Div. 1) B. Legacy](https://codeforces.com/contest/786/problem/B)
- [D - Shortest Path on a Line](https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d)

## References

- [https://ei1333.hateblo.jp/entry/2017/12/14/000000](https://ei1333.hateblo.jp/entry/2017/12/14/000000)
- [https://twitter.com/noshi91/status/1193177214453338113](https://twitter.com/noshi91/status/1193177214453338113)
- [https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)
