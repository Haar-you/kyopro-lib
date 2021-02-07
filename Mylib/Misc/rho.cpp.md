---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Misc/rho.cpp\"\n#include <vector>\n#include <utility>\n\
    \ntemplate <typename F>\nstd::pair<int, int> rho(int N, int first, F f){\n  std::vector<int>\
    \ check(N);\n\n  int tail = 0, cycle = 0;\n  int a = first, i = 1;\n  while(true){\n\
    \    check[a] = i;\n\n    a = f(a);\n    ++i;\n    if(check[a] > 0){\n      tail\
    \ = check[a] - 1;\n      cycle = i - check[a];\n      break;\n    }\n  }\n\n \
    \ return {tail, cycle};\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n\ntemplate <typename\
    \ F>\nstd::pair<int, int> rho(int N, int first, F f){\n  std::vector<int> check(N);\n\
    \n  int tail = 0, cycle = 0;\n  int a = first, i = 1;\n  while(true){\n    check[a]\
    \ = i;\n\n    a = f(a);\n    ++i;\n    if(check[a] > 0){\n      tail = check[a]\
    \ - 1;\n      cycle = i - check[a];\n      break;\n    }\n  }\n\n  return {tail,\
    \ cycle};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/rho.cpp
  requiredBy: []
  timestamp: '2020-09-26 05:19:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Misc/rho.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
