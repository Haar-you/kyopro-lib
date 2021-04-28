---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/extended_gcd.cpp
    title: Extended Euclidean algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/aoj/NTL_1_E/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Number/extended_gcd.cpp\"\n#include <tuple>\n\
    \nnamespace haar_lib {\n  auto ext_gcd(int64_t a, int64_t b) -> std::tuple<\n\
    \      int64_t,  // gcd\n      int64_t,  // p\n      int64_t   // q\n      > {\n\
    \    if (b == 0) return std::make_tuple(a, 1, 0);\n    const auto [d, q, p] =\
    \ ext_gcd(b, (a + b) % b);\n    return std::make_tuple(d, p, q - a / b * p);\n\
    \  }\n}  // namespace haar_lib\n#line 5 \"test/aoj/NTL_1_E/main.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main() {\n  int a, b;\n  std::cin >> a >> b;\n\
    \n  int x, y;\n  std::tie(std::ignore, x, y) = hl::ext_gcd(a, b);\n\n  std::cout\
    \ << x << \" \" << y << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/extended_gcd.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main() {\n  int a, b;\n  std::cin >> a >> b;\n\n  int\
    \ x, y;\n  std::tie(std::ignore, x, y) = hl::ext_gcd(a, b);\n\n  std::cout <<\
    \ x << \" \" << y << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/extended_gcd.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_E/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_E/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_E/main.test.cpp
- /verify/test/aoj/NTL_1_E/main.test.cpp.html
title: test/aoj/NTL_1_E/main.test.cpp
---
