---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/binary_gcd.cpp
    title: Binary GCD
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
  bundledCode: "#line 1 \"test/aoj/NTL_1_C/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \n\n#include <iostream>\n#include <vector>\n#line 2 \"Mylib/Number/binary_gcd.cpp\"\
    \n#include <utility>\n#include <cmath>\n\nnamespace haar_lib {\n  int64_t binary_gcd(int64_t\
    \ a, int64_t b){\n    int64_t g = 1;\n\n    while(1){\n      if(a > b) std::swap(a,\
    \ b);\n\n      if(a == 0){\n        break;\n      }else{\n        if((a & 1) ==\
    \ 0 and (b & 1) == 0){\n          a >>= 1;\n          b >>= 1;\n          g <<=\
    \ 1;\n        }else if((a & 1) == 0){\n          a >>= 1;\n        }else if((b\
    \ & 1) == 0){\n          b >>= 1;\n        }else{\n          int64_t t = std::abs(a\
    \ - b) >> 1;\n          b = t;\n        }\n      }\n    }\n\n    return g * b;\n\
    \  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T> ret(N);\n\
    \    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n\
    \  template <typename T>\n  std::vector<std::vector<T>> input_vector(int N, int\
    \ M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i < N; ++i)\
    \ ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 7 \"test/aoj/NTL_1_C/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n; std::cin >> n;\n\n  auto\
    \ a = hl::input_vector<int>(n);\n\n  int l = 1;\n  for(auto x : a){\n    l = l\
    \ / hl::binary_gcd(l, x) * x;\n  }\n\n  std::cout << l << \"\\n\";\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Number/binary_gcd.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int n; std::cin >> n;\n\n  auto a = hl::input_vector<int>(n);\n\n  int l =\
    \ 1;\n  for(auto x : a){\n    l = l / hl::binary_gcd(l, x) * x;\n  }\n\n  std::cout\
    \ << l << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/binary_gcd.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_C/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_C/main.test.cpp
- /verify/test/aoj/NTL_1_C/main.test.cpp.html
title: test/aoj/NTL_1_C/main.test.cpp
---
