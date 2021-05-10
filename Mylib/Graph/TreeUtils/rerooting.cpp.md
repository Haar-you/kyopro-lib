---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1595/main.test.cpp
    title: test/aoj/1595/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/922/main.test.cpp
    title: test/yukicoder/922/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/TreeUtils/rerooting.cpp\"\n#include <vector>\n\
    #line 2 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n#line 4 \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct edge {\n    int from,\
    \ to;\n    T cost;\n    int index = -1;\n    edge() {}\n    edge(int from, int\
    \ to, T cost) : from(from), to(to), cost(cost) {}\n    edge(int from, int to,\
    \ T cost, int index) : from(from), to(to), cost(cost), index(index) {}\n  };\n\
    \n  template <typename T>\n  struct graph {\n    using weight_type = T;\n    using\
    \ edge_type   = edge<T>;\n\n    std::vector<std::vector<edge<T>>> data;\n\n  \
    \  auto& operator[](size_t i) { return data[i]; }\n    const auto& operator[](size_t\
    \ i) const { return data[i]; }\n\n    auto begin() const { return data.begin();\
    \ }\n    auto end() const { return data.end(); }\n\n    graph() {}\n    graph(int\
    \ N) : data(N) {}\n\n    bool empty() const { return data.empty(); }\n    int\
    \ size() const { return data.size(); }\n\n    void add_edge(int i, int j, T w,\
    \ int index = -1) {\n      data[i].emplace_back(i, j, w, index);\n    }\n\n  \
    \  void add_undirected(int i, int j, T w, int index = -1) {\n      add_edge(i,\
    \ j, w, index);\n      add_edge(j, i, w, index);\n    }\n\n    template <size_t\
    \ I, bool DIRECTED = true, bool WEIGHTED = true>\n    void read(int M) {\n   \
    \   for (int i = 0; i < M; ++i) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n        u -= I;\n        v -= I;\n        T w = 1;\n        if (WEIGHTED)\
    \ std::cin >> w;\n        if (DIRECTED)\n          add_edge(u, v, w, i);\n   \
    \     else\n          add_undirected(u, v, w, i);\n      }\n    }\n  };\n\n  template\
    \ <typename T>\n  using tree = graph<T>;\n}  // namespace haar_lib\n#line 4 \"\
    Mylib/Graph/TreeUtils/rerooting.cpp\"\n\nnamespace haar_lib {\n  namespace rerooting_impl\
    \ {\n    template <typename T, typename U, typename Merge, typename EdgeF, typename\
    \ VertexF>\n    T rec1(\n        tree<U> &tr,\n        T id,\n        const Merge\
    \ &merge,\n        const EdgeF &f,\n        const VertexF &g,\n        std::vector<std::vector<T>>\
    \ &dp,\n        int cur,\n        int par = -1) {\n      T acc = id;\n\n     \
    \ for (int i = 0; i < (int) tr[cur].size(); ++i) {\n        auto &e = tr[cur][i];\n\
    \        if (e.to == par) continue;\n        dp[cur][i] = rec1(tr, id, merge,\
    \ f, g, dp, e.to, cur);\n        acc        = merge(acc, f(dp[cur][i], e));\n\
    \      }\n\n      return g(acc, cur);\n    }\n\n    template <typename T, typename\
    \ U, typename Merge, typename EdgeF, typename VertexF>\n    void rec2(\n     \
    \   const tree<U> &tr,\n        T id,\n        const Merge &merge,\n        const\
    \ EdgeF &f,\n        const VertexF &g,\n        std::vector<std::vector<T>> &dp,\n\
    \        int cur,\n        int par,\n        T value) {\n      const int l = tr[cur].size();\n\
    \n      for (int i = 0; i < l; ++i) {\n        if (tr[cur][i].to == par) {\n \
    \         dp[cur][i] = value;\n        }\n      }\n\n      std::vector<T> left(l\
    \ + 1, id), right(l + 1, id);\n\n      for (int i = 0; i < l - 1; ++i) {\n   \
    \     const auto &e = tr[cur][i];\n        left[i + 1]   = merge(left[i], f(dp[cur][i],\
    \ e));\n      }\n\n      for (int i = l - 1; i >= 1; --i) {\n        const auto\
    \ &e = tr[cur][i];\n        right[i - 1]  = merge(right[i], f(dp[cur][i], e));\n\
    \      }\n\n      for (int i = 0; i < l; ++i) {\n        const auto &e = tr[cur][i];\n\
    \        if (e.to == par) continue;\n\n        rec2(tr, id, merge, f, g, dp, e.to,\
    \ cur, g(merge(left[i], right[i]), cur));\n      }\n    }\n  }  // namespace rerooting_impl\n\
    \n  template <typename T, typename U, typename Merge, typename EdgeF, typename\
    \ VertexF>\n  auto rerooting(tree<U> tr, T id, Merge merge, EdgeF f, VertexF g)\
    \ {\n    const int N = tr.size();\n    std::vector<std::vector<T>> dp(N);\n  \
    \  std::vector<T> ret(N, id);\n\n    for (int i = 0; i < N; ++i) dp[i].assign(tr[i].size(),\
    \ id);\n    rerooting_impl::rec1(tr, id, merge, f, g, dp, 0);\n    rerooting_impl::rec2(tr,\
    \ id, merge, f, g, dp, 0, -1, id);\n    for (int i = 0; i < N; ++i) {\n      for\
    \ (int j = 0; j < (int) tr[i].size(); ++j) {\n        ret[i] = merge(ret[i], f(dp[i][j],\
    \ tr[i][j]));\n      }\n\n      ret[i] = g(ret[i], i);\n    }\n\n    return ret;\n\
    \  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  namespace rerooting_impl {\n    template <typename\
    \ T, typename U, typename Merge, typename EdgeF, typename VertexF>\n    T rec1(\n\
    \        tree<U> &tr,\n        T id,\n        const Merge &merge,\n        const\
    \ EdgeF &f,\n        const VertexF &g,\n        std::vector<std::vector<T>> &dp,\n\
    \        int cur,\n        int par = -1) {\n      T acc = id;\n\n      for (int\
    \ i = 0; i < (int) tr[cur].size(); ++i) {\n        auto &e = tr[cur][i];\n   \
    \     if (e.to == par) continue;\n        dp[cur][i] = rec1(tr, id, merge, f,\
    \ g, dp, e.to, cur);\n        acc        = merge(acc, f(dp[cur][i], e));\n   \
    \   }\n\n      return g(acc, cur);\n    }\n\n    template <typename T, typename\
    \ U, typename Merge, typename EdgeF, typename VertexF>\n    void rec2(\n     \
    \   const tree<U> &tr,\n        T id,\n        const Merge &merge,\n        const\
    \ EdgeF &f,\n        const VertexF &g,\n        std::vector<std::vector<T>> &dp,\n\
    \        int cur,\n        int par,\n        T value) {\n      const int l = tr[cur].size();\n\
    \n      for (int i = 0; i < l; ++i) {\n        if (tr[cur][i].to == par) {\n \
    \         dp[cur][i] = value;\n        }\n      }\n\n      std::vector<T> left(l\
    \ + 1, id), right(l + 1, id);\n\n      for (int i = 0; i < l - 1; ++i) {\n   \
    \     const auto &e = tr[cur][i];\n        left[i + 1]   = merge(left[i], f(dp[cur][i],\
    \ e));\n      }\n\n      for (int i = l - 1; i >= 1; --i) {\n        const auto\
    \ &e = tr[cur][i];\n        right[i - 1]  = merge(right[i], f(dp[cur][i], e));\n\
    \      }\n\n      for (int i = 0; i < l; ++i) {\n        const auto &e = tr[cur][i];\n\
    \        if (e.to == par) continue;\n\n        rec2(tr, id, merge, f, g, dp, e.to,\
    \ cur, g(merge(left[i], right[i]), cur));\n      }\n    }\n  }  // namespace rerooting_impl\n\
    \n  template <typename T, typename U, typename Merge, typename EdgeF, typename\
    \ VertexF>\n  auto rerooting(tree<U> tr, T id, Merge merge, EdgeF f, VertexF g)\
    \ {\n    const int N = tr.size();\n    std::vector<std::vector<T>> dp(N);\n  \
    \  std::vector<T> ret(N, id);\n\n    for (int i = 0; i < N; ++i) dp[i].assign(tr[i].size(),\
    \ id);\n    rerooting_impl::rec1(tr, id, merge, f, g, dp, 0);\n    rerooting_impl::rec2(tr,\
    \ id, merge, f, g, dp, 0, -1, id);\n    for (int i = 0; i < N; ++i) {\n      for\
    \ (int j = 0; j < (int) tr[i].size(); ++j) {\n        ret[i] = merge(ret[i], f(dp[i][j],\
    \ tr[i][j]));\n      }\n\n      ret[i] = g(ret[i], i);\n    }\n\n    return ret;\n\
    \  }\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/TreeUtils/rerooting.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1595/main.test.cpp
  - test/yukicoder/922/main.test.cpp
documentation_of: Mylib/Graph/TreeUtils/rerooting.cpp
layout: document
title: Rerooting DP
---

## Operations

## Requirements

## Notes

## Problems

- [EDPC V - Subtree](https://atcoder.jp/contests/dp/tasks/dp_v)
- [Codeforces Round #627 (Div. 3) F. Maximum White Subtree](https://codeforces.com/contest/1324/problem/F)
- [ABC 160 F - Distributing Integers](https://atcoder.jp/contests/abc160/tasks/abc160_f)
- [ARC 028 C - 高橋王国の分割統治 ](https://atcoder.jp/contests/arc028/tasks/arc028_3)
- [s8pc #4 D - Driving on a Tree](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_d)

## References
- [https://null-mn.hatenablog.com/entry/2020/04/14/124151](https://null-mn.hatenablog.com/entry/2020/04/14/124151)
- [https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e](https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e)
- [https://kuretchi.github.io/blog/entries/rerooting/](https://kuretchi.github.io/blog/entries/rerooting/)
