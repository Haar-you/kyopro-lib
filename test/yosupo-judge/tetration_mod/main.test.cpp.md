---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Totient/totient.cpp
    title: Euler's totient function
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/tetration.cpp
    title: Tetration
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tetration_mod
    links:
    - https://judge.yosupo.jp/problem/tetration_mod
  bundledCode: "#line 1 \"test/yosupo-judge/tetration_mod/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\n\n#include <iostream>\n\
    #line 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n#include <tuple>\n#include\
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
    \ ...>(N);\n  }\n}\n#line 2 \"Mylib/Number/Totient/totient.cpp\"\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  int64_t totient(int64_t n){\n    int64_t ret = n;\n\n\
    \    for(int64_t i = 2; i * i <= n; ++i){\n      if(n % i == 0){\n        ret\
    \ -= ret / i;\n        while(n % i == 0) n /= i;\n      }\n    }\n\n    if(n !=\
    \ 1) ret -= ret / n;\n\n    return ret;\n  }\n}\n#line 3 \"Mylib/Number/tetration.cpp\"\
    \n\nnamespace haar_lib {\n  namespace tetration_impl {\n    int rec(int64_t a,\
    \ int64_t b, int64_t m){\n      if(b == 1) return a % m;\n      if(b == 0) return\
    \ 1 % m;\n      if(b == 2){\n        bool c = a >= m;\n        int64_t ret = 1;\n\
    \        int64_t p = a;\n        a %= m;\n\n        while(p > 0){\n          if(p\
    \ & 1) if((ret *= a) >= m) ret %= m, c = true;\n          if((a *= a) >= m) a\
    \ %= m, c = true;\n          p >>= 1;\n        }\n\n        if(c) ret += m;\n\
    \        return ret;\n      }\n      if(a == 0) return b % 2 == 1 ? 0 : 1;\n \
    \     if(m == 1) return 1;\n\n      int phi = totient(m);\n      int p = rec(a,\
    \ b - 1, phi);\n\n      bool c = p >= phi;\n      int64_t ret = 1;\n\n      while(p\
    \ > 0){\n        if(p & 1) if((ret *= a) >= m) ret %= m, c = true;\n        if((a\
    \ *= a) >= m) a %= m, c = true;\n        p >>= 1;\n      }\n\n      if(c) ret\
    \ += m;\n      return ret;\n    }\n  }\n\n  int tetration(int64_t a, int64_t b,\
    \ int64_t m){\n    return tetration_impl::rec(a, b, m) % m;\n  }\n}\n#line 6 \"\
    test/yosupo-judge/tetration_mod/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int T; std::cin >> T;\n\n  for(auto [A, B, M] : hl::input_tuples<int,\
    \ int, int>(T)){\n    auto ans = hl::tetration(A, B, M);\n    std::cout << ans\
    \ << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tetration_mod\"\n\n#include\
    \ <iostream>\n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/Number/tetration.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int T; std::cin >> T;\n\n  for(auto\
    \ [A, B, M] : hl::input_tuples<int, int, int>(T)){\n    auto ans = hl::tetration(A,\
    \ B, M);\n    std::cout << ans << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/Number/tetration.cpp
  - Mylib/Number/Totient/totient.cpp
  isVerificationFile: true
  path: test/yosupo-judge/tetration_mod/main.test.cpp
  requiredBy: []
  timestamp: '2020-11-01 20:53:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/tetration_mod/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/tetration_mod/main.test.cpp
- /verify/test/yosupo-judge/tetration_mod/main.test.cpp.html
title: test/yosupo-judge/tetration_mod/main.test.cpp
---
