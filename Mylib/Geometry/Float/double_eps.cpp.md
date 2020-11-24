---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2136/main.test.cpp
    title: test/aoj/2136/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3034/main.test.cpp
    title: test/aoj/3034/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A/main.test.cpp
    title: test/aoj/CGL_1_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B/main.test.cpp
    title: test/aoj/CGL_1_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_C/main.test.cpp
    title: test/aoj/CGL_1_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_A/main.test.cpp
    title: test/aoj/CGL_2_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_B/main.test.cpp
    title: test/aoj/CGL_2_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C/main.test.cpp
    title: test/aoj/CGL_2_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_D/main.test.cpp
    title: test/aoj/CGL_2_D/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_A/main.test.cpp
    title: test/aoj/CGL_3_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B/main.test.cpp
    title: test/aoj/CGL_3_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_C/main.test.cpp
    title: test/aoj/CGL_3_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_A/main.test.cpp
    title: test/aoj/CGL_4_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B/main.test.cpp
    title: test/aoj/CGL_4_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C/main.test.cpp
    title: test/aoj/CGL_4_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A/main.test.cpp
    title: test/aoj/CGL_5_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_A/main.test.cpp
    title: test/aoj/CGL_7_A/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B/main.test.cpp
    title: test/aoj/CGL_7_B/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C/main.test.cpp
    title: test/aoj/CGL_7_C/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_D/main.test.cpp
    title: test/aoj/CGL_7_D/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_E/main.test.cpp
    title: test/aoj/CGL_7_E/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_F/main.test.cpp
    title: test/aoj/CGL_7_F/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_G/main.test.cpp
    title: test/aoj/CGL_7_G/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_H/main.test.cpp
    title: test/aoj/CGL_7_H/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_I/main.test.cpp
    title: test/aoj/CGL_7_I/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Geometry/Float/double_eps.cpp\"\n#include <iostream>\n\
    #include <limits>\n#include <cmath>\n\nnamespace haar_lib {\n  template <typename\
    \ T, const T &eps>\n  struct double_eps {\n    using value_type = T;\n\n  private:\n\
    \    T value_;\n\n  public:\n    double_eps(): value_(0){}\n    double_eps(T value_):\
    \ value_(value_){}\n\n    auto& operator=(const double_eps &rhs){this->value_\
    \ = rhs.value_; return *this;}\n    auto& operator+=(const double_eps &rhs){this->value_\
    \ += rhs.value_; return *this;}\n    auto& operator-=(const double_eps &rhs){this->value_\
    \ -= rhs.value_; return *this;}\n    auto& operator*=(const double_eps &rhs){this->value_\
    \ *= rhs.value_; return *this;}\n    auto& operator/=(const double_eps &rhs){this->value_\
    \ /= rhs.value_; return *this;}\n\n    auto operator+(const double_eps &rhs) const\
    \ {return double_eps(this->value_ + rhs.value_);}\n    auto operator-(const double_eps\
    \ &rhs) const {return double_eps(this->value_ - rhs.value_);}\n    auto operator*(const\
    \ double_eps &rhs) const {return double_eps(this->value_ * rhs.value_);}\n   \
    \ auto operator/(const double_eps &rhs) const {return double_eps(this->value_\
    \ / rhs.value_);}\n\n    bool operator==(const double_eps &rhs) const {return\
    \ std::abs(this->value_ - rhs.value_) < eps;}\n    bool operator!=(const double_eps\
    \ &rhs) const {return !(*this == rhs);}\n    bool operator<(const double_eps &rhs)\
    \ const {return this->value_ - rhs.value_ < -eps;}\n    bool operator<=(const\
    \ double_eps &rhs) const {return this->value_ - rhs.value_ < eps;}\n    bool operator>(const\
    \ double_eps &rhs) const {return !(*this <= rhs);}\n    bool operator>=(const\
    \ double_eps &rhs) const {return !(*this < rhs);}\n\n    auto operator-() const\
    \ {return double_eps(-(this->value_));}\n\n    explicit operator double() const\
    \ noexcept {return value_;}\n    explicit operator long double() const noexcept\
    \ {return value_;}\n\n    friend std::ostream& operator<<(std::ostream &s, const\
    \ double_eps &rhs){s << rhs.value_; return s;}\n    friend std::istream& operator>>(std::istream\
    \ &s, double_eps &rhs){s >> rhs.value_; return s;}\n\n    friend double_eps sin(double_eps\
    \ x){return std::sin((T)x);}\n    friend double_eps cos(double_eps x){return std::cos((T)x);}\n\
    \    friend double_eps tan(double_eps x){return std::tan((T)x);}\n    friend double_eps\
    \ acos(double_eps x){return std::acos((T)x);}\n    friend double_eps atan2(double_eps\
    \ y, double_eps x){return std::atan2((T)y, (T)x);}\n    friend double_eps abs(double_eps\
    \ x){return std::abs((T)x);}\n    friend double_eps sqrt(double_eps x){return\
    \ std::sqrt(std::max<T>(0, (T)x));}\n  };\n}\n\nnamespace std {\n  template <typename\
    \ T, const T &eps>\n  class numeric_limits<haar_lib::double_eps<T, eps>> {\n \
    \ public:\n    static haar_lib::double_eps<T, eps> infinity() {return numeric_limits<T>::infinity();}\n\
    \    static haar_lib::double_eps<T, eps> min() {return numeric_limits<T>::min();}\n\
    \    static haar_lib::double_eps<T, eps> max() {return numeric_limits<T>::max();}\n\
    \    static haar_lib::double_eps<T, eps> lowest() {return numeric_limits<T>::lowest();}\n\
    \  };\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <limits>\n#include <cmath>\n\n\
    namespace haar_lib {\n  template <typename T, const T &eps>\n  struct double_eps\
    \ {\n    using value_type = T;\n\n  private:\n    T value_;\n\n  public:\n   \
    \ double_eps(): value_(0){}\n    double_eps(T value_): value_(value_){}\n\n  \
    \  auto& operator=(const double_eps &rhs){this->value_ = rhs.value_; return *this;}\n\
    \    auto& operator+=(const double_eps &rhs){this->value_ += rhs.value_; return\
    \ *this;}\n    auto& operator-=(const double_eps &rhs){this->value_ -= rhs.value_;\
    \ return *this;}\n    auto& operator*=(const double_eps &rhs){this->value_ *=\
    \ rhs.value_; return *this;}\n    auto& operator/=(const double_eps &rhs){this->value_\
    \ /= rhs.value_; return *this;}\n\n    auto operator+(const double_eps &rhs) const\
    \ {return double_eps(this->value_ + rhs.value_);}\n    auto operator-(const double_eps\
    \ &rhs) const {return double_eps(this->value_ - rhs.value_);}\n    auto operator*(const\
    \ double_eps &rhs) const {return double_eps(this->value_ * rhs.value_);}\n   \
    \ auto operator/(const double_eps &rhs) const {return double_eps(this->value_\
    \ / rhs.value_);}\n\n    bool operator==(const double_eps &rhs) const {return\
    \ std::abs(this->value_ - rhs.value_) < eps;}\n    bool operator!=(const double_eps\
    \ &rhs) const {return !(*this == rhs);}\n    bool operator<(const double_eps &rhs)\
    \ const {return this->value_ - rhs.value_ < -eps;}\n    bool operator<=(const\
    \ double_eps &rhs) const {return this->value_ - rhs.value_ < eps;}\n    bool operator>(const\
    \ double_eps &rhs) const {return !(*this <= rhs);}\n    bool operator>=(const\
    \ double_eps &rhs) const {return !(*this < rhs);}\n\n    auto operator-() const\
    \ {return double_eps(-(this->value_));}\n\n    explicit operator double() const\
    \ noexcept {return value_;}\n    explicit operator long double() const noexcept\
    \ {return value_;}\n\n    friend std::ostream& operator<<(std::ostream &s, const\
    \ double_eps &rhs){s << rhs.value_; return s;}\n    friend std::istream& operator>>(std::istream\
    \ &s, double_eps &rhs){s >> rhs.value_; return s;}\n\n    friend double_eps sin(double_eps\
    \ x){return std::sin((T)x);}\n    friend double_eps cos(double_eps x){return std::cos((T)x);}\n\
    \    friend double_eps tan(double_eps x){return std::tan((T)x);}\n    friend double_eps\
    \ acos(double_eps x){return std::acos((T)x);}\n    friend double_eps atan2(double_eps\
    \ y, double_eps x){return std::atan2((T)y, (T)x);}\n    friend double_eps abs(double_eps\
    \ x){return std::abs((T)x);}\n    friend double_eps sqrt(double_eps x){return\
    \ std::sqrt(std::max<T>(0, (T)x));}\n  };\n}\n\nnamespace std {\n  template <typename\
    \ T, const T &eps>\n  class numeric_limits<haar_lib::double_eps<T, eps>> {\n \
    \ public:\n    static haar_lib::double_eps<T, eps> infinity() {return numeric_limits<T>::infinity();}\n\
    \    static haar_lib::double_eps<T, eps> min() {return numeric_limits<T>::min();}\n\
    \    static haar_lib::double_eps<T, eps> max() {return numeric_limits<T>::max();}\n\
    \    static haar_lib::double_eps<T, eps> lowest() {return numeric_limits<T>::lowest();}\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Geometry/Float/double_eps.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_1_B/main.test.cpp
  - test/aoj/CGL_7_D/main.test.cpp
  - test/aoj/CGL_7_A/main.test.cpp
  - test/aoj/CGL_2_D/main.test.cpp
  - test/aoj/2136/main.test.cpp
  - test/aoj/CGL_7_G/main.test.cpp
  - test/aoj/CGL_7_I/main.test.cpp
  - test/aoj/CGL_3_C/main.test.cpp
  - test/aoj/CGL_7_B/main.test.cpp
  - test/aoj/CGL_7_H/main.test.cpp
  - test/aoj/CGL_2_B/main.test.cpp
  - test/aoj/3034/main.test.cpp
  - test/aoj/CGL_7_C/main.test.cpp
  - test/aoj/CGL_1_C/main.test.cpp
  - test/aoj/CGL_4_A/main.test.cpp
  - test/aoj/CGL_2_C/main.test.cpp
  - test/aoj/CGL_7_E/main.test.cpp
  - test/aoj/CGL_3_A/main.test.cpp
  - test/aoj/CGL_2_A/main.test.cpp
  - test/aoj/CGL_4_B/main.test.cpp
  - test/aoj/CGL_4_C/main.test.cpp
  - test/aoj/CGL_1_A/main.test.cpp
  - test/aoj/CGL_5_A/main.test.cpp
  - test/aoj/CGL_7_F/main.test.cpp
  - test/aoj/CGL_3_B/main.test.cpp
documentation_of: Mylib/Geometry/Float/double_eps.cpp
layout: document
title: Floating point number with eps
---

## Operations

## Requirements

## Notes

## Problems

## References
