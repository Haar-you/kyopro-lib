---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Math/sum_of_exponential_times_polynomial_limit.cpp
    title: Sum of exponential times polynomial limit (\sum_{i=0}^{\infty} r^i i^d)
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
    links:
    - https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit
  bundledCode: "#line 1 \"test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Math/sum_of_exponential_times_polynomial_limit.cpp\"\
    \n#include <cstdint>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  T sum_of_exponential_times_polynomial_limit(int64_t r, int d) {\n    T\
    \ ret   = 0;\n    T r_pow = 1;\n    int m   = T::mod();\n\n    std::vector<T>\
    \ s(d + 1);\n    std::vector<T> invs(d + 2);\n    invs[1] = 1;\n\n    for (int\
    \ i = 2; i <= d + 1; ++i) {\n      invs[i] = (m / i) * (m - invs[m % i]);\n  \
    \  }\n\n    for (int i = 0; i <= d; ++i) {\n      if (i > 0) s[i] += s[i - 1];\n\
    \      s[i] += T::pow(i, d) * r_pow;\n      r_pow *= r;\n    }\n\n    T t = 1;\n\
    \    for (int i = 0; i <= d; ++i) {\n      ret += t * s[d - i];\n      t *= invs[i\
    \ + 1] * (-r) * (d + 1 - i);\n    }\n\n    ret /= T::pow(1 - r, d + 1);\n\n  \
    \  return ret;\n  }\n}  // namespace haar_lib\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <int32_t M>\n  class\
    \ modint {\n    uint32_t val_;\n\n  public:\n    constexpr static auto mod() {\
    \ return M; }\n\n    constexpr modint() : val_(0) {}\n    constexpr modint(int64_t\
    \ n) {\n      if (n >= M)\n        val_ = n % M;\n      else if (n < 0)\n    \
    \    val_ = n % M + M;\n      else\n        val_ = n;\n    }\n\n    constexpr\
    \ auto &operator=(const modint &a) {\n      val_ = a.val_;\n      return *this;\n\
    \    }\n    constexpr auto &operator+=(const modint &a) {\n      if (val_ + a.val_\
    \ >= M)\n        val_ = (uint64_t) val_ + a.val_ - M;\n      else\n        val_\
    \ += a.val_;\n      return *this;\n    }\n    constexpr auto &operator-=(const\
    \ modint &a) {\n      if (val_ < a.val_) val_ += M;\n      val_ -= a.val_;\n \
    \     return *this;\n    }\n    constexpr auto &operator*=(const modint &a) {\n\
    \      val_ = (uint64_t) val_ * a.val_ % M;\n      return *this;\n    }\n    constexpr\
    \ auto &operator/=(const modint &a) {\n      val_ = (uint64_t) val_ * a.inv().val_\
    \ % M;\n      return *this;\n    }\n\n    constexpr auto operator+(const modint\
    \ &a) const { return modint(*this) += a; }\n    constexpr auto operator-(const\
    \ modint &a) const { return modint(*this) -= a; }\n    constexpr auto operator*(const\
    \ modint &a) const { return modint(*this) *= a; }\n    constexpr auto operator/(const\
    \ modint &a) const { return modint(*this) /= a; }\n\n    constexpr bool operator==(const\
    \ modint &a) const { return val_ == a.val_; }\n    constexpr bool operator!=(const\
    \ modint &a) const { return val_ != a.val_; }\n\n    constexpr auto &operator++()\
    \ {\n      *this += 1;\n      return *this;\n    }\n    constexpr auto &operator--()\
    \ {\n      *this -= 1;\n      return *this;\n    }\n\n    constexpr auto operator++(int)\
    \ {\n      auto t = *this;\n      *this += 1;\n      return t;\n    }\n    constexpr\
    \ auto operator--(int) {\n      auto t = *this;\n      *this -= 1;\n      return\
    \ t;\n    }\n\n    constexpr static modint pow(int64_t n, int64_t p) {\n     \
    \ if (p < 0) return pow(n, -p).inv();\n\n      int64_t ret = 1, e = n % M;\n \
    \     for (; p; (e *= e) %= M, p >>= 1)\n        if (p & 1) (ret *= e) %= M;\n\
    \      return ret;\n    }\n\n    constexpr static modint inv(int64_t a) {\n  \
    \    int64_t b = M, u = 1, v = 0;\n\n      while (b) {\n        int64_t t = a\
    \ / b;\n        a -= t * b;\n        std::swap(a, b);\n        u -= t * v;\n \
    \       std::swap(u, v);\n      }\n\n      u %= M;\n      if (u < 0) u += M;\n\
    \n      return u;\n    }\n\n    constexpr static auto frac(int64_t a, int64_t\
    \ b) { return modint(a) / modint(b); }\n\n    constexpr auto pow(int64_t p) const\
    \ { return pow(val_, p); }\n    constexpr auto inv() const { return inv(val_);\
    \ }\n\n    friend constexpr auto operator-(const modint &a) { return modint(M\
    \ - a.val_); }\n\n    friend constexpr auto operator+(int64_t a, const modint\
    \ &b) { return modint(a) + b; }\n    friend constexpr auto operator-(int64_t a,\
    \ const modint &b) { return modint(a) - b; }\n    friend constexpr auto operator*(int64_t\
    \ a, const modint &b) { return modint(a) * b; }\n    friend constexpr auto operator/(int64_t\
    \ a, const modint &b) { return modint(a) / b; }\n\n    friend std::istream &operator>>(std::istream\
    \ &s, modint &a) {\n      s >> a.val_;\n      return s;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &s, const modint &a) {\n      s << a.val_;\n      return\
    \ s;\n    }\n\n    template <int N>\n    static auto div() {\n      static auto\
    \ value = inv(N);\n      return value;\n    }\n\n    explicit operator int32_t()\
    \ const noexcept { return val_; }\n    explicit operator int64_t() const noexcept\
    \ { return val_; }\n  };\n}  // namespace haar_lib\n#line 6 \"test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconstexpr int mod = 998244353;\nusing mint   \
    \     = hl::modint<mod>;\n\nint main() {\n  int r, d;\n  std::cin >> r >> d;\n\
    \  std::cout << hl::sum_of_exponential_times_polynomial_limit<mint>(r, d) << \"\
    \\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \n\n#include <iostream>\n#include \"Mylib/Math/sum_of_exponential_times_polynomial_limit.cpp\"\
    \n#include \"Mylib/Number/Mint/mint.cpp\"\n\nnamespace hl = haar_lib;\n\nconstexpr\
    \ int mod = 998244353;\nusing mint        = hl::modint<mod>;\n\nint main() {\n\
    \  int r, d;\n  std::cin >> r >> d;\n  std::cout << hl::sum_of_exponential_times_polynomial_limit<mint>(r,\
    \ d) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Math/sum_of_exponential_times_polynomial_limit.cpp
  - Mylib/Number/Mint/mint.cpp
  isVerificationFile: true
  path: test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp
  requiredBy: []
  timestamp: '2021-05-10 06:09:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp
- /verify/test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp.html
title: test/yosupo-judge/sum_of_exponential_times_polynomial_limit/main.test.cpp
---
