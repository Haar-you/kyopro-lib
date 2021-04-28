---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':x:'
    path: Mylib/Typical/knapsack_small_weight.cpp
    title: 0-1 Knapsack problem (Small weight)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B
  bundledCode: "#line 1 \"test/aoj/DPL_1_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include <initializer_list>\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\n#include\
    \ <tuple>\n#include <utility>\n#line 7 \"Mylib/IO/input_tuple_vector.cpp\"\n\n\
    namespace haar_lib {\n  template <typename T, size_t... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0)...};\n  }\n\n  template <typename T, size_t... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0)...};\n  }\n\n  template <typename... Args>\n  auto\
    \ input_tuple_vector(int N) {\n    std::tuple<std::vector<Args>...> ret;\n\n \
    \   input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());\n\
    \    for (int i = 0; i < N; ++i) {\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());\n\
    \    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n#line 2 \"Mylib/Typical/knapsack_small_weight.cpp\"\
    \n#include <algorithm>\n#line 4 \"Mylib/Typical/knapsack_small_weight.cpp\"\n\n\
    namespace haar_lib {\n  template <typename Weight, typename Value>\n  Value knapsack_small_weight(int\
    \ N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v) {\n\
    \    std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(cap + 1));\n\
    \n    for (int i = 0; i < N; ++i) {\n      for (int j = 0; j <= cap; ++j) {\n\
    \        dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);\n        if (j + w[i]\
    \ <= cap) dp[i + 1][j + w[i]] = std::max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);\n\
    \      }\n    }\n\n    return dp[N][cap];\n  }\n}  // namespace haar_lib\n#line\
    \ 7 \"test/aoj/DPL_1_B/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main()\
    \ {\n  int N, W;\n  std::cin >> N >> W;\n\n  auto [v, w] = hl::input_tuple_vector<int,\
    \ int>(N);\n\n  auto ans = hl::knapsack_small_weight(N, W, w, v);\n  std::cout\
    \ << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include \"Mylib/Typical/knapsack_small_weight.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main() {\n  int N, W;\n  std::cin >> N >> W;\n\n  auto [v, w] = hl::input_tuple_vector<int,\
    \ int>(N);\n\n  auto ans = hl::knapsack_small_weight(N, W, w, v);\n  std::cout\
    \ << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/Typical/knapsack_small_weight.cpp
  isVerificationFile: true
  path: test/aoj/DPL_1_B/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_1_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_B/main.test.cpp
- /verify/test/aoj/DPL_1_B/main.test.cpp.html
title: test/aoj/DPL_1_B/main.test.cpp
---
