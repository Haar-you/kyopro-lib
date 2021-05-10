---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/range_affine_range_sum/main.test.cpp
    title: test/yosupo-judge/range_affine_range_sum/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct affine_sum {\n    using monoid_get        = MonoidGet;\n    using monoid_update\
    \     = MonoidUpdate;\n    using value_type_get    = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int len) const {\n      return\
    \ b.first * a + b.second * len;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidUpdate,\
    \ typename MonoidGet>\n  struct affine_sum {\n    using monoid_get        = MonoidGet;\n\
    \    using monoid_update     = MonoidUpdate;\n    using value_type_get    = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(value_type_get a, value_type_update b, int len)\
    \ const {\n      return b.first * a + b.second * len;\n    }\n  };\n}  // namespace\
    \ haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/range_affine_range_sum/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp
layout: document
title: Range affine / Range sum
---

## Operations

## Requirements

## Notes

## Problems

## References