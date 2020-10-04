---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Misc/timer.cpp\"\n#include <chrono>\n#include <iostream>\n\
    \nclass timer {\n  std::chrono::system_clock::time_point s_, last_;\n\npublic:\n\
    \  timer(){}\n\n  void set(){\n    s_ = last_ = std::chrono::system_clock::now();\n\
    \  }\n\n  void time(){\n    auto t = std::chrono::system_clock::now();\n    auto\
    \ d = std::chrono::duration_cast<std::chrono::milliseconds>(t - last_).count();\n\
    \    std::cerr << \"\\e[1;33m\" << d << \"ms\\e[m\\n\";\n    last_ = t;\n  }\n\
    };\n"
  code: "#pragma once\n#include <chrono>\n#include <iostream>\n\nclass timer {\n \
    \ std::chrono::system_clock::time_point s_, last_;\n\npublic:\n  timer(){}\n\n\
    \  void set(){\n    s_ = last_ = std::chrono::system_clock::now();\n  }\n\n  void\
    \ time(){\n    auto t = std::chrono::system_clock::now();\n    auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t\
    \ - last_).count();\n    std::cerr << \"\\e[1;33m\" << d << \"ms\\e[m\\n\";\n\
    \    last_ = t;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/timer.cpp
  requiredBy: []
  timestamp: '2020-10-02 09:27:49+09:00'
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
