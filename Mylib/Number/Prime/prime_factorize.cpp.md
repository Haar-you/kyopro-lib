---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/Number/Prime/count_coprime.cpp
    title: Count coprime
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_A/main.test.cpp
    title: test/aoj/NTL_1_A/main.test.cpp
  - icon: ':x:'
    path: test/aoj/NTL_1_D/main.test.cpp
    title: test/aoj/NTL_1_D/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/prime_factorize.cpp\"\n#include <cstdint>\n\
    #include <utility>\n#include <vector>\n\nnamespace haar_lib {\n  auto prime_factorize(int64_t\
    \ n) -> std::vector<std::pair<int64_t, int64_t>> {\n    std::vector<std::pair<int64_t,\
    \ int64_t>> ret;\n    for (int64_t i = 2LL; i * i <= n; ++i) {\n      if (n %\
    \ i == 0) {\n        int64_t c = 0;\n        while (n % i == 0) {\n          n\
    \ /= i;\n          ++c;\n        }\n        ret.emplace_back(i, c);\n      }\n\
    \    }\n    if (n != 1) ret.emplace_back(n, 1);\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n#include <utility>\n#include <vector>\n\
    \nnamespace haar_lib {\n  auto prime_factorize(int64_t n) -> std::vector<std::pair<int64_t,\
    \ int64_t>> {\n    std::vector<std::pair<int64_t, int64_t>> ret;\n    for (int64_t\
    \ i = 2LL; i * i <= n; ++i) {\n      if (n % i == 0) {\n        int64_t c = 0;\n\
    \        while (n % i == 0) {\n          n /= i;\n          ++c;\n        }\n\
    \        ret.emplace_back(i, c);\n      }\n    }\n    if (n != 1) ret.emplace_back(n,\
    \ 1);\n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/prime_factorize.cpp
  requiredBy:
  - Mylib/Number/Prime/count_coprime.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/NTL_1_A/main.test.cpp
  - test/aoj/NTL_1_D/main.test.cpp
documentation_of: Mylib/Number/Prime/prime_factorize.cpp
layout: document
title: Prime factorization
---

## Operations

## Requirements

## Notes

## Problems

## References
