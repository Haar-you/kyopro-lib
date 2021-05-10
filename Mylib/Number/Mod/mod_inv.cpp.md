---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Combinatorics/binomial_coefficient.cpp
    title: Binomial coefficient
  - icon: ':x:'
    path: Mylib/Number/Mod/mod_log.cpp
    title: Mod logarithm
  - icon: ':warning:'
    path: Mylib/Number/garner.cpp
    title: Garner algorithm
  - icon: ':warning:'
    path: Mylib/Number/linear_congruence_equation.cpp
    title: Linear congruence equation
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/binomial_coefficient/main.test.cpp
    title: test/yosupo-judge/binomial_coefficient/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
    title: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mod/mod_inv.cpp\"\n#include <cstdint>\n#include\
    \ <utility>\n\nnamespace haar_lib {\n  constexpr int64_t mod_inv(int64_t a, int64_t\
    \ m) {\n    int64_t b = m, u = 1, v = 0;\n\n    while (b) {\n      int64_t t =\
    \ a / b;\n      a -= t * b;\n      a = a ^ b;\n      b = a ^ b;\n      a = a ^\
    \ b;\n\n      u -= t * v;\n      u = u ^ v;\n      v = u ^ v;\n      u = u ^ v;\n\
    \    }\n\n    u %= m;\n    if (u < 0) u += m;\n\n    return u;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  constexpr int64_t mod_inv(int64_t a, int64_t m) {\n    int64_t b = m, u\
    \ = 1, v = 0;\n\n    while (b) {\n      int64_t t = a / b;\n      a -= t * b;\n\
    \      a = a ^ b;\n      b = a ^ b;\n      a = a ^ b;\n\n      u -= t * v;\n \
    \     u = u ^ v;\n      v = u ^ v;\n      u = u ^ v;\n    }\n\n    u %= m;\n \
    \   if (u < 0) u += m;\n\n    return u;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Mod/mod_inv.cpp
  requiredBy:
  - Mylib/Combinatorics/binomial_coefficient.cpp
  - Mylib/Number/linear_congruence_equation.cpp
  - Mylib/Number/Mod/mod_log.cpp
  - Mylib/Number/garner.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
  - test/yosupo-judge/binomial_coefficient/main.test.cpp
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
