---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/is_square.cpp\"\n\nnamespace haar_lib {\n \
    \ template <typename T>\n  constexpr bool is_square(T n) {\n    T rt = sqrt(n);\n\
    \    return rt * rt == n;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename T>\n  constexpr\
    \ bool is_square(T n) {\n    T rt = sqrt(n);\n    return rt * rt == n;\n  }\n\
    }  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/is_square.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/is_square.cpp
layout: document
title: Check square number
---

## Operations

## Requirements

## Notes

## Problems

## References
