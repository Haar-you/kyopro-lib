---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1327/main.test.cpp
    title: test/aoj/1327/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/montmort_number_mod/main.test.cpp
    title: test/yosupo-judge/montmort_number_mod/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mint/runtime_mint.cpp\"\n#include <iostream>\n\
    #include <utility>\n\nnamespace haar_lib {\n  template <const int &M>\n  class\
    \ runtime_modint {\n    int64_t val_;\n\n  public:\n    runtime_modint() : val_(0)\
    \ {}\n    runtime_modint(int64_t n) {\n      if (n >= M)\n        val_ = n % M;\n\
    \      else if (n < 0)\n        val_ = n % M + M;\n      else\n        val_ =\
    \ n;\n    }\n\n    static auto mod() { return M; }\n\n    auto operator+(const\
    \ runtime_modint &a) const { return runtime_modint(val_ + a.val_); }\n    auto\
    \ operator-(const runtime_modint &a) const { return runtime_modint(val_ - a.val_);\
    \ }\n    auto operator*(const runtime_modint &a) const { return runtime_modint(val_\
    \ * a.val_); }\n    auto operator/(const runtime_modint &a) const { return runtime_modint(val_\
    \ * a.inv().val_); }\n\n    const auto &operator=(const runtime_modint &a) {\n\
    \      val_ = a.val_;\n      return *this;\n    }\n    const auto &operator+=(const\
    \ runtime_modint &a) {\n      if ((val_ += a.val_) >= M) val_ -= M;\n      return\
    \ *this;\n    }\n    const auto &operator-=(const runtime_modint &a) {\n     \
    \ if (val_ < a.val_) val_ += M;\n      val_ -= a.val_;\n      return *this;\n\
    \    }\n    const auto &operator*=(const runtime_modint &a) {\n      (val_ *=\
    \ a.val_) %= M;\n      return *this;\n    }\n    const auto &operator/=(const\
    \ runtime_modint &a) {\n      (val_ *= a.inv().val_) %= M;\n      return *this;\n\
    \    }\n\n    bool operator==(const runtime_modint &a) const { return val_ ==\
    \ a.val_; }\n    bool operator!=(const runtime_modint &a) const { return val_\
    \ != a.val_; }\n\n    static auto pow(int64_t n, int64_t p) {\n      runtime_modint\
    \ ret = 1, e = n;\n      for (; p; e *= e, p >>= 1)\n        if (p & 1) ret *=\
    \ e;\n      return ret;\n    }\n\n    auto pow(int64_t p) const {\n      runtime_modint\
    \ ret = 1, e = val_;\n      for (; p; e *= e, p >>= 1)\n        if (p & 1) ret\
    \ *= e;\n      return ret;\n    }\n\n    runtime_modint inv() const {\n      int64_t\
    \ a = val_, b = M, u = 1, v = 0;\n\n      while (b) {\n        int64_t t = a /\
    \ b;\n        a -= t * b;\n        std::swap(a, b);\n        u -= t * v;\n   \
    \     std::swap(u, v);\n      }\n      u %= M;\n      if (u < 0) u += M;\n\n \
    \     return u;\n    }\n\n    explicit operator int32_t() const noexcept { return\
    \ val_; }\n    explicit operator int64_t() const noexcept { return val_; }\n\n\
    \    friend auto operator-(const runtime_modint &a) { return runtime_modint(-a.val_);\
    \ }\n\n    friend auto operator+(int64_t a, const runtime_modint &b) { return\
    \ runtime_modint(a) + b; }\n    friend auto operator-(int64_t a, const runtime_modint\
    \ &b) { return runtime_modint(a) - b; }\n    friend auto operator*(int64_t a,\
    \ const runtime_modint &b) { return runtime_modint(a) * b; }\n    friend auto\
    \ operator/(int64_t a, const runtime_modint &b) { return runtime_modint(a) / b;\
    \ }\n\n    friend std::istream &operator>>(std::istream &is, runtime_modint &a)\
    \ {\n      is >> a.val_;\n      return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const runtime_modint &a) {\n      os << a.val_;\n      return os;\n   \
    \ }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <iostream>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <const int &M>\n  class runtime_modint {\n    int64_t val_;\n\n\
    \  public:\n    runtime_modint() : val_(0) {}\n    runtime_modint(int64_t n) {\n\
    \      if (n >= M)\n        val_ = n % M;\n      else if (n < 0)\n        val_\
    \ = n % M + M;\n      else\n        val_ = n;\n    }\n\n    static auto mod()\
    \ { return M; }\n\n    auto operator+(const runtime_modint &a) const { return\
    \ runtime_modint(val_ + a.val_); }\n    auto operator-(const runtime_modint &a)\
    \ const { return runtime_modint(val_ - a.val_); }\n    auto operator*(const runtime_modint\
    \ &a) const { return runtime_modint(val_ * a.val_); }\n    auto operator/(const\
    \ runtime_modint &a) const { return runtime_modint(val_ * a.inv().val_); }\n\n\
    \    const auto &operator=(const runtime_modint &a) {\n      val_ = a.val_;\n\
    \      return *this;\n    }\n    const auto &operator+=(const runtime_modint &a)\
    \ {\n      if ((val_ += a.val_) >= M) val_ -= M;\n      return *this;\n    }\n\
    \    const auto &operator-=(const runtime_modint &a) {\n      if (val_ < a.val_)\
    \ val_ += M;\n      val_ -= a.val_;\n      return *this;\n    }\n    const auto\
    \ &operator*=(const runtime_modint &a) {\n      (val_ *= a.val_) %= M;\n     \
    \ return *this;\n    }\n    const auto &operator/=(const runtime_modint &a) {\n\
    \      (val_ *= a.inv().val_) %= M;\n      return *this;\n    }\n\n    bool operator==(const\
    \ runtime_modint &a) const { return val_ == a.val_; }\n    bool operator!=(const\
    \ runtime_modint &a) const { return val_ != a.val_; }\n\n    static auto pow(int64_t\
    \ n, int64_t p) {\n      runtime_modint ret = 1, e = n;\n      for (; p; e *=\
    \ e, p >>= 1)\n        if (p & 1) ret *= e;\n      return ret;\n    }\n\n    auto\
    \ pow(int64_t p) const {\n      runtime_modint ret = 1, e = val_;\n      for (;\
    \ p; e *= e, p >>= 1)\n        if (p & 1) ret *= e;\n      return ret;\n    }\n\
    \n    runtime_modint inv() const {\n      int64_t a = val_, b = M, u = 1, v =\
    \ 0;\n\n      while (b) {\n        int64_t t = a / b;\n        a -= t * b;\n \
    \       std::swap(a, b);\n        u -= t * v;\n        std::swap(u, v);\n    \
    \  }\n      u %= M;\n      if (u < 0) u += M;\n\n      return u;\n    }\n\n  \
    \  explicit operator int32_t() const noexcept { return val_; }\n    explicit operator\
    \ int64_t() const noexcept { return val_; }\n\n    friend auto operator-(const\
    \ runtime_modint &a) { return runtime_modint(-a.val_); }\n\n    friend auto operator+(int64_t\
    \ a, const runtime_modint &b) { return runtime_modint(a) + b; }\n    friend auto\
    \ operator-(int64_t a, const runtime_modint &b) { return runtime_modint(a) - b;\
    \ }\n    friend auto operator*(int64_t a, const runtime_modint &b) { return runtime_modint(a)\
    \ * b; }\n    friend auto operator/(int64_t a, const runtime_modint &b) { return\
    \ runtime_modint(a) / b; }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, runtime_modint &a) {\n      is >> a.val_;\n      return is;\n    }\n  \
    \  friend std::ostream &operator<<(std::ostream &os, const runtime_modint &a)\
    \ {\n      os << a.val_;\n      return os;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Mint/runtime_mint.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/montmort_number_mod/main.test.cpp
  - test/aoj/1327/main.test.cpp
documentation_of: Mylib/Number/Mint/runtime_mint.cpp
layout: document
title: Modint (Runtime mod)
---

## Operations

## Requirements

## Notes

## Problems

## References