---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/partition_function/main.fps.test.cpp
    title: test/yosupo-judge/partition_function/main.fps.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Combinatorics/partition_number_fps.cpp\"\n#include\
    \ <vector>\n#include <cmath>\n\nnamespace haar_lib {\n  template <typename Fps>\n\
    \  auto partition_number_fps(int N){\n    using T = typename Fps::value_type;\n\
    \n    std::vector<T> f(N + 1);\n    f[0] = 1;\n\n    {\n      const int M = (std::sqrt(1\
    \ + 24 * N) - 1) / 6;\n      for(int i = 1; i <= M; ++i){\n        f[i * (3 *\
    \ i + 1) / 2] += (i % 2 == 0 ? 1 : -1);\n      }\n    }\n\n    {\n      const\
    \ int M = (std::sqrt(1 + 24 * N) + 1) / 6;\n      for(int i = 1; i <= M; ++i){\n\
    \        f[i * (3 * i - 1) / 2] += (i % 2 == 0 ? 1 : -1);\n      }\n    }\n\n\
    \    Fps ret(f);\n    ret = ret.inv();\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cmath>\n\nnamespace haar_lib {\n\
    \  template <typename Fps>\n  auto partition_number_fps(int N){\n    using T =\
    \ typename Fps::value_type;\n\n    std::vector<T> f(N + 1);\n    f[0] = 1;\n\n\
    \    {\n      const int M = (std::sqrt(1 + 24 * N) - 1) / 6;\n      for(int i\
    \ = 1; i <= M; ++i){\n        f[i * (3 * i + 1) / 2] += (i % 2 == 0 ? 1 : -1);\n\
    \      }\n    }\n\n    {\n      const int M = (std::sqrt(1 + 24 * N) + 1) / 6;\n\
    \      for(int i = 1; i <= M; ++i){\n        f[i * (3 * i - 1) / 2] += (i % 2\
    \ == 0 ? 1 : -1);\n      }\n    }\n\n    Fps ret(f);\n    ret = ret.inv();\n\n\
    \    return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Combinatorics/partition_number_fps.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
