---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/polynomial.cpp\"\n#include <vector>\n#include\
    \ <initializer_list>\n\nnamespace haar_lib {\n  template <typename T, const auto\
    \ &convolve>\n  class polynomial {\n    std::vector<T> data_;\n\n  public:\n \
    \   explicit polynomial(int N): data_(N){}\n    polynomial(std::vector<T> data):\
    \ data_(data){}\n    polynomial(std::initializer_list<T> data): data_(data.begin(),\
    \ data.end()){}\n\n    auto& data(){return data_;}\n    const auto& data() const\
    \ {return data_;}\n    int size() const {return data_.size();}\n\n    auto& operator+=(const\
    \ polynomial &that){\n      if(data_.size() < that.data_.size()) data_.resize(that.data_.size());\n\
    \      for(size_t i = 0; i < that.data_.size(); ++i) data_[i] += that.data_[i];\n\
    \      return *this;\n    }\n\n    auto& operator-=(const polynomial &that){\n\
    \      if(data_.size() < that.data_.size()) data_.resize(that.data_.size());\n\
    \      for(size_t i = 0; i < that.data_.size(); ++i) data_[i] -= that.data_[i];\n\
    \      return *this;\n    }\n\n    auto& operator*=(T k){\n      for(auto &x :\
    \ data_) x *= k;\n      return *this;\n    }\n\n    auto& operator/=(T k){\n \
    \     for(auto &x : data_) x /= k;\n      return *this;\n    }\n\n    auto& operator*=(const\
    \ polynomial &that){\n      const int k = data_.size() + that.data_.size() - 1;\n\
    \      data_ = convolve(data_, that.data_);\n      data_.resize(k);\n      return\
    \ *this;\n    }\n\n    auto operator+(const polynomial &that) const {\n      return\
    \ polynomial(*this) += that;\n    }\n\n    auto operator-(const polynomial &that)\
    \ const {\n      return polynomial(*this) -= that;\n    }\n\n    auto operator*(T\
    \ k) const {\n      return polynomial(*this) *= k;\n    }\n\n    auto operator/(T\
    \ k) const {\n      return polynomial(*this) /= k;\n    }\n\n    auto operator*(const\
    \ polynomial &that) const {\n      return polynomial(*this) *= that;\n    }\n\n\
    \    auto differentiate() const {\n      polynomial ret((int)data_.size() - 1);\n\
    \      for(int i = 0; i < (int)ret.data_.size(); ++i){\n        ret.data_[i] =\
    \ data_[i + 1] * (i + 1);\n      }\n      return ret;\n    }\n\n    auto integrate()\
    \ const {\n      polynomial ret((int)data_.size() + 1);\n      for(int i = 1;\
    \ i < (int)ret.data_.size(); ++i){\n        ret.data_[i] = data_[i - 1] / i;\n\
    \      }\n\n      return ret;\n    }\n\n    auto integrate(T lb, T ub) const {\n\
    \      T ret = 0, x1 = 1, x2 = 1;\n      for(int i = 0; i < (int)data_.size();\
    \ ++i){\n        x1 *= lb;\n        x2 *= ub;\n        ret += data_[i] / (i +\
    \ 1) * (x2 - x1);\n      }\n\n      return ret;\n    }\n\n    auto shift(int k)\
    \ const {\n      polynomial ret((int)data_.size() + k);\n      for(int i = 0;\
    \ i < (int)data_.size(); ++i){\n        ret.data_[i + k] = data_[i];\n      }\n\
    \n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <initializer_list>\n\nnamespace\
    \ haar_lib {\n  template <typename T, const auto &convolve>\n  class polynomial\
    \ {\n    std::vector<T> data_;\n\n  public:\n    explicit polynomial(int N): data_(N){}\n\
    \    polynomial(std::vector<T> data): data_(data){}\n    polynomial(std::initializer_list<T>\
    \ data): data_(data.begin(), data.end()){}\n\n    auto& data(){return data_;}\n\
    \    const auto& data() const {return data_;}\n    int size() const {return data_.size();}\n\
    \n    auto& operator+=(const polynomial &that){\n      if(data_.size() < that.data_.size())\
    \ data_.resize(that.data_.size());\n      for(size_t i = 0; i < that.data_.size();\
    \ ++i) data_[i] += that.data_[i];\n      return *this;\n    }\n\n    auto& operator-=(const\
    \ polynomial &that){\n      if(data_.size() < that.data_.size()) data_.resize(that.data_.size());\n\
    \      for(size_t i = 0; i < that.data_.size(); ++i) data_[i] -= that.data_[i];\n\
    \      return *this;\n    }\n\n    auto& operator*=(T k){\n      for(auto &x :\
    \ data_) x *= k;\n      return *this;\n    }\n\n    auto& operator/=(T k){\n \
    \     for(auto &x : data_) x /= k;\n      return *this;\n    }\n\n    auto& operator*=(const\
    \ polynomial &that){\n      const int k = data_.size() + that.data_.size() - 1;\n\
    \      data_ = convolve(data_, that.data_);\n      data_.resize(k);\n      return\
    \ *this;\n    }\n\n    auto operator+(const polynomial &that) const {\n      return\
    \ polynomial(*this) += that;\n    }\n\n    auto operator-(const polynomial &that)\
    \ const {\n      return polynomial(*this) -= that;\n    }\n\n    auto operator*(T\
    \ k) const {\n      return polynomial(*this) *= k;\n    }\n\n    auto operator/(T\
    \ k) const {\n      return polynomial(*this) /= k;\n    }\n\n    auto operator*(const\
    \ polynomial &that) const {\n      return polynomial(*this) *= that;\n    }\n\n\
    \    auto differentiate() const {\n      polynomial ret((int)data_.size() - 1);\n\
    \      for(int i = 0; i < (int)ret.data_.size(); ++i){\n        ret.data_[i] =\
    \ data_[i + 1] * (i + 1);\n      }\n      return ret;\n    }\n\n    auto integrate()\
    \ const {\n      polynomial ret((int)data_.size() + 1);\n      for(int i = 1;\
    \ i < (int)ret.data_.size(); ++i){\n        ret.data_[i] = data_[i - 1] / i;\n\
    \      }\n\n      return ret;\n    }\n\n    auto integrate(T lb, T ub) const {\n\
    \      T ret = 0, x1 = 1, x2 = 1;\n      for(int i = 0; i < (int)data_.size();\
    \ ++i){\n        x1 *= lb;\n        x2 *= ub;\n        ret += data_[i] / (i +\
    \ 1) * (x2 - x1);\n      }\n\n      return ret;\n    }\n\n    auto shift(int k)\
    \ const {\n      polynomial ret((int)data_.size() + k);\n      for(int i = 0;\
    \ i < (int)data_.size(); ++i){\n        ret.data_[i + k] = data_[i];\n      }\n\
    \n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/polynomial.cpp
  requiredBy: []
  timestamp: '2020-10-18 10:24:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Math/polynomial.cpp
layout: document
title: Polynomial
---

## Operations

## Requirements

## Notes

## Problems

## References
