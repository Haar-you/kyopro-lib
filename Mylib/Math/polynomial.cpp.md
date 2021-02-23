---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/multipoint_evaluation/main.test.cpp
    title: test/yosupo-judge/multipoint_evaluation/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/polynomial.cpp\"\n#include <vector>\n#include\
    \ <initializer_list>\n#include <algorithm>\n\nnamespace haar_lib {\n  template\
    \ <typename T, const auto &convolve>\n  class polynomial {\n  public:\n    using\
    \ value_type = T;\n\n  private:\n    std::vector<T> data_;\n\n  public:\n    explicit\
    \ polynomial(int N): data_(N){}\n    polynomial(std::vector<T> data): data_(data){}\n\
    \    polynomial(std::initializer_list<T> data): data_(data.begin(), data.end()){}\n\
    \n    auto& data(){return data_;}\n    const auto& data() const {return data_;}\n\
    \    size_t size() const {return data_.size();}\n    auto begin(){return data_.begin();}\n\
    \    auto end(){return data_.end();}\n\n    const auto& operator[](size_t i) const\
    \ {return data_[i];}\n    auto& operator[](size_t i){return data_[i];}\n\n   \
    \ auto get(int n) const {\n      return polynomial(std::vector(data_.begin(),\
    \ data_.begin() + std::min<int>(n, data_.size())));\n    }\n\n    int shrink(){\n\
    \      while(not data_.empty() and data_.back() == 0){\n        data_.pop_back();\n\
    \      }\n      return data_.size();\n    }\n\n    auto& operator+=(const polynomial\
    \ &that){\n      if(data_.size() < that.data_.size()) data_.resize(that.data_.size());\n\
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
    \n      return ret;\n    }\n\n    auto square() const {\n      const int k = data_.size()\
    \ * 2 - 1;\n      auto ret = convolve(data_, data_, true);\n      ret.resize(k);\n\
    \      return polynomial(ret);\n    }\n\n    auto inv(int n) const {\n      polynomial\
    \ ret({data_[0].inv()});\n      int t = 1;\n\n      while(t <= n * 2){\n     \
    \   ret = ret * T(2) - ret.square().get(t) * (*this).get(t);\n        if((int)ret.data_.size()\
    \ > t) ret.data_.resize(t);\n        t *= 2;\n      }\n\n      return ret;\n \
    \   }\n\n    std::pair<polynomial, polynomial> divmod(const polynomial &that)\
    \ const {\n      if(data_.size() < that.size()) return {{0}, *this};\n\n     \
    \ const int m = data_.size() - that.size();\n\n      auto g = *this;\n      std::reverse(g.begin(),\
    \ g.end());\n\n      auto f = that;\n      const int d = (int)that.size() - 1;\n\
    \      std::reverse(f.begin(), f.end());\n\n      f = f.inv(m);\n\n      f.data_.resize(m\
    \ + 1);\n\n      auto q = f * g;\n      q.data_.resize(m + 1);\n\n      std::reverse(q.begin(),\
    \ q.end());\n\n      auto r = (*this) - that * q;\n      r.data_.resize(d);\n\n\
    \      r.shrink();\n      q.shrink();\n\n      return {q, r};\n    }\n\n    auto&\
    \ operator/=(const polynomial &that){\n      *this = divmod(that).first;\n   \
    \   return *this;\n    }\n\n    auto& operator%=(const polynomial &that){\n  \
    \    *this = divmod(that).second;\n      return *this;\n    }\n\n    auto operator/(const\
    \ polynomial &that) const {\n      return polynomial(*this) /= that;\n    }\n\n\
    \    auto operator%(const polynomial &that) const {\n      return polynomial(*this)\
    \ %= that;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <initializer_list>\n#include <algorithm>\n\
    \nnamespace haar_lib {\n  template <typename T, const auto &convolve>\n  class\
    \ polynomial {\n  public:\n    using value_type = T;\n\n  private:\n    std::vector<T>\
    \ data_;\n\n  public:\n    explicit polynomial(int N): data_(N){}\n    polynomial(std::vector<T>\
    \ data): data_(data){}\n    polynomial(std::initializer_list<T> data): data_(data.begin(),\
    \ data.end()){}\n\n    auto& data(){return data_;}\n    const auto& data() const\
    \ {return data_;}\n    size_t size() const {return data_.size();}\n    auto begin(){return\
    \ data_.begin();}\n    auto end(){return data_.end();}\n\n    const auto& operator[](size_t\
    \ i) const {return data_[i];}\n    auto& operator[](size_t i){return data_[i];}\n\
    \n    auto get(int n) const {\n      return polynomial(std::vector(data_.begin(),\
    \ data_.begin() + std::min<int>(n, data_.size())));\n    }\n\n    int shrink(){\n\
    \      while(not data_.empty() and data_.back() == 0){\n        data_.pop_back();\n\
    \      }\n      return data_.size();\n    }\n\n    auto& operator+=(const polynomial\
    \ &that){\n      if(data_.size() < that.data_.size()) data_.resize(that.data_.size());\n\
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
    \n      return ret;\n    }\n\n    auto square() const {\n      const int k = data_.size()\
    \ * 2 - 1;\n      auto ret = convolve(data_, data_, true);\n      ret.resize(k);\n\
    \      return polynomial(ret);\n    }\n\n    auto inv(int n) const {\n      polynomial\
    \ ret({data_[0].inv()});\n      int t = 1;\n\n      while(t <= n * 2){\n     \
    \   ret = ret * T(2) - ret.square().get(t) * (*this).get(t);\n        if((int)ret.data_.size()\
    \ > t) ret.data_.resize(t);\n        t *= 2;\n      }\n\n      return ret;\n \
    \   }\n\n    std::pair<polynomial, polynomial> divmod(const polynomial &that)\
    \ const {\n      if(data_.size() < that.size()) return {{0}, *this};\n\n     \
    \ const int m = data_.size() - that.size();\n\n      auto g = *this;\n      std::reverse(g.begin(),\
    \ g.end());\n\n      auto f = that;\n      const int d = (int)that.size() - 1;\n\
    \      std::reverse(f.begin(), f.end());\n\n      f = f.inv(m);\n\n      f.data_.resize(m\
    \ + 1);\n\n      auto q = f * g;\n      q.data_.resize(m + 1);\n\n      std::reverse(q.begin(),\
    \ q.end());\n\n      auto r = (*this) - that * q;\n      r.data_.resize(d);\n\n\
    \      r.shrink();\n      q.shrink();\n\n      return {q, r};\n    }\n\n    auto&\
    \ operator/=(const polynomial &that){\n      *this = divmod(that).first;\n   \
    \   return *this;\n    }\n\n    auto& operator%=(const polynomial &that){\n  \
    \    *this = divmod(that).second;\n      return *this;\n    }\n\n    auto operator/(const\
    \ polynomial &that) const {\n      return polynomial(*this) /= that;\n    }\n\n\
    \    auto operator%(const polynomial &that) const {\n      return polynomial(*this)\
    \ %= that;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/polynomial.cpp
  requiredBy: []
  timestamp: '2021-02-20 08:15:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/multipoint_evaluation/main.test.cpp
documentation_of: Mylib/Math/polynomial.cpp
layout: document
title: Polynomial
---

## Operations

## Requirements

## Notes

## Problems

## References
