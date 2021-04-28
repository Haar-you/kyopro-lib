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
  bundledCode: "#line 2 \"Mylib/Misc/timer.cpp\"\n#include <chrono>\n#include <iostream>\n\
    \nnamespace haar_lib {\n  class timer {\n    std::chrono::system_clock::time_point\
    \ s_, last_;\n\n  public:\n    timer() {}\n\n    void set() {\n      s_ = last_\
    \ = std::chrono::system_clock::now();\n    }\n\n    void time() {\n#ifdef DEBUG\n\
    \      auto t = std::chrono::system_clock::now();\n      auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t\
    \ - last_).count();\n      std::cerr << \"\\e[1;33m\" << d << \"ms\\e[m\\n\";\n\
    \      last_ = t;\n#endif\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <chrono>\n#include <iostream>\n\nnamespace haar_lib\
    \ {\n  class timer {\n    std::chrono::system_clock::time_point s_, last_;\n\n\
    \  public:\n    timer() {}\n\n    void set() {\n      s_ = last_ = std::chrono::system_clock::now();\n\
    \    }\n\n    void time() {\n#ifdef DEBUG\n      auto t = std::chrono::system_clock::now();\n\
    \      auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t - last_).count();\n\
    \      std::cerr << \"\\e[1;33m\" << d << \"ms\\e[m\\n\";\n      last_ = t;\n\
    #endif\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Misc/timer.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
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
