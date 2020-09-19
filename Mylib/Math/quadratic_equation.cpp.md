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
  bundledCode: "#line 2 \"Mylib/Math/quadratic_equation.cpp\"\n#include <cmath>\n\
    #include <vector>\n\nnamespace haar_lib {\n  std::vector<double> quadratic_equation(double\
    \ a, double b, double c){\n    double d = b * b - 4 * a * c;\n    if(d < 0) return\
    \ {};\n\n    double x1 = (-b - std::sqrt(d)) / (2 * a);\n    double x2 = (-b +\
    \ std::sqrt(d)) / (2 * a);\n    return {x1, x2};\n  }\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  std::vector<double> quadratic_equation(double a, double b, double c){\n   \
    \ double d = b * b - 4 * a * c;\n    if(d < 0) return {};\n\n    double x1 = (-b\
    \ - std::sqrt(d)) / (2 * a);\n    double x2 = (-b + std::sqrt(d)) / (2 * a);\n\
    \    return {x1, x2};\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/quadratic_equation.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Math/quadratic_equation.cpp
layout: document
title: Real solutions of quadratic equation
---

## Operations

## Requirements

## Notes

## Problems

## References
