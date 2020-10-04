---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Prime/segmented_sieve.cpp\"\n#include <vector>\n\
    #include <cstdint>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ Checker>\n  class segmented_sieve {\n    int L_, R_, D_;\n    std::vector<bool>\
    \ data_;\n\n  public:\n    segmented_sieve(){}\n    segmented_sieve(int l, int\
    \ r, Checker is_prime): // [l, r]\n      L_(l), R_(r), D_(R_ - L_ + 1), data_(D_,\
    \ true){\n      std::vector<int> primes;\n      for(int64_t i = 2; i * i <= R_;\
    \ ++i){\n        if(is_prime(i)) primes.push_back(i);\n      }\n\n      for(int64_t\
    \ i = 0; i < D_; ++i){\n        const int64_t x = L_ + i;\n\n        if(x == 1){\n\
    \          data_[i] = false;\n          continue;\n        }\n\n        for(auto\
    \ p : primes){\n          if(x == p) break;\n          if(x % p == 0){\n     \
    \       data_[i] = false;\n            break;\n          }\n        }\n      }\n\
    \    }\n\n    bool operator()(int i) const {\n      assert(L_ <= i and i <= R_);\n\
    \      return data_[i - L_];\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cstdint>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename Checker>\n  class segmented_sieve\
    \ {\n    int L_, R_, D_;\n    std::vector<bool> data_;\n\n  public:\n    segmented_sieve(){}\n\
    \    segmented_sieve(int l, int r, Checker is_prime): // [l, r]\n      L_(l),\
    \ R_(r), D_(R_ - L_ + 1), data_(D_, true){\n      std::vector<int> primes;\n \
    \     for(int64_t i = 2; i * i <= R_; ++i){\n        if(is_prime(i)) primes.push_back(i);\n\
    \      }\n\n      for(int64_t i = 0; i < D_; ++i){\n        const int64_t x =\
    \ L_ + i;\n\n        if(x == 1){\n          data_[i] = false;\n          continue;\n\
    \        }\n\n        for(auto p : primes){\n          if(x == p) break;\n   \
    \       if(x % p == 0){\n            data_[i] = false;\n            break;\n \
    \         }\n        }\n      }\n    }\n\n    bool operator()(int i) const {\n\
    \      assert(L_ <= i and i <= R_);\n      return data_[i - L_];\n    }\n  };\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Prime/segmented_sieve.cpp
  requiredBy: []
  timestamp: '2020-09-30 02:01:30+09:00'
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
