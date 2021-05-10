---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1300/main.test.cpp
    title: test/aoj/1300/main.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/LinearAlgebra/gaussian_elimination.cpp\"\n#include\
    \ <utility>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n\
    \  int gaussian_elimination(std::vector<std::vector<T>> &a) {\n    const int h\
    \ = a.size();\n    const int w = a[0].size();\n    int rank    = 0;\n\n    for\
    \ (int j = 0; j < w; ++j) {\n      int pivot = -1;\n\n      for (int i = rank;\
    \ i < h; ++i) {\n        if (a[i][j] != 0) {\n          pivot = i;\n         \
    \ break;\n        }\n      }\n\n      if (pivot == -1) continue;\n\n      std::swap(a[pivot],\
    \ a[rank]);\n\n      auto d = a[rank][j];\n      for (int k = 0; k < w; ++k) a[rank][k]\
    \ /= d;\n\n      for (int i = 0; i < h; ++i) {\n        if (i == rank or a[i][j]\
    \ == 0) continue;\n        auto d = a[i][j];\n        for (int k = 0; k < w; ++k)\
    \ {\n          a[i][k] -= a[rank][k] * d;\n        }\n      }\n\n      ++rank;\n\
    \    }\n\n    return rank;\n  }\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  int gaussian_elimination(std::vector<std::vector<T>>\
    \ &a) {\n    const int h = a.size();\n    const int w = a[0].size();\n    int\
    \ rank    = 0;\n\n    for (int j = 0; j < w; ++j) {\n      int pivot = -1;\n\n\
    \      for (int i = rank; i < h; ++i) {\n        if (a[i][j] != 0) {\n       \
    \   pivot = i;\n          break;\n        }\n      }\n\n      if (pivot == -1)\
    \ continue;\n\n      std::swap(a[pivot], a[rank]);\n\n      auto d = a[rank][j];\n\
    \      for (int k = 0; k < w; ++k) a[rank][k] /= d;\n\n      for (int i = 0; i\
    \ < h; ++i) {\n        if (i == rank or a[i][j] == 0) continue;\n        auto\
    \ d = a[i][j];\n        for (int k = 0; k < w; ++k) {\n          a[i][k] -= a[rank][k]\
    \ * d;\n        }\n      }\n\n      ++rank;\n    }\n\n    return rank;\n  }\n\
    }  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/LinearAlgebra/gaussian_elimination.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1300/main.test.cpp
documentation_of: Mylib/LinearAlgebra/gaussian_elimination.cpp
layout: document
title: Gaussian elimination
---

## Operations

## Requirements

## Notes

## Problems

## References