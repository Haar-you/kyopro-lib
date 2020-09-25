---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/euler_totient_function.cpp
    title: Euler's totient function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D/main.totient.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\n\n#include\
    \ <iostream>\n#line 2 \"Mylib/Number/euler_totient_function.cpp\"\n#include <cstdint>\n\
    \nnamespace haar_lib {\n  int64_t totient(int64_t n){\n    int64_t ret = n;\n\n\
    \    for(int64_t i = 2; i * i <= n; ++i){\n      if(n % i == 0){\n        ret\
    \ -= ret / i;\n        while(n % i == 0) n /= i;\n      }\n    }\n\n    if(n !=\
    \ 1) ret -= ret / n;\n\n    return ret;\n  }\n}\n#line 5 \"test/aoj/NTL_1_D/main.totient.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n\n  std::cout\
    \ << hl::totient(n) << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/euler_totient_function.cpp\"\n\
    \nnamespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n\n  std::cout\
    \ << hl::totient(n) << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/euler_totient_function.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_D/main.totient.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 05:28:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D/main.totient.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D/main.totient.test.cpp
- /verify/test/aoj/NTL_1_D/main.totient.test.cpp.html
title: test/aoj/NTL_1_D/main.totient.test.cpp
---
