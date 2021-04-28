---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/enumerate_primes/main.atkin.test.cpp
    title: test/yosupo-judge/enumerate_primes/main.atkin.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/sieve_atkin.cpp\"\n#include <cstdint>\n\
    #include <vector>\n\nnamespace haar_lib {\n  class atkin_sieve {\n    std::vector<bool>\
    \ is_prime_;\n\n  public:\n    atkin_sieve() {}\n    atkin_sieve(int MAX) : is_prime_(MAX\
    \ + 1) {\n      for (int64_t i = 1; i * i <= MAX; ++i) {\n        for (int64_t\
    \ j = 1; j * j <= MAX; ++j) {\n          {\n            auto n = 4LL * i * i +\
    \ j * j;\n            if (n <= MAX and (n % 12 == 1 or n % 12 == 5)) {\n     \
    \         is_prime_[n] = not is_prime_[n];\n            }\n          }\n     \
    \     {\n            auto n = 3LL * i * i + j * j;\n            if (n <= MAX and\
    \ n % 12 == 7) {\n              is_prime_[n] = not is_prime_[n];\n           \
    \ }\n          }\n          if (i > j) {\n            auto n = 3LL * i * i - j\
    \ * j;\n            if (n <= MAX and n % 12 == 11) {\n              is_prime_[n]\
    \ = not is_prime_[n];\n            }\n          }\n        }\n      }\n\n    \
    \  for (int64_t i = 5; i * i <= MAX; ++i) {\n        if (is_prime_[i]) {\n   \
    \       for (int64_t k = i * i, j = k; j <= MAX; j += k) {\n            is_prime_[j]\
    \ = false;\n          }\n        }\n      }\n\n      is_prime_[2] = is_prime_[3]\
    \ = true;\n    }\n\n    bool operator()(int i) const {\n      return is_prime_[i];\n\
    \    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  class atkin_sieve {\n    std::vector<bool> is_prime_;\n\n  public:\n  \
    \  atkin_sieve() {}\n    atkin_sieve(int MAX) : is_prime_(MAX + 1) {\n      for\
    \ (int64_t i = 1; i * i <= MAX; ++i) {\n        for (int64_t j = 1; j * j <= MAX;\
    \ ++j) {\n          {\n            auto n = 4LL * i * i + j * j;\n           \
    \ if (n <= MAX and (n % 12 == 1 or n % 12 == 5)) {\n              is_prime_[n]\
    \ = not is_prime_[n];\n            }\n          }\n          {\n            auto\
    \ n = 3LL * i * i + j * j;\n            if (n <= MAX and n % 12 == 7) {\n    \
    \          is_prime_[n] = not is_prime_[n];\n            }\n          }\n    \
    \      if (i > j) {\n            auto n = 3LL * i * i - j * j;\n            if\
    \ (n <= MAX and n % 12 == 11) {\n              is_prime_[n] = not is_prime_[n];\n\
    \            }\n          }\n        }\n      }\n\n      for (int64_t i = 5; i\
    \ * i <= MAX; ++i) {\n        if (is_prime_[i]) {\n          for (int64_t k =\
    \ i * i, j = k; j <= MAX; j += k) {\n            is_prime_[j] = false;\n     \
    \     }\n        }\n      }\n\n      is_prime_[2] = is_prime_[3] = true;\n   \
    \ }\n\n    bool operator()(int i) const {\n      return is_prime_[i];\n    }\n\
    \  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/sieve_atkin.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/enumerate_primes/main.atkin.test.cpp
documentation_of: Mylib/Number/Prime/sieve_atkin.cpp
layout: document
title: Sieve of Atkin
---

## Operations

## Requirements

## Notes

## Problems

## References
