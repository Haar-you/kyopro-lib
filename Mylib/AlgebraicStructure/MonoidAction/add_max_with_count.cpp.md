---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3035/main.test.cpp
    title: test/aoj/3035/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct add_max_with_count {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(const value_type_get &a, const value_type_update &b, int) const {\n\
    \      return {a.value ? a.value.value() + b : a.value, a.count};\n    }\n  };\n\
    }\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidGet, typename\
    \ MonoidUpdate>\n  struct add_max_with_count {\n    using value_type_get = typename\
    \ MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(const value_type_get &a, const value_type_update\
    \ &b, int) const {\n      return {a.value ? a.value.value() + b : a.value, a.count};\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:43:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
