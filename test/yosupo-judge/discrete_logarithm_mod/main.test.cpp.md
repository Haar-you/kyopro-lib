---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mod/mod_inv.cpp
    title: Mod inverse
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mod/mod_log.cpp
    title: Mod logarithm
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo-judge/discrete_logarithm_mod/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\
    \n#include <iostream>\n#line 2 \"Mylib/Number/Mod/mod_log.cpp\"\n#include <unordered_map>\n\
    #include <optional>\n#include <numeric>\n#include <cmath>\n#line 2 \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  constexpr int64_t mod_pow(int64_t\
    \ n, int64_t p, int64_t m){\n    int64_t ret = 1;\n    while(p > 0){\n      if(p\
    \ & 1) (ret *= n) %= m;\n      (n *= n) %= m;\n      p >>= 1;\n    }\n    return\
    \ ret;\n  }\n}\n#line 2 \"Mylib/Number/Mod/mod_inv.cpp\"\n#include <utility>\n\
    #line 4 \"Mylib/Number/Mod/mod_inv.cpp\"\n\nnamespace haar_lib {\n  int64_t mod_inv(int64_t\
    \ a, int64_t m){\n    int64_t b = m, u = 1, v = 0;\n\n    while(b){\n      int64_t\
    \ t = a / b;\n      a -= t * b; std::swap(a, b);\n      u -= t * v; std::swap(u,\
    \ v);\n    }\n\n    u %= m;\n    if(u < 0) u += m;\n\n    return u;\n  }\n}\n\
    #line 8 \"Mylib/Number/Mod/mod_log.cpp\"\n\nnamespace haar_lib {\n  std::optional<int64_t>\
    \ mod_log(int64_t a, int64_t b, int64_t m){\n    if(b == 1) return 0;\n\n    int64_t\
    \ d = 0;\n\n    while(1){\n      if(auto g = std::gcd(a, m); g != 1){\n      \
    \  if(b % g != 0) return {};\n\n        d += 1;\n        m /= g;\n        b /=\
    \ g;\n        (b *= mod_inv(a / g, m)) %= m;\n\n        if(b == 1) return d;\n\
    \      }else{\n        break;\n      }\n    }\n\n    const int64_t sq = std::sqrt(m)\
    \ + 1;\n\n    std::unordered_map<int64_t, int64_t> mp;\n    {\n      int64_t t\
    \ = 1 % m;\n\n      for(int i = 0; i < sq; ++i){\n        if(mp.find(t) == mp.end())\
    \ mp[t] = i;\n        (t *= a) %= m;\n      }\n    }\n\n    {\n      int64_t A\
    \ = mod_pow(mod_inv(a, m), sq, m);\n      int64_t t = b % m;\n\n      for(int\
    \ i = 0; i < sq; ++i){\n        if(mp.find(t) != mp.end()){\n          int64_t\
    \ ret = i * sq + mp[t] + d;\n\n          return ret;\n        }\n\n        (t\
    \ *= A) %= m;\n      }\n    }\n\n    return {};\n  }\n}\n#line 3 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <vector>\n#include <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\n\
    #include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t ... I>\n  static void input_tuple_helper(std::istream\
    \ &s, T &val, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s\
    \ >> std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n\
    \  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){\n    s >>\
    \ value.first >> value.second;\n    return s;\n  }\n\n  template <typename ...\
    \ Args>\n  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){\n\
    \    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename ... Args>\n  class InputTuples {\n    struct iter {\n\
    \      using value_type = std::tuple<Args ...>;\n      value_type value;\n   \
    \   bool fetched = false;\n      int N, c = 0;\n\n      value_type operator*(){\n\
    \        if(not fetched){\n          std::cin >> value;\n        }\n        return\
    \ value;\n      }\n\n      void operator++(){\n        ++c;\n        fetched =\
    \ false;\n      }\n\n      bool operator!=(iter &) const {\n        return c <\
    \ N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n\
    \    InputTuples(int N): N(N){}\n\n    iter begin() const {return iter(N);}\n\
    \    iter end() const {return iter(N);}\n  };\n\n  template <typename ... Args>\n\
    \  auto input_tuples(int N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line\
    \ 6 \"test/yosupo-judge/discrete_logarithm_mod/main.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int T; std::cin >> T;\n\n  for(auto [X, Y, M] : hl::input_tuples<int, int,\
    \ int>(T)){\n    std::cout << hl::mod_log(X, Y, M).value_or(-1) << \"\\n\";\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/Mod/mod_log.cpp\"\n#include \"\
    Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int T; std::cin >> T;\n\n  for(auto\
    \ [X, Y, M] : hl::input_tuples<int, int, int>(T)){\n    std::cout << hl::mod_log(X,\
    \ Y, M).value_or(-1) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Mod/mod_log.cpp
  - Mylib/Number/Mod/mod_pow.cpp
  - Mylib/Number/Mod/mod_inv.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 03:22:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
- /verify/test/yosupo-judge/discrete_logarithm_mod/main.test.cpp.html
title: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp
---
