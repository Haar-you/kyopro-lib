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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/transformation.cpp\"\n#include\
    \ <array>\n\nnamespace haar_lib {\n  template <size_t N>\n  struct transformation_monoid\
    \ {\n    using value_type = std::array<int, N>;\n\n    value_type operator()()\
    \ const {\n      value_type ret;\n      for (int i = 0; i < (int) N; ++i) ret[i]\
    \ = i;\n      return ret;\n    }\n\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const {\n      value_type ret;\n      for (int i =\
    \ 0; i < (int) N; ++i) ret[i] = a[b[i]];\n      return ret;\n    }\n  };\n}  //\
    \ namespace haar_lib\n"
  code: "#pragma once\n#include <array>\n\nnamespace haar_lib {\n  template <size_t\
    \ N>\n  struct transformation_monoid {\n    using value_type = std::array<int,\
    \ N>;\n\n    value_type operator()() const {\n      value_type ret;\n      for\
    \ (int i = 0; i < (int) N; ++i) ret[i] = i;\n      return ret;\n    }\n\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {\n      value_type\
    \ ret;\n      for (int i = 0; i < (int) N; ++i) ret[i] = a[b[i]];\n      return\
    \ ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/transformation.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/transformation.cpp
layout: document
title: Transformation monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
