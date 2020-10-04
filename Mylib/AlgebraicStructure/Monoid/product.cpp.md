---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3132/main.test.cpp
    title: test/aoj/3132/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/product.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct product_monoid {\n    using value_type\
    \ = T;\n    value_type operator()() const {return 1;}\n    value_type operator()(value_type\
    \ a, value_type b) const {return a * b;}\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  struct product_monoid\
    \ {\n    using value_type = T;\n    value_type operator()() const {return 1;}\n\
    \    value_type operator()(value_type a, value_type b) const {return a * b;}\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/product.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/3132/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/product.cpp
layout: document
title: Product monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
