---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3034/main.test.cpp
    title: test/aoj/3034/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP2_11_C/main.asc.test.cpp
    title: test/aoj/ITP2_11_C/main.asc.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Bit/enumerate_subsets_asc.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename Func>\n  void enumerate_subsets_asc(int a, const Func\
    \ &f){\n    for(int t = 0; ; t = (t - a) & a){\n      if(not f(t)) break;\n  \
    \    if(t == a) break;\n    }\n  }\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Func>\n  void\
    \ enumerate_subsets_asc(int a, const Func &f){\n    for(int t = 0; ; t = (t -\
    \ a) & a){\n      if(not f(t)) break;\n      if(t == a) break;\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/enumerate_subsets_asc.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
