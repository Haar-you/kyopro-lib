---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_3_A/main.test.cpp
    title: test/aoj/GRL_3_A/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/GraphUtils/articulation_points.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\n\
    #include <iostream>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/GraphUtils/articulation_points.cpp\"\
    \n\nnamespace haar_lib {\n  namespace articulation_points_impl {\n    template\
    \ <typename T>\n    int dfs(\n      const graph<T> &g,\n      int root,\n    \
    \  int cur,\n      std::vector<int> &visit,\n      std::vector<int> &low,\n  \
    \    std::vector<int> &ret,\n      int &v\n    ){\n      if(visit[cur] != -1)\
    \ return visit[cur];\n      visit[cur] = v;\n\n      int temp = v;\n      std::vector<int>\
    \ children;\n      ++v;\n\n      for(auto &e : g[cur]){\n        if(visit[e.to]\
    \ == -1) children.push_back(e.to);\n        int t = dfs(g, root, e.to, visit,\
    \ low, ret, v);\n        temp = std::min(temp, t);\n      }\n\n      low[cur]\
    \ = temp;\n\n      if(cur != root or children.size() >= 2){\n        for(auto\
    \ x : children){\n          if(low[x] >= visit[cur]){\n            ret.push_back(cur);\n\
    \            break;\n          }\n        }\n      }\n\n      return low[cur];\n\
    \    };\n  }\n\n  template <typename T>\n  std::vector<int> articulation_points(const\
    \ graph<T> &g){\n    const int n = g.size();\n    std::vector<int> visit(n, -1),\
    \ low(n, -1), ret;\n    int v = 0;\n\n    for(int i = 0; i < n; ++i){\n      if(visit[i]\
    \ == -1){\n        articulation_points_impl::dfs(g, i, i, visit, low, ret, v);\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  namespace articulation_points_impl {\n    template\
    \ <typename T>\n    int dfs(\n      const graph<T> &g,\n      int root,\n    \
    \  int cur,\n      std::vector<int> &visit,\n      std::vector<int> &low,\n  \
    \    std::vector<int> &ret,\n      int &v\n    ){\n      if(visit[cur] != -1)\
    \ return visit[cur];\n      visit[cur] = v;\n\n      int temp = v;\n      std::vector<int>\
    \ children;\n      ++v;\n\n      for(auto &e : g[cur]){\n        if(visit[e.to]\
    \ == -1) children.push_back(e.to);\n        int t = dfs(g, root, e.to, visit,\
    \ low, ret, v);\n        temp = std::min(temp, t);\n      }\n\n      low[cur]\
    \ = temp;\n\n      if(cur != root or children.size() >= 2){\n        for(auto\
    \ x : children){\n          if(low[x] >= visit[cur]){\n            ret.push_back(cur);\n\
    \            break;\n          }\n        }\n      }\n\n      return low[cur];\n\
    \    };\n  }\n\n  template <typename T>\n  std::vector<int> articulation_points(const\
    \ graph<T> &g){\n    const int n = g.size();\n    std::vector<int> visit(n, -1),\
    \ low(n, -1), ret;\n    int v = 0;\n\n    for(int i = 0; i < n; ++i){\n      if(visit[i]\
    \ == -1){\n        articulation_points_impl::dfs(g, i, i, visit, low, ret, v);\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/GraphUtils/articulation_points.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_3_A/main.test.cpp
documentation_of: Mylib/Graph/GraphUtils/articulation_points.cpp
layout: document
title: Articulation points
---

## Operations

## Requirements

## Notes

## Problems

## References
