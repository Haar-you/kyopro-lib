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
    path: Mylib/Misc/int128.cpp
    title: 128-bit int
  - icon: ':question:'
    path: Mylib/Number/Prime/miller_rabin.cpp
    title: Primality test (Miller-Rabin algorithm)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/3030
    links:
    - https://yukicoder.me/problems/no/3030
  bundledCode: "#line 1 \"test/yukicoder/3030/main.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/3030\"\n\n#include <iostream>\n#line 2 \"Mylib/Number/Prime/miller_rabin.cpp\"\
    \n#include <cstdint>\n#include <initializer_list>\n#line 2 \"Mylib/Misc/int128.cpp\"\
    \n\nnamespace haar_lib {\n#ifdef __SIZEOF_INT128__\n  using uint128_t = __uint128_t;\n\
    \  using int128_t = __int128_t;\n#else\n#include <boost/multiprecision/cpp_int.hpp>\n\
    \  using uint128_t = boost::multiprecision::uint128_t;\n  using int128_t = boost::multiprecision::int128_t;\n\
    #endif\n}\n#line 5 \"Mylib/Number/Prime/miller_rabin.cpp\"\n\nnamespace haar_lib\
    \ {\n  namespace miller_rabin_impl {\n    uint128_t power(uint128_t a, uint128_t\
    \ b, uint128_t p){\n      uint128_t ret = 1;\n\n      while(b > 0){\n        if(b\
    \ & 1) ret = ret * a % p;\n        a = a * a % p;\n        b >>= 1;\n      }\n\
    \n      return ret;\n    }\n\n    bool is_composite(uint64_t a, uint64_t p, int\
    \ s, uint64_t d){\n      uint128_t x = power(a, d, p);\n\n      if(x == 1) return\
    \ false;\n\n      for(int i = 0; i < s; ++i){\n        if(x == p - 1) return false;\n\
    \        x = x * x % p;\n      }\n\n      return true;\n    }\n  }\n\n  bool miller_rabin(uint64_t\
    \ n){\n    if(n <= 1) return false;\n    if(n == 2) return true;\n    if(n % 2\
    \ == 0) return false;\n\n    int s = 0;\n    uint64_t d = n - 1;\n    while((d\
    \ & 1) == 0){\n      s += 1;\n      d >>= 1;\n    }\n\n    if(n < 4759123141){\n\
    \      for(uint64_t x : {2, 7, 61}){\n        if(x < n and miller_rabin_impl::is_composite(x,\
    \ n, s, d)) return false;\n      }\n\n      return true;\n    }\n\n    for(uint64_t\
    \ x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){\n      if(x < n and miller_rabin_impl::is_composite(x,\
    \ n, s, d)) return false;\n    }\n\n    return true;\n  }\n}\n#line 3 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <vector>\n#include <tuple>\n#include <utility>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 6 \"test/yukicoder/3030/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  for(auto [x] : hl::input_tuples<int64_t>(N)){\n\
    \    std::cout << x << \" \" << hl::miller_rabin(x) << \"\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/3030\"\n\n#include <iostream>\n\
    #include \"Mylib/Number/Prime/miller_rabin.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  for(auto [x] : hl::input_tuples<int64_t>(N)){\n\
    \    std::cout << x << \" \" << hl::miller_rabin(x) << \"\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/Number/Prime/miller_rabin.cpp
  - Mylib/Misc/int128.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/3030/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/3030/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/3030/main.test.cpp
- /verify/test/yukicoder/3030/main.test.cpp.html
title: test/yukicoder/3030/main.test.cpp
---
