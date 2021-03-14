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
  bundledCode: "#line 2 \"Mylib/Number/Prime/prime_factorize_sieve.cpp\"\n#include\
    \ <vector>\n#include <cstdint>\n\nnamespace haar_lib {\n  class prime_factorize_sieve\
    \ {\n    std::vector<int> p_;\n\n  public:\n    prime_factorize_sieve(){}\n  \
    \  prime_factorize_sieve(int N): p_(N + 1){\n      for(int i = 2; i <= N; ++i){\n\
    \        if(p_[i] != 0) continue;\n        for(int j = i; j <= N; j += i){\n \
    \         if(p_[j] == 0) p_[j] = i;\n        }\n      }\n    }\n\n    std::vector<int64_t>\
    \ factorize(int N) const {\n      std::vector<int64_t> ret;\n\n      while(N >\
    \ 1){\n        ret.push_back(p_[N]);\n        N /= p_[N];\n      }\n\n      return\
    \ ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  class prime_factorize_sieve {\n    std::vector<int> p_;\n\n  public:\n\
    \    prime_factorize_sieve(){}\n    prime_factorize_sieve(int N): p_(N + 1){\n\
    \      for(int i = 2; i <= N; ++i){\n        if(p_[i] != 0) continue;\n      \
    \  for(int j = i; j <= N; j += i){\n          if(p_[j] == 0) p_[j] = i;\n    \
    \    }\n      }\n    }\n\n    std::vector<int64_t> factorize(int N) const {\n\
    \      std::vector<int64_t> ret;\n\n      while(N > 1){\n        ret.push_back(p_[N]);\n\
    \        N /= p_[N];\n      }\n\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/prime_factorize_sieve.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:56:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/Prime/prime_factorize_sieve.cpp
layout: document
title: Prime factorization (Sieve)
---

## Operations

- `PrimeFactorize(int N)`
	- `p[i]` = (`i`の最小の素因数)
	- Time complexity $O(N log N)$

- `factorize(int N)`
	- `N`の素因数を昇順に列挙する。
	- 素因数の個数だけループが回る。

## Requirements

## Notes

## Problems

## References
