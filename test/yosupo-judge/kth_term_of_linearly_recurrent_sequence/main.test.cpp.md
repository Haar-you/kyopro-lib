---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Convolution/ntt_convolution.cpp
    title: Number theoretic transform
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':x:'
    path: Mylib/Math/linearly_recurrent_sequence.cpp
    title: Kth term of linearly recurrent sequence
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  - icon: ':x:'
    path: Mylib/Number/Prime/primitive_root.cpp
    title: Primitive root
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Convolution/ntt_convolution.cpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n#line\
    \ 4 \"Mylib/Number/Mint/mint.cpp\"\n\nnamespace haar_lib {\n  template <int32_t\
    \ M>\n  class modint {\n    uint32_t val_;\n\n  public:\n    constexpr static\
    \ auto mod() { return M; }\n\n    constexpr modint() : val_(0) {}\n    constexpr\
    \ modint(int64_t n) {\n      if (n >= M)\n        val_ = n % M;\n      else if\
    \ (n < 0)\n        val_ = n % M + M;\n      else\n        val_ = n;\n    }\n\n\
    \    constexpr auto &operator=(const modint &a) {\n      val_ = a.val_;\n    \
    \  return *this;\n    }\n    constexpr auto &operator+=(const modint &a) {\n \
    \     if (val_ + a.val_ >= M)\n        val_ = (uint64_t) val_ + a.val_ - M;\n\
    \      else\n        val_ += a.val_;\n      return *this;\n    }\n    constexpr\
    \ auto &operator-=(const modint &a) {\n      if (val_ < a.val_) val_ += M;\n \
    \     val_ -= a.val_;\n      return *this;\n    }\n    constexpr auto &operator*=(const\
    \ modint &a) {\n      val_ = (uint64_t) val_ * a.val_ % M;\n      return *this;\n\
    \    }\n    constexpr auto &operator/=(const modint &a) {\n      val_ = (uint64_t)\
    \ val_ * a.inv().val_ % M;\n      return *this;\n    }\n\n    constexpr auto operator+(const\
    \ modint &a) const { return modint(*this) += a; }\n    constexpr auto operator-(const\
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
    \ { return val_; }\n  };\n}  // namespace haar_lib\n#line 7 \"Mylib/Convolution/ntt_convolution.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, int PRIM_ROOT, int MAX_SIZE>\n\
    \  class number_theoretic_transform {\n  public:\n    using value_type       \
    \             = T;\n    constexpr static int primitive_root = PRIM_ROOT;\n   \
    \ constexpr static int max_size       = MAX_SIZE;\n\n  private:\n    const int\
    \ MAX_POWER_;\n    std::vector<T> BASE_, INV_BASE_;\n\n  public:\n    number_theoretic_transform()\
    \ : MAX_POWER_(__builtin_ctz(MAX_SIZE)),\n                                   BASE_(MAX_POWER_\
    \ + 1),\n                                   INV_BASE_(MAX_POWER_ + 1) {\n    \
    \  static_assert((MAX_SIZE & (MAX_SIZE - 1)) == 0, \"MAX_SIZE must be power of\
    \ 2.\");\n      static_assert((T::mod() - 1) % MAX_SIZE == 0);\n\n      T t =\
    \ T::pow(PRIM_ROOT, (T::mod() - 1) >> (MAX_POWER_ + 2));\n      T s = t.inv();\n\
    \n      for (int i = MAX_POWER_; --i >= 0;) {\n        t *= t;\n        s *= s;\n\
    \        BASE_[i]     = -t;\n        INV_BASE_[i] = -s;\n      }\n    }\n\n  \
    \  void run(std::vector<T> &f, bool INVERSE = false) const {\n      const int\
    \ n = f.size();\n      assert((n & (n - 1)) == 0 and n <= MAX_SIZE);  // \u30C7\
    \u30FC\u30BF\u6570\u306F2\u306E\u51AA\u4E57\u500B\n\n      if (INVERSE) {\n  \
    \      for (int b = 1; b < n; b <<= 1) {\n          T w = 1;\n          for (int\
    \ j = 0, k = 1; j < n; j += 2 * b, ++k) {\n            for (int i = 0; i < b;\
    \ ++i) {\n              const auto s = f[i + j];\n              const auto t =\
    \ f[i + j + b];\n\n              f[i + j]     = s + t;\n              f[i + j\
    \ + b] = (s - t) * w;\n            }\n            w *= INV_BASE_[__builtin_ctz(k)];\n\
    \          }\n        }\n\n        const T t = T::inv(n);\n        for (auto &x\
    \ : f) x *= t;\n      } else {\n        for (int b = n >> 1; b; b >>= 1) {\n \
    \         T w = 1;\n          for (int j = 0, k = 1; j < n; j += 2 * b, ++k) {\n\
    \            for (int i = 0; i < b; ++i) {\n              const auto s = f[i +\
    \ j];\n              const auto t = f[i + j + b] * w;\n\n              f[i + j]\
    \     = s + t;\n              f[i + j + b] = s - t;\n            }\n         \
    \   w *= BASE_[__builtin_ctz(k)];\n          }\n        }\n      }\n    }\n\n\
    \    template <typename U>\n    std::vector<T> convolve(std::vector<U> f, std::vector<U>\
    \ g, bool is_same = false) const {\n      const int m = f.size() + g.size() -\
    \ 1;\n      int n       = 1;\n      while (n < m) n *= 2;\n\n      std::vector<T>\
    \ f2(n);\n      for (int i = 0; i < (int) f.size(); ++i) f2[i] = (int64_t) f[i];\n\
    \      run(f2);\n\n      if (is_same) {\n        for (int i = 0; i < n; ++i) f2[i]\
    \ *= f2[i];\n        run(f2, true);\n      } else {\n        std::vector<T> g2(n);\n\
    \        for (int i = 0; i < (int) g.size(); ++i) g2[i] = (int64_t) g[i];\n  \
    \      run(g2);\n\n        for (int i = 0; i < n; ++i) f2[i] *= g2[i];\n     \
    \   run(f2, true);\n      }\n\n      return f2;\n    }\n\n    template <typename\
    \ U>\n    std::vector<T> operator()(std::vector<U> f, std::vector<U> g, bool is_same\
    \ = false) const {\n      return convolve(f, g, is_same);\n    }\n  };\n\n  template\
    \ <typename T>\n  std::vector<T> convolve_general_mod(std::vector<T> f, std::vector<T>\
    \ g) {\n    static constexpr int M1 = 167772161, P1 = 3;\n    static constexpr\
    \ int M2 = 469762049, P2 = 3;\n    static constexpr int M3 = 1224736769, P3 =\
    \ 3;\n\n    auto res1 = number_theoretic_transform<modint<M1>, P1, 1 << 20>().convolve(f,\
    \ g);\n    auto res2 = number_theoretic_transform<modint<M2>, P2, 1 << 20>().convolve(f,\
    \ g);\n    auto res3 = number_theoretic_transform<modint<M3>, P3, 1 << 20>().convolve(f,\
    \ g);\n\n    const int n = res1.size();\n\n    std::vector<T> ret(n);\n\n    const\
    \ int64_t M12 = (int64_t) modint<M2>::inv(M1);\n    const int64_t M13 = (int64_t)\
    \ modint<M3>::inv(M1);\n    const int64_t M23 = (int64_t) modint<M3>::inv(M2);\n\
    \n    for (int i = 0; i < n; ++i) {\n      const int64_t r[3] = {(int64_t) res1[i],\
    \ (int64_t) res2[i], (int64_t) res3[i]};\n\n      const int64_t t0 = r[0] % M1;\n\
    \      const int64_t t1 = (r[1] - t0 + M2) * M12 % M2;\n      const int64_t t2\
    \ = ((r[2] - t0 + M3) * M13 % M3 - t1 + M3) * M23 % M3;\n\n      ret[i] = T(t0)\
    \ + T(t1) * M1 + T(t2) * M1 * M2;\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<T> input_vector(int N) {\n    std::vector<T> ret(N);\n\
    \    for (int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n\
    \  template <typename T>\n  std::vector<std::vector<T>> input_vector(int N, int\
    \ M) {\n    std::vector<std::vector<T>> ret(N);\n    for (int i = 0; i < N; ++i)\
    \ ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}  // namespace haar_lib\n\
    #line 3 \"Mylib/Math/linearly_recurrent_sequence.cpp\"\n#include <cstdint>\n#line\
    \ 5 \"Mylib/Math/linearly_recurrent_sequence.cpp\"\n\nnamespace haar_lib {\n \
    \ template <typename T, auto &convolve>\n  T linearly_recurrent_sequence(const\
    \ std::vector<T> &a, const std::vector<T> &c, int64_t k) {\n    assert(a.size()\
    \ == c.size());\n\n    const int d = a.size();\n\n    std::vector<T> Q(d + 1);\n\
    \    Q[0] = 1;\n    for (int i = 0; i < d; ++i) Q[d - i] = -c[i];\n\n    std::vector<T>\
    \ P = convolve(a, Q);\n    P.resize(d);\n\n    while (k > 0) {\n      auto q =\
    \ Q;\n      for (size_t i = 1; i < q.size(); i += 2) q[i] = -q[i];\n      auto\
    \ U = convolve(P, q);\n      auto A = convolve(Q, q);\n\n      if (k % 2 == 0)\
    \ {\n        for (int i = 0; i < d; ++i) P[i] = i * 2 < (int) U.size() ? U[i *\
    \ 2] : 0;\n      } else {\n        for (int i = 0; i < d; ++i) P[i] = i * 2 +\
    \ 1 < (int) U.size() ? U[i * 2 + 1] : 0;\n      }\n\n      for (int i = 0; i <=\
    \ d; ++i) Q[i] = i * 2 < (int) A.size() ? A[i * 2] : 0;\n\n      k >>= 1;\n  \
    \  }\n\n    return P[0];\n  }\n}  // namespace haar_lib\n#line 3 \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n\nnamespace haar_lib {\n  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t\
    \ m) {\n    int64_t ret = 1;\n    while (p > 0) {\n      if (p & 1) (ret *= n)\
    \ %= m;\n      (n *= n) %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}\
    \  // namespace haar_lib\n#line 3 \"Mylib/Number/Prime/primitive_root.cpp\"\n\n\
    namespace haar_lib {\n  constexpr int primitive_root(int p) {\n    int pf[30]\
    \ = {};\n    int k      = 0;\n    {\n      int n = p - 1;\n      for (int64_t\
    \ i = 2; i * i <= p; ++i) {\n        if (n % i == 0) {\n          pf[k++] = i;\n\
    \          while (n % i == 0) n /= i;\n        }\n      }\n      if (n != 1)\n\
    \        pf[k++] = n;\n    }\n\n    for (int g = 2; g <= p; ++g) {\n      bool\
    \ ok = true;\n      for (int i = 0; i < k; ++i) {\n        if (mod_pow(g, (p -\
    \ 1) / pf[i], p) == 1) {\n          ok = false;\n          break;\n        }\n\
    \      }\n\n      if (not ok) continue;\n\n      return g;\n    }\n    return\
    \ -1;\n  }\n}  // namespace haar_lib\n#line 9 \"test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconstexpr int mod       = 998244353;\nconstexpr\
    \ int prim_root = hl::primitive_root(mod);\nusing mint              = hl::modint<mod>;\n\
    using NTT               = hl::number_theoretic_transform<mint, prim_root, 1 <<\
    \ 21>;\nconst static auto ntt   = NTT();\n\nint main() {\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int d;\n  std::cin >> d;\n  int64_t\
    \ k;\n  std::cin >> k;\n\n  auto a = hl::input_vector<mint>(d);\n  auto c = hl::input_vector<mint>(d);\n\
    \  std::reverse(c.begin(), c.end());\n\n  auto ans = hl::linearly_recurrent_sequence<mint,\
    \ ntt>(a, c, k);\n\n  std::cout << ans << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n#include \"Mylib/Convolution/ntt_convolution.cpp\"\n\
    #include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/Math/linearly_recurrent_sequence.cpp\"\
    \n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/Number/Prime/primitive_root.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconstexpr int mod       = 998244353;\nconstexpr\
    \ int prim_root = hl::primitive_root(mod);\nusing mint              = hl::modint<mod>;\n\
    using NTT               = hl::number_theoretic_transform<mint, prim_root, 1 <<\
    \ 21>;\nconst static auto ntt   = NTT();\n\nint main() {\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int d;\n  std::cin >> d;\n  int64_t\
    \ k;\n  std::cin >> k;\n\n  auto a = hl::input_vector<mint>(d);\n  auto c = hl::input_vector<mint>(d);\n\
    \  std::reverse(c.begin(), c.end());\n\n  auto ans = hl::linearly_recurrent_sequence<mint,\
    \ ntt>(a, c, k);\n\n  std::cout << ans << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Convolution/ntt_convolution.cpp
  - Mylib/Number/Mint/mint.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/Math/linearly_recurrent_sequence.cpp
  - Mylib/Number/Prime/primitive_root.cpp
  - Mylib/Number/Mod/mod_pow.cpp
  isVerificationFile: true
  path: test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp
- /verify/test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp.html
title: test/yosupo-judge/kth_term_of_linearly_recurrent_sequence/main.test.cpp
---