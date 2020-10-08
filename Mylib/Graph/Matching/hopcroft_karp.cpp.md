---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_7_A/main.hopcroft_karp.test.cpp
    title: test/aoj/GRL_7_A/main.hopcroft_karp.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/bipartitematching/main.test.cpp
    title: test/yosupo-judge/bipartitematching/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Matching/hopcroft_karp.cpp\"\n#include <vector>\n\
    #include <queue>\n#include <utility>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  class hopcroft_karp {\n    struct edge {\n      int from, to;\n      int\
    \ rev;\n      bool used;\n    };\n\n    int L_, R_, N_;\n    std::vector<std::vector<edge>>\
    \ g_;\n    std::vector<int> dist_;\n\n    bool bfs(){\n      dist_.assign(N_,\
    \ -1);\n      std::queue<int> q;\n\n      q.push(0);\n      dist_[0] = 0;\n\n\
    \      while(not q.empty()){\n        int i = q.front(); q.pop();\n\n        for(auto\
    \ &e : g_[i]){\n          if(not e.used and dist_[e.to] == -1){\n            dist_[e.to]\
    \ = dist_[i] + 1;\n            q.push(e.to);\n          }\n        }\n      }\n\
    \n      return dist_[N_ - 1] != -1;\n    }\n\n    bool dfs(int cur){\n      if(cur\
    \ == N_ - 1) return true;\n\n      for(auto &e : g_[cur]){\n        if(not e.used\
    \ and dist_[cur] + 1 == dist_[e.to]){\n          if(dfs(e.to)){\n            e.used\
    \ = true;\n            if(e.rev >= 0) g_[e.to][e.rev].used = false;\n        \
    \    return true;\n          }\n        }\n      }\n\n      return false;\n  \
    \  }\n\n  public:\n    hopcroft_karp(){}\n    hopcroft_karp(int L, int R): L_(L),\
    \ R_(R), N_(L + R + 2), g_(N_), dist_(N_){\n      for(int i = 0; i < L_; ++i){\n\
    \        g_[0].push_back((edge){0, i + 1, -1, false});\n      }\n\n      for(int\
    \ i = 0; i < R_; ++i){\n        g_[i + L_ + 1].push_back((edge){i + L_ + 1, N_\
    \ - 1, -1, false});\n      }\n    }\n\n    void add_edge(int i, int j){\n    \
    \  assert(0 <= i and i < L_);\n      assert(0 <= j and j < R_);\n\n      const\
    \ int x = i + 1;\n      const int y = j + L_ + 1;\n\n      g_[x].push_back((edge){x,\
    \ y, (int)g_[y].size(), false});\n      g_[y].push_back((edge){y, x, (int)g_[x].size()\
    \ - 1, true});\n    }\n\n    int match(){\n      int ret = 0;\n\n      while(bfs()){\n\
    \        int flow = 0;\n        for(int i = 0; i < L_; ++i){\n          auto &e\
    \ = g_[0][i];\n          if(not e.used and dfs(e.to)){\n            e.used = true;\n\
    \            ++flow;\n          }\n        }\n        if(flow == 0) break;\n \
    \       ret += flow;\n      }\n\n      return ret;\n    }\n\n    auto get_matching(){\n\
    \      std::vector<std::pair<int, int>> ret;\n      for(int i = 0; i < L_; ++i){\n\
    \        for(auto &e : g_[i + 1]){\n          if(e.used) ret.emplace_back(i, e.to\
    \ - L_ - 1);\n        }\n      }\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <utility>\n#include\
    \ <cassert>\n\nnamespace haar_lib {\n  class hopcroft_karp {\n    struct edge\
    \ {\n      int from, to;\n      int rev;\n      bool used;\n    };\n\n    int\
    \ L_, R_, N_;\n    std::vector<std::vector<edge>> g_;\n    std::vector<int> dist_;\n\
    \n    bool bfs(){\n      dist_.assign(N_, -1);\n      std::queue<int> q;\n\n \
    \     q.push(0);\n      dist_[0] = 0;\n\n      while(not q.empty()){\n       \
    \ int i = q.front(); q.pop();\n\n        for(auto &e : g_[i]){\n          if(not\
    \ e.used and dist_[e.to] == -1){\n            dist_[e.to] = dist_[i] + 1;\n  \
    \          q.push(e.to);\n          }\n        }\n      }\n\n      return dist_[N_\
    \ - 1] != -1;\n    }\n\n    bool dfs(int cur){\n      if(cur == N_ - 1) return\
    \ true;\n\n      for(auto &e : g_[cur]){\n        if(not e.used and dist_[cur]\
    \ + 1 == dist_[e.to]){\n          if(dfs(e.to)){\n            e.used = true;\n\
    \            if(e.rev >= 0) g_[e.to][e.rev].used = false;\n            return\
    \ true;\n          }\n        }\n      }\n\n      return false;\n    }\n\n  public:\n\
    \    hopcroft_karp(){}\n    hopcroft_karp(int L, int R): L_(L), R_(R), N_(L +\
    \ R + 2), g_(N_), dist_(N_){\n      for(int i = 0; i < L_; ++i){\n        g_[0].push_back((edge){0,\
    \ i + 1, -1, false});\n      }\n\n      for(int i = 0; i < R_; ++i){\n       \
    \ g_[i + L_ + 1].push_back((edge){i + L_ + 1, N_ - 1, -1, false});\n      }\n\
    \    }\n\n    void add_edge(int i, int j){\n      assert(0 <= i and i < L_);\n\
    \      assert(0 <= j and j < R_);\n\n      const int x = i + 1;\n      const int\
    \ y = j + L_ + 1;\n\n      g_[x].push_back((edge){x, y, (int)g_[y].size(), false});\n\
    \      g_[y].push_back((edge){y, x, (int)g_[x].size() - 1, true});\n    }\n\n\
    \    int match(){\n      int ret = 0;\n\n      while(bfs()){\n        int flow\
    \ = 0;\n        for(int i = 0; i < L_; ++i){\n          auto &e = g_[0][i];\n\
    \          if(not e.used and dfs(e.to)){\n            e.used = true;\n       \
    \     ++flow;\n          }\n        }\n        if(flow == 0) break;\n        ret\
    \ += flow;\n      }\n\n      return ret;\n    }\n\n    auto get_matching(){\n\
    \      std::vector<std::pair<int, int>> ret;\n      for(int i = 0; i < L_; ++i){\n\
    \        for(auto &e : g_[i + 1]){\n          if(e.used) ret.emplace_back(i, e.to\
    \ - L_ - 1);\n        }\n      }\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Matching/hopcroft_karp.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/bipartitematching/main.test.cpp
  - test/aoj/GRL_7_A/main.hopcroft_karp.test.cpp
documentation_of: Mylib/Graph/Matching/hopcroft_karp.cpp
layout: document
title: Hopcroft-Karp algorithm
---

## Operations

- `HopcroftKarp(L, R)`
- `add_edge(i, j)`
- `solve()`
	- Time complexity $O(E \sqrt V)$
- `get_matching()`

## Requirements

## Notes

## Problems

## References
