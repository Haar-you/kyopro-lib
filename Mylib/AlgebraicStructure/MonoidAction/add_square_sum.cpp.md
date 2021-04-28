---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1099/main.test.cpp
    title: test/yukicoder/1099/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <typename MonoidUpdate>\n\
    \  struct add_square_sum {\n    struct internal_type {\n      using value_type\
    \ = typename MonoidUpdate::value_type;\n      value_type sum, square_sum;\n  \
    \    internal_type(value_type value) : sum(value), square_sum(value * value) {}\n\
    \      internal_type(value_type sum, value_type square_sum) : sum(sum), square_sum(square_sum)\
    \ {}\n    };\n\n    struct monoid_get {\n      using value_type = internal_type;\n\
    \      value_type operator()() const { return {0, 0}; };\n      value_type operator()(const\
    \ value_type &a, const value_type &b) { return {a.sum + b.sum, a.square_sum +\
    \ b.square_sum}; }\n    };\n\n    using monoid_update     = MonoidUpdate;\n  \
    \  using value_type_get    = typename monoid_get::value_type;\n    using value_type_update\
    \ = typename MonoidUpdate::value_type;\n\n    value_type_get operator()(const\
    \ value_type_get &a, const value_type_update &b, int len) const {\n      return\
    \ {\n          a.sum + b * len,\n          a.square_sum + b * (2 * a.sum + b *\
    \ len)};\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ MonoidUpdate>\n  struct add_square_sum {\n    struct internal_type {\n     \
    \ using value_type = typename MonoidUpdate::value_type;\n      value_type sum,\
    \ square_sum;\n      internal_type(value_type value) : sum(value), square_sum(value\
    \ * value) {}\n      internal_type(value_type sum, value_type square_sum) : sum(sum),\
    \ square_sum(square_sum) {}\n    };\n\n    struct monoid_get {\n      using value_type\
    \ = internal_type;\n      value_type operator()() const { return {0, 0}; };\n\
    \      value_type operator()(const value_type &a, const value_type &b) { return\
    \ {a.sum + b.sum, a.square_sum + b.square_sum}; }\n    };\n\n    using monoid_update\
    \     = MonoidUpdate;\n    using value_type_get    = typename monoid_get::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(const value_type_get &a, const value_type_update &b, int len) const\
    \ {\n      return {\n          a.sum + b * len,\n          a.square_sum + b *\
    \ (2 * a.sum + b * len)};\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1099/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp
layout: document
title: Range add / Range square sum
---

## Operations

## Requirements

## Notes

## Problems

## References
