---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_1_B/main.test.cpp
    title: test/aoj/DSL_1_B/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/UnionFind/weighted_unionfind.cpp\"\n\
    #include <vector>\n#include <numeric>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class weighted_unionfind {\n    std::vector<int> parent, depth, size;\n\
    \    std::vector<T> weight;\n    int count;\n\n  public:\n    weighted_unionfind(int\
    \ n): parent(n), depth(n, 1), size(n, 1), weight(n, 0){\n      std::iota(parent.begin(),\
    \ parent.end(), 0);\n    }\n\n    int root_of(int i){\n      if(parent[i] == i)\
    \ return i;\n      else {\n        const int p = root_of(parent[i]);\n       \
    \ weight[i] += weight[parent[i]];\n        return parent[i] = p;\n      }\n  \
    \  }\n\n    T weight_of(int i){root_of(i); return weight[i];}\n    bool is_same(int\
    \ i, int j){return root_of(i) == root_of(j);}\n    T diff(int i, int j){return\
    \ weight_of(i) - weight_of(j);}\n\n    int merge(int i, int j, T w){\n      const\
    \ int ri = root_of(i), rj = root_of(j);\n      if(ri == rj) return ri;\n     \
    \ else{\n        if(depth[ri] < depth[rj]){\n          parent[ri] = rj; size[rj]\
    \ += size[ri]; weight[ri] = w - weight[i] + weight[j];\n          return rj;\n\
    \        }else{\n          parent[rj] = ri; size[ri] += size[rj]; weight[rj] =\
    \ -w + weight[i] - weight[j];\n          if(depth[ri] == depth[rj]) ++depth[ri];\n\
    \          return ri;\n        }\n      }\n    }\n\n    int size_of(int i){return\
    \ size[root_of(i)];}\n    int count_groups(){return count;}\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <numeric>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class weighted_unionfind {\n    std::vector<int>\
    \ parent, depth, size;\n    std::vector<T> weight;\n    int count;\n\n  public:\n\
    \    weighted_unionfind(int n): parent(n), depth(n, 1), size(n, 1), weight(n,\
    \ 0){\n      std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    int root_of(int\
    \ i){\n      if(parent[i] == i) return i;\n      else {\n        const int p =\
    \ root_of(parent[i]);\n        weight[i] += weight[parent[i]];\n        return\
    \ parent[i] = p;\n      }\n    }\n\n    T weight_of(int i){root_of(i); return\
    \ weight[i];}\n    bool is_same(int i, int j){return root_of(i) == root_of(j);}\n\
    \    T diff(int i, int j){return weight_of(i) - weight_of(j);}\n\n    int merge(int\
    \ i, int j, T w){\n      const int ri = root_of(i), rj = root_of(j);\n      if(ri\
    \ == rj) return ri;\n      else{\n        if(depth[ri] < depth[rj]){\n       \
    \   parent[ri] = rj; size[rj] += size[ri]; weight[ri] = w - weight[i] + weight[j];\n\
    \          return rj;\n        }else{\n          parent[rj] = ri; size[ri] +=\
    \ size[rj]; weight[rj] = -w + weight[i] - weight[j];\n          if(depth[ri] ==\
    \ depth[rj]) ++depth[ri];\n          return ri;\n        }\n      }\n    }\n\n\
    \    int size_of(int i){return size[root_of(i)];}\n    int count_groups(){return\
    \ count;}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/UnionFind/weighted_unionfind.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_1_B/main.test.cpp
documentation_of: Mylib/DataStructure/UnionFind/weighted_unionfind.cpp
layout: document
title: Weighted union-find
---

## Operations

## Requirements

## Notes

## Problems

- [ABC 087 D - People on a Line](https://atcoder.jp/contests/abc087/tasks/arc090_b)
- [AOJ 1330 Never Wait for Weights](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330)
- [AOJ DSL_1_B Weighted Union Find Trees](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B)

## References
