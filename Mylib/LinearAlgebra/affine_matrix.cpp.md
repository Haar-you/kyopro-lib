---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/affine_matrix.cpp\"\n#include <array>\n\
    #include <initializer_list>\n#include <vector>\n#include <cmath>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class affine_matrix_2d {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    std::array<std::array<T, 3>, 3>\
    \ data_;\n\n  public:\n    affine_matrix_2d(){}\n    affine_matrix_2d(std::initializer_list<std::initializer_list<T>>\
    \ list){\n      int i = 0, j = 0;\n      for(auto it = list.begin(); it != list.end();\
    \ ++it){\n        j = 0;\n        for(auto it2 = (*it).begin(); it2 != (*it).end();\
    \ ++it2){\n          data_[i][j] = *it2;\n          ++j;\n        }\n        ++i;\n\
    \      }\n    }\n\n    const auto& data() const {return data_;}\n    auto& data(){return\
    \ data_;}\n\n    const auto& operator[](size_t i) const {return data_[i];}\n \
    \   auto& operator[](size_t i){return data_[i];}\n\n    auto& operator*=(const\
    \ affine_matrix_2d &that){\n      std::array<std::array<T, 3>, 3> ret = {};\n\
    \      for(int i = 0; i < 3; ++i)\n        for(int j = 0; j < 3; ++j)\n      \
    \    for(int k = 0; k < 3; ++k)\n            ret[i][j] += data_[i][k] * that.data_[k][j];\n\
    \      data_ = ret;\n      return *this;\n    }\n\n    auto operator*(const affine_matrix_2d\
    \ &that) const {\n      return affine_matrix_2d(*this) *= that;\n    }\n\n   \
    \ auto operator*(const std::vector<T> &that) const {\n      std::array<T, 3> ret\
    \ = {};\n      for(int i = 0; i < 3; ++i)\n        for(int j = 0; j < 3; ++j)\n\
    \          ret[i] += data_[i][j] * that[j];\n      return ret;\n    }\n\n    static\
    \ auto unit(){\n      return affine_matrix_2d({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});\n\
    \    }\n\n    static auto rotate(double a){\n      return affine_matrix_2d(\n\
    \        {{(T)std::cos(a), -(T)std::sin(a), 0}, {(T)std::sin(a), (T)std::cos(a),\
    \ 0}, {0, 0, 1}}\n      );\n    }\n\n    static auto rotate90(int n = 1){\n  \
    \    const static int c[4] = {1, 0, -1, 0};\n      const static int s[4] = {0,\
    \ 1, 0, -1};\n      const int i = ((n % 4) + 4) % 4;\n      return affine_matrix_2d({{c[i],\
    \ -s[i], 0}, {s[i], c[i], 0}, {0, 0, 1}});\n    }\n\n    static auto move(T dx,\
    \ T dy){\n      return affine_matrix_2d({{1, 0, dx}, {0, 1, dy}, {0, 0, 1}});\n\
    \    }\n\n    static auto scale(T sx, T sy){\n      return affine_matrix_2d({{sx,\
    \ 0, 0}, {0, sy, 0}, {0, 0, 1}});\n    }\n  };\n}\n"
  code: "#pragma once\n#include <array>\n#include <initializer_list>\n#include <vector>\n\
    #include <cmath>\n\nnamespace haar_lib {\n  template <typename T>\n  class affine_matrix_2d\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    std::array<std::array<T,\
    \ 3>, 3> data_;\n\n  public:\n    affine_matrix_2d(){}\n    affine_matrix_2d(std::initializer_list<std::initializer_list<T>>\
    \ list){\n      int i = 0, j = 0;\n      for(auto it = list.begin(); it != list.end();\
    \ ++it){\n        j = 0;\n        for(auto it2 = (*it).begin(); it2 != (*it).end();\
    \ ++it2){\n          data_[i][j] = *it2;\n          ++j;\n        }\n        ++i;\n\
    \      }\n    }\n\n    const auto& data() const {return data_;}\n    auto& data(){return\
    \ data_;}\n\n    const auto& operator[](size_t i) const {return data_[i];}\n \
    \   auto& operator[](size_t i){return data_[i];}\n\n    auto& operator*=(const\
    \ affine_matrix_2d &that){\n      std::array<std::array<T, 3>, 3> ret = {};\n\
    \      for(int i = 0; i < 3; ++i)\n        for(int j = 0; j < 3; ++j)\n      \
    \    for(int k = 0; k < 3; ++k)\n            ret[i][j] += data_[i][k] * that.data_[k][j];\n\
    \      data_ = ret;\n      return *this;\n    }\n\n    auto operator*(const affine_matrix_2d\
    \ &that) const {\n      return affine_matrix_2d(*this) *= that;\n    }\n\n   \
    \ auto operator*(const std::vector<T> &that) const {\n      std::array<T, 3> ret\
    \ = {};\n      for(int i = 0; i < 3; ++i)\n        for(int j = 0; j < 3; ++j)\n\
    \          ret[i] += data_[i][j] * that[j];\n      return ret;\n    }\n\n    static\
    \ auto unit(){\n      return affine_matrix_2d({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});\n\
    \    }\n\n    static auto rotate(double a){\n      return affine_matrix_2d(\n\
    \        {{(T)std::cos(a), -(T)std::sin(a), 0}, {(T)std::sin(a), (T)std::cos(a),\
    \ 0}, {0, 0, 1}}\n      );\n    }\n\n    static auto rotate90(int n = 1){\n  \
    \    const static int c[4] = {1, 0, -1, 0};\n      const static int s[4] = {0,\
    \ 1, 0, -1};\n      const int i = ((n % 4) + 4) % 4;\n      return affine_matrix_2d({{c[i],\
    \ -s[i], 0}, {s[i], c[i], 0}, {0, 0, 1}});\n    }\n\n    static auto move(T dx,\
    \ T dy){\n      return affine_matrix_2d({{1, 0, dx}, {0, 1, dy}, {0, 0, 1}});\n\
    \    }\n\n    static auto scale(T sx, T sy){\n      return affine_matrix_2d({{sx,\
    \ 0, 0}, {0, sy, 0}, {0, 0, 1}});\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/affine_matrix.cpp
  requiredBy: []
  timestamp: '2021-02-28 02:02:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/LinearAlgebra/affine_matrix.cpp
layout: document
title: Affine transformation matrix (2D)
---

## Operations

## Requirements

## Notes

## Problems

## References
