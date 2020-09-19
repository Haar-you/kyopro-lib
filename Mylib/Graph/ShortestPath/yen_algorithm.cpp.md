---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1069/main.test.cpp
    title: test/yukicoder/1069/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/ShortestPath/yen_algorithm.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <optional>\n#include <queue>\n#include <functional>\n\
    #line 3 \"Mylib/Graph/Template/graph.cpp\"\n#include <iostream>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct edge {\n    int from, to;\n    T cost;\n\
    \    int index = -1;\n    edge(){}\n    edge(int from, int to, T cost): from(from),\
    \ to(to), cost(cost){}\n    edge(int from, int to, T cost, int index): from(from),\
    \ to(to), cost(cost), index(index){}\n  };\n\n  template <typename T>\n  struct\
    \ graph {\n    using weight_type = T;\n    using edge_type = edge<T>;\n\n    std::vector<std::vector<edge<T>>>\
    \ data;\n\n    auto& operator[](size_t i){return data[i];}\n    const auto& operator[](size_t\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 8 \"Mylib/Graph/ShortestPath/yen_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  namespace yen_algorithm_impl {\n    template <typename\
    \ T>\n    auto shortest_path(\n      const graph<T> &g,\n      int from,\n   \
    \   int t,\n      const std::vector<bool> &usable,\n      const std::vector<std::vector<bool>>\
    \ &valid\n    ){\n      using Path = std::pair<T, std::vector<int>>;\n      using\
    \ P = std::pair<T, int>;\n\n      const int N = g.size();\n      std::vector<bool>\
    \ visited(N, false);\n      std::vector<std::optional<T>> dist(N);\n      std::vector<std::pair<int,\
    \ int>> restore(N);\n\n      std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n      dist[from] = 0;\n      pq.emplace(0, from);\n\n      while(not\
    \ pq.empty()){\n        auto [d, i] = pq.top(); pq.pop();\n\n        if(visited[i])\
    \ continue;\n        visited[i] = true;\n\n        for(int k = 0; k < (int)g[i].size();\
    \ ++k){\n          if(not valid[i][k] or not usable[g[i][k].to]) continue;\n \
    \         auto &e = g[i][k];\n\n          if(not dist[e.to] or *dist[e.to] > d\
    \ + e.cost){\n            dist[e.to] = d + e.cost;\n            restore[e.to]\
    \ = std::make_pair(i, k);\n            if(not visited[e.to]) pq.emplace(*dist[e.to],\
    \ e.to);\n          }\n        }\n      }\n\n      std::optional<Path> ret;\n\n\
    \      if(dist[t]){\n        std::vector<int> p;\n\n        int cur = t;\n   \
    \     while(cur != from){\n          auto [i, j] = restore[cur];\n          p.push_back(j);\n\
    \          cur = i;\n        }\n\n        std::reverse(p.begin(), p.end());\n\n\
    \        ret = std::make_pair(*dist[t], p);\n      }\n\n      return ret;\n  \
    \  }\n  }\n\n  template <typename T>\n  auto yen_algorithm(const graph<T> &g,\
    \ int s, int t, int K){\n    using Path = std::pair<T, std::vector<int>>;\n\n\
    \    const int N = g.size();\n\n    std::vector<std::vector<bool>> valid(N);\n\
    \    std::vector<std::optional<Path>> result(K);\n    std::priority_queue<Path,\
    \ std::vector<Path>, std::greater<Path>> stock;\n\n    for(int i = 0; i < N; ++i){\n\
    \      valid[i].assign(g[i].size(), true);\n    }\n\n    for(int i = 0; i < K;\
    \ ++i){\n      if(i == 0){\n        std::vector<bool> usable(N, true);\n     \
    \   if(auto res = yen_algorithm_impl::shortest_path(g, s, t, usable, valid); res)\
    \ stock.push(*res);\n      }else{\n        std::vector<int> prev_path;\n\n   \
    \     {\n          int cur = s;\n          for(auto u : result[i - 1]->second){\n\
    \            prev_path.push_back(cur);\n            cur = g[cur][u].to;\n    \
    \      }\n          prev_path.push_back(t);\n        }\n\n        std::vector<bool>\
    \ check(i, true);\n        std::vector<bool> usable(N, true);\n\n        for(int\
    \ k = 0; k < (int)prev_path.size() - 1; ++k){\n          const int u = prev_path[k];\n\
    \n          for(int j = 0; j < i; ++j){\n            if(check[j]){\n         \
    \     valid[prev_path[k]][result[j]->second[k]] = false;\n            }\n    \
    \      }\n\n          if(auto res = yen_algorithm_impl::shortest_path(g, u, t,\
    \ usable, valid); res){\n            auto [c, p] = *res;\n\n            std::vector<int>\
    \ temp;\n            for(int j = 0; j < k; ++j){\n              int v = result[i\
    \ - 1]->second[j];\n\n              c += g[prev_path[j]][v].cost;\n          \
    \    temp.push_back(v);\n            }\n\n            temp.insert(temp.end(),\
    \ p.begin(), p.end());\n            stock.emplace(c, temp);\n          }\n\n \
    \         usable[u] = false;\n\n          for(int j = 0; j < i; ++j){\n      \
    \      if(check[j]){\n              valid[prev_path[k]][result[j]->second[k]]\
    \ = true;\n            }\n          }\n\n          for(int j = 0; j < i; ++j){\n\
    \            if(check[j]){\n              if(prev_path[k + 1] != g[prev_path[k]][result[j]->second[k]].to){\n\
    \                check[j] = false;\n              }\n            }\n         \
    \ }\n        }\n      }\n\n      if(stock.empty()) break;\n\n      result[i] =\
    \ stock.top(); stock.pop();\n\n      while(not stock.empty() and stock.top() ==\
    \ result[i]){\n        stock.pop();\n      }\n    }\n\n    return result;\n  }\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <optional>\n\
    #include <queue>\n#include <functional>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  namespace yen_algorithm_impl {\n    template <typename\
    \ T>\n    auto shortest_path(\n      const graph<T> &g,\n      int from,\n   \
    \   int t,\n      const std::vector<bool> &usable,\n      const std::vector<std::vector<bool>>\
    \ &valid\n    ){\n      using Path = std::pair<T, std::vector<int>>;\n      using\
    \ P = std::pair<T, int>;\n\n      const int N = g.size();\n      std::vector<bool>\
    \ visited(N, false);\n      std::vector<std::optional<T>> dist(N);\n      std::vector<std::pair<int,\
    \ int>> restore(N);\n\n      std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n      dist[from] = 0;\n      pq.emplace(0, from);\n\n      while(not\
    \ pq.empty()){\n        auto [d, i] = pq.top(); pq.pop();\n\n        if(visited[i])\
    \ continue;\n        visited[i] = true;\n\n        for(int k = 0; k < (int)g[i].size();\
    \ ++k){\n          if(not valid[i][k] or not usable[g[i][k].to]) continue;\n \
    \         auto &e = g[i][k];\n\n          if(not dist[e.to] or *dist[e.to] > d\
    \ + e.cost){\n            dist[e.to] = d + e.cost;\n            restore[e.to]\
    \ = std::make_pair(i, k);\n            if(not visited[e.to]) pq.emplace(*dist[e.to],\
    \ e.to);\n          }\n        }\n      }\n\n      std::optional<Path> ret;\n\n\
    \      if(dist[t]){\n        std::vector<int> p;\n\n        int cur = t;\n   \
    \     while(cur != from){\n          auto [i, j] = restore[cur];\n          p.push_back(j);\n\
    \          cur = i;\n        }\n\n        std::reverse(p.begin(), p.end());\n\n\
    \        ret = std::make_pair(*dist[t], p);\n      }\n\n      return ret;\n  \
    \  }\n  }\n\n  template <typename T>\n  auto yen_algorithm(const graph<T> &g,\
    \ int s, int t, int K){\n    using Path = std::pair<T, std::vector<int>>;\n\n\
    \    const int N = g.size();\n\n    std::vector<std::vector<bool>> valid(N);\n\
    \    std::vector<std::optional<Path>> result(K);\n    std::priority_queue<Path,\
    \ std::vector<Path>, std::greater<Path>> stock;\n\n    for(int i = 0; i < N; ++i){\n\
    \      valid[i].assign(g[i].size(), true);\n    }\n\n    for(int i = 0; i < K;\
    \ ++i){\n      if(i == 0){\n        std::vector<bool> usable(N, true);\n     \
    \   if(auto res = yen_algorithm_impl::shortest_path(g, s, t, usable, valid); res)\
    \ stock.push(*res);\n      }else{\n        std::vector<int> prev_path;\n\n   \
    \     {\n          int cur = s;\n          for(auto u : result[i - 1]->second){\n\
    \            prev_path.push_back(cur);\n            cur = g[cur][u].to;\n    \
    \      }\n          prev_path.push_back(t);\n        }\n\n        std::vector<bool>\
    \ check(i, true);\n        std::vector<bool> usable(N, true);\n\n        for(int\
    \ k = 0; k < (int)prev_path.size() - 1; ++k){\n          const int u = prev_path[k];\n\
    \n          for(int j = 0; j < i; ++j){\n            if(check[j]){\n         \
    \     valid[prev_path[k]][result[j]->second[k]] = false;\n            }\n    \
    \      }\n\n          if(auto res = yen_algorithm_impl::shortest_path(g, u, t,\
    \ usable, valid); res){\n            auto [c, p] = *res;\n\n            std::vector<int>\
    \ temp;\n            for(int j = 0; j < k; ++j){\n              int v = result[i\
    \ - 1]->second[j];\n\n              c += g[prev_path[j]][v].cost;\n          \
    \    temp.push_back(v);\n            }\n\n            temp.insert(temp.end(),\
    \ p.begin(), p.end());\n            stock.emplace(c, temp);\n          }\n\n \
    \         usable[u] = false;\n\n          for(int j = 0; j < i; ++j){\n      \
    \      if(check[j]){\n              valid[prev_path[k]][result[j]->second[k]]\
    \ = true;\n            }\n          }\n\n          for(int j = 0; j < i; ++j){\n\
    \            if(check[j]){\n              if(prev_path[k + 1] != g[prev_path[k]][result[j]->second[k]].to){\n\
    \                check[j] = false;\n              }\n            }\n         \
    \ }\n        }\n      }\n\n      if(stock.empty()) break;\n\n      result[i] =\
    \ stock.top(); stock.pop();\n\n      while(not stock.empty() and stock.top() ==\
    \ result[i]){\n        stock.pop();\n      }\n    }\n\n    return result;\n  }\n\
    }\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/ShortestPath/yen_algorithm.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1069/main.test.cpp
documentation_of: Mylib/Graph/ShortestPath/yen_algorithm.cpp
layout: document
title: Yen's algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22#%E7%AC%AC1%E6%9C%80%E7%9F%AD%E8%B7%AF](https://qiita.com/nariaki3551/items/821dc6ffdc552d3d5f22)
