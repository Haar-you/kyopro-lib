---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/510/main.test.cpp
    title: test/yukicoder/510/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/product_matrix.cpp\"\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct product_matrix_monoid\
    \ {\n    using value_type = T;\n    value_type operator()() const { return T::unit();\
    \ }\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ { return a * b; }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct product_matrix_monoid\
    \ {\n    using value_type = T;\n    value_type operator()() const { return T::unit();\
    \ }\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ { return a * b; }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/product_matrix.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/510/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/product_matrix.cpp
layout: document
title: Product matrix monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
