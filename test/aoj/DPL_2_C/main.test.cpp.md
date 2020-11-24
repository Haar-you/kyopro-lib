---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DynamicProgramming/bitonic_tour.cpp
    title: Bitonic tour
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.0001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C
  bundledCode: "#line 1 \"test/aoj/DPL_2_C/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C\"\
    \n#define ERROR 0.0001\n\n#include <iostream>\n#include <vector>\n#include <iomanip>\n\
    #line 3 \"Mylib/DynamicProgramming/bitonic_tour.cpp\"\n#include <limits>\n#include\
    \ <algorithm>\n#include <cmath>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  double bitonic_tour(int n, const std::vector<T> &x, const std::vector<T>\
    \ &y){\n    std::vector<std::vector<double>> dist(n, std::vector<double>(n));\n\
    \    for(int i = 0; i < n; ++i){\n      for(int j = 0; j < n; ++j){\n        double\
    \ dx = x[i] - x[j];\n        double dy = y[i] - y[j];\n        dist[i][j] = std::sqrt(dx\
    \ * dx + dy * dy);\n      }\n    }\n\n    std::vector<std::vector<double>> dp(n,\
    \ std::vector<double>(n, std::numeric_limits<double>::max()));\n\n    dp[0][0]\
    \ = 0;\n\n    for(int i = 0; i < n; ++i){\n      for(int j = 0; j < n; ++j){\n\
    \        dp[i][i] = std::min(dp[i][i], dp[i][j] + dist[i][j]);\n        if(i +\
    \ 1 < n){\n          dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + dist[i][i\
    \ + 1]);\n          dp[i][i + 1] = std::min(dp[i][i + 1], dp[i][j] + dist[j][i\
    \ + 1]);\n        }\n        if(j + 1 < n){\n          dp[i][j + 1] = std::min(dp[i][j\
    \ + 1], dp[i][j] + dist[j][j + 1]);\n          dp[j + 1][j] = std::min(dp[j +\
    \ 1][j], dp[i][j] + dist[i][j + 1]);\n        }\n      }\n    }\n\n    return\
    \ dp[n - 1][n - 1];\n  }\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\n#include\
    \ <tuple>\n#include <utility>\n#include <initializer_list>\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T &val,\
    \ int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 9 \"test/aoj/DPL_2_C/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n; std::cin >> n;\n\n  auto [x, y] = hl::input_tuple_vector<int, int>(n);\n\
    \n  std::cout << std::fixed << std::setprecision(12) << hl::bitonic_tour(n, x,\
    \ y) << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_C\"\
    \n#define ERROR 0.0001\n\n#include <iostream>\n#include <vector>\n#include <iomanip>\n\
    #include \"Mylib/DynamicProgramming/bitonic_tour.cpp\"\n#include \"Mylib/IO/input_tuple_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n; std::cin >> n;\n\n  auto [x, y] = hl::input_tuple_vector<int, int>(n);\n\
    \n  std::cout << std::fixed << std::setprecision(12) << hl::bitonic_tour(n, x,\
    \ y) << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DynamicProgramming/bitonic_tour.cpp
  - Mylib/IO/input_tuple_vector.cpp
  isVerificationFile: true
  path: test/aoj/DPL_2_C/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_2_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_2_C/main.test.cpp
- /verify/test/aoj/DPL_2_C/main.test.cpp.html
title: test/aoj/DPL_2_C/main.test.cpp
---
