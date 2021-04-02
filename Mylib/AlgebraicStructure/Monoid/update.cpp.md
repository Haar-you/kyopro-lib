---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D/main.test.cpp
    title: test/aoj/DSL_2_D/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F/main.dynamic.test.cpp
    title: test/aoj/DSL_2_F/main.dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F/main.test.cpp
    title: test/aoj/DSL_2_F/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I/main.test.cpp
    title: test/aoj/DSL_2_I/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899/main.test.cpp
    title: test/yukicoder/899/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/update.cpp\"\n#include <optional>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  struct update_monoid {\n  \
    \  using value_type = std::optional<T>;\n    value_type operator()() const {return\
    \ std::nullopt;}\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {return (a ? a : b);}\n  };\n}\n"
  code: "#pragma once\n#include <optional>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct update_monoid {\n    using value_type = std::optional<T>;\n   \
    \ value_type operator()() const {return std::nullopt;}\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {return (a ? a : b);}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/update.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/899/main.test.cpp
  - test/aoj/DSL_2_D/main.test.cpp
  - test/aoj/DSL_2_I/main.test.cpp
  - test/aoj/DSL_2_F/main.dynamic.test.cpp
  - test/aoj/DSL_2_F/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/update.cpp
layout: document
title: Update monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
