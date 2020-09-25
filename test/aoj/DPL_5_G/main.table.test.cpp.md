---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':x:'
    path: Mylib/Combinatorics/bell_number_table.cpp
    title: Bell number (Table)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
  bundledCode: "#line 1 \"test/aoj/DPL_5_G/main.table.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G\"\n\n#include\
    \ <iostream>\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\n#include <utility>\n\nnamespace\
    \ haar_lib {\n  template <int32_t M>\n  class modint {\n    uint32_t val;\n\n\
    \  public:\n    constexpr static auto mod(){return M;}\n\n    constexpr modint():\
    \ val(0){}\n    constexpr modint(int64_t n){\n      if(n >= M) val = n % M;\n\
    \      else if(n < 0) val = n % M + M;\n      else val = n;\n    }\n\n    constexpr\
    \ auto& operator=(const modint &a){val = a.val; return *this;}\n    constexpr\
    \ auto& operator+=(const modint &a){\n      if(val + a.val >= M) val = (uint64_t)val\
    \ + a.val - M;\n      else val += a.val;\n      return *this;\n    }\n    constexpr\
    \ auto& operator-=(const modint &a){\n      if(val < a.val) val += M;\n      val\
    \ -= a.val;\n      return *this;\n    }\n    constexpr auto& operator*=(const\
    \ modint &a){\n      val = (uint64_t)val * a.val % M;\n      return *this;\n \
    \   }\n    constexpr auto& operator/=(const modint &a){\n      val = (uint64_t)val\
    \ * a.inv().val % M;\n      return *this;\n    }\n\n    constexpr auto operator+(const\
    \ modint &a) const {return modint(*this) += a;}\n    constexpr auto operator-(const\
    \ modint &a) const {return modint(*this) -= a;}\n    constexpr auto operator*(const\
    \ modint &a) const {return modint(*this) *= a;}\n    constexpr auto operator/(const\
    \ modint &a) const {return modint(*this) /= a;}\n\n    constexpr bool operator==(const\
    \ modint &a) const {return val == a.val;}\n    constexpr bool operator!=(const\
    \ modint &a) const {return val != a.val;}\n\n    constexpr auto& operator++(){*this\
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
    \ p) const {return pow(val, p);}\n    constexpr auto inv() const {return inv(val);}\n\
    \n    friend constexpr auto operator-(const modint &a){return modint(M - a.val);}\n\
    \n    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a)\
    \ + b;}\n    friend constexpr auto operator-(int64_t a, const modint &b){return\
    \ modint(a) - b;}\n    friend constexpr auto operator*(int64_t a, const modint\
    \ &b){return modint(a) * b;}\n    friend constexpr auto operator/(int64_t a, const\
    \ modint &b){return modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream\
    \ &s, modint<M> &a){s >> a.val; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint<M> &a){s << a.val; return s;}\n\n    template <int N>\n   \
    \ static auto div(){\n      static auto value = inv(N);\n      return value;\n\
    \    }\n\n    explicit operator int32_t() const noexcept {return val;}\n    explicit\
    \ operator int64_t() const noexcept {return val;}\n  };\n}\n#line 2 \"Mylib/Combinatorics/bell_number_table.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  auto bell_number_table(int\
    \ n){\n    std::vector<std::vector<T>> ret(n + 1, std::vector<T>(n + 1));\n\n\
    \    ret[0][0] = 1;\n\n    for(int i = 1; i <= n; ++i) ret[i][1] = ret[i][i] =\
    \ 1;\n\n    for(int i = 3; i <= n; ++i){\n      for(int j = 2; j < i; ++j){\n\
    \        ret[i][j] = ret[i - 1][j - 1] + j * ret[i - 1][j];\n      }\n    }\n\n\
    \    for(int i = 0; i <= n; ++i){\n      for(int j = 1; j <= n; ++j){\n      \
    \  ret[i][j] += ret[i][j - 1];\n      }\n    }\n\n    return ret;\n  }\n}\n#line\
    \ 6 \"test/aoj/DPL_5_G/main.table.test.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ mint = hl::modint<1000000007>;\n\nint main(){\n  int N, K; std::cin >> N >>\
    \ K;\n\n  auto table = hl::bell_number_table<mint>(std::max(N, K));\n\n  std::cout\
    \ << table[N][K] << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/Mint/mint.cpp\"\n#include \"\
    Mylib/Combinatorics/bell_number_table.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ mint = hl::modint<1000000007>;\n\nint main(){\n  int N, K; std::cin >> N >>\
    \ K;\n\n  auto table = hl::bell_number_table<mint>(std::max(N, K));\n\n  std::cout\
    \ << table[N][K] << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/Combinatorics/bell_number_table.cpp
  isVerificationFile: true
  path: test/aoj/DPL_5_G/main.table.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_5_G/main.table.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_G/main.table.test.cpp
- /verify/test/aoj/DPL_5_G/main.table.test.cpp.html
title: test/aoj/DPL_5_G/main.table.test.cpp
---
