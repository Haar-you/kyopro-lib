---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Prime/prime_factorize.cpp
    title: Prime factorization
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/aoj/NTL_1_A/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Number/Prime/prime_factorize.cpp\"\n\
    #include <vector>\n#include <utility>\n#include <cstdint>\n\nnamespace haar_lib\
    \ {\n  auto prime_factorize(int64_t n) -> std::vector<std::pair<int64_t, int64_t>>\
    \ {\n    std::vector<std::pair<int64_t, int64_t>> ret;\n    for(int64_t i = 2LL;\
    \ i * i <= n; ++i){\n      if(n % i == 0){\n        int64_t c = 0;\n        while(n\
    \ % i == 0){\n          n /= i;\n          ++c;\n        }\n        ret.emplace_back(i,\
    \ c);\n      }\n    }\n    if(n != 1) ret.emplace_back(n, 1);\n    return ret;\n\
    \  }\n}\n#line 5 \"test/aoj/NTL_1_A/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int n; std::cin >> n;\n\n  auto res = hl::prime_factorize(n);\n\
    \n  std::cout << n << \":\";\n\n  for(auto &[x, c] : res){\n    for(int i = 0;\
    \ i < c; ++i){\n      std::cout << \" \" << x;\n    }\n  }\n\n  std::cout << std::endl;\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/Prime/prime_factorize.cpp\"\n\
    \nnamespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n\n  auto res\
    \ = hl::prime_factorize(n);\n\n  std::cout << n << \":\";\n\n  for(auto &[x, c]\
    \ : res){\n    for(int i = 0; i < c; ++i){\n      std::cout << \" \" << x;\n \
    \   }\n  }\n\n  std::cout << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Prime/prime_factorize.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_A/main.test.cpp
  requiredBy: []
  timestamp: '2021-03-13 04:56:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_A/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_A/main.test.cpp
- /verify/test/aoj/NTL_1_A/main.test.cpp.html
title: test/aoj/NTL_1_A/main.test.cpp
---
