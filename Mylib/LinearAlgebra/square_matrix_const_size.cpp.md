---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/510/main.test.cpp
    title: test/yukicoder/510/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/square_matrix_const_size.cpp\"\n#include\
    \ <array>\n#include <initializer_list>\n#include <utility>\n#include <iostream>\n\
    \nnamespace haar_lib {\n  template <typename T, int N>\n  class vector_const {\n\
    \  public:\n    using value_type = T;\n\n  private:\n    std::array<T, N> data_;\n\
    \n  public:\n    vector_const(){data_.fill(0);}\n    vector_const(T value){data_.fill(value);}\n\
    \    vector_const(std::initializer_list<T> list){\n      int i = 0;\n      for(auto\
    \ it = list.begin(); it != list.end(); ++it) data_[i++] = *it;\n    }\n    vector_const(const\
    \ vector_const &that): data_(that.data_){}\n\n    bool operator==(const vector_const\
    \ &that){return data_ == that.data_;}\n    bool operator!=(const vector_const\
    \ &that){return !(*this == that);}\n\n    auto& operator=(const vector_const &that){\n\
    \      data_ = that.data_;\n      return *this;\n    }\n\n    auto& operator+=(const\
    \ vector_const &that){\n      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];\n\
    \      return *this;\n    }\n\n    auto& operator-=(const vector_const &that){\n\
    \      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n\
    \    }\n\n    friend auto dot(const vector_const &a, const vector_const &b){\n\
    \      T ret = 0;\n      for(int i = 0; i < N; ++i) ret += a.data_[i] * b.data_[i];\n\
    \      return ret;\n    }\n\n    auto operator+(const vector_const &that) const\
    \ {\n      return vector_const(*this) += that;\n    }\n\n    auto operator-(const\
    \ vector_const &that) const {\n      return vector_const(*this) -= that;\n   \
    \ }\n\n    auto& operator[](int i){return data_[i];}\n    const auto& operator[](int\
    \ i) const {return data_[i];}\n    auto begin() const {return data_.begin();}\n\
    \    auto end() const {return data_.end();}\n\n    int size() const {return N;}\n\
    \n    friend std::ostream& operator<<(std::ostream &s, const vector_const &a){\n\
    \      s << \"{\";\n      for(auto it = a.data_.begin(); it != a.data_.end();\
    \ ++it){\n        if(it != a.data_.begin()) s << \",\";\n        s << *it;\n \
    \     }\n      s << \"}\";\n      return s;\n    }\n  };\n\n\n  template <typename\
    \ T, int N>\n  class square_matrix_const {\n  public:\n    using value_type =\
    \ T;\n    using vector_type = vector_const<T, N>;\n\n  private:\n    std::array<vector_type,\
    \ N> data_;\n\n  public:\n    square_matrix_const(){\n      for(int i = 0; i <\
    \ N; ++i) data_[i] = vector_type();\n    }\n    square_matrix_const(const T &val){\n\
    \      for(int i = 0; i < N; ++i) data_[i] = vector_type(val);\n    }\n    square_matrix_const(std::initializer_list<std::initializer_list<T>>\
    \ list){\n      int i = 0;\n      for(auto it = list.begin(); it != list.end();\
    \ ++it){\n        data_[i++] = vector_type(*it);\n      }\n    }\n    square_matrix_const(const\
    \ square_matrix_const &that): data_(that.data_){}\n\n    bool operator==(const\
    \ square_matrix_const &that) const {return data_ == that.data_;}\n    bool operator!=(const\
    \ square_matrix_const &that) const {return !(*this == that);}\n\n    auto& operator=(const\
    \ square_matrix_const &that){\n      data_ = that.data_;\n      return *this;\n\
    \    }\n\n    auto& operator+=(const square_matrix_const &that){\n      for(int\
    \ i = 0; i < N; ++i) data_[i] += that.data_[i];\n      return *this;\n    }\n\n\
    \    auto& operator-=(const square_matrix_const &that){\n      for(int i = 0;\
    \ i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n    }\n\n    auto&\
    \ operator*=(const square_matrix_const &that){\n      square_matrix_const ret;\n\
    \      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n      \
    \    for(int k = 0; k < N; ++k)\n            ret[i][j] += data_[i][k] * that.data_[k][j];\n\
    \      return *this = ret;\n    }\n\n    const auto& operator[](int i) const {return\
    \ data_[i];}\n    auto& operator[](int i){return data_[i];}\n    int size() const\
    \ {return N;}\n\n    static auto unit(){\n      square_matrix_const ret;\n   \
    \   for(int i = 0; i < N; ++i) ret[i][i] = 1;\n      return ret;\n    }\n\n  \
    \  auto operator+(const square_matrix_const &that) const {\n      return square_matrix_const(*this)\
    \ += that;\n    }\n    auto operator-(const square_matrix_const &that) const {\n\
    \      return square_matrix_const(*this) -= that;\n    }\n    auto operator*(const\
    \ square_matrix_const &that) const {\n      return square_matrix_const(*this)\
    \ *= that;\n    }\n\n    auto pow(uint64_t p) const {\n      auto ret = unit();\n\
    \      auto a = *this;\n\n      while(p > 0){\n        if(p & 1) ret *= a;\n \
    \       a *= a;\n        p >>= 1;\n      }\n\n      return ret;\n    }\n\n   \
    \ auto operator*(const vector_type &that) const {\n      vector_type ret;\n  \
    \    for(int i = 0; i < N; ++i) ret[i] = dot(data_[i], that);\n      return ret;\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <array>\n#include <initializer_list>\n#include <utility>\n\
    #include <iostream>\n\nnamespace haar_lib {\n  template <typename T, int N>\n\
    \  class vector_const {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    std::array<T, N> data_;\n\n  public:\n    vector_const(){data_.fill(0);}\n\
    \    vector_const(T value){data_.fill(value);}\n    vector_const(std::initializer_list<T>\
    \ list){\n      int i = 0;\n      for(auto it = list.begin(); it != list.end();\
    \ ++it) data_[i++] = *it;\n    }\n    vector_const(const vector_const &that):\
    \ data_(that.data_){}\n\n    bool operator==(const vector_const &that){return\
    \ data_ == that.data_;}\n    bool operator!=(const vector_const &that){return\
    \ !(*this == that);}\n\n    auto& operator=(const vector_const &that){\n     \
    \ data_ = that.data_;\n      return *this;\n    }\n\n    auto& operator+=(const\
    \ vector_const &that){\n      for(int i = 0; i < N; ++i) data_[i] += that.data_[i];\n\
    \      return *this;\n    }\n\n    auto& operator-=(const vector_const &that){\n\
    \      for(int i = 0; i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n\
    \    }\n\n    friend auto dot(const vector_const &a, const vector_const &b){\n\
    \      T ret = 0;\n      for(int i = 0; i < N; ++i) ret += a.data_[i] * b.data_[i];\n\
    \      return ret;\n    }\n\n    auto operator+(const vector_const &that) const\
    \ {\n      return vector_const(*this) += that;\n    }\n\n    auto operator-(const\
    \ vector_const &that) const {\n      return vector_const(*this) -= that;\n   \
    \ }\n\n    auto& operator[](int i){return data_[i];}\n    const auto& operator[](int\
    \ i) const {return data_[i];}\n    auto begin() const {return data_.begin();}\n\
    \    auto end() const {return data_.end();}\n\n    int size() const {return N;}\n\
    \n    friend std::ostream& operator<<(std::ostream &s, const vector_const &a){\n\
    \      s << \"{\";\n      for(auto it = a.data_.begin(); it != a.data_.end();\
    \ ++it){\n        if(it != a.data_.begin()) s << \",\";\n        s << *it;\n \
    \     }\n      s << \"}\";\n      return s;\n    }\n  };\n\n\n  template <typename\
    \ T, int N>\n  class square_matrix_const {\n  public:\n    using value_type =\
    \ T;\n    using vector_type = vector_const<T, N>;\n\n  private:\n    std::array<vector_type,\
    \ N> data_;\n\n  public:\n    square_matrix_const(){\n      for(int i = 0; i <\
    \ N; ++i) data_[i] = vector_type();\n    }\n    square_matrix_const(const T &val){\n\
    \      for(int i = 0; i < N; ++i) data_[i] = vector_type(val);\n    }\n    square_matrix_const(std::initializer_list<std::initializer_list<T>>\
    \ list){\n      int i = 0;\n      for(auto it = list.begin(); it != list.end();\
    \ ++it){\n        data_[i++] = vector_type(*it);\n      }\n    }\n    square_matrix_const(const\
    \ square_matrix_const &that): data_(that.data_){}\n\n    bool operator==(const\
    \ square_matrix_const &that) const {return data_ == that.data_;}\n    bool operator!=(const\
    \ square_matrix_const &that) const {return !(*this == that);}\n\n    auto& operator=(const\
    \ square_matrix_const &that){\n      data_ = that.data_;\n      return *this;\n\
    \    }\n\n    auto& operator+=(const square_matrix_const &that){\n      for(int\
    \ i = 0; i < N; ++i) data_[i] += that.data_[i];\n      return *this;\n    }\n\n\
    \    auto& operator-=(const square_matrix_const &that){\n      for(int i = 0;\
    \ i < N; ++i) data_[i] -= that.data_[i];\n      return *this;\n    }\n\n    auto&\
    \ operator*=(const square_matrix_const &that){\n      square_matrix_const ret;\n\
    \      for(int i = 0; i < N; ++i)\n        for(int j = 0; j < N; ++j)\n      \
    \    for(int k = 0; k < N; ++k)\n            ret[i][j] += data_[i][k] * that.data_[k][j];\n\
    \      return *this = ret;\n    }\n\n    const auto& operator[](int i) const {return\
    \ data_[i];}\n    auto& operator[](int i){return data_[i];}\n    int size() const\
    \ {return N;}\n\n    static auto unit(){\n      square_matrix_const ret;\n   \
    \   for(int i = 0; i < N; ++i) ret[i][i] = 1;\n      return ret;\n    }\n\n  \
    \  auto operator+(const square_matrix_const &that) const {\n      return square_matrix_const(*this)\
    \ += that;\n    }\n    auto operator-(const square_matrix_const &that) const {\n\
    \      return square_matrix_const(*this) -= that;\n    }\n    auto operator*(const\
    \ square_matrix_const &that) const {\n      return square_matrix_const(*this)\
    \ *= that;\n    }\n\n    auto pow(uint64_t p) const {\n      auto ret = unit();\n\
    \      auto a = *this;\n\n      while(p > 0){\n        if(p & 1) ret *= a;\n \
    \       a *= a;\n        p >>= 1;\n      }\n\n      return ret;\n    }\n\n   \
    \ auto operator*(const vector_type &that) const {\n      vector_type ret;\n  \
    \    for(int i = 0; i < N; ++i) ret[i] = dot(data_[i], that);\n      return ret;\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/square_matrix_const_size.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:11:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/510/main.test.cpp
documentation_of: Mylib/LinearAlgebra/square_matrix_const_size.cpp
layout: document
title: Square matrix (Const size)
---

## Operations

## Requirements

## Notes

## Problems

## References
