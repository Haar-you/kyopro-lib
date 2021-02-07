---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/exp_of_formal_power_series/main.montgomery.test.cpp
    title: test/yosupo-judge/exp_of_formal_power_series/main.montgomery.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mint/montgomery.cpp\"\n#include <iostream>\n\
    \nnamespace haar_lib {\n  template <int64_t M>\n  class montgomery {\n    constexpr\
    \ static int64_t MOD = M;\n    constexpr static int b = 64 - __builtin_clzll(MOD);\n\
    \    constexpr static int64_t R = 1LL << b;\n    constexpr static int64_t R2 =\
    \ (R % MOD) * (R % MOD) % MOD;\n\n    constexpr static int64_t mask = R - 1;\n\
    \n    constexpr static int64_t init(){\n      int64_t ret = 0, r = R, i = 1, t\
    \ = 0;\n      while(r > 1){\n        if(t % 2 == 0) t += MOD, ret += i;\n    \
    \    t >>= 1, r >>= 1, i <<= 1;\n      }\n      return ret;\n    }\n\n    constexpr\
    \ static int64_t m = init();\n\n    static_assert(R > MOD, \"R > MOD\");\n   \
    \ static_assert((R & (R - 1)) == 0, \"R must be power of 2\");\n\n    static int64_t\
    \ reduce(int64_t T){\n      int64_t ret = ((((T & mask) * m) & mask) * MOD + T)\
    \ >> b;\n      if(ret >= MOD) ret -= MOD;\n      return ret;\n    }\n\n    int64_t\
    \ val_;\n\n  public:\n    montgomery(): val_(0){}\n    montgomery(int64_t a){\n\
    \      if(a < 0){\n        if(a < -MOD) a = a % MOD + MOD;\n        else a +=\
    \ MOD;\n      }else if(a >= MOD){\n        if(a < 2 * MOD) a -= MOD;\n       \
    \ else a %= MOD;\n      }\n\n      val_ = reduce(a * R2);\n    }\n    montgomery(const\
    \ montgomery &that): val_(that.val_){}\n\n    constexpr static auto mod(){return\
    \ MOD;}\n\n    auto& operator+=(const montgomery &that){\n      val_ += that.val_;\n\
    \      if(val_ >= MOD) val_ -= MOD;\n      return *this;\n    }\n\n    auto& operator-=(const\
    \ montgomery &that){\n      val_ -= that.val_;\n      if(val_ < 0) val_ += MOD;\n\
    \      return *this;\n    }\n\n    auto& operator*=(const montgomery &that){\n\
    \      val_ = reduce(val_ * that.val_);\n      return *this;\n    }\n\n    auto&\
    \ operator/=(const montgomery &that){\n      *this *= that.inv();\n      return\
    \ *this;\n    }\n\n    auto operator-() const {\n      montgomery ret(0);\n  \
    \    ret -= *this;\n      return ret;\n    }\n\n    auto operator+(const montgomery\
    \ &that) const {auto ret = *this; return ret += that;}\n    auto operator-(const\
    \ montgomery &that) const {auto ret = *this; return ret -= that;}\n    auto operator*(const\
    \ montgomery &that) const {auto ret = *this; return ret *= that;}\n    auto operator/(const\
    \ montgomery &that) const {auto ret = *this; return ret /= that;}\n\n    auto\
    \ pow(int64_t p) const {\n      montgomery ret = 1, e = *this;\n\n      while(p\
    \ > 0){\n        if(p & 1) ret *= e;\n        e *= e;\n        p >>= 1;\n    \
    \  }\n\n      return ret;\n    }\n\n    static auto pow(int64_t n, int64_t p){return\
    \ montgomery(n).pow(p);}\n\n    auto inv() const {return pow(MOD - 2);}\n    static\
    \ auto inv(int64_t n){return montgomery(n).inv();}\n\n    friend auto operator+(int64_t\
    \ a, const montgomery &b) {return montgomery(a) + b;}\n    friend auto operator-(int64_t\
    \ a, const montgomery &b) {return montgomery(a) - b;}\n    friend auto operator*(int64_t\
    \ a, const montgomery &b) {return montgomery(a) * b;}\n    friend auto operator/(int64_t\
    \ a, const montgomery &b) {return montgomery(a) / b;}\n\n    bool operator==(const\
    \ montgomery &that) const {\n      return (val_ >= MOD ? val_ - MOD : val_) ==\
    \ (that.val_ >= MOD ? that.val_ - MOD : that.val_);\n    }\n\n    bool operator!=(const\
    \ montgomery &that) const {return !(*this == that);}\n\n    friend std::ostream&\
    \ operator<<(std::ostream& s, const montgomery &a){\n      return s << reduce(a.val_);\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& s, montgomery &a){\n\
    \      int64_t t; s >> t;\n      a = montgomery(t);\n      return s;\n    }\n\n\
    \    explicit operator int32_t() const {return reduce(val_);}\n    explicit operator\
    \ int64_t() const {return reduce(val_);}\n  };\n}\n"
  code: "#pragma once\n#include <iostream>\n\nnamespace haar_lib {\n  template <int64_t\
    \ M>\n  class montgomery {\n    constexpr static int64_t MOD = M;\n    constexpr\
    \ static int b = 64 - __builtin_clzll(MOD);\n    constexpr static int64_t R =\
    \ 1LL << b;\n    constexpr static int64_t R2 = (R % MOD) * (R % MOD) % MOD;\n\n\
    \    constexpr static int64_t mask = R - 1;\n\n    constexpr static int64_t init(){\n\
    \      int64_t ret = 0, r = R, i = 1, t = 0;\n      while(r > 1){\n        if(t\
    \ % 2 == 0) t += MOD, ret += i;\n        t >>= 1, r >>= 1, i <<= 1;\n      }\n\
    \      return ret;\n    }\n\n    constexpr static int64_t m = init();\n\n    static_assert(R\
    \ > MOD, \"R > MOD\");\n    static_assert((R & (R - 1)) == 0, \"R must be power\
    \ of 2\");\n\n    static int64_t reduce(int64_t T){\n      int64_t ret = ((((T\
    \ & mask) * m) & mask) * MOD + T) >> b;\n      if(ret >= MOD) ret -= MOD;\n  \
    \    return ret;\n    }\n\n    int64_t val_;\n\n  public:\n    montgomery(): val_(0){}\n\
    \    montgomery(int64_t a){\n      if(a < 0){\n        if(a < -MOD) a = a % MOD\
    \ + MOD;\n        else a += MOD;\n      }else if(a >= MOD){\n        if(a < 2\
    \ * MOD) a -= MOD;\n        else a %= MOD;\n      }\n\n      val_ = reduce(a *\
    \ R2);\n    }\n    montgomery(const montgomery &that): val_(that.val_){}\n\n \
    \   constexpr static auto mod(){return MOD;}\n\n    auto& operator+=(const montgomery\
    \ &that){\n      val_ += that.val_;\n      if(val_ >= MOD) val_ -= MOD;\n    \
    \  return *this;\n    }\n\n    auto& operator-=(const montgomery &that){\n   \
    \   val_ -= that.val_;\n      if(val_ < 0) val_ += MOD;\n      return *this;\n\
    \    }\n\n    auto& operator*=(const montgomery &that){\n      val_ = reduce(val_\
    \ * that.val_);\n      return *this;\n    }\n\n    auto& operator/=(const montgomery\
    \ &that){\n      *this *= that.inv();\n      return *this;\n    }\n\n    auto\
    \ operator-() const {\n      montgomery ret(0);\n      ret -= *this;\n      return\
    \ ret;\n    }\n\n    auto operator+(const montgomery &that) const {auto ret =\
    \ *this; return ret += that;}\n    auto operator-(const montgomery &that) const\
    \ {auto ret = *this; return ret -= that;}\n    auto operator*(const montgomery\
    \ &that) const {auto ret = *this; return ret *= that;}\n    auto operator/(const\
    \ montgomery &that) const {auto ret = *this; return ret /= that;}\n\n    auto\
    \ pow(int64_t p) const {\n      montgomery ret = 1, e = *this;\n\n      while(p\
    \ > 0){\n        if(p & 1) ret *= e;\n        e *= e;\n        p >>= 1;\n    \
    \  }\n\n      return ret;\n    }\n\n    static auto pow(int64_t n, int64_t p){return\
    \ montgomery(n).pow(p);}\n\n    auto inv() const {return pow(MOD - 2);}\n    static\
    \ auto inv(int64_t n){return montgomery(n).inv();}\n\n    friend auto operator+(int64_t\
    \ a, const montgomery &b) {return montgomery(a) + b;}\n    friend auto operator-(int64_t\
    \ a, const montgomery &b) {return montgomery(a) - b;}\n    friend auto operator*(int64_t\
    \ a, const montgomery &b) {return montgomery(a) * b;}\n    friend auto operator/(int64_t\
    \ a, const montgomery &b) {return montgomery(a) / b;}\n\n    bool operator==(const\
    \ montgomery &that) const {\n      return (val_ >= MOD ? val_ - MOD : val_) ==\
    \ (that.val_ >= MOD ? that.val_ - MOD : that.val_);\n    }\n\n    bool operator!=(const\
    \ montgomery &that) const {return !(*this == that);}\n\n    friend std::ostream&\
    \ operator<<(std::ostream& s, const montgomery &a){\n      return s << reduce(a.val_);\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& s, montgomery &a){\n\
    \      int64_t t; s >> t;\n      a = montgomery(t);\n      return s;\n    }\n\n\
    \    explicit operator int32_t() const {return reduce(val_);}\n    explicit operator\
    \ int64_t() const {return reduce(val_);}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Mint/montgomery.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/exp_of_formal_power_series/main.montgomery.test.cpp
documentation_of: Mylib/Number/Mint/montgomery.cpp
layout: document
title: Montgomery multiplication
---

## Operations

## Requirements

## Notes

## Problems

## References
