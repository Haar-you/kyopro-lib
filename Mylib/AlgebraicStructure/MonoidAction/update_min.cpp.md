---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_F/main.test.cpp
    title: test/aoj/DSL_2_F/main.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_F/main.dynamic.test.cpp
    title: test/aoj/DSL_2_F/main.dynamic.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/update_min.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct update_min {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int) const {\n      return\
    \ b ? *b : a;\n    }\n  };\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename MonoidGet, typename\
    \ MonoidUpdate>\n  struct update_min {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int) const {\n      return\
    \ b ? *b : a;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/update_min.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:43:57+09:00'
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
