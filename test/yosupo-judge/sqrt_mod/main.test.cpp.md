---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  - icon: ':x:'
    path: Mylib/Number/Mod/mod_sqrt.cpp
    title: Mod sqrt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/yosupo-judge/sqrt_mod/main.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include <iostream>\n#line 2\
    \ \"Mylib/Number/Mod/mod_sqrt.cpp\"\n#include <random>\n#include <optional>\n\
    #line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t m){\n    int64_t\
    \ ret = 1;\n    while(p > 0){\n      if(p & 1) (ret *= n) %= m;\n      (n *= n)\
    \ %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}\n#line 5 \"Mylib/Number/Mod/mod_sqrt.cpp\"\
    \n\nnamespace haar_lib {\n  std::optional<int64_t> mod_sqrt(int64_t a, int64_t\
    \ p){\n    if(p == 2) return a % 2;\n    if(a == 0) return 0;\n\n    int64_t b\
    \ = mod_pow(a, (p - 1) / 2, p);\n\n    if(b == p - 1) return {};\n    if(p % 4\
    \ == 3) return mod_pow(a, (p + 1) / 4, p);\n\n    int64_t q = p - 1, s = 0;\n\
    \    while(q % 2 == 0){\n      q /= 2;\n      s += 1;\n    }\n\n    static std::mt19937_64\
    \ rand(time(0));\n    std::uniform_int_distribution<> dist(0, p - 1);\n\n    int64_t\
    \ z;\n    while(1){\n      z = dist(rand);\n      if(mod_pow(z, (p - 1) / 2, p)\
    \ == p - 1) break;\n    }\n\n    int64_t m = s;\n    int64_t c = mod_pow(z, q,\
    \ p);\n    int64_t t = mod_pow(a, q, p);\n    int64_t r = mod_pow(a, (q + 1) /\
    \ 2, p);\n\n    while(1){\n      if(t == 0) return 0;\n      if(t == 1) return\
    \ r;\n\n      int i = 1;\n      for(int64_t T = t; i < m; ++i){\n        (T *=\
    \ T) %= p;\n        if(T == 1) break;\n      }\n\n      int64_t b = mod_pow(c,\
    \ 1LL << (m - i - 1), p);\n\n      m = i;\n      c = b * b % p;\n      (t *= b\
    \ * b % p) %= p;\n      (r *= b) %= p;\n    }\n  }\n}\n#line 3 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <vector>\n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\
    #line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t ... I>\n  static void input_tuple_helper(std::istream &s, T &val,\
    \ std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s >>\
    \ std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n  std::istream&\
    \ operator>>(std::istream &s, std::pair<T, U> &value){\n    s >> value.first >>\
    \ value.second;\n    return s;\n  }\n\n  template <typename ... Args>\n  std::istream&\
    \ operator>>(std::istream &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s,\
    \ value, std::make_index_sequence<sizeof ... (Args)>());\n    return s;\n  }\n\
    }\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ ... Args>\n  class InputTuples {\n    struct iter {\n      using value_type\
    \ = std::tuple<Args ...>;\n      value_type value;\n      bool fetched = false;\n\
    \      int N, c = 0;\n\n      value_type operator*(){\n        if(not fetched){\n\
    \          std::cin >> value;\n        }\n        return value;\n      }\n\n \
    \     void operator++(){\n        ++c;\n        fetched = false;\n      }\n\n\
    \      bool operator!=(iter &) const {\n        return c < N;\n      }\n\n   \
    \   iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n    InputTuples(int\
    \ N): N(N){}\n\n    iter begin() const {return iter(N);}\n    iter end() const\
    \ {return iter(N);}\n  };\n\n  template <typename ... Args>\n  auto input_tuples(int\
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 6 \"test/yosupo-judge/sqrt_mod/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int T; std::cin >> T;\n  for(auto [Y, P] : hl::input_tuples<int64_t, int64_t>(T)){\n\
    \    std::cout << hl::mod_sqrt(Y, P).value_or(-1) << \"\\n\";\n  }\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ <iostream>\n#include \"Mylib/Number/Mod/mod_sqrt.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int T; std::cin >> T;\n  for(auto [Y, P] : hl::input_tuples<int64_t, int64_t>(T)){\n\
    \    std::cout << hl::mod_sqrt(Y, P).value_or(-1) << \"\\n\";\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/Number/Mod/mod_sqrt.cpp
  - Mylib/Number/Mod/mod_pow.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/sqrt_mod/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 03:22:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/sqrt_mod/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/sqrt_mod/main.test.cpp
- /verify/test/yosupo-judge/sqrt_mod/main.test.cpp.html
title: test/yosupo-judge/sqrt_mod/main.test.cpp
---
