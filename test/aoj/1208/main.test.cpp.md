---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Number/Rational/stern_brocot_tree.cpp
    title: Stern-Brocot tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208
  bundledCode: "#line 1 \"test/aoj/1208/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208\"\
    \n\n#include <iostream>\n#include <utility>\n#line 2 \"Mylib/Number/Rational/stern_brocot_tree.cpp\"\
    \n#include <cstdint>\n#line 4 \"Mylib/Number/Rational/stern_brocot_tree.cpp\"\n\
    \nnamespace haar_lib {\n  template <typename Checker>\n  void stern_brocot_tree(\n\
    \      const Checker &check,\n      int n,\n      std::pair<int, int> &lower,\n\
    \      std::pair<int, int> &upper,\n      int64_t pl = 0, int64_t ql = 1, int64_t\
    \ pr = 1, int64_t qr = 0) {\n    int64_t pm = pl + pr;\n    int64_t qm = ql +\
    \ qr;\n\n    if (pm > n or qm > n) return;\n\n    auto t = check(pm, qm);\n\n\
    \    if (t < 0) {\n      lower = {pm, qm};\n      stern_brocot_tree(check, n,\
    \ lower, upper, pm, qm, pr, qr);\n    } else if (t > 0) {\n      upper = {pm,\
    \ qm};\n      stern_brocot_tree(check, n, lower, upper, pl, ql, pm, qm);\n   \
    \ } else {\n      lower = {pm, qm};\n      upper = {pm, qm};\n    }\n  }\n}  //\
    \ namespace haar_lib\n#line 6 \"test/aoj/1208/main.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int p, n;\n  while (std::cin >> p >> n, p) {\n    std::pair<int, int> lower,\
    \ upper;\n    hl::stern_brocot_tree(\n        [p](int64_t pm, int64_t qm) {\n\
    \          auto a = pm * pm;\n          auto b = p * qm * qm;\n          if (a\
    \ < b) return -1;\n          if (a > b) return 1;\n          return 0;\n     \
    \   },\n        n, lower, upper);\n    std::cout << upper.first << \"/\" << upper.second\
    \ << \" \"\n              << lower.first << \"/\" << lower.second << \"\\n\";\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208\"\
    \n\n#include <iostream>\n#include <utility>\n#include \"Mylib/Number/Rational/stern_brocot_tree.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int p, n;\n  while (std::cin >> p >> n, p) {\n    std::pair<int, int> lower,\
    \ upper;\n    hl::stern_brocot_tree(\n        [p](int64_t pm, int64_t qm) {\n\
    \          auto a = pm * pm;\n          auto b = p * qm * qm;\n          if (a\
    \ < b) return -1;\n          if (a > b) return 1;\n          return 0;\n     \
    \   },\n        n, lower, upper);\n    std::cout << upper.first << \"/\" << upper.second\
    \ << \" \"\n              << lower.first << \"/\" << lower.second << \"\\n\";\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Number/Rational/stern_brocot_tree.cpp
  isVerificationFile: true
  path: test/aoj/1208/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1208/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1208/main.test.cpp
- /verify/test/aoj/1208/main.test.cpp.html
title: test/aoj/1208/main.test.cpp
---
