---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3035/main.test.cpp
    title: test/aoj/3035/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1030/main.test.cpp
    title: test/yukicoder/1030/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/631/main.test.cpp
    title: test/yukicoder/631/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/max.cpp\"\n#include <algorithm>\n\
    #include <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ max_monoid {\n    using value_type = std::optional<T>;\n\n    value_type operator()()\
    \ const {return {};}\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if(not a) return b;\n      if(not b) return a;\n      return\
    \ {std::max(*a, *b)};\n    }\n  };\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <optional>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct max_monoid {\n    using value_type = std::optional<T>;\n\
    \n    value_type operator()() const {return {};}\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      if(not a) return b;\n   \
    \   if(not b) return a;\n      return {std::max(*a, *b)};\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/max.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1030/main.test.cpp
  - test/yukicoder/631/main.test.cpp
  - test/aoj/3035/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/max.cpp
layout: document
title: Max monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
