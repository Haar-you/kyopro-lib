---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/499/main.test.cpp
    title: test/yukicoder/499/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/782/main.test.cpp
    title: test/yukicoder/782/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Misc/convert_base.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  std::vector<int64_t> convert_base_to(int64_t\
    \ val, int64_t base) {\n    if (val == 0) return {0};\n\n    int b = std::abs(base);\n\
    \n    std::vector<int64_t> ret;\n    while (val != 0) {\n      int r = val % b;\n\
    \      if (r < 0) r += b;\n      val = (val - r) / base;\n      ret.push_back(r);\n\
    \    }\n\n    std::reverse(ret.begin(), ret.end());\n\n    return ret;\n  }\n\n\
    \  int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base) {\n\
    \    int64_t ret = 0;\n    for (auto it = val.begin(); it != val.end(); ++it)\
    \ {\n      (ret *= base) += *it;\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  std::vector<int64_t> convert_base_to(int64_t val, int64_t base) {\n   \
    \ if (val == 0) return {0};\n\n    int b = std::abs(base);\n\n    std::vector<int64_t>\
    \ ret;\n    while (val != 0) {\n      int r = val % b;\n      if (r < 0) r +=\
    \ b;\n      val = (val - r) / base;\n      ret.push_back(r);\n    }\n\n    std::reverse(ret.begin(),\
    \ ret.end());\n\n    return ret;\n  }\n\n  int64_t convert_base_from(const std::vector<int64_t>\
    \ &val, int64_t base) {\n    int64_t ret = 0;\n    for (auto it = val.begin();\
    \ it != val.end(); ++it) {\n      (ret *= base) += *it;\n    }\n\n    return ret;\n\
    \  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/convert_base.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/499/main.test.cpp
  - test/yukicoder/782/main.test.cpp
documentation_of: Mylib/Misc/convert_base.cpp
layout: document
title: Convert base
---

## Operations

## Requirements

## Notes

## Problems

## References