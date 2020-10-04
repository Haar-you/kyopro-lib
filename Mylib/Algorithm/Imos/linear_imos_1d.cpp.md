---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3165/main.test.imos.cpp
    title: test/aoj/3165/main.test.imos.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Imos/linear_imos_1d.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  class linear_imos_1d {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    int n_;\n    std::vector<T> vec_a_,\
    \ vec_a_end_, vec_b_, data_;\n\n  public:\n    linear_imos_1d(int n):\n      n_(n),\
    \ vec_a_(n_ + 1), vec_a_end_(n_ + 1), vec_b_(n_ + 1), data_(n_){}\n\n    void\
    \ update(int s, int t, const T &a, const T &b){\n      vec_a_[s + 1] += a;\n \
    \     vec_a_[t] -= a;\n\n      vec_a_end_[t] -= a * (t - s - 1);\n\n      vec_b_[s]\
    \ += b;\n      vec_b_[t] -= b;\n    }\n\n    void build(){\n      for(int i =\
    \ 0; i < n_; ++i) vec_a_[i + 1] += vec_a_[i];\n      for(int i = 0; i <= n_; ++i)\
    \ vec_a_[i] += vec_a_end_[i];\n      for(int i = 0; i < n_; ++i) vec_a_[i + 1]\
    \ += vec_a_[i];\n      for(int i = 0; i < n_; ++i) vec_b_[i + 1] += vec_b_[i];\n\
    \      for(int i = 0; i < n_; ++i) data_[i] = vec_a_[i] + vec_b_[i];\n    }\n\n\
    \    T operator[](size_t i) const {return data_[i];}\n\n    auto begin() const\
    \ {return data_.begin();}\n    auto end() const {return data_.end();}\n  };\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class linear_imos_1d {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    int n_;\n    std::vector<T> vec_a_, vec_a_end_, vec_b_, data_;\n\n  public:\n\
    \    linear_imos_1d(int n):\n      n_(n), vec_a_(n_ + 1), vec_a_end_(n_ + 1),\
    \ vec_b_(n_ + 1), data_(n_){}\n\n    void update(int s, int t, const T &a, const\
    \ T &b){\n      vec_a_[s + 1] += a;\n      vec_a_[t] -= a;\n\n      vec_a_end_[t]\
    \ -= a * (t - s - 1);\n\n      vec_b_[s] += b;\n      vec_b_[t] -= b;\n    }\n\
    \n    void build(){\n      for(int i = 0; i < n_; ++i) vec_a_[i + 1] += vec_a_[i];\n\
    \      for(int i = 0; i <= n_; ++i) vec_a_[i] += vec_a_end_[i];\n      for(int\
    \ i = 0; i < n_; ++i) vec_a_[i + 1] += vec_a_[i];\n      for(int i = 0; i < n_;\
    \ ++i) vec_b_[i + 1] += vec_b_[i];\n      for(int i = 0; i < n_; ++i) data_[i]\
    \ = vec_a_[i] + vec_b_[i];\n    }\n\n    T operator[](size_t i) const {return\
    \ data_[i];}\n\n    auto begin() const {return data_.begin();}\n    auto end()\
    \ const {return data_.end();}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Imos/linear_imos_1d.cpp
  requiredBy: []
  timestamp: '2020-10-01 09:22:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/3165/main.test.imos.cpp
documentation_of: Mylib/Algorithm/Imos/linear_imos_1d.cpp
layout: document
title: 1D Imos algorithm (Linear addition)
---

## Operations

## Requirements

## Notes

## Problems

- [ARC 077 E - guruguru](https://atcoder.jp/contests/arc077/tasks/arc077_c)

## References

