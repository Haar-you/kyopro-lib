---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \   return ret;\n    }\n  };\n}\n#line 3 \"Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp\"\
    \n\nnamespace haar_lib {\n  class bipartite_graph {\n    int n;\n    unionfind\
    \ check;\n\n  public:\n    bipartite_graph(int n): n(n), check(2 * n){}\n\n  \
    \  void add_diff(int i, int j){ // i\u3068j\u3092\u7570\u306A\u308B\u8272\u3067\
    \u5857\u308B\u3002\n      check.merge(i, j + n);\n      check.merge(i + n, j);\n\
    \    }\n\n    void add_same(int i, int j){ // i\u3068j\u3092\u540C\u3058\u8272\
    \u3067\u5857\u308B\u3002 = i\u3068j\u3092\u540C\u3058\u9802\u70B9\u3068\u898B\u505A\
    \u3059\u3002\n      check.merge(i, j);\n      check.merge(i + n, j + n);\n   \
    \ }\n\n    bool is_bipartite_graph(int i){ // i\u3092\u542B\u3080\u9023\u7D50\u30B0\
    \u30E9\u30D5\u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\u3002\n      return not check.is_same(i, i + n);\n    }\n\n    bool is_same(int\
    \ i, int j){ // i\u3068j\u304C\u540C\u3058\u8272\u3067\u5857\u3089\u308C\u3066\
    \u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\u3002\n      return check.is_same(i,\
    \ j);\n    }\n  };\n}\n"
  code: "#pragma once\n#include \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n\n\
    namespace haar_lib {\n  class bipartite_graph {\n    int n;\n    unionfind check;\n\
    \n  public:\n    bipartite_graph(int n): n(n), check(2 * n){}\n\n    void add_diff(int\
    \ i, int j){ // i\u3068j\u3092\u7570\u306A\u308B\u8272\u3067\u5857\u308B\u3002\
    \n      check.merge(i, j + n);\n      check.merge(i + n, j);\n    }\n\n    void\
    \ add_same(int i, int j){ // i\u3068j\u3092\u540C\u3058\u8272\u3067\u5857\u308B\
    \u3002 = i\u3068j\u3092\u540C\u3058\u9802\u70B9\u3068\u898B\u505A\u3059\u3002\n\
    \      check.merge(i, j);\n      check.merge(i + n, j + n);\n    }\n\n    bool\
    \ is_bipartite_graph(int i){ // i\u3092\u542B\u3080\u9023\u7D50\u30B0\u30E9\u30D5\
    \u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\
    \n      return not check.is_same(i, i + n);\n    }\n\n    bool is_same(int i,\
    \ int j){ // i\u3068j\u304C\u540C\u3058\u8272\u3067\u5857\u3089\u308C\u3066\u3044\
    \u308B\u304B\u5224\u5B9A\u3059\u308B\u3002\n      return check.is_same(i, j);\n\
    \    }\n  };\n}\n"
  dependsOn:
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  isVerificationFile: false
  path: Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp
layout: document
title: Check bipartite graph (Using union-find)
---

## Operations

## Requirements

## Notes

## Problems

- [CODE FESTIVAL 2017 qual B C - 3 Steps](https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c)
- [ARC 036 D - 偶数メートル](https://atcoder.jp/contests/arc036/tasks/arc036_d)

## References

