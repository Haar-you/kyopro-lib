---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/755/main.test.cpp
    title: test/yukicoder/755/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp\"\n\
    #include <vector>\n#include <functional>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>\n\
    \  class cumulative_sum_2d {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    std::vector<std::vector<T>> data_;\n    int N_, M_;\n    Add add_;\n    Minus\
    \ minus_;\n    bool is_built_ = false;\n\n  public:\n    cumulative_sum_2d(){}\n\
    \    cumulative_sum_2d(int N, int M, const T &e = 0, const Add &add = Add(), const\
    \ Minus &minus = Minus()):\n      N_(N), M_(M), add_(add), minus_(minus)\n   \
    \ {\n      data_.assign(N_ + 1, std::vector<T>(M_ + 1, e));\n    }\n\n    auto&\
    \ update(const std::vector<std::vector<T>> &a){\n      assert(not is_built_);\n\
    \      for(int i = 0; i < N_; ++i){\n        for(int j = 0; j < M_; ++j){\n  \
    \        data_[i + 1][j + 1] = add_(data_[i + 1][j + 1], a[i][j]);\n        }\n\
    \      }\n      return *this;\n    }\n\n    auto& update(int i, int j, const T\
    \ &val){\n      assert(not is_built_);\n      data_[i + 1][j + 1] = add_(data_[i\
    \ + 1][j + 1], val);\n      return *this;\n    }\n\n    auto& build(){\n     \
    \ assert(not is_built_);\n      for(int i = 1; i <= N_; ++i)\n        for(int\
    \ j = 0; j <= M_; ++j)\n          data_[i][j] = add_(data_[i][j], data_[i - 1][j]);\n\
    \      for(int i = 0; i <= N_; ++i)\n        for(int j = 1; j <= M_; ++j)\n  \
    \        data_[i][j] = add_(data_[i][j], data_[i][j - 1]);\n      is_built_ =\
    \ true;\n      return *this;\n    }\n\n    T fold(std::pair<int, int> p1, std::pair<int,\
    \ int> p2) const {\n      assert(is_built_);\n      const auto [x1, y1] = p1;\n\
    \      const auto [x2, y2] = p2;\n      return add_(minus_(data_[x2][y2], add_(data_[x1][y2],\
    \ data_[x2][y1])), data_[x1][y1]);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Add = std::plus<T>, typename\
    \ Minus = std::minus<T>>\n  class cumulative_sum_2d {\n  public:\n    using value_type\
    \ = T;\n\n  private:\n    std::vector<std::vector<T>> data_;\n    int N_, M_;\n\
    \    Add add_;\n    Minus minus_;\n    bool is_built_ = false;\n\n  public:\n\
    \    cumulative_sum_2d(){}\n    cumulative_sum_2d(int N, int M, const T &e = 0,\
    \ const Add &add = Add(), const Minus &minus = Minus()):\n      N_(N), M_(M),\
    \ add_(add), minus_(minus)\n    {\n      data_.assign(N_ + 1, std::vector<T>(M_\
    \ + 1, e));\n    }\n\n    auto& update(const std::vector<std::vector<T>> &a){\n\
    \      assert(not is_built_);\n      for(int i = 0; i < N_; ++i){\n        for(int\
    \ j = 0; j < M_; ++j){\n          data_[i + 1][j + 1] = add_(data_[i + 1][j +\
    \ 1], a[i][j]);\n        }\n      }\n      return *this;\n    }\n\n    auto& update(int\
    \ i, int j, const T &val){\n      assert(not is_built_);\n      data_[i + 1][j\
    \ + 1] = add_(data_[i + 1][j + 1], val);\n      return *this;\n    }\n\n    auto&\
    \ build(){\n      assert(not is_built_);\n      for(int i = 1; i <= N_; ++i)\n\
    \        for(int j = 0; j <= M_; ++j)\n          data_[i][j] = add_(data_[i][j],\
    \ data_[i - 1][j]);\n      for(int i = 0; i <= N_; ++i)\n        for(int j = 1;\
    \ j <= M_; ++j)\n          data_[i][j] = add_(data_[i][j], data_[i][j - 1]);\n\
    \      is_built_ = true;\n      return *this;\n    }\n\n    T fold(std::pair<int,\
    \ int> p1, std::pair<int, int> p2) const {\n      assert(is_built_);\n      const\
    \ auto [x1, y1] = p1;\n      const auto [x2, y2] = p2;\n      return add_(minus_(data_[x2][y2],\
    \ add_(data_[x1][y2], data_[x2][y1])), data_[x1][y1]);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/755/main.test.cpp
documentation_of: Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp
layout: document
title: 2D cumulative sum
---

## Operations

## Requirements

## Notes

## Problems

## References
