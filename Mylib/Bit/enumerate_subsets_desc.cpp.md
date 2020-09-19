---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ITP2_11_C/main.desc.test.cpp
    title: test/aoj/ITP2_11_C/main.desc.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Bit/enumerate_subsets_desc.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename Func>\n  void enumerate_subsets_desc(int a, const Func\
    \ &f){\n    for(int t = a; ; t = (t - 1) & a){\n      if(not f(t)) break;\n  \
    \    if(t == 0) break;\n    }\n  }\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  template <typename Func>\n  void\
    \ enumerate_subsets_desc(int a, const Func &f){\n    for(int t = a; ; t = (t -\
    \ 1) & a){\n      if(not f(t)) break;\n      if(t == 0) break;\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Bit/enumerate_subsets_desc.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ITP2_11_C/main.desc.test.cpp
documentation_of: Mylib/Bit/enumerate_subsets_desc.cpp
layout: document
title: Enumerate subsets (Descending order)
---

## Operations

## Requirements

## Notes

## Problems

## References
