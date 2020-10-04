---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Semiring/add_mul.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct add_mul_semiring {\n    using\
    \ value_type = T;\n    value_type id_add() const {return 0;}\n    value_type id_mul()\
    \ const {return 1;}\n    value_type add(value_type a, value_type b) const {return\
    \ a + b;}\n    value_type mul(value_type a, value_type b) const {return a * b;}\n\
    \  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct add_mul_semiring\
    \ {\n    using value_type = T;\n    value_type id_add() const {return 0;}\n  \
    \  value_type id_mul() const {return 1;}\n    value_type add(value_type a, value_type\
    \ b) const {return a + b;}\n    value_type mul(value_type a, value_type b) const\
    \ {return a * b;}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Semiring/add_mul.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Semiring/add_mul.cpp
layout: document
title: Add-mul semiring
---

## Operations

## Requirements

## Notes

## Problems

## References
