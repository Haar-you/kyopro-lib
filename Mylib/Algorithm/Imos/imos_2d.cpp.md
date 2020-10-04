---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_5_B/main.test.cpp
    title: test/aoj/DSL_5_B/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Imos/imos_2d.cpp\"\n#include <vector>\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct imos_2d {\n    using value_type\
    \ = T;\n\n  private:\n    std::vector<std::vector<T>> data_;\n    int n_, m_;\n\
    \n  public:\n    imos_2d(){}\n    imos_2d(int n, int m): data_(n, std::vector<T>(m)),\
    \ n_(n), m_(m){}\n\n    void update(std::pair<int, int> p1, std::pair<int, int>\
    \ p2, T val){\n      const auto [x1, y1] = p1;\n      const auto [x2, y2] = p2;\n\
    \n      data_[x1][y1] += val;\n      if(x2 < n_ and y2 < m_) data_[x2][y2] +=\
    \ val;\n      if(y2 < m_) data_[x1][y2] -= val;\n      if(x2 < n_) data_[x2][y1]\
    \ -= val;\n    }\n\n    void build(){\n      for(int i = 1; i < n_; ++i){\n  \
    \      for(int j = 0; j < m_; ++j){\n          data_[i][j] += data_[i - 1][j];\n\
    \        }\n      }\n\n      for(int i = 0; i < n_; ++i){\n        for(int j =\
    \ 1; j < m_; ++j){\n          data_[i][j] += data_[i][j - 1];\n        }\n   \
    \   }\n    }\n\n    const std::vector<T>& operator[](size_t i) const {return data_[i];}\n\
    \n    auto begin() const {return data_.begin();}\n    auto end() const {return\
    \ data_.end();}\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct imos_2d {\n    using value_type = T;\n\n  private:\n    std::vector<std::vector<T>>\
    \ data_;\n    int n_, m_;\n\n  public:\n    imos_2d(){}\n    imos_2d(int n, int\
    \ m): data_(n, std::vector<T>(m)), n_(n), m_(m){}\n\n    void update(std::pair<int,\
    \ int> p1, std::pair<int, int> p2, T val){\n      const auto [x1, y1] = p1;\n\
    \      const auto [x2, y2] = p2;\n\n      data_[x1][y1] += val;\n      if(x2 <\
    \ n_ and y2 < m_) data_[x2][y2] += val;\n      if(y2 < m_) data_[x1][y2] -= val;\n\
    \      if(x2 < n_) data_[x2][y1] -= val;\n    }\n\n    void build(){\n      for(int\
    \ i = 1; i < n_; ++i){\n        for(int j = 0; j < m_; ++j){\n          data_[i][j]\
    \ += data_[i - 1][j];\n        }\n      }\n\n      for(int i = 0; i < n_; ++i){\n\
    \        for(int j = 1; j < m_; ++j){\n          data_[i][j] += data_[i][j - 1];\n\
    \        }\n      }\n    }\n\n    const std::vector<T>& operator[](size_t i) const\
    \ {return data_[i];}\n\n    auto begin() const {return data_.begin();}\n    auto\
    \ end() const {return data_.end();}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Imos/imos_2d.cpp
  requiredBy: []
  timestamp: '2020-10-01 09:22:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_5_B/main.test.cpp
documentation_of: Mylib/Algorithm/Imos/imos_2d.cpp
layout: document
title: 2D Imos algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
