---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_3_D/main.test.cpp
    title: test/aoj/ITP1_3_D/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Divisor/enumerate_divisors.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n\nnamespace haar_lib {\n  std::vector<int64_t>\
    \ enumerate_divisors(int64_t n){\n    std::vector<int64_t> temp, ret;\n\n    {\n\
    \      int64_t i;\n      for(i = 1LL; i * i < n; ++i){\n        if(n % i == 0){\n\
    \          temp.push_back(n / i);\n          ret.push_back(i);\n        }\n  \
    \    }\n      if(i * i == n) ret.push_back(i);\n    }\n\n    std::reverse(temp.begin(),\
    \ temp.end());\n    ret.insert(ret.end(), temp.begin(), temp.end());\n\n    return\
    \ ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n\nnamespace haar_lib\
    \ {\n  std::vector<int64_t> enumerate_divisors(int64_t n){\n    std::vector<int64_t>\
    \ temp, ret;\n\n    {\n      int64_t i;\n      for(i = 1LL; i * i < n; ++i){\n\
    \        if(n % i == 0){\n          temp.push_back(n / i);\n          ret.push_back(i);\n\
    \        }\n      }\n      if(i * i == n) ret.push_back(i);\n    }\n\n    std::reverse(temp.begin(),\
    \ temp.end());\n    ret.insert(ret.end(), temp.begin(), temp.end());\n\n    return\
    \ ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Number/Divisor/enumerate_divisors.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
