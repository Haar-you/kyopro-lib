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
  bundledCode: "#line 2 \"Mylib/Number/pow.cpp\"\n#include <cstdint>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename Monoid, typename value_type = typename\
    \ Monoid::value_type>\n  value_type pow(value_type a, int64_t p){\n    assert(p\
    \ >= 0);\n    const Monoid M;\n    auto ret = M();\n\n    while(p > 0){\n    \
    \  if(p & 1) ret = M(ret, a);\n      a = M(a, a);\n      p >>= 1;\n    }\n\n \
    \   return ret;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename Monoid, typename value_type = typename Monoid::value_type>\n\
    \  value_type pow(value_type a, int64_t p){\n    assert(p >= 0);\n    const Monoid\
    \ M;\n    auto ret = M();\n\n    while(p > 0){\n      if(p & 1) ret = M(ret, a);\n\
    \      a = M(a, a);\n      p >>= 1;\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/pow.cpp
  requiredBy:
  - Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp
  timestamp: '2020-09-27 07:43:10+09:00'
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
