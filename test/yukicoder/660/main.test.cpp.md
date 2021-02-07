---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Combinatorics/catalan_number.cpp
    title: Catalan number
  - icon: ':heavy_check_mark:'
    path: Mylib/Combinatorics/factorial_table.cpp
    title: Factorial table
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/660
    links:
    - https://yukicoder.me/problems/no/660
  bundledCode: "#line 1 \"test/yukicoder/660/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/660\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <int32_t M>\n  class\
    \ modint {\n    uint32_t val_;\n\n  public:\n    constexpr static auto mod(){return\
    \ M;}\n\n    constexpr modint(): val_(0){}\n    constexpr modint(int64_t n){\n\
    \      if(n >= M) val_ = n % M;\n      else if(n < 0) val_ = n % M + M;\n    \
    \  else val_ = n;\n    }\n\n    constexpr auto& operator=(const modint &a){val_\
    \ = a.val_; return *this;}\n    constexpr auto& operator+=(const modint &a){\n\
    \      if(val_ + a.val_ >= M) val_ = (uint64_t)val_ + a.val_ - M;\n      else\
    \ val_ += a.val_;\n      return *this;\n    }\n    constexpr auto& operator-=(const\
    \ modint &a){\n      if(val_ < a.val_) val_ += M;\n      val_ -= a.val_;\n   \
    \   return *this;\n    }\n    constexpr auto& operator*=(const modint &a){\n \
    \     val_ = (uint64_t)val_ * a.val_ % M;\n      return *this;\n    }\n    constexpr\
    \ auto& operator/=(const modint &a){\n      val_ = (uint64_t)val_ * a.inv().val_\
    \ % M;\n      return *this;\n    }\n\n    constexpr auto operator+(const modint\
    \ &a) const {return modint(*this) += a;}\n    constexpr auto operator-(const modint\
    \ &a) const {return modint(*this) -= a;}\n    constexpr auto operator*(const modint\
    \ &a) const {return modint(*this) *= a;}\n    constexpr auto operator/(const modint\
    \ &a) const {return modint(*this) /= a;}\n\n    constexpr bool operator==(const\
    \ modint &a) const {return val_ == a.val_;}\n    constexpr bool operator!=(const\
    \ modint &a) const {return val_ != a.val_;}\n\n    constexpr auto& operator++(){*this\
    \ += 1; return *this;}\n    constexpr auto& operator--(){*this -= 1; return *this;}\n\
    \n    constexpr auto operator++(int){auto t = *this; *this += 1; return t;}\n\
    \    constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}\n\n\
    \    constexpr static modint pow(int64_t n, int64_t p){\n      if(p < 0) return\
    \ pow(n, -p).inv();\n\n      int64_t ret = 1, e = n % M;\n      for(; p; (e *=\
    \ e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;\n      return ret;\n    }\n\n \
    \   constexpr static modint inv(int64_t a){\n      int64_t b = M, u = 1, v = 0;\n\
    \n      while(b){\n        int64_t t = a / b;\n        a -= t * b; std::swap(a,\
    \ b);\n        u -= t * v; std::swap(u, v);\n      }\n\n      u %= M;\n      if(u\
    \ < 0) u += M;\n\n      return u;\n    }\n\n    constexpr static auto frac(int64_t\
    \ a, int64_t b){return modint(a) / modint(b);}\n\n    constexpr auto pow(int64_t\
    \ p) const {return pow(val_, p);}\n    constexpr auto inv() const {return inv(val_);}\n\
    \n    friend constexpr auto operator-(const modint &a){return modint(M - a.val_);}\n\
    \n    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a)\
    \ + b;}\n    friend constexpr auto operator-(int64_t a, const modint &b){return\
    \ modint(a) - b;}\n    friend constexpr auto operator*(int64_t a, const modint\
    \ &b){return modint(a) * b;}\n    friend constexpr auto operator/(int64_t a, const\
    \ modint &b){return modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream\
    \ &s, modint &a){s >> a.val_; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint &a){s << a.val_; return s;}\n\n    template <int N>\n    static\
    \ auto div(){\n      static auto value = inv(N);\n      return value;\n    }\n\
    \n    explicit operator int32_t() const noexcept {return val_;}\n    explicit\
    \ operator int64_t() const noexcept {return val_;}\n  };\n}\n#line 3 \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n#include <cassert>\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class factorial_table {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    int N_;\n    std::vector<T> f_table_, if_table_;\n\n  public:\n    factorial_table(){}\n\
    \    factorial_table(int N): N_(N){\n      f_table_.assign(N + 1, 1);\n      if_table_.assign(N\
    \ + 1, 1);\n\n      for(int i = 1; i <= N; ++i){\n        f_table_[i] = f_table_[i\
    \ - 1] * i;\n      }\n\n      if_table_[N] = f_table_[N].inv();\n\n      for(int\
    \ i = N; --i >= 0;){\n        if_table_[i] = if_table_[i + 1] * (i + 1);\n   \
    \   }\n    }\n\n    T factorial(int64_t i) const {\n      assert(0 <= i and i\
    \ <= N_);\n      return f_table_[i];\n    }\n\n    T inv_factorial(int64_t i)\
    \ const {\n      assert(0 <= i and i <= N_);\n      return if_table_[i];\n   \
    \ }\n\n    T P(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k < 0)\
    \ return 0;\n      return factorial(n) * inv_factorial(n - k);\n    }\n\n    T\
    \ C(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k < 0) return 0;\n\
    \      return P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t\
    \ k) const {\n      if(n == 0 and k == 0) return 1;\n      return C(n + k - 1,\
    \ k);\n    }\n  };\n}\n#line 4 \"Mylib/Combinatorics/catalan_number.cpp\"\n\n\
    namespace haar_lib {\n  template <const auto &ft>\n  auto catalan_number(int64_t\
    \ n){\n    return ft.C(2 * n, n) - ft.C(2 * n, n - 1);\n  }\n}\n#line 8 \"test/yukicoder/660/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\nconst static\
    \ auto ft = hl::factorial_table<mint>(500000);\n\nint main(){\n  int N; std::cin\
    \ >> N;\n\n  std::vector<mint> c(N + 1);\n  for(int i = 0; i <= N; ++i){\n   \
    \ c[i] = hl::catalan_number<ft>(i);\n  }\n\n  for(int i = 1; i <= N; ++i){\n \
    \   c[i] += c[i - 1];\n  }\n\n  mint ans = 0;\n\n  for(int k = 0; k <= N / 2;\
    \ ++k){\n    ans += ft.C(N + 2 * k, k);\n  }\n\n  for(int k = 0; k < N / 2; ++k){\n\
    \    ans -= ft.C(N + 2 * k, k) * c[N / 2 - k - 1] * 2;\n  }\n\n  std::cout <<\
    \ ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/660\"\n\n#include <iostream>\n\
    #include <vector>\n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n#include \"Mylib/Combinatorics/catalan_number.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nusing mint = hl::modint<1000000007>;\nconst static auto ft = hl::factorial_table<mint>(500000);\n\
    \nint main(){\n  int N; std::cin >> N;\n\n  std::vector<mint> c(N + 1);\n  for(int\
    \ i = 0; i <= N; ++i){\n    c[i] = hl::catalan_number<ft>(i);\n  }\n\n  for(int\
    \ i = 1; i <= N; ++i){\n    c[i] += c[i - 1];\n  }\n\n  mint ans = 0;\n\n  for(int\
    \ k = 0; k <= N / 2; ++k){\n    ans += ft.C(N + 2 * k, k);\n  }\n\n  for(int k\
    \ = 0; k < N / 2; ++k){\n    ans -= ft.C(N + 2 * k, k) * c[N / 2 - k - 1] * 2;\n\
    \  }\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/Combinatorics/factorial_table.cpp
  - Mylib/Combinatorics/catalan_number.cpp
  isVerificationFile: true
  path: test/yukicoder/660/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 12:47:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/660/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/660/main.test.cpp
- /verify/test/yukicoder/660/main.test.cpp.html
title: test/yukicoder/660/main.test.cpp
---
