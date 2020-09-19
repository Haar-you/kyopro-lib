---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1099/main.test.cpp
    title: test/yukicoder/1099/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <typename MonoidGet,\
    \ typename MonoidUpdate>\n  struct add_square_sum {\n    using value_type_get\
    \ = typename MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(const value_type_get &a, const value_type_update\
    \ &b, int len) const {\n      return {std::get<0>(a) + b * len, std::get<1>(a)\
    \ + b * (2 * std::get<0>(a) + b * len)};\n    }\n  };\n}\n"
  code: "#pragma once\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ MonoidGet, typename MonoidUpdate>\n  struct add_square_sum {\n    using value_type_get\
    \ = typename MonoidGet::value_type;\n    using value_type_update = typename MonoidUpdate::value_type;\n\
    \n    value_type_get operator()(const value_type_get &a, const value_type_update\
    \ &b, int len) const {\n      return {std::get<0>(a) + b * len, std::get<1>(a)\
    \ + b * (2 * std::get<0>(a) + b * len)};\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:43:57+09:00'
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
