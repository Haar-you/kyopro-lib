---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/Totient/totient.cpp
    title: Euler's totient function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D/main.totient.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\n\n#include\
    \ <iostream>\n#line 2 \"Mylib/Number/Totient/totient.cpp\"\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  constexpr int64_t totient(int64_t n) {\n    int64_t\
    \ ret = n;\n\n    for (int64_t i = 2; i * i <= n; ++i) {\n      if (n % i == 0)\
    \ {\n        ret -= ret / i;\n        while (n % i == 0) n /= i;\n      }\n  \
    \  }\n\n    if (n != 1) ret -= ret / n;\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n#line 5 \"test/aoj/NTL_1_D/main.totient.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main() {\n  int n;\n  std::cin >> n;\n\n  std::cout << hl::totient(n)\
    \ << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/Totient/totient.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main() {\n  int n;\n  std::cin >> n;\n\n  std::cout <<\
    \ hl::totient(n) << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Totient/totient.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_D/main.totient.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D/main.totient.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D/main.totient.test.cpp
- /verify/test/aoj/NTL_1_D/main.totient.test.cpp.html
title: test/aoj/NTL_1_D/main.totient.test.cpp
---
