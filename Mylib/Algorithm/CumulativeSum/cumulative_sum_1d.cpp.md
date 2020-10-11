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
    \ {\n  template <typename T>\n  class cumulative_sum_1d {\n  public:\n    using\
    \ value_type = T;\n\n  private:\n    template <typename> friend class cumulative_sum_1d_builder;\n\
    \    int N_;\n    std::vector<T> data_;\n\n  public:\n    T fold(int l, int r)\
    \ const {\n      assert(0 <= l and l <= r and r <= N_);\n      return data_[r]\
    \ - data_[l];\n    }\n  };\n\n  template <typename T>\n  class cumulative_sum_1d_builder\
    \ {\n    int N_;\n    std::vector<T> data_;\n\n  public:\n    cumulative_sum_1d_builder(){}\n\
    \    cumulative_sum_1d_builder(int N): N_(N), data_(N + 1){}\n\n    auto& update(const\
    \ std::vector<T> &a){\n      for(int i = 0; i < N_; ++i) data_[i + 1] += a[i];\n\
    \      return *this;\n    }\n\n    auto& update(int i, const T &val){\n      assert(0\
    \ <= i and i < N_);\n      data_[i + 1] += val;\n      return *this;\n    }\n\n\
    \    auto build() const {\n      cumulative_sum_1d<T> ret;\n      ret.data_ =\
    \ data_;\n      ret.N_ = N_;\n      for(int i = 0; i < N_; ++i) ret.data_[i +\
    \ 1] += ret.data_[i];\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  class cumulative_sum_1d {\n\
    \  public:\n    using value_type = T;\n\n  private:\n    template <typename> friend\
    \ class cumulative_sum_1d_builder;\n    int N_;\n    std::vector<T> data_;\n\n\
    \  public:\n    T fold(int l, int r) const {\n      assert(0 <= l and l <= r and\
    \ r <= N_);\n      return data_[r] - data_[l];\n    }\n  };\n\n  template <typename\
    \ T>\n  class cumulative_sum_1d_builder {\n    int N_;\n    std::vector<T> data_;\n\
    \n  public:\n    cumulative_sum_1d_builder(){}\n    cumulative_sum_1d_builder(int\
    \ N): N_(N), data_(N + 1){}\n\n    auto& update(const std::vector<T> &a){\n  \
    \    for(int i = 0; i < N_; ++i) data_[i + 1] += a[i];\n      return *this;\n\
    \    }\n\n    auto& update(int i, const T &val){\n      assert(0 <= i and i <\
    \ N_);\n      data_[i + 1] += val;\n      return *this;\n    }\n\n    auto build()\
    \ const {\n      cumulative_sum_1d<T> ret;\n      ret.data_ = data_;\n      ret.N_\
    \ = N_;\n      for(int i = 0; i < N_; ++i) ret.data_[i + 1] += ret.data_[i];\n\
    \      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp
  requiredBy: []
  timestamp: '2020-10-11 03:06:10+09:00'
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
