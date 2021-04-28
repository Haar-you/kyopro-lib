---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':x:'
    path: Mylib/LinearAlgebra/matrix.cpp
    title: Matrix
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/yosupo-judge/matrix_product/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include <iostream>\n\
    \n#line 3 \"Mylib/IO/input_vector.cpp\"\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<T> input_vector(int N) {\n    std::vector<T>\
    \ ret(N);\n    for (int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n\
    \  }\n\n  template <typename T>\n  std::vector<std::vector<T>> input_vector(int\
    \ N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for (int i = 0; i\
    \ < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\
    \nnamespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter first,\
    \ Iter last, std::string delim = \" \") {\n    std::stringstream s;\n\n    for\
    \ (auto it = first; it != last; ++it) {\n      if (it != first) s << delim;\n\
    \      s << *it;\n    }\n\n    return s.str();\n  }\n}  // namespace haar_lib\n\
    #line 2 \"Mylib/LinearAlgebra/matrix.cpp\"\n#include <cassert>\n#line 4 \"Mylib/LinearAlgebra/matrix.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class matrix {\n    std::vector<std::vector<T>>\
    \ data_;\n    size_t R_, C_;\n\n  public:\n    matrix() : data_(), R_(0), C_(0)\
    \ {}\n    matrix(size_t R, size_t C, T value = T()) : data_(R, std::vector<T>(C,\
    \ value)), R_(R), C_(C) {}\n    matrix(std::vector<std::vector<T>> data) : data_(data),\
    \ R_(data.size()), C_(data[0].size()) {}\n\n    const auto &operator[](size_t\
    \ i) const {\n      return data_[i];\n    }\n\n    friend auto operator*(const\
    \ matrix<T> &a, const matrix<T> &b) {\n      assert(a.C_ == b.R_);\n\n      matrix\
    \ ret(a.R_, b.C_);\n\n      for (size_t i = 0; i < a.R_; ++i) {\n        for (size_t\
    \ k = 0; k < a.C_; ++k) {\n          for (size_t j = 0; j < b.C_; ++j) {\n   \
    \         ret.data_[i][j] += a.data_[i][k] * b.data_[k][j];\n          }\n   \
    \     }\n      }\n\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n\
    #line 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <int32_t M>\n  class modint {\n    uint32_t val_;\n\n  public:\n\
    \    constexpr static auto mod() { return M; }\n\n    constexpr modint() : val_(0)\
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
    \ { return val_; }\n  };\n}  // namespace haar_lib\n#line 9 \"test/yosupo-judge/matrix_product/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, M, K;\n\
    \  std::cin >> N >> M >> K;\n\n  auto a = hl::matrix(hl::input_vector<mint>(N,\
    \ M));\n  auto b = hl::matrix(hl::input_vector<mint>(M, K));\n\n  auto c = a *\
    \ b;\n\n  for (int i = 0; i < N; ++i) {\n    std::cout << hl::join(c[i].begin(),\
    \ c[i].end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n\n#include\
    \ <iostream>\n\n#include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/join.cpp\"\
    \n#include \"Mylib/LinearAlgebra/matrix.cpp\"\n#include \"Mylib/Number/Mint/mint.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<998244353>;\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, M, K;\n\
    \  std::cin >> N >> M >> K;\n\n  auto a = hl::matrix(hl::input_vector<mint>(N,\
    \ M));\n  auto b = hl::matrix(hl::input_vector<mint>(M, K));\n\n  auto c = a *\
    \ b;\n\n  for (int i = 0; i < N; ++i) {\n    std::cout << hl::join(c[i].begin(),\
    \ c[i].end()) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/join.cpp
  - Mylib/LinearAlgebra/matrix.cpp
  - Mylib/Number/Mint/mint.cpp
  isVerificationFile: true
  path: test/yosupo-judge/matrix_product/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/matrix_product/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/matrix_product/main.test.cpp
- /verify/test/yosupo-judge/matrix_product/main.test.cpp.html
title: test/yosupo-judge/matrix_product/main.test.cpp
---
