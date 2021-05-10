---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Algorithm/sliding_minimum.cpp
    title: Sliding window minimum
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"Mylib/Algorithm/sliding_minimum.cpp\"\
    \n#include <deque>\n#line 4 \"Mylib/Algorithm/sliding_minimum.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> sliding_minimum(const\
    \ std::vector<T> &a, int k) {\n    const int n = a.size();\n    std::deque<int>\
    \ dq;\n    std::vector<T> ret;\n\n    for (int i = 0; i < k; ++i) {\n      while\
    \ (not dq.empty() and a[dq.back()] >= a[i]) {\n        dq.pop_back();\n      }\n\
    \n      dq.push_back(i);\n    }\n\n    for (int i = 0; i < n - k + 1; ++i) {\n\
    \      while (dq.front() < i) {\n        dq.pop_front();\n      }\n\n      ret.push_back(a[dq.front()]);\n\
    \n      while (not dq.empty() and i + k < n and a[dq.back()] >= a[i + k]) {\n\
    \        dq.pop_back();\n      }\n\n      dq.push_back(i + k);\n    }\n\n    return\
    \ ret;\n  }\n}  // namespace haar_lib\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N) {\n    std::vector<T> ret(N);\n    for (int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for\
    \ (int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n\
    #include <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string\
    \ join(Iter first, Iter last, std::string delim = \" \") {\n    std::stringstream\
    \ s;\n\n    for (auto it = first; it != last; ++it) {\n      if (it != first)\
    \ s << delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}  // namespace\
    \ haar_lib\n#line 8 \"test/aoj/DSL_3_D/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main() {\n  int N, L;\n  std::cin >> N >> L;\n\n  auto a = hl::input_vector<int>(N);\n\
    \n  auto ans = hl::sliding_minimum(a, L);\n\n  std::cout << hl::join(ans.begin(),\
    \ ans.end()) << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Algorithm/sliding_minimum.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/join.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main() {\n  int N, L;\n  std::cin >> N >> L;\n\n  auto\
    \ a = hl::input_vector<int>(N);\n\n  auto ans = hl::sliding_minimum(a, L);\n\n\
    \  std::cout << hl::join(ans.begin(), ans.end()) << std::endl;\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/Algorithm/sliding_minimum.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D/main.test.cpp
- /verify/test/aoj/DSL_3_D/main.test.cpp.html
title: test/aoj/DSL_3_D/main.test.cpp
---