---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/lsi.cpp\"\n#include <vector>\n#include <optional>\n\
    #include <cassert>\n#include <algorithm>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 7 \"Mylib/Graph/lsi.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T, typename U>\n  std::optional<std::vector<U>>\
    \ lsi(const graph<T> &g, const std::vector<U> &c){\n    const int N = g.size();\n\
    \    assert((int)c.size() == N);\n\n    graph<T> h(N);\n\n    int M = 0;\n   \
    \ for(auto &v : g){\n      for(auto &e : v){\n        h[e.from].push_back(e);\n\
    \        h[e.to].push_back(e);\n        M = std::max(M, e.index + 1);\n      }\n\
    \    }\n\n    std::vector<U> ret(M);\n    std::vector<bool> check(N);\n\n    auto\
    \ dfs =\n      [&](auto &dfs, int cur) -> U {\n        check[cur] = true;\n\n\
    \        U t = c[cur];\n\n        for(auto &e : h[cur]){\n          auto v = e.from\
    \ == cur ? e.to : e.from;\n          if(check[v]) continue;\n\n          auto\
    \ y = dfs(dfs, v);\n\n          if(e.from == cur) ret[e.index] = y;\n        \
    \  else ret[e.index] = -y;\n\n          t += y;\n        }\n\n        return t;\n\
    \      };\n\n    for(int i = 0; i < N; ++i){\n      if(check[i]) continue;\n \
    \     auto y = dfs(dfs, i);\n      if(y != 0) return std::nullopt;\n    }\n\n\
    \    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <optional>\n#include <cassert>\n\
    #include <algorithm>\n#include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, typename U>\n  std::optional<std::vector<U>>\
    \ lsi(const graph<T> &g, const std::vector<U> &c){\n    const int N = g.size();\n\
    \    assert((int)c.size() == N);\n\n    graph<T> h(N);\n\n    int M = 0;\n   \
    \ for(auto &v : g){\n      for(auto &e : v){\n        h[e.from].push_back(e);\n\
    \        h[e.to].push_back(e);\n        M = std::max(M, e.index + 1);\n      }\n\
    \    }\n\n    std::vector<U> ret(M);\n    std::vector<bool> check(N);\n\n    auto\
    \ dfs =\n      [&](auto &dfs, int cur) -> U {\n        check[cur] = true;\n\n\
    \        U t = c[cur];\n\n        for(auto &e : h[cur]){\n          auto v = e.from\
    \ == cur ? e.to : e.from;\n          if(check[v]) continue;\n\n          auto\
    \ y = dfs(dfs, v);\n\n          if(e.from == cur) ret[e.index] = y;\n        \
    \  else ret[e.index] = -y;\n\n          t += y;\n        }\n\n        return t;\n\
    \      };\n\n    for(int i = 0; i < N; ++i){\n      if(check[i]) continue;\n \
    \     auto y = dfs(dfs, i);\n      if(y != 0) return std::nullopt;\n    }\n\n\
    \    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/lsi.cpp
  requiredBy: []
  timestamp: '2020-09-30 10:16:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/lsi.cpp
layout: document
title: Linear system incidence
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://opt-cp.com/cp/linear-system-incidence/](https://opt-cp.com/cp/linear-system-incidence/)
