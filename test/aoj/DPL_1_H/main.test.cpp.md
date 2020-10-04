---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':x:'
    path: Mylib/Typical/KnapsackProblem/knapsack_small_quantity.cpp
    title: 0-1 Knapsack problem (Small quantity)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H
  bundledCode: "#line 1 \"test/aoj/DPL_1_H/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Typical/KnapsackProblem/knapsack_small_quantity.cpp\"\
    \n#include <map>\n#include <algorithm>\n#include <iterator>\n\nnamespace haar_lib\
    \ {\n  template <typename Weight, typename Value>\n  Value knapsack_small_quantity(int\
    \ N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){\n\
    \    Value ret = 0;\n\n    const int p = N / 2;\n    const int q = N - p;\n\n\
    \    std::map<Weight, Value> a;\n    for(int i = 0; i < 1 << p; ++i){\n      Weight\
    \ weight = 0;\n      Value value = 0;\n      for(int j = 0; j < p; ++j){\n   \
    \     if(i & (1 << j)){\n          weight += w[j];\n          value += v[j];\n\
    \        }\n      }\n\n      a[weight] = std::max(a[weight], value);\n    }\n\n\
    \    Value m = 0;\n    for(auto &kv : a){\n      kv.second = std::max(kv.second,\
    \ m);\n      m = kv.second;\n    }\n\n    for(int i = 0; i < 1 << q; ++i){\n \
    \     Weight weight = 0;\n      Value value = 0;\n      for(int j = 0; j < q;\
    \ ++j){\n        if(i & (1 << j)){\n          weight += w[j + p];\n          value\
    \ += v[j + p];\n        }\n      }\n\n      auto itr = a.upper_bound(std::max((Weight)0,\
    \ cap - weight));\n\n      itr = std::prev(itr);\n      if(weight + itr->first\
    \ <= cap) ret = std::max(ret, value + itr->second);\n    }\n\n    return ret;\n\
    \  }\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\n#include <tuple>\n#include\
    \ <utility>\n#include <initializer_list>\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t ... I>\n  void input_tuple_vector_init(T &val, int N, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 7 \"test/aoj/DPL_1_H/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n  int64_t\
    \ W; std::cin >> W;\n\n  auto [v, w] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\
    \n  auto ans = hl::knapsack_small_quantity(N, W, w, v);\n\n  std::cout << ans\
    \ << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Typical/KnapsackProblem/knapsack_small_quantity.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int N; std::cin >> N;\n  int64_t W; std::cin >> W;\n\n  auto [v,\
    \ w] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\n  auto ans = hl::knapsack_small_quantity(N,\
    \ W, w, v);\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Typical/KnapsackProblem/knapsack_small_quantity.cpp
  - Mylib/IO/input_tuple_vector.cpp
  isVerificationFile: true
  path: test/aoj/DPL_1_H/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-21 02:36:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_1_H/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_H/main.test.cpp
- /verify/test/aoj/DPL_1_H/main.test.cpp.html
title: test/aoj/DPL_1_H/main.test.cpp
---
