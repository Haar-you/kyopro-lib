---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3058/main.test.cpp
    title: test/aoj/3058/main.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp
    title: test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903/main.test.cpp
    title: test/aoj/2903/main.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_7_A/main.test.cpp
    title: test/aoj/GRL_7_A/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Flow/ford_fulkerson.cpp\"\n#include <vector>\n\
    #include <algorithm>\n\nnamespace haar_lib {\n  namespace ford_fulkerson_impl\
    \ {\n    template <typename T>\n    struct edge {\n      int from, to, rev;\n\
    \      T cap;\n      bool is_rev;\n      edge(int from, int to, int rev, T cap,\
    \ bool is_rev):\n        from(from), to(to), rev(rev), cap(cap), is_rev(is_rev){}\n\
    \    };\n  }\n\n  template <typename T>\n  class ford_fulkerson {\n    using edge\
    \ = ford_fulkerson_impl::edge<T>;\n\n    int size;\n    std::vector<std::vector<edge>>\
    \ g;\n    std::vector<bool> visit;\n\n    T dfs(int from, int to, T flow){\n \
    \     if(from == to) return flow;\n      visit[from] = true;\n\n      for(auto\
    \ &e : g[from]){\n        if(!visit[e.to] and e.cap > 0){\n          T d = dfs(e.to,\
    \ to, std::min(flow, e.cap));\n          if(d > 0){\n            e.cap -= d;\n\
    \            g[e.to][e.rev].cap += d;\n            return d;\n          }\n  \
    \      }\n      }\n      return 0;\n    }\n\n  public:\n    ford_fulkerson(){}\n\
    \    ford_fulkerson(int size): size(size), g(size), visit(size){}\n\n    void\
    \ add_edge(int from, int to, T c){\n      g[from].emplace_back(from, to, (int)g[to].size(),\
    \ c, false);\n      g[to].emplace_back(to, from, (int)g[from].size() - 1, 0, true);\n\
    \    }\n\n    void reset_flow(){\n      for(auto &v : g){\n        for(auto &e\
    \ : v){\n          if(e.is_rev){\n            g[e.to][e.rev].cap += e.cap;\n \
    \           e.cap = 0;\n          }\n        }\n      }\n    }\n\n    T solve(int\
    \ s, int t){\n      T ret = 0;\n\n      while(1){\n        visit.assign(size,\
    \ false);\n        T flow = dfs(s, t, std::numeric_limits<T>::max());\n      \
    \  if(flow == 0) return ret;\n        ret += flow;\n      }\n    }\n\n    std::vector<edge>\
    \ edges() const {\n      std::vector<edge> ret;\n      for(auto &v : g) ret.insert(ret.end(),\
    \ v.begin(), v.end());\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  namespace ford_fulkerson_impl {\n    template <typename T>\n    struct\
    \ edge {\n      int from, to, rev;\n      T cap;\n      bool is_rev;\n      edge(int\
    \ from, int to, int rev, T cap, bool is_rev):\n        from(from), to(to), rev(rev),\
    \ cap(cap), is_rev(is_rev){}\n    };\n  }\n\n  template <typename T>\n  class\
    \ ford_fulkerson {\n    using edge = ford_fulkerson_impl::edge<T>;\n\n    int\
    \ size;\n    std::vector<std::vector<edge>> g;\n    std::vector<bool> visit;\n\
    \n    T dfs(int from, int to, T flow){\n      if(from == to) return flow;\n  \
    \    visit[from] = true;\n\n      for(auto &e : g[from]){\n        if(!visit[e.to]\
    \ and e.cap > 0){\n          T d = dfs(e.to, to, std::min(flow, e.cap));\n   \
    \       if(d > 0){\n            e.cap -= d;\n            g[e.to][e.rev].cap +=\
    \ d;\n            return d;\n          }\n        }\n      }\n      return 0;\n\
    \    }\n\n  public:\n    ford_fulkerson(){}\n    ford_fulkerson(int size): size(size),\
    \ g(size), visit(size){}\n\n    void add_edge(int from, int to, T c){\n      g[from].emplace_back(from,\
    \ to, (int)g[to].size(), c, false);\n      g[to].emplace_back(to, from, (int)g[from].size()\
    \ - 1, 0, true);\n    }\n\n    void reset_flow(){\n      for(auto &v : g){\n \
    \       for(auto &e : v){\n          if(e.is_rev){\n            g[e.to][e.rev].cap\
    \ += e.cap;\n            e.cap = 0;\n          }\n        }\n      }\n    }\n\n\
    \    T solve(int s, int t){\n      T ret = 0;\n\n      while(1){\n        visit.assign(size,\
    \ false);\n        T flow = dfs(s, t, std::numeric_limits<T>::max());\n      \
    \  if(flow == 0) return ret;\n        ret += flow;\n      }\n    }\n\n    std::vector<edge>\
    \ edges() const {\n      std::vector<edge> ret;\n      for(auto &v : g) ret.insert(ret.end(),\
    \ v.begin(), v.end());\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Flow/ford_fulkerson.cpp
  requiredBy: []
  timestamp: '2020-09-17 19:52:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/3058/main.test.cpp
  - test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp
  - test/aoj/2903/main.test.cpp
  - test/aoj/GRL_7_A/main.test.cpp
documentation_of: Mylib/Graph/Flow/ford_fulkerson.cpp
layout: document
title: Ford-Fulkerson algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
