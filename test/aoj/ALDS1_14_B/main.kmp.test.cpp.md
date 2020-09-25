---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/String/knuth_morris_pratt.cpp
    title: Knuth-Morris-Pratt algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B/main.kmp.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #include <iostream>\n#include <string>\n#line 2 \"Mylib/String/knuth_morris_pratt.cpp\"\
    \n#include <vector>\n#line 4 \"Mylib/String/knuth_morris_pratt.cpp\"\n#include\
    \ <string_view>\n\nnamespace haar_lib {\n  struct knuth_morris_pratt {\n    int\
    \ M;\n    std::string pattern;\n    std::vector<int> table;\n\n    knuth_morris_pratt(std::string\
    \ p): M(p.size()), pattern(p), table(M + 1){\n      table[0] = -1;\n      table[1]\
    \ = 0;\n\n      pattern.push_back('\\0');\n\n      for(int i = 2, j = 0; i <=\
    \ M;){\n        if(pattern[i - 1] == pattern[j]){\n          table[i] = j + 1;\n\
    \          ++i;\n          ++j;\n        }else if(j > 0){\n          j = table[j];\n\
    \        }else{\n          table[i] = 0;\n          ++i;\n        }\n      }\n\
    \    }\n\n    std::vector<int> match(const std::string_view &s) const {\n    \
    \  std::vector<int> ret;\n      const int N = s.size();\n\n      for(int m = 0,\
    \ i = 0; m + i < N;){\n        if(pattern[i] == s[m + i]){\n          ++i;\n \
    \         if(i == M){\n            ret.push_back(m);\n            m += i - table[i];\n\
    \            if(i > 0) i = table[i];\n          }\n        }else{\n          m\
    \ += i - table[i];\n          if(i > 0) i = table[i];\n        }\n      }\n\n\
    \      return ret;\n    }\n  };\n}\n#line 6 \"test/aoj/ALDS1_14_B/main.kmp.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::string t, p; std::cin >> t\
    \ >> p;\n\n  auto res = hl::knuth_morris_pratt(p).match(t);\n  for(auto i : res)\
    \ std::cout << i << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/String/knuth_morris_pratt.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::string t, p; std::cin >> t\
    \ >> p;\n\n  auto res = hl::knuth_morris_pratt(p).match(t);\n  for(auto i : res)\
    \ std::cout << i << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/String/knuth_morris_pratt.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B/main.kmp.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B/main.kmp.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B/main.kmp.test.cpp
- /verify/test/aoj/ALDS1_14_B/main.kmp.test.cpp.html
title: test/aoj/ALDS1_14_B/main.kmp.test.cpp
---
