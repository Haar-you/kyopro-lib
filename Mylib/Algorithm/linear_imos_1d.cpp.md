---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/3165/main.test.imos.cpp
    title: test/aoj/3165/main.test.imos.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/linear_imos_1d.cpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  class linear_imos_1d\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    int n_;\n    std::vector<T>\
    \ vec_a_, vec_a_end_, vec_b_;\n\n  public:\n    linear_imos_1d(int n) : n_(n),\
    \ vec_a_(n_ + 1), vec_a_end_(n_ + 1), vec_b_(n_ + 1) {}\n\n    void update(int\
    \ s, int t, const T &a, const T &b) {\n      assert(0 <= s and s <= t and t <=\
    \ n_);\n      vec_a_[s + 1] += a;\n      vec_a_[t] -= a;\n\n      vec_a_end_[t]\
    \ -= a * (t - s - 1);\n\n      vec_b_[s] += b;\n      vec_b_[t] -= b;\n    }\n\
    \n    auto build() const {\n      std::vector<T> ret(vec_a_);\n      for (int\
    \ i = 0; i < n_; ++i) ret[i + 1] += ret[i];\n      for (int i = 0; i < n_; ++i)\
    \ ret[i] += vec_a_end_[i];\n      for (int i = 0; i < n_; ++i) ret[i + 1] += ret[i];\n\
    \n      std::vector<T> temp(vec_b_);\n      for (int i = 0; i < n_; ++i) temp[i\
    \ + 1] += temp[i];\n      for (int i = 0; i < n_; ++i) ret[i] += temp[i];\n\n\
    \      ret.pop_back();\n\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class linear_imos_1d {\n  public:\n    using value_type\
    \ = T;\n\n  private:\n    int n_;\n    std::vector<T> vec_a_, vec_a_end_, vec_b_;\n\
    \n  public:\n    linear_imos_1d(int n) : n_(n), vec_a_(n_ + 1), vec_a_end_(n_\
    \ + 1), vec_b_(n_ + 1) {}\n\n    void update(int s, int t, const T &a, const T\
    \ &b) {\n      assert(0 <= s and s <= t and t <= n_);\n      vec_a_[s + 1] +=\
    \ a;\n      vec_a_[t] -= a;\n\n      vec_a_end_[t] -= a * (t - s - 1);\n\n   \
    \   vec_b_[s] += b;\n      vec_b_[t] -= b;\n    }\n\n    auto build() const {\n\
    \      std::vector<T> ret(vec_a_);\n      for (int i = 0; i < n_; ++i) ret[i +\
    \ 1] += ret[i];\n      for (int i = 0; i < n_; ++i) ret[i] += vec_a_end_[i];\n\
    \      for (int i = 0; i < n_; ++i) ret[i + 1] += ret[i];\n\n      std::vector<T>\
    \ temp(vec_b_);\n      for (int i = 0; i < n_; ++i) temp[i + 1] += temp[i];\n\
    \      for (int i = 0; i < n_; ++i) ret[i] += temp[i];\n\n      ret.pop_back();\n\
    \n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/linear_imos_1d.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/3165/main.test.imos.cpp
documentation_of: Mylib/Algorithm/linear_imos_1d.cpp
layout: document
title: 1D Imos algorithm (Linear addition)
---

## Operations

## Requirements

## Notes

## Problems

- [ARC 077 E - guruguru](https://atcoder.jp/contests/arc077/tasks/arc077_c)

## References

