---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_1_B/main.test.cpp
    title: test/aoj/GRL_1_B/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/ShortestPath/bellman_ford.cpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <cassert>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 6 \"Mylib/Graph/ShortestPath/bellman_ford.cpp\"\
    \n\nnamespace haar_lib {\n  namespace bellman_ford_impl {\n    template <typename\
    \ T>\n    struct result {\n      enum class Tag {OK, NEGLOOP, UNREACHABLE} tag;\n\
    \      T val;\n      result(Tag tag): tag(tag){}\n\n    public:\n      static\
    \ auto unreachable() {return result(Tag::UNREACHABLE);}\n      static auto negloop()\
    \ {return result(Tag::NEGLOOP);}\n      result(T val): tag(Tag::OK), val(val){}\n\
    \n      bool is_unreachable() const {return tag == Tag::UNREACHABLE;}\n      bool\
    \ is_negloop() const {return tag == Tag::NEGLOOP;}\n      bool is_ok() const {return\
    \ tag == Tag::OK;}\n\n      T value() const {\n        assert(tag == Tag::OK);\n\
    \        return val;\n      }\n\n      friend std::ostream& operator<<(std::ostream\
    \ &s, const result &a){\n        if(a.is_unreachable()) s << \"\u221E\";\n   \
    \     else if(a.is_negloop()) s << \"-\u221E\";\n        else s << a.value();\n\
    \        return s;\n      }\n    };\n  }\n\n  template <typename T>\n  auto bellman_ford(const\
    \ graph<T> &g, int src){\n    using Result = bellman_ford_impl::result<T>;\n \
    \   const int n = g.size();\n    std::vector<Result> dist(n, Result::unreachable());\n\
    \n    dist[src] = 0;\n\n    for(int i = 0; i < n; ++i){\n      for(int s = 0;\
    \ s < n; ++s){\n        for(auto &e : g[s]){\n          int t = e.to;\n      \
    \    T d = e.cost;\n\n          if(dist[s].is_ok() and\n             dist[t].is_ok()\
    \ and\n             dist[s].value() + d < dist[t].value() and i == n - 1){\n \
    \           dist[t] = Result::negloop();\n          }else{\n            if(dist[s].is_ok()){\n\
    \              if(dist[t].is_unreachable()){\n                dist[t] = dist[s].value()\
    \ + d;\n              }else if(dist[t].is_ok()){\n                dist[t] = std::min(dist[t].value(),\
    \ dist[s].value() + d);\n              }\n            }\n          }\n       \
    \ }\n      }\n    }\n\n    for(int i = 0; i < n; ++i){\n      for(int s = 0; s\
    \ < n; ++s){\n        for(auto &e : g[s]){\n          if(dist[s].is_negloop()){\n\
    \            dist[e.to] = Result::negloop();\n          }\n        }\n      }\n\
    \    }\n\n    return dist;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <cassert>\n\
    #include \"Mylib/Graph/Template/graph.cpp\"\n\nnamespace haar_lib {\n  namespace\
    \ bellman_ford_impl {\n    template <typename T>\n    struct result {\n      enum\
    \ class Tag {OK, NEGLOOP, UNREACHABLE} tag;\n      T val;\n      result(Tag tag):\
    \ tag(tag){}\n\n    public:\n      static auto unreachable() {return result(Tag::UNREACHABLE);}\n\
    \      static auto negloop() {return result(Tag::NEGLOOP);}\n      result(T val):\
    \ tag(Tag::OK), val(val){}\n\n      bool is_unreachable() const {return tag ==\
    \ Tag::UNREACHABLE;}\n      bool is_negloop() const {return tag == Tag::NEGLOOP;}\n\
    \      bool is_ok() const {return tag == Tag::OK;}\n\n      T value() const {\n\
    \        assert(tag == Tag::OK);\n        return val;\n      }\n\n      friend\
    \ std::ostream& operator<<(std::ostream &s, const result &a){\n        if(a.is_unreachable())\
    \ s << \"\u221E\";\n        else if(a.is_negloop()) s << \"-\u221E\";\n      \
    \  else s << a.value();\n        return s;\n      }\n    };\n  }\n\n  template\
    \ <typename T>\n  auto bellman_ford(const graph<T> &g, int src){\n    using Result\
    \ = bellman_ford_impl::result<T>;\n    const int n = g.size();\n    std::vector<Result>\
    \ dist(n, Result::unreachable());\n\n    dist[src] = 0;\n\n    for(int i = 0;\
    \ i < n; ++i){\n      for(int s = 0; s < n; ++s){\n        for(auto &e : g[s]){\n\
    \          int t = e.to;\n          T d = e.cost;\n\n          if(dist[s].is_ok()\
    \ and\n             dist[t].is_ok() and\n             dist[s].value() + d < dist[t].value()\
    \ and i == n - 1){\n            dist[t] = Result::negloop();\n          }else{\n\
    \            if(dist[s].is_ok()){\n              if(dist[t].is_unreachable()){\n\
    \                dist[t] = dist[s].value() + d;\n              }else if(dist[t].is_ok()){\n\
    \                dist[t] = std::min(dist[t].value(), dist[s].value() + d);\n \
    \             }\n            }\n          }\n        }\n      }\n    }\n\n   \
    \ for(int i = 0; i < n; ++i){\n      for(int s = 0; s < n; ++s){\n        for(auto\
    \ &e : g[s]){\n          if(dist[s].is_negloop()){\n            dist[e.to] = Result::negloop();\n\
    \          }\n        }\n      }\n    }\n\n    return dist;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/ShortestPath/bellman_ford.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_1_B/main.test.cpp
documentation_of: Mylib/Graph/ShortestPath/bellman_ford.cpp
layout: document
title: Bellman-Ford algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
