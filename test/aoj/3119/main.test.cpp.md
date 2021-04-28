---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Convolution/fast_mobius_transform_superset.cpp
    title: "Fast M\xF6bius transform (Supersets)"
  - icon: ':x:'
    path: Mylib/Convolution/fast_zeta_transform_superset.cpp
    title: Fast Zeta transform (Supersets)
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':x:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3119
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3119
  bundledCode: "#line 1 \"test/aoj/3119/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3119\"\
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"Mylib/Convolution/fast_mobius_transform_superset.cpp\"\
    \n#include <cassert>\n#include <functional>\n#line 5 \"Mylib/Convolution/fast_mobius_transform_superset.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, typename Func = std::minus<T>>\n\
    \  std::vector<T> fast_mobius_transform_superset(std::vector<T> f, const Func\
    \ &op = std::minus<T>()) {\n    const int N = f.size();\n    assert((N & (N -\
    \ 1)) == 0 && \"N must be a power of 2\");\n    for (int i = 1; i < N; i <<= 1)\
    \ {\n      for (int j = 0; j < N; ++j) {\n        if (not(j & i)) f[j] = op(f[j],\
    \ f[j ^ i]);\n      }\n    }\n    return f;\n  }\n}  // namespace haar_lib\n#line\
    \ 5 \"Mylib/Convolution/fast_zeta_transform_superset.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Func = std::plus<T>>\n  std::vector<T> fast_zeta_transform_superset(std::vector<T>\
    \ f, const Func &op = std::plus<T>()) {\n    const int N = f.size();\n    assert((N\
    \ & (N - 1)) == 0 && \"N must be a power of 2\");\n    for (int i = 1; i < N;\
    \ i <<= 1) {\n      for (int j = 0; j < N; ++j) {\n        if (not(j & i)) f[j]\
    \ = op(f[j], f[j ^ i]);\n      }\n    }\n    return f;\n  }\n}  // namespace haar_lib\n\
    #line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  std::vector<T> input_vector(int N) {\n    std::vector<T> ret(N);\n   \
    \ for (int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n  template\
    \ <typename T>\n  std::vector<std::vector<T>> input_vector(int N, int M) {\n \
    \   std::vector<std::vector<T>> ret(N);\n    for (int i = 0; i < N; ++i) ret[i]\
    \ = input_vector<T>(M);\n    return ret;\n  }\n}  // namespace haar_lib\n#line\
    \ 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\nnamespace haar_lib {\n\
    \  template <int32_t M>\n  class modint {\n    uint32_t val_;\n\n  public:\n \
    \   constexpr static auto mod() { return M; }\n\n    constexpr modint() : val_(0)\
    \ {}\n    constexpr modint(int64_t n) {\n      if (n >= M)\n        val_ = n %\
    \ M;\n      else if (n < 0)\n        val_ = n % M + M;\n      else\n        val_\
    \ = n;\n    }\n\n    constexpr auto &operator=(const modint &a) {\n      val_\
    \ = a.val_;\n      return *this;\n    }\n    constexpr auto &operator+=(const\
    \ modint &a) {\n      if (val_ + a.val_ >= M)\n        val_ = (uint64_t) val_\
    \ + a.val_ - M;\n      else\n        val_ += a.val_;\n      return *this;\n  \
    \  }\n    constexpr auto &operator-=(const modint &a) {\n      if (val_ < a.val_)\
    \ val_ += M;\n      val_ -= a.val_;\n      return *this;\n    }\n    constexpr\
    \ auto &operator*=(const modint &a) {\n      val_ = (uint64_t) val_ * a.val_ %\
    \ M;\n      return *this;\n    }\n    constexpr auto &operator/=(const modint\
    \ &a) {\n      val_ = (uint64_t) val_ * a.inv().val_ % M;\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const modint &a) const { return modint(*this)\
    \ += a; }\n    constexpr auto operator-(const modint &a) const { return modint(*this)\
    \ -= a; }\n    constexpr auto operator*(const modint &a) const { return modint(*this)\
    \ *= a; }\n    constexpr auto operator/(const modint &a) const { return modint(*this)\
    \ /= a; }\n\n    constexpr bool operator==(const modint &a) const { return val_\
    \ == a.val_; }\n    constexpr bool operator!=(const modint &a) const { return\
    \ val_ != a.val_; }\n\n    constexpr auto &operator++() {\n      *this += 1;\n\
    \      return *this;\n    }\n    constexpr auto &operator--() {\n      *this -=\
    \ 1;\n      return *this;\n    }\n\n    constexpr auto operator++(int) {\n   \
    \   auto t = *this;\n      *this += 1;\n      return t;\n    }\n    constexpr\
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
    \ { return val_; }\n  };\n}  // namespace haar_lib\n#line 9 \"test/aoj/3119/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n\n  auto a = hl::input_vector<int>(n);\n\n  std::vector<int>\
    \ dp(1 << 20);\n  for (auto x : a) dp[x] += 1;\n\n  dp = hl::fast_zeta_transform_superset(dp);\n\
    \n  std::vector<mint> f(1 << 20);\n  for (int i = 0; i < 1 << 20; ++i) f[i] =\
    \ mint::pow(2, dp[i]) - 1;\n\n  auto ans = hl::fast_mobius_transform_superset(f);\n\
    \n  std::cout << ans[0] << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3119\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Convolution/fast_mobius_transform_superset.cpp\"\
    \n#include \"Mylib/Convolution/fast_zeta_transform_superset.cpp\"\n#include \"\
    Mylib/IO/input_vector.cpp\"\n#include \"Mylib/Number/Mint/mint.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\n\nint main() {\n  int\
    \ n;\n  std::cin >> n;\n\n  auto a = hl::input_vector<int>(n);\n\n  std::vector<int>\
    \ dp(1 << 20);\n  for (auto x : a) dp[x] += 1;\n\n  dp = hl::fast_zeta_transform_superset(dp);\n\
    \n  std::vector<mint> f(1 << 20);\n  for (int i = 0; i < 1 << 20; ++i) f[i] =\
    \ mint::pow(2, dp[i]) - 1;\n\n  auto ans = hl::fast_mobius_transform_superset(f);\n\
    \n  std::cout << ans[0] << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Convolution/fast_mobius_transform_superset.cpp
  - Mylib/Convolution/fast_zeta_transform_superset.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/Number/Mint/mint.cpp
  isVerificationFile: true
  path: test/aoj/3119/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/3119/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/3119/main.test.cpp
- /verify/test/aoj/3119/main.test.cpp.html
title: test/aoj/3119/main.test.cpp
---
