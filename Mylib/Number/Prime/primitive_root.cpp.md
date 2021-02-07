---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/convolution_multiply.cpp
    title: Convolution (Index multiplication mod P)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/bernoulli_number/main.test.cpp
    title: test/yosupo-judge/bernoulli_number/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/convolution_mod/main.test.cpp
    title: test/yosupo-judge/convolution_mod/main.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
    title: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
    title: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
    title: test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/931/main.test.cpp
    title: test/yukicoder/931/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\n#include <cstdint>\n\nnamespace\
    \ haar_lib {\n  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t m){\n\
    \    int64_t ret = 1;\n    while(p > 0){\n      if(p & 1) (ret *= n) %= m;\n \
    \     (n *= n) %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}\n#line 3\
    \ \"Mylib/Number/Prime/primitive_root.cpp\"\n\nnamespace haar_lib {\n  constexpr\
    \ int primitive_root(int p){\n    int pf[30] = {};\n    int k = 0;\n    {\n  \
    \    int n = p - 1;\n      for(int64_t i = 2; i * i <= p; ++i){\n        if(n\
    \ % i == 0){\n          pf[k++] = i;\n          while(n % i == 0) n /= i;\n  \
    \      }\n      }\n      if(n != 1)\n        pf[k++] = n;\n    }\n\n    for(int\
    \ g = 2; g <= p; ++g){\n      bool ok = true;\n      for(int i = 0; i < k; ++i){\n\
    \        if(mod_pow(g, (p - 1) / pf[i], p) == 1){\n          ok = false;\n   \
    \       break;\n        }\n      }\n\n      if(not ok) continue;\n\n      return\
    \ g;\n    }\n    return -1;\n  }\n}\n"
  code: "#pragma once\n#include \"Mylib/Number/Mod/mod_pow.cpp\"\n\nnamespace haar_lib\
    \ {\n  constexpr int primitive_root(int p){\n    int pf[30] = {};\n    int k =\
    \ 0;\n    {\n      int n = p - 1;\n      for(int64_t i = 2; i * i <= p; ++i){\n\
    \        if(n % i == 0){\n          pf[k++] = i;\n          while(n % i == 0)\
    \ n /= i;\n        }\n      }\n      if(n != 1)\n        pf[k++] = n;\n    }\n\
    \n    for(int g = 2; g <= p; ++g){\n      bool ok = true;\n      for(int i = 0;\
    \ i < k; ++i){\n        if(mod_pow(g, (p - 1) / pf[i], p) == 1){\n          ok\
    \ = false;\n          break;\n        }\n      }\n\n      if(not ok) continue;\n\
    \n      return g;\n    }\n    return -1;\n  }\n}\n"
  dependsOn:
  - Mylib/Number/Mod/mod_pow.cpp
  isVerificationFile: false
  path: Mylib/Number/Prime/primitive_root.cpp
  requiredBy:
  - Mylib/Convolution/convolution_multiply.cpp
  timestamp: '2020-10-28 03:22:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/log_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/partition_function/main.fps.test.cpp
  - test/yosupo-judge/multipoint_evaluation/main.test.cpp
  - test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
  - test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
  - test/yosupo-judge/bernoulli_number/main.test.cpp
  - test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
  - test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
  - test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/convolution_mod/main.test.cpp
  - test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/exp_of_formal_power_series/main.montgomery.test.cpp
  - test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
  - test/yukicoder/931/main.test.cpp
documentation_of: Mylib/Number/Prime/primitive_root.cpp
layout: document
title: Primitive root
---

## Operations

## Requirements

- `p`は素数

## Notes

## Problems

## References
