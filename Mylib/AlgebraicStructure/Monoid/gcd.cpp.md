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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/gcd.cpp\"\n#include <numeric>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct gcd_monoid {\n    using\
    \ value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return std::gcd(a, b);}\n  };\n\
    }\n"
  code: "#pragma once\n#include <numeric>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct gcd_monoid {\n    using value_type = T;\n    value_type operator()()\
    \ const {return 0;}\n    value_type operator()(value_type a, value_type b) const\
    \ {return std::gcd(a, b);}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/gcd.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/gcd.cpp
layout: document
title: GCD monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
