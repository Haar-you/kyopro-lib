---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/843/main.eratosthenes.test.cpp
    title: test/yukicoder/843/main.eratosthenes.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/eratosthenes_sieve.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  class eratosthenes_sieve {\n    std::vector<bool> is_prime_;\n\
    \n  public:\n    eratosthenes_sieve(){}\n    eratosthenes_sieve(int MAX): is_prime_(MAX\
    \ + 1){\n      is_prime_.flip();\n      is_prime_[0] = is_prime_[1] = false;\n\
    \n      for(int i = 2; i <= MAX; ++i){\n        if(is_prime_[i]){\n          for(int\
    \ j = 2 * i; j <= MAX; j += i){\n            is_prime_[j] = false;\n         \
    \ }\n        }\n      }\n    }\n\n    bool operator()(int i) const {\n      return\
    \ is_prime_[i];\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  class eratosthenes_sieve\
    \ {\n    std::vector<bool> is_prime_;\n\n  public:\n    eratosthenes_sieve(){}\n\
    \    eratosthenes_sieve(int MAX): is_prime_(MAX + 1){\n      is_prime_.flip();\n\
    \      is_prime_[0] = is_prime_[1] = false;\n\n      for(int i = 2; i <= MAX;\
    \ ++i){\n        if(is_prime_[i]){\n          for(int j = 2 * i; j <= MAX; j +=\
    \ i){\n            is_prime_[j] = false;\n          }\n        }\n      }\n  \
    \  }\n\n    bool operator()(int i) const {\n      return is_prime_[i];\n    }\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/eratosthenes_sieve.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/843/main.eratosthenes.test.cpp
documentation_of: Mylib/Number/Prime/eratosthenes_sieve.cpp
layout: document
title: Sieve of Eratosthenes
---

## Operations

## Requirements

## Notes

## Problems

## References
