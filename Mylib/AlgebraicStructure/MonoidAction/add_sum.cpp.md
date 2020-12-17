---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667/main.test.cpp
    title: test/aoj/2667/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G/main.test.cpp
    title: test/aoj/DSL_2_G/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp\"\n\n\
    namespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct add_sum {\n    using monoid_get = MonoidGet;\n    using monoid_update\
    \ = MonoidUpdate;\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int len) const {\n      return\
    \ a + b * len;\n    }\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidUpdate,\
    \ typename MonoidGet>\n  struct add_sum {\n    using monoid_get = MonoidGet;\n\
    \    using monoid_update = MonoidUpdate;\n    using value_type_get = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(value_type_get a, value_type_update b, int len)\
    \ const {\n      return a + b * len;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp
  requiredBy: []
  timestamp: '2020-10-02 17:13:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2667/main.test.cpp
  - test/aoj/DSL_2_G/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/MonoidAction/add_sum.cpp
layout: document
title: Range add / Range sum
---

## Operations

## Requirements

## Notes

## Problems

## References
