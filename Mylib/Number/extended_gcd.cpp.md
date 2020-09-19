---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Number/chinese_remainder_algorithm.cpp
    title: Chinese remainder theorem
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_E/main.test.cpp
    title: test/aoj/NTL_1_E/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/186/main.test.cpp
    title: test/yukicoder/186/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/extended_gcd.cpp\"\n#include <tuple>\n\nnamespace\
    \ haar_lib {\n  std::tuple<int64_t, int64_t, int64_t> ext_gcd(int64_t a, int64_t\
    \ b){\n    if(b == 0) return std::make_tuple(a, 1, 0);\n    int64_t d, p, q;\n\
    \    std::tie(d, q, p) = ext_gcd(b, (a + b) % b);\n    return std::make_tuple(d,\
    \ p, q - a / b * p);\n  }\n}\n"
  code: "#pragma once\n#include <tuple>\n\nnamespace haar_lib {\n  std::tuple<int64_t,\
    \ int64_t, int64_t> ext_gcd(int64_t a, int64_t b){\n    if(b == 0) return std::make_tuple(a,\
    \ 1, 0);\n    int64_t d, p, q;\n    std::tie(d, q, p) = ext_gcd(b, (a + b) % b);\n\
    \    return std::make_tuple(d, p, q - a / b * p);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/extended_gcd.cpp
  requiredBy:
  - Mylib/Number/chinese_remainder_algorithm.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
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
