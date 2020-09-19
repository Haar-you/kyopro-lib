---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/segmented_sieve.cpp\"\n#include <vector>\n\
    #include <cstdint>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ Checker>\n  class segmented_sieve {\n    int L, R, D;\n    std::vector<bool>\
    \ data;\n\n  public:\n    // [l, r]\n    segmented_sieve(int l, int r, Checker\
    \ is_prime):\n      L(l), R(r), D(R - L + 1), data(D, true){\n      std::vector<int>\
    \ primes;\n      for(int64_t i = 2; i * i <= R; ++i){\n        if(is_prime(i))\
    \ primes.push_back(i);\n      }\n\n      for(int64_t i = 0; i < D; ++i){\n   \
    \     const int64_t x = L + i;\n\n        if(x == 1){\n          data[i] = false;\n\
    \          continue;\n        }\n\n        for(auto p : primes){\n          if(x\
    \ == p) break;\n          if(x % p == 0){\n            data[i] = false;\n    \
    \        break;\n          }\n        }\n      }\n    }\n\n    bool operator()(int\
    \ i) const {\n      assert(L <= i and i <= R);\n      return data[i - L];\n  \
    \  }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename Checker>\n  class segmented_sieve\
    \ {\n    int L, R, D;\n    std::vector<bool> data;\n\n  public:\n    // [l, r]\n\
    \    segmented_sieve(int l, int r, Checker is_prime):\n      L(l), R(r), D(R -\
    \ L + 1), data(D, true){\n      std::vector<int> primes;\n      for(int64_t i\
    \ = 2; i * i <= R; ++i){\n        if(is_prime(i)) primes.push_back(i);\n     \
    \ }\n\n      for(int64_t i = 0; i < D; ++i){\n        const int64_t x = L + i;\n\
    \n        if(x == 1){\n          data[i] = false;\n          continue;\n     \
    \   }\n\n        for(auto p : primes){\n          if(x == p) break;\n        \
    \  if(x % p == 0){\n            data[i] = false;\n            break;\n       \
    \   }\n        }\n      }\n    }\n\n    bool operator()(int i) const {\n     \
    \ assert(L <= i and i <= R);\n      return data[i - L];\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/segmented_sieve.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/Prime/segmented_sieve.cpp
layout: document
title: Segmented sieve
---

## Operations

## Requirements

- `Checker`は`sqrt(r)`以下の素数判定が可能である。

## Notes

## Problems

- [SPOJ PRIME1](https://www.spoj.com/problems/PRIME1/)

## References

- [http://www.prefield.com/algorithm/math/segment_sieve.html](http://www.prefield.com/algorithm/math/segment_sieve.html)
