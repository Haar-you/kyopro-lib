---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/510/main.test.cpp
    title: test/yukicoder/510/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp\"\
    \n#include <array>\n#include <initializer_list>\n#include <utility>\n\nnamespace\
    \ haar_lib {\n  template <typename T, int N>\n  struct square_matrix_const {\n\
    \    using value_type = T;\n\n    std::array<std::array<T, N>, N> matrix;\n\n\
    \    square_matrix_const(){\n      for(size_t i = 0; i < N; ++i) for(size_t j\
    \ = 0; j < N; ++j) matrix[i][j] = 0;\n    }\n    square_matrix_const(const T &val){\n\
    \      for(size_t i = 0; i < N; ++i) matrix[i].fill(val);\n    }\n    square_matrix_const(std::initializer_list<std::initializer_list<T>>\
    \ list){\n      int i = 0;\n      for(auto it1 = list.begin(); it1 != list.end();\
    \ ++it1, ++i){\n        int j = 0;\n        for(auto it2 = it1->begin(); it2 !=\
    \ it1->end(); ++it2, ++j){\n          matrix[i][j] = *it2;\n        }\n      }\n\
    \    }\n\n    bool operator==(const square_matrix_const &val) const {return matrix\
    \ == val.matrix;}\n    bool operator!=(const square_matrix_const &val) const {return\
    \ !(*this == val);}\n\n    auto& operator=(const square_matrix_const &val){\n\
    \      this->matrix = val.matrix;\n      return *this;\n    }\n\n    auto& operator+=(const\
    \ square_matrix_const &val){\n      for(int i = 0; i < N; ++i)\n        for(int\
    \ j = 0; j < N; ++j)\n          matrix[i][j] = matrix[i][j] + val[i][j];\n   \
    \   return *this;\n    }\n\n    auto& operator-=(const square_matrix_const &val){\n\
    \      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n      \
    \    matrix[i][j] = matrix[i][j] - val[i][j];\n      return *this;\n    }\n\n\
    \    auto& operator*=(const square_matrix_const &val){\n      std::array<std::array<T,\
    \ N>, N> temp = {};\n      for(int i = 0; i < N; ++i)\n        for(int j = 0;\
    \ j < N; ++j)\n          for(int k = 0; k < N; ++k)\n            temp[i][j] +=\
    \ matrix[i][k] * val[k][j];\n      std::swap(matrix, temp);\n      return *this;\n\
    \    }\n\n    const auto& operator[](size_t i) const {return matrix[i];}\n   \
    \ auto& operator[](size_t i){return matrix[i];}\n    int size() const {return\
    \ N;}\n\n    static auto unit(){\n      square_matrix_const ret;\n      for(size_t\
    \ i = 0; i < N; ++i) ret[i][i] = 1;\n      return ret;\n    }\n\n    friend auto\
    \ operator+(const square_matrix_const &a, const square_matrix_const &b){\n   \
    \   auto ret = a; return ret += b;\n    }\n    friend auto operator-(const square_matrix_const\
    \ &a, const square_matrix_const &b){\n      auto ret = a; return ret -= b;\n \
    \   }\n    friend auto operator*(const square_matrix_const &a, const square_matrix_const\
    \ &b){\n      auto ret = a; return ret *= b;\n    }\n\n    auto pow(uint64_t p)\
    \ const {\n      auto ret = unit();\n      auto a = *this;\n\n      while(p >\
    \ 0){\n        if(p & 1) ret *= a;\n        a *= a;\n        p >>= 1;\n      }\n\
    \n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <array>\n#include <initializer_list>\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <typename T, int N>\n  struct square_matrix_const\
    \ {\n    using value_type = T;\n\n    std::array<std::array<T, N>, N> matrix;\n\
    \n    square_matrix_const(){\n      for(size_t i = 0; i < N; ++i) for(size_t j\
    \ = 0; j < N; ++j) matrix[i][j] = 0;\n    }\n    square_matrix_const(const T &val){\n\
    \      for(size_t i = 0; i < N; ++i) matrix[i].fill(val);\n    }\n    square_matrix_const(std::initializer_list<std::initializer_list<T>>\
    \ list){\n      int i = 0;\n      for(auto it1 = list.begin(); it1 != list.end();\
    \ ++it1, ++i){\n        int j = 0;\n        for(auto it2 = it1->begin(); it2 !=\
    \ it1->end(); ++it2, ++j){\n          matrix[i][j] = *it2;\n        }\n      }\n\
    \    }\n\n    bool operator==(const square_matrix_const &val) const {return matrix\
    \ == val.matrix;}\n    bool operator!=(const square_matrix_const &val) const {return\
    \ !(*this == val);}\n\n    auto& operator=(const square_matrix_const &val){\n\
    \      this->matrix = val.matrix;\n      return *this;\n    }\n\n    auto& operator+=(const\
    \ square_matrix_const &val){\n      for(int i = 0; i < N; ++i)\n        for(int\
    \ j = 0; j < N; ++j)\n          matrix[i][j] = matrix[i][j] + val[i][j];\n   \
    \   return *this;\n    }\n\n    auto& operator-=(const square_matrix_const &val){\n\
    \      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n      \
    \    matrix[i][j] = matrix[i][j] - val[i][j];\n      return *this;\n    }\n\n\
    \    auto& operator*=(const square_matrix_const &val){\n      std::array<std::array<T,\
    \ N>, N> temp = {};\n      for(int i = 0; i < N; ++i)\n        for(int j = 0;\
    \ j < N; ++j)\n          for(int k = 0; k < N; ++k)\n            temp[i][j] +=\
    \ matrix[i][k] * val[k][j];\n      std::swap(matrix, temp);\n      return *this;\n\
    \    }\n\n    const auto& operator[](size_t i) const {return matrix[i];}\n   \
    \ auto& operator[](size_t i){return matrix[i];}\n    int size() const {return\
    \ N;}\n\n    static auto unit(){\n      square_matrix_const ret;\n      for(size_t\
    \ i = 0; i < N; ++i) ret[i][i] = 1;\n      return ret;\n    }\n\n    friend auto\
    \ operator+(const square_matrix_const &a, const square_matrix_const &b){\n   \
    \   auto ret = a; return ret += b;\n    }\n    friend auto operator-(const square_matrix_const\
    \ &a, const square_matrix_const &b){\n      auto ret = a; return ret -= b;\n \
    \   }\n    friend auto operator*(const square_matrix_const &a, const square_matrix_const\
    \ &b){\n      auto ret = a; return ret *= b;\n    }\n\n    auto pow(uint64_t p)\
    \ const {\n      auto ret = unit();\n      auto a = *this;\n\n      while(p >\
    \ 0){\n        if(p & 1) ret *= a;\n        a *= a;\n        p >>= 1;\n      }\n\
    \n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp
  requiredBy: []
  timestamp: '2020-09-21 01:58:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/510/main.test.cpp
documentation_of: Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp
layout: document
title: Square matrix (Const size)
---

## Operations

## Requirements

## Notes

## Problems

## References
