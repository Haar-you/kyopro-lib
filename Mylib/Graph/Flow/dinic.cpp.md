---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_6_A/main.dinic.test.cpp
    title: test/aoj/GRL_6_A/main.dinic.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Flow/dinic.cpp\"\n#include <vector>\n#include\
    \ <utility>\n#include <queue>\n#include <algorithm>\n\nnamespace haar_lib {\n\
    \  namespace dinic_impl {\n    template <typename T>\n    struct edge {\n    \
    \  int from, to, rev;\n      T cap;\n      bool is_rev;\n      edge(int from,\
    \ int to, int rev, T cap, bool is_rev):\n        from(from), to(to), rev(rev),\
    \ cap(cap), is_rev(is_rev){}\n    };\n  }\n\n  template <typename T>\n  class\
    \ dinic {\n    using edge = dinic_impl::edge<T>;\n\n    int size;\n    std::vector<std::vector<edge>>\
    \ g;\n    std::vector<int> level;\n\n    bool build_level(int s, int t){\n   \
    \   std::fill(level.begin(), level.end(), 0);\n      level[s] = 1;\n      std::queue<int>\
    \ q;\n      q.push(s);\n      while(not q.empty()){\n        int cur = q.front();\
    \ q.pop();\n        for(auto &e : g[cur]){\n          if(level[e.to] == 0 and\
    \ e.cap > 0){\n            level[e.to] = level[e.from] + 1;\n            q.push(e.to);\n\
    \          }\n        }\n      }\n      return level[t] != 0;\n    }\n\n    void\
    \ dfs(std::vector<edge*> &path, T &flow, int cur, int t){\n      if(cur == t){\n\
    \        T f = std::numeric_limits<T>::max();\n\n        for(auto e : path){\n\
    \          f = std::min(f, (*e).cap);\n        }\n\n        for(auto e : path){\n\
    \          (*e).cap -= f;\n          g[e->to][e->rev].cap += f;\n        }\n\n\
    \        flow += f;\n      }else{\n        for(auto &e : g[cur]){\n          if(e.cap\
    \ > 0 and level[e.to] > level[e.from]){\n            path.emplace_back(&e);\n\
    \            dfs(path, flow, e.to, t);\n            path.pop_back();\n       \
    \   }\n        }\n      }\n    }\n\n  public:\n    dinic(){}\n    dinic(int size):\
    \ size(size), g(size), level(size){}\n\n    void add_edge(int from, int to, T\
    \ c){\n      g[from].emplace_back(from, to, (int)g[to].size(), c, false);\n  \
    \    g[to].emplace_back(to, from, (int)g[from].size() - 1, 0, true);\n    }\n\n\
    \    T solve(int s, int t){\n      T f = 0;\n      while(build_level(s, t)){\n\
    \        T a = 0;\n        std::vector<edge*> path;\n        dfs(path, a, s, t);\n\
    \        f += a;\n      }\n      return f;\n    }\n\n    std::vector<edge> edges()\
    \ const {\n      std::vector<edge> ret;\n      for(auto &v : g) ret.insert(ret.end(),\
    \ v.begin(), v.end());\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <queue>\n#include\
    \ <algorithm>\n\nnamespace haar_lib {\n  namespace dinic_impl {\n    template\
    \ <typename T>\n    struct edge {\n      int from, to, rev;\n      T cap;\n  \
    \    bool is_rev;\n      edge(int from, int to, int rev, T cap, bool is_rev):\n\
    \        from(from), to(to), rev(rev), cap(cap), is_rev(is_rev){}\n    };\n  }\n\
    \n  template <typename T>\n  class dinic {\n    using edge = dinic_impl::edge<T>;\n\
    \n    int size;\n    std::vector<std::vector<edge>> g;\n    std::vector<int> level;\n\
    \n    bool build_level(int s, int t){\n      std::fill(level.begin(), level.end(),\
    \ 0);\n      level[s] = 1;\n      std::queue<int> q;\n      q.push(s);\n     \
    \ while(not q.empty()){\n        int cur = q.front(); q.pop();\n        for(auto\
    \ &e : g[cur]){\n          if(level[e.to] == 0 and e.cap > 0){\n            level[e.to]\
    \ = level[e.from] + 1;\n            q.push(e.to);\n          }\n        }\n  \
    \    }\n      return level[t] != 0;\n    }\n\n    void dfs(std::vector<edge*>\
    \ &path, T &flow, int cur, int t){\n      if(cur == t){\n        T f = std::numeric_limits<T>::max();\n\
    \n        for(auto e : path){\n          f = std::min(f, (*e).cap);\n        }\n\
    \n        for(auto e : path){\n          (*e).cap -= f;\n          g[e->to][e->rev].cap\
    \ += f;\n        }\n\n        flow += f;\n      }else{\n        for(auto &e :\
    \ g[cur]){\n          if(e.cap > 0 and level[e.to] > level[e.from]){\n       \
    \     path.emplace_back(&e);\n            dfs(path, flow, e.to, t);\n        \
    \    path.pop_back();\n          }\n        }\n      }\n    }\n\n  public:\n \
    \   dinic(){}\n    dinic(int size): size(size), g(size), level(size){}\n\n   \
    \ void add_edge(int from, int to, T c){\n      g[from].emplace_back(from, to,\
    \ (int)g[to].size(), c, false);\n      g[to].emplace_back(to, from, (int)g[from].size()\
    \ - 1, 0, true);\n    }\n\n    T solve(int s, int t){\n      T f = 0;\n      while(build_level(s,\
    \ t)){\n        T a = 0;\n        std::vector<edge*> path;\n        dfs(path,\
    \ a, s, t);\n        f += a;\n      }\n      return f;\n    }\n\n    std::vector<edge>\
    \ edges() const {\n      std::vector<edge> ret;\n      for(auto &v : g) ret.insert(ret.end(),\
    \ v.begin(), v.end());\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Flow/dinic.cpp
  requiredBy: []
  timestamp: '2020-09-17 19:52:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_6_A/main.dinic.test.cpp
documentation_of: Mylib/Graph/Flow/dinic.cpp
layout: document
title: Dinic algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
