---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/static_range_sum/main.test.cpp
    title: test/yosupo-judge/static_range_sum/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp\"\n\
    #include <vector>\n#include <functional>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>\n\
    \  class cumulative_sum_1d {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    std::vector<T> data_;\n    int N_;\n    Add add_;\n    Minus minus_;\n  \
    \  bool is_built_ = false;\n\n  public:\n    cumulative_sum_1d(){}\n    cumulative_sum_1d(\n\
    \      int N, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()\n\
    \    ): N_(N), add_(add), minus_(minus)\n    {\n      data_.assign(N_ + 1, e);\n\
    \    }\n\n    auto& update(const std::vector<T> &a){\n      assert(not is_built_);\n\
    \      for(int i = 0; i < N_; ++i) data_[i + 1] = add_(data_[i + 1], a[i]);\n\
    \      return *this;\n    }\n\n    auto& update(int i, const T &val){\n      assert(not\
    \ is_built_);\n      data_[i + 1] = add_(data_[i + 1], val);\n      return *this;\n\
    \    }\n\n    auto& build(){\n      assert(not is_built_);\n      for(int i =\
    \ 0; i < N_; ++i) data_[i + 1] = add_(data_[i + 1], data_[i]);\n      is_built_\
    \ = true;\n      return *this;\n    }\n\n    T fold(int l, int r) const {\n  \
    \    assert(is_built_);\n      return minus_(data_[r], data_[l]);\n    }\n  };\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Add = std::plus<T>, typename\
    \ Minus = std::minus<T>>\n  class cumulative_sum_1d {\n  public:\n    using value_type\
    \ = T;\n\n  private:\n    std::vector<T> data_;\n    int N_;\n    Add add_;\n\
    \    Minus minus_;\n    bool is_built_ = false;\n\n  public:\n    cumulative_sum_1d(){}\n\
    \    cumulative_sum_1d(\n      int N, const T &e = 0, const Add &add = Add(),\
    \ const Minus &minus = Minus()\n    ): N_(N), add_(add), minus_(minus)\n    {\n\
    \      data_.assign(N_ + 1, e);\n    }\n\n    auto& update(const std::vector<T>\
    \ &a){\n      assert(not is_built_);\n      for(int i = 0; i < N_; ++i) data_[i\
    \ + 1] = add_(data_[i + 1], a[i]);\n      return *this;\n    }\n\n    auto& update(int\
    \ i, const T &val){\n      assert(not is_built_);\n      data_[i + 1] = add_(data_[i\
    \ + 1], val);\n      return *this;\n    }\n\n    auto& build(){\n      assert(not\
    \ is_built_);\n      for(int i = 0; i < N_; ++i) data_[i + 1] = add_(data_[i +\
    \ 1], data_[i]);\n      is_built_ = true;\n      return *this;\n    }\n\n    T\
    \ fold(int l, int r) const {\n      assert(is_built_);\n      return minus_(data_[r],\
    \ data_[l]);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/static_range_sum/main.test.cpp
documentation_of: Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp
layout: document
title: 1D cumulative sum
---

## Operations

## Requirements

## Notes

## Problems

## References
