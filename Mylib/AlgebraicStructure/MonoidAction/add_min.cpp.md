---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_H/main.test.cpp
    title: test/aoj/DSL_2_H/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_min.cpp\"\n\n\
    namespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct add_min {\n    using monoid_get = MonoidGet;\n    using monoid_update\
    \ = MonoidUpdate;\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int) const {\n      if(a)\
    \ return {*a + b};\n      return {};\n    }\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidUpdate,\
    \ typename MonoidGet>\n  struct add_min {\n    using monoid_get = MonoidGet;\n\
    \    using monoid_update = MonoidUpdate;\n    using value_type_get = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(value_type_get a, value_type_update b, int) const\
    \ {\n      if(a) return {*a + b};\n      return {};\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/add_min.cpp
  requiredBy: []
  timestamp: '2020-10-02 17:13:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_H/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/MonoidAction/add_min.cpp
layout: document
title: Range add / Range min
---

## Operations

## Requirements

## Notes

## Problems

## References
