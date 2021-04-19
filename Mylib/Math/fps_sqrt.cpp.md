---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Math/formal_power_series.cpp
    title: Formal power series
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_sqrt.cpp
    title: Mod sqrt
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Math/formal_power_series.cpp\"\n#include <functional>\n\
    #include <vector>\n#include <initializer_list>\n#include <cassert>\n\nnamespace\
    \ haar_lib {\n  template <typename T, const auto &convolve>\n  class formal_power_series\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    std::vector<T> data_;\n\
    \n  public:\n    formal_power_series(){}\n    explicit formal_power_series(int\
    \ N): data_(N){}\n    formal_power_series(const std::vector<T> &data_): data_(data_){}\n\
    \    formal_power_series(std::initializer_list<T> init): data_(init.begin(), init.end()){}\n\
    \    formal_power_series(const formal_power_series &a): data_(a.data_){}\n   \
    \ formal_power_series(formal_power_series &&a) noexcept {*this = std::move(a);}\n\
    \n    size_t size() const {\n      return data_.size();\n    }\n\n    const T&\
    \ operator[](int i) const {\n      return data_[i];\n    }\n\n    T& operator[](int\
    \ i){\n      return data_[i];\n    }\n\n    auto begin() {return data_.begin();}\n\
    \    auto end() {return data_.end();}\n\n    const auto& data() const {return\
    \ data_;}\n\n    void resize(int n){\n      data_.resize(n);\n    }\n\n    auto&\
    \ operator=(formal_power_series &&rhs) noexcept {\n      if(this != &rhs){\n \
    \       data_ = std::move(rhs.data_);\n      }\n      return *this;\n    }\n\n\
    \    auto& operator+=(const formal_power_series &rhs){\n      if(data_.size()\
    \ < rhs.size()) data_.resize(rhs.size());\n      for(int i = 0; i < rhs.size();\
    \ ++i) data_[i] += rhs[i];\n      return *this;\n    }\n\n    auto& operator+=(T\
    \ rhs){\n      data_[0] += rhs;\n      return *this;\n    }\n\n    auto operator+(T\
    \ rhs) const {\n      auto ret = *this;\n      return ret += rhs;\n    }\n\n \
    \   auto operator+(const formal_power_series &rhs) const {\n      auto ret = *this;\n\
    \      return ret += rhs;\n    }\n\n    auto& operator-=(const formal_power_series\
    \ &rhs){\n      if(data_.size() < rhs.size()) data_.resize(rhs.size());\n    \
    \  for(int i = 0; i < rhs.size(); ++i) data_[i] -= rhs[i];\n      return *this;\n\
    \    }\n\n    auto& operator-=(T rhs){\n      data_[0] -= rhs;\n      return *this;\n\
    \    }\n\n    auto operator-(T rhs) const {\n      auto ret = *this;\n      return\
    \ ret -= rhs;\n    }\n\n    auto operator-(const formal_power_series &rhs) const\
    \ {\n      auto ret = *this;\n      return ret -= rhs;\n    }\n\n    auto operator-()\
    \ const {\n      auto ret = *this;\n      for(auto &x : ret) x = -x;\n      return\
    \ ret;\n    }\n\n    auto& operator*=(const formal_power_series &rhs){\n     \
    \ data_ = convolve(data_, rhs.data_);\n      return *this;\n    }\n\n    auto\
    \ operator*(const formal_power_series &rhs) const {\n      auto ret = convolve(data_,\
    \ rhs.data_);\n      return formal_power_series(ret);\n    }\n\n    auto& operator*=(T\
    \ rhs){\n      for(auto &x : data_) x *= rhs;\n      return *this;\n    }\n\n\
    \    auto operator*(T rhs) const {\n      auto ret = *this;\n      return ret\
    \ *= rhs;\n    }\n\n    auto differentiate() const {\n      const int n = data_.size();\n\
    \      std::vector<T> ret(n - 1);\n      for(int i = 0; i < n - 1; ++i){\n   \
    \     ret[i] = data_[i + 1] * (i + 1);\n      }\n\n      return formal_power_series(ret);\n\
    \    }\n\n    auto integrate() const {\n      const int n = data_.size();\n  \
    \    std::vector<T> ret(n + 1), invs(n + 1, 1);\n      const int p = T::mod();\n\
    \      for(int i = 2; i <= n; ++i) invs[i] = -invs[p % i] * (p / i);\n      for(int\
    \ i = 0; i < n; ++i){\n        ret[i + 1] = data_[i] * invs[i + 1];\n      }\n\
    \n      return formal_power_series(ret);\n    }\n\n    auto inv() const {\n  \
    \    assert(data_[0] != 0);\n      const int n = data_.size();\n\n      int t\
    \ = 1;\n      std::vector<T> ret = {data_[0].inv()};\n      ret.reserve(n * 2);\n\
    \n      while(t <= n * 2){\n        std::vector<T> c(data_.begin(), data_.begin()\
    \ + std::min(t, n));\n        auto a = convolve(ret, ret, true);\n        if((int)a.size()\
    \ > t) a.resize(t);\n\n        c = convolve(c, a);\n\n        if((int)c.size()\
    \ > t) c.resize(t);\n        if((int)ret.size() > t) ret.resize(t);\n\n      \
    \  for(int i = 0; i < (int)ret.size(); ++i) ret[i] = ret[i] * 2;\n\n        if(ret.size()\
    \ < c.size()) ret.resize(std::min<int>(c.size(), t));\n\n        for(int i = 0;\
    \ i < (int)c.size(); ++i){\n          ret[i] -= c[i];\n        }\n\n        t\
    \ <<= 1;\n      }\n\n      ret.resize(n);\n\n      return formal_power_series(ret);\n\
    \    }\n\n    auto log() const {\n      assert(data_[0] == 1);\n      const int\
    \ n = data_.size();\n      auto ret = (differentiate() * inv()).integrate();\n\
    \      ret.resize(n);\n      return ret;\n    }\n\n    auto exp() const {\n  \
    \    const int n = data_.size();\n\n      int t = 1;\n      formal_power_series\
    \ b({1});\n\n      while(t <= n * 2){\n        t <<= 1;\n        auto temp = b.log();\n\
    \        temp.resize(t);\n\n        for(int i = 0; i < t; ++i) temp[i] = -temp[i];\n\
    \        temp[0] += 1;\n        for(int i = 0; i < std::min(t, n); ++i) temp[i]\
    \ += data_[i];\n\n        b = b * temp;\n        b.resize(t);\n      }\n\n   \
    \   b.resize(n);\n\n      return b;\n    }\n\n    auto shift(int64_t k) const\
    \ {\n      const int64_t n = data_.size();\n      formal_power_series ret(n);\n\
    \n      if(k >= 0){\n        for(int64_t i = k; i < n; ++i){\n          ret[i]\
    \ = data_[i - k];\n        }\n      }else{\n        for(int64_t i = 0; i < n +\
    \ k; ++i){\n          ret[i] = data_[i - k];\n        }\n      }\n\n      return\
    \ ret;\n    }\n\n    auto pow(int64_t M) const {\n      assert(M >= 0);\n\n  \
    \    const int n = data_.size();\n      int k = 0;\n      for(; k < n; ++k){\n\
    \        if(data_[k] != 0){\n          break;\n        }\n      }\n\n      if(k\
    \ >= n) return *this;\n\n      T a = data_[k];\n\n      formal_power_series ret\
    \ = *this;\n      ret = (ret.shift(-k)) * a.inv();\n      ret = (ret.log() * (T)M).exp();\n\
    \      ret = (ret * a.pow(M)).shift(M * k);\n\n      return ret;\n    }\n\n  \
    \  std::optional<formal_power_series> sqrt() const;\n  };\n}\n#line 2 \"Mylib/Number/Mod/mod_sqrt.cpp\"\
    \n#include <random>\n#include <optional>\n#line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  constexpr int64_t mod_pow(int64_t\
    \ n, int64_t p, int64_t m){\n    int64_t ret = 1;\n    while(p > 0){\n      if(p\
    \ & 1) (ret *= n) %= m;\n      (n *= n) %= m;\n      p >>= 1;\n    }\n    return\
    \ ret;\n  }\n}\n#line 5 \"Mylib/Number/Mod/mod_sqrt.cpp\"\n\nnamespace haar_lib\
    \ {\n  std::optional<int64_t> mod_sqrt(int64_t a, int64_t p){\n    if(p == 2)\
    \ return a % 2;\n    if(a == 0) return 0;\n\n    int64_t b = mod_pow(a, (p - 1)\
    \ / 2, p);\n\n    if(b == p - 1) return {};\n    if(p % 4 == 3) return mod_pow(a,\
    \ (p + 1) / 4, p);\n\n    int64_t q = p - 1, s = 0;\n    while(q % 2 == 0){\n\
    \      q /= 2;\n      s += 1;\n    }\n\n    static std::mt19937_64 rand(time(0));\n\
    \    std::uniform_int_distribution<> dist(0, p - 1);\n\n    int64_t z;\n    while(1){\n\
    \      z = dist(rand);\n      if(mod_pow(z, (p - 1) / 2, p) == p - 1) break;\n\
    \    }\n\n    int64_t m = s;\n    int64_t c = mod_pow(z, q, p);\n    int64_t t\
    \ = mod_pow(a, q, p);\n    int64_t r = mod_pow(a, (q + 1) / 2, p);\n\n    while(1){\n\
    \      if(t == 0) return 0;\n      if(t == 1) return r;\n\n      int i = 1;\n\
    \      for(int64_t T = t; i < m; ++i){\n        (T *= T) %= p;\n        if(T ==\
    \ 1) break;\n      }\n\n      int64_t b = mod_pow(c, 1LL << (m - i - 1), p);\n\
    \n      m = i;\n      c = b * b % p;\n      (t *= b * b % p) %= p;\n      (r *=\
    \ b) %= p;\n    }\n  }\n}\n#line 4 \"Mylib/Math/fps_sqrt.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, const auto &convolve>\n  auto formal_power_series<T,\
    \ convolve>::sqrt() const ->\n    std::optional<formal_power_series<T, convolve>>\
    \ {\n    constexpr int mod = value_type::mod();\n\n    const int n = data_.size();\n\
    \    int k = 0;\n    for(; k < n; ++k) if(data_[k] != 0) break;\n\n    if(k >=\
    \ n) return *this;\n    if(k % 2 != 0) return {};\n\n    auto x = mod_sqrt((int64_t)data_[k],\
    \ mod);\n\n    if(not x) return {};\n\n    const int m = n - k;\n\n    auto it\
    \ = data_.begin() + k;\n    formal_power_series ret({*x});\n\n    int t = 1;\n\
    \    while(t <= m * 2){\n      formal_power_series f(std::vector<T>(it, it + std::min(t,\
    \ m)));\n      ret.resize(t);\n      f.resize(t);\n      ret = (ret + f * ret.inv())\
    \ * T(2).inv();\n      t <<= 1;\n    }\n\n    ret.resize(n);\n    ret = ret.shift(k\
    \ / 2);\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include \"Mylib/Math/formal_power_series.cpp\"\n#include \"\
    Mylib/Number/Mod/mod_sqrt.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, const auto &convolve>\n  auto formal_power_series<T, convolve>::sqrt() const\
    \ ->\n    std::optional<formal_power_series<T, convolve>> {\n    constexpr int\
    \ mod = value_type::mod();\n\n    const int n = data_.size();\n    int k = 0;\n\
    \    for(; k < n; ++k) if(data_[k] != 0) break;\n\n    if(k >= n) return *this;\n\
    \    if(k % 2 != 0) return {};\n\n    auto x = mod_sqrt((int64_t)data_[k], mod);\n\
    \n    if(not x) return {};\n\n    const int m = n - k;\n\n    auto it = data_.begin()\
    \ + k;\n    formal_power_series ret({*x});\n\n    int t = 1;\n    while(t <= m\
    \ * 2){\n      formal_power_series f(std::vector<T>(it, it + std::min(t, m)));\n\
    \      ret.resize(t);\n      f.resize(t);\n      ret = (ret + f * ret.inv()) *\
    \ T(2).inv();\n      t <<= 1;\n    }\n\n    ret.resize(n);\n    ret = ret.shift(k\
    \ / 2);\n\n    return ret;\n  }\n}\n"
  dependsOn:
  - Mylib/Math/formal_power_series.cpp
  - Mylib/Number/Mod/mod_sqrt.cpp
  - Mylib/Number/Mod/mod_pow.cpp
  isVerificationFile: false
  path: Mylib/Math/fps_sqrt.cpp
  requiredBy: []
  timestamp: '2021-02-23 11:22:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
documentation_of: Mylib/Math/fps_sqrt.cpp
layout: document
title: Formal power series (Sqrt)
---

## Operations

## Requirements

## Notes

## Problems

## References
