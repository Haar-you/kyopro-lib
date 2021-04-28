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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/with_max_index.cpp\"\n#include\
    \ <algorithm>\n#include <limits>\n#include <utility>\n\nnamespace haar_lib {\n\
    \  namespace with_max_index_impl {\n    template <typename T>\n    struct value_index\
    \ {\n      T value;\n      int index;\n      value_index() {}\n      value_index(T\
    \ value, int index) : value(value), index(index) {}\n    };\n  }  // namespace\
    \ with_max_index_impl\n\n  template <typename Monoid>\n  struct with_max_index\
    \ {\n    using value_type = with_max_index_impl::value_index<typename Monoid::value_type>;\n\
    \    const static Monoid M;\n\n    value_type operator()() const {\n      return\
    \ {M(), 0};\n    }\n\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if (a.value == b.value) return {a.value, std::max(a.index,\
    \ b.index)};\n      if (M(a.value, b.value) == a.value)\n        return a;\n \
    \     else\n        return b;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <utility>\n\
    \nnamespace haar_lib {\n  namespace with_max_index_impl {\n    template <typename\
    \ T>\n    struct value_index {\n      T value;\n      int index;\n      value_index()\
    \ {}\n      value_index(T value, int index) : value(value), index(index) {}\n\
    \    };\n  }  // namespace with_max_index_impl\n\n  template <typename Monoid>\n\
    \  struct with_max_index {\n    using value_type = with_max_index_impl::value_index<typename\
    \ Monoid::value_type>;\n    const static Monoid M;\n\n    value_type operator()()\
    \ const {\n      return {M(), 0};\n    }\n\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const {\n      if (a.value == b.value) return {a.value,\
    \ std::max(a.index, b.index)};\n      if (M(a.value, b.value) == a.value)\n  \
    \      return a;\n      else\n        return b;\n    }\n  };\n}  // namespace\
    \ haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/with_max_index.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Monoid/with_max_index.cpp
layout: document
title: With max index
---

## Operations

## Requirements

## Notes

## Problems

## References
