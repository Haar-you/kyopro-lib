---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_5_A/main.test.cpp
    title: test/aoj/DSL_5_A/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/imos_1d.cpp\"\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  struct imos_1d\
    \ {\n    using value_type = T;\n\n  private:\n    std::vector<T> data_;\n    int\
    \ n_;\n\n  public:\n    imos_1d() {}\n    imos_1d(int n) : data_(n), n_(n) {}\n\
    \n    void update(int l, int r, T val) {  // [l, r)\n      assert(0 <= l and l\
    \ <= r and r <= n_);\n      data_[l] += val;\n      if (r < n_) data_[r] -= val;\n\
    \    }\n\n    auto build() const {\n      std::vector<T> ret(data_);\n      for\
    \ (int i = 1; i < n_; ++i) {\n        ret[i] += ret[i - 1];\n      }\n      return\
    \ ret;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct imos_1d {\n    using value_type = T;\n\n\
    \  private:\n    std::vector<T> data_;\n    int n_;\n\n  public:\n    imos_1d()\
    \ {}\n    imos_1d(int n) : data_(n), n_(n) {}\n\n    void update(int l, int r,\
    \ T val) {  // [l, r)\n      assert(0 <= l and l <= r and r <= n_);\n      data_[l]\
    \ += val;\n      if (r < n_) data_[r] -= val;\n    }\n\n    auto build() const\
    \ {\n      std::vector<T> ret(data_);\n      for (int i = 1; i < n_; ++i) {\n\
    \        ret[i] += ret[i - 1];\n      }\n      return ret;\n    }\n  };\n}  //\
    \ namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/imos_1d.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_5_A/main.test.cpp
documentation_of: Mylib/Algorithm/imos_1d.cpp
layout: document
title: 1D Imos algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References