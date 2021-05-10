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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/array.cpp\"\n#include <array>\n\
    \nnamespace haar_lib {\n  template <typename Monoid, int B>\n  struct array_monoid\
    \ {\n    using value_type = std::array<typename Monoid::value_type, B>;\n    const\
    \ static Monoid M;\n\n    value_type operator()() const {\n      value_type ret;\n\
    \      ret.fill(M());\n      return ret;\n    }\n\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      value_type ret;\n      for\
    \ (int i = 0; i < B; ++i) ret[i] = M(a[i], b[i]);\n      return ret;\n    }\n\
    \  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <array>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid, int B>\n  struct array_monoid {\n    using value_type = std::array<typename\
    \ Monoid::value_type, B>;\n    const static Monoid M;\n\n    value_type operator()()\
    \ const {\n      value_type ret;\n      ret.fill(M());\n      return ret;\n  \
    \  }\n\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ {\n      value_type ret;\n      for (int i = 0; i < B; ++i) ret[i] = M(a[i],\
    \ b[i]);\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/array.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/array.cpp
layout: document
title: Array monoid
---

## Operations

## Requirements

## Notes

## Problems

## References