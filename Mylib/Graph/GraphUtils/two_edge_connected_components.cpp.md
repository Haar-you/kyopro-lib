---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Template/graph.cpp
    title: Basic graph
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/two_edge_connected_components/main.test.cpp
    title: test/yosupo-judge/two_edge_connected_components/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/GraphUtils/two_edge_connected_components.cpp\"\
    \n#include <vector>\n#include <stack>\n#line 3 \"Mylib/Graph/Template/graph.cpp\"\
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
    \ <typename T>\n  using tree = graph<T>;\n}\n#line 5 \"Mylib/Graph/GraphUtils/two_edge_connected_components.cpp\"\
    \n\nnamespace haar_lib {\n  namespace two_edge_connected_components_impl {\n \
    \   template <typename T>\n    int dfs(\n      const graph<T> &g,\n      int cur,\n\
    \      int par,\n      std::vector<int> &low,\n      std::vector<int> &order,\n\
    \      std::vector<std::vector<int>> &ret,\n      std::stack<int> &st,\n     \
    \ int &v\n    ){\n      if(order[cur] != -1) return order[cur];\n      order[cur]\
    \ = v;\n      int temp = v++;\n      st.push(cur);\n\n      int count = 0;\n\n\
    \      for(const auto &e : g[cur]){\n        if(e.to == par){\n          ++count;\n\
    \          if(count == 1) continue;\n        }\n\n        const int t = dfs(g,\
    \ e.to, cur, low, order, ret, st, v);\n        temp = std::min(temp, t);\n\n \
    \       if(low[e.to] > order[cur]){ // e is a bridge\n          std::vector<int>\
    \ cc;\n          while(true){\n            int c = st.top();\n            cc.emplace_back(c);\n\
    \            st.pop();\n            if(c == e.to) break;\n          }\n      \
    \    ret.emplace_back(cc);\n        }\n      }\n\n      return low[cur] = temp;\n\
    \    }\n  }\n\n  template <typename T>\n  auto two_edge_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<int> low(n, -1),\
    \ order(n, -1);\n    std::vector<std::vector<int>> ret;\n    std::stack<int> st;\n\
    \    int v = 0;\n\n    for(int i = 0; i < n; ++i){\n      if(order[i] == -1){\n\
    \        two_edge_connected_components_impl::dfs(g, i, -1, low, order, ret, st,\
    \ v);\n        if(not st.empty()){\n          std::vector<int> cc;\n         \
    \ while(not st.empty()) cc.emplace_back(st.top()), st.pop();\n          ret.emplace_back(cc);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <stack>\n#include \"Mylib/Graph/Template/graph.cpp\"\
    \n\nnamespace haar_lib {\n  namespace two_edge_connected_components_impl {\n \
    \   template <typename T>\n    int dfs(\n      const graph<T> &g,\n      int cur,\n\
    \      int par,\n      std::vector<int> &low,\n      std::vector<int> &order,\n\
    \      std::vector<std::vector<int>> &ret,\n      std::stack<int> &st,\n     \
    \ int &v\n    ){\n      if(order[cur] != -1) return order[cur];\n      order[cur]\
    \ = v;\n      int temp = v++;\n      st.push(cur);\n\n      int count = 0;\n\n\
    \      for(const auto &e : g[cur]){\n        if(e.to == par){\n          ++count;\n\
    \          if(count == 1) continue;\n        }\n\n        const int t = dfs(g,\
    \ e.to, cur, low, order, ret, st, v);\n        temp = std::min(temp, t);\n\n \
    \       if(low[e.to] > order[cur]){ // e is a bridge\n          std::vector<int>\
    \ cc;\n          while(true){\n            int c = st.top();\n            cc.emplace_back(c);\n\
    \            st.pop();\n            if(c == e.to) break;\n          }\n      \
    \    ret.emplace_back(cc);\n        }\n      }\n\n      return low[cur] = temp;\n\
    \    }\n  }\n\n  template <typename T>\n  auto two_edge_connected_components(const\
    \ graph<T> &g){\n    const int n = g.size();\n\n    std::vector<int> low(n, -1),\
    \ order(n, -1);\n    std::vector<std::vector<int>> ret;\n    std::stack<int> st;\n\
    \    int v = 0;\n\n    for(int i = 0; i < n; ++i){\n      if(order[i] == -1){\n\
    \        two_edge_connected_components_impl::dfs(g, i, -1, low, order, ret, st,\
    \ v);\n        if(not st.empty()){\n          std::vector<int> cc;\n         \
    \ while(not st.empty()) cc.emplace_back(st.top()), st.pop();\n          ret.emplace_back(cc);\n\
    \        }\n      }\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Graph/Template/graph.cpp
  isVerificationFile: false
  path: Mylib/Graph/GraphUtils/two_edge_connected_components.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/two_edge_connected_components/main.test.cpp
documentation_of: Mylib/Graph/GraphUtils/two_edge_connected_components.cpp
layout: document
title: Two edge connected components
---

## Operations

## Requirements

## Notes

## Problems

## References
