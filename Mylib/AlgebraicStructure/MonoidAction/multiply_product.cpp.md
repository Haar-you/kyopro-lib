---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp
    title: Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp\"\n#include\
    \ <cstdint>\n\nnamespace haar_lib {\n  template <typename Monoid, typename value_type\
    \ = typename Monoid::value_type>\n  value_type times(value_type a, int64_t p){\n\
    \    Monoid M;\n    auto ret = M.id();\n\n    while(p > 0){\n      if(p & 1) ret\
    \ = M.op(ret, a);\n      a = M.op(a, a);\n      p >>= 1;\n    }\n\n    return\
    \ ret;\n  }\n}\n#line 3 \"Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct multiply_product {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int len) const {\n      return\
    \ a * times<MonoidUpdate>(b, len);\n    }\n  };\n}\n"
  code: "#pragma once\n#include \"Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct multiply_product {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int len) const {\n      return\
    \ a * times<MonoidUpdate>(b, len);\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:43:57+09:00'
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
