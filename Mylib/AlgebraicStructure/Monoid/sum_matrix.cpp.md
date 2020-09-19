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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/sum_matrix.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct sum_matrix_monoid {\n    using\
    \ value_type = T;\n    value_type operator()() const {return T();}\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {return a + b;}\n\
    \  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_matrix_monoid\
    \ {\n    using value_type = T;\n    value_type operator()() const {return T();}\n\
    \    value_type operator()(const value_type &a, const value_type &b) const {return\
    \ a + b;}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/sum_matrix.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/sum_matrix.cpp
layout: document
title: Sum matrix monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
