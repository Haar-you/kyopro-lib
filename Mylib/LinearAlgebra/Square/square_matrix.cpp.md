---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1327/main.test.cpp
    title: test/aoj/1327/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/matrix_det/main.test.cpp
    title: test/yosupo-judge/matrix_det/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/194/main.test.cpp
    title: test/yukicoder/194/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/Square/square_matrix.cpp\"\n#include\
    \ <vector>\n#include <utility>\n\nnamespace haar_lib {\n  template <typename T,\
    \ const int &N>\n  struct square_matrix {\n    using value_type = T;\n\n    std::vector<std::vector<T>>\
    \ matrix;\n\n    square_matrix(): matrix(N, std::vector<T>(N)){}\n    square_matrix(const\
    \ T &val): matrix(N, std::vector<T>(N, val)){}\n    square_matrix(const std::vector<std::vector<T>>\
    \ &matrix): matrix(matrix){}\n\n    bool operator==(const square_matrix &val)\
    \ const {return matrix == val.matrix;}\n    bool operator!=(const square_matrix\
    \ &val) const {return !(*this == val);}\n\n    auto& operator=(const square_matrix\
    \ &val){\n      this->matrix = val.matrix;\n      return *this;\n    }\n\n   \
    \ auto& operator+=(const square_matrix &val){\n      for(int i = 0; i < N; ++i)\
    \ for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] + val[i][j];\n      return\
    \ *this;\n    }\n\n    auto& operator-=(const square_matrix &val){\n      for(int\
    \ i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j] -\
    \ val[i][j];\n      return *this;\n    }\n\n    auto& operator*=(const square_matrix\
    \ &val){\n      std::vector<std::vector<T>> temp(N, std::vector<T>(N));\n    \
    \  for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n          for(int\
    \ k = 0; k < N; ++k)\n            temp[i][j] = temp[i][j] + matrix[i][k] * val[k][j];\n\
    \      std::swap(matrix, temp);\n      return *this;\n    }\n\n    const auto&\
    \ operator[](size_t i) const {return matrix[i];}\n    auto& operator[](size_t\
    \ i){return matrix[i];}\n    int size() const {return N;}\n\n    static auto make_unit(){\n\
    \      square_matrix ret;\n      for(int i = 0; i < N; ++i) ret[i][i] = 1;\n \
    \     return ret;\n    }\n\n    friend auto operator+(const square_matrix &a,\
    \ const square_matrix &b){auto ret = a; ret += b; return ret;}\n    friend auto\
    \ operator-(const square_matrix &a, const square_matrix &b){auto ret = a; ret\
    \ -= b; return ret;}\n    friend auto operator*(const square_matrix &a, const\
    \ square_matrix &b){auto ret = a; ret *= b; return ret;}\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <typename T, const int &N>\n  struct square_matrix {\n    using\
    \ value_type = T;\n\n    std::vector<std::vector<T>> matrix;\n\n    square_matrix():\
    \ matrix(N, std::vector<T>(N)){}\n    square_matrix(const T &val): matrix(N, std::vector<T>(N,\
    \ val)){}\n    square_matrix(const std::vector<std::vector<T>> &matrix): matrix(matrix){}\n\
    \n    bool operator==(const square_matrix &val) const {return matrix == val.matrix;}\n\
    \    bool operator!=(const square_matrix &val) const {return !(*this == val);}\n\
    \n    auto& operator=(const square_matrix &val){\n      this->matrix = val.matrix;\n\
    \      return *this;\n    }\n\n    auto& operator+=(const square_matrix &val){\n\
    \      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j] = matrix[i][j]\
    \ + val[i][j];\n      return *this;\n    }\n\n    auto& operator-=(const square_matrix\
    \ &val){\n      for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) matrix[i][j]\
    \ = matrix[i][j] - val[i][j];\n      return *this;\n    }\n\n    auto& operator*=(const\
    \ square_matrix &val){\n      std::vector<std::vector<T>> temp(N, std::vector<T>(N));\n\
    \      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n      \
    \    for(int k = 0; k < N; ++k)\n            temp[i][j] = temp[i][j] + matrix[i][k]\
    \ * val[k][j];\n      std::swap(matrix, temp);\n      return *this;\n    }\n\n\
    \    const auto& operator[](size_t i) const {return matrix[i];}\n    auto& operator[](size_t\
    \ i){return matrix[i];}\n    int size() const {return N;}\n\n    static auto make_unit(){\n\
    \      square_matrix ret;\n      for(int i = 0; i < N; ++i) ret[i][i] = 1;\n \
    \     return ret;\n    }\n\n    friend auto operator+(const square_matrix &a,\
    \ const square_matrix &b){auto ret = a; ret += b; return ret;}\n    friend auto\
    \ operator-(const square_matrix &a, const square_matrix &b){auto ret = a; ret\
    \ -= b; return ret;}\n    friend auto operator*(const square_matrix &a, const\
    \ square_matrix &b){auto ret = a; ret *= b; return ret;}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/Square/square_matrix.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1327/main.test.cpp
  - test/yosupo-judge/matrix_det/main.test.cpp
  - test/yukicoder/194/main.test.cpp
documentation_of: Mylib/LinearAlgebra/Square/square_matrix.cpp
layout: document
title: Square matrix
---

## Operations

## Requirements

## Notes

## Problems

## References
