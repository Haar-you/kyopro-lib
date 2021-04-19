---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/matrix_product/main.test.cpp
    title: test/yosupo-judge/matrix_product/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/matrix.cpp\"\n#include <vector>\n#include\
    \ <cassert>\n\nnamespace haar_lib {\n  template <typename T>\n  class matrix {\n\
    \    std::vector<std::vector<T>> data_;\n    size_t R_, C_;\n\n  public:\n   \
    \ matrix(): data_(), R_(0), C_(0){}\n    matrix(size_t R, size_t C, T value =\
    \ T()): data_(R, std::vector<T>(C, value)), R_(R), C_(C){}\n    matrix(std::vector<std::vector<T>>\
    \ data): data_(data), R_(data.size()), C_(data[0].size()){}\n\n    const auto&\
    \ operator[](size_t i) const {\n      return data_[i];\n    }\n\n    friend auto\
    \ operator*(const matrix<T> &a, const matrix<T> &b){\n      assert(a.C_ == b.R_);\n\
    \n      matrix ret(a.R_, b.C_);\n\n      for(size_t i = 0; i < a.R_; ++i){\n \
    \       for(size_t k = 0; k < a.C_; ++k){\n          for(size_t j = 0; j < b.C_;\
    \ ++j){\n            ret.data_[i][j] += a.data_[i][k] * b.data_[k][j];\n     \
    \     }\n        }\n      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class matrix {\n    std::vector<std::vector<T>>\
    \ data_;\n    size_t R_, C_;\n\n  public:\n    matrix(): data_(), R_(0), C_(0){}\n\
    \    matrix(size_t R, size_t C, T value = T()): data_(R, std::vector<T>(C, value)),\
    \ R_(R), C_(C){}\n    matrix(std::vector<std::vector<T>> data): data_(data), R_(data.size()),\
    \ C_(data[0].size()){}\n\n    const auto& operator[](size_t i) const {\n     \
    \ return data_[i];\n    }\n\n    friend auto operator*(const matrix<T> &a, const\
    \ matrix<T> &b){\n      assert(a.C_ == b.R_);\n\n      matrix ret(a.R_, b.C_);\n\
    \n      for(size_t i = 0; i < a.R_; ++i){\n        for(size_t k = 0; k < a.C_;\
    \ ++k){\n          for(size_t j = 0; j < b.C_; ++j){\n            ret.data_[i][j]\
    \ += a.data_[i][k] * b.data_[k][j];\n          }\n        }\n      }\n\n     \
    \ return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/matrix.cpp
  requiredBy: []
  timestamp: '2021-04-19 11:39:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/matrix_product/main.test.cpp
documentation_of: Mylib/LinearAlgebra/matrix.cpp
layout: document
title: Matrix
---

## Operations

## Requirements

## Notes

## Problems

## References
