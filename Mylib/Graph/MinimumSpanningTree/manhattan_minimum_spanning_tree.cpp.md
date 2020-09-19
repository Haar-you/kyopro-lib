---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/MinimumSpanningTree/kruskal.cpp
    title: Kruskal algorithm
  - icon: ':question:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/manhattanmst/main.test.cpp
    title: test/yosupo-judge/manhattanmst/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <algorithm>\n#include <numeric>\n\
    #include <cmath>\n#line 3 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n#include\
    \ <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct min_monoid\
    \ {\n    using value_type = std::optional<T>;\n\n    value_type operator()() const\
    \ {return {};}\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if(not a) return b;\n      if(not b) return a;\n      return\
    \ {std::min(*a, *b)};\n    }\n  };\n}\n#line 4 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <functional>\n\nnamespace haar_lib {\n  template <typename Monoid>\n\
    \  class segment_tree {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    int depth, size, hsize;\n    std::vector<value_type>\
    \ data;\n\n  public:\n    segment_tree(){}\n    segment_tree(int n):\n      depth(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 << depth), hsize(size\
    \ / 2),\n      data(size, M())\n    {}\n\n    auto operator[](int i) const {return\
    \ data[hsize + i];}\n\n    auto get(int x, int y) const {\n      value_type ret_left\
    \ = M();\n      value_type ret_right = M();\n\n      int l = x + hsize, r = y\
    \ + hsize;\n      while(l < r){\n        if(r & 1) ret_right = M(data[--r], ret_right);\n\
    \        if(l & 1) ret_left = M(ret_left, data[l++]);\n        l >>= 1, r >>=\
    \ 1;\n      }\n\n      return M(ret_left, ret_right);\n    }\n\n    void update(int\
    \ i, const value_type &x){\n      i += hsize;\n      data[i] = x;\n      while(i\
    \ > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n  \
    \  template <typename T>\n    void init_with_vector(const std::vector<T> &val){\n\
    \      data.assign(size, M());\n      for(int i = 0; i < (int)val.size(); ++i)\
    \ data[hsize + i] = val[i];\n      for(int i = hsize - 1; i >= 1; --i) data[i]\
    \ = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n    template <typename T>\n\
    \    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize,\
    \ val));\n    }\n\n  private:\n    template <bool Lower, typename F>\n    int\
    \ bound(const int l, const int r, value_type x, F f) const {\n      std::vector<int>\
    \ pl, pr;\n      int L = l + hsize;\n      int R = r + hsize;\n      while(L <\
    \ R){\n        if(R & 1) pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n\
    \        L >>= 1, R >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n\
    \      pl.insert(pl.end(), pr.begin(), pr.end());\n\n      value_type a = M();\n\
    \n      for(int i : pl){\n        auto b = M(a, data[i]);\n\n        if((Lower\
    \ and not f(b, x)) or (not Lower and f(x, b))){\n          while(i < hsize){\n\
    \            if(auto c = M(a, data[i << 1 | 0]); (Lower and not f(c, x)) or (not\
    \ Lower and f(x, c))){\n              i = i << 1 | 0;\n            }else{\n  \
    \            a = c;\n              i = i << 1 | 1;\n            }\n          }\n\
    \n          return i - hsize;\n        }\n\n        a = b;\n      }\n\n      return\
    \ r;\n    }\n\n  public:\n    template <typename F = std::less<value_type>>\n\
    \    int lower_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<true>(l, r, x, f);\n    }\n\n    template <typename F = std::less<value_type>>\n\
    \    int upper_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<false>(l, r, x, f);\n    }\n  };\n}\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
    \n\nnamespace haar_lib {\n  class unionfind {\n    int n;\n    mutable std::vector<int>\
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
    \    return ret;\n  }\n}\n#line 11 \"Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<edge<T>> manhattan_minimum_spanning_tree(std::vector<T>\
    \ x, std::vector<T> y){\n    const int N = x.size();\n    graph<T> g(N);\n   \
    \ segment_tree<min_monoid<std::pair<T, int>>> seg(N);\n\n    auto f =\n      [&](){\n\
    \        std::vector<T> Y(y);\n        std::sort(Y.begin(), Y.end());\n      \
    \  Y.erase(std::unique(Y.begin(), Y.end()), Y.end());\n\n        seg.init(std::nullopt);\n\
    \n        std::vector<int> ord(N);\n        std::iota(ord.begin(), ord.end(),\
    \ 0);\n        std::sort(\n          ord.begin(), ord.end(),\n          [&](int\
    \ i, int j){\n            if(y[i] - x[i] == y[j] - x[j]) return x[i] > x[j];\n\
    \            return y[i] - x[i] < y[j] - x[j];\n          }\n        );\n\n  \
    \      for(int i : ord){\n          int lb = std::lower_bound(Y.begin(), Y.end(),\
    \ y[i]) - Y.begin();\n\n          if(auto res = seg.get(lb, N); res){\n      \
    \      auto j = res->second;\n            T c = std::abs(x[i] - x[j]) + std::abs(y[i]\
    \ - y[j]);\n            g.add_edge(i, j, c);\n          }\n\n          if(auto\
    \ res = seg[lb]; not res or x[i] + y[i] < res->first){\n            seg.update(lb,\
    \ {{x[i] + y[i], i}});\n          }\n        }\n      };\n\n    for(int i = 0;\
    \ i < 2; ++i){\n      for(int j = 0; j < 2; ++j){\n        for(int k = 0; k <\
    \ 2; ++k){\n          f();\n          for(int l = 0; l < N; ++l) std::swap(x[l],\
    \ y[l]);\n        }\n        for(int l = 0; l < N; ++l) x[l] = -x[l];\n      }\n\
    \      for(int l = 0; l < N; ++l) y[l] = -y[l];\n    }\n\n    return kruskal(g);\n\
    \  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <numeric>\n#include <cmath>\n#include \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n#include \"Mylib/Graph/MinimumSpanningTree/kruskal.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<edge<T>> manhattan_minimum_spanning_tree(std::vector<T>\
    \ x, std::vector<T> y){\n    const int N = x.size();\n    graph<T> g(N);\n   \
    \ segment_tree<min_monoid<std::pair<T, int>>> seg(N);\n\n    auto f =\n      [&](){\n\
    \        std::vector<T> Y(y);\n        std::sort(Y.begin(), Y.end());\n      \
    \  Y.erase(std::unique(Y.begin(), Y.end()), Y.end());\n\n        seg.init(std::nullopt);\n\
    \n        std::vector<int> ord(N);\n        std::iota(ord.begin(), ord.end(),\
    \ 0);\n        std::sort(\n          ord.begin(), ord.end(),\n          [&](int\
    \ i, int j){\n            if(y[i] - x[i] == y[j] - x[j]) return x[i] > x[j];\n\
    \            return y[i] - x[i] < y[j] - x[j];\n          }\n        );\n\n  \
    \      for(int i : ord){\n          int lb = std::lower_bound(Y.begin(), Y.end(),\
    \ y[i]) - Y.begin();\n\n          if(auto res = seg.get(lb, N); res){\n      \
    \      auto j = res->second;\n            T c = std::abs(x[i] - x[j]) + std::abs(y[i]\
    \ - y[j]);\n            g.add_edge(i, j, c);\n          }\n\n          if(auto\
    \ res = seg[lb]; not res or x[i] + y[i] < res->first){\n            seg.update(lb,\
    \ {{x[i] + y[i], i}});\n          }\n        }\n      };\n\n    for(int i = 0;\
    \ i < 2; ++i){\n      for(int j = 0; j < 2; ++j){\n        for(int k = 0; k <\
    \ 2; ++k){\n          f();\n          for(int l = 0; l < N; ++l) std::swap(x[l],\
    \ y[l]);\n        }\n        for(int l = 0; l < N; ++l) x[l] = -x[l];\n      }\n\
    \      for(int l = 0; l < N; ++l) y[l] = -y[l];\n    }\n\n    return kruskal(g);\n\
    \  }\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/MinimumSpanningTree/kruskal.cpp
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  isVerificationFile: false
  path: Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
