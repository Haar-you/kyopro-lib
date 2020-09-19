---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1300/main.test.cpp
    title: test/aoj/1300/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Rational/rational.cpp\"\n#include <numeric>\n\
    #include <iostream>\n#include <cmath>\n\nnamespace haar_lib {\n  class rational\
    \ {\n  public:\n    int64_t nume, deno;\n    rational(): nume(0), deno(1){}\n\
    \    rational(int64_t num): nume(num), deno(1){}\n    rational(int64_t num, int64_t\
    \ den){\n      int64_t g = std::gcd(num, den);\n      nume = num / g;\n      deno\
    \ = den / g;\n      if(deno < 0){\n        nume = -nume;\n        deno = -deno;\n\
    \      }\n    }\n\n    auto operator+(const rational &b){\n      int64_t l = std::lcm((*this).deno,\
    \ b.deno);\n      return rational(l / (*this).deno * (*this).nume + l / b.deno\
    \ * b.nume, l);\n    }\n\n    auto operator-(const rational &b){\n      int64_t\
    \ l = std::lcm((*this).deno, b.deno);\n      return rational(l / (*this).deno\
    \ * (*this).nume - l / b.deno * b.nume, l);\n    }\n\n    auto operator*(const\
    \ rational &b){\n      return rational((*this).nume * b.nume, (*this).deno * b.deno);\n\
    \    }\n\n    auto operator/(const rational &b){\n      return rational((*this).nume\
    \ * b.deno, (*this).deno * b.nume);\n    }\n\n    auto& operator+=(const rational\
    \ &a){*this = *this + a; return *this;}\n    auto& operator-=(const rational &a){*this\
    \ = *this - a; return *this;}\n    auto& operator*=(const rational &a){*this =\
    \ *this * a; return *this;}\n    auto& operator/=(const rational &a){*this = *this\
    \ / a; return *this;}\n\n    explicit operator double() const {return (double)nume\
    \ / deno;}\n    explicit operator long double() const {return (long double)nume\
    \ / deno;}\n  };\n\n  std::ostream& operator<<(std::ostream &os, const rational\
    \ &r){\n    if(r.deno == 1) os << r.nume;\n    else os << r.nume << \"/\" << r.deno;\n\
    \    return os;\n  }\n\n  auto operator-(const rational &a){return rational(-a.nume,\
    \ a.deno);}\n\n  bool operator==(const rational &a, const rational &b){return\
    \ a.nume == b.nume && a.deno == b.deno;}\n  bool operator!=(const rational &a,\
    \ const rational &b){return !(a == b);}\n  bool operator<(const rational &a, const\
    \ rational &b){return a.nume * b.deno < b.nume * a.deno;}\n  bool operator<=(const\
    \ rational &a, const rational &b){return a.nume * b.deno <= b.nume * a.deno;}\n\
    \  bool operator>(const rational &a, const rational &b){return !(a <= b);}\n \
    \ bool operator>=(const rational &a, const rational &b){return !(a < b);}\n\n\
    \  auto abs(const rational &a){return rational(std::abs(a.nume), std::abs(a.deno));}\n\
    }\n"
  code: "#pragma once\n#include <numeric>\n#include <iostream>\n#include <cmath>\n\
    \nnamespace haar_lib {\n  class rational {\n  public:\n    int64_t nume, deno;\n\
    \    rational(): nume(0), deno(1){}\n    rational(int64_t num): nume(num), deno(1){}\n\
    \    rational(int64_t num, int64_t den){\n      int64_t g = std::gcd(num, den);\n\
    \      nume = num / g;\n      deno = den / g;\n      if(deno < 0){\n        nume\
    \ = -nume;\n        deno = -deno;\n      }\n    }\n\n    auto operator+(const\
    \ rational &b){\n      int64_t l = std::lcm((*this).deno, b.deno);\n      return\
    \ rational(l / (*this).deno * (*this).nume + l / b.deno * b.nume, l);\n    }\n\
    \n    auto operator-(const rational &b){\n      int64_t l = std::lcm((*this).deno,\
    \ b.deno);\n      return rational(l / (*this).deno * (*this).nume - l / b.deno\
    \ * b.nume, l);\n    }\n\n    auto operator*(const rational &b){\n      return\
    \ rational((*this).nume * b.nume, (*this).deno * b.deno);\n    }\n\n    auto operator/(const\
    \ rational &b){\n      return rational((*this).nume * b.deno, (*this).deno * b.nume);\n\
    \    }\n\n    auto& operator+=(const rational &a){*this = *this + a; return *this;}\n\
    \    auto& operator-=(const rational &a){*this = *this - a; return *this;}\n \
    \   auto& operator*=(const rational &a){*this = *this * a; return *this;}\n  \
    \  auto& operator/=(const rational &a){*this = *this / a; return *this;}\n\n \
    \   explicit operator double() const {return (double)nume / deno;}\n    explicit\
    \ operator long double() const {return (long double)nume / deno;}\n  };\n\n  std::ostream&\
    \ operator<<(std::ostream &os, const rational &r){\n    if(r.deno == 1) os <<\
    \ r.nume;\n    else os << r.nume << \"/\" << r.deno;\n    return os;\n  }\n\n\
    \  auto operator-(const rational &a){return rational(-a.nume, a.deno);}\n\n  bool\
    \ operator==(const rational &a, const rational &b){return a.nume == b.nume &&\
    \ a.deno == b.deno;}\n  bool operator!=(const rational &a, const rational &b){return\
    \ !(a == b);}\n  bool operator<(const rational &a, const rational &b){return a.nume\
    \ * b.deno < b.nume * a.deno;}\n  bool operator<=(const rational &a, const rational\
    \ &b){return a.nume * b.deno <= b.nume * a.deno;}\n  bool operator>(const rational\
    \ &a, const rational &b){return !(a <= b);}\n  bool operator>=(const rational\
    \ &a, const rational &b){return !(a < b);}\n\n  auto abs(const rational &a){return\
    \ rational(std::abs(a.nume), std::abs(a.deno));}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Rational/rational.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
