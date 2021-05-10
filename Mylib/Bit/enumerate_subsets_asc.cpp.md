---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3034/main.test.cpp
    title: test/aoj/3034/main.test.cpp
  - icon: ':x:'
    path: test/aoj/ITP2_11_C/main.asc.test.cpp
    title: test/aoj/ITP2_11_C/main.asc.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Bit/enumerate_subsets_asc.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename Func>\n  void enumerate_subsets_asc(int a, const Func\
    \ &f) {\n    for (int t = 0;; t = (t - a) & a) {\n      if (not f(t)) break;\n\
    \      if (t == a) break;\n    }\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Func>\n  void\
    \ enumerate_subsets_asc(int a, const Func &f) {\n    for (int t = 0;; t = (t -\
    \ a) & a) {\n      if (not f(t)) break;\n      if (t == a) break;\n    }\n  }\n\
    }  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/enumerate_subsets_asc.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/3034/main.test.cpp
  - test/aoj/ITP2_11_C/main.asc.test.cpp
documentation_of: Mylib/Bit/enumerate_subsets_asc.cpp
layout: document
title: Enumerate subsets (Ascending order)
---

## Operations

## Requirements

## Notes

## Problems

## References
