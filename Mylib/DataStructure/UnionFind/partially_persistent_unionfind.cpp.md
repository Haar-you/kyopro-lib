---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/UnionFind/partially_persistent_unionfind.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <algorithm>\n#include <iterator>\n\
    #include <numeric>\n\nnamespace haar_lib {\n  class partially_persistent_unionfind\
    \ {\n    int N;\n    std::vector<std::vector<std::pair<int, int>>> P;\n    std::vector<int>\
    \ par;\n    int T = 0;\n    std::vector<int> rank;\n\n  public:\n    partially_persistent_unionfind(int\
    \ N): N(N), P(N), par(N), rank(N, 1){\n      for(int i = 0; i < N; ++i) P[i].emplace_back(0,\
    \ 1);\n      std::iota(par.begin(), par.end(), 0);\n    }\n\n    int root_of(int\
    \ i, int t){\n      if(par[i] == i) return i;\n\n      if(P[i].back().first ==\
    \ 0 || t < P[i].back().first) return i;\n      else if(t == P[i].back().first)\
    \ return P[i].back().second;\n      return root_of(par[i], t);\n    }\n\n    bool\
    \ is_same(int u, int v, int t){\n      return root_of(u, t) == root_of(v, t);\n\
    \    }\n\n    int size_of(int u, int t){\n      u = root_of(u, t);\n      auto\
    \ it = std::prev(std::lower_bound(P[u].begin(), P[u].end(), std::make_pair(t +\
    \ 1, 0)));\n      return it->second;\n    }\n\n    void merge(int u, int v){\n\
    \      u = root_of(u, T);\n      v = root_of(v, T);\n      ++T;\n\n      if(u\
    \ == v) return;\n\n      const int s = size_of(u, T - 1) + size_of(v, T - 1);\n\
    \n      if(rank[u] < rank[v]){\n        par[u] = par[v] = v;\n        P[u].emplace_back(T,\
    \ v);\n        P[v].emplace_back(T, s);\n      }else{\n        par[u] = par[v]\
    \ = u;\n        P[v].emplace_back(T, u);\n        P[u].emplace_back(T, s);\n \
    \       if(rank[u] == rank[v]) ++rank[u];\n      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <iterator>\n#include <numeric>\n\nnamespace haar_lib {\n  class partially_persistent_unionfind\
    \ {\n    int N;\n    std::vector<std::vector<std::pair<int, int>>> P;\n    std::vector<int>\
    \ par;\n    int T = 0;\n    std::vector<int> rank;\n\n  public:\n    partially_persistent_unionfind(int\
    \ N): N(N), P(N), par(N), rank(N, 1){\n      for(int i = 0; i < N; ++i) P[i].emplace_back(0,\
    \ 1);\n      std::iota(par.begin(), par.end(), 0);\n    }\n\n    int root_of(int\
    \ i, int t){\n      if(par[i] == i) return i;\n\n      if(P[i].back().first ==\
    \ 0 || t < P[i].back().first) return i;\n      else if(t == P[i].back().first)\
    \ return P[i].back().second;\n      return root_of(par[i], t);\n    }\n\n    bool\
    \ is_same(int u, int v, int t){\n      return root_of(u, t) == root_of(v, t);\n\
    \    }\n\n    int size_of(int u, int t){\n      u = root_of(u, t);\n      auto\
    \ it = std::prev(std::lower_bound(P[u].begin(), P[u].end(), std::make_pair(t +\
    \ 1, 0)));\n      return it->second;\n    }\n\n    void merge(int u, int v){\n\
    \      u = root_of(u, T);\n      v = root_of(v, T);\n      ++T;\n\n      if(u\
    \ == v) return;\n\n      const int s = size_of(u, T - 1) + size_of(v, T - 1);\n\
    \n      if(rank[u] < rank[v]){\n        par[u] = par[v] = v;\n        P[u].emplace_back(T,\
    \ v);\n        P[v].emplace_back(T, s);\n      }else{\n        par[u] = par[v]\
    \ = u;\n        P[v].emplace_back(T, u);\n        P[u].emplace_back(T, s);\n \
    \       if(rank[u] == rank[v]) ++rank[u];\n      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/UnionFind/partially_persistent_unionfind.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/UnionFind/partially_persistent_unionfind.cpp
layout: document
title: Partially persistent union-find
---

## Operations

- `PartiallyPersistentUnionFind(N)`
- `root_of(int i, int t)`
	- 時刻`t`での`i`の属する連結成分のrootを返す。
- `is_same(int u, int v, int t)`
	- 時刻`t`での`u`と`v`が同じ連結成分に属するかを判定する。
- `size_of(int u, int t)`
	- 時刻`t`での`u`が属する連結成分の大きさを返す。
- `merge(int u, int v)`
	- 最新の状態で`u`と`v`を連結する。

## Requirements

## Notes

## Problems

- [CODE THANKS FESTIVAL 2017 H - Union Sets](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h)
- [AGC 002 D - Stamp Rally](https://atcoder.jp/contests/agc002/tasks/agc002_d)

## References

- [https://camypaper.bitbucket.io/2016/12/18/adc2016/](https://camypaper.bitbucket.io/2016/12/18/adc2016/)
