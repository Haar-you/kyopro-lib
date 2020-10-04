---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Misc/int128.cpp
    title: 128-bit int
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Number/Prime/pollard_rho.cpp
    title: Prime factorization (Pollard's rho algorithm)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/factorize/main.test.cpp
    title: test/yosupo-judge/factorize/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/3030/main.test.cpp
    title: test/yukicoder/3030/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/miller_rabin.cpp\"\n#include <cstdint>\n\
    #include <initializer_list>\n#line 2 \"Mylib/Misc/int128.cpp\"\n\nnamespace haar_lib\
    \ {\n#ifdef __SIZEOF_INT128__\n  using uint128_t = __uint128_t;\n  using int128_t\
    \ = __int128_t;\n#else\n#include <boost/multiprecision/cpp_int.hpp>\n  using uint128_t\
    \ = boost::multiprecision::uint128_t;\n  using int128_t = boost::multiprecision::int128_t;\n\
    #endif\n}\n#line 5 \"Mylib/Number/Prime/miller_rabin.cpp\"\n\nnamespace haar_lib\
    \ {\n  namespace miller_rabin_impl {\n    uint128_t power(uint128_t a, uint128_t\
    \ b, uint128_t p){\n      uint128_t ret = 1;\n\n      while(b > 0){\n        if(b\
    \ & 1) ret = ret * a % p;\n        a = a * a % p;\n        b >>= 1;\n      }\n\
    \n      return ret;\n    }\n\n    bool is_composite(uint64_t a, uint64_t p, int\
    \ s, uint64_t d){\n      uint128_t x = power(a, d, p);\n\n      if(x == 1) return\
    \ false;\n\n      for(int i = 0; i < s; ++i){\n        if(x == p - 1) return false;\n\
    \        x = x * x % p;\n      }\n\n      return true;\n    }\n  }\n\n  bool miller_rabin(uint64_t\
    \ n){\n    if(n <= 1) return false;\n    if(n == 2) return true;\n    if(n % 2\
    \ == 0) return false;\n\n    int s = 0;\n    uint64_t d = n - 1;\n    while((d\
    \ & 1) == 0){\n      s += 1;\n      d >>= 1;\n    }\n\n    if(n < 4759123141){\n\
    \      for(uint64_t x : {2, 7, 61}){\n        if(x < n and miller_rabin_impl::is_composite(x,\
    \ n, s, d)) return false;\n      }\n\n      return true;\n    }\n\n    for(uint64_t\
    \ x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){\n      if(x < n and miller_rabin_impl::is_composite(x,\
    \ n, s, d)) return false;\n    }\n\n    return true;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <initializer_list>\n#include \"\
    Mylib/Misc/int128.cpp\"\n\nnamespace haar_lib {\n  namespace miller_rabin_impl\
    \ {\n    uint128_t power(uint128_t a, uint128_t b, uint128_t p){\n      uint128_t\
    \ ret = 1;\n\n      while(b > 0){\n        if(b & 1) ret = ret * a % p;\n    \
    \    a = a * a % p;\n        b >>= 1;\n      }\n\n      return ret;\n    }\n\n\
    \    bool is_composite(uint64_t a, uint64_t p, int s, uint64_t d){\n      uint128_t\
    \ x = power(a, d, p);\n\n      if(x == 1) return false;\n\n      for(int i = 0;\
    \ i < s; ++i){\n        if(x == p - 1) return false;\n        x = x * x % p;\n\
    \      }\n\n      return true;\n    }\n  }\n\n  bool miller_rabin(uint64_t n){\n\
    \    if(n <= 1) return false;\n    if(n == 2) return true;\n    if(n % 2 == 0)\
    \ return false;\n\n    int s = 0;\n    uint64_t d = n - 1;\n    while((d & 1)\
    \ == 0){\n      s += 1;\n      d >>= 1;\n    }\n\n    if(n < 4759123141){\n  \
    \    for(uint64_t x : {2, 7, 61}){\n        if(x < n and miller_rabin_impl::is_composite(x,\
    \ n, s, d)) return false;\n      }\n\n      return true;\n    }\n\n    for(uint64_t\
    \ x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){\n      if(x < n and miller_rabin_impl::is_composite(x,\
    \ n, s, d)) return false;\n    }\n\n    return true;\n  }\n}\n"
  dependsOn:
  - Mylib/Misc/int128.cpp
  isVerificationFile: false
  path: Mylib/Number/Prime/miller_rabin.cpp
  requiredBy:
  - Mylib/Number/Prime/pollard_rho.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/factorize/main.test.cpp
  - test/yukicoder/3030/main.test.cpp
documentation_of: Mylib/Number/Prime/miller_rabin.cpp
layout: document
title: Primality test (Miller-Rabin algorithm)
---

## Operations

## Requirements

## Notes

## Problems

## References
