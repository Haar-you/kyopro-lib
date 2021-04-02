---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/cycle_detection/main.test.cpp
    title: test/yosupo-judge/cycle_detection/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Cycle/detect_cycle.cpp\"\n#include <optional>\n\
    #include <vector>\n#include <algorithm>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/Cycle/detect_cycle.cpp\"\
    \n\nnamespace haar_lib {\n  namespace detect_cycle_impl {\n    constexpr static\
    \ int SEARCHED = 1;\n    constexpr static int SEARCHING = 2;\n\n    template <typename\
    \ T>\n    std::optional<int> rec(\n      const graph<T> &g,\n      int cur,\n\
    \      std::vector<edge<T>> &temp,\n      std::vector<edge<T>> &ret,\n      std::vector<int>\
    \ &check\n    ){\n      if(check[cur] == SEARCHED) return std::nullopt;\n    \
    \  if(check[cur] == SEARCHING) return {cur};\n      check[cur] = SEARCHING;\n\n\
    \      for(auto &e : g[cur]){\n        temp.push_back(e);\n\n        if(auto res\
    \ = rec(g, e.to, temp, ret, check); res){\n          if(*res != -1){\n       \
    \     ret.push_back(e);\n            if(*res == cur){\n              return {-1};\n\
    \            }\n          }\n\n          return res;\n        }\n\n        temp.pop_back();\n\
    \      }\n\n      check[cur] = SEARCHED;\n\n      return std::nullopt;\n    }\n\
    \  }\n\n  template <typename T>\n  std::optional<std::vector<edge<T>>> detect_cycle(const\
    \ graph<T> &g){\n    const int N = g.size();\n    std::vector<int> check(N);\n\
    \n    for(int i = 0; i < N; ++i){\n      if(check[i] == 0){\n        std::vector<edge<T>>\
    \ temp, ret;\n        detect_cycle_impl::rec(g, i, temp, ret, check);\n      \
    \  if(not ret.empty()){\n          std::reverse(ret.begin(), ret.end());\n   \
    \       return {ret};\n        }\n      }\n    }\n\n    return std::nullopt;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <optional>\n#include <vector>\n#include <algorithm>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  namespace\
    \ detect_cycle_impl {\n    constexpr static int SEARCHED = 1;\n    constexpr static\
    \ int SEARCHING = 2;\n\n    template <typename T>\n    std::optional<int> rec(\n\
    \      const graph<T> &g,\n      int cur,\n      std::vector<edge<T>> &temp,\n\
    \      std::vector<edge<T>> &ret,\n      std::vector<int> &check\n    ){\n   \
    \   if(check[cur] == SEARCHED) return std::nullopt;\n      if(check[cur] == SEARCHING)\
    \ return {cur};\n      check[cur] = SEARCHING;\n\n      for(auto &e : g[cur]){\n\
    \        temp.push_back(e);\n\n        if(auto res = rec(g, e.to, temp, ret, check);\
    \ res){\n          if(*res != -1){\n            ret.push_back(e);\n          \
    \  if(*res == cur){\n              return {-1};\n            }\n          }\n\n\
    \          return res;\n        }\n\n        temp.pop_back();\n      }\n\n   \
    \   check[cur] = SEARCHED;\n\n      return std::nullopt;\n    }\n  }\n\n  template\
    \ <typename T>\n  std::optional<std::vector<edge<T>>> detect_cycle(const graph<T>\
    \ &g){\n    const int N = g.size();\n    std::vector<int> check(N);\n\n    for(int\
    \ i = 0; i < N; ++i){\n      if(check[i] == 0){\n        std::vector<edge<T>>\
    \ temp, ret;\n        detect_cycle_impl::rec(g, i, temp, ret, check);\n      \
    \  if(not ret.empty()){\n          std::reverse(ret.begin(), ret.end());\n   \
    \       return {ret};\n        }\n      }\n    }\n\n    return std::nullopt;\n\
    \  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/Cycle/detect_cycle.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/cycle_detection/main.test.cpp
documentation_of: Mylib/Graph/Cycle/detect_cycle.cpp
layout: document
title: Detect cycle
---

## Operations

## Requirements

## Notes

## Problems

## References
