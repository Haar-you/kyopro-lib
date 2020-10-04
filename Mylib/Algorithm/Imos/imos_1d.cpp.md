---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_5_A/main.test.cpp
    title: test/aoj/DSL_5_A/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Imos/imos_1d.cpp\"\n#include <vector>\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct imos_1d {\n    using value_type\
    \ = T;\n\n  private:\n    std::vector<T> data_;\n    int n_;\n\n  public:\n  \
    \  imos_1d(){}\n    imos_1d(int n): data_(n), n_(n){}\n\n    void update(int l,\
    \ int r, T val){ // [l, r)\n      data_[l] += 1;\n      if(r < n_) data_[r] -=\
    \ 1;\n    }\n\n    void build(){\n      for(int i = 1; i < n_; ++i){\n       \
    \ data_[i] += data_[i - 1];\n      }\n    }\n\n    T operator[](size_t i) const\
    \ {return data_[i];}\n\n    auto begin() const {return data_.begin();}\n    auto\
    \ end() const {return data_.end();}\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct imos_1d {\n    using value_type = T;\n\n  private:\n    std::vector<T>\
    \ data_;\n    int n_;\n\n  public:\n    imos_1d(){}\n    imos_1d(int n): data_(n),\
    \ n_(n){}\n\n    void update(int l, int r, T val){ // [l, r)\n      data_[l] +=\
    \ 1;\n      if(r < n_) data_[r] -= 1;\n    }\n\n    void build(){\n      for(int\
    \ i = 1; i < n_; ++i){\n        data_[i] += data_[i - 1];\n      }\n    }\n\n\
    \    T operator[](size_t i) const {return data_[i];}\n\n    auto begin() const\
    \ {return data_.begin();}\n    auto end() const {return data_.end();}\n  };\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Imos/imos_1d.cpp
  requiredBy: []
  timestamp: '2020-10-01 09:22:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
