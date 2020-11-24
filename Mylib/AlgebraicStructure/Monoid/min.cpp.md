---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
    title: Manhattan distance MST
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508/main.splay_tree.test.cpp
    title: test/aoj/1508/main.splay_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508/main.treap.test.cpp
    title: test/aoj/1508/main.treap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3035/main.test.cpp
    title: test/aoj/3035/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A/main.test.cpp
    title: test/aoj/DSL_2_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F/main.dynamic.test.cpp
    title: test/aoj/DSL_2_F/main.dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F/main.test.cpp
    title: test/aoj/DSL_2_F/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H/main.test.cpp
    title: test/aoj/DSL_2_H/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/manhattanmst/main.test.cpp
    title: test/yosupo-judge/manhattanmst/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/875/main.test.cpp
    title: test/yukicoder/875/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n#include <algorithm>\n\
    #include <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ min_monoid {\n    using value_type = std::optional<T>;\n\n    value_type operator()()\
    \ const {return {};}\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if(not a) return b;\n      if(not b) return a;\n      return\
    \ {std::min(*a, *b)};\n    }\n  };\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <optional>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct min_monoid {\n    using value_type = std::optional<T>;\n\
    \n    value_type operator()() const {return {};}\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      if(not a) return b;\n   \
    \   if(not b) return a;\n      return {std::min(*a, *b)};\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/min.cpp
  requiredBy:
  - Mylib/Graph/MinimumSpanningTree/manhattan_minimum_spanning_tree.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/manhattanmst/main.test.cpp
  - test/yukicoder/875/main.test.cpp
  - test/aoj/DSL_2_H/main.test.cpp
  - test/aoj/3035/main.test.cpp
  - test/aoj/DSL_2_A/main.test.cpp
  - test/aoj/DSL_2_F/main.test.cpp
  - test/aoj/DSL_2_F/main.dynamic.test.cpp
  - test/aoj/1508/main.splay_tree.test.cpp
  - test/aoj/1508/main.treap.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/min.cpp
layout: document
title: Min monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
