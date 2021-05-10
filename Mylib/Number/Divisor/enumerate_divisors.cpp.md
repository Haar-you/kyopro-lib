---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ITP1_3_D/main.test.cpp
    title: test/aoj/ITP1_3_D/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Divisor/enumerate_divisors.cpp\"\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace haar_lib {\n  std::vector<int64_t>\
    \ enumerate_divisors(int64_t n) {\n    std::vector<int64_t> temp, ret;\n\n   \
    \ {\n      int64_t i;\n      for (i = 1LL; i * i < n; ++i) {\n        if (n %\
    \ i == 0) {\n          temp.push_back(n / i);\n          ret.push_back(i);\n \
    \       }\n      }\n      if (i * i == n) ret.push_back(i);\n    }\n\n    std::reverse(temp.begin(),\
    \ temp.end());\n    ret.insert(ret.end(), temp.begin(), temp.end());\n\n    return\
    \ ret;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  std::vector<int64_t> enumerate_divisors(int64_t n) {\n    std::vector<int64_t>\
    \ temp, ret;\n\n    {\n      int64_t i;\n      for (i = 1LL; i * i < n; ++i) {\n\
    \        if (n % i == 0) {\n          temp.push_back(n / i);\n          ret.push_back(i);\n\
    \        }\n      }\n      if (i * i == n) ret.push_back(i);\n    }\n\n    std::reverse(temp.begin(),\
    \ temp.end());\n    ret.insert(ret.end(), temp.begin(), temp.end());\n\n    return\
    \ ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Divisor/enumerate_divisors.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ITP1_3_D/main.test.cpp
documentation_of: Mylib/Number/Divisor/enumerate_divisors.cpp
layout: document
title: Enumerate divisors
---

## Operations

## Requirements

## Notes

## Problems

## References