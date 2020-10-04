---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2444/main.test.cpp
    title: test/aoj/2444/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/AlgebraicStructure/Monoid/pair.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <typename Monoid1, typename Monoid2>\n  struct\
    \ pair_monoid {\n    using value_type = std::pair<typename Monoid1::value_type,\
    \ typename Monoid2::value_type>;\n    const static Monoid1 M1;\n    const static\
    \ Monoid2 M2;\n\n    value_type operator()() const {\n      return {M1(), M2()};\n\
    \    }\n\n    value_type operator()(const value_type &a, const value_type &b)\
    \ const {\n      return {M1(a.first, b.first), M2(a.second, b.second)};\n    }\n\
    \  };\n}\n"
  code: "#pragma once\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid1, typename Monoid2>\n  struct pair_monoid {\n    using value_type = std::pair<typename\
    \ Monoid1::value_type, typename Monoid2::value_type>;\n    const static Monoid1\
    \ M1;\n    const static Monoid2 M2;\n\n    value_type operator()() const {\n \
    \     return {M1(), M2()};\n    }\n\n    value_type operator()(const value_type\
    \ &a, const value_type &b) const {\n      return {M1(a.first, b.first), M2(a.second,\
    \ b.second)};\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/AlgebraicStructure/Monoid/pair.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2444/main.test.cpp
documentation_of: Mylib/AlgebraicStructure/Monoid/pair.cpp
layout: document
title: Pair monoid
---

## Operations

## Requirements

## Notes

## Problems

## References
