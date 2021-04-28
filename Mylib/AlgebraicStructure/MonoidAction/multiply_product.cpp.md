---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Mylib/Number/pow.cpp
    title: Binary exponentiation
  _extendedRequiredBy: []
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
    \    return ret;\n  }\n}  // namespace haar_lib\n#line 3 \"Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidUpdate, typename MonoidGet>\n\
    \  struct multiply_product {\n    using monoid_get        = MonoidGet;\n    using\
    \ monoid_update     = MonoidUpdate;\n    using value_type_get    = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int len) const {\n      return\
    \ a * pow<MonoidUpdate>(b, len);\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include \"Mylib/Number/pow.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename MonoidUpdate, typename MonoidGet>\n  struct multiply_product\
    \ {\n    using monoid_get        = MonoidGet;\n    using monoid_update     = MonoidUpdate;\n\
    \    using value_type_get    = typename MonoidGet::value_type;\n    using value_type_update\
    \ = typename MonoidUpdate::value_type;\n\n    value_type_get operator()(value_type_get\
    \ a, value_type_update b, int len) const {\n      return a * pow<MonoidUpdate>(b,\
    \ len);\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Number/pow.cpp
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp
layout: document
title: Range multiply / Range product
---

## Operations

## Requirements

## Notes

## Problems

## References
