---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Prime/is_prime.cpp
    title: Primality test (Trial division)
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_1_C/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Number/Prime/is_prime.cpp\"\n\nnamespace\
    \ haar_lib {\n  bool is_prime(int n){\n    if(n <= 1) return false;\n    for(int\
    \ i = 2; i * i <= n; ++i){\n      if(n % i == 0) return false;\n    }\n    return\
    \ true;\n  }\n}\n#line 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n#include\
    \ <tuple>\n#include <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 6 \"test/aoj/ALDS1_1_C/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n\n  int ans = 0;\n\n\
    \  for(auto [x] : hl::input_tuples<int>(N)) if(hl::is_prime(x)) ++ans;\n\n  std::cout\
    \ << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/Prime/is_prime.cpp\"\n#include\
    \ \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n \
    \ int N; std::cin >> N;\n\n  int ans = 0;\n\n  for(auto [x] : hl::input_tuples<int>(N))\
    \ if(hl::is_prime(x)) ++ans;\n\n  std::cout << ans << std::endl;\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/Number/Prime/is_prime.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_1_C/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_1_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_1_C/main.test.cpp
- /verify/test/aoj/ALDS1_1_C/main.test.cpp.html
title: test/aoj/ALDS1_1_C/main.test.cpp
---
