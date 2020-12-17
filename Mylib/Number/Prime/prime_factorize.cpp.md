---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Prime/count_coprime.cpp
    title: Count coprime
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_A/main.test.cpp
    title: test/aoj/NTL_1_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D/main.test.cpp
    title: test/aoj/NTL_1_D/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/prime_factorize.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <cstdint>\n\nnamespace haar_lib {\n  auto prime_factorize(int64_t\
    \ n){\n    std::vector<std::pair<int64_t, int64_t>> ret;\n    for(int64_t i =\
    \ 2LL; i * i <= n; ++i){\n      if(n % i == 0){\n        int64_t c = 0;\n    \
    \    while(n % i == 0){\n          n /= i;\n          ++c;\n        }\n      \
    \  ret.emplace_back(i, c);\n      }\n    }\n    if(n != 1) ret.emplace_back(n,\
    \ 1);\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  auto prime_factorize(int64_t n){\n    std::vector<std::pair<int64_t,\
    \ int64_t>> ret;\n    for(int64_t i = 2LL; i * i <= n; ++i){\n      if(n % i ==\
    \ 0){\n        int64_t c = 0;\n        while(n % i == 0){\n          n /= i;\n\
    \          ++c;\n        }\n        ret.emplace_back(i, c);\n      }\n    }\n\
    \    if(n != 1) ret.emplace_back(n, 1);\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/prime_factorize.cpp
  requiredBy:
  - Mylib/Number/Prime/count_coprime.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_D/main.test.cpp
  - test/aoj/NTL_1_A/main.test.cpp
documentation_of: Mylib/Number/Prime/prime_factorize.cpp
layout: document
title: Prime factorization
---

## Operations

## Requirements

## Notes

## Problems

## References
