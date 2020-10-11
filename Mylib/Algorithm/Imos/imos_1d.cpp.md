---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_5_A/main.test.cpp
    title: test/aoj/DSL_5_A/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Imos/imos_1d.cpp\"\n#include <vector>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ imos_1d {\n    using value_type = T;\n\n  private:\n    std::vector<T> data_;\n\
    \    int n_;\n\n  public:\n    imos_1d(){}\n    imos_1d(int n): data_(n), n_(n){}\n\
    \n    void update(int l, int r, T val){ // [l, r)\n      assert(0 <= l and l <=\
    \ r and r <= n_);\n      data_[l] += 1;\n      if(r < n_) data_[r] -= 1;\n   \
    \ }\n\n    auto build() const {\n      std::vector<T> ret(data_);\n      for(int\
    \ i = 1; i < n_; ++i){\n        ret[i] += ret[i - 1];\n      }\n      return ret;\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct imos_1d {\n    using value_type = T;\n\n\
    \  private:\n    std::vector<T> data_;\n    int n_;\n\n  public:\n    imos_1d(){}\n\
    \    imos_1d(int n): data_(n), n_(n){}\n\n    void update(int l, int r, T val){\
    \ // [l, r)\n      assert(0 <= l and l <= r and r <= n_);\n      data_[l] += 1;\n\
    \      if(r < n_) data_[r] -= 1;\n    }\n\n    auto build() const {\n      std::vector<T>\
    \ ret(data_);\n      for(int i = 1; i < n_; ++i){\n        ret[i] += ret[i - 1];\n\
    \      }\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Imos/imos_1d.cpp
  requiredBy: []
  timestamp: '2020-10-11 03:06:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_5_A/main.test.cpp
documentation_of: Mylib/Algorithm/Imos/imos_1d.cpp
layout: document
title: 1D Imos algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
