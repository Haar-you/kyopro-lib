---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Combinatorics/binomial_coefficient.cpp
    title: Binomial coefficient
  - icon: ':warning:'
    path: Mylib/Number/bezout_identity.cpp
    title: "B\xE9zout's identity"
  - icon: ':x:'
    path: Mylib/Number/chinese_remainder_algorithm.cpp
    title: Chinese remainder theorem
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_E/main.test.cpp
    title: test/aoj/NTL_1_E/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/binomial_coefficient/main.test.cpp
    title: test/yosupo-judge/binomial_coefficient/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/186/main.test.cpp
    title: test/yukicoder/186/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/extended_gcd.cpp\"\n#include <tuple>\n\nnamespace\
    \ haar_lib {\n  auto ext_gcd(int64_t a, int64_t b) -> std::tuple<\n      int64_t,\
    \  // gcd\n      int64_t,  // p\n      int64_t   // q\n      > {\n    if (b ==\
    \ 0) return std::make_tuple(a, 1, 0);\n    const auto [d, q, p] = ext_gcd(b, (a\
    \ + b) % b);\n    return std::make_tuple(d, p, q - a / b * p);\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <tuple>\n\nnamespace haar_lib {\n  auto ext_gcd(int64_t\
    \ a, int64_t b) -> std::tuple<\n      int64_t,  // gcd\n      int64_t,  // p\n\
    \      int64_t   // q\n      > {\n    if (b == 0) return std::make_tuple(a, 1,\
    \ 0);\n    const auto [d, q, p] = ext_gcd(b, (a + b) % b);\n    return std::make_tuple(d,\
    \ p, q - a / b * p);\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/extended_gcd.cpp
  requiredBy:
  - Mylib/Combinatorics/binomial_coefficient.cpp
  - Mylib/Number/bezout_identity.cpp
  - Mylib/Number/chinese_remainder_algorithm.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/binomial_coefficient/main.test.cpp
  - test/aoj/NTL_1_E/main.test.cpp
  - test/yukicoder/186/main.test.cpp
documentation_of: Mylib/Number/extended_gcd.cpp
layout: document
title: Extended Euclidean algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References