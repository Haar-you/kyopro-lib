---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Number/Mint/mint.cpp
    title: Modint
  - icon: ':x:'
    path: Mylib/Combinatorics/factorial_table.cpp
    title: Factorial table
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"test/yukicoder/117/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\
    \n\n#include <iostream>\n#include <string>\n#include <regex>\n#line 3 \"Mylib/Number/Mint/mint.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  template <int32_t M>\n  class\
    \ modint {\n    uint32_t val;\n\n  public:\n    constexpr static auto mod(){return\
    \ M;}\n\n    constexpr modint(): val(0){}\n    constexpr modint(int64_t n){\n\
    \      if(n >= M) val = n % M;\n      else if(n < 0) val = n % M + M;\n      else\
    \ val = n;\n    }\n\n    constexpr auto& operator=(const modint &a){val = a.val;\
    \ return *this;}\n    constexpr auto& operator+=(const modint &a){\n      if(val\
    \ + a.val >= M) val = (uint64_t)val + a.val - M;\n      else val += a.val;\n \
    \     return *this;\n    }\n    constexpr auto& operator-=(const modint &a){\n\
    \      if(val < a.val) val += M;\n      val -= a.val;\n      return *this;\n \
    \   }\n    constexpr auto& operator*=(const modint &a){\n      val = (uint64_t)val\
    \ * a.val % M;\n      return *this;\n    }\n    constexpr auto& operator/=(const\
    \ modint &a){\n      val = (uint64_t)val * a.inv().val % M;\n      return *this;\n\
    \    }\n\n    constexpr auto operator+(const modint &a) const {return modint(*this)\
    \ += a;}\n    constexpr auto operator-(const modint &a) const {return modint(*this)\
    \ -= a;}\n    constexpr auto operator*(const modint &a) const {return modint(*this)\
    \ *= a;}\n    constexpr auto operator/(const modint &a) const {return modint(*this)\
    \ /= a;}\n\n    constexpr bool operator==(const modint &a) const {return val ==\
    \ a.val;}\n    constexpr bool operator!=(const modint &a) const {return val !=\
    \ a.val;}\n\n    constexpr auto& operator++(){*this += 1; return *this;}\n   \
    \ constexpr auto& operator--(){*this -= 1; return *this;}\n\n    constexpr auto\
    \ operator++(int){auto t = *this; *this += 1; return t;}\n    constexpr auto operator--(int){auto\
    \ t = *this; *this -= 1; return t;}\n\n    constexpr static modint pow(int64_t\
    \ n, int64_t p){\n      if(p < 0) return pow(n, -p).inv();\n\n      int64_t ret\
    \ = 1, e = n % M;\n      for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e)\
    \ %= M;\n      return ret;\n    }\n\n    constexpr static modint inv(int64_t a){\n\
    \      int64_t b = M, u = 1, v = 0;\n\n      while(b){\n        int64_t t = a\
    \ / b;\n        a -= t * b; std::swap(a, b);\n        u -= t * v; std::swap(u,\
    \ v);\n      }\n\n      u %= M;\n      if(u < 0) u += M;\n\n      return u;\n\
    \    }\n\n    constexpr static auto frac(int64_t a, int64_t b){return modint(a)\
    \ / modint(b);}\n\n    constexpr auto pow(int64_t p) const {return pow(val, p);}\n\
    \    constexpr auto inv() const {return inv(val);}\n\n    friend constexpr auto\
    \ operator-(const modint &a){return modint(M - a.val);}\n\n    friend constexpr\
    \ auto operator+(int64_t a, const modint &b){return modint(a) + b;}\n    friend\
    \ constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}\n\
    \    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a)\
    \ * b;}\n    friend constexpr auto operator/(int64_t a, const modint &b){return\
    \ modint(a) / b;}\n\n    friend std::istream& operator>>(std::istream &s, modint<M>\
    \ &a){s >> a.val; return s;}\n    friend std::ostream& operator<<(std::ostream\
    \ &s, const modint<M> &a){s << a.val; return s;}\n\n    template <int N>\n   \
    \ static auto div(){\n      static auto value = inv(N);\n      return value;\n\
    \    }\n\n    explicit operator int32_t() const noexcept {return val;}\n    explicit\
    \ operator int64_t() const noexcept {return val;}\n  };\n}\n#line 2 \"Mylib/Combinatorics/factorial_table.cpp\"\
    \n#include <vector>\n#include <cassert>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class factorial_table {\n  public:\n    using\
    \ value_type = T;\n\n  private:\n    std::vector<T> f_table;\n    std::vector<T>\
    \ if_table;\n\n  public:\n    factorial_table(int N){\n      f_table.assign(N\
    \ + 1, 1);\n      if_table.assign(N + 1, 1);\n\n      for(int i = 1; i <= N; ++i){\n\
    \        f_table[i] = f_table[i - 1] * i;\n      }\n\n      if_table[N] = f_table[N].inv();\n\
    \n      for(int i = N; --i >= 0;){\n        if_table[i] = if_table[i + 1] * (i\
    \ + 1);\n      }\n    }\n\n    T factorial(int64_t i) const {\n      assert(i\
    \ < (int)f_table.size());\n      return f_table[i];\n    }\n\n    T inv_factorial(int64_t\
    \ i) const {\n      assert(i < (int)if_table.size());\n      return if_table[i];\n\
    \    }\n\n    T P(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k\
    \ < 0) return 0;\n      return factorial(n) * inv_factorial(n - k);\n    }\n\n\
    \    T C(int64_t n, int64_t k) const {\n      if(n < k or n < 0 or k < 0) return\
    \ 0;\n      return P(n, k) * inv_factorial(k);\n    }\n\n    T H(int64_t n, int64_t\
    \ k) const {\n      if(n == 0 and k == 0) return 1;\n      return C(n + k - 1,\
    \ k);\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n\
    #line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n#line 6 \"\
    Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename T, size_t\
    \ ... I>\n  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)\
    \ ...};\n  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
    \ &s, std::pair<T, U> &value){\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename ... Args>\n  std::istream& operator>>(std::istream\
    \ &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuples\
    \ {\n    struct iter {\n      using value_type = std::tuple<Args ...>;\n     \
    \ value_type value;\n      bool fetched = false;\n      int N, c = 0;\n\n    \
    \  value_type operator*(){\n        if(not fetched){\n          std::cin >> value;\n\
    \        }\n        return value;\n      }\n\n      void operator++(){\n     \
    \   ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n \
    \   int N;\n\n  public:\n    InputTuples(int N): N(N){}\n\n    iter begin() const\
    \ {return iter(N);}\n    iter end() const {return iter(N);}\n  };\n\n  template\
    \ <typename ... Args>\n  auto input_tuples(int N){\n    return InputTuples<Args\
    \ ...>(N);\n  }\n}\n#line 9 \"test/yukicoder/117/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\n\nint main(){\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  auto ft = hl::factorial_table<mint>(2000000);\n\
    \n  int T; std::cin >> T;\n\n  std::regex re(R\"((.)\\((.+),(.+)\\))\");\n\n \
    \ for(auto [s] : hl::input_tuples<std::string>(T)){\n    std::smatch m;\n    std::regex_match(s,\
    \ m, re);\n\n    char type = m[1].str()[0];\n    int N = std::stoi(m[2].str());\n\
    \    int K = std::stoi(m[3].str());\n\n    switch(type){\n    case 'C': std::cout\
    \ << ft.C(N, K) << \"\\n\"; break;\n    case 'P': std::cout << ft.P(N, K) << \"\
    \\n\"; break;\n    case 'H': std::cout << ft.H(N, K) << \"\\n\"; break;\n    }\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n\n#include <iostream>\n\
    #include <string>\n#include <regex>\n#include \"Mylib/Number/Mint/mint.cpp\"\n\
    #include \"Mylib/Combinatorics/factorial_table.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing mint = hl::modint<1000000007>;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  auto ft = hl::factorial_table<mint>(2000000);\n\
    \n  int T; std::cin >> T;\n\n  std::regex re(R\"((.)\\((.+),(.+)\\))\");\n\n \
    \ for(auto [s] : hl::input_tuples<std::string>(T)){\n    std::smatch m;\n    std::regex_match(s,\
    \ m, re);\n\n    char type = m[1].str()[0];\n    int N = std::stoi(m[2].str());\n\
    \    int K = std::stoi(m[3].str());\n\n    switch(type){\n    case 'C': std::cout\
    \ << ft.C(N, K) << \"\\n\"; break;\n    case 'P': std::cout << ft.P(N, K) << \"\
    \\n\"; break;\n    case 'H': std::cout << ft.H(N, K) << \"\\n\"; break;\n    }\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mint/mint.cpp
  - Mylib/Combinatorics/factorial_table.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/117/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-17 22:58:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/117/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/117/main.test.cpp
- /verify/test/yukicoder/117/main.test.cpp.html
title: test/yukicoder/117/main.test.cpp
---
