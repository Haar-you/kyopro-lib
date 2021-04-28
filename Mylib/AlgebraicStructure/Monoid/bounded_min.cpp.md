---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
    title: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/bounded_min.cpp\"\n#include\
    \ <algorithm>\n#include <limits>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct bounded_min_monoid {\n    using value_type = T;\n\n    value_type\
    \ operator()() const { return std::numeric_limits<T>::max(); }\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {\n      return std::min(a,\
    \ b);\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct bounded_min_monoid {\n    using value_type\
    \ = T;\n\n    value_type operator()() const { return std::numeric_limits<T>::max();\
    \ }\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ {\n      return std::min(a, b);\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/bounded_min.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/bounded_min.cpp
layout: document
title: Bounded min monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
