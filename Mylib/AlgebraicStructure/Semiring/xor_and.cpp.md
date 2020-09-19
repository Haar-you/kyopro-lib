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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Semiring/xor_and.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct xor_and_semiring {\n    using\
    \ value_type = T;\n    value_type id_add() const {return 0;}\n    value_type id_mul()\
    \ const {return ~(T)0;}\n    value_type add(value_type a, value_type b) const\
    \ {return a ^ b;}\n    value_type mul(value_type a, value_type b) const {return\
    \ a & b;}\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct xor_and_semiring\
    \ {\n    using value_type = T;\n    value_type id_add() const {return 0;}\n  \
    \  value_type id_mul() const {return ~(T)0;}\n    value_type add(value_type a,\
    \ value_type b) const {return a ^ b;}\n    value_type mul(value_type a, value_type\
    \ b) const {return a & b;}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Semiring/xor_and.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Semiring/xor_and.cpp
layout: document
title: Xor-and semiring
---

## Operations

## Requirements

## Notes

## Problems

## References
