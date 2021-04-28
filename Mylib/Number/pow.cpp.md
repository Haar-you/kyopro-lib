---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp
    title: Range multiply / Range product
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/pow.cpp\"\n#include <cassert>\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  template <typename Monoid, typename value_type = typename\
    \ Monoid::value_type>\n  value_type pow(value_type a, int64_t p) {\n    assert(p\
    \ >= 0);\n    const Monoid M;\n    auto ret = M();\n\n    while (p > 0) {\n  \
    \    if (p & 1) ret = M(ret, a);\n      a = M(a, a);\n      p >>= 1;\n    }\n\n\
    \    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  template <typename Monoid, typename value_type = typename Monoid::value_type>\n\
    \  value_type pow(value_type a, int64_t p) {\n    assert(p >= 0);\n    const Monoid\
    \ M;\n    auto ret = M();\n\n    while (p > 0) {\n      if (p & 1) ret = M(ret,\
    \ a);\n      a = M(a, a);\n      p >>= 1;\n    }\n\n    return ret;\n  }\n}  //\
    \ namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/pow.cpp
  requiredBy:
  - Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/pow.cpp
layout: document
title: Binary exponentiation
---

## Operations

## Requirements

## Notes

## Problems

## References
