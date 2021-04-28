---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/GraphUtils/biconnected_components.cpp\"\n#include\
    \ <algorithm>\n#include <stack>\n#include <vector>\n#line 2 \"Mylib/Graph/Template/graph.cpp\"\
    \n#include <iostream>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct edge {\n    int from, to;\n  \
    \  T cost;\n    int index = -1;\n    edge() {}\n    edge(int from, int to, T cost)\
    \ : from(from), to(to), cost(cost) {}\n    edge(int from, int to, T cost, int\
    \ index) : from(from), to(to), cost(cost), index(index) {}\n  };\n\n  template\
    \ <typename T>\n  struct graph {\n    using weight_type = T;\n    using edge_type\
    \   = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n    auto& operator[](size_t\
    \ i) { return data[i]; }\n    const auto& operator[](size_t i) const { return\
    \ data[i]; }\n\n    auto begin() const { return data.begin(); }\n    auto end()\
    \ const { return data.end(); }\n\n    graph() {}\n    graph(int N) : data(N) {}\n\
    \n    bool empty() const { return data.empty(); }\n    int size() const { return\
    \ data.size(); }\n\n    void add_edge(int i, int j, T w, int index = -1) {\n \
    \     data[i].emplace_back(i, j, w, index);\n    }\n\n    void add_undirected(int\
    \ i, int j, T w, int index = -1) {\n      add_edge(i, j, w, index);\n      add_edge(j,\
    \ i, w, index);\n    }\n\n    template <size_t I, bool DIRECTED = true, bool WEIGHTED\
    \ = true>\n    void read(int M) {\n      for (int i = 0; i < M; ++i) {\n     \
    \   int u, v;\n        std::cin >> u >> v;\n        u -= I;\n        v -= I;\n\
    \        T w = 1;\n        if (WEIGHTED) std::cin >> w;\n        if (DIRECTED)\n\
    \          add_edge(u, v, w, i);\n        else\n          add_undirected(u, v,\
    \ w, i);\n      }\n    }\n  };\n\n  template <typename T>\n  using tree = graph<T>;\n\
    }  // namespace haar_lib\n#line 6 \"Mylib/Graph/GraphUtils/biconnected_components.cpp\"\
    \n\nnamespace haar_lib {\n  namespace biconnected_components_impl {\n    template\
    \ <typename T>\n    void dfs(\n        const graph<T> &g,\n        int cur,\n\
    \        int par,\n        std::vector<bool> &check,\n        std::vector<int>\
    \ &low,\n        std::vector<int> &ord,\n        std::vector<std::vector<edge<T>>>\
    \ &ret,\n        std::stack<edge<T>> &st,\n        int &t) {\n      check[cur]\
    \ = true;\n      ord[cur]   = t;\n      low[cur]   = t;\n      ++t;\n\n      for\
    \ (auto &e : g[cur]) {\n        if (e.to == par) continue;\n\n        if (ord[e.to]\
    \ < ord[cur]) {\n          auto f = e;\n          if (f.from > f.to) std::swap(f.from,\
    \ f.to);\n          st.push(f);\n        }\n        if (not check[e.to]) {\n \
    \         dfs(g, e.to, cur, check, low, ord, ret, st, t);\n          low[cur]\
    \ = std::min(low[cur], low[e.to]);\n          if (low[e.to] >= ord[cur]) {\n \
    \           ret.emplace_back();\n            while (true) {\n              auto\
    \ f = st.top();\n              st.pop();\n              ret.back().push_back(f);\n\
    \              if (f.from == std::min(e.from, e.to) and f.to == std::max(e.from,\
    \ e.to)) break;\n            }\n          }\n        } else {\n          low[cur]\
    \ = std::min(low[cur], ord[e.to]);\n        }\n      }\n    }\n  }  // namespace\
    \ biconnected_components_impl\n\n  template <typename T>\n  auto biconnected_components(const\
    \ graph<T> &g) {\n    const int n = g.size();\n\n    std::vector<bool> check(n);\n\
    \    std::vector<int> low(n, -1), ord(n, -1);\n    std::vector<std::vector<edge<T>>>\
    \ ret;\n    std::stack<edge<T>> st;\n    int t = 0;\n\n    for (int i = 0; i <\
    \ n; ++i) {\n      if (not check[i]) biconnected_components_impl::dfs(g, i, -1,\
    \ check, low, ord, ret, st, t);\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <stack>\n#include <vector>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  namespace\
    \ biconnected_components_impl {\n    template <typename T>\n    void dfs(\n  \
    \      const graph<T> &g,\n        int cur,\n        int par,\n        std::vector<bool>\
    \ &check,\n        std::vector<int> &low,\n        std::vector<int> &ord,\n  \
    \      std::vector<std::vector<edge<T>>> &ret,\n        std::stack<edge<T>> &st,\n\
    \        int &t) {\n      check[cur] = true;\n      ord[cur]   = t;\n      low[cur]\
    \   = t;\n      ++t;\n\n      for (auto &e : g[cur]) {\n        if (e.to == par)\
    \ continue;\n\n        if (ord[e.to] < ord[cur]) {\n          auto f = e;\n  \
    \        if (f.from > f.to) std::swap(f.from, f.to);\n          st.push(f);\n\
    \        }\n        if (not check[e.to]) {\n          dfs(g, e.to, cur, check,\
    \ low, ord, ret, st, t);\n          low[cur] = std::min(low[cur], low[e.to]);\n\
    \          if (low[e.to] >= ord[cur]) {\n            ret.emplace_back();\n   \
    \         while (true) {\n              auto f = st.top();\n              st.pop();\n\
    \              ret.back().push_back(f);\n              if (f.from == std::min(e.from,\
    \ e.to) and f.to == std::max(e.from, e.to)) break;\n            }\n          }\n\
    \        } else {\n          low[cur] = std::min(low[cur], ord[e.to]);\n     \
    \   }\n      }\n    }\n  }  // namespace biconnected_components_impl\n\n  template\
    \ <typename T>\n  auto biconnected_components(const graph<T> &g) {\n    const\
    \ int n = g.size();\n\n    std::vector<bool> check(n);\n    std::vector<int> low(n,\
    \ -1), ord(n, -1);\n    std::vector<std::vector<edge<T>>> ret;\n    std::stack<edge<T>>\
    \ st;\n    int t = 0;\n\n    for (int i = 0; i < n; ++i) {\n      if (not check[i])\
    \ biconnected_components_impl::dfs(g, i, -1, check, low, ord, ret, st, t);\n \
    \   }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/GraphUtils/biconnected_components.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/GraphUtils/biconnected_components.cpp
layout: document
title: Biconnected components
---

## Operations

## Requirements

## Notes

## Problems

- [ARC062 F - AtCoDeerくんとグラフ色塗り](https://atcoder.jp/contests/arc062/tasks/arc062_d)

## References

- [http://www.prefield.com/algorithm/graph/articulation_point.html](http://www.prefield.com/algorithm/graph/articulation_point.html)
- [https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html](https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html)
