---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':heavy_check_mark:'
    path: Mylib/Typical/knapsack_small_quantity.cpp
    title: 0-1 Knapsack problem (Small quantity)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H
  bundledCode: "#line 1 \"test/aoj/DPL_1_H/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Typical/knapsack_small_quantity.cpp\"\
    \n#include <map>\n#include <algorithm>\n#include <iterator>\n\nnamespace haar_lib\
    \ {\n  template <typename Weight, typename Value>\n  Value knapsack_small_quantity(int\
    \ N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){\n\
    \    const int p = N / 2;\n    const int q = N - p;\n\n    std::vector<std::pair<Weight,\
    \ Value>> a, b;\n    a.reserve(1 << p);\n    b.reserve(1 << q);\n\n    a.emplace_back(0,\
    \ 0);\n    b.emplace_back(0, 0);\n\n    for(int i = 0; i < p; ++i){\n      const\
    \ int k = a.size();\n      const auto begin = a.begin();\n      const auto end\
    \ = a.end();\n\n      for(auto it = begin; it != end; ++it){\n        a.emplace_back(it->first\
    \ + w[i], it->second + v[i]);\n      }\n\n      std::inplace_merge(a.begin(),\
    \ a.begin() + k, a.end());\n    }\n\n    for(int i = p; i < p + q; ++i){\n   \
    \   const int k = b.size();\n      const auto begin = b.begin();\n      const\
    \ auto end = b.end();\n\n      for(auto it = begin; it != end; ++it){\n      \
    \  b.emplace_back(it->first + w[i], it->second + v[i]);\n      }\n\n      std::inplace_merge(b.begin(),\
    \ b.begin() + k, b.end());\n    }\n\n    for(size_t i = 1; i < a.size(); ++i){\n\
    \      a[i].second = std::max(a[i].second, a[i - 1].second);\n    }\n\n    for(size_t\
    \ i = 1; i < b.size(); ++i){\n      b[i].second = std::max(b[i].second, b[i -\
    \ 1].second);\n    }\n\n    Value ret = 0;\n\n    for(int i = 0, j = (int)b.size()\
    \ - 1; i < (int)a.size(); ++i){\n      while(j >= 0 and a[i].first + b[j].first\
    \ > cap) --j;\n      if(j < 0) break;\n      ret = std::max(ret, a[i].second +\
    \ b[j].second);\n    }\n\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
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
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Typical/knapsack_small_quantity.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int N; std::cin >> N;\n  int64_t W; std::cin >> W;\n\n  auto [v,\
    \ w] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\n  auto ans = hl::knapsack_small_quantity(N,\
    \ W, w, v);\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Typical/knapsack_small_quantity.cpp
  - Mylib/IO/input_tuple_vector.cpp
  isVerificationFile: true
  path: test/aoj/DPL_1_H/main.test.cpp
  requiredBy: []
  timestamp: '2020-11-23 21:23:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_1_H/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_H/main.test.cpp
- /verify/test/aoj/DPL_1_H/main.test.cpp.html
title: test/aoj/DPL_1_H/main.test.cpp
---
