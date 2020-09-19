---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2293/main.test.cpp
    title: test/aoj/2293/main.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_6_B/main.test.cpp
    title: test/aoj/GRL_6_B/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/assignment/main.test.cpp
    title: test/yosupo-judge/assignment/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Flow/minimum_cost_flow.cpp\"\n#include <vector>\n\
    #include <queue>\n#include <utility>\n#include <functional>\n#include <algorithm>\n\
    #include <tuple>\n\nnamespace haar_lib {\n  namespace minimum_cost_flow_impl {\n\
    \    template <typename T, typename U>\n    struct edge {\n      int from, to,\
    \ rev;\n      T cap;\n      U cost;\n      bool is_rev;\n      edge(int from,\
    \ int to, int rev, T cap, U cost, bool is_rev):\n        from(from), to(to), rev(rev),\
    \ cap(cap), cost(cost), is_rev(is_rev){}\n    };\n  }\n\n  template <typename\
    \ Capacity, typename Cost>\n  class minimum_cost_flow {\n    using edge = minimum_cost_flow_impl::edge<Capacity,\
    \ Cost>;\n\n    int size;\n    std::vector<std::vector<edge>> g;\n\n  public:\n\
    \    minimum_cost_flow(){}\n    minimum_cost_flow(int size): size(size), g(size){}\n\
    \n    void add_edge(int from, int to, Capacity cap, Cost cost){\n      g[from].emplace_back(from,\
    \ to, g[to].size(), cap, cost, false);\n      g[to].emplace_back(to, from, g[from].size()\
    \ - 1, 0, -cost, true);\n    }\n\n    std::pair<Capacity, Cost> solve(int src,\
    \ int dst, const Capacity &f){\n      using P = std::pair<Cost, int>;\n      Cost\
    \ ret = 0;\n      Capacity flow = f;\n      std::vector<Cost> h(size, 0), cost(size);\n\
    \      std::vector<bool> is_inf(size, true);\n      std::vector<int> prev_node(size),\
    \ prev_edge(size);\n      std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n      while(flow > 0){\n        std::fill(is_inf.begin(), is_inf.end(),\
    \ true);\n\n        // src -> dst \u306E\u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF\
    \u3092\u63A2\u7D22\u3059\u308B\u3002 (dijkstra algorithm)\n        cost[src] =\
    \ 0;\n        pq.emplace(0, src);\n        is_inf[src] = false;\n\n        while(!pq.empty()){\n\
    \          Cost c;\n          int v;\n          std::tie(c, v) = pq.top(); pq.pop();\n\
    \n          if(cost[v] < c) continue;\n          for(int i = 0; i < (int)g[v].size();\
    \ ++i){\n            edge &e = g[v][i];\n            int w = e.to;\n         \
    \   Capacity cap = e.cap;\n            Cost cst = e.cost;\n            if(cap\
    \ > 0){\n              if(is_inf[w] or cost[w] + h[w] > cost[v] + h[v] + cst){\n\
    \                is_inf[w] = false;\n                cost[w] = cost[v] + cst +\
    \ h[v] - h[w];\n                prev_node[w] = v;\n                prev_edge[w]\
    \ = i;\n                pq.emplace(cost[w], w);\n              }\n           \
    \ }\n          }\n        }\n\n        if(is_inf[dst]) return {f - flow, ret};\
    \ // dst\u3078\u5230\u9054\u4E0D\u53EF\u80FD\n\n        for(int i = 0; i < size;\
    \ ++i) h[i] += cost[i];\n\n        // src -> dst \u306E\u6700\u5C0F\u30B3\u30B9\
    \u30C8\u7D4C\u8DEF\u3078\u6D41\u305B\u308B\u91CF(df)\u3092\u6C7A\u5B9A\u3059\u308B\
    \u3002\n        Capacity df = flow;\n        for(int cur = dst; cur != src; cur\
    \ = prev_node[cur]){\n          df = std::min(df, g[prev_node[cur]][prev_edge[cur]].cap);\n\
    \        }\n\n        flow -= df;\n        ret += df * h[dst];\n\n        // cap\u306E\
    \u66F4\u65B0\n        for(int cur = dst; cur != src; cur = prev_node[cur]){\n\
    \          edge &e = g[prev_node[cur]][prev_edge[cur]];\n          e.cap -= df;\n\
    \          g[cur][e.rev].cap += df;\n        }\n      }\n\n      return {f - flow,\
    \ ret};\n    }\n\n    std::vector<edge> edges() const {\n      std::vector<edge>\
    \ ret;\n      for(auto &v : g) ret.insert(ret.end(), v.begin(), v.end());\n  \
    \    return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <utility>\n#include\
    \ <functional>\n#include <algorithm>\n#include <tuple>\n\nnamespace haar_lib {\n\
    \  namespace minimum_cost_flow_impl {\n    template <typename T, typename U>\n\
    \    struct edge {\n      int from, to, rev;\n      T cap;\n      U cost;\n  \
    \    bool is_rev;\n      edge(int from, int to, int rev, T cap, U cost, bool is_rev):\n\
    \        from(from), to(to), rev(rev), cap(cap), cost(cost), is_rev(is_rev){}\n\
    \    };\n  }\n\n  template <typename Capacity, typename Cost>\n  class minimum_cost_flow\
    \ {\n    using edge = minimum_cost_flow_impl::edge<Capacity, Cost>;\n\n    int\
    \ size;\n    std::vector<std::vector<edge>> g;\n\n  public:\n    minimum_cost_flow(){}\n\
    \    minimum_cost_flow(int size): size(size), g(size){}\n\n    void add_edge(int\
    \ from, int to, Capacity cap, Cost cost){\n      g[from].emplace_back(from, to,\
    \ g[to].size(), cap, cost, false);\n      g[to].emplace_back(to, from, g[from].size()\
    \ - 1, 0, -cost, true);\n    }\n\n    std::pair<Capacity, Cost> solve(int src,\
    \ int dst, const Capacity &f){\n      using P = std::pair<Cost, int>;\n      Cost\
    \ ret = 0;\n      Capacity flow = f;\n      std::vector<Cost> h(size, 0), cost(size);\n\
    \      std::vector<bool> is_inf(size, true);\n      std::vector<int> prev_node(size),\
    \ prev_edge(size);\n      std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n      while(flow > 0){\n        std::fill(is_inf.begin(), is_inf.end(),\
    \ true);\n\n        // src -> dst \u306E\u6700\u5C0F\u30B3\u30B9\u30C8\u7D4C\u8DEF\
    \u3092\u63A2\u7D22\u3059\u308B\u3002 (dijkstra algorithm)\n        cost[src] =\
    \ 0;\n        pq.emplace(0, src);\n        is_inf[src] = false;\n\n        while(!pq.empty()){\n\
    \          Cost c;\n          int v;\n          std::tie(c, v) = pq.top(); pq.pop();\n\
    \n          if(cost[v] < c) continue;\n          for(int i = 0; i < (int)g[v].size();\
    \ ++i){\n            edge &e = g[v][i];\n            int w = e.to;\n         \
    \   Capacity cap = e.cap;\n            Cost cst = e.cost;\n            if(cap\
    \ > 0){\n              if(is_inf[w] or cost[w] + h[w] > cost[v] + h[v] + cst){\n\
    \                is_inf[w] = false;\n                cost[w] = cost[v] + cst +\
    \ h[v] - h[w];\n                prev_node[w] = v;\n                prev_edge[w]\
    \ = i;\n                pq.emplace(cost[w], w);\n              }\n           \
    \ }\n          }\n        }\n\n        if(is_inf[dst]) return {f - flow, ret};\
    \ // dst\u3078\u5230\u9054\u4E0D\u53EF\u80FD\n\n        for(int i = 0; i < size;\
    \ ++i) h[i] += cost[i];\n\n        // src -> dst \u306E\u6700\u5C0F\u30B3\u30B9\
    \u30C8\u7D4C\u8DEF\u3078\u6D41\u305B\u308B\u91CF(df)\u3092\u6C7A\u5B9A\u3059\u308B\
    \u3002\n        Capacity df = flow;\n        for(int cur = dst; cur != src; cur\
    \ = prev_node[cur]){\n          df = std::min(df, g[prev_node[cur]][prev_edge[cur]].cap);\n\
    \        }\n\n        flow -= df;\n        ret += df * h[dst];\n\n        // cap\u306E\
    \u66F4\u65B0\n        for(int cur = dst; cur != src; cur = prev_node[cur]){\n\
    \          edge &e = g[prev_node[cur]][prev_edge[cur]];\n          e.cap -= df;\n\
    \          g[cur][e.rev].cap += df;\n        }\n      }\n\n      return {f - flow,\
    \ ret};\n    }\n\n    std::vector<edge> edges() const {\n      std::vector<edge>\
    \ ret;\n      for(auto &v : g) ret.insert(ret.end(), v.begin(), v.end());\n  \
    \    return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Flow/minimum_cost_flow.cpp
  requiredBy: []
  timestamp: '2020-09-17 19:52:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2293/main.test.cpp
  - test/aoj/GRL_6_B/main.test.cpp
  - test/yosupo-judge/assignment/main.test.cpp
documentation_of: Mylib/Graph/Flow/minimum_cost_flow.cpp
layout: document
title: Minimum cost flow
---

## Operations

## Requirements

## Notes

## Problems

## References
