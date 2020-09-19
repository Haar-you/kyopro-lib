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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/Matching/hopcroft_karp.cpp\"\n#include <vector>\n\
    #include <queue>\n#include <utility>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  class hopcroft_karp {\n    struct edge {\n      int from, to;\n      int\
    \ rev;\n      bool used;\n    };\n\n    int L, R, N;\n    std::vector<std::vector<edge>>\
    \ graph;\n    std::vector<int> dist;\n\n    bool bfs(){\n      dist.assign(N,\
    \ -1);\n      std::queue<int> q;\n\n      q.push(0);\n      dist[0] = 0;\n\n \
    \     while(not q.empty()){\n        int i = q.front(); q.pop();\n\n        for(auto\
    \ &e : graph[i]){\n          if(not e.used and dist[e.to] == -1){\n          \
    \  dist[e.to] = dist[i] + 1;\n            q.push(e.to);\n          }\n       \
    \ }\n      }\n\n      return dist[N - 1] != -1;\n    }\n\n    bool dfs(int cur){\n\
    \      if(cur == N - 1) return true;\n\n      for(auto &e : graph[cur]){\n   \
    \     if(not e.used and dist[cur] + 1 == dist[e.to]){\n          if(dfs(e.to)){\n\
    \            e.used = true;\n            if(e.rev >= 0) graph[e.to][e.rev].used\
    \ = false;\n            return true;\n          }\n        }\n      }\n\n    \
    \  return false;\n    }\n\n  public:\n    hopcroft_karp(int L, int R): L(L), R(R),\
    \ N(L + R + 2), graph(N), dist(N){\n      for(int i = 0; i < L; ++i){\n      \
    \  graph[0].push_back((edge){0, i + 1, -1, false});\n      }\n\n      for(int\
    \ i = 0; i < R; ++i){\n        graph[i + L + 1].push_back((edge){i + L + 1, N\
    \ - 1, -1, false});\n      }\n    }\n\n    void add_edge(int i, int j){\n    \
    \  assert(0 <= i and i < L);\n      assert(0 <= j and j < R);\n\n      const int\
    \ x = i + 1;\n      const int y = j + L + 1;\n\n      graph[x].push_back((edge){x,\
    \ y, (int)graph[y].size(), false});\n      graph[y].push_back((edge){y, x, (int)graph[x].size()\
    \ - 1, true});\n    }\n\n    int solve(){\n      int ret = 0;\n\n      while(bfs()){\n\
    \        int flow = 0;\n        for(int i = 0; i < L; ++i){\n          auto &e\
    \ = graph[0][i];\n          if(not e.used and dfs(e.to)){\n            e.used\
    \ = true;\n            ++flow;\n          }\n        }\n        if(flow == 0)\
    \ break;\n        ret += flow;\n      }\n\n      return ret;\n    }\n\n    auto\
    \ get_matching(){\n      std::vector<std::pair<int, int>> ret;\n      for(int\
    \ i = 0; i < L; ++i){\n        for(auto &e : graph[i + 1]){\n          if(e.used)\
    \ ret.emplace_back(i, e.to - L - 1);\n        }\n      }\n      return ret;\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <utility>\n#include\
    \ <cassert>\n\nnamespace haar_lib {\n  class hopcroft_karp {\n    struct edge\
    \ {\n      int from, to;\n      int rev;\n      bool used;\n    };\n\n    int\
    \ L, R, N;\n    std::vector<std::vector<edge>> graph;\n    std::vector<int> dist;\n\
    \n    bool bfs(){\n      dist.assign(N, -1);\n      std::queue<int> q;\n\n   \
    \   q.push(0);\n      dist[0] = 0;\n\n      while(not q.empty()){\n        int\
    \ i = q.front(); q.pop();\n\n        for(auto &e : graph[i]){\n          if(not\
    \ e.used and dist[e.to] == -1){\n            dist[e.to] = dist[i] + 1;\n     \
    \       q.push(e.to);\n          }\n        }\n      }\n\n      return dist[N\
    \ - 1] != -1;\n    }\n\n    bool dfs(int cur){\n      if(cur == N - 1) return\
    \ true;\n\n      for(auto &e : graph[cur]){\n        if(not e.used and dist[cur]\
    \ + 1 == dist[e.to]){\n          if(dfs(e.to)){\n            e.used = true;\n\
    \            if(e.rev >= 0) graph[e.to][e.rev].used = false;\n            return\
    \ true;\n          }\n        }\n      }\n\n      return false;\n    }\n\n  public:\n\
    \    hopcroft_karp(int L, int R): L(L), R(R), N(L + R + 2), graph(N), dist(N){\n\
    \      for(int i = 0; i < L; ++i){\n        graph[0].push_back((edge){0, i + 1,\
    \ -1, false});\n      }\n\n      for(int i = 0; i < R; ++i){\n        graph[i\
    \ + L + 1].push_back((edge){i + L + 1, N - 1, -1, false});\n      }\n    }\n\n\
    \    void add_edge(int i, int j){\n      assert(0 <= i and i < L);\n      assert(0\
    \ <= j and j < R);\n\n      const int x = i + 1;\n      const int y = j + L +\
    \ 1;\n\n      graph[x].push_back((edge){x, y, (int)graph[y].size(), false});\n\
    \      graph[y].push_back((edge){y, x, (int)graph[x].size() - 1, true});\n   \
    \ }\n\n    int solve(){\n      int ret = 0;\n\n      while(bfs()){\n        int\
    \ flow = 0;\n        for(int i = 0; i < L; ++i){\n          auto &e = graph[0][i];\n\
    \          if(not e.used and dfs(e.to)){\n            e.used = true;\n       \
    \     ++flow;\n          }\n        }\n        if(flow == 0) break;\n        ret\
    \ += flow;\n      }\n\n      return ret;\n    }\n\n    auto get_matching(){\n\
    \      std::vector<std::pair<int, int>> ret;\n      for(int i = 0; i < L; ++i){\n\
    \        for(auto &e : graph[i + 1]){\n          if(e.used) ret.emplace_back(i,\
    \ e.to - L - 1);\n        }\n      }\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/Matching/hopcroft_karp.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_7_A/main.hopcroft_karp.test.cpp
  - test/yosupo-judge/bipartitematching/main.test.cpp
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
