---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_5_A/main.test.cpp
    title: test/aoj/DSL_5_A/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Imos/imos_1d.cpp\"\n#include <vector>\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct imos_1d {\n    using value_type\
    \ = T;\n\n    std::vector<T> data;\n    imos_1d(int n): data(n + 1){}\n\n    void\
    \ add(int a, int b, const T& val){ // [a, b)\n      data[a] += 1;\n      data[b]\
    \ -= 1;\n    }\n\n    void build(){\n      for(int i = 0; i < (int)data.size()\
    \ - 1; ++i){\n        data[i + 1] += data[i];\n      }\n    }\n\n    T operator[](size_t\
    \ i) const {return data[i];}\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  struct imos_1d {\n    using value_type = T;\n\n    std::vector<T> data;\n\
    \    imos_1d(int n): data(n + 1){}\n\n    void add(int a, int b, const T& val){\
    \ // [a, b)\n      data[a] += 1;\n      data[b] -= 1;\n    }\n\n    void build(){\n\
    \      for(int i = 0; i < (int)data.size() - 1; ++i){\n        data[i + 1] +=\
    \ data[i];\n      }\n    }\n\n    T operator[](size_t i) const {return data[i];}\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Algorithm/Imos/imos_1d.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_5_A/main.test.cpp
documentation_of: Mylib/Algorithm/Imos/imos_1d.cpp
layout: document
title: 1D Imos algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
