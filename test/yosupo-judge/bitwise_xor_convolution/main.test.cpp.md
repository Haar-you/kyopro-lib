---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Convolution/convolution_xor.cpp
    title: Convolution (Index bitwise XOR)
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/yosupo-judge/bitwise_xor_convolution/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\
    \n#include <iostream>\n#line 3 \"Mylib/IO/input_vector.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\nnamespace haar_lib {\n\
    \  template <int32_t M>\n  class modint {\n    uint32_t val_;\n\n  public:\n \
    \   constexpr static auto mod(){return M;}\n\n    constexpr modint(): val_(0){}\n\
    \    constexpr modint(int64_t n){\n      if(n >= M) val_ = n % M;\n      else\
    \ if(n < 0) val_ = n % M + M;\n      else val_ = n;\n    }\n\n    constexpr auto&\
    \ operator=(const modint &a){val_ = a.val_; return *this;}\n    constexpr auto&\
    \ operator+=(const modint &a){\n      if(val_ + a.val_ >= M) val_ = (uint64_t)val_\
    \ + a.val_ - M;\n      else val_ += a.val_;\n      return *this;\n    }\n    constexpr\
    \ auto& operator-=(const modint &a){\n      if(val_ < a.val_) val_ += M;\n   \
    \   val_ -= a.val_;\n      return *this;\n    }\n    constexpr auto& operator*=(const\
    \ modint &a){\n      val_ = (uint64_t)val_ * a.val_ % M;\n      return *this;\n\
    \    }\n    constexpr auto& operator/=(const modint &a){\n      val_ = (uint64_t)val_\
    \ * a.inv().val_ % M;\n      return *this;\n    }\n\n    constexpr auto operator+(const\
    \ modint &a) const {return modint(*this) += a;}\n    constexpr auto operator-(const\
    \ modint &a) const {return modint(*this) -= a;}\n    constexpr auto operator*(const\
    \ modint &a) const {return modint(*this) *= a;}\n    constexpr auto operator/(const\
    \ modint &a) const {return modint(*this) /= a;}\n\n    constexpr bool operator==(const\
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
    \ operator int64_t() const noexcept {return val_;}\n  };\n}\n#line 3 \"Mylib/Convolution/convolution_xor.cpp\"\
    \n#include <cassert>\n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T>\
    \ convolution_xor(std::vector<T> f, std::vector<T> g){\n    const int n = f.size();\n\
    \    assert((int)f.size() == n and (int)g.size() == n and (n & (n - 1)) == 0);\n\
    \n    auto fwt =\n      [n](std::vector<T> f){\n        for(int i = 1; i < n;\
    \ i <<= 1){\n          for(int j = 0; j < n; ++j){\n            if((j & i) ==\
    \ 0){\n              auto x = f[j], y = f[j | i];\n              f[j] = x + y;\n\
    \              f[j | i] = x - y;\n            }\n          }\n        }\n    \
    \    return f;\n      };\n\n    auto ifwt =\n      [n](std::vector<T> f){\n  \
    \      for(int i = 1; i < n; i <<= 1){\n          for(int j = 0; j < n; ++j){\n\
    \            if((j & i) == 0){\n              auto x = f[j], y = f[j | i];\n \
    \             f[j] = (x + y) / 2;\n              f[j | i] = (x - y) / 2;\n   \
    \         }\n          }\n        }\n        return f;\n      };\n\n    f = fwt(f);\n\
    \    g = fwt(g);\n\n    for(int i = 0; i < n; ++i) f[i] *= g[i];\n\n    f = ifwt(f);\n\
    \n    return f;\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include\
    \ <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string\
    \ join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 8 \"test/yosupo-judge/bitwise_xor_convolution/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconstexpr int mod = 998244353;\nusing mint = hl::modint<mod>;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N; std::cin >> N;\n  const auto a = hl::input_vector<mint>(1 << N);\n  const\
    \ auto b = hl::input_vector<mint>(1 << N);\n\n  const auto ans = convolution_xor(a,\
    \ b);\n  std::cout << hl::join(ans.begin(), ans.end()) << \"\\n\";\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <iostream>\n#include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/Number/Mint/mint.cpp\"\
    \n#include \"Mylib/Convolution/convolution_xor.cpp\"\n#include \"Mylib/IO/join.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconstexpr int mod = 998244353;\nusing mint = hl::modint<mod>;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N; std::cin >> N;\n  const auto a = hl::input_vector<mint>(1 << N);\n  const\
    \ auto b = hl::input_vector<mint>(1 << N);\n\n  const auto ans = convolution_xor(a,\
    \ b);\n  std::cout << hl::join(ans.begin(), ans.end()) << \"\\n\";\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/Number/Mint/mint.cpp
  - Mylib/Convolution/convolution_xor.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/yosupo-judge/bitwise_xor_convolution/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-18 01:35:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/bitwise_xor_convolution/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/bitwise_xor_convolution/main.test.cpp
- /verify/test/yosupo-judge/bitwise_xor_convolution/main.test.cpp.html
title: test/yosupo-judge/bitwise_xor_convolution/main.test.cpp
---
