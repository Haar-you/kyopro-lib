---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Coloring/chromatic_number.cpp
    title: Graph vertex coloring
  - icon: ':x:'
    path: Mylib/Number/Mod/mod_log.cpp
    title: Mod logarithm
  - icon: ':x:'
    path: Mylib/Number/Mod/mod_sqrt.cpp
    title: Mod sqrt
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2136/main.test.cpp
    title: test/aoj/2136/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2530/main.test.cpp
    title: test/aoj/2530/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
    title: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/sqrt_mod/main.test.cpp
    title: test/yosupo-judge/sqrt_mod/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\n#include <cstdint>\n\nnamespace\
    \ haar_lib {\n  int64_t mod_pow(int64_t n, int64_t p, int64_t m){\n    int64_t\
    \ ret = 1;\n    while(p > 0){\n      if(p & 1) (ret *= n) %= m;\n      (n *= n)\
    \ %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  int64_t mod_pow(int64_t\
    \ n, int64_t p, int64_t m){\n    int64_t ret = 1;\n    while(p > 0){\n      if(p\
    \ & 1) (ret *= n) %= m;\n      (n *= n) %= m;\n      p >>= 1;\n    }\n    return\
    \ ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Mod/mod_pow.cpp
  requiredBy:
  - Mylib/Graph/Coloring/chromatic_number.cpp
  - Mylib/Number/Mod/mod_log.cpp
  - Mylib/Number/Mod/mod_sqrt.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2136/main.test.cpp
  - test/aoj/2530/main.test.cpp
  - test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
  - test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/sqrt_mod/main.test.cpp
documentation_of: Mylib/Number/Mod/mod_pow.cpp
layout: document
title: Mod pow
---

## Operations

- `mod_pow(n, p, m)`
	- $n ^ p \pmod m$を求める。
	- Time complexity $O(\log p)$

## Requirements

## Notes

## Problems

## References

