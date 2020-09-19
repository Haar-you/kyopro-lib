---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"old/runtime_mint.cpp\"\n#include <iostream>\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <typename Tag>\n  class runtime_modint {\n\
    \    static uint32_t M;\n    uint64_t val;\n\n  public:\n    runtime_modint():\
    \ val(0){}\n    runtime_modint(int64_t n){\n      if(n >= M) val = n % M;\n  \
    \    else if(n < 0) val = n % M + M;\n      else val = n;\n    }\n\n    static\
    \ auto mod(){return M;}\n\n    auto operator+(const runtime_modint &a) const {return\
    \ runtime_modint(val + a.val);}\n    auto operator-(const runtime_modint &a) const\
    \ {return runtime_modint(val - a.val);}\n    auto operator*(const runtime_modint\
    \ &a) const {return runtime_modint(val * a.val);}\n    auto operator/(const runtime_modint\
    \ &a) const {return runtime_modint(val * a.inv().val);}\n\n    const auto& operator=(const\
    \ runtime_modint &a){val = a.val; return *this;}\n    const auto& operator+=(const\
    \ runtime_modint &a){if((val += a.val) >= M) val -= M; return *this;}\n    const\
    \ auto& operator-=(const runtime_modint &a){if(val < a.val) val += M; val -= a.val;\
    \ return *this;}\n    const auto& operator*=(const runtime_modint &a){(val *=\
    \ a.val) %= M; return *this;}\n    const auto& operator/=(const runtime_modint\
    \ &a){(val *= a.inv().val) %= M; return *this;}\n\n    bool operator==(const runtime_modint\
    \ &a) const {return val == a.val;}\n    bool operator!=(const runtime_modint &a)\
    \ const {return val != a.val;}\n\n    static auto pow(int64_t n, int64_t p){\n\
    \      runtime_modint ret = 1, e = n;\n      for(; p; e *= e, p >>= 1) if(p &\
    \ 1) ret *= e;\n      return ret;\n    }\n\n    auto pow(int64_t p) const {\n\
    \      runtime_modint ret = 1, e = val;\n      for(; p; e *= e, p >>= 1) if(p\
    \ & 1) ret *= e;\n      return ret;\n    }\n\n    runtime_modint inv() const {\n\
    \      int64_t a = val, b = M, u = 1, v = 0;\n\n      while(b){\n        int64_t\
    \ t = a / b;\n        a -= t * b; std::swap(a, b);\n        u -= t * v; std::swap(u,\
    \ v);\n      }\n      u %= M;\n      if(u < 0) u += M;\n\n      return u;\n  \
    \  }\n\n    explicit operator int32_t() const noexcept {return val;}\n    explicit\
    \ operator int64_t() const noexcept {return val;}\n\n    static void init(uint32_t\
    \ m){M = m;}\n\n    friend auto operator-(const runtime_modint &a){return runtime_modint(-a.val);}\n\
    \n    friend auto operator+(int64_t a, const runtime_modint &b){return runtime_modint(a)\
    \ + b;}\n    friend auto operator-(int64_t a, const runtime_modint &b){return\
    \ runtime_modint(a) - b;}\n    friend auto operator*(int64_t a, const runtime_modint\
    \ &b){return runtime_modint(a) * b;}\n    friend auto operator/(int64_t a, const\
    \ runtime_modint &b){return runtime_modint(a) / b;}\n\n    friend std::istream&\
    \ operator>>(std::istream &is, runtime_modint &a){is >> a.val; return is;}\n \
    \   friend std::ostream& operator<<(std::ostream &os, const runtime_modint &a){os\
    \ << a.val; return os;}\n  };\n\n  template <typename Tag> uint32_t runtime_modint<Tag>::M;\n\
    }\n"
  code: "#pragma once\n#include <iostream>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <typename Tag>\n  class runtime_modint {\n    static uint32_t\
    \ M;\n    uint64_t val;\n\n  public:\n    runtime_modint(): val(0){}\n    runtime_modint(int64_t\
    \ n){\n      if(n >= M) val = n % M;\n      else if(n < 0) val = n % M + M;\n\
    \      else val = n;\n    }\n\n    static auto mod(){return M;}\n\n    auto operator+(const\
    \ runtime_modint &a) const {return runtime_modint(val + a.val);}\n    auto operator-(const\
    \ runtime_modint &a) const {return runtime_modint(val - a.val);}\n    auto operator*(const\
    \ runtime_modint &a) const {return runtime_modint(val * a.val);}\n    auto operator/(const\
    \ runtime_modint &a) const {return runtime_modint(val * a.inv().val);}\n\n   \
    \ const auto& operator=(const runtime_modint &a){val = a.val; return *this;}\n\
    \    const auto& operator+=(const runtime_modint &a){if((val += a.val) >= M) val\
    \ -= M; return *this;}\n    const auto& operator-=(const runtime_modint &a){if(val\
    \ < a.val) val += M; val -= a.val; return *this;}\n    const auto& operator*=(const\
    \ runtime_modint &a){(val *= a.val) %= M; return *this;}\n    const auto& operator/=(const\
    \ runtime_modint &a){(val *= a.inv().val) %= M; return *this;}\n\n    bool operator==(const\
    \ runtime_modint &a) const {return val == a.val;}\n    bool operator!=(const runtime_modint\
    \ &a) const {return val != a.val;}\n\n    static auto pow(int64_t n, int64_t p){\n\
    \      runtime_modint ret = 1, e = n;\n      for(; p; e *= e, p >>= 1) if(p &\
    \ 1) ret *= e;\n      return ret;\n    }\n\n    auto pow(int64_t p) const {\n\
    \      runtime_modint ret = 1, e = val;\n      for(; p; e *= e, p >>= 1) if(p\
    \ & 1) ret *= e;\n      return ret;\n    }\n\n    runtime_modint inv() const {\n\
    \      int64_t a = val, b = M, u = 1, v = 0;\n\n      while(b){\n        int64_t\
    \ t = a / b;\n        a -= t * b; std::swap(a, b);\n        u -= t * v; std::swap(u,\
    \ v);\n      }\n      u %= M;\n      if(u < 0) u += M;\n\n      return u;\n  \
    \  }\n\n    explicit operator int32_t() const noexcept {return val;}\n    explicit\
    \ operator int64_t() const noexcept {return val;}\n\n    static void init(uint32_t\
    \ m){M = m;}\n\n    friend auto operator-(const runtime_modint &a){return runtime_modint(-a.val);}\n\
    \n    friend auto operator+(int64_t a, const runtime_modint &b){return runtime_modint(a)\
    \ + b;}\n    friend auto operator-(int64_t a, const runtime_modint &b){return\
    \ runtime_modint(a) - b;}\n    friend auto operator*(int64_t a, const runtime_modint\
    \ &b){return runtime_modint(a) * b;}\n    friend auto operator/(int64_t a, const\
    \ runtime_modint &b){return runtime_modint(a) / b;}\n\n    friend std::istream&\
    \ operator>>(std::istream &is, runtime_modint &a){is >> a.val; return is;}\n \
    \   friend std::ostream& operator<<(std::ostream &os, const runtime_modint &a){os\
    \ << a.val; return os;}\n  };\n\n  template <typename Tag> uint32_t runtime_modint<Tag>::M;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: old/runtime_mint.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: old/runtime_mint.cpp
layout: document
redirect_from:
- /library/old/runtime_mint.cpp
- /library/old/runtime_mint.cpp.html
title: old/runtime_mint.cpp
---
