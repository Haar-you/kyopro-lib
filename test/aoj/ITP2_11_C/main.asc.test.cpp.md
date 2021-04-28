---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Bit/enumerate_subsets_asc.cpp
    title: Enumerate subsets (Ascending order)
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_C
  bundledCode: "#line 1 \"test/aoj/ITP2_11_C/main.asc.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_C\"\n\n#include\
    \ <iostream>\n#include <map>\n#include <vector>\n#line 2 \"Mylib/Bit/enumerate_subsets_asc.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Func>\n  void enumerate_subsets_asc(int\
    \ a, const Func &f) {\n    for (int t = 0;; t = (t - a) & a) {\n      if (not\
    \ f(t)) break;\n      if (t == a) break;\n    }\n  }\n}  // namespace haar_lib\n\
    #line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  std::vector<T> input_vector(int N) {\n    std::vector<T> ret(N);\n   \
    \ for (int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n  template\
    \ <typename T>\n  std::vector<std::vector<T>> input_vector(int N, int M) {\n \
    \   std::vector<std::vector<T>> ret(N);\n    for (int i = 0; i < N; ++i) ret[i]\
    \ = input_vector<T>(M);\n    return ret;\n  }\n}  // namespace haar_lib\n#line\
    \ 8 \"test/aoj/ITP2_11_C/main.asc.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint\
    \ main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int n,\
    \ k;\n  std::cin >> n >> k;\n\n  int t = 0;\n  for (auto b : hl::input_vector<int>(k))\
    \ {\n    t |= 1 << b;\n  }\n\n  std::map<int, std::vector<int>> ans;\n  hl::enumerate_subsets_asc(\n\
    \      t,\n      [&](int d) {\n        ans[d];\n        for (int i = 0; i < n;\
    \ ++i) {\n          if (d & (1 << i)) ans[d].push_back(i);\n        }\n      \
    \  return true;\n      });\n\n  for (auto& [m, v] : ans) {\n    std::cout << m\
    \ << \":\";\n    for (auto x : v) std::cout << \" \" << x;\n    std::cout << \"\
    \\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_C\"\
    \n\n#include <iostream>\n#include <map>\n#include <vector>\n#include \"Mylib/Bit/enumerate_subsets_asc.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int n, k;\n\
    \  std::cin >> n >> k;\n\n  int t = 0;\n  for (auto b : hl::input_vector<int>(k))\
    \ {\n    t |= 1 << b;\n  }\n\n  std::map<int, std::vector<int>> ans;\n  hl::enumerate_subsets_asc(\n\
    \      t,\n      [&](int d) {\n        ans[d];\n        for (int i = 0; i < n;\
    \ ++i) {\n          if (d & (1 << i)) ans[d].push_back(i);\n        }\n      \
    \  return true;\n      });\n\n  for (auto& [m, v] : ans) {\n    std::cout << m\
    \ << \":\";\n    for (auto x : v) std::cout << \" \" << x;\n    std::cout << \"\
    \\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Bit/enumerate_subsets_asc.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/ITP2_11_C/main.asc.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ITP2_11_C/main.asc.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP2_11_C/main.asc.test.cpp
- /verify/test/aoj/ITP2_11_C/main.asc.test.cpp.html
title: test/aoj/ITP2_11_C/main.asc.test.cpp
---
