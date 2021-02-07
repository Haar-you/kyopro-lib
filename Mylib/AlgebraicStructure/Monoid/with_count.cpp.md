---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3035/main.test.cpp
    title: test/aoj/3035/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/with_count.cpp\"\n#include\
    \ <utility>\n#include <cstdint>\n\nnamespace haar_lib {\n  namespace with_count_impl\
    \ {\n    template <typename T>\n    struct inner_value {\n      T value;\n   \
    \   int64_t count;\n      inner_value(): value(T()), count(0){}\n      inner_value(T\
    \ value): value(value), count(1){}\n      inner_value(T value, int64_t count):\
    \ value(value), count(count){}\n    };\n  }\n\n  template <typename Monoid>\n\
    \  struct with_count {\n    using value_type = with_count_impl::inner_value<typename\
    \ Monoid::value_type>;\n    const static Monoid M;\n\n    value_type operator()()\
    \ const {\n      return {M(), 0};\n    }\n\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const {\n      if(a.value == b.value) return {a.value,\
    \ a.count + b.count};\n      if(M(a.value, b.value) == a.value) return a;\n  \
    \    return b;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <utility>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  namespace with_count_impl {\n    template <typename T>\n    struct inner_value\
    \ {\n      T value;\n      int64_t count;\n      inner_value(): value(T()), count(0){}\n\
    \      inner_value(T value): value(value), count(1){}\n      inner_value(T value,\
    \ int64_t count): value(value), count(count){}\n    };\n  }\n\n  template <typename\
    \ Monoid>\n  struct with_count {\n    using value_type = with_count_impl::inner_value<typename\
    \ Monoid::value_type>;\n    const static Monoid M;\n\n    value_type operator()()\
    \ const {\n      return {M(), 0};\n    }\n\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const {\n      if(a.value == b.value) return {a.value,\
    \ a.count + b.count};\n      if(M(a.value, b.value) == a.value) return a;\n  \
    \    return b;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/with_count.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:43:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3035/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/with_count.cpp
layout: document
title: With count
---

## Operations

## Requirements

## Notes

## Problems

## References
