---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_5_B/main.test.cpp
    title: test/aoj/DSL_5_B/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Imos/imos_2d.cpp\"\n#include <vector>\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct imos_2d {\n    using value_type\
    \ = T;\n\n    std::vector<std::vector<T>> vec;\n    int n, m;\n    imos_2d(int\
    \ n, int m): vec(n + 1, std::vector<T>(m + 1)), n(n), m(m){}\n\n    void add(int\
    \ a1, int b1, int a2, int b2){ // [a1, a2) [b1, b2)\n      vec[a1][b1] += 1;\n\
    \      vec[a2][b2] += 1;\n      vec[a1][b2] -= 1;\n      vec[a2][b1] -= 1;\n \
    \   }\n\n    void build(){\n      for(int i = 0; i < n; ++i){\n        for(int\
    \ j = 0; j < m + 1; ++j){\n          vec[i + 1][j] += vec[i][j];\n        }\n\
    \      }\n\n      for(int i = 0; i < n + 1; ++i){\n        for(int j = 0; j <\
    \ m; ++j){\n          vec[i][j + 1] += vec[i][j];\n        }\n      }\n    }\n\
    \n    const std::vector<T>& operator[](size_t i) const {return vec[i];}\n  };\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct imos_2d {\n    using value_type = T;\n\n    std::vector<std::vector<T>>\
    \ vec;\n    int n, m;\n    imos_2d(int n, int m): vec(n + 1, std::vector<T>(m\
    \ + 1)), n(n), m(m){}\n\n    void add(int a1, int b1, int a2, int b2){ // [a1,\
    \ a2) [b1, b2)\n      vec[a1][b1] += 1;\n      vec[a2][b2] += 1;\n      vec[a1][b2]\
    \ -= 1;\n      vec[a2][b1] -= 1;\n    }\n\n    void build(){\n      for(int i\
    \ = 0; i < n; ++i){\n        for(int j = 0; j < m + 1; ++j){\n          vec[i\
    \ + 1][j] += vec[i][j];\n        }\n      }\n\n      for(int i = 0; i < n + 1;\
    \ ++i){\n        for(int j = 0; j < m; ++j){\n          vec[i][j + 1] += vec[i][j];\n\
    \        }\n      }\n    }\n\n    const std::vector<T>& operator[](size_t i) const\
    \ {return vec[i];}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Imos/imos_2d.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_5_B/main.test.cpp
documentation_of: Mylib/Algorithm/Imos/imos_2d.cpp
layout: document
title: 2D Imos algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
