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
  bundledCode: "#line 2 \"Mylib/Bit/enumerate_subsets_between.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename Func>\n  void enumerate_subsets_between(int a, int b,\
    \ const Func &f) {\n    const int x = b ^ (a & b);\n    for (int t = x;; t = (t\
    \ - 1) & x) {\n      if (not f(t | a)) break;\n      if (t == 0) break;\n    }\n\
    \  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Func>\n  void\
    \ enumerate_subsets_between(int a, int b, const Func &f) {\n    const int x =\
    \ b ^ (a & b);\n    for (int t = x;; t = (t - 1) & x) {\n      if (not f(t | a))\
    \ break;\n      if (t == 0) break;\n    }\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/enumerate_subsets_between.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Bit/enumerate_subsets_between.cpp
layout: document
title: Enumerate subsets (Between)
---

## Operations

## Requirements

## Notes

## Problems

## References
