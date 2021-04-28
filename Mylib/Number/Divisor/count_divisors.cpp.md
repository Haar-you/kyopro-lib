---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Divisor/count_divisors.cpp\"\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  constexpr int count_divisors(int64_t n) {\n    int count\
    \ = 0;\n    for (int64_t i = 1LL; i * i <= n; ++i) {\n      if (n % i == 0) {\n\
    \        count += 2;\n        if (i * i == n) count -= 1;\n      }\n    }\n  \
    \  return count;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  constexpr int\
    \ count_divisors(int64_t n) {\n    int count = 0;\n    for (int64_t i = 1LL; i\
    \ * i <= n; ++i) {\n      if (n % i == 0) {\n        count += 2;\n        if (i\
    \ * i == n) count -= 1;\n      }\n    }\n    return count;\n  }\n}  // namespace\
    \ haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Divisor/count_divisors.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/Divisor/count_divisors.cpp
layout: document
title: Count divisors
---

## Operations

## Requirements

## Notes

## Problems

## References
