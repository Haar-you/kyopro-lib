---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C/main.test.cpp
    title: test/aoj/ALDS1_1_C/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/is_prime.cpp\"\n\nnamespace haar_lib\
    \ {\n  constexpr bool is_prime(int n){\n    if(n <= 1) return false;\n    for(int\
    \ i = 2; i * i <= n; ++i){\n      if(n % i == 0) return false;\n    }\n    return\
    \ true;\n  }\n}\n"
  code: "#pragma once\n\nnamespace haar_lib {\n  constexpr bool is_prime(int n){\n\
    \    if(n <= 1) return false;\n    for(int i = 2; i * i <= n; ++i){\n      if(n\
    \ % i == 0) return false;\n    }\n    return true;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/is_prime.cpp
  requiredBy: []
  timestamp: '2021-02-28 17:48:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_C/main.test.cpp
documentation_of: Mylib/Number/Prime/is_prime.cpp
layout: document
title: Primality test (Trial division)
---

## Operations

## Requirements

## Notes

## Problems

## References
