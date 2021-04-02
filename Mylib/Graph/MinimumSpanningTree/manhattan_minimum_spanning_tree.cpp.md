---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/manhattanmst/main.test.cpp
    title: test/yosupo-judge/manhattanmst/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <algorithm>\n#include <numeric>\n\
    #include <cmath>\n#line 3 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n#include\
    \ <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct min_monoid\
    \ {\n    using value_type = std::optional<T>;\n\n    value_type operator()() const\
    \ {return {};}\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if(not a) return b;\n      if(not b) return a;\n      return\
    \ {std::min(*a, *b)};\n    }\n  };\n}\n#line 4 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <functional>\n#include <cassert>\n\nnamespace haar_lib {\n  template\
    \ <typename Monoid>\n  class segment_tree {\n  public:\n    using value_type =\
    \ typename Monoid::value_type;\n\n  private:\n    Monoid M_;\n    int depth_,\
    \ size_, hsize_;\n    std::vector<value_type> data_;\n\n  public:\n    segment_tree(){}\n\
    \    segment_tree(int n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1\
    \ : 1),\n      size_(1 << depth_), hsize_(size_ / 2),\n      data_(size_, M_())\n\
    \    {}\n\n    auto operator[](int i) const {\n      assert(0 <= i and i < hsize_);\n\
    \      return data_[hsize_ + i];\n    }\n\n    auto fold(int l, int r) const {\n\
    \      assert(0 <= l and l <= r and r <= hsize_);\n      value_type ret_left =\
    \ M_();\n      value_type ret_right = M_();\n\n      int L = l + hsize_, R = r\
    \ + hsize_;\n      while(L < R){\n        if(R & 1) ret_right = M_(data_[--R],\
    \ ret_right);\n        if(L & 1) ret_left = M_(ret_left, data_[L++]);\n      \
    \  L >>= 1, R >>= 1;\n      }\n\n      return M_(ret_left, ret_right);\n    }\n\
    \n    auto fold_all() const {\n      return data_[1];\n    }\n\n    void set(int\
    \ i, const value_type &x){\n      assert(0 <= i and i < hsize_);\n      i += hsize_;\n\
    \      data_[i] = x;\n      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 |\
    \ 0], data_[i << 1 | 1]);\n    }\n\n    void update(int i, const value_type &x){\n\
    \      assert(0 <= i and i < hsize_);\n      i += hsize_;\n      data_[i] = M_(data_[i],\
    \ x);\n      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i <<\
    \ 1 | 1]);\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val){\n      data_.assign(size_, M_());\n      for(int i = 0;\
    \ i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n      for(int i = hsize_;\
    \ --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n \
    \   template <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize_,\
    \ val));\n    }\n\n  private:\n    template <bool Lower, typename F>\n    int\
    \ bound(const int l, const int r, value_type x, F f) const {\n      std::vector<int>\
    \ pl, pr;\n      int L = l + hsize_;\n      int R = r + hsize_;\n      while(L\
    \ < R){\n        if(R & 1) pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n\
    \        L >>= 1, R >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n\
    \      pl.insert(pl.end(), pr.begin(), pr.end());\n\n      value_type a = M_();\n\
    \n      for(int i : pl){\n        auto b = M_(a, data_[i]);\n\n        if((Lower\
    \ and not f(b, x)) or (not Lower and f(x, b))){\n          while(i < hsize_){\n\
    \            const auto c = M_(a, data_[i << 1 | 0]);\n            if((Lower and\
    \ not f(c, x)) or (not Lower and f(x, c))){\n              i = i << 1 | 0;\n \
    \           }else{\n              a = c;\n              i = i << 1 | 1;\n    \
    \        }\n          }\n\n          return i - hsize_;\n        }\n\n       \
    \ a = b;\n      }\n\n      return r;\n    }\n\n  public:\n    template <typename\
    \ F = std::less<value_type>>\n    int lower_bound(int l, int r, value_type x,\
    \ F f = F()) const {\n      return bound<true>(l, r, x, f);\n    }\n\n    template\
    \ <typename F = std::less<value_type>>\n    int upper_bound(int l, int r, value_type\
    \ x, F f = F()) const {\n      return bound<false>(l, r, x, f);\n    }\n  };\n\
    }\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct edge {\n    int from, to;\n  \
    \  T cost;\n    int index = -1;\n    edge(){}\n    edge(int from, int to, T cost):\
    \ from(from), to(to), cost(cost){}\n    edge(int from, int to, T cost, int index):\
    \ from(from), to(to), cost(cost), index(index){}\n  };\n\n  template <typename\
    \ T>\n  struct graph {\n    using weight_type = T;\n    using edge_type = edge<T>;\n\
    \n    std::vector<std::vector<edge<T>>> data;\n\n    auto& operator[](size_t i){return\
    \ data[i];}\n    const auto& operator[](size_t i) const {return data[i];}\n\n\
    \    auto begin() const {return data.begin();}\n    auto end() const {return data.end();}\n\
    \n    graph(){}\n    graph(int N): data(N){}\n\n    bool empty() const {return\
    \ data.empty();}\n    int size() const {return data.size();}\n\n    void add_edge(int\
    \ i, int j, T w, int index = -1){\n      data[i].emplace_back(i, j, w, index);\n\
    \    }\n\n    void add_undirected(int i, int j, T w, int index = -1){\n      add_edge(i,\
    \ j, w, index);\n      add_edge(j, i, w, index);\n    }\n\n    template <size_t\
    \ I, bool DIRECTED = true, bool WEIGHTED = true>\n    void read(int M){\n    \
    \  for(int i = 0; i < M; ++i){\n        int u, v; std::cin >> u >> v;\n      \
    \  u -= I;\n        v -= I;\n        T w = 1;\n        if(WEIGHTED) std::cin >>\
    \ w;\n        if(DIRECTED) add_edge(u, v, w, i);\n        else add_undirected(u,\
    \ v, w, i);\n      }\n    }\n  };\n\n  template <typename T>\n  using tree = graph<T>;\n\
    }\n#line 10 \"Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, typename MST>\n  std::vector<edge<T>>\
    \ manhattan_minimum_spanning_tree(std::vector<T> x, std::vector<T> y, MST mst){\n\
    \    const int N = x.size();\n    graph<T> g(N);\n    segment_tree<min_monoid<std::pair<T,\
    \ int>>> seg(N);\n\n    auto f =\n      [&](){\n        std::vector<T> Y(y);\n\
    \        std::sort(Y.begin(), Y.end());\n        Y.erase(std::unique(Y.begin(),\
    \ Y.end()), Y.end());\n\n        seg.init(std::nullopt);\n\n        std::vector<int>\
    \ ord(N);\n        std::iota(ord.begin(), ord.end(), 0);\n        std::sort(\n\
    \          ord.begin(), ord.end(),\n          [&](int i, int j){\n           \
    \ if(y[i] - x[i] == y[j] - x[j]) return x[i] > x[j];\n            return y[i]\
    \ - x[i] < y[j] - x[j];\n          }\n        );\n\n        for(int i : ord){\n\
    \          int lb = std::lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();\n\n\
    \          if(auto res = seg.fold(lb, N); res){\n            auto j = res->second;\n\
    \            T c = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);\n          \
    \  g.add_edge(i, j, c);\n          }\n\n          if(auto res = seg[lb]; not res\
    \ or x[i] + y[i] < res->first){\n            seg.set(lb, {{x[i] + y[i], i}});\n\
    \          }\n        }\n      };\n\n    for(int i = 0; i < 2; ++i){\n      for(int\
    \ j = 0; j < 2; ++j){\n        for(int k = 0; k < 2; ++k){\n          f();\n \
    \         for(int l = 0; l < N; ++l) std::swap(x[l], y[l]);\n        }\n     \
    \   for(int l = 0; l < N; ++l) x[l] = -x[l];\n      }\n      for(int l = 0; l\
    \ < N; ++l) y[l] = -y[l];\n    }\n\n    return mst(g);\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <numeric>\n#include <cmath>\n#include \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, typename MST>\n  std::vector<edge<T>>\
    \ manhattan_minimum_spanning_tree(std::vector<T> x, std::vector<T> y, MST mst){\n\
    \    const int N = x.size();\n    graph<T> g(N);\n    segment_tree<min_monoid<std::pair<T,\
    \ int>>> seg(N);\n\n    auto f =\n      [&](){\n        std::vector<T> Y(y);\n\
    \        std::sort(Y.begin(), Y.end());\n        Y.erase(std::unique(Y.begin(),\
    \ Y.end()), Y.end());\n\n        seg.init(std::nullopt);\n\n        std::vector<int>\
    \ ord(N);\n        std::iota(ord.begin(), ord.end(), 0);\n        std::sort(\n\
    \          ord.begin(), ord.end(),\n          [&](int i, int j){\n           \
    \ if(y[i] - x[i] == y[j] - x[j]) return x[i] > x[j];\n            return y[i]\
    \ - x[i] < y[j] - x[j];\n          }\n        );\n\n        for(int i : ord){\n\
    \          int lb = std::lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();\n\n\
    \          if(auto res = seg.fold(lb, N); res){\n            auto j = res->second;\n\
    \            T c = std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);\n          \
    \  g.add_edge(i, j, c);\n          }\n\n          if(auto res = seg[lb]; not res\
    \ or x[i] + y[i] < res->first){\n            seg.set(lb, {{x[i] + y[i], i}});\n\
    \          }\n        }\n      };\n\n    for(int i = 0; i < 2; ++i){\n      for(int\
    \ j = 0; j < 2; ++j){\n        for(int k = 0; k < 2; ++k){\n          f();\n \
    \         for(int l = 0; l < N; ++l) std::swap(x[l], y[l]);\n        }\n     \
    \   for(int l = 0; l < N; ++l) x[l] = -x[l];\n      }\n      for(int l = 0; l\
    \ < N; ++l) y[l] = -y[l];\n    }\n\n    return mst(g);\n  }\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/manhattanmst/main.test.cpp
documentation_of: Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
layout: document
title: Manhattan distance MST
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://knuu.github.io/manhattan_mst.html](https://knuu.github.io/manhattan_mst.html)
