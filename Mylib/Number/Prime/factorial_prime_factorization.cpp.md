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
  bundledCode: "#line 2 \"Mylib/Number/Prime/factorial_prime_factorization.cpp\"\n\
    #include <cstdint>\n\nnamespace haar_lib {\n  int64_t factorial_prime_factorization(int64_t\
    \ a, int64_t p) {\n    int64_t ret = 0, q = p;\n\n    while (q <= a) {\n     \
    \ int64_t t = a / q;\n\n      ret += t;\n\n      int64_t k;\n      if (__builtin_smulll_overflow(q,\
    \ p, (long long int*) &k)) break;\n\n      q = k;\n    }\n    return ret;\n  }\n\
    }  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  int64_t factorial_prime_factorization(int64_t\
    \ a, int64_t p) {\n    int64_t ret = 0, q = p;\n\n    while (q <= a) {\n     \
    \ int64_t t = a / q;\n\n      ret += t;\n\n      int64_t k;\n      if (__builtin_smulll_overflow(q,\
    \ p, (long long int*) &k)) break;\n\n      q = k;\n    }\n    return ret;\n  }\n\
    }  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/factorial_prime_factorization.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/Prime/factorial_prime_factorization.cpp
layout: document
title: Count number of prime factor p of $a!$
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #589 (Div. 2) C. Primes and Multiplication](https://codeforces.com/contest/1228/problem/C)

## References
