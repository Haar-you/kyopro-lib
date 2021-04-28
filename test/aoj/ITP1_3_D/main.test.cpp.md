---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/Divisor/enumerate_divisors.cpp
    title: Enumerate divisors
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
  bundledCode: "#line 1 \"test/aoj/ITP1_3_D/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Number/Divisor/enumerate_divisors.cpp\"\
    \n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib {\n  std::vector<int64_t>\
    \ enumerate_divisors(int64_t n) {\n    std::vector<int64_t> temp, ret;\n\n   \
    \ {\n      int64_t i;\n      for (i = 1LL; i * i < n; ++i) {\n        if (n %\
    \ i == 0) {\n          temp.push_back(n / i);\n          ret.push_back(i);\n \
    \       }\n      }\n      if (i * i == n) ret.push_back(i);\n    }\n\n    std::reverse(temp.begin(),\
    \ temp.end());\n    ret.insert(ret.end(), temp.begin(), temp.end());\n\n    return\
    \ ret;\n  }\n}  // namespace haar_lib\n#line 5 \"test/aoj/ITP1_3_D/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int a, b, c;\n  std::cin >> a\
    \ >> b >> c;\n\n  int ans = 0;\n\n  for (auto d : hl::enumerate_divisors(c)) {\n\
    \    if (a <= d and d <= b) ++ans;\n  }\n\n  std::cout << ans << std::endl;\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/Divisor/enumerate_divisors.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int a, b, c;\n  std::cin >> a\
    \ >> b >> c;\n\n  int ans = 0;\n\n  for (auto d : hl::enumerate_divisors(c)) {\n\
    \    if (a <= d and d <= b) ++ans;\n  }\n\n  std::cout << ans << std::endl;\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Divisor/enumerate_divisors.cpp
  isVerificationFile: true
  path: test/aoj/ITP1_3_D/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ITP1_3_D/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_3_D/main.test.cpp
- /verify/test/aoj/ITP1_3_D/main.test.cpp.html
title: test/aoj/ITP1_3_D/main.test.cpp
---
