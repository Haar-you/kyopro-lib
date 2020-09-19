---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/power.cpp\"\n#include <functional>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  T power(T n, int64_t p, const T &e, const\
    \ std::function<T(T, T)> &f){\n    T ret = e;\n\n    while(p > 0){\n      if(p\
    \ & 1) ret = f(ret, n);\n      n = f(n, n);\n      p >>= 1;\n    }\n\n    return\
    \ ret;\n  }\n}\n"
  code: "#pragma once\n#include <functional>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  T power(T n, int64_t p, const T &e, const std::function<T(T, T)> &f){\n\
    \    T ret = e;\n\n    while(p > 0){\n      if(p & 1) ret = f(ret, n);\n     \
    \ n = f(n, n);\n      p >>= 1;\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/power.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/power.cpp
layout: document
title: Binary exponentiation
---

## Operations

## Requirements

## Notes

## Problems

## References
