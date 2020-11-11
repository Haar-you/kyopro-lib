---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Convolution/convolution_multiply.cpp
    title: Convolution (Index multiplication mod P)
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/Coloring/chromatic_number.cpp
    title: Graph vertex coloring
  - icon: ':x:'
    path: Mylib/Math/fps_sqrt.cpp
    title: Formal power series (Sqrt)
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mod/mod_log.cpp
    title: Mod logarithm
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_sqrt.cpp
    title: Mod sqrt
  - icon: ':question:'
    path: Mylib/Number/Prime/primitive_root.cpp
    title: Primitive root
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2136/main.test.cpp
    title: test/aoj/2136/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2530/main.test.cpp
    title: test/aoj/2530/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/bernoulli_number/main.test.cpp
    title: test/yosupo-judge/bernoulli_number/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/convolution_mod/main.test.cpp
    title: test/yosupo-judge/convolution_mod/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
    title: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/exp_of_formal_power_series/main.montgomery.test.cpp
    title: test/yosupo-judge/exp_of_formal_power_series/main.montgomery.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/log_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/log_of_formal_power_series/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/multipoint_evaluation/main.test.cpp
    title: test/yosupo-judge/multipoint_evaluation/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/partition_function/main.fps.test.cpp
    title: test/yosupo-judge/partition_function/main.fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
    title: test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
    title: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/sqrt_mod/main.test.cpp
    title: test/yosupo-judge/sqrt_mod/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
    title: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
    title: test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/931/main.test.cpp
    title: test/yukicoder/931/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\n#include <cstdint>\n\nnamespace\
    \ haar_lib {\n  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t m){\n\
    \    int64_t ret = 1;\n    while(p > 0){\n      if(p & 1) (ret *= n) %= m;\n \
    \     (n *= n) %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  constexpr int64_t\
    \ mod_pow(int64_t n, int64_t p, int64_t m){\n    int64_t ret = 1;\n    while(p\
    \ > 0){\n      if(p & 1) (ret *= n) %= m;\n      (n *= n) %= m;\n      p >>= 1;\n\
    \    }\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Mod/mod_pow.cpp
  requiredBy:
  - Mylib/Number/Prime/primitive_root.cpp
  - Mylib/Number/Mod/mod_sqrt.cpp
  - Mylib/Number/Mod/mod_log.cpp
  - Mylib/Convolution/convolution_multiply.cpp
  - Mylib/Graph/Coloring/chromatic_number.cpp
  - Mylib/Math/fps_sqrt.cpp
  timestamp: '2020-10-28 03:22:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/931/main.test.cpp
  - test/aoj/2136/main.test.cpp
  - test/aoj/2530/main.test.cpp
  - test/yosupo-judge/partition_function/main.fps.test.cpp
  - test/yosupo-judge/bernoulli_number/main.test.cpp
  - test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
  - test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
  - test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/multipoint_evaluation/main.test.cpp
  - test/yosupo-judge/log_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/exp_of_formal_power_series/main.montgomery.test.cpp
  - test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
  - test/yosupo-judge/convolution_mod/main.test.cpp
  - test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
  - test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
  - test/yosupo-judge/sqrt_mod/main.test.cpp
  - test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
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

