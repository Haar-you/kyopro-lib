---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3035/main.test.cpp
    title: test/aoj/3035/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct add_max_with_count {\n    using monoid_get        = MonoidGet;\n   \
    \ using monoid_update     = MonoidUpdate;\n    using value_type_get    = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(const value_type_get &a, const value_type_update\
    \ &b, int) const {\n      return {a.value ? a.value.value() + b : a.value, a.count};\n\
    \    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidUpdate,\
    \ typename MonoidGet>\n  struct add_max_with_count {\n    using monoid_get   \
    \     = MonoidGet;\n    using monoid_update     = MonoidUpdate;\n    using value_type_get\
    \    = typename MonoidGet::value_type;\n    using value_type_update = typename\
    \ MonoidUpdate::value_type;\n\n    value_type_get operator()(const value_type_get\
    \ &a, const value_type_update &b, int) const {\n      return {a.value ? a.value.value()\
    \ + b : a.value, a.count};\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/3035/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp
layout: document
title: Range add / Range max with count
---

## Operations

## Requirements

## Notes

## Problems

## References
