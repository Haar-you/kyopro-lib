---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp
    title: Range multiply / Range product
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/pow.cpp\"\n#include <cstdint>\n\nnamespace\
    \ haar_lib {\n  template <typename Monoid, typename value_type = typename Monoid::value_type>\n\
    \  value_type pow(value_type a, int64_t p){\n    assert(p >= 0);\n    const Monoid\
    \ M;\n    auto ret = M();\n\n    while(p > 0){\n      if(p & 1) ret = M(ret, a);\n\
    \      a = M(a, a);\n      p >>= 1;\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid, typename value_type = typename Monoid::value_type>\n  value_type pow(value_type\
    \ a, int64_t p){\n    assert(p >= 0);\n    const Monoid M;\n    auto ret = M();\n\
    \n    while(p > 0){\n      if(p & 1) ret = M(ret, a);\n      a = M(a, a);\n  \
    \    p >>= 1;\n    }\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/pow.cpp
  requiredBy:
  - Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp
  timestamp: '2020-09-25 04:25:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/pow.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
