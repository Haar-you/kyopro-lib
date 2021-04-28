---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3035/main.test.cpp
    title: test/aoj/3035/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/with_count.cpp\"\n#include\
    \ <cstdint>\n#include <utility>\n\nnamespace haar_lib {\n  namespace with_count_impl\
    \ {\n    template <typename T>\n    struct internal_value {\n      T value;\n\
    \      int64_t count;\n      internal_value() : value(T()), count(0) {}\n    \
    \  internal_value(T value) : value(value), count(1) {}\n      internal_value(T\
    \ value, int64_t count) : value(value), count(count) {}\n    };\n  }  // namespace\
    \ with_count_impl\n\n  template <typename Monoid>\n  struct with_count {\n   \
    \ using value_type = with_count_impl::internal_value<typename Monoid::value_type>;\n\
    \    const static Monoid M;\n\n    value_type operator()() const {\n      return\
    \ {M(), 0};\n    }\n\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if (a.value == b.value) return {a.value, a.count + b.count};\n\
    \      if (M(a.value, b.value) == a.value) return a;\n      return b;\n    }\n\
    \  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  namespace with_count_impl {\n    template <typename T>\n    struct internal_value\
    \ {\n      T value;\n      int64_t count;\n      internal_value() : value(T()),\
    \ count(0) {}\n      internal_value(T value) : value(value), count(1) {}\n   \
    \   internal_value(T value, int64_t count) : value(value), count(count) {}\n \
    \   };\n  }  // namespace with_count_impl\n\n  template <typename Monoid>\n  struct\
    \ with_count {\n    using value_type = with_count_impl::internal_value<typename\
    \ Monoid::value_type>;\n    const static Monoid M;\n\n    value_type operator()()\
    \ const {\n      return {M(), 0};\n    }\n\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const {\n      if (a.value == b.value) return {a.value,\
    \ a.count + b.count};\n      if (M(a.value, b.value) == a.value) return a;\n \
    \     return b;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/with_count.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
