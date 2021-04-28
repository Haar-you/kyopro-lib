---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mint/mint_2.cpp\"\n#include <iostream>\n\n\
    class modint2 {\n  uint32_t val_;\n\npublic:\n  constexpr static int mod() { return\
    \ 2; }\n\n  constexpr modint2() : val_(0) {}\n  constexpr modint2(int64_t n) :\
    \ val_(n & 1) {}\n\n  constexpr auto &operator=(const modint2 &a) {\n    val_\
    \ = a.val_;\n    return *this;\n  }\n  constexpr auto &operator+=(const modint2\
    \ &a) {\n    val_ ^= a.val_;\n    return *this;\n  }\n  constexpr auto &operator-=(const\
    \ modint2 &a) {\n    val_ ^= a.val_;\n    return *this;\n  }\n  constexpr auto\
    \ &operator*=(const modint2 &a) {\n    val_ &= a.val_;\n    return *this;\n  }\n\
    \  constexpr auto &operator/=(const modint2 &a) {\n    val_ &= a.val_;\n    return\
    \ *this;\n  }\n\n  constexpr auto operator+(const modint2 &a) const { return modint2(*this)\
    \ += a; }\n  constexpr auto operator-(const modint2 &a) const { return modint2(*this)\
    \ -= a; }\n  constexpr auto operator*(const modint2 &a) const { return modint2(*this)\
    \ *= a; }\n  constexpr auto operator/(const modint2 &a) const { return modint2(*this)\
    \ /= a; }\n\n  constexpr bool operator==(const modint2 &a) const { return val_\
    \ == a.val_; }\n  constexpr bool operator!=(const modint2 &a) const { return val_\
    \ != a.val_; }\n\n  constexpr auto &operator++() {\n    *this += 1;\n    return\
    \ *this;\n  }\n  constexpr auto &operator--() {\n    *this -= 1;\n    return *this;\n\
    \  }\n\n  constexpr auto operator++(int) {\n    auto t = *this;\n    *this +=\
    \ 1;\n    return t;\n  }\n  constexpr auto operator--(int) {\n    auto t = *this;\n\
    \    *this -= 1;\n    return t;\n  }\n\n  constexpr static modint2 pow(int64_t\
    \ n, int64_t) { return n; }\n  constexpr static modint2 inv(int64_t a) { return\
    \ a; }\n\n  constexpr static auto frac(int64_t a, int64_t b) { return modint2(a)\
    \ / modint2(b); }\n\n  constexpr auto pow(int64_t) const { return *this; }\n \
    \ constexpr auto inv() const { return *this; }\n\n  friend constexpr auto operator-(const\
    \ modint2 &a) { return a; }\n\n  friend constexpr auto operator+(int64_t a, const\
    \ modint2 &b) { return modint2(a) + b; }\n  friend constexpr auto operator-(int64_t\
    \ a, const modint2 &b) { return modint2(a) - b; }\n  friend constexpr auto operator*(int64_t\
    \ a, const modint2 &b) { return modint2(a) * b; }\n  friend constexpr auto operator/(int64_t\
    \ a, const modint2 &b) { return modint2(a) / b; }\n\n  friend std::istream &operator>>(std::istream\
    \ &s, modint2 &a) {\n    s >> a.val_;\n    return s;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &s, const modint2 &a) {\n    s << a.val_;\n    return\
    \ s;\n  }\n\n  explicit operator int32_t() const noexcept { return val_; }\n \
    \ explicit operator int64_t() const noexcept { return val_; }\n};\n"
  code: "#pragma once\n#include <iostream>\n\nclass modint2 {\n  uint32_t val_;\n\n\
    public:\n  constexpr static int mod() { return 2; }\n\n  constexpr modint2() :\
    \ val_(0) {}\n  constexpr modint2(int64_t n) : val_(n & 1) {}\n\n  constexpr auto\
    \ &operator=(const modint2 &a) {\n    val_ = a.val_;\n    return *this;\n  }\n\
    \  constexpr auto &operator+=(const modint2 &a) {\n    val_ ^= a.val_;\n    return\
    \ *this;\n  }\n  constexpr auto &operator-=(const modint2 &a) {\n    val_ ^= a.val_;\n\
    \    return *this;\n  }\n  constexpr auto &operator*=(const modint2 &a) {\n  \
    \  val_ &= a.val_;\n    return *this;\n  }\n  constexpr auto &operator/=(const\
    \ modint2 &a) {\n    val_ &= a.val_;\n    return *this;\n  }\n\n  constexpr auto\
    \ operator+(const modint2 &a) const { return modint2(*this) += a; }\n  constexpr\
    \ auto operator-(const modint2 &a) const { return modint2(*this) -= a; }\n  constexpr\
    \ auto operator*(const modint2 &a) const { return modint2(*this) *= a; }\n  constexpr\
    \ auto operator/(const modint2 &a) const { return modint2(*this) /= a; }\n\n \
    \ constexpr bool operator==(const modint2 &a) const { return val_ == a.val_; }\n\
    \  constexpr bool operator!=(const modint2 &a) const { return val_ != a.val_;\
    \ }\n\n  constexpr auto &operator++() {\n    *this += 1;\n    return *this;\n\
    \  }\n  constexpr auto &operator--() {\n    *this -= 1;\n    return *this;\n \
    \ }\n\n  constexpr auto operator++(int) {\n    auto t = *this;\n    *this += 1;\n\
    \    return t;\n  }\n  constexpr auto operator--(int) {\n    auto t = *this;\n\
    \    *this -= 1;\n    return t;\n  }\n\n  constexpr static modint2 pow(int64_t\
    \ n, int64_t) { return n; }\n  constexpr static modint2 inv(int64_t a) { return\
    \ a; }\n\n  constexpr static auto frac(int64_t a, int64_t b) { return modint2(a)\
    \ / modint2(b); }\n\n  constexpr auto pow(int64_t) const { return *this; }\n \
    \ constexpr auto inv() const { return *this; }\n\n  friend constexpr auto operator-(const\
    \ modint2 &a) { return a; }\n\n  friend constexpr auto operator+(int64_t a, const\
    \ modint2 &b) { return modint2(a) + b; }\n  friend constexpr auto operator-(int64_t\
    \ a, const modint2 &b) { return modint2(a) - b; }\n  friend constexpr auto operator*(int64_t\
    \ a, const modint2 &b) { return modint2(a) * b; }\n  friend constexpr auto operator/(int64_t\
    \ a, const modint2 &b) { return modint2(a) / b; }\n\n  friend std::istream &operator>>(std::istream\
    \ &s, modint2 &a) {\n    s >> a.val_;\n    return s;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &s, const modint2 &a) {\n    s << a.val_;\n    return\
    \ s;\n  }\n\n  explicit operator int32_t() const noexcept { return val_; }\n \
    \ explicit operator int64_t() const noexcept { return val_; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Mint/mint_2.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Number/Mint/mint_2.cpp
layout: document
title: Modint (mod 2)
---

## Operations

## Requirements

## Notes

## Problems

## References
