---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/String/longest_common_subsequence.cpp
    title: Longest common subsequence
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_10_C/main.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\n\n#include\
    \ <iostream>\n#include <string>\n#line 2 \"Mylib/String/longest_common_subsequence.cpp\"\
    \n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib {\n  template\
    \ <typename Container>\n  int lcs(const Container &a, const Container &b){\n \
    \   const int n = a.size(), m = b.size();\n\n    std::vector<std::vector<int>>\
    \ dp(n + 1, std::vector<int>(m + 1, 0));\n    for(int i = 1; i <= n; ++i){\n \
    \     for(int j = 1; j <= m; ++j){\n        dp[i][j] = a[i - 1] == b[j - 1] ?\
    \ dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]);\n      }\n    }\n\
    \n    return dp[n][m];\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include\
    \ <tuple>\n#include <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){\n \
    \   (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
    \ &s, std::pair<T, U> &value){\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename ... Args>\n  std::istream& operator>>(std::istream\
    \ &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuples\
    \ {\n    struct iter {\n      using value_type = std::tuple<Args ...>;\n     \
    \ value_type value;\n      bool fetched = false;\n      int N, c = 0;\n\n    \
    \  value_type operator*(){\n        if(not fetched){\n          std::cin >> value;\n\
    \        }\n        return value;\n      }\n\n      void operator++(){\n     \
    \   ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n \
    \   int N;\n\n  public:\n    InputTuples(int N): N(N){}\n\n    iter begin() const\
    \ {return iter(N);}\n    iter end() const {return iter(N);}\n  };\n\n  template\
    \ <typename ... Args>\n  auto input_tuples(int N){\n    return InputTuples<Args\
    \ ...>(N);\n  }\n}\n#line 7 \"test/aoj/ALDS1_10_C/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  int q; std::cin >> q;\n\n  for(auto [x, y]\
    \ : hl::input_tuples<std::string, std::string>(q)){\n    std::cout << hl::lcs(x,\
    \ y) << std::endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/String/longest_common_subsequence.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int q; std::cin >> q;\n\n  for(auto [x, y] : hl::input_tuples<std::string,\
    \ std::string>(q)){\n    std::cout << hl::lcs(x, y) << std::endl;\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/String/longest_common_subsequence.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_10_C/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_10_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_10_C/main.test.cpp
- /verify/test/aoj/ALDS1_10_C/main.test.cpp.html
title: test/aoj/ALDS1_10_C/main.test.cpp
---
