---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp
    title: test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/sieve_eratosthenes.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  class eratosthenes_sieve {\n    std::vector<bool> is_prime_;\n\
    \n  public:\n    eratosthenes_sieve(){}\n    eratosthenes_sieve(int MAX): is_prime_((MAX\
    \ + 1) / 2, true){\n      is_prime_[0] = false;\n\n      for(int i = 3; i * i\
    \ <= MAX; i += 2){\n        if(not is_prime_[i / 2]) continue;\n\n        for(int\
    \ j = i * i; j <= MAX; j += 2 * i){\n          is_prime_[j / 2] = false;\n   \
    \     }\n      }\n    }\n\n    bool operator()(int i) const {\n      if(i == 2)\
    \ return true;\n      if(i % 2 == 0) return false;\n      return is_prime_[i /\
    \ 2];\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  class eratosthenes_sieve\
    \ {\n    std::vector<bool> is_prime_;\n\n  public:\n    eratosthenes_sieve(){}\n\
    \    eratosthenes_sieve(int MAX): is_prime_((MAX + 1) / 2, true){\n      is_prime_[0]\
    \ = false;\n\n      for(int i = 3; i * i <= MAX; i += 2){\n        if(not is_prime_[i\
    \ / 2]) continue;\n\n        for(int j = i * i; j <= MAX; j += 2 * i){\n     \
    \     is_prime_[j / 2] = false;\n        }\n      }\n    }\n\n    bool operator()(int\
    \ i) const {\n      if(i == 2) return true;\n      if(i % 2 == 0) return false;\n\
    \      return is_prime_[i / 2];\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/sieve_eratosthenes.cpp
  requiredBy: []
  timestamp: '2020-11-05 03:06:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/enumerate_primes/main.eratosthenes.test.cpp
documentation_of: Mylib/Number/Prime/sieve_eratosthenes.cpp
layout: document
title: Sieve of Eratosthenes
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://qiita.com/peria/items/a4ff4ddb3336f7b81d50](https://qiita.com/peria/items/a4ff4ddb3336f7b81d50)
