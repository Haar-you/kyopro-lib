---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Misc/timer.cpp\"\n#include <chrono>\n#include <iostream>\n\
    \nnamespace haar_lib {\ntemplate <typename F>\nvoid timer(F f){\n  auto s = std::chrono::system_clock::now();\n\
    \  f();\n  auto t = std::chrono::system_clock::now();\n  auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t\
    \ - s).count();\n  std::cerr << d << \"ms\" << \"\\n\";\n};\n}\n"
  code: "#pragma once\n#include <chrono>\n#include <iostream>\n\nnamespace haar_lib\
    \ {\ntemplate <typename F>\nvoid timer(F f){\n  auto s = std::chrono::system_clock::now();\n\
    \  f();\n  auto t = std::chrono::system_clock::now();\n  auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t\
    \ - s).count();\n  std::cerr << d << \"ms\" << \"\\n\";\n};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/timer.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Misc/timer.cpp
layout: document
title: Timer
---

## Operations

## Requirements

## Notes

## Problems

## References
