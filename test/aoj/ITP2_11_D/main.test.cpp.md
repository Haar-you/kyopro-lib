---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Bit/enumerate_sets_of_size_k.cpp
    title: Enumerate sets of size k
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D
  bundledCode: "#line 1 \"test/aoj/ITP2_11_D/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D\"\
    \n\n#include <iostream>\n#include <vector>\n#include <map>\n#line 2 \"Mylib/Bit/enumerate_sets_of_size_k.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Func>\n  void enumerate_sets_of_size_k(int\
    \ k, int n, const Func &f){\n    int c = (1 << k) - 1;\n    while(c < (1 << n)){\n\
    \      if(not f(c)) break;\n      const int x = c & (-c);\n      const int y =\
    \ c + x;\n      c = ((c & (~y)) / x >> 1) | y;\n    }\n  }\n}\n#line 7 \"test/aoj/ITP2_11_D/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n, k; std::cin >> n >> k;\n\n  std::map<int, std::vector<int>> ans;\n\n\
    \  hl::enumerate_sets_of_size_k(\n    k, n,\n    [&](int d){\n      for(int i\
    \ = 0; i < n; ++i){\n        if(d & (1 << i)) ans[d].push_back(i);\n      }\n\
    \      return true;\n    }\n  );\n\n  for(auto &[m, v] : ans){\n    std::cout\
    \ << m << \":\";\n    for(auto x : v) std::cout << \" \" << x;\n    std::cout\
    \ << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_D\"\
    \n\n#include <iostream>\n#include <vector>\n#include <map>\n#include \"Mylib/Bit/enumerate_sets_of_size_k.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n, k; std::cin >> n >> k;\n\n  std::map<int, std::vector<int>> ans;\n\n\
    \  hl::enumerate_sets_of_size_k(\n    k, n,\n    [&](int d){\n      for(int i\
    \ = 0; i < n; ++i){\n        if(d & (1 << i)) ans[d].push_back(i);\n      }\n\
    \      return true;\n    }\n  );\n\n  for(auto &[m, v] : ans){\n    std::cout\
    \ << m << \":\";\n    for(auto x : v) std::cout << \" \" << x;\n    std::cout\
    \ << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Bit/enumerate_sets_of_size_k.cpp
  isVerificationFile: true
  path: test/aoj/ITP2_11_D/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP2_11_D/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP2_11_D/main.test.cpp
- /verify/test/aoj/ITP2_11_D/main.test.cpp.html
title: test/aoj/ITP2_11_D/main.test.cpp
---
