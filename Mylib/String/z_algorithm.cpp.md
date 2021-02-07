---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Mylib/String/run_enumerate.cpp
    title: Run enumerate
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/runenumerate/main.test.cpp
    title: test/yosupo-judge/runenumerate/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/zalgorithm/main.test.cpp
    title: test/yosupo-judge/zalgorithm/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/z_algorithm.cpp\"\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace haar_lib {\n  template <typename Container>\n  std::vector<int>\
    \ z_algorithm(const Container &s){\n    const int n = s.size();\n    std::vector<int>\
    \ ret(n, 0);\n    int j = 0;\n\n    for(int i = 1; i < n; ++i){\n      if(i +\
    \ ret[i - j] < j + ret[j]){\n        ret[i] = ret[i - j];\n      }else{\n    \
    \    int k = std::max<int>(0, j + ret[j] - i);\n        while(i + k < n and s[k]\
    \ == s[i + k]) ++k;\n        ret[i] = k;\n        j = i;\n      }\n    }\n\n \
    \   ret[0] = n;\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  template <typename Container>\n  std::vector<int> z_algorithm(const Container\
    \ &s){\n    const int n = s.size();\n    std::vector<int> ret(n, 0);\n    int\
    \ j = 0;\n\n    for(int i = 1; i < n; ++i){\n      if(i + ret[i - j] < j + ret[j]){\n\
    \        ret[i] = ret[i - j];\n      }else{\n        int k = std::max<int>(0,\
    \ j + ret[j] - i);\n        while(i + k < n and s[k] == s[i + k]) ++k;\n     \
    \   ret[i] = k;\n        j = i;\n      }\n    }\n\n    ret[0] = n;\n\n    return\
    \ ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/z_algorithm.cpp
  requiredBy:
  - Mylib/String/run_enumerate.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/runenumerate/main.test.cpp
  - test/yosupo-judge/zalgorithm/main.test.cpp
documentation_of: Mylib/String/z_algorithm.cpp
layout: document
title: Z-algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
