---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1300/main.test.cpp
    title: test/aoj/1300/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/String/split.cpp\"\n#include <string>\n#include <vector>\n\
    \nnamespace haar_lib {\n  auto split(const std::string &s, const std::string &delim){\n\
    \    std::vector<std::string> ret;\n\n    size_t i = 0;\n    while(1){\n     \
    \ size_t j = s.find(delim, i);\n      if(j == std::string::npos) break;\n\n  \
    \    ret.push_back(s.substr(i, j - i));\n\n      i = j + delim.size();\n    }\n\
    \n    ret.push_back(s.substr(i, s.size() - i));\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  auto split(const std::string &s, const std::string &delim){\n    std::vector<std::string>\
    \ ret;\n\n    size_t i = 0;\n    while(1){\n      size_t j = s.find(delim, i);\n\
    \      if(j == std::string::npos) break;\n\n      ret.push_back(s.substr(i, j\
    \ - i));\n\n      i = j + delim.size();\n    }\n\n    ret.push_back(s.substr(i,\
    \ s.size() - i));\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/split.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1300/main.test.cpp
documentation_of: Mylib/String/split.cpp
layout: document
title: split
---

## Operations

## Requirements

## Notes

## Problems

## References
