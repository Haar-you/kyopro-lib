---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/631/main.test.cpp
    title: test/yukicoder/631/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_max.cpp\"\n\n\
    namespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct add_max {\n    using monoid_get = MonoidGet;\n    using monoid_update\
    \ = MonoidUpdate;\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int) const {\n      if(a)\
    \ return {*a + b};\n      return {};\n    }\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidUpdate,\
    \ typename MonoidGet>\n  struct add_max {\n    using monoid_get = MonoidGet;\n\
    \    using monoid_update = MonoidUpdate;\n    using value_type_get = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(value_type_get a, value_type_update b, int) const\
    \ {\n      if(a) return {*a + b};\n      return {};\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/add_max.cpp
  requiredBy: []
  timestamp: '2020-10-02 17:13:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/631/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/MonoidAction/add_max.cpp
layout: document
title: Range add / Range max
---

## Operations

## Requirements

## Notes

## Problems

## References
