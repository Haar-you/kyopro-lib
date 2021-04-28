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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/bounded_max.cpp\"\n#include\
    \ <algorithm>\n#include <limits>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct bounded_max_monoid {\n    using value_type = T;\n\n    value_type\
    \ operator()() const { return std::numeric_limits<T>::lowest(); }\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {\n      return std::max(a,\
    \ b);\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct bounded_max_monoid {\n    using value_type\
    \ = T;\n\n    value_type operator()() const { return std::numeric_limits<T>::lowest();\
    \ }\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ {\n      return std::max(a, b);\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/bounded_max.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/bounded_max.cpp
layout: document
title: Bounded max monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
