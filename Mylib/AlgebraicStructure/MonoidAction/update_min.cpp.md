---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_F/main.dynamic.test.cpp
    title: test/aoj/DSL_2_F/main.dynamic.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_F/main.test.cpp
    title: test/aoj/DSL_2_F/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/update_min.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct update_min {\n    using monoid_get        = MonoidGet;\n    using monoid_update\
    \     = MonoidUpdate;\n    using value_type_get    = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int) const {\n      return\
    \ b ? *b : a;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidUpdate,\
    \ typename MonoidGet>\n  struct update_min {\n    using monoid_get        = MonoidGet;\n\
    \    using monoid_update     = MonoidUpdate;\n    using value_type_get    = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(value_type_get a, value_type_update b, int) const\
    \ {\n      return b ? *b : a;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/update_min.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_F/main.test.cpp
  - test/aoj/DSL_2_F/main.dynamic.test.cpp
documentation_of: Mylib/AlgebraicStructure/MonoidAction/update_min.cpp
layout: document
title: Range update / Range min
---

## Operations

## Requirements

## Notes

## Problems

## References
