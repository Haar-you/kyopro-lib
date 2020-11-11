---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename UF>\n  class bipartite_graph :\
    \ public UF {\n    int n_;\n\n    using super = UF;\n\n  public:\n    bipartite_graph(){}\n\
    \    bipartite_graph(int n): super(2 * n), n_(n){}\n\n    void add_diff(int i,\
    \ int j){ // i\u3068j\u3092\u7570\u306A\u308B\u8272\u3067\u5857\u308B\u3002\n\
    \      super::merge(i, j + n_);\n      super::merge(i + n_, j);\n    }\n\n   \
    \ void add_same(int i, int j){ // i\u3068j\u3092\u540C\u3058\u8272\u3067\u5857\
    \u308B\u3002 = i\u3068j\u3092\u540C\u3058\u9802\u70B9\u3068\u898B\u505A\u3059\u3002\
    \n      super::merge(i, j);\n      super::merge(i + n_, j + n_);\n    }\n\n  \
    \  bool is_bipartite_graph(int i){ // i\u3092\u542B\u3080\u9023\u7D50\u30B0\u30E9\
    \u30D5\u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \u3002\n      return not super::is_same(i, i + n_);\n    }\n\n    bool is_same(int\
    \ i, int j){ // i\u3068j\u304C\u540C\u3058\u8272\u3067\u5857\u3089\u308C\u3066\
    \u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\u3002\n      return super::is_same(i,\
    \ j);\n    }\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename UF>\n  class bipartite_graph\
    \ : public UF {\n    int n_;\n\n    using super = UF;\n\n  public:\n    bipartite_graph(){}\n\
    \    bipartite_graph(int n): super(2 * n), n_(n){}\n\n    void add_diff(int i,\
    \ int j){ // i\u3068j\u3092\u7570\u306A\u308B\u8272\u3067\u5857\u308B\u3002\n\
    \      super::merge(i, j + n_);\n      super::merge(i + n_, j);\n    }\n\n   \
    \ void add_same(int i, int j){ // i\u3068j\u3092\u540C\u3058\u8272\u3067\u5857\
    \u308B\u3002 = i\u3068j\u3092\u540C\u3058\u9802\u70B9\u3068\u898B\u505A\u3059\u3002\
    \n      super::merge(i, j);\n      super::merge(i + n_, j + n_);\n    }\n\n  \
    \  bool is_bipartite_graph(int i){ // i\u3092\u542B\u3080\u9023\u7D50\u30B0\u30E9\
    \u30D5\u304C\u4E8C\u90E8\u30B0\u30E9\u30D5\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \u3002\n      return not super::is_same(i, i + n_);\n    }\n\n    bool is_same(int\
    \ i, int j){ // i\u3068j\u304C\u540C\u3058\u8272\u3067\u5857\u3089\u308C\u3066\
    \u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\u3002\n      return super::is_same(i,\
    \ j);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Graph/BipartiteGraph/construct_bipartite_graph.cpp
  requiredBy: []
  timestamp: '2020-11-06 05:05:43+09:00'
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

