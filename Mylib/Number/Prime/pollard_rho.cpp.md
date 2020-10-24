---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Misc/int128.cpp
    title: 128-bit int
  - icon: ':question:'
    path: Mylib/Number/Prime/miller_rabin.cpp
    title: Primality test (Miller-Rabin algorithm)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/factorize/main.test.cpp
    title: test/yosupo-judge/factorize/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/pollard_rho.cpp\"\n#include <optional>\n\
    #include <vector>\n#include <utility>\n#include <numeric>\n#include <algorithm>\n\
    #include <cassert>\n#line 2 \"Mylib/Misc/int128.cpp\"\n\nnamespace haar_lib {\n\
    #ifdef __SIZEOF_INT128__\n  using uint128_t = __uint128_t;\n  using int128_t =\
    \ __int128_t;\n#else\n#include <boost/multiprecision/cpp_int.hpp>\n  using uint128_t\
    \ = boost::multiprecision::uint128_t;\n  using int128_t = boost::multiprecision::int128_t;\n\
    #endif\n}\n#line 2 \"Mylib/Number/Prime/miller_rabin.cpp\"\n#include <cstdint>\n\
    #include <initializer_list>\n#line 5 \"Mylib/Number/Prime/miller_rabin.cpp\"\n\
    \nnamespace haar_lib {\n  namespace miller_rabin_impl {\n    uint128_t power(uint128_t\
    \ a, uint128_t b, uint128_t p){\n      uint128_t ret = 1;\n\n      while(b > 0){\n\
    \        if(b & 1) ret = ret * a % p;\n        a = a * a % p;\n        b >>= 1;\n\
    \      }\n\n      return ret;\n    }\n\n    bool is_composite(uint64_t a, uint64_t\
    \ p, int s, uint64_t d){\n      uint128_t x = power(a, d, p);\n\n      if(x ==\
    \ 1) return false;\n\n      for(int i = 0; i < s; ++i){\n        if(x == p - 1)\
    \ return false;\n        x = x * x % p;\n      }\n\n      return true;\n    }\n\
    \  }\n\n  bool miller_rabin(uint64_t n){\n    if(n <= 1) return false;\n    if(n\
    \ == 2) return true;\n    if(n % 2 == 0) return false;\n\n    int s = 0;\n   \
    \ uint64_t d = n - 1;\n    while((d & 1) == 0){\n      s += 1;\n      d >>= 1;\n\
    \    }\n\n    if(n < 4759123141){\n      for(uint64_t x : {2, 7, 61}){\n     \
    \   if(x < n and miller_rabin_impl::is_composite(x, n, s, d)) return false;\n\
    \      }\n\n      return true;\n    }\n\n    for(uint64_t x : {2, 3, 5, 7, 11,\
    \ 13, 17, 19, 23, 29, 31, 37}){\n      if(x < n and miller_rabin_impl::is_composite(x,\
    \ n, s, d)) return false;\n    }\n\n    return true;\n  }\n}\n#line 10 \"Mylib/Number/Prime/pollard_rho.cpp\"\
    \n\nnamespace haar_lib {\n  namespace pollard_rho_impl {\n    int128_t f(int128_t\
    \ x){\n      return x * x + 1;\n    }\n\n    std::optional<int64_t> rho(int64_t\
    \ n){\n      int64_t x = 2, y = 2, d = 1;\n\n      while(d == 1){\n        x =\
    \ f(x) % n;\n        y = f(f(y) % n) % n;\n        d = std::gcd(std::abs(x - y),\
    \ n);\n        if(d == n) return {};\n      }\n\n      return {d};\n    }\n  }\n\
    \n  auto pollard_rho(int64_t n){\n    std::vector<std::pair<int64_t, int64_t>>\
    \ ret;\n\n    for(int i = 2; i <= 1000000; ++i){\n      if(n % i == 0){\n    \
    \    int c = 0;\n        while(n % i == 0){\n          n /= i;\n          ++c;\n\
    \        }\n        ret.emplace_back(i, c);\n      }\n      if(i > n) break;\n\
    \    }\n\n    while(n > 1){\n      if(miller_rabin(n)){\n        ret.emplace_back(n,\
    \ 1);\n        break;\n      }\n\n      auto res = pollard_rho_impl::rho(n);\n\
    \      if(not res){\n        assert(false);\n      }\n\n      auto r = *res;\n\
    \      if(r == 1) break;\n\n      int c = 0;\n      while(n % r == 0){\n     \
    \   n /= r;\n        ++c;\n      }\n\n      ret.emplace_back(r, c);\n    }\n\n\
    \    std::sort(ret.begin(), ret.end());\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <optional>\n#include <vector>\n#include <utility>\n\
    #include <numeric>\n#include <algorithm>\n#include <cassert>\n#include \"Mylib/Misc/int128.cpp\"\
    \n#include \"Mylib/Number/Prime/miller_rabin.cpp\"\n\nnamespace haar_lib {\n \
    \ namespace pollard_rho_impl {\n    int128_t f(int128_t x){\n      return x *\
    \ x + 1;\n    }\n\n    std::optional<int64_t> rho(int64_t n){\n      int64_t x\
    \ = 2, y = 2, d = 1;\n\n      while(d == 1){\n        x = f(x) % n;\n        y\
    \ = f(f(y) % n) % n;\n        d = std::gcd(std::abs(x - y), n);\n        if(d\
    \ == n) return {};\n      }\n\n      return {d};\n    }\n  }\n\n  auto pollard_rho(int64_t\
    \ n){\n    std::vector<std::pair<int64_t, int64_t>> ret;\n\n    for(int i = 2;\
    \ i <= 1000000; ++i){\n      if(n % i == 0){\n        int c = 0;\n        while(n\
    \ % i == 0){\n          n /= i;\n          ++c;\n        }\n        ret.emplace_back(i,\
    \ c);\n      }\n      if(i > n) break;\n    }\n\n    while(n > 1){\n      if(miller_rabin(n)){\n\
    \        ret.emplace_back(n, 1);\n        break;\n      }\n\n      auto res =\
    \ pollard_rho_impl::rho(n);\n      if(not res){\n        assert(false);\n    \
    \  }\n\n      auto r = *res;\n      if(r == 1) break;\n\n      int c = 0;\n  \
    \    while(n % r == 0){\n        n /= r;\n        ++c;\n      }\n\n      ret.emplace_back(r,\
    \ c);\n    }\n\n    std::sort(ret.begin(), ret.end());\n\n    return ret;\n  }\n\
    }\n"
  dependsOn:
  - Mylib/Misc/int128.cpp
  - Mylib/Number/Prime/miller_rabin.cpp
  isVerificationFile: false
  path: Mylib/Number/Prime/pollard_rho.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/factorize/main.test.cpp
documentation_of: Mylib/Number/Prime/pollard_rho.cpp
layout: document
title: Prime factorization (Pollard's rho algorithm)
---

## Operations

## Requirements

## Notes

## Problems

## References
