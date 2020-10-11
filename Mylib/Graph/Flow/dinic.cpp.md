---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615/main.test.cpp
    title: test/aoj/1615/main.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_6_A/main.dinic.test.cpp
    title: test/aoj/GRL_6_A/main.dinic.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Flow/dinic.cpp\"\n#include <vector>\n#include\
    \ <utility>\n#include <queue>\n#include <algorithm>\n#include <cassert>\n\nnamespace\
    \ haar_lib {\n  namespace dinic_impl {\n    template <typename T>\n    struct\
    \ edge {\n      int from, to, rev;\n      T cap;\n      bool is_rev;\n      edge(int\
    \ from, int to, int rev, T cap, bool is_rev):\n        from(from), to(to), rev(rev),\
    \ cap(cap), is_rev(is_rev){}\n    };\n  }\n\n  template <typename T>\n  class\
    \ dinic {\n  public:\n    using edge = dinic_impl::edge<T>;\n    using capacity_type\
    \ = T;\n\n  private:\n    int size_;\n    std::vector<std::vector<edge>> g_;\n\
    \    std::vector<int> level_;\n\n    bool build_level(int s, int t){\n      std::fill(level_.begin(),\
    \ level_.end(), 0);\n      level_[s] = 1;\n      std::queue<int> q;\n      q.push(s);\n\
    \      while(not q.empty()){\n        int cur = q.front(); q.pop();\n        for(auto\
    \ &e : g_[cur]){\n          if(level_[e.to] == 0 and e.cap > 0){\n           \
    \ level_[e.to] = level_[e.from] + 1;\n            q.push(e.to);\n          }\n\
    \        }\n      }\n      return level_[t] != 0;\n    }\n\n    void dfs(std::vector<edge*>\
    \ &path, T &flow, int cur, int t){\n      if(cur == t){\n        T f = std::numeric_limits<T>::max();\n\
    \n        for(auto e : path){\n          f = std::min(f, (*e).cap);\n        }\n\
    \n        for(auto e : path){\n          (*e).cap -= f;\n          g_[e->to][e->rev].cap\
    \ += f;\n        }\n\n        flow += f;\n      }else{\n        for(auto &e :\
    \ g_[cur]){\n          if(e.cap > 0 and level_[e.to] > level_[e.from]){\n    \
    \        path.emplace_back(&e);\n            dfs(path, flow, e.to, t);\n     \
    \       path.pop_back();\n          }\n        }\n      }\n    }\n\n  public:\n\
    \    dinic(){}\n    dinic(int size): size_(size), g_(size), level_(size){}\n\n\
    \    void add_edge(int from, int to, T c){\n      assert(0 <= from and from <\
    \ size_);\n      assert(0 <= to and to < size_);\n      g_[from].emplace_back(from,\
    \ to, (int)g_[to].size(), c, false);\n      g_[to].emplace_back(to, from, (int)g_[from].size()\
    \ - 1, 0, true);\n    }\n\n    T max_flow(int s, int t){\n      assert(0 <= s\
    \ and s < size_);\n      assert(0 <= t and t < size_);\n\n      T f = 0;\n   \
    \   while(build_level(s, t)){\n        T a = 0;\n        std::vector<edge*> path;\n\
    \        dfs(path, a, s, t);\n        f += a;\n      }\n      return f;\n    }\n\
    \n    std::vector<edge> edges() const {\n      std::vector<edge> ret;\n      for(auto\
    \ &v : g_) ret.insert(ret.end(), v.begin(), v.end());\n      return ret;\n   \
    \ }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <queue>\n#include\
    \ <algorithm>\n#include <cassert>\n\nnamespace haar_lib {\n  namespace dinic_impl\
    \ {\n    template <typename T>\n    struct edge {\n      int from, to, rev;\n\
    \      T cap;\n      bool is_rev;\n      edge(int from, int to, int rev, T cap,\
    \ bool is_rev):\n        from(from), to(to), rev(rev), cap(cap), is_rev(is_rev){}\n\
    \    };\n  }\n\n  template <typename T>\n  class dinic {\n  public:\n    using\
    \ edge = dinic_impl::edge<T>;\n    using capacity_type = T;\n\n  private:\n  \
    \  int size_;\n    std::vector<std::vector<edge>> g_;\n    std::vector<int> level_;\n\
    \n    bool build_level(int s, int t){\n      std::fill(level_.begin(), level_.end(),\
    \ 0);\n      level_[s] = 1;\n      std::queue<int> q;\n      q.push(s);\n    \
    \  while(not q.empty()){\n        int cur = q.front(); q.pop();\n        for(auto\
    \ &e : g_[cur]){\n          if(level_[e.to] == 0 and e.cap > 0){\n           \
    \ level_[e.to] = level_[e.from] + 1;\n            q.push(e.to);\n          }\n\
    \        }\n      }\n      return level_[t] != 0;\n    }\n\n    void dfs(std::vector<edge*>\
    \ &path, T &flow, int cur, int t){\n      if(cur == t){\n        T f = std::numeric_limits<T>::max();\n\
    \n        for(auto e : path){\n          f = std::min(f, (*e).cap);\n        }\n\
    \n        for(auto e : path){\n          (*e).cap -= f;\n          g_[e->to][e->rev].cap\
    \ += f;\n        }\n\n        flow += f;\n      }else{\n        for(auto &e :\
    \ g_[cur]){\n          if(e.cap > 0 and level_[e.to] > level_[e.from]){\n    \
    \        path.emplace_back(&e);\n            dfs(path, flow, e.to, t);\n     \
    \       path.pop_back();\n          }\n        }\n      }\n    }\n\n  public:\n\
    \    dinic(){}\n    dinic(int size): size_(size), g_(size), level_(size){}\n\n\
    \    void add_edge(int from, int to, T c){\n      assert(0 <= from and from <\
    \ size_);\n      assert(0 <= to and to < size_);\n      g_[from].emplace_back(from,\
    \ to, (int)g_[to].size(), c, false);\n      g_[to].emplace_back(to, from, (int)g_[from].size()\
    \ - 1, 0, true);\n    }\n\n    T max_flow(int s, int t){\n      assert(0 <= s\
    \ and s < size_);\n      assert(0 <= t and t < size_);\n\n      T f = 0;\n   \
    \   while(build_level(s, t)){\n        T a = 0;\n        std::vector<edge*> path;\n\
    \        dfs(path, a, s, t);\n        f += a;\n      }\n      return f;\n    }\n\
    \n    std::vector<edge> edges() const {\n      std::vector<edge> ret;\n      for(auto\
    \ &v : g_) ret.insert(ret.end(), v.begin(), v.end());\n      return ret;\n   \
    \ }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Flow/dinic.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1615/main.test.cpp
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
