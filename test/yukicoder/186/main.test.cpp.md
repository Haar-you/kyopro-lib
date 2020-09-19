---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/chinese_remainder_algorithm.cpp
    title: Chinese remainder theorem
  - icon: ':x:'
    path: Mylib/Number/extended_gcd.cpp
    title: Extended Euclidean algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/447
    links:
    - https://yukicoder.me/problems/447
  bundledCode: "#line 1 \"test/yukicoder/186/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/447\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Number/chinese_remainder_algorithm.cpp\"\
    \n#include <vector>\n#include <tuple>\n#line 3 \"Mylib/Number/extended_gcd.cpp\"\
    \n\nnamespace haar_lib {\n  std::tuple<int64_t, int64_t, int64_t> ext_gcd(int64_t\
    \ a, int64_t b){\n    if(b == 0) return std::make_tuple(a, 1, 0);\n    int64_t\
    \ d, p, q;\n    std::tie(d, q, p) = ext_gcd(b, (a + b) % b);\n    return std::make_tuple(d,\
    \ p, q - a / b * p);\n  }\n}\n#line 5 \"Mylib/Number/chinese_remainder_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  bool chinese_remainder_algorithm(int64_t b1, int64_t\
    \ m1, int64_t b2, int64_t m2, int64_t &r, int64_t &m){\n    int64_t p, q, d;\n\
    \    std::tie(d, p, q) = ext_gcd(m1, m2);\n    if((b2 - b1) % d != 0) return false;\n\
    \    m = m1 * m2 / d;\n    int64_t t = ((b2 - b1) * p / d) % (m2 / d);\n    r\
    \ = (b1 + m1 * t + m) % m;\n    return true;\n  }\n\n  bool chinese_remainder_algorithm(const\
    \ std::vector<int64_t> &bs, const std::vector<int64_t> &ms, int64_t &r, int64_t\
    \ &m){\n    int64_t R = 0, M = 1;\n    for(int i = 0; i < (int)bs.size(); ++i){\n\
    \      if(not chinese_remainder_algorithm(R, M, bs[i], ms[i], r, m)) return false;\n\
    \      R = r;\n      M = m;\n    }\n    return true;\n  }\n}\n#line 5 \"test/yukicoder/186/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int64_t x1, y1, x2, y2, x3, y3;\
    \ std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;\n\n  int64_t m, r;\n\n  if(hl::chinese_remainder_algorithm({x1,\
    \ x2, x3}, {y1, y2, y3}, r, m)){\n    std::cout << (r == 0 ? m : r) << std::endl;\n\
    \  }else{\n    std::cout << -1 << std::endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/447\"\n\n#include <iostream>\n\
    #include \"Mylib/Number/chinese_remainder_algorithm.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  int64_t x1, y1, x2, y2, x3, y3; std::cin >> x1 >> y1 >> x2 >>\
    \ y2 >> x3 >> y3;\n\n  int64_t m, r;\n\n  if(hl::chinese_remainder_algorithm({x1,\
    \ x2, x3}, {y1, y2, y3}, r, m)){\n    std::cout << (r == 0 ? m : r) << std::endl;\n\
    \  }else{\n    std::cout << -1 << std::endl;\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/chinese_remainder_algorithm.cpp
  - Mylib/Number/extended_gcd.cpp
  isVerificationFile: true
  path: test/yukicoder/186/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/186/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/186/main.test.cpp
- /verify/test/yukicoder/186/main.test.cpp.html
title: test/yukicoder/186/main.test.cpp
---
