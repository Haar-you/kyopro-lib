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
  bundledCode: "#line 2 \"Mylib/Heuristic/simulated_annealing.cpp\"\n#include <chrono>\n\
    #include <cmath>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ Func>\n  void simulated_annealing(int duration, double T0, double T1, Func f){\n\
    \    using namespace std::chrono;\n    assert(T0 >= T1);\n\n    auto s = system_clock::now();\n\
    \n    while(true){\n      auto t = system_clock::now();\n      int d = duration_cast<milliseconds>(t\
    \ - s).count();\n      if(d >= duration) break;\n\n      double now = (double)d\
    \ / duration;\n\n      double T = std::pow(T0, 1.0 - now) * std::pow(T1, now);\n\
    \n      f(d, T);\n    }\n  }\n}\n"
  code: "#pragma once\n#include <chrono>\n#include <cmath>\n#include <cassert>\n\n\
    namespace haar_lib {\n  template <typename Func>\n  void simulated_annealing(int\
    \ duration, double T0, double T1, Func f){\n    using namespace std::chrono;\n\
    \    assert(T0 >= T1);\n\n    auto s = system_clock::now();\n\n    while(true){\n\
    \      auto t = system_clock::now();\n      int d = duration_cast<milliseconds>(t\
    \ - s).count();\n      if(d >= duration) break;\n\n      double now = (double)d\
    \ / duration;\n\n      double T = std::pow(T0, 1.0 - now) * std::pow(T1, now);\n\
    \n      f(d, T);\n    }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Heuristic/simulated_annealing.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Heuristic/simulated_annealing.cpp
layout: document
title: Simulated annealing
---

## Operations

## Requirements

## Notes

## Problems

## References
