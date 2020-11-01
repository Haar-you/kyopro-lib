---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mod/mod_inv.cpp
    title: Mod inverse
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
    title: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mod/mod_log.cpp\"\n#include <unordered_map>\n\
    #include <optional>\n#include <numeric>\n#include <cmath>\n#line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  constexpr int64_t mod_pow(int64_t\
    \ n, int64_t p, int64_t m){\n    int64_t ret = 1;\n    while(p > 0){\n      if(p\
    \ & 1) (ret *= n) %= m;\n      (n *= n) %= m;\n      p >>= 1;\n    }\n    return\
    \ ret;\n  }\n}\n#line 2 \"Mylib/Number/Mod/mod_inv.cpp\"\n#include <utility>\n\
    #line 4 \"Mylib/Number/Mod/mod_inv.cpp\"\n\nnamespace haar_lib {\n  int64_t mod_inv(int64_t\
    \ a, int64_t m){\n    int64_t b = m, u = 1, v = 0;\n\n    while(b){\n      int64_t\
    \ t = a / b;\n      a -= t * b; std::swap(a, b);\n      u -= t * v; std::swap(u,\
    \ v);\n    }\n\n    u %= m;\n    if(u < 0) u += m;\n\n    return u;\n  }\n}\n\
    #line 8 \"Mylib/Number/Mod/mod_log.cpp\"\n\nnamespace haar_lib {\n  std::optional<int64_t>\
    \ mod_log(int64_t a, int64_t b, int64_t m){\n    if(b == 1) return 0;\n\n    int64_t\
    \ d = 0;\n\n    while(1){\n      if(auto g = std::gcd(a, m); g != 1){\n      \
    \  if(b % g != 0) return {};\n\n        d += 1;\n        m /= g;\n        b /=\
    \ g;\n        (b *= mod_inv(a / g, m)) %= m;\n\n        if(b == 1) return d;\n\
    \      }else{\n        break;\n      }\n    }\n\n    const int64_t sq = std::sqrt(m)\
    \ + 1;\n\n    std::unordered_map<int64_t, int64_t> mp;\n    {\n      int64_t t\
    \ = 1 % m;\n\n      for(int i = 0; i < sq; ++i){\n        if(mp.find(t) == mp.end())\
    \ mp[t] = i;\n        (t *= a) %= m;\n      }\n    }\n\n    {\n      int64_t A\
    \ = mod_pow(mod_inv(a, m), sq, m);\n      int64_t t = b % m;\n\n      for(int\
    \ i = 0; i < sq; ++i){\n        if(mp.find(t) != mp.end()){\n          int64_t\
    \ ret = i * sq + mp[t] + d;\n\n          return ret;\n        }\n\n        (t\
    \ *= A) %= m;\n      }\n    }\n\n    return {};\n  }\n}\n"
  code: "#pragma once\n#include <unordered_map>\n#include <optional>\n#include <numeric>\n\
    #include <cmath>\n#include \"Mylib/Number/Mod/mod_pow.cpp\"\n#include \"Mylib/Number/Mod/mod_inv.cpp\"\
    \n\nnamespace haar_lib {\n  std::optional<int64_t> mod_log(int64_t a, int64_t\
    \ b, int64_t m){\n    if(b == 1) return 0;\n\n    int64_t d = 0;\n\n    while(1){\n\
    \      if(auto g = std::gcd(a, m); g != 1){\n        if(b % g != 0) return {};\n\
    \n        d += 1;\n        m /= g;\n        b /= g;\n        (b *= mod_inv(a /\
    \ g, m)) %= m;\n\n        if(b == 1) return d;\n      }else{\n        break;\n\
    \      }\n    }\n\n    const int64_t sq = std::sqrt(m) + 1;\n\n    std::unordered_map<int64_t,\
    \ int64_t> mp;\n    {\n      int64_t t = 1 % m;\n\n      for(int i = 0; i < sq;\
    \ ++i){\n        if(mp.find(t) == mp.end()) mp[t] = i;\n        (t *= a) %= m;\n\
    \      }\n    }\n\n    {\n      int64_t A = mod_pow(mod_inv(a, m), sq, m);\n \
    \     int64_t t = b % m;\n\n      for(int i = 0; i < sq; ++i){\n        if(mp.find(t)\
    \ != mp.end()){\n          int64_t ret = i * sq + mp[t] + d;\n\n          return\
    \ ret;\n        }\n\n        (t *= A) %= m;\n      }\n    }\n\n    return {};\n\
    \  }\n}\n"
  dependsOn:
  - Mylib/Number/Mod/mod_pow.cpp
  - Mylib/Number/Mod/mod_inv.cpp
  isVerificationFile: false
  path: Mylib/Number/Mod/mod_log.cpp
  requiredBy: []
  timestamp: '2020-10-28 03:22:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
documentation_of: Mylib/Number/Mod/mod_log.cpp
layout: document
title: Mod logarithm
---

## Operations

- `mod_log(a, b, n)`
	- $a^x = b \pmod m$を満たす`x`を求める。
	- Time complexity $O(\sqrt m)$

## Requirements

## Notes

## Problems

## References
