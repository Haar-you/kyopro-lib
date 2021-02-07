---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/UnionFind/partially_persistent_unionfind.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <algorithm>\n#include <iterator>\n\
    #include <numeric>\n\nnamespace haar_lib {\n  class partially_persistent_unionfind\
    \ {\n    int N_, T_ = 0;\n    std::vector<std::vector<std::pair<int, int>>> P_;\n\
    \    std::vector<int> par_, rank_;\n\n  public:\n    partially_persistent_unionfind(){}\n\
    \    partially_persistent_unionfind(int N): N_(N), P_(N), par_(N), rank_(N, 1){\n\
    \      for(int i = 0; i < N_; ++i) P_[i].emplace_back(0, 1);\n      std::iota(par_.begin(),\
    \ par_.end(), 0);\n    }\n\n    int root_of(int i, int t){\n      if(par_[i] ==\
    \ i) return i;\n\n      if(P_[i].back().first == 0 or t < P_[i].back().first)\
    \ return i;\n      else if(t == P_[i].back().first) return P_[i].back().second;\n\
    \      return root_of(par_[i], t);\n    }\n\n    bool is_same(int u, int v, int\
    \ t){\n      return root_of(u, t) == root_of(v, t);\n    }\n\n    int size_of(int\
    \ u, int t){\n      u = root_of(u, t);\n      auto it = std::prev(std::lower_bound(P_[u].begin(),\
    \ P_[u].end(), std::make_pair(t + 1, 0)));\n      return it->second;\n    }\n\n\
    \    void merge(int u, int v){\n      u = root_of(u, T_);\n      v = root_of(v,\
    \ T_);\n      ++T_;\n\n      if(u == v) return;\n\n      const int s = size_of(u,\
    \ T_ - 1) + size_of(v, T_ - 1);\n\n      if(rank_[u] < rank_[v]){\n        par_[u]\
    \ = par_[v] = v;\n        P_[u].emplace_back(T_, v);\n        P_[v].emplace_back(T_,\
    \ s);\n      }else{\n        par_[u] = par_[v] = u;\n        P_[v].emplace_back(T_,\
    \ u);\n        P_[u].emplace_back(T_, s);\n        if(rank_[u] == rank_[v]) ++rank_[u];\n\
    \      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <iterator>\n#include <numeric>\n\nnamespace haar_lib {\n  class partially_persistent_unionfind\
    \ {\n    int N_, T_ = 0;\n    std::vector<std::vector<std::pair<int, int>>> P_;\n\
    \    std::vector<int> par_, rank_;\n\n  public:\n    partially_persistent_unionfind(){}\n\
    \    partially_persistent_unionfind(int N): N_(N), P_(N), par_(N), rank_(N, 1){\n\
    \      for(int i = 0; i < N_; ++i) P_[i].emplace_back(0, 1);\n      std::iota(par_.begin(),\
    \ par_.end(), 0);\n    }\n\n    int root_of(int i, int t){\n      if(par_[i] ==\
    \ i) return i;\n\n      if(P_[i].back().first == 0 or t < P_[i].back().first)\
    \ return i;\n      else if(t == P_[i].back().first) return P_[i].back().second;\n\
    \      return root_of(par_[i], t);\n    }\n\n    bool is_same(int u, int v, int\
    \ t){\n      return root_of(u, t) == root_of(v, t);\n    }\n\n    int size_of(int\
    \ u, int t){\n      u = root_of(u, t);\n      auto it = std::prev(std::lower_bound(P_[u].begin(),\
    \ P_[u].end(), std::make_pair(t + 1, 0)));\n      return it->second;\n    }\n\n\
    \    void merge(int u, int v){\n      u = root_of(u, T_);\n      v = root_of(v,\
    \ T_);\n      ++T_;\n\n      if(u == v) return;\n\n      const int s = size_of(u,\
    \ T_ - 1) + size_of(v, T_ - 1);\n\n      if(rank_[u] < rank_[v]){\n        par_[u]\
    \ = par_[v] = v;\n        P_[u].emplace_back(T_, v);\n        P_[v].emplace_back(T_,\
    \ s);\n      }else{\n        par_[u] = par_[v] = u;\n        P_[v].emplace_back(T_,\
    \ u);\n        P_[u].emplace_back(T_, s);\n        if(rank_[u] == rank_[v]) ++rank_[u];\n\
    \      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/UnionFind/partially_persistent_unionfind.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
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
