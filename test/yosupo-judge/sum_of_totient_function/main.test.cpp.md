---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':x:'
    path: Mylib/Number/Totient/totient_sum.cpp
    title: Sum of totient function
  - icon: ':x:'
    path: Mylib/Number/Totient/totient_table.cpp
    title: Euler's totient function (Table)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"test/yosupo-judge/sum_of_totient_function/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\
    \n#include <iostream>\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <int32_t M>\n  class modint {\n    uint32_t\
    \ val_;\n\n  public:\n    constexpr static auto mod() { return M; }\n\n    constexpr\
    \ modint() : val_(0) {}\n    constexpr modint(int64_t n) {\n      if (n >= M)\n\
    \        val_ = n % M;\n      else if (n < 0)\n        val_ = n % M + M;\n   \
    \   else\n        val_ = n;\n    }\n\n    constexpr auto &operator=(const modint\
    \ &a) {\n      val_ = a.val_;\n      return *this;\n    }\n    constexpr auto\
    \ &operator+=(const modint &a) {\n      if (val_ + a.val_ >= M)\n        val_\
    \ = (uint64_t) val_ + a.val_ - M;\n      else\n        val_ += a.val_;\n     \
    \ return *this;\n    }\n    constexpr auto &operator-=(const modint &a) {\n  \
    \    if (val_ < a.val_) val_ += M;\n      val_ -= a.val_;\n      return *this;\n\
    \    }\n    constexpr auto &operator*=(const modint &a) {\n      val_ = (uint64_t)\
    \ val_ * a.val_ % M;\n      return *this;\n    }\n    constexpr auto &operator/=(const\
    \ modint &a) {\n      val_ = (uint64_t) val_ * a.inv().val_ % M;\n      return\
    \ *this;\n    }\n\n    constexpr auto operator+(const modint &a) const { return\
    \ modint(*this) += a; }\n    constexpr auto operator-(const modint &a) const {\
    \ return modint(*this) -= a; }\n    constexpr auto operator*(const modint &a)\
    \ const { return modint(*this) *= a; }\n    constexpr auto operator/(const modint\
    \ &a) const { return modint(*this) /= a; }\n\n    constexpr bool operator==(const\
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
    \ { return val_; }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/Number/Totient/totient_sum.cpp\"\
    \n#include <cmath>\n#include <unordered_map>\n#include <vector>\n#line 2 \"Mylib/Number/Totient/totient_table.cpp\"\
    \n#include <numeric>\n#line 4 \"Mylib/Number/Totient/totient_table.cpp\"\n\nnamespace\
    \ haar_lib {\n  std::vector<int> totient_table(int n) {\n    std::vector<int>\
    \ ret(n + 1);\n    std::iota(ret.begin(), ret.end(), 0);\n\n    for (int i = 2;\
    \ i <= n; ++i) {\n      if (ret[i] == i) {\n        for (int j = i; j <= n; j\
    \ += i) {\n          ret[j] = ret[j] / i * (i - 1);\n        }\n      }\n    }\n\
    \n    return ret;\n  }\n}  // namespace haar_lib\n#line 6 \"Mylib/Number/Totient/totient_sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  T totient_sum(int64_t N)\
    \ {\n    const int64_t K = (int64_t) pow(N, 0.66);\n\n    std::vector<T> memo1(K\
    \ + 1);\n    auto table = totient_table(K);\n    T sum      = 0;\n    for (int\
    \ i = 1; i <= K; ++i) {\n      sum += table[i];\n      memo1[i] = sum;\n    }\n\
    \n    std::unordered_map<int64_t, T> memo2;\n\n    auto f =\n        [&](auto\
    \ &f, int64_t x) -> T {\n      if (x <= K) return memo1[x];\n      if (memo2.find(x)\
    \ != memo2.end()) return memo2[x];\n\n      T ret = 0;\n\n      const int64_t\
    \ s = sqrt(x);\n\n      for (int i = 2; i <= s; ++i) {\n        if (x / i <= s)\
    \ continue;\n        ret -= f(f, x / i);\n      }\n\n      for (int i = 1; i <=\
    \ s; ++i) {\n        ret -= f(f, i) * (x / i - x / (i + 1));\n      }\n\n    \
    \  ret += (T) x * (x + 1) / 2;\n\n      return memo2[x] = ret;\n    };\n\n   \
    \ return f(f, N);\n  }\n}  // namespace haar_lib\n#line 6 \"test/yosupo-judge/sum_of_totient_function/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int64_t N;\n\
    \  std::cin >> N;\n\n  std::cout << hl::totient_sum<mint>(N) << \"\\n\";\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"\
    Mylib/Number/Totient/totient_sum.cpp\"\n\nnamespace hl = haar_lib;\n\nusing mint\
    \ = hl::modint<998244353>;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int64_t N;\n  std::cin >> N;\n\n  std::cout << hl::totient_sum<mint>(N) <<\
    \ \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/Number/Totient/totient_sum.cpp
  - Mylib/Number/Totient/totient_table.cpp
  isVerificationFile: true
  path: test/yosupo-judge/sum_of_totient_function/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/sum_of_totient_function/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/sum_of_totient_function/main.test.cpp
- /verify/test/yosupo-judge/sum_of_totient_function/main.test.cpp.html
title: test/yosupo-judge/sum_of_totient_function/main.test.cpp
---