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
    path: Mylib/Math/sum_of_floor_of_linear.cpp
    title: Sum of floor of linear
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\
    \n#include <iostream>\n#line 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n\
    #include <tuple>\n#include <utility>\n#include <initializer_list>\n#line 6 \"\
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
    \ ...>(N);\n  }\n}\n#line 2 \"Mylib/Math/sum_of_floor_of_linear.cpp\"\n#include\
    \ <cstdint>\n\nnamespace haar_lib {\n  int64_t sum_of_floor_of_linear(int64_t\
    \ N, int64_t M, int64_t A, int64_t B){\n    int64_t ret = 0;\n\n    if(B >= M){\n\
    \      ret += N * (B / M);\n      B %= M;\n    }\n\n    if(A >= M){\n      ret\
    \ += N * (N - 1) * (A / M) / 2;\n      A %= M;\n    }\n\n    int64_t y_max = (A\
    \ * N + B) / M;\n    int64_t x_max = y_max * M - B;\n    if(y_max == 0) return\
    \ ret;\n\n    ret += (N - (x_max + A - 1) / A) * y_max;\n    ret += sum_of_floor_of_linear(y_max,\
    \ A, M, (A - x_max % A) % A);\n    return ret;\n  }\n}\n#line 6 \"test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int T; std::cin >> T;\n\n  for(auto [N, M, A, B] : hl::input_tuples<int64_t,\
    \ int64_t, int64_t, int64_t>(T)){\n    std::cout << hl::sum_of_floor_of_linear(N,\
    \ M, A, B) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <iostream>\n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/Math/sum_of_floor_of_linear.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int T; std::cin >> T;\n\n  for(auto [N, M, A, B] : hl::input_tuples<int64_t,\
    \ int64_t, int64_t, int64_t>(T)){\n    std::cout << hl::sum_of_floor_of_linear(N,\
    \ M, A, B) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/Math/sum_of_floor_of_linear.cpp
  isVerificationFile: true
  path: test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-27 07:43:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp
- /verify/test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp.html
title: test/yosupo-judge/sum_of_floor_of_linear/main.test.cpp
---
