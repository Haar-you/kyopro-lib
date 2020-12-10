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
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':heavy_check_mark:'
    path: Mylib/Misc/int128.cpp
    title: 128-bit int
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Prime/miller_rabin.cpp
    title: Primality test (Miller-Rabin algorithm)
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Prime/pollard_rho.cpp
    title: Prime factorization (Pollard's rho algorithm)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo-judge/factorize/main.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/factorize\"\n\n#include <iostream>\n#line\
    \ 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n#include <tuple>\n#include\
    \ <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){\n \
    \   (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
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
    \ ...>(N);\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#include\
    \ <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string\
    \ join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n#line 2 \"Mylib/Number/Prime/pollard_rho.cpp\"\
    \n#include <optional>\n#line 5 \"Mylib/Number/Prime/pollard_rho.cpp\"\n#include\
    \ <numeric>\n#include <algorithm>\n#include <cassert>\n#line 2 \"Mylib/Misc/int128.cpp\"\
    \n\nnamespace haar_lib {\n#ifdef __SIZEOF_INT128__\n  using uint128_t = __uint128_t;\n\
    \  using int128_t = __int128_t;\n#else\n#include <boost/multiprecision/cpp_int.hpp>\n\
    \  using uint128_t = boost::multiprecision::uint128_t;\n  using int128_t = boost::multiprecision::int128_t;\n\
    #endif\n}\n#line 2 \"Mylib/Number/Prime/miller_rabin.cpp\"\n#include <cstdint>\n\
    #line 5 \"Mylib/Number/Prime/miller_rabin.cpp\"\n\nnamespace haar_lib {\n  namespace\
    \ miller_rabin_impl {\n    uint128_t power(uint128_t a, uint128_t b, uint128_t\
    \ p){\n      uint128_t ret = 1;\n\n      while(b > 0){\n        if(b & 1) ret\
    \ = ret * a % p;\n        a = a * a % p;\n        b >>= 1;\n      }\n\n      return\
    \ ret;\n    }\n\n    bool is_composite(uint64_t a, uint64_t p, int s, uint64_t\
    \ d){\n      uint128_t x = power(a, d, p);\n\n      if(x == 1) return false;\n\
    \n      for(int i = 0; i < s; ++i){\n        if(x == p - 1) return false;\n  \
    \      x = x * x % p;\n      }\n\n      return true;\n    }\n  }\n\n  bool miller_rabin(uint64_t\
    \ n){\n    if(n <= 1) return false;\n    if(n == 2) return true;\n    if(n % 2\
    \ == 0) return false;\n\n    int s = 0;\n    uint64_t d = n - 1;\n    while((d\
    \ & 1) == 0){\n      s += 1;\n      d >>= 1;\n    }\n\n    if(n < 4759123141){\n\
    \      for(uint64_t x : {2, 7, 61}){\n        if(x < n and miller_rabin_impl::is_composite(x,\
    \ n, s, d)) return false;\n      }\n\n      return true;\n    }\n\n    for(uint64_t\
    \ x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){\n      if(x < n and miller_rabin_impl::is_composite(x,\
    \ n, s, d)) return false;\n    }\n\n    return true;\n  }\n}\n#line 10 \"Mylib/Number/Prime/pollard_rho.cpp\"\
    \n\nnamespace haar_lib {\n  namespace pollard_rho_impl {\n    int128_t f(int128_t\
    \ x){\n      return x * x + 1;\n    }\n\n    std::optional<int64_t> rho(int64_t\
    \ n){\n      int64_t x = 2, y = 2, d = 1;\n\n      while(d == 1){\n        x =\
    \ f(x) % n;\n        y = f(f(y) % n) % n;\n        d = std::gcd(std::abs(x - y),\
    \ n);\n        if(d == n) return {};\n      }\n\n      return {d};\n    }\n  }\n\
    \n  auto pollard_rho(int64_t n){\n    std::vector<std::pair<int64_t, int64_t>>\
    \ ret;\n\n    for(int i = 2; i <= 1000000; ++i){\n      if(n % i == 0){\n    \
    \    int c = 0;\n        while(n % i == 0){\n          n /= i;\n          ++c;\n\
    \        }\n        ret.emplace_back(i, c);\n      }\n      if(i > n) break;\n\
    \    }\n\n    while(n > 1){\n      if(miller_rabin(n)){\n        ret.emplace_back(n,\
    \ 1);\n        break;\n      }\n\n      auto res = pollard_rho_impl::rho(n);\n\
    \      if(not res){\n        assert(false);\n      }\n\n      auto r = *res;\n\
    \      if(r == 1) break;\n\n      int c = 0;\n      while(n % r == 0){\n     \
    \   n /= r;\n        ++c;\n      }\n\n      ret.emplace_back(r, c);\n    }\n\n\
    \    std::sort(ret.begin(), ret.end());\n\n    return ret;\n  }\n}\n#line 7 \"\
    test/yosupo-judge/factorize/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint\
    \ main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int Q;\
    \ std::cin >> Q;\n\n  for(auto [a] : hl::input_tuples<int64_t>(Q)){\n    auto\
    \ res = hl::pollard_rho(a);\n\n    std::vector<int64_t> ans;\n    for(auto [x,\
    \ k] : res){\n      while(k--) ans.push_back(x);\n    }\n\n    std::cout << ans.size()\
    \ << \" \" << hl::join(ans.begin(), ans.end()) << \"\\n\";\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ <iostream>\n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/IO/join.cpp\"\
    \n#include \"Mylib/Number/Prime/pollard_rho.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ Q; std::cin >> Q;\n\n  for(auto [a] : hl::input_tuples<int64_t>(Q)){\n    auto\
    \ res = hl::pollard_rho(a);\n\n    std::vector<int64_t> ans;\n    for(auto [x,\
    \ k] : res){\n      while(k--) ans.push_back(x);\n    }\n\n    std::cout << ans.size()\
    \ << \" \" << hl::join(ans.begin(), ans.end()) << \"\\n\";\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/join.cpp
  - Mylib/Number/Prime/pollard_rho.cpp
  - Mylib/Misc/int128.cpp
  - Mylib/Number/Prime/miller_rabin.cpp
  isVerificationFile: true
  path: test/yosupo-judge/factorize/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/factorize/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/factorize/main.test.cpp
- /verify/test/yosupo-judge/factorize/main.test.cpp.html
title: test/yosupo-judge/factorize/main.test.cpp
---
