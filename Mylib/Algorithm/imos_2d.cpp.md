---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_5_B/main.test.cpp
    title: test/aoj/DSL_5_B/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/imos_2d.cpp\"\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  struct imos_2d\
    \ {\n    using value_type = T;\n\n  private:\n    std::vector<std::vector<T>>\
    \ data_;\n    int n_, m_;\n\n  public:\n    imos_2d() {}\n    imos_2d(int n, int\
    \ m) : data_(n, std::vector<T>(m)), n_(n), m_(m) {}\n\n    void update(std::pair<int,\
    \ int> p1, std::pair<int, int> p2, T val) {\n      const auto [x1, y1] = p1;\n\
    \      const auto [x2, y2] = p2;\n      assert(0 <= x1 and x1 <= x2 and x2 <=\
    \ n_);\n      assert(0 <= y1 and y1 <= y2 and y2 <= m_);\n\n      data_[x1][y1]\
    \ += val;\n      if (x2 < n_ and y2 < m_) data_[x2][y2] += val;\n      if (y2\
    \ < m_) data_[x1][y2] -= val;\n      if (x2 < n_) data_[x2][y1] -= val;\n    }\n\
    \n    auto build() const {\n      std::vector<std::vector<T>> ret(data_);\n  \
    \    for (int i = 1; i < n_; ++i) {\n        for (int j = 0; j < m_; ++j) {\n\
    \          ret[i][j] += ret[i - 1][j];\n        }\n      }\n\n      for (int i\
    \ = 0; i < n_; ++i) {\n        for (int j = 1; j < m_; ++j) {\n          ret[i][j]\
    \ += ret[i][j - 1];\n        }\n      }\n      return ret;\n    }\n  };\n}  //\
    \ namespace haar_lib\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  struct imos_2d {\n    using value_type = T;\n\n\
    \  private:\n    std::vector<std::vector<T>> data_;\n    int n_, m_;\n\n  public:\n\
    \    imos_2d() {}\n    imos_2d(int n, int m) : data_(n, std::vector<T>(m)), n_(n),\
    \ m_(m) {}\n\n    void update(std::pair<int, int> p1, std::pair<int, int> p2,\
    \ T val) {\n      const auto [x1, y1] = p1;\n      const auto [x2, y2] = p2;\n\
    \      assert(0 <= x1 and x1 <= x2 and x2 <= n_);\n      assert(0 <= y1 and y1\
    \ <= y2 and y2 <= m_);\n\n      data_[x1][y1] += val;\n      if (x2 < n_ and y2\
    \ < m_) data_[x2][y2] += val;\n      if (y2 < m_) data_[x1][y2] -= val;\n    \
    \  if (x2 < n_) data_[x2][y1] -= val;\n    }\n\n    auto build() const {\n   \
    \   std::vector<std::vector<T>> ret(data_);\n      for (int i = 1; i < n_; ++i)\
    \ {\n        for (int j = 0; j < m_; ++j) {\n          ret[i][j] += ret[i - 1][j];\n\
    \        }\n      }\n\n      for (int i = 0; i < n_; ++i) {\n        for (int\
    \ j = 1; j < m_; ++j) {\n          ret[i][j] += ret[i][j - 1];\n        }\n  \
    \    }\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/imos_2d.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_5_B/main.test.cpp
documentation_of: Mylib/Algorithm/imos_2d.cpp
layout: document
title: 2D Imos algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
