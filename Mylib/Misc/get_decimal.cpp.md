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
  bundledCode: "#line 2 \"Mylib/Misc/get_decimal.cpp\"\n#include <iostream>\n#include\
    \ <string>\n\nnamespace haar_lib {\n  template <typename T, unsigned int D>\n\
    \  T get_decimal(){\n    T ret = 0;\n    bool minus = false;\n\n    std::string\
    \ s; std::cin >> s;\n\n    auto it = s.begin();\n\n    while(it != s.end() and\
    \ std::isspace(*it)){\n      it += 1;\n    }\n\n    if(it != s.end() and *it ==\
    \ '-'){\n      minus = true;\n      it += 1;\n    }\n\n    while(it != s.end()\
    \ and std::isdigit(*it)){\n      ret = ret * 10 + (int)(*it - '0');\n      it\
    \ += 1;\n    }\n\n    int r = 0;\n    if(it != s.end() and *it == '.'){\n    \
    \  it += 1;\n\n      while(r < (int)D and it != s.end() and std::isdigit(*it)){\n\
    \        ret = ret * 10 + (int)(*it - '0');\n        it += 1;\n        r += 1;\n\
    \      }\n    }\n\n    for(int i = 0; i < (int)D - r; ++i){\n      ret = ret *\
    \ 10;\n    }\n\n    if(minus) ret = -ret;\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <string>\n\nnamespace haar_lib\
    \ {\n  template <typename T, unsigned int D>\n  T get_decimal(){\n    T ret =\
    \ 0;\n    bool minus = false;\n\n    std::string s; std::cin >> s;\n\n    auto\
    \ it = s.begin();\n\n    while(it != s.end() and std::isspace(*it)){\n      it\
    \ += 1;\n    }\n\n    if(it != s.end() and *it == '-'){\n      minus = true;\n\
    \      it += 1;\n    }\n\n    while(it != s.end() and std::isdigit(*it)){\n  \
    \    ret = ret * 10 + (int)(*it - '0');\n      it += 1;\n    }\n\n    int r =\
    \ 0;\n    if(it != s.end() and *it == '.'){\n      it += 1;\n\n      while(r <\
    \ (int)D and it != s.end() and std::isdigit(*it)){\n        ret = ret * 10 + (int)(*it\
    \ - '0');\n        it += 1;\n        r += 1;\n      }\n    }\n\n    for(int i\
    \ = 0; i < (int)D - r; ++i){\n      ret = ret * 10;\n    }\n\n    if(minus) ret\
    \ = -ret;\n\n    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/get_decimal.cpp
  requiredBy: []
  timestamp: '2021-02-07 22:54:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Misc/get_decimal.cpp
layout: document
title: Input decimal
---

## Operations

## Requirements

## Notes

## Problems

## References
