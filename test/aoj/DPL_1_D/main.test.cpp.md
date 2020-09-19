---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DynamicProgramming/longest_increasing_subsequence.cpp
    title: Longest increasing subsequence
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"test/aoj/DPL_1_D/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/DynamicProgramming/longest_increasing_subsequence.cpp\"\
    \n#include <algorithm>\n\nnamespace haar_lib {\n  template <typename Container,\
    \ typename T = typename Container::value_type>\n  int lis(const Container &xs){\n\
    \    std::vector<T> dp;\n    dp.reserve(xs.size());\n\n    for(auto x : xs){\n\
    \      if(dp.empty() or dp.back() < x){\n        dp.push_back(x);\n      }else{\n\
    \        dp[std::lower_bound(dp.begin(), dp.end(), x) - dp.begin()] = x;\n   \
    \   }\n    }\n\n    return dp.size();\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 7 \"test/aoj/DPL_1_D/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N; std::cin >> N;\n\n  auto a = hl::input_vector<int>(N);\n\n  auto ans\
    \ = hl::lis(a);\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/DynamicProgramming/longest_increasing_subsequence.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int N; std::cin >> N;\n\n  auto a = hl::input_vector<int>(N);\n\n  auto ans\
    \ = hl::lis(a);\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DynamicProgramming/longest_increasing_subsequence.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/DPL_1_D/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_1_D/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_D/main.test.cpp
- /verify/test/aoj/DPL_1_D/main.test.cpp.html
title: test/aoj/DPL_1_D/main.test.cpp
---
