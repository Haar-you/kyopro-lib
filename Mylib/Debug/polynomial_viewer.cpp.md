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
  bundledCode: "#line 2 \"Mylib/Debug/polynomial_viewer.cpp\"\n#include <iostream>\n\
    #include <string>\n\ntemplate <typename Container>\nclass PolynomialViewer {\n\
    \  Container data;\n\npublic:\n  PolynomialViewer(Container data): data(data){}\n\
    \n  void show_x(std::ostream &s, int k) const {\n    if(k == 0) return;\n    else\
    \ if(k == 1) s << \"x\";\n    else{\n      s << \"x\";\n\n      constexpr static\
    \ auto p = \"\u2070\xB9\xB2\xB3\u2074\u2075\u2076\u2077\u2078\u2079\";\n     \
    \ for(char c : std::to_string(k)){\n        int i = c - '0';\n        if(i ==\
    \ 0) s << p[i] << p[i + 1] << p[i + 2];\n        else if(1 <= i and i <= 3) s\
    \ << p[1 + i * 2] << p[2 + i * 2];\n        else s << p[i * 3 - 3] << p[i * 3\
    \ - 2] << p[i * 3 - 1];\n      }\n    }\n  }\n\n  auto& run(std::ostream &s) const\
    \ {\n    const int n = data.size();\n\n    for(int i = 0; i < n; ++i){\n     \
    \ s << data[i];\n      show_x(s, i);\n      s << \" \";\n    }\n\n    return s;\n\
    \  }\n\n  friend std::ostream& operator<<(std::ostream &s, const PolynomialViewer\
    \ &a){\n    return a.run(s);\n  }\n};\n"
  code: "#pragma once\n#include <iostream>\n#include <string>\n\ntemplate <typename\
    \ Container>\nclass PolynomialViewer {\n  Container data;\n\npublic:\n  PolynomialViewer(Container\
    \ data): data(data){}\n\n  void show_x(std::ostream &s, int k) const {\n    if(k\
    \ == 0) return;\n    else if(k == 1) s << \"x\";\n    else{\n      s << \"x\"\
    ;\n\n      constexpr static auto p = \"\u2070\xB9\xB2\xB3\u2074\u2075\u2076\u2077\
    \u2078\u2079\";\n      for(char c : std::to_string(k)){\n        int i = c - '0';\n\
    \        if(i == 0) s << p[i] << p[i + 1] << p[i + 2];\n        else if(1 <= i\
    \ and i <= 3) s << p[1 + i * 2] << p[2 + i * 2];\n        else s << p[i * 3 -\
    \ 3] << p[i * 3 - 2] << p[i * 3 - 1];\n      }\n    }\n  }\n\n  auto& run(std::ostream\
    \ &s) const {\n    const int n = data.size();\n\n    for(int i = 0; i < n; ++i){\n\
    \      s << data[i];\n      show_x(s, i);\n      s << \" \";\n    }\n\n    return\
    \ s;\n  }\n\n  friend std::ostream& operator<<(std::ostream &s, const PolynomialViewer\
    \ &a){\n    return a.run(s);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Debug/polynomial_viewer.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Debug/polynomial_viewer.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
