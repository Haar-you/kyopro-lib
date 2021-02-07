---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Prime/count_coprime.cpp
    title: Count coprime
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Number/Prime/count_coprime.cpp\"\n#include\
    \ <cstdint>\n#line 2 \"Mylib/Number/Prime/prime_factorize.cpp\"\n#include <vector>\n\
    #include <utility>\n#line 5 \"Mylib/Number/Prime/prime_factorize.cpp\"\n\nnamespace\
    \ haar_lib {\n  auto prime_factorize(int64_t n){\n    std::vector<std::pair<int64_t,\
    \ int64_t>> ret;\n    for(int64_t i = 2LL; i * i <= n; ++i){\n      if(n % i ==\
    \ 0){\n        int64_t c = 0;\n        while(n % i == 0){\n          n /= i;\n\
    \          ++c;\n        }\n        ret.emplace_back(i, c);\n      }\n    }\n\
    \    if(n != 1) ret.emplace_back(n, 1);\n    return ret;\n  }\n}\n#line 4 \"Mylib/Number/Prime/count_coprime.cpp\"\
    \n\nnamespace haar_lib {\n  int64_t count_coprime(int64_t n, int64_t m){\n   \
    \ const auto p = prime_factorize(m);\n    const int k = p.size();\n\n    int64_t\
    \ ret = 0;\n\n    for(int i = 0; i < 1 << k; ++i){\n      int64_t s = 1;\n\n \
    \     for(int j = 0; j < k; ++j){\n        if(i & (1 << j)) s *= p[j].first;\n\
    \      }\n\n      if(__builtin_popcount(i) % 2 == 1) ret -= n / s;\n      else\
    \ ret += n / s;\n    }\n\n    return ret;\n  }\n}\n#line 5 \"test/aoj/NTL_1_D/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n\n  std::cout\
    \ << hl::count_coprime(n, n) << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include <iostream>\n#include \"Mylib/Number/Prime/count_coprime.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n\n  std::cout\
    \ << hl::count_coprime(n, n) << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Prime/count_coprime.cpp
  - Mylib/Number/Prime/prime_factorize.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_D/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D/main.test.cpp
- /verify/test/aoj/NTL_1_D/main.test.cpp.html
title: test/aoj/NTL_1_D/main.test.cpp
---
