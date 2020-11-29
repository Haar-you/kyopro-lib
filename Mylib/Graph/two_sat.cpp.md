---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
    title: Strongly connected components
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/two_sat/main.test.cpp
    title: test/yosupo-judge/two_sat/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/two_sat.cpp\"\n#include <vector>\n#include <optional>\n\
    #include <cassert>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 3 \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n#include <algorithm>\n#line 5 \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  auto strongly_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<int> ret(n), low(n,\
    \ -1), ord(n, -1), S;\n    std::vector<bool> check(n);\n    S.reserve(n);\n  \
    \  int t = 0;\n    int k = 0;\n\n    auto dfs =\n      [&](auto &dfs, int cur)\
    \ -> void {\n        low[cur] = ord[cur] = t++;\n        S.push_back(cur);\n \
    \       check[cur] = true;\n\n        for(auto &e : g[cur]){\n          if(ord[e.to]\
    \ == -1){\n            dfs(dfs, e.to);\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }else if(check[e.to]){\n            low[cur] = std::min(low[cur],\
    \ low[e.to]);\n          }\n        }\n\n        if(low[cur] == ord[cur]){\n \
    \         while(true){\n            int u = S.back(); S.pop_back();\n        \
    \    check[u] = false;\n            ret[u] = k;\n            if(cur == u) break;\n\
    \          }\n          ++k;\n        }\n      };\n\n    for(int i = 0; i < n;\
    \ ++i){\n      if(ord[i] == -1){\n        t = 0;\n        dfs(dfs, i);\n     \
    \ }\n    }\n\n    for(auto &x : ret) x = k - 1 - x;\n\n    return std::make_pair(ret,\
    \ k);\n  }\n}\n#line 7 \"Mylib/Graph/two_sat.cpp\"\n\nnamespace haar_lib {\n \
    \ class two_sat {\n    int n_;\n    graph<int> g_;\n\n    int f(int i){\n    \
    \  assert(i != 0);\n      assert(std::abs(i) <= n_);\n      if(i > 0) return i\
    \ - 1;\n      else return std::abs(i) - 1 + n_;\n    }\n\n  public:\n    two_sat(){}\n\
    \    two_sat(int n): n_(n), g_(2 * n){}\n\n    /**\n     * @note a\u2192b\u3092\
    \u5C0E\u5165\u3059\u308B\n     */\n    void add_if(int a, int b){\n      g_.add_edge(f(a),\
    \ f(b), 1);\n    }\n\n    /**\n     * @note a\u2228b\u3092\u5C0E\u5165\u3059\u308B\
    \n     * @note a \u2228 b <=> (!a => b) \u2227 (!b => a)\n     */\n    void add_or(int\
    \ a, int b){\n      add_if(-a, b);\n      add_if(-b, a);\n    }\n\n    /**\n \
    \    * @note \xAC(a\u2227b)\u3092\u5C0E\u5165\u3059\u308B\n     * @note !(A \u2227\
    \ B) <=> (!A \u2228 !B)\n     */\n    void not_coexist(int a, int b){\n      add_or(-a,\
    \ -b);\n    }\n\n  public:\n    std::optional<std::vector<bool>> solve() const\
    \ {\n      auto [scc, m] = strongly_connected_components(g_);\n\n      for(int\
    \ i = 0; i < n_; ++i){\n        if(scc[i] == scc[i + n_]) return std::nullopt;\n\
    \      }\n\n      std::vector<bool> ret(n_);\n      for(int i = 0; i < n_; ++i)\
    \ ret[i] = scc[i] > scc[i + n_];\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <cassert>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n\nnamespace haar_lib {\n  class two_sat {\n    int n_;\n    graph<int> g_;\n\
    \n    int f(int i){\n      assert(i != 0);\n      assert(std::abs(i) <= n_);\n\
    \      if(i > 0) return i - 1;\n      else return std::abs(i) - 1 + n_;\n    }\n\
    \n  public:\n    two_sat(){}\n    two_sat(int n): n_(n), g_(2 * n){}\n\n    /**\n\
    \     * @note a\u2192b\u3092\u5C0E\u5165\u3059\u308B\n     */\n    void add_if(int\
    \ a, int b){\n      g_.add_edge(f(a), f(b), 1);\n    }\n\n    /**\n     * @note\
    \ a\u2228b\u3092\u5C0E\u5165\u3059\u308B\n     * @note a \u2228 b <=> (!a => b)\
    \ \u2227 (!b => a)\n     */\n    void add_or(int a, int b){\n      add_if(-a,\
    \ b);\n      add_if(-b, a);\n    }\n\n    /**\n     * @note \xAC(a\u2227b)\u3092\
    \u5C0E\u5165\u3059\u308B\n     * @note !(A \u2227 B) <=> (!A \u2228 !B)\n    \
    \ */\n    void not_coexist(int a, int b){\n      add_or(-a, -b);\n    }\n\n  public:\n\
    \    std::optional<std::vector<bool>> solve() const {\n      auto [scc, m] = strongly_connected_components(g_);\n\
    \n      for(int i = 0; i < n_; ++i){\n        if(scc[i] == scc[i + n_]) return\
    \ std::nullopt;\n      }\n\n      std::vector<bool> ret(n_);\n      for(int i\
    \ = 0; i < n_; ++i) ret[i] = scc[i] > scc[i + n_];\n\n      return ret;\n    }\n\
    \  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/GraphUtils/strongly_connected_components.cpp
  isVerificationFile: false
  path: Mylib/Graph/two_sat.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/two_sat/main.test.cpp
documentation_of: Mylib/Graph/two_sat.cpp
layout: document
title: 2-SAT
---

## Operations

- `two_sat(int n)`
- `add_if(int a, int b)`
	- $a \rightarrow b$を導入する。
- `add_or(int a, int b)`
	- $a \lor b$を導入する。
- `not_coexist(int a, int b)`
	- $\lnot (a \land b)$を導入する。
- `solve()`
	- 与えられた論理式をすべて`True`にするような変数の真偽値の割り当てを返す。
	- Time complexity $O(V + E)$

## Requirements

- `add_if`, `add_or`, `not_coexist`の引数は`[1, n]`または`[-n, -1]`を満たさなければならない。
	- 正数`i`は$x_i$を、負数`-i`は$\lnot x_i$を表す。

## Notes

## Problems

- [yukicoder No.274 The Wall](https://yukicoder.me/problems/no/274)
- [yukicoder No.470 Inverse S+T Problem](https://yukicoder.me/problems/no/470)
- [ARC 069 F - Flags](https://atcoder.jp/contests/arc069/tasks/arc069_d)

## References

