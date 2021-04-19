---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':heavy_check_mark:'
    path: Mylib/Math/berlekamp_massey.cpp
    title: Berlekamp-Massey
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"test/yosupo-judge/find_linear_recurrence/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n\
    \n#line 2 \"Mylib/Number/Mint/mint.cpp\"\n#include <iostream>\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <int32_t M>\n  class modint {\n    uint32_t\
    \ val_;\n\n  public:\n    constexpr static auto mod(){return M;}\n\n    constexpr\
    \ modint(): val_(0){}\n    constexpr modint(int64_t n){\n      if(n >= M) val_\
    \ = n % M;\n      else if(n < 0) val_ = n % M + M;\n      else val_ = n;\n   \
    \ }\n\n    constexpr auto& operator=(const modint &a){val_ = a.val_; return *this;}\n\
    \    constexpr auto& operator+=(const modint &a){\n      if(val_ + a.val_ >= M)\
    \ val_ = (uint64_t)val_ + a.val_ - M;\n      else val_ += a.val_;\n      return\
    \ *this;\n    }\n    constexpr auto& operator-=(const modint &a){\n      if(val_\
    \ < a.val_) val_ += M;\n      val_ -= a.val_;\n      return *this;\n    }\n  \
    \  constexpr auto& operator*=(const modint &a){\n      val_ = (uint64_t)val_ *\
    \ a.val_ % M;\n      return *this;\n    }\n    constexpr auto& operator/=(const\
    \ modint &a){\n      val_ = (uint64_t)val_ * a.inv().val_ % M;\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const modint &a) const {return modint(*this)\
    \ += a;}\n    constexpr auto operator-(const modint &a) const {return modint(*this)\
    \ -= a;}\n    constexpr auto operator*(const modint &a) const {return modint(*this)\
    \ *= a;}\n    constexpr auto operator/(const modint &a) const {return modint(*this)\
    \ /= a;}\n\n    constexpr bool operator==(const modint &a) const {return val_\
    \ == a.val_;}\n    constexpr bool operator!=(const modint &a) const {return val_\
    \ != a.val_;}\n\n    constexpr auto& operator++(){*this += 1; return *this;}\n\
    \    constexpr auto& operator--(){*this -= 1; return *this;}\n\n    constexpr\
    \ auto operator++(int){auto t = *this; *this += 1; return t;}\n    constexpr auto\
    \ operator--(int){auto t = *this; *this -= 1; return t;}\n\n    constexpr static\
    \ modint pow(int64_t n, int64_t p){\n      if(p < 0) return pow(n, -p).inv();\n\
    \n      int64_t ret = 1, e = n % M;\n      for(; p; (e *= e) %= M, p >>= 1) if(p\
    \ & 1) (ret *= e) %= M;\n      return ret;\n    }\n\n    constexpr static modint\
    \ inv(int64_t a){\n      int64_t b = M, u = 1, v = 0;\n\n      while(b){\n   \
    \     int64_t t = a / b;\n        a -= t * b; std::swap(a, b);\n        u -= t\
    \ * v; std::swap(u, v);\n      }\n\n      u %= M;\n      if(u < 0) u += M;\n\n\
    \      return u;\n    }\n\n    constexpr static auto frac(int64_t a, int64_t b){return\
    \ modint(a) / modint(b);}\n\n    constexpr auto pow(int64_t p) const {return pow(val_,\
    \ p);}\n    constexpr auto inv() const {return inv(val_);}\n\n    friend constexpr\
    \ auto operator-(const modint &a){return modint(M - a.val_);}\n\n    friend constexpr\
    \ auto operator+(int64_t a, const modint &b){return modint(a) + b;}\n    friend\
    \ constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}\n\
    \    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a)\
    \ * b;}\n    friend constexpr auto operator/(int64_t a, const modint &b){return\
    \ modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream &s, modint\
    \ &a){s >> a.val_; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint &a){s << a.val_; return s;}\n\n    template <int N>\n    static\
    \ auto div(){\n      static auto value = inv(N);\n      return value;\n    }\n\
    \n    explicit operator int32_t() const noexcept {return val_;}\n    explicit\
    \ operator int64_t() const noexcept {return val_;}\n  };\n}\n#line 3 \"Mylib/IO/input_vector.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T>\
    \ input_vector(int N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N;\
    \ ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n  template <typename T>\n\
    \  std::vector<std::vector<T>> input_vector(int N, int M){\n    std::vector<std::vector<T>>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return\
    \ ret;\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include <string>\n\
    \nnamespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter first,\
    \ Iter last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n#line 3 \"Mylib/Math/berlekamp_massey.cpp\"\
    \n\ntemplate <typename T>\nstd::vector<T> berlekamp_massey(const std::vector<T>\
    \ &s){\n  const int N = s.size();\n\n  std::vector<T> C = {1}, B = {1};\n  int\
    \ L = 0, m = 1;\n  T b = 1;\n\n  for(int n = 0; n < N; ++n){\n    T d = s[n];\n\
    \    for(size_t i = 1; i < C.size(); ++i) d += C[i] * s[n - i];\n\n    if(d ==\
    \ 0){\n      m += 1;\n    }else if(2 * L <= n){\n      auto temp = C;\n      if(C.size()\
    \ < B.size() + m) C.resize(B.size() + m);\n      const T t = d / b;\n      for(int\
    \ i = 0; i < (int)B.size(); ++i) C[i + m] -= t * B[i];\n      L = n + 1 - L;\n\
    \      B = temp;\n      b = d;\n      m = 1;\n    }else{\n      if(C.size() <\
    \ B.size() + m) C.resize(B.size() + m);\n      const T t = d / b;\n      for(int\
    \ i = 0; i < (int)B.size(); ++i) C[i + m] -= t * B[i];\n      m += 1;\n    }\n\
    \  }\n\n  std::vector<T> ret(L);\n  for(int i = 0; i < L; ++i) ret[i] = -C[i +\
    \ 1];\n\n  return ret;\n}\n#line 7 \"test/yosupo-judge/find_linear_recurrence/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconstexpr int mod = 998244353;\nusing mint = hl::modint<mod>;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N; std::cin >> N;\n  auto a = hl::input_vector<mint>(N);\n\n  auto c = berlekamp_massey(a);\n\
    \  std::cout << c.size() << \"\\n\"\n            << hl::join(c.begin(), c.end())\
    \ << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"Mylib/IO/input_vector.cpp\"\
    \n#include \"Mylib/IO/join.cpp\"\n#include \"Mylib/Math/berlekamp_massey.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconstexpr int mod = 998244353;\nusing mint = hl::modint<mod>;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N; std::cin >> N;\n  auto a = hl::input_vector<mint>(N);\n\n  auto c = berlekamp_massey(a);\n\
    \  std::cout << c.size() << \"\\n\"\n            << hl::join(c.begin(), c.end())\
    \ << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/join.cpp
  - Mylib/Math/berlekamp_massey.cpp
  isVerificationFile: true
  path: test/yosupo-judge/find_linear_recurrence/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-20 01:19:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/find_linear_recurrence/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/find_linear_recurrence/main.test.cpp
- /verify/test/yosupo-judge/find_linear_recurrence/main.test.cpp.html
title: test/yosupo-judge/find_linear_recurrence/main.test.cpp
---
