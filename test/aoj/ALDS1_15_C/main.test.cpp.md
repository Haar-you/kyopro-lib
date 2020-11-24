---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':heavy_check_mark:'
    path: Mylib/Typical/interval_scheduling.cpp
    title: Interval scheduling problem
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_15_C/main.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 3 \"Mylib/Typical/interval_scheduling.cpp\"\
    \n#include <numeric>\n#include <algorithm>\n#include <limits>\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  std::vector<std::pair<T, T>>\
    \ interval_scheduling(const std::vector<T> &l, const std::vector<T> &r){\n   \
    \ const int N = l.size();\n    std::vector<std::pair<T, T>> ret;\n    std::vector<int>\
    \ ord(N);\n    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(),\
    \ ord.end(), [&](int i, int j){return r[i] < r[j];});\n\n    auto b = std::numeric_limits<T>::lowest();\n\
    \n    for(int i : ord){\n      if(l[i] >= b){\n        ret.emplace_back(l[i],\
    \ r[i]);\n        b = r[i];\n      }\n    }\n\n    return ret;\n  }\n}\n#line\
    \ 4 \"Mylib/IO/input_tuple_vector.cpp\"\n#include <tuple>\n#line 6 \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include <initializer_list>\n\nnamespace haar_lib {\n  template <typename T,\
    \ size_t ... I>\n  void input_tuple_vector_init(T &val, int N, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 7 \"test/aoj/ALDS1_15_C/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n\n  auto\
    \ [left, right] = hl::input_tuple_vector<int, int>(n);\n  for(auto &x : right)\
    \ x += 1;\n\n  auto ans = hl::interval_scheduling(left, right);\n\n  std::cout\
    \ << ans.size() << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_C\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Typical/interval_scheduling.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int n; std::cin >> n;\n\n  auto [left, right] = hl::input_tuple_vector<int,\
    \ int>(n);\n  for(auto &x : right) x += 1;\n\n  auto ans = hl::interval_scheduling(left,\
    \ right);\n\n  std::cout << ans.size() << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Typical/interval_scheduling.cpp
  - Mylib/IO/input_tuple_vector.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_15_C/main.test.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_15_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_15_C/main.test.cpp
- /verify/test/aoj/ALDS1_15_C/main.test.cpp.html
title: test/aoj/ALDS1_15_C/main.test.cpp
---
