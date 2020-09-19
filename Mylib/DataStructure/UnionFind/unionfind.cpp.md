---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Graph/MinimumSpanningTree/kruskal.cpp
    title: Kruskal algorithm
  - icon: ':x:'
    path: Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
    title: Manhattan distance MST
  - icon: ':x:'
    path: Mylib/Graph/MinimumSpanningTree/boruvka.cpp
    title: "Bor\u016Fvka algorithm"
  - icon: ':warning:'
    path: Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp
    title: Check bipartite graph (Using union-find)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_2_A/main.kruskal.test.cpp
    title: test/aoj/GRL_2_A/main.kruskal.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_2_A/main.boruvka.test.cpp
    title: test/aoj/GRL_2_A/main.boruvka.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0575/main.test.cpp
    title: test/aoj/0575/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2955/main.test.cpp
    title: test/aoj/2955/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1337/main.test.cpp
    title: test/aoj/1337/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/unionfind/main.test.cpp
    title: test/yosupo-judge/unionfind/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/manhattanmst/main.test.cpp
    title: test/yosupo-judge/manhattanmst/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n#include\
    \ <vector>\n#include <numeric>\n#include <algorithm>\n\nnamespace haar_lib {\n\
    \  class unionfind {\n    int n;\n    mutable std::vector<int> parent;\n    std::vector<int>\
    \ depth, size;\n    int count;\n\n  public:\n    unionfind(){}\n    unionfind(int\
    \ n): n(n), parent(n), depth(n, 1), size(n, 1), count(n){\n      std::iota(parent.begin(),\
    \ parent.end(), 0);\n    }\n\n    int root_of(int i) const {\n      if(parent[i]\
    \ == i) return i;\n      else return parent[i] = root_of(parent[i]);\n    }\n\n\
    \    bool is_same(int i, int j) const {return root_of(i) == root_of(j);}\n\n \
    \   int merge(int i, int j){\n      const int ri = root_of(i), rj = root_of(j);\n\
    \      if(ri == rj) return ri;\n      else{\n        --count;\n        if(depth[ri]\
    \ < depth[rj]){\n          parent[ri] = rj;\n          size[rj] += size[ri];\n\
    \          return rj;\n        }else{\n          parent[rj] = ri;\n          size[ri]\
    \ += size[rj];\n          if(depth[ri] == depth[rj]) ++depth[ri];\n          return\
    \ ri;\n        }\n      }\n    }\n\n    int size_of(int i) const {return size[root_of(i)];}\n\
    \n    int count_groups() const {return count;}\n\n    auto get_groups() const\
    \ {\n      std::vector<std::vector<int>> ret(n);\n\n      for(int i = 0; i < n;\
    \ ++i){\n        ret[root_of(i)].push_back(i);\n      }\n\n      ret.erase(\n\
    \        std::remove_if(\n          ret.begin(), ret.end(),\n          [](const\
    \ auto &a){return a.empty();}\n        ),\n        ret.end()\n      );\n\n   \
    \   return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <numeric>\n#include <algorithm>\n\
    \nnamespace haar_lib {\n  class unionfind {\n    int n;\n    mutable std::vector<int>\
    \ parent;\n    std::vector<int> depth, size;\n    int count;\n\n  public:\n  \
    \  unionfind(){}\n    unionfind(int n): n(n), parent(n), depth(n, 1), size(n,\
    \ 1), count(n){\n      std::iota(parent.begin(), parent.end(), 0);\n    }\n\n\
    \    int root_of(int i) const {\n      if(parent[i] == i) return i;\n      else\
    \ return parent[i] = root_of(parent[i]);\n    }\n\n    bool is_same(int i, int\
    \ j) const {return root_of(i) == root_of(j);}\n\n    int merge(int i, int j){\n\
    \      const int ri = root_of(i), rj = root_of(j);\n      if(ri == rj) return\
    \ ri;\n      else{\n        --count;\n        if(depth[ri] < depth[rj]){\n   \
    \       parent[ri] = rj;\n          size[rj] += size[ri];\n          return rj;\n\
    \        }else{\n          parent[rj] = ri;\n          size[ri] += size[rj];\n\
    \          if(depth[ri] == depth[rj]) ++depth[ri];\n          return ri;\n   \
    \     }\n      }\n    }\n\n    int size_of(int i) const {return size[root_of(i)];}\n\
    \n    int count_groups() const {return count;}\n\n    auto get_groups() const\
    \ {\n      std::vector<std::vector<int>> ret(n);\n\n      for(int i = 0; i < n;\
    \ ++i){\n        ret[root_of(i)].push_back(i);\n      }\n\n      ret.erase(\n\
    \        std::remove_if(\n          ret.begin(), ret.end(),\n          [](const\
    \ auto &a){return a.empty();}\n        ),\n        ret.end()\n      );\n\n   \
    \   return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/UnionFind/unionfind.cpp
  requiredBy:
  - Mylib/Graph/MinimumSpanningTree/kruskal.cpp
  - Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
  - Mylib/Graph/MinimumSpanningTree/boruvka.cpp
  - Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_2_A/main.kruskal.test.cpp
  - test/aoj/GRL_2_A/main.boruvka.test.cpp
  - test/aoj/0575/main.test.cpp
  - test/aoj/2955/main.test.cpp
  - test/aoj/1337/main.test.cpp
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
