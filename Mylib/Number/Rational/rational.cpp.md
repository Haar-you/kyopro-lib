---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1300/main.test.cpp
    title: test/aoj/1300/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Rational/rational.cpp\"\n#include <cmath>\n\
    #include <iostream>\n#include <numeric>\n\nnamespace haar_lib {\n  class rational\
    \ {\n    int64_t nume_, deno_;\n\n  public:\n    rational() : nume_(0), deno_(1)\
    \ {}\n    rational(int64_t nume) : nume_(nume), deno_(1) {}\n    rational(int64_t\
    \ nume, int64_t deno) {\n      const int64_t g = std::gcd(nume, deno);\n     \
    \ nume_           = nume / g;\n      deno_           = deno / g;\n      if (deno_\
    \ < 0) {\n        nume_ = -nume_;\n        deno_ = -deno_;\n      }\n    }\n\n\
    \    int64_t numerator() const { return nume_; }\n    int64_t denominator() const\
    \ { return deno_; }\n\n    auto operator+(const rational &b) {\n      int64_t\
    \ l = std::lcm((*this).deno_, b.deno_);\n      return rational(l / (*this).deno_\
    \ * (*this).nume_ + l / b.deno_ * b.nume_, l);\n    }\n\n    auto operator-(const\
    \ rational &b) {\n      int64_t l = std::lcm((*this).deno_, b.deno_);\n      return\
    \ rational(l / (*this).deno_ * (*this).nume_ - l / b.deno_ * b.nume_, l);\n  \
    \  }\n\n    auto operator*(const rational &b) {\n      return rational((*this).nume_\
    \ * b.nume_, (*this).deno_ * b.deno_);\n    }\n\n    auto operator/(const rational\
    \ &b) {\n      return rational((*this).nume_ * b.deno_, (*this).deno_ * b.nume_);\n\
    \    }\n\n    auto &operator+=(const rational &a) {\n      *this = *this + a;\n\
    \      return *this;\n    }\n    auto &operator-=(const rational &a) {\n     \
    \ *this = *this - a;\n      return *this;\n    }\n    auto &operator*=(const rational\
    \ &a) {\n      *this = *this * a;\n      return *this;\n    }\n    auto &operator/=(const\
    \ rational &a) {\n      *this = *this / a;\n      return *this;\n    }\n\n   \
    \ explicit operator double() const { return (double) nume_ / deno_; }\n    explicit\
    \ operator long double() const { return (long double) nume_ / deno_; }\n\n   \
    \ auto operator-() { return rational(-nume_, deno_); }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const rational &r) {\n      if (r.deno_ == 1)\n\
    \        os << r.nume_;\n      else\n        os << r.nume_ << \"/\" << r.deno_;\n\
    \      return os;\n    }\n\n    friend bool operator==(const rational &a, const\
    \ rational &b) { return a.nume_ == b.nume_ and a.deno_ == b.deno_; }\n    friend\
    \ bool operator!=(const rational &a, const rational &b) { return !(a == b); }\n\
    \    friend bool operator<(const rational &a, const rational &b) { return a.nume_\
    \ * b.deno_ < b.nume_ * a.deno_; }\n    friend bool operator<=(const rational\
    \ &a, const rational &b) { return a.nume_ * b.deno_ <= b.nume_ * a.deno_; }\n\
    \    friend bool operator>(const rational &a, const rational &b) { return !(a\
    \ <= b); }\n    friend bool operator>=(const rational &a, const rational &b) {\
    \ return !(a < b); }\n\n    friend auto abs(const rational &a) {\n      return\
    \ rational(std::abs(a.nume_), std::abs(a.deno_));\n    }\n  };\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <cmath>\n#include <iostream>\n#include <numeric>\n\
    \nnamespace haar_lib {\n  class rational {\n    int64_t nume_, deno_;\n\n  public:\n\
    \    rational() : nume_(0), deno_(1) {}\n    rational(int64_t nume) : nume_(nume),\
    \ deno_(1) {}\n    rational(int64_t nume, int64_t deno) {\n      const int64_t\
    \ g = std::gcd(nume, deno);\n      nume_           = nume / g;\n      deno_  \
    \         = deno / g;\n      if (deno_ < 0) {\n        nume_ = -nume_;\n     \
    \   deno_ = -deno_;\n      }\n    }\n\n    int64_t numerator() const { return\
    \ nume_; }\n    int64_t denominator() const { return deno_; }\n\n    auto operator+(const\
    \ rational &b) {\n      int64_t l = std::lcm((*this).deno_, b.deno_);\n      return\
    \ rational(l / (*this).deno_ * (*this).nume_ + l / b.deno_ * b.nume_, l);\n  \
    \  }\n\n    auto operator-(const rational &b) {\n      int64_t l = std::lcm((*this).deno_,\
    \ b.deno_);\n      return rational(l / (*this).deno_ * (*this).nume_ - l / b.deno_\
    \ * b.nume_, l);\n    }\n\n    auto operator*(const rational &b) {\n      return\
    \ rational((*this).nume_ * b.nume_, (*this).deno_ * b.deno_);\n    }\n\n    auto\
    \ operator/(const rational &b) {\n      return rational((*this).nume_ * b.deno_,\
    \ (*this).deno_ * b.nume_);\n    }\n\n    auto &operator+=(const rational &a)\
    \ {\n      *this = *this + a;\n      return *this;\n    }\n    auto &operator-=(const\
    \ rational &a) {\n      *this = *this - a;\n      return *this;\n    }\n    auto\
    \ &operator*=(const rational &a) {\n      *this = *this * a;\n      return *this;\n\
    \    }\n    auto &operator/=(const rational &a) {\n      *this = *this / a;\n\
    \      return *this;\n    }\n\n    explicit operator double() const { return (double)\
    \ nume_ / deno_; }\n    explicit operator long double() const { return (long double)\
    \ nume_ / deno_; }\n\n    auto operator-() { return rational(-nume_, deno_); }\n\
    \n    friend std::ostream &operator<<(std::ostream &os, const rational &r) {\n\
    \      if (r.deno_ == 1)\n        os << r.nume_;\n      else\n        os << r.nume_\
    \ << \"/\" << r.deno_;\n      return os;\n    }\n\n    friend bool operator==(const\
    \ rational &a, const rational &b) { return a.nume_ == b.nume_ and a.deno_ == b.deno_;\
    \ }\n    friend bool operator!=(const rational &a, const rational &b) { return\
    \ !(a == b); }\n    friend bool operator<(const rational &a, const rational &b)\
    \ { return a.nume_ * b.deno_ < b.nume_ * a.deno_; }\n    friend bool operator<=(const\
    \ rational &a, const rational &b) { return a.nume_ * b.deno_ <= b.nume_ * a.deno_;\
    \ }\n    friend bool operator>(const rational &a, const rational &b) { return\
    \ !(a <= b); }\n    friend bool operator>=(const rational &a, const rational &b)\
    \ { return !(a < b); }\n\n    friend auto abs(const rational &a) {\n      return\
    \ rational(std::abs(a.nume_), std::abs(a.deno_));\n    }\n  };\n}  // namespace\
    \ haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Rational/rational.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1300/main.test.cpp
documentation_of: Mylib/Number/Rational/rational.cpp
layout: document
title: Rational number
---

## Operations

## Requirements

## Notes

## Problems

## References
