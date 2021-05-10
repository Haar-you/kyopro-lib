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
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Semiring/min_add.cpp\"\n#include\
    \ <algorithm>\n#include <optional>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct min_add_semiring {\n    using value_type = std::optional<T>;\n\n\
    \    value_type id_add() const { return std::nullopt; }\n    value_type id_mul()\
    \ const { return 0; }\n\n    value_type add(const value_type &a, const value_type\
    \ &b) const {\n      if (not a) return b;\n      if (not b) return a;\n      return\
    \ {std::min(*a, *b)};\n    }\n    value_type mul(const value_type &a, const value_type\
    \ &b) const {\n      if (not a or not b) return {};\n      return {*a + *b};\n\
    \    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <optional>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct min_add_semiring {\n    using value_type\
    \ = std::optional<T>;\n\n    value_type id_add() const { return std::nullopt;\
    \ }\n    value_type id_mul() const { return 0; }\n\n    value_type add(const value_type\
    \ &a, const value_type &b) const {\n      if (not a) return b;\n      if (not\
    \ b) return a;\n      return {std::min(*a, *b)};\n    }\n    value_type mul(const\
    \ value_type &a, const value_type &b) const {\n      if (not a or not b) return\
    \ {};\n      return {*a + *b};\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Semiring/min_add.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/AlgebraicStructure/Semiring/min_add.cpp
layout: document
title: Min-add semiring
---

## Operations

## Requirements

## Notes

## Problems

## References