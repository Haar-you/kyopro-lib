---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/trivial.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct trivial_monoid {\n    using value_type\
    \ = T;\n    value_type operator()() const {return T();}\n    value_type operator()(const\
    \ value_type &, const value_type &) const {return T();}\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct trivial_monoid\
    \ {\n    using value_type = T;\n    value_type operator()() const {return T();}\n\
    \    value_type operator()(const value_type &, const value_type &) const {return\
    \ T();}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/trivial.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/trivial.cpp
layout: document
title: Trivial monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
