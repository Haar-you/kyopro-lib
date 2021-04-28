---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/875/main.test.cpp
    title: test/yukicoder/875/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/with_min_index.cpp\"\n#include\
    \ <algorithm>\n#include <limits>\n#include <utility>\n\nnamespace haar_lib {\n\
    \  namespace with_min_index_impl {\n    template <typename T>\n    struct value_index\
    \ {\n      T value;\n      int index;\n      value_index() {}\n      value_index(T\
    \ value, int index) : value(value), index(index) {}\n    };\n  }  // namespace\
    \ with_min_index_impl\n\n  template <typename Monoid>\n  struct with_min_index\
    \ {\n    using value_type = with_min_index_impl::value_index<typename Monoid::value_type>;\n\
    \    const static Monoid M;\n\n    value_type operator()() const {\n      return\
    \ {M(), std::numeric_limits<int>::max()};\n    }\n\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      if (a.value == b.value) return\
    \ {a.value, std::min(a.index, b.index)};\n      if (M(a.value, b.value) == a.value)\n\
    \        return a;\n      else\n        return b;\n    }\n  };\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <utility>\n\
    \nnamespace haar_lib {\n  namespace with_min_index_impl {\n    template <typename\
    \ T>\n    struct value_index {\n      T value;\n      int index;\n      value_index()\
    \ {}\n      value_index(T value, int index) : value(value), index(index) {}\n\
    \    };\n  }  // namespace with_min_index_impl\n\n  template <typename Monoid>\n\
    \  struct with_min_index {\n    using value_type = with_min_index_impl::value_index<typename\
    \ Monoid::value_type>;\n    const static Monoid M;\n\n    value_type operator()()\
    \ const {\n      return {M(), std::numeric_limits<int>::max()};\n    }\n\n   \
    \ value_type operator()(const value_type &a, const value_type &b) const {\n  \
    \    if (a.value == b.value) return {a.value, std::min(a.index, b.index)};\n \
    \     if (M(a.value, b.value) == a.value)\n        return a;\n      else\n   \
    \     return b;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/with_min_index.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/875/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/with_min_index.cpp
layout: document
title: With min index
---

## Operations

## Requirements

## Notes

## Problems

## References
