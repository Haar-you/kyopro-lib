---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/755/main.test.cpp
    title: test/yukicoder/755/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/cumulative_sum_2d.cpp\"\n#include <vector>\n\
    #include <functional>\n#include <cassert>\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  class cumulative_sum_2d {\n  public:\n    using value_type =\
    \ T;\n\n  private:\n    template <typename> friend class cumulative_sum_2d_builder;\n\
    \    int N_, M_;\n    std::vector<std::vector<T>> data_;\n\n  public:\n    T fold(std::pair<int,\
    \ int> p1, std::pair<int, int> p2) const {\n      const auto [x1, y1] = p1;\n\
    \      const auto [x2, y2] = p2;\n      assert(0 <= x1 and x1 <= x2 and x2 <=\
    \ N_);\n      assert(0 <= y1 and y1 <= y2 and y2 <= M_);\n      return data_[x2][y2]\
    \ - data_[x1][y2] - data_[x2][y1] + data_[x1][y1];\n    }\n  };\n\n  template\
    \ <typename T>\n  class cumulative_sum_2d_builder {\n    int N_, M_;\n    std::vector<std::vector<T>>\
    \ data_;\n\n  public:\n    cumulative_sum_2d_builder(){}\n    cumulative_sum_2d_builder(int\
    \ N, int M):\n      N_(N), M_(M), data_(N + 1, std::vector<T>(M + 1)){}\n\n  \
    \  auto& update(const std::vector<std::vector<T>> &a){\n      for(int i = 0; i\
    \ < N_; ++i){\n        for(int j = 0; j < M_; ++j){\n          data_[i + 1][j\
    \ + 1] += a[i][j];\n        }\n      }\n      return *this;\n    }\n\n    auto&\
    \ update(int i, int j, const T &val){\n      data_[i + 1][j + 1] += val;\n   \
    \   return *this;\n    }\n\n    auto build() const {\n      cumulative_sum_2d<T>\
    \ ret;\n      ret.data_ = data_;\n      ret.N_ = N_;\n      ret.M_ = M_;\n\n \
    \     for(int i = 1; i <= N_; ++i)\n        for(int j = 0; j <= M_; ++j)\n   \
    \       ret.data_[i][j] += ret.data_[i - 1][j];\n      for(int i = 0; i <= N_;\
    \ ++i)\n        for(int j = 1; j <= M_; ++j)\n          ret.data_[i][j] += ret.data_[i][j\
    \ - 1];\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  class cumulative_sum_2d {\n\
    \  public:\n    using value_type = T;\n\n  private:\n    template <typename> friend\
    \ class cumulative_sum_2d_builder;\n    int N_, M_;\n    std::vector<std::vector<T>>\
    \ data_;\n\n  public:\n    T fold(std::pair<int, int> p1, std::pair<int, int>\
    \ p2) const {\n      const auto [x1, y1] = p1;\n      const auto [x2, y2] = p2;\n\
    \      assert(0 <= x1 and x1 <= x2 and x2 <= N_);\n      assert(0 <= y1 and y1\
    \ <= y2 and y2 <= M_);\n      return data_[x2][y2] - data_[x1][y2] - data_[x2][y1]\
    \ + data_[x1][y1];\n    }\n  };\n\n  template <typename T>\n  class cumulative_sum_2d_builder\
    \ {\n    int N_, M_;\n    std::vector<std::vector<T>> data_;\n\n  public:\n  \
    \  cumulative_sum_2d_builder(){}\n    cumulative_sum_2d_builder(int N, int M):\n\
    \      N_(N), M_(M), data_(N + 1, std::vector<T>(M + 1)){}\n\n    auto& update(const\
    \ std::vector<std::vector<T>> &a){\n      for(int i = 0; i < N_; ++i){\n     \
    \   for(int j = 0; j < M_; ++j){\n          data_[i + 1][j + 1] += a[i][j];\n\
    \        }\n      }\n      return *this;\n    }\n\n    auto& update(int i, int\
    \ j, const T &val){\n      data_[i + 1][j + 1] += val;\n      return *this;\n\
    \    }\n\n    auto build() const {\n      cumulative_sum_2d<T> ret;\n      ret.data_\
    \ = data_;\n      ret.N_ = N_;\n      ret.M_ = M_;\n\n      for(int i = 1; i <=\
    \ N_; ++i)\n        for(int j = 0; j <= M_; ++j)\n          ret.data_[i][j] +=\
    \ ret.data_[i - 1][j];\n      for(int i = 0; i <= N_; ++i)\n        for(int j\
    \ = 1; j <= M_; ++j)\n          ret.data_[i][j] += ret.data_[i][j - 1];\n    \
    \  return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/cumulative_sum_2d.cpp
  requiredBy: []
  timestamp: '2020-12-09 10:43:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/755/main.test.cpp
documentation_of: Mylib/Algorithm/cumulative_sum_2d.cpp
layout: document
title: 2D cumulative sum
---

## Operations

## Requirements

## Notes

## Problems

## References
