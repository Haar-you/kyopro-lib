---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/String/knuth_morris_pratt.cpp
    title: Knuth-Morris-Pratt algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B/main.kmp.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #include <iostream>\n#include <string>\n#line 3 \"Mylib/String/knuth_morris_pratt.cpp\"\
    \n#include <string_view>\n#include <vector>\n\nnamespace haar_lib {\n  class knuth_morris_pratt\
    \ {\n    int M_;\n    std::string pattern_;\n    std::vector<int> table_;\n\n\
    \  public:\n    knuth_morris_pratt() {}\n    knuth_morris_pratt(std::string p)\
    \ : M_(p.size()), pattern_(p), table_(M_ + 1) {\n      table_[0] = -1;\n     \
    \ table_[1] = 0;\n\n      pattern_.push_back('\\0');\n\n      for (int i = 2,\
    \ j = 0; i <= M_;) {\n        if (pattern_[i - 1] == pattern_[j]) {\n        \
    \  table_[i] = j + 1;\n          ++i;\n          ++j;\n        } else if (j >\
    \ 0) {\n          j = table_[j];\n        } else {\n          table_[i] = 0;\n\
    \          ++i;\n        }\n      }\n    }\n\n    std::vector<int> match(const\
    \ std::string_view &s) const {\n      std::vector<int> ret;\n      const int N\
    \ = s.size();\n\n      for (int m = 0, i = 0; m + i < N;) {\n        if (pattern_[i]\
    \ == s[m + i]) {\n          ++i;\n          if (i == M_) {\n            ret.push_back(m);\n\
    \            m += i - table_[i];\n            if (i > 0) i = table_[i];\n    \
    \      }\n        } else {\n          m += i - table_[i];\n          if (i > 0)\
    \ i = table_[i];\n        }\n      }\n\n      return ret;\n    }\n  };\n}  //\
    \ namespace haar_lib\n#line 6 \"test/aoj/ALDS1_14_B/main.kmp.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main() {\n  std::string t, p;\n  std::cin >> t >> p;\n\
    \n  auto res = hl::knuth_morris_pratt(p).match(t);\n  for (auto i : res) std::cout\
    \ << i << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/String/knuth_morris_pratt.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::string t, p;\n  std::cin\
    \ >> t >> p;\n\n  auto res = hl::knuth_morris_pratt(p).match(t);\n  for (auto\
    \ i : res) std::cout << i << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/String/knuth_morris_pratt.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B/main.kmp.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B/main.kmp.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B/main.kmp.test.cpp
- /verify/test/aoj/ALDS1_14_B/main.kmp.test.cpp.html
title: test/aoj/ALDS1_14_B/main.kmp.test.cpp
---
