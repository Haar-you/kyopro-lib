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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/sum_matrix.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct sum_matrix_monoid {\n    using\
    \ value_type = T;\n    value_type operator()() const { return T(); }\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const { return a + b; }\n\
    \  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_matrix_monoid\
    \ {\n    using value_type = T;\n    value_type operator()() const { return T();\
    \ }\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ { return a + b; }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/sum_matrix.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
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
