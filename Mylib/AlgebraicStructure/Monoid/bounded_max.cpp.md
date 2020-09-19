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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/bounded_max.cpp\"\n#include\
    \ <limits>\n#include <algorithm>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct bounded_max_monoid {\n    using value_type = T;\n\n    value_type\
    \ operator()() const {return std::numeric_limits<T>::lowest();}\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {\n      return std::max(a,\
    \ b);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <limits>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct bounded_max_monoid {\n    using value_type\
    \ = T;\n\n    value_type operator()() const {return std::numeric_limits<T>::lowest();}\n\
    \    value_type operator()(const value_type &a, const value_type &b) const {\n\
    \      return std::max(a, b);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/bounded_max.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
