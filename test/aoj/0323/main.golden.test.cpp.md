---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/golden_section_search_upwards.cpp
    title: Golden section search (Convex upwards)
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0323
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0323
  bundledCode: "#line 1 \"test/aoj/0323/main.golden.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0323\"\n#define ERROR\
    \ 0.001\n\n#include <iostream>\n#include <iomanip>\n#include <algorithm>\n#include\
    \ <cmath>\n#line 2 \"Mylib/Algorithm/golden_section_search_upwards.cpp\"\n#include\
    \ <functional>\n#line 4 \"Mylib/Algorithm/golden_section_search_upwards.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T = double, typename Func = std::function<T(T)>>\n\
    \  T golden_section_search_upwards(T lb, T ub, const Func &f, int LOOP_COUNT =\
    \ 100){\n    static const T phi = (1.0 + std::sqrt(5)) / 2;\n\n    T t1 = 0, t2\
    \ = 0;\n\n    while(LOOP_COUNT--){\n      t1 = (lb * phi + ub) / (phi + 1.0);\n\
    \      t2 = (lb + ub * phi) / (phi + 1.0);\n\n      if(f(t1) > f(t2)){\n     \
    \   ub = t2;\n      }else{\n        lb = t1;\n      }\n    }\n\n    return lb;\n\
    \  }\n}\n#line 3 \"Mylib/IO/input_tuple_vector.cpp\"\n#include <vector>\n#include\
    \ <tuple>\n#include <utility>\n#include <initializer_list>\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T &val,\
    \ int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 10 \"test/aoj/0323/main.golden.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n\n  auto\
    \ [x, r] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\n  std::vector<std::pair<int64_t,\
    \ int>> p;\n  for(int i = 0; i < N; ++i){\n    p.emplace_back(x[i] - r[i], -1);\n\
    \    p.emplace_back(x[i] + r[i], 1);\n  }\n\n  std::sort(p.begin(), p.end());\n\
    \n  double left = 0, right = 0;\n\n  int c = 0;\n  for(auto &a : p){\n    if(c\
    \ == N){\n      right = a.first;\n    }\n\n    c -= a.second;\n\n    if(c == N){\n\
    \      left = a.first;\n    }\n  }\n\n  auto f =\n    [&](double p){\n      double\
    \ ret = 1e9;\n\n      for(int i = 0; i < N; ++i){\n        double l = std::abs(x[i]\
    \ - p);\n        ret = std::min(ret, std::sqrt(r[i] * r[i] - l * l));\n      }\n\
    \n      return ret;\n    };\n\n  auto a = hl::golden_section_search_upwards<double>(left,\
    \ right, f);\n\n  std::cout << std::fixed << std::setprecision(12) << f(a) <<\
    \ std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0323\"\
    \n#define ERROR 0.001\n\n#include <iostream>\n#include <iomanip>\n#include <algorithm>\n\
    #include <cmath>\n#include \"Mylib/Algorithm/golden_section_search_upwards.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int N; std::cin >> N;\n\n  auto [x, r] = hl::input_tuple_vector<int64_t,\
    \ int64_t>(N);\n\n  std::vector<std::pair<int64_t, int>> p;\n  for(int i = 0;\
    \ i < N; ++i){\n    p.emplace_back(x[i] - r[i], -1);\n    p.emplace_back(x[i]\
    \ + r[i], 1);\n  }\n\n  std::sort(p.begin(), p.end());\n\n  double left = 0, right\
    \ = 0;\n\n  int c = 0;\n  for(auto &a : p){\n    if(c == N){\n      right = a.first;\n\
    \    }\n\n    c -= a.second;\n\n    if(c == N){\n      left = a.first;\n    }\n\
    \  }\n\n  auto f =\n    [&](double p){\n      double ret = 1e9;\n\n      for(int\
    \ i = 0; i < N; ++i){\n        double l = std::abs(x[i] - p);\n        ret = std::min(ret,\
    \ std::sqrt(r[i] * r[i] - l * l));\n      }\n\n      return ret;\n    };\n\n \
    \ auto a = hl::golden_section_search_upwards<double>(left, right, f);\n\n  std::cout\
    \ << std::fixed << std::setprecision(12) << f(a) << std::endl;\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/Algorithm/golden_section_search_upwards.cpp
  - Mylib/IO/input_tuple_vector.cpp
  isVerificationFile: true
  path: test/aoj/0323/main.golden.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 10:43:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/0323/main.golden.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/0323/main.golden.test.cpp
- /verify/test/aoj/0323/main.golden.test.cpp.html
title: test/aoj/0323/main.golden.test.cpp
---
