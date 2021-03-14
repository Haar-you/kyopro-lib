---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':heavy_check_mark:'
    path: Mylib/String/manacher.cpp
    title: Manacher algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n\
    #include <iostream>\n#include <string>\n#line 2 \"Mylib/String/manacher.cpp\"\n\
    #include <vector>\n#include <optional>\n\nnamespace haar_lib {\n  template <typename\
    \ Container>\n  std::vector<int> manacher(const Container &s){\n    const int\
    \ n = s.size();\n    std::vector<int> ret(n);\n    int center = 0;\n\n    for(int\
    \ cur = 0; cur < n; ++cur){\n      int left = center - (cur - center);\n\n   \
    \   if(left >= 0 and cur + ret[left] < center + ret[center]){\n        ret[cur]\
    \ = ret[left];\n      }else{\n        int len = center + ret[center] - cur;\n\
    \        while(cur - len >= 0 and cur + len < n and s[cur - len] == s[cur + len])\
    \ ++len;\n        ret[cur] = len;\n        center = cur;\n      }\n    }\n\n \
    \   return ret;\n  }\n\n  template <typename Container>\n  std::vector<int> manacher_all(const\
    \ Container &s){\n    using T = typename Container::value_type;\n    const int\
    \ N = s.size();\n    std::vector<int> ret(2 * N - 1);\n\n    {\n      auto res\
    \ = manacher(s);\n      for(int i = 0; i < N; ++i){\n        ret[i * 2] = res[i]\
    \ * 2 - 1;\n      }\n    }\n\n    {\n      std::vector<std::optional<T>> T;\n\
    \      for(int i = 0; i < N; ++i){\n        if(i) T.push_back(std::nullopt);\n\
    \        T.push_back(s[i]);\n      }\n\n      auto res = manacher(T);\n      for(int\
    \ i = 0; i < N - 1; ++i){\n        ret[i * 2 + 1] = (res[i * 2 + 1] / 2) * 2;\n\
    \      }\n    }\n\n    return ret;\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\n#include\
    \ <sstream>\n#line 5 \"Mylib/IO/join.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename Iter>\n  std::string join(Iter first, Iter last, std::string delim\
    \ = \" \"){\n    std::stringstream s;\n\n    for(auto it = first; it != last;\
    \ ++it){\n      if(it != first) s << delim;\n      s << *it;\n    }\n\n    return\
    \ s.str();\n  }\n}\n#line 7 \"test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  std::string S; std::cin >> S;\n\n  auto ans = hl::manacher_all(S);\n  std::cout\
    \ << hl::join(ans.begin(), ans.end()) << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/String/manacher.cpp\"\
    \n#include \"Mylib/IO/join.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  std::string S; std::cin\
    \ >> S;\n\n  auto ans = hl::manacher_all(S);\n  std::cout << hl::join(ans.begin(),\
    \ ans.end()) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/String/manacher.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp
  requiredBy: []
  timestamp: '2020-11-30 03:27:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp
- /verify/test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp.html
title: test/yosupo-judge/enumerate_palindromes/main.manacher.test.cpp
---
