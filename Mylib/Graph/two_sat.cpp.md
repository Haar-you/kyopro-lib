---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  - icon: ':x:'
    path: Mylib/Graph/GraphUtils/strongly_connected_components.cpp
    title: Strongly connected components
  - icon: ':x:'
    path: Mylib/Graph/TopologicalSort/topological_sort.cpp
    title: Topological sort
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/two_sat/main.test.cpp
    title: test/yosupo-judge/two_sat/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
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
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<bool> visit(n);\n\
    \    std::vector<int> check(n);\n    std::vector<int> result(n, -1);\n\n    auto\
    \ dfs =\n      [&](auto &f, int cur) -> void {\n        visit[cur] = true;\n \
    \       for(const auto &e : g[cur]){\n          if(not visit[e.to]) f(f, e.to);\n\
    \        }\n        check.push_back(cur);\n      };\n\n    for(int i = 0; i <\
    \ n; ++i) if(not visit[i]) dfs(dfs, i);\n\n    std::reverse(check.begin(), check.end());\n\
    \n    graph<T> rg(n);\n\n    auto rdfs =\n      [&](auto &f, int cur, int i) ->\
    \ void {\n        result[cur] = i;\n        for(const auto &e : rg[cur]){\n  \
    \        if(result[e.to] == -1) f(f, e.to, i);\n        }\n      };\n\n    for(int\
    \ i = 0; i < n; ++i) for(const auto &e : g[i]) rg[e.to].emplace_back(e.to, e.from,\
    \ e.cost);\n\n    int i = 0;\n    for(auto c : check) if(result[c] == -1) rdfs(rdfs,\
    \ c, i), ++i;\n\n    return std::make_pair(result, i);\n  }\n}\n#line 4 \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\
    \n#include <queue>\n#line 6 \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::optional<std::vector<int>>\
    \ topological_sort(const graph<T> &g){\n    const int n = g.size();\n    std::vector<int>\
    \ indeg(n);\n\n    for(int i = 0; i < n; ++i){\n      for(auto &e : g[i]){\n \
    \       ++indeg[e.to];\n      }\n    }\n\n    std::queue<int> q;\n    for(int\
    \ i = 0; i < n; ++i){\n      if(indeg[i] == 0) q.push(i);\n    }\n\n    std::vector<int>\
    \ ret;\n    while(not q.empty()){\n      int cur = q.front(); q.pop();\n     \
    \ ret.push_back(cur);\n      for(auto &e : g[cur]){\n        --indeg[e.to];\n\
    \        if(indeg[e.to] == 0){\n          q.push(e.to);\n        }\n      }\n\
    \    }\n\n    if((int)ret.size() == n){\n      return {ret};\n    }else{\n   \
    \   return std::nullopt;\n    }\n  }\n}\n#line 8 \"Mylib/Graph/two_sat.cpp\"\n\
    \nnamespace haar_lib {\n  class two_sat {\n    const int n;\n    graph<int> g;\n\
    \n    int f(int i){\n      assert(i != 0);\n      assert(std::abs(i) <= n);\n\
    \      if(i > 0) return i - 1;\n      else return std::abs(i) - 1 + n;\n    }\n\
    \n  public:\n    two_sat(int n): n(n), g(2 * n){}\n\n    /**\n     * @note a\u2192\
    b\u3092\u5C0E\u5165\u3059\u308B\n     */\n    void add_if(int a, int b){\n   \
    \   g.add_edge(f(a), f(b), 1);\n    }\n\n    /**\n     * @note a\u2228b\u3092\u5C0E\
    \u5165\u3059\u308B\n     * @note a \u2228 b <=> (!a => b) \u2227 (!b => a)\n \
    \    */\n    void add_or(int a, int b){\n      add_if(-a, b);\n      add_if(-b,\
    \ a);\n    }\n\n    /**\n     * @note \xAC(a\u2227b)\u3092\u5C0E\u5165\u3059\u308B\
    \n     * @note !(A \u2227 B) <=> (!A \u2228 !B)\n     */\n    void not_coexist(int\
    \ a, int b){\n      add_or(-a, -b);\n    }\n\n  public:\n    std::optional<std::vector<bool>>\
    \ solve() const {\n      auto [scc, m] = strongly_connected_components(g);\n\n\
    \      for(int i = 0; i < n; ++i){\n        if(scc[i] == scc[i + n]) return {};\n\
    \      }\n\n      graph<int> g2(m);\n\n      for(int i = 0; i < 2 * n; ++i){\n\
    \        for(auto &e : g[i]){\n          if(scc[e.from] != scc[e.to]){\n     \
    \       g2.add_edge(scc[e.from], scc[e.to], 1);\n          }\n        }\n    \
    \  }\n\n      auto ts = *topological_sort(g2);\n\n      std::vector<int> r(m);\n\
    \      for(int i = 0; i < m; ++i) r[ts[i]] = i;\n\n      std::vector<bool> ret(n);\n\
    \      for(int i = 0; i < n; ++i) ret[i] = r[scc[i]] > r[scc[i + n]];\n\n    \
    \  return {ret};\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <cassert>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n#include \"Mylib/Graph/GraphUtils/strongly_connected_components.cpp\"\
    \n#include \"Mylib/Graph/TopologicalSort/topological_sort.cpp\"\n\nnamespace haar_lib\
    \ {\n  class two_sat {\n    const int n;\n    graph<int> g;\n\n    int f(int i){\n\
    \      assert(i != 0);\n      assert(std::abs(i) <= n);\n      if(i > 0) return\
    \ i - 1;\n      else return std::abs(i) - 1 + n;\n    }\n\n  public:\n    two_sat(int\
    \ n): n(n), g(2 * n){}\n\n    /**\n     * @note a\u2192b\u3092\u5C0E\u5165\u3059\
    \u308B\n     */\n    void add_if(int a, int b){\n      g.add_edge(f(a), f(b),\
    \ 1);\n    }\n\n    /**\n     * @note a\u2228b\u3092\u5C0E\u5165\u3059\u308B\n\
    \     * @note a \u2228 b <=> (!a => b) \u2227 (!b => a)\n     */\n    void add_or(int\
    \ a, int b){\n      add_if(-a, b);\n      add_if(-b, a);\n    }\n\n    /**\n \
    \    * @note \xAC(a\u2227b)\u3092\u5C0E\u5165\u3059\u308B\n     * @note !(A \u2227\
    \ B) <=> (!A \u2228 !B)\n     */\n    void not_coexist(int a, int b){\n      add_or(-a,\
    \ -b);\n    }\n\n  public:\n    std::optional<std::vector<bool>> solve() const\
    \ {\n      auto [scc, m] = strongly_connected_components(g);\n\n      for(int\
    \ i = 0; i < n; ++i){\n        if(scc[i] == scc[i + n]) return {};\n      }\n\n\
    \      graph<int> g2(m);\n\n      for(int i = 0; i < 2 * n; ++i){\n        for(auto\
    \ &e : g[i]){\n          if(scc[e.from] != scc[e.to]){\n            g2.add_edge(scc[e.from],\
    \ scc[e.to], 1);\n          }\n        }\n      }\n\n      auto ts = *topological_sort(g2);\n\
    \n      std::vector<int> r(m);\n      for(int i = 0; i < m; ++i) r[ts[i]] = i;\n\
    \n      std::vector<bool> ret(n);\n      for(int i = 0; i < n; ++i) ret[i] = r[scc[i]]\
    \ > r[scc[i + n]];\n\n      return {ret};\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  - Mylib/Graph/GraphUtils/strongly_connected_components.cpp
  - Mylib/Graph/TopologicalSort/topological_sort.cpp
  isVerificationFile: false
  path: Mylib/Graph/two_sat.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/two_sat/main.test.cpp
documentation_of: Mylib/Graph/two_sat.cpp
layout: document
title: 2-SAT
---

## Operations

- `TwoSat(int n)`
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

