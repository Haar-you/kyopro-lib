---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp
    title: Check bipartite graph (Using union-find)
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/boruvka.cpp
    title: "Bor\u016Fvka algorithm"
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/kruskal.cpp
    title: Kruskal algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0575/main.test.cpp
    title: test/aoj/0575/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1337/main.test.cpp
    title: test/aoj/1337/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2955/main.test.cpp
    title: test/aoj/2955/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A/main.boruvka.test.cpp
    title: test/aoj/GRL_2_A/main.boruvka.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A/main.kruskal.test.cpp
    title: test/aoj/GRL_2_A/main.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/manhattanmst/main.test.cpp
    title: test/yosupo-judge/manhattanmst/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/unionfind/main.test.cpp
    title: test/yosupo-judge/unionfind/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n#include\
    \ <vector>\n#include <numeric>\n#include <algorithm>\n\nnamespace haar_lib {\n\
    \  class unionfind {\n    int n_, count_;\n    mutable std::vector<int> parent_;\n\
    \    std::vector<int> depth_, size_;\n\n  public:\n    unionfind(){}\n    unionfind(int\
    \ n): n_(n), count_(n), parent_(n), depth_(n, 1), size_(n, 1){\n      std::iota(parent_.begin(),\
    \ parent_.end(), 0);\n    }\n\n    int root_of(int i) const {\n      if(parent_[i]\
    \ == i) return i;\n      else return parent_[i] = root_of(parent_[i]);\n    }\n\
    \n    bool is_same(int i, int j) const {return root_of(i) == root_of(j);}\n\n\
    \    int merge(int i, int j){\n      const int ri = root_of(i), rj = root_of(j);\n\
    \      if(ri == rj) return ri;\n      else{\n        --count_;\n        if(depth_[ri]\
    \ < depth_[rj]){\n          parent_[ri] = rj;\n          size_[rj] += size_[ri];\n\
    \          return rj;\n        }else{\n          parent_[rj] = ri;\n         \
    \ size_[ri] += size_[rj];\n          if(depth_[ri] == depth_[rj]) ++depth_[ri];\n\
    \          return ri;\n        }\n      }\n    }\n\n    int size_of(int i) const\
    \ {return size_[root_of(i)];}\n\n    int count_groups() const {return count_;}\n\
    \n    auto get_groups() const {\n      std::vector<std::vector<int>> ret(n_);\n\
    \n      for(int i = 0; i < n_; ++i){\n        ret[root_of(i)].push_back(i);\n\
    \      }\n\n      ret.erase(\n        std::remove_if(\n          ret.begin(),\
    \ ret.end(),\n          [](const auto &a){return a.empty();}\n        ),\n   \
    \     ret.end()\n      );\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <numeric>\n#include <algorithm>\n\
    \nnamespace haar_lib {\n  class unionfind {\n    int n_, count_;\n    mutable\
    \ std::vector<int> parent_;\n    std::vector<int> depth_, size_;\n\n  public:\n\
    \    unionfind(){}\n    unionfind(int n): n_(n), count_(n), parent_(n), depth_(n,\
    \ 1), size_(n, 1){\n      std::iota(parent_.begin(), parent_.end(), 0);\n    }\n\
    \n    int root_of(int i) const {\n      if(parent_[i] == i) return i;\n      else\
    \ return parent_[i] = root_of(parent_[i]);\n    }\n\n    bool is_same(int i, int\
    \ j) const {return root_of(i) == root_of(j);}\n\n    int merge(int i, int j){\n\
    \      const int ri = root_of(i), rj = root_of(j);\n      if(ri == rj) return\
    \ ri;\n      else{\n        --count_;\n        if(depth_[ri] < depth_[rj]){\n\
    \          parent_[ri] = rj;\n          size_[rj] += size_[ri];\n          return\
    \ rj;\n        }else{\n          parent_[rj] = ri;\n          size_[ri] += size_[rj];\n\
    \          if(depth_[ri] == depth_[rj]) ++depth_[ri];\n          return ri;\n\
    \        }\n      }\n    }\n\n    int size_of(int i) const {return size_[root_of(i)];}\n\
    \n    int count_groups() const {return count_;}\n\n    auto get_groups() const\
    \ {\n      std::vector<std::vector<int>> ret(n_);\n\n      for(int i = 0; i <\
    \ n_; ++i){\n        ret[root_of(i)].push_back(i);\n      }\n\n      ret.erase(\n\
    \        std::remove_if(\n          ret.begin(), ret.end(),\n          [](const\
    \ auto &a){return a.empty();}\n        ),\n        ret.end()\n      );\n\n   \
    \   return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/UnionFind/unionfind.cpp
  requiredBy:
  - Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp
  - Mylib/Graph/MinimumSpanningTree/kruskal.cpp
  - Mylib/Graph/MinimumSpanningTree/boruvka.cpp
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/0575/main.test.cpp
  - test/aoj/GRL_2_A/main.kruskal.test.cpp
  - test/aoj/GRL_2_A/main.boruvka.test.cpp
  - test/aoj/1337/main.test.cpp
  - test/aoj/2955/main.test.cpp
  - test/yosupo-judge/unionfind/main.test.cpp
  - test/yosupo-judge/manhattanmst/main.test.cpp
documentation_of: Mylib/DataStructure/UnionFind/unionfind.cpp
layout: document
title: Union-find
---

## Operations

- `UnionFind(n)`
- `root_of(int i)`
	- `i`のrootを得る。
- `is_same(int i, int j)`
	- `i`と`j`が同じ連結成分かどうかを判定する。
- `merge(int i, int j)`
	- `i`と`j`を同じ連結成分にし、その連結成分のrootを返す。
- `size_of(int i)`
	- `i`の属する連結成分の大きさ。
- `count_group()`
	- 連結成分の個数を返す。

## Requirements

## Notes

## Problems

## References
