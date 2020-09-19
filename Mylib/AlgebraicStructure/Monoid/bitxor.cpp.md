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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/bitxor.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct bitxor_monoid {\n    using value_type\
    \ = T;\n    value_type operator()() const {return 0;}\n    value_type operator()(value_type\
    \ a, value_type b) const {return a ^ b;}\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct bitxor_monoid\
    \ {\n    using value_type = T;\n    value_type operator()() const {return 0;}\n\
    \    value_type operator()(value_type a, value_type b) const {return a ^ b;}\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/bitxor.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/bitxor.cpp
layout: document
title: Bitxor monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
