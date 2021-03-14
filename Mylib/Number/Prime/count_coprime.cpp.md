---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Prime/prime_factorize.cpp
    title: Prime factorization
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D/main.test.cpp
    title: test/aoj/NTL_1_D/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/count_coprime.cpp\"\n#include <cstdint>\n\
    #line 2 \"Mylib/Number/Prime/prime_factorize.cpp\"\n#include <vector>\n#include\
    \ <utility>\n#line 5 \"Mylib/Number/Prime/prime_factorize.cpp\"\n\nnamespace haar_lib\
    \ {\n  auto prime_factorize(int64_t n) -> std::vector<std::pair<int64_t, int64_t>>\
    \ {\n    std::vector<std::pair<int64_t, int64_t>> ret;\n    for(int64_t i = 2LL;\
    \ i * i <= n; ++i){\n      if(n % i == 0){\n        int64_t c = 0;\n        while(n\
    \ % i == 0){\n          n /= i;\n          ++c;\n        }\n        ret.emplace_back(i,\
    \ c);\n      }\n    }\n    if(n != 1) ret.emplace_back(n, 1);\n    return ret;\n\
    \  }\n}\n#line 4 \"Mylib/Number/Prime/count_coprime.cpp\"\n\nnamespace haar_lib\
    \ {\n  int64_t count_coprime(int64_t n, int64_t m){\n    const auto p = prime_factorize(m);\n\
    \    const int k = p.size();\n\n    int64_t ret = 0;\n\n    for(int i = 0; i <\
    \ 1 << k; ++i){\n      int64_t s = 1;\n\n      for(int j = 0; j < k; ++j){\n \
    \       if(i & (1 << j)) s *= p[j].first;\n      }\n\n      if(__builtin_popcount(i)\
    \ % 2 == 1) ret -= n / s;\n      else ret += n / s;\n    }\n\n    return ret;\n\
    \  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include \"Mylib/Number/Prime/prime_factorize.cpp\"\
    \n\nnamespace haar_lib {\n  int64_t count_coprime(int64_t n, int64_t m){\n   \
    \ const auto p = prime_factorize(m);\n    const int k = p.size();\n\n    int64_t\
    \ ret = 0;\n\n    for(int i = 0; i < 1 << k; ++i){\n      int64_t s = 1;\n\n \
    \     for(int j = 0; j < k; ++j){\n        if(i & (1 << j)) s *= p[j].first;\n\
    \      }\n\n      if(__builtin_popcount(i) % 2 == 1) ret -= n / s;\n      else\
    \ ret += n / s;\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Number/Prime/prime_factorize.cpp
  isVerificationFile: false
  path: Mylib/Number/Prime/count_coprime.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:56:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_D/main.test.cpp
documentation_of: Mylib/Number/Prime/count_coprime.cpp
layout: document
title: Count coprime
---

## Operations

- `count_coprime(n, m)`
	- `[1, n]`を満たす自然数で`m`と互いに素であるものの個数

## Requirements

## Notes

## Problems

## References
