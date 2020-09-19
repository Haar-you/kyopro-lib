---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ITP2_11_D/main.test.cpp
    title: test/aoj/ITP2_11_D/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Bit/enumerate_sets_of_size_k.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename Func>\n  void enumerate_sets_of_size_k(int k, int n,\
    \ const Func &f){\n    int c = (1 << k) - 1;\n    while(c < (1 << n)){\n     \
    \ if(not f(c)) break;\n      const int x = c & (-c);\n      const int y = c +\
    \ x;\n      c = ((c & (~y)) / x >> 1) | y;\n    }\n  }\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Func>\n  void\
    \ enumerate_sets_of_size_k(int k, int n, const Func &f){\n    int c = (1 << k)\
    \ - 1;\n    while(c < (1 << n)){\n      if(not f(c)) break;\n      const int x\
    \ = c & (-c);\n      const int y = c + x;\n      c = ((c & (~y)) / x >> 1) | y;\n\
    \    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/enumerate_sets_of_size_k.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ITP2_11_D/main.test.cpp
documentation_of: Mylib/Bit/enumerate_sets_of_size_k.cpp
layout: document
title: Enumerate sets of size k
---

## Operations

## Requirements

## Notes

## Problems

## References
