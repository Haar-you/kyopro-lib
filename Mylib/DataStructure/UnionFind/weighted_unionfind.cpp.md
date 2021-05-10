---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_1_B/main.test.cpp
    title: test/aoj/DSL_1_B/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/UnionFind/weighted_unionfind.cpp\"\n\
    #include <numeric>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class weighted_unionfind {\n  public:\n    using value_type = T;\n\n \
    \ private:\n    std::vector<int> parent_, depth_, size_;\n    std::vector<T> weight_;\n\
    \    int count_;\n\n  public:\n    weighted_unionfind() {}\n    weighted_unionfind(int\
    \ n) : parent_(n), depth_(n, 1), size_(n, 1), weight_(n, 0) {\n      std::iota(parent_.begin(),\
    \ parent_.end(), 0);\n    }\n\n    int root_of(int i) {\n      if (parent_[i]\
    \ == i)\n        return i;\n      else {\n        const int p = root_of(parent_[i]);\n\
    \        weight_[i] += weight_[parent_[i]];\n        return parent_[i] = p;\n\
    \      }\n    }\n\n    T weight_of(int i) {\n      root_of(i);\n      return weight_[i];\n\
    \    }\n    bool is_same(int i, int j) { return root_of(i) == root_of(j); }\n\
    \    T diff(int i, int j) { return weight_of(i) - weight_of(j); }\n\n    int merge(int\
    \ i, int j, T w) {\n      const int ri = root_of(i), rj = root_of(j);\n      if\
    \ (ri == rj)\n        return ri;\n      else {\n        if (depth_[ri] < depth_[rj])\
    \ {\n          parent_[ri] = rj;\n          size_[rj] += size_[ri];\n        \
    \  weight_[ri] = w - weight_[i] + weight_[j];\n          return rj;\n        }\
    \ else {\n          parent_[rj] = ri;\n          size_[ri] += size_[rj];\n   \
    \       weight_[rj] = -w + weight_[i] - weight_[j];\n          if (depth_[ri]\
    \ == depth_[rj]) ++depth_[ri];\n          return ri;\n        }\n      }\n   \
    \ }\n\n    int size_of(int i) { return size_[root_of(i)]; }\n    int count_groups()\
    \ { return count_; }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class weighted_unionfind {\n  public:\n    using\
    \ value_type = T;\n\n  private:\n    std::vector<int> parent_, depth_, size_;\n\
    \    std::vector<T> weight_;\n    int count_;\n\n  public:\n    weighted_unionfind()\
    \ {}\n    weighted_unionfind(int n) : parent_(n), depth_(n, 1), size_(n, 1), weight_(n,\
    \ 0) {\n      std::iota(parent_.begin(), parent_.end(), 0);\n    }\n\n    int\
    \ root_of(int i) {\n      if (parent_[i] == i)\n        return i;\n      else\
    \ {\n        const int p = root_of(parent_[i]);\n        weight_[i] += weight_[parent_[i]];\n\
    \        return parent_[i] = p;\n      }\n    }\n\n    T weight_of(int i) {\n\
    \      root_of(i);\n      return weight_[i];\n    }\n    bool is_same(int i, int\
    \ j) { return root_of(i) == root_of(j); }\n    T diff(int i, int j) { return weight_of(i)\
    \ - weight_of(j); }\n\n    int merge(int i, int j, T w) {\n      const int ri\
    \ = root_of(i), rj = root_of(j);\n      if (ri == rj)\n        return ri;\n  \
    \    else {\n        if (depth_[ri] < depth_[rj]) {\n          parent_[ri] = rj;\n\
    \          size_[rj] += size_[ri];\n          weight_[ri] = w - weight_[i] + weight_[j];\n\
    \          return rj;\n        } else {\n          parent_[rj] = ri;\n       \
    \   size_[ri] += size_[rj];\n          weight_[rj] = -w + weight_[i] - weight_[j];\n\
    \          if (depth_[ri] == depth_[rj]) ++depth_[ri];\n          return ri;\n\
    \        }\n      }\n    }\n\n    int size_of(int i) { return size_[root_of(i)];\
    \ }\n    int count_groups() { return count_; }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/UnionFind/weighted_unionfind.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
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