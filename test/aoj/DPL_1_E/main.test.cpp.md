---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/String/levenshtein_distance.cpp
    title: Levenshtein distance / Edit distance
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
  bundledCode: "#line 1 \"test/aoj/DPL_1_E/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \n\n#include <iostream>\n#include <string>\n#line 2 \"Mylib/String/levenshtein_distance.cpp\"\
    \n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib {\n  template\
    \ <typename Container>\n  int levenshtein_distance(const Container &a, const Container\
    \ &b) {\n    const int n = a.size(), m = b.size();\n    std::vector<std::vector<int>>\
    \ dp(n + 1, std::vector<int>(m + 1, 0));\n\n    for (int i = 0; i <= n; ++i) dp[i][0]\
    \ = i;\n    for (int i = 0; i <= m; ++i) dp[0][i] = i;\n\n    for (int i = 0;\
    \ i < n; ++i) {\n      for (int j = 0; j < m; ++j) {\n        dp[i + 1][j + 1]\
    \ = std::min(dp[i][j + 1] + 1, dp[i + 1][j] + 1);\n\n        if (a[i] == b[j])\
    \ {\n          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);\n    \
    \    } else {\n          dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]\
    \ + 1);\n        }\n      }\n    }\n    return dp[n][m];\n  }\n}  // namespace\
    \ haar_lib\n#line 6 \"test/aoj/DPL_1_E/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main() {\n  std::string s1, s2;\n  std::cin >> s1 >> s2;\n\n  auto ans =\
    \ hl::levenshtein_distance(s1, s2);\n\n  std::cout << ans << std::endl;\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/String/levenshtein_distance.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::string s1, s2;\n  std::cin\
    \ >> s1 >> s2;\n\n  auto ans = hl::levenshtein_distance(s1, s2);\n\n  std::cout\
    \ << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/String/levenshtein_distance.cpp
  isVerificationFile: true
  path: test/aoj/DPL_1_E/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_1_E/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_E/main.test.cpp
- /verify/test/aoj/DPL_1_E/main.test.cpp.html
title: test/aoj/DPL_1_E/main.test.cpp
---
