---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':x:'
    path: Mylib/String/z_algorithm.cpp
    title: Z-algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo-judge/zalgorithm/main.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <iostream>\n#include\
    \ <string>\n#line 3 \"Mylib/IO/join.cpp\"\n#include <sstream>\n#line 5 \"Mylib/IO/join.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter\
    \ first, Iter last, std::string delim = \" \") {\n    std::stringstream s;\n\n\
    \    for (auto it = first; it != last; ++it) {\n      if (it != first) s << delim;\n\
    \      s << *it;\n    }\n\n    return s.str();\n  }\n}  // namespace haar_lib\n\
    #line 2 \"Mylib/String/z_algorithm.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename Container>\n  std::vector<int> z_algorithm(const\
    \ Container &s) {\n    const int n = s.size();\n    std::vector<int> ret(n, 0);\n\
    \    int j = 0;\n\n    for (int i = 1; i < n; ++i) {\n      if (i + ret[i - j]\
    \ < j + ret[j]) {\n        ret[i] = ret[i - j];\n      } else {\n        int k\
    \ = std::max<int>(0, j + ret[j] - i);\n        while (i + k < n and s[k] == s[i\
    \ + k]) ++k;\n        ret[i] = k;\n        j      = i;\n      }\n    }\n\n   \
    \ ret[0] = n;\n\n    return ret;\n  }\n}  // namespace haar_lib\n#line 7 \"test/yosupo-judge/zalgorithm/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::string s;\n  std::cin >>\
    \ s;\n\n  auto ans = hl::z_algorithm(s);\n  std::cout << hl::join(ans.begin(),\
    \ ans.end()) << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <iostream>\n#include <string>\n#include \"Mylib/IO/join.cpp\"\n#include \"Mylib/String/z_algorithm.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::string s;\n  std::cin >>\
    \ s;\n\n  auto ans = hl::z_algorithm(s);\n  std::cout << hl::join(ans.begin(),\
    \ ans.end()) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/join.cpp
  - Mylib/String/z_algorithm.cpp
  isVerificationFile: true
  path: test/yosupo-judge/zalgorithm/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/zalgorithm/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/zalgorithm/main.test.cpp
- /verify/test/yosupo-judge/zalgorithm/main.test.cpp.html
title: test/yosupo-judge/zalgorithm/main.test.cpp
---
