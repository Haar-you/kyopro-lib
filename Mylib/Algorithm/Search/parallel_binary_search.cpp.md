---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0575/main.test.cpp
    title: test/aoj/0575/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Search/parallel_binary_search.cpp\"\n#include\
    \ <vector>\n#include <cmath>\n\nnamespace haar_lib {\n  template <typename Init,\
    \ typename Process, typename Checker>\n  auto parallel_binary_search(int M, int\
    \ Q, Init init, Process process, Checker checker){\n    std::vector<int> lb(Q,\
    \ -1), ub(Q, M);\n\n    while(1){\n      bool check = true;\n      std::vector<std::vector<int>>\
    \ mids(M);\n      for(int i = 0; i < Q; ++i){\n        if(std::abs(lb[i] - ub[i])\
    \ > 1){\n          check = false;\n          int mid = (lb[i] + ub[i]) / 2;\n\
    \          mids[mid].push_back(i);\n        }\n      }\n\n      if(check) break;\n\
    \n      init();\n\n      for(int i = 0; i < M; ++i){\n        process(i);\n  \
    \      for(int j : mids[i]){\n          if(checker(j)){\n            ub[j] = i;\n\
    \          }else{\n            lb[j] = i;\n          }\n        }\n      }\n \
    \   }\n\n    return ub;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cmath>\n\nnamespace haar_lib {\n\
    \  template <typename Init, typename Process, typename Checker>\n  auto parallel_binary_search(int\
    \ M, int Q, Init init, Process process, Checker checker){\n    std::vector<int>\
    \ lb(Q, -1), ub(Q, M);\n\n    while(1){\n      bool check = true;\n      std::vector<std::vector<int>>\
    \ mids(M);\n      for(int i = 0; i < Q; ++i){\n        if(std::abs(lb[i] - ub[i])\
    \ > 1){\n          check = false;\n          int mid = (lb[i] + ub[i]) / 2;\n\
    \          mids[mid].push_back(i);\n        }\n      }\n\n      if(check) break;\n\
    \n      init();\n\n      for(int i = 0; i < M; ++i){\n        process(i);\n  \
    \      for(int j : mids[i]){\n          if(checker(j)){\n            ub[j] = i;\n\
    \          }else{\n            lb[j] = i;\n          }\n        }\n      }\n \
    \   }\n\n    return ub;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Search/parallel_binary_search.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0575/main.test.cpp
documentation_of: Mylib/Algorithm/Search/parallel_binary_search.cpp
layout: document
title: Parallel binary search
---

## Operations

## Requirements

## Notes

## Problems

- [CODE THANKS FESTIVAL 2017 H - Union Sets](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h)

## References

- [http://pazzle1230.hatenablog.com/entry/2017/12/26/163616](http://pazzle1230.hatenablog.com/entry/2017/12/26/163616)
- [https://betrue12.hateblo.jp/entry/2019/08/14/152227](https://betrue12.hateblo.jp/entry/2019/08/14/152227)
- [http://codeforces.com/blog/entry/45578](http://codeforces.com/blog/entry/45578)
