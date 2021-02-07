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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/ordering.cpp\"\n\nnamespace\
    \ haar_lib {\n  struct ordering_monoid {\n    using value_type = int;\n    value_type\
    \ operator()() const {return 0;}\n    value_type operator()(const value_type &a,\
    \ const value_type &b) const {return a ? a : b;}\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  struct ordering_monoid {\n    using\
    \ value_type = int;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {return a ? a : b;}\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/ordering.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/ordering.cpp
layout: document
title: Ordering monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
