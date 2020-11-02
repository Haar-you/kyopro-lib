---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
    title: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/bounded_min.cpp\"\n#include\
    \ <limits>\n#include <algorithm>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct bounded_min_monoid {\n    using value_type = T;\n\n    value_type\
    \ operator()() const {return std::numeric_limits<T>::max();}\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      return std::min(a, b);\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <limits>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct bounded_min_monoid {\n    using value_type\
    \ = T;\n\n    value_type operator()() const {return std::numeric_limits<T>::max();}\n\
    \    value_type operator()(const value_type &a, const value_type &b) const {\n\
    \      return std::min(a, b);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/bounded_min.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
