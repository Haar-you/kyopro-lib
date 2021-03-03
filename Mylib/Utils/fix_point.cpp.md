---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.binomial_heap.test.cpp
    title: test/aoj/2559/main.binomial_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.leftist_heap.test.cpp
    title: test/aoj/2559/main.leftist_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.pairing_heap.test.cpp
    title: test/aoj/2559/main.pairing_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.skew_heap.test.cpp
    title: test/aoj/2559/main.skew_heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3034/main.test.cpp
    title: test/aoj/3034/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Utils/fix_point.cpp\"\n#include <utility>\n\nnamespace\
    \ haar_lib {\n  template <typename F>\n  struct fix_point : F {\n    explicit\
    \ constexpr fix_point(F &&f) noexcept : F(std::forward<F>(f)){}\n\n    template\
    \ <typename ... Args>\n    constexpr auto operator()(Args &&... args) const {\n\
    \      return F::operator()(*this, std::forward<Args>(args) ...);\n    }\n  };\n\
    \n  template <typename F>\n  inline constexpr auto make_fix_point(F &&f){\n  \
    \  return fix_point<F>(std::forward<F>(f));\n  }\n\n  template <typename F>\n\
    \  inline constexpr auto make_fix_point(F &f){\n    return fix_point<F>(std::forward<F>(f));\n\
    \  }\n}\n"
  code: "#pragma once\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ F>\n  struct fix_point : F {\n    explicit constexpr fix_point(F &&f) noexcept\
    \ : F(std::forward<F>(f)){}\n\n    template <typename ... Args>\n    constexpr\
    \ auto operator()(Args &&... args) const {\n      return F::operator()(*this,\
    \ std::forward<Args>(args) ...);\n    }\n  };\n\n  template <typename F>\n  inline\
    \ constexpr auto make_fix_point(F &&f){\n    return fix_point<F>(std::forward<F>(f));\n\
    \  }\n\n  template <typename F>\n  inline constexpr auto make_fix_point(F &f){\n\
    \    return fix_point<F>(std::forward<F>(f));\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Utils/fix_point.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2559/main.binomial_heap.test.cpp
  - test/aoj/2559/main.pairing_heap.test.cpp
  - test/aoj/2559/main.skew_heap.test.cpp
  - test/aoj/2559/main.leftist_heap.test.cpp
  - test/aoj/3034/main.test.cpp
documentation_of: Mylib/Utils/fix_point.cpp
layout: document
title: Fixed point combinator
---

## Operations

## Requirements

## Notes

## Problems

## References

- [http://koturn.hatenablog.com/entry/2018/06/10/060000](http://koturn.hatenablog.com/entry/2018/06/10/060000)
