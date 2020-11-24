---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':heavy_check_mark:'
    path: Mylib/Typical/knapsack_small_value.cpp
    title: 0-1 Knapsack problem (Small value)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F
  bundledCode: "#line 1 \"test/aoj/DPL_1_F/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Typical/knapsack_small_value.cpp\"\
    \n#include <algorithm>\n#include <numeric>\n#include <climits>\n\nnamespace haar_lib\
    \ {\n  template <typename Weight, typename Value>\n  Value knapsack_small_value(int\
    \ N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){\n\
    \    const Value MAX_V = std::accumulate(v.begin(), v.end(), 0);\n    std::vector<std::vector<Value>>\
    \ dp(N + 1, std::vector<Value>(MAX_V + 1, LLONG_MAX));\n\n    dp[0][0] = 0;\n\n\
    \    for(int i = 0; i < N; ++i){\n      for(int j = 0; j <= MAX_V; ++j){\n   \
    \     dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);\n        if(j + v[i] <=\
    \ MAX_V and dp[i][j] < LLONG_MAX){\n          dp[i + 1][j + v[i]] = std::min(dp[i\
    \ + 1][j + v[i]], dp[i][j] + w[i]);\n        }\n      }\n    }\n\n    Value ret\
    \ = 0;\n\n    for(int i = 0; i <= MAX_V; ++i){\n      if(dp[N][i] <= cap) ret\
    \ = i;\n    }\n\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 7 \"test/aoj/DPL_1_F/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n  int64_t\
    \ W; std::cin >> W;\n\n  auto [v, w] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\
    \n  auto ans = hl::knapsack_small_value(N, W, w, v);\n\n  std::cout << ans <<\
    \ std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Typical/knapsack_small_value.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int N; std::cin >> N;\n  int64_t W; std::cin >> W;\n\n  auto [v,\
    \ w] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\n  auto ans = hl::knapsack_small_value(N,\
    \ W, w, v);\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Typical/knapsack_small_value.cpp
  - Mylib/IO/input_tuple_vector.cpp
  isVerificationFile: true
  path: test/aoj/DPL_1_F/main.test.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_1_F/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_F/main.test.cpp
- /verify/test/aoj/DPL_1_F/main.test.cpp.html
title: test/aoj/DPL_1_F/main.test.cpp
---
