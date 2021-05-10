---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/partition_function/main.fps.test.cpp
    title: test/yosupo-judge/partition_function/main.fps.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/partition_number_fps.cpp\"\n#include\
    \ <cmath>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename Fps>\n\
    \  Fps partition_number_fps(int N) {\n    using T = typename Fps::value_type;\n\
    \n    std::vector<T> f(N + 1);\n    f[0] = 1;\n\n    {\n      const int M = (std::sqrt(1\
    \ + 24 * N) - 1) / 6;\n      for (int i = 1; i <= M; ++i) {\n        f[i * (3\
    \ * i + 1) / 2] += (i % 2 == 0 ? 1 : -1);\n      }\n    }\n\n    {\n      const\
    \ int M = (std::sqrt(1 + 24 * N) + 1) / 6;\n      for (int i = 1; i <= M; ++i)\
    \ {\n        f[i * (3 * i - 1) / 2] += (i % 2 == 0 ? 1 : -1);\n      }\n    }\n\
    \n    Fps ret(f);\n    ret = ret.inv();\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  template <typename Fps>\n  Fps partition_number_fps(int N) {\n    using T =\
    \ typename Fps::value_type;\n\n    std::vector<T> f(N + 1);\n    f[0] = 1;\n\n\
    \    {\n      const int M = (std::sqrt(1 + 24 * N) - 1) / 6;\n      for (int i\
    \ = 1; i <= M; ++i) {\n        f[i * (3 * i + 1) / 2] += (i % 2 == 0 ? 1 : -1);\n\
    \      }\n    }\n\n    {\n      const int M = (std::sqrt(1 + 24 * N) + 1) / 6;\n\
    \      for (int i = 1; i <= M; ++i) {\n        f[i * (3 * i - 1) / 2] += (i %\
    \ 2 == 0 ? 1 : -1);\n      }\n    }\n\n    Fps ret(f);\n    ret = ret.inv();\n\
    \n    return ret;\n  }\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/partition_number_fps.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/partition_function/main.fps.test.cpp
documentation_of: Mylib/Combinatorics/partition_number_fps.cpp
layout: document
title: Partition number (FPS)
---

## Operations

## Requirements

## Notes

## Problems

## References