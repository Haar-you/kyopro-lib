---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Math/fps_sqrt.cpp
    title: Formal power series (Sqrt)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/sqrt_mod/main.test.cpp
    title: test/yosupo-judge/sqrt_mod/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mod/mod_sqrt.cpp\"\n#include <random>\n#include\
    \ <optional>\n#line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\n#include <cstdint>\n\n\
    namespace haar_lib {\n  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t\
    \ m){\n    int64_t ret = 1;\n    while(p > 0){\n      if(p & 1) (ret *= n) %=\
    \ m;\n      (n *= n) %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}\n#line\
    \ 5 \"Mylib/Number/Mod/mod_sqrt.cpp\"\n\nnamespace haar_lib {\n  std::optional<int64_t>\
    \ mod_sqrt(int64_t a, int64_t p){\n    if(p == 2) return a % 2;\n    if(a == 0)\
    \ return 0;\n\n    int64_t b = mod_pow(a, (p - 1) / 2, p);\n\n    if(b == p -\
    \ 1) return {};\n    if(p % 4 == 3) return mod_pow(a, (p + 1) / 4, p);\n\n   \
    \ int64_t q = p - 1, s = 0;\n    while(q % 2 == 0){\n      q /= 2;\n      s +=\
    \ 1;\n    }\n\n    static std::mt19937_64 rand(time(0));\n    std::uniform_int_distribution<>\
    \ dist(0, p - 1);\n\n    int64_t z;\n    while(1){\n      z = dist(rand);\n  \
    \    if(mod_pow(z, (p - 1) / 2, p) == p - 1) break;\n    }\n\n    int64_t m =\
    \ s;\n    int64_t c = mod_pow(z, q, p);\n    int64_t t = mod_pow(a, q, p);\n \
    \   int64_t r = mod_pow(a, (q + 1) / 2, p);\n\n    while(1){\n      if(t == 0)\
    \ return 0;\n      if(t == 1) return r;\n\n      int i = 1;\n      for(int64_t\
    \ T = t; i < m; ++i){\n        (T *= T) %= p;\n        if(T == 1) break;\n   \
    \   }\n\n      int64_t b = mod_pow(c, 1LL << (m - i - 1), p);\n\n      m = i;\n\
    \      c = b * b % p;\n      (t *= b * b % p) %= p;\n      (r *= b) %= p;\n  \
    \  }\n  }\n}\n"
  code: "#pragma once\n#include <random>\n#include <optional>\n#include \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n\nnamespace haar_lib {\n  std::optional<int64_t> mod_sqrt(int64_t a, int64_t\
    \ p){\n    if(p == 2) return a % 2;\n    if(a == 0) return 0;\n\n    int64_t b\
    \ = mod_pow(a, (p - 1) / 2, p);\n\n    if(b == p - 1) return {};\n    if(p % 4\
    \ == 3) return mod_pow(a, (p + 1) / 4, p);\n\n    int64_t q = p - 1, s = 0;\n\
    \    while(q % 2 == 0){\n      q /= 2;\n      s += 1;\n    }\n\n    static std::mt19937_64\
    \ rand(time(0));\n    std::uniform_int_distribution<> dist(0, p - 1);\n\n    int64_t\
    \ z;\n    while(1){\n      z = dist(rand);\n      if(mod_pow(z, (p - 1) / 2, p)\
    \ == p - 1) break;\n    }\n\n    int64_t m = s;\n    int64_t c = mod_pow(z, q,\
    \ p);\n    int64_t t = mod_pow(a, q, p);\n    int64_t r = mod_pow(a, (q + 1) /\
    \ 2, p);\n\n    while(1){\n      if(t == 0) return 0;\n      if(t == 1) return\
    \ r;\n\n      int i = 1;\n      for(int64_t T = t; i < m; ++i){\n        (T *=\
    \ T) %= p;\n        if(T == 1) break;\n      }\n\n      int64_t b = mod_pow(c,\
    \ 1LL << (m - i - 1), p);\n\n      m = i;\n      c = b * b % p;\n      (t *= b\
    \ * b % p) %= p;\n      (r *= b) %= p;\n    }\n  }\n}\n"
  dependsOn:
  - Mylib/Number/Mod/mod_pow.cpp
  isVerificationFile: false
  path: Mylib/Number/Mod/mod_sqrt.cpp
  requiredBy:
  - Mylib/Math/fps_sqrt.cpp
  timestamp: '2020-10-28 03:22:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/sqrt_mod/main.test.cpp
documentation_of: Mylib/Number/Mod/mod_sqrt.cpp
layout: document
title: Mod sqrt
---

## Operations

- `mod_sqrt(a, p)`
	- $x ^ 2 = a \pmod p$を満たす`x`を求める。

## Requirements

## Notes

## Problems

## References

- [https://ja.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E5%89%B0%E4%BD%99%E3%81%AE%E7%9B%B8%E4%BA%92%E6%B3%95%E5%89%87](https://ja.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E5%89%B0%E4%BD%99%E3%81%AE%E7%9B%B8%E4%BA%92%E6%B3%95%E5%89%87)
- [https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a](https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a)
- [https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm](https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm)
