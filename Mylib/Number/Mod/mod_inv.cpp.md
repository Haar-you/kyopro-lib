---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mod/mod_log.cpp
    title: Mod logarithm
  - icon: ':warning:'
    path: Mylib/Number/garner.cpp
    title: Garner algorithm
  - icon: ':warning:'
    path: Mylib/Number/linear_congruence_equation.cpp
    title: Linear congruence equation
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
    title: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mod/mod_inv.cpp\"\n#include <utility>\n#include\
    \ <cstdint>\n\nnamespace haar_lib {\n  int64_t mod_inv(int64_t a, int64_t m){\n\
    \    int64_t b = m, u = 1, v = 0;\n\n    while(b){\n      int64_t t = a / b;\n\
    \      a -= t * b; std::swap(a, b);\n      u -= t * v; std::swap(u, v);\n    }\n\
    \n    u %= m;\n    if(u < 0) u += m;\n\n    return u;\n  }\n}\n"
  code: "#pragma once\n#include <utility>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  int64_t mod_inv(int64_t a, int64_t m){\n    int64_t b = m, u = 1, v = 0;\n\
    \n    while(b){\n      int64_t t = a / b;\n      a -= t * b; std::swap(a, b);\n\
    \      u -= t * v; std::swap(u, v);\n    }\n\n    u %= m;\n    if(u < 0) u +=\
    \ m;\n\n    return u;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Mod/mod_inv.cpp
  requiredBy:
  - Mylib/Number/garner.cpp
  - Mylib/Number/Mod/mod_log.cpp
  - Mylib/Number/linear_congruence_equation.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
documentation_of: Mylib/Number/Mod/mod_inv.cpp
layout: document
title: Mod inverse
---

## Operations

- `mod_inv(a, m)`
	- $ax = 1 \pmod m$を満たす`x`を求める。
	- $gcd(a,  m) = 1$を満たさなければならない。
	- Time complexity $O(\log N)$

## Requirements

## Notes

## Problems

## References
