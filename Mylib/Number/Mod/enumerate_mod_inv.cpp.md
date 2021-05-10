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
  bundledCode: "#line 2 \"Mylib/Number/Mod/enumerate_mod_inv.cpp\"\n#include <cstdint>\n\
    #include <vector>\n\nnamespace haar_lib {\n  std::vector<int64_t> enumerate_mod_inv(int\
    \ n, int64_t p) {\n    std::vector<int64_t> ret(n + 1);\n\n    ret[1] = 1;\n\n\
    \    for (int i = 2; i <= n; ++i) {\n      ret[i] = (p / i) * (p - ret[p % i])\
    \ % p;\n    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  std::vector<int64_t> enumerate_mod_inv(int n, int64_t p) {\n    std::vector<int64_t>\
    \ ret(n + 1);\n\n    ret[1] = 1;\n\n    for (int i = 2; i <= n; ++i) {\n     \
    \ ret[i] = (p / i) * (p - ret[p % i]) % p;\n    }\n\n    return ret;\n  }\n} \
    \ // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Mod/enumerate_mod_inv.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/Mod/enumerate_mod_inv.cpp
layout: document
title: Enumerate mod inv
---

## Operations

- `enumerate_mod_inv(n, p)`
  - `p` is prime
  - Time complexity $O(n)$

## Requirements

## Notes

## Problems

## References