---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1327/main.test.cpp
    title: test/aoj/1327/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/matrix_det/main.test.cpp
    title: test/yosupo-judge/matrix_det/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/194/main.test.cpp
    title: test/yukicoder/194/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/square_matrix.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <cstdint>\n#include <iostream>\n\nnamespace haar_lib\
    \ {\n  template <typename T, int &N>\n  class vector_dyn {\n  public:\n    using\
    \ value_type = T;\n\n  private:\n    std::vector<T> data_;\n\n  public:\n    vector_dyn():\
    \ data_(N){}\n    vector_dyn(T value): data_(N, value){}\n    vector_dyn(std::initializer_list<T>\
    \ list): data_(N){\n      int i = 0;\n      for(auto it = list.begin(); it !=\
    \ list.end(); ++it) data_[i++] = *it;\n    }\n    vector_dyn(const vector_dyn\
    \ &that): data_(that.data_){}\n\n    template <typename U>\n    vector_dyn(const\
    \ std::vector<U> &that): data_(that.begin(), that.end()){}\n\n    bool operator==(const\
    \ vector_dyn &that){return data_ == that.data_;}\n    bool operator!=(const vector_dyn\
    \ &that){return !(*this == that);}\n\n    auto& operator=(const vector_dyn &that){\n\
    \      data_ = that.data_;\n      return *this;\n    }\n\n    auto& operator+=(const\
    \ vector_dyn &that){\n      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];\n\
    \      return *this;\n    }\n\n    auto& operator-=(const vector_dyn &that){\n\
    \      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n\
    \    }\n\n    friend auto dot(const vector_dyn &a, const vector_dyn &b){\n   \
    \   T ret = 0;\n      for(int i = 0; i < N; ++i) ret += a.data_[i] * b.data_[i];\n\
    \      return ret;\n    }\n\n    auto operator+(const vector_dyn &that) const\
    \ {\n      return vector(*this) += that;\n    }\n\n    auto operator-(const vector_dyn\
    \ &that) const {\n      return vector(*this) -= that;\n    }\n\n    auto& operator[](int\
    \ i){return data_[i];}\n    const auto& operator[](int i) const {return data_[i];}\n\
    \    auto begin() const {return data_.begin();}\n    auto end() const {return\
    \ data_.end();}\n\n    int size() const {return N;}\n\n    friend std::ostream&\
    \ operator<<(std::ostream &s, const vector_dyn &a){\n      s << \"{\";\n     \
    \ for(auto it = a.data_.begin(); it != a.data_.end(); ++it){\n        if(it !=\
    \ a.data_.begin()) s << \",\";\n        s << *it;\n      }\n      s << \"}\";\n\
    \      return s;\n    }\n  };\n\n\n  template <typename T, int &N>\n  class square_matrix_dyn\
    \ {\n  public:\n    using value_type = T;\n    using vector_type = vector_dyn<T,\
    \ N>;\n\n  private:\n    std::vector<vector_type> data_;\n\n  public:\n    square_matrix_dyn():\
    \ data_(N, vector_type()){}\n    square_matrix_dyn(const T &val): data_(N, vector_type(val)){}\n\
    \    square_matrix_dyn(std::initializer_list<std::initializer_list<T>> list):\
    \ data_(N){\n      int i = 0;\n      for(auto it = list.begin(); it != list.end();\
    \ ++it){\n        data_[i++] = vector_type(*it);\n      }\n    }\n    square_matrix_dyn(const\
    \ square_matrix_dyn &that): data_(that.data_){}\n    square_matrix_dyn(const std::vector<std::vector<T>>\
    \ &that): data_(N){\n      for(int i = 0; i < N; ++i) data_[i] = that[i];\n  \
    \  }\n\n    bool operator==(const square_matrix_dyn &that) const {return data_\
    \ == that.data_;}\n    bool operator!=(const square_matrix_dyn &that) const {return\
    \ !(*this == that);}\n\n    auto& operator=(const square_matrix_dyn &that){\n\
    \      data_ = that.data_;\n      return *this;\n    }\n\n    auto& operator+=(const\
    \ square_matrix_dyn &that){\n      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];\n\
    \      return *this;\n    }\n\n    auto& operator-=(const square_matrix_dyn &that){\n\
    \      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n\
    \    }\n\n    auto& operator*=(const square_matrix_dyn &that){\n      square_matrix_dyn\
    \ ret;\n      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n\
    \          for(int k = 0; k < N; ++k)\n            ret[i][j] += data_[i][k] *\
    \ that.data_[k][j];\n      return *this = ret;\n    }\n\n    const auto& operator[](int\
    \ i) const {return data_[i];}\n    auto& operator[](int i){return data_[i];}\n\
    \    int size() const {return N;}\n\n    static auto unit(){\n      square_matrix_dyn\
    \ ret;\n      for(int i = 0; i < N; ++i) ret[i][i] = 1;\n      return ret;\n \
    \   }\n\n    auto operator+(const square_matrix_dyn &that){\n      return square_matrix_dyn(*this)\
    \ += that;\n    }\n    auto operator-(const square_matrix_dyn &that){\n      return\
    \ square_matrix_dyn(*this) -= that;\n    }\n    auto operator*(const square_matrix_dyn\
    \ &that){\n      return square_matrix_dyn(*this) *= that;\n    }\n\n    auto pow(uint64_t\
    \ p) const {\n      auto ret = unit();\n      auto a = *this;\n\n      while(p\
    \ > 0){\n        if(p & 1) ret *= a;\n        a *= a;\n        p >>= 1;\n    \
    \  }\n\n      return ret;\n    }\n\n    auto operator*(const vector_type &that){\n\
    \      vector_type ret;\n      for(int i = 0; i < N; ++i) ret[i] = dot(data_[i],\
    \ that);\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <cstdint>\n\
    #include <iostream>\n\nnamespace haar_lib {\n  template <typename T, int &N>\n\
    \  class vector_dyn {\n  public:\n    using value_type = T;\n\n  private:\n  \
    \  std::vector<T> data_;\n\n  public:\n    vector_dyn(): data_(N){}\n    vector_dyn(T\
    \ value): data_(N, value){}\n    vector_dyn(std::initializer_list<T> list): data_(N){\n\
    \      int i = 0;\n      for(auto it = list.begin(); it != list.end(); ++it) data_[i++]\
    \ = *it;\n    }\n    vector_dyn(const vector_dyn &that): data_(that.data_){}\n\
    \n    template <typename U>\n    vector_dyn(const std::vector<U> &that): data_(that.begin(),\
    \ that.end()){}\n\n    bool operator==(const vector_dyn &that){return data_ ==\
    \ that.data_;}\n    bool operator!=(const vector_dyn &that){return !(*this ==\
    \ that);}\n\n    auto& operator=(const vector_dyn &that){\n      data_ = that.data_;\n\
    \      return *this;\n    }\n\n    auto& operator+=(const vector_dyn &that){\n\
    \      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];\n      return *this;\n\
    \    }\n\n    auto& operator-=(const vector_dyn &that){\n      for(int i = 0;\
    \ i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n    }\n\n    friend\
    \ auto dot(const vector_dyn &a, const vector_dyn &b){\n      T ret = 0;\n    \
    \  for(int i = 0; i < N; ++i) ret += a.data_[i] * b.data_[i];\n      return ret;\n\
    \    }\n\n    auto operator+(const vector_dyn &that) const {\n      return vector(*this)\
    \ += that;\n    }\n\n    auto operator-(const vector_dyn &that) const {\n    \
    \  return vector(*this) -= that;\n    }\n\n    auto& operator[](int i){return\
    \ data_[i];}\n    const auto& operator[](int i) const {return data_[i];}\n   \
    \ auto begin() const {return data_.begin();}\n    auto end() const {return data_.end();}\n\
    \n    int size() const {return N;}\n\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const vector_dyn &a){\n      s << \"{\";\n      for(auto it = a.data_.begin();\
    \ it != a.data_.end(); ++it){\n        if(it != a.data_.begin()) s << \",\";\n\
    \        s << *it;\n      }\n      s << \"}\";\n      return s;\n    }\n  };\n\
    \n\n  template <typename T, int &N>\n  class square_matrix_dyn {\n  public:\n\
    \    using value_type = T;\n    using vector_type = vector_dyn<T, N>;\n\n  private:\n\
    \    std::vector<vector_type> data_;\n\n  public:\n    square_matrix_dyn(): data_(N,\
    \ vector_type()){}\n    square_matrix_dyn(const T &val): data_(N, vector_type(val)){}\n\
    \    square_matrix_dyn(std::initializer_list<std::initializer_list<T>> list):\
    \ data_(N){\n      int i = 0;\n      for(auto it = list.begin(); it != list.end();\
    \ ++it){\n        data_[i++] = vector_type(*it);\n      }\n    }\n    square_matrix_dyn(const\
    \ square_matrix_dyn &that): data_(that.data_){}\n    square_matrix_dyn(const std::vector<std::vector<T>>\
    \ &that): data_(N){\n      for(int i = 0; i < N; ++i) data_[i] = that[i];\n  \
    \  }\n\n    bool operator==(const square_matrix_dyn &that) const {return data_\
    \ == that.data_;}\n    bool operator!=(const square_matrix_dyn &that) const {return\
    \ !(*this == that);}\n\n    auto& operator=(const square_matrix_dyn &that){\n\
    \      data_ = that.data_;\n      return *this;\n    }\n\n    auto& operator+=(const\
    \ square_matrix_dyn &that){\n      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];\n\
    \      return *this;\n    }\n\n    auto& operator-=(const square_matrix_dyn &that){\n\
    \      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n\
    \    }\n\n    auto& operator*=(const square_matrix_dyn &that){\n      square_matrix_dyn\
    \ ret;\n      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n\
    \          for(int k = 0; k < N; ++k)\n            ret[i][j] += data_[i][k] *\
    \ that.data_[k][j];\n      return *this = ret;\n    }\n\n    const auto& operator[](int\
    \ i) const {return data_[i];}\n    auto& operator[](int i){return data_[i];}\n\
    \    int size() const {return N;}\n\n    static auto unit(){\n      square_matrix_dyn\
    \ ret;\n      for(int i = 0; i < N; ++i) ret[i][i] = 1;\n      return ret;\n \
    \   }\n\n    auto operator+(const square_matrix_dyn &that){\n      return square_matrix_dyn(*this)\
    \ += that;\n    }\n    auto operator-(const square_matrix_dyn &that){\n      return\
    \ square_matrix_dyn(*this) -= that;\n    }\n    auto operator*(const square_matrix_dyn\
    \ &that){\n      return square_matrix_dyn(*this) *= that;\n    }\n\n    auto pow(uint64_t\
    \ p) const {\n      auto ret = unit();\n      auto a = *this;\n\n      while(p\
    \ > 0){\n        if(p & 1) ret *= a;\n        a *= a;\n        p >>= 1;\n    \
    \  }\n\n      return ret;\n    }\n\n    auto operator*(const vector_type &that){\n\
    \      vector_type ret;\n      for(int i = 0; i < N; ++i) ret[i] = dot(data_[i],\
    \ that);\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/square_matrix.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:11:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/194/main.test.cpp
  - test/aoj/1327/main.test.cpp
  - test/yosupo-judge/matrix_det/main.test.cpp
documentation_of: Mylib/LinearAlgebra/square_matrix.cpp
layout: document
title: Square matrix
---

## Operations

## Requirements

## Notes

## Problems

## References
