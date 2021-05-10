---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/String/run_enumerate.cpp
    title: Run enumerate
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/runenumerate/main.test.cpp
    title: test/yosupo-judge/runenumerate/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/zalgorithm/main.test.cpp
    title: test/yosupo-judge/zalgorithm/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/z_algorithm.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename Container>\n  std::vector<int>\
    \ z_algorithm(const Container &s) {\n    const int n = s.size();\n    std::vector<int>\
    \ ret(n, 0);\n    int j = 0;\n\n    for (int i = 1; i < n; ++i) {\n      if (i\
    \ + ret[i - j] < j + ret[j]) {\n        ret[i] = ret[i - j];\n      } else {\n\
    \        int k = std::max<int>(0, j + ret[j] - i);\n        while (i + k < n and\
    \ s[k] == s[i + k]) ++k;\n        ret[i] = k;\n        j      = i;\n      }\n\
    \    }\n\n    ret[0] = n;\n\n    return ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename Container>\n  std::vector<int> z_algorithm(const Container\
    \ &s) {\n    const int n = s.size();\n    std::vector<int> ret(n, 0);\n    int\
    \ j = 0;\n\n    for (int i = 1; i < n; ++i) {\n      if (i + ret[i - j] < j +\
    \ ret[j]) {\n        ret[i] = ret[i - j];\n      } else {\n        int k = std::max<int>(0,\
    \ j + ret[j] - i);\n        while (i + k < n and s[k] == s[i + k]) ++k;\n    \
    \    ret[i] = k;\n        j      = i;\n      }\n    }\n\n    ret[0] = n;\n\n \
    \   return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/z_algorithm.cpp
  requiredBy:
  - Mylib/String/run_enumerate.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/zalgorithm/main.test.cpp
  - test/yosupo-judge/runenumerate/main.test.cpp
documentation_of: Mylib/String/z_algorithm.cpp
layout: document
title: Z-algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References