---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842/main.fenwick_tree.test.cpp
    title: test/aoj/2842/main.fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
    title: test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Group/sum.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct sum_group {\n    using value_type = T;\n\
    \n    value_type operator()() const {return 0;}\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {return a + b;}\n    value_type inv(const\
    \ value_type &a) const {return -a;}\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_group\
    \ {\n    using value_type = T;\n\n    value_type operator()() const {return 0;}\n\
    \    value_type operator()(const value_type &a, const value_type &b) const {return\
    \ a + b;}\n    value_type inv(const value_type &a) const {return -a;}\n  };\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Group/sum.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
  - test/aoj/2842/main.fenwick_tree.test.cpp
  - test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
documentation_of: Mylib/AlgebraicStructure/Group/sum.cpp
layout: document
title: Sum group
---

## Operations

## Requirements

## Notes

## Problems

## References
