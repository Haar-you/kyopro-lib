---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Mylib/Number/bezout_identity.cpp
    title: "B\xE9zout's identity"
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/chinese_remainder_algorithm.cpp
    title: Chinese remainder theorem
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_E/main.test.cpp
    title: test/aoj/NTL_1_E/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/186/main.test.cpp
    title: test/yukicoder/186/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/extended_gcd.cpp\"\n#include <tuple>\n\nnamespace\
    \ haar_lib {\n  std::tuple<int64_t, int64_t, int64_t> ext_gcd(int64_t a, int64_t\
    \ b){\n    if(b == 0) return std::make_tuple(a, 1, 0);\n    const auto [d, q,\
    \ p] = ext_gcd(b, (a + b) % b);\n    return std::make_tuple(d, p, q - a / b *\
    \ p);\n  }\n}\n"
  code: "#pragma once\n#include <tuple>\n\nnamespace haar_lib {\n  std::tuple<int64_t,\
    \ int64_t, int64_t> ext_gcd(int64_t a, int64_t b){\n    if(b == 0) return std::make_tuple(a,\
    \ 1, 0);\n    const auto [d, q, p] = ext_gcd(b, (a + b) % b);\n    return std::make_tuple(d,\
    \ p, q - a / b * p);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/extended_gcd.cpp
  requiredBy:
  - Mylib/Number/chinese_remainder_algorithm.cpp
  - Mylib/Number/bezout_identity.cpp
  timestamp: '2020-09-25 03:22:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/186/main.test.cpp
  - test/aoj/NTL_1_E/main.test.cpp
documentation_of: Mylib/Number/extended_gcd.cpp
layout: document
title: Extended Euclidean algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
