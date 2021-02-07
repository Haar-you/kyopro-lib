---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/ternary_search_downwards.cpp
    title: Ternary search (Convex downwards)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: https://yukicoder.me/problems/no/306
    links:
    - https://yukicoder.me/problems/no/306
  bundledCode: "#line 1 \"test/yukicoder/306/main.ternary.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/306\"\n#define ERROR 1e-6\n\n#include <iostream>\n\
    #include <iomanip>\n#include <cmath>\n#line 2 \"Mylib/Algorithm/ternary_search_downwards.cpp\"\
    \n#include <functional>\n\nnamespace haar_lib {\n  template <typename T = double,\
    \ typename Func = std::function<T(T)>>\n  T ternary_search_downwards(T lb, T ub,\
    \ const Func &f, int LOOP_COUNT = 100){\n    T t1 = 0, t2 = 0;\n\n    while(LOOP_COUNT--){\n\
    \      t1 = lb + (ub - lb) / 3;\n      t2 = lb + (ub - lb) / 3 * 2;\n\n      if(f(t1)\
    \ < f(t2)){\n        ub = t2;\n      }else{\n        lb = t1;\n      }\n    }\n\
    \n    return lb;\n  }\n}\n#line 8 \"test/yukicoder/306/main.ternary.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int xa, xb, ya, yb; std::cin >>\
    \ xa >> ya >> xb >> yb;\n\n  auto f =\n    [&](long double p){\n      return std::hypot(xa,\
    \ ya - p) + std::hypot(xb, yb - p);\n    };\n\n  auto ans = hl::ternary_search_downwards<long\
    \ double>(-1000, 1000, f);\n\n  std::cout << std::fixed << std::setprecision(12)\
    \ << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/306\"\n#define ERROR 1e-6\n\
    \n#include <iostream>\n#include <iomanip>\n#include <cmath>\n#include \"Mylib/Algorithm/ternary_search_downwards.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int xa, xb, ya, yb; std::cin >>\
    \ xa >> ya >> xb >> yb;\n\n  auto f =\n    [&](long double p){\n      return std::hypot(xa,\
    \ ya - p) + std::hypot(xb, yb - p);\n    };\n\n  auto ans = hl::ternary_search_downwards<long\
    \ double>(-1000, 1000, f);\n\n  std::cout << std::fixed << std::setprecision(12)\
    \ << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Algorithm/ternary_search_downwards.cpp
  isVerificationFile: true
  path: test/yukicoder/306/main.ternary.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 10:43:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/306/main.ternary.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/306/main.ternary.test.cpp
- /verify/test/yukicoder/306/main.ternary.test.cpp.html
title: test/yukicoder/306/main.ternary.test.cpp
---
