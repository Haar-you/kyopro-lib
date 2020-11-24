---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':heavy_check_mark:'
    path: Mylib/Typical/knapsack_limited.cpp
    title: Knapsack problem (With quantity limitations)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G
  bundledCode: "#line 1 \"test/aoj/DPL_1_G/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Typical/knapsack_limited.cpp\"\
    \n#include <algorithm>\n\nnamespace haar_lib {\n  template <typename Weight, typename\
    \ Value>\n  Value knapsack_limited(int N, Weight cap, const std::vector<Weight>\
    \ &w, const std::vector<Value> &v, const std::vector<int> &m){\n    std::vector<Value>\
    \ dp(cap + 1);\n\n    for(int i = 0; i < N; ++i){\n      for(int64_t a = 1, x\
    \ = m[i], k; k = std::min(x, a), x > 0; x -= k, a *= 2){\n        for(int j =\
    \ cap; j >= 0; --j){\n          if(j - k * w[i] >= 0){\n            dp[j] = std::max(dp[j],\
    \ dp[j - k * w[i]] + (Weight)k * v[i]);\n          }\n        }\n      }\n   \
    \ }\n\n    return dp[cap];\n  }\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 7 \"test/aoj/DPL_1_G/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N, W; std::cin >> N >> W;\n\
    \n  auto [v, w, m] = hl::input_tuple_vector<int, int, int>(N);\n\n  auto ans =\
    \ hl::knapsack_limited(N, W, w, v, m);\n  std::cout << ans << std::endl;\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Typical/knapsack_limited.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int N, W; std::cin >> N >> W;\n\n  auto [v, w, m] = hl::input_tuple_vector<int,\
    \ int, int>(N);\n\n  auto ans = hl::knapsack_limited(N, W, w, v, m);\n  std::cout\
    \ << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Typical/knapsack_limited.cpp
  - Mylib/IO/input_tuple_vector.cpp
  isVerificationFile: true
  path: test/aoj/DPL_1_G/main.test.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_1_G/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_G/main.test.cpp
- /verify/test/aoj/DPL_1_G/main.test.cpp.html
title: test/aoj/DPL_1_G/main.test.cpp
---
