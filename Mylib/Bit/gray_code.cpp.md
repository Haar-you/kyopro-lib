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
  bundledCode: "#line 2 \"Mylib/Bit/gray_code.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename Func>\n  void gray_code(int n, const Func &f) {\n    for (int i =\
    \ 0; i < (1 << n); ++i) {\n      if (not f(i ^ (i >> 1))) break;\n    }\n  }\n\
    }  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Func>\n  void\
    \ gray_code(int n, const Func &f) {\n    for (int i = 0; i < (1 << n); ++i) {\n\
    \      if (not f(i ^ (i >> 1))) break;\n    }\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/gray_code.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Bit/gray_code.cpp
layout: document
title: Gray code
---

## Operations

## Requirements

## Notes

## Problems

## References