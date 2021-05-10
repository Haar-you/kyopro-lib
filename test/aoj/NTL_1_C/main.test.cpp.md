---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':x:'
    path: Mylib/Number/binary_gcd.cpp
    title: Binary GCD
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
  bundledCode: "#line 1 \"test/aoj/NTL_1_C/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \n\n#include <iostream>\n#include <vector>\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N) {\n    std::vector<T> ret(N);\n    for (int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M) {\n    std::vector<std::vector<T>> ret(N);\n    for\
    \ (int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n\
    }  // namespace haar_lib\n#line 2 \"Mylib/Number/binary_gcd.cpp\"\n#include <cmath>\n\
    #include <utility>\n\nnamespace haar_lib {\n  int64_t binary_gcd(int64_t a, int64_t\
    \ b) {\n    int64_t g = 1;\n\n    while (1) {\n      if (a > b) std::swap(a, b);\n\
    \n      if (a == 0) {\n        break;\n      } else {\n        if ((a & 1) ==\
    \ 0 and (b & 1) == 0) {\n          a >>= 1;\n          b >>= 1;\n          g <<=\
    \ 1;\n        } else if ((a & 1) == 0) {\n          a >>= 1;\n        } else if\
    \ ((b & 1) == 0) {\n          b >>= 1;\n        } else {\n          int64_t t\
    \ = std::abs(a - b) >> 1;\n          b         = t;\n        }\n      }\n    }\n\
    \n    return g * b;\n  }\n}  // namespace haar_lib\n#line 7 \"test/aoj/NTL_1_C/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int n;\n  std::cin >> n;\n\n \
    \ auto a = hl::input_vector<int>(n);\n\n  int l = 1;\n  for (auto x : a) {\n \
    \   l = l / hl::binary_gcd(l, x) * x;\n  }\n\n  std::cout << l << \"\\n\";\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/IO/input_vector.cpp\"\
    \n#include \"Mylib/Number/binary_gcd.cpp\"\n\nnamespace hl = haar_lib;\n\nint\
    \ main() {\n  int n;\n  std::cin >> n;\n\n  auto a = hl::input_vector<int>(n);\n\
    \n  int l = 1;\n  for (auto x : a) {\n    l = l / hl::binary_gcd(l, x) * x;\n\
    \  }\n\n  std::cout << l << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/Number/binary_gcd.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_C/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_C/main.test.cpp
- /verify/test/aoj/NTL_1_C/main.test.cpp.html
title: test/aoj/NTL_1_C/main.test.cpp
---