---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
    title: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/SubsetSumProblem/subset_sum_count_fps.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename Fps>\n  auto\
    \ subset_sum_count_fps(std::vector<int> s, int t){\n    using T = typename Fps::value_type;\n\
    \n    std::vector<int> c(t + 1);\n    for(int i : s) c[i] += 1;\n\n    Fps ret(t\
    \ + 1);\n\n    for(int i = 1; i <= t; ++i){\n      if(c[i] == 0) continue;\n\n\
    \      for(int j = 1; j * i <= t; ++j){\n        const int k = j * i;\n      \
    \  const T x = (j % 2 == 1 ? 1 : -1) * i * ((T)k).inv();\n        ret[k] += x\
    \ * c[i];\n      }\n    }\n\n    ret = ret.exp();\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Fps>\n  auto subset_sum_count_fps(std::vector<int> s, int t){\n    using T =\
    \ typename Fps::value_type;\n\n    std::vector<int> c(t + 1);\n    for(int i :\
    \ s) c[i] += 1;\n\n    Fps ret(t + 1);\n\n    for(int i = 1; i <= t; ++i){\n \
    \     if(c[i] == 0) continue;\n\n      for(int j = 1; j * i <= t; ++j){\n    \
    \    const int k = j * i;\n        const T x = (j % 2 == 1 ? 1 : -1) * i * ((T)k).inv();\n\
    \        ret[k] += x * c[i];\n      }\n    }\n\n    ret = ret.exp();\n\n    return\
    \ ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/SubsetSumProblem/subset_sum_count_fps.cpp
  requiredBy: []
  timestamp: '2020-09-21 02:36:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
documentation_of: Mylib/Typical/SubsetSumProblem/subset_sum_count_fps.cpp
layout: document
title: Subset sum problem (Count, FPS)
---

## Operations

## Requirements

## Notes

## Problems

## References
