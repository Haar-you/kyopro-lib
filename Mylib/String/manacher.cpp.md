---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/manacher.cpp\"\n#include <vector>\n\nnamespace\
    \ haar_lib {\n  template <typename Container>\n  std::vector<int> manacher(const\
    \ Container &s){\n    const int n = s.size();\n    std::vector<int> ret(n);\n\
    \    int center = 0;\n\n    for(int cur = 0; cur < n; ++cur){\n      int left\
    \ = center - (cur - center);\n\n      if(left >= 0 and cur + ret[left] < center\
    \ + ret[center]){\n        ret[cur] = ret[left];\n      }else{\n        int len\
    \ = center + ret[center] - cur;\n        while(cur - len >= 0 and cur + len <\
    \ n and s[cur - len] == s[cur + len]) ++len;\n        ret[cur] = len;\n      \
    \  center = cur;\n      }\n    }\n\n    return ret;\n  }\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Container>\n  std::vector<int> manacher(const Container &s){\n    const int\
    \ n = s.size();\n    std::vector<int> ret(n);\n    int center = 0;\n\n    for(int\
    \ cur = 0; cur < n; ++cur){\n      int left = center - (cur - center);\n\n   \
    \   if(left >= 0 and cur + ret[left] < center + ret[center]){\n        ret[cur]\
    \ = ret[left];\n      }else{\n        int len = center + ret[center] - cur;\n\
    \        while(cur - len >= 0 and cur + len < n and s[cur - len] == s[cur + len])\
    \ ++len;\n        ret[cur] = len;\n        center = cur;\n      }\n    }\n\n \
    \   return ret;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/manacher.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/String/manacher.cpp
layout: document
title: Manacher algorithm
---

## Operations

- `manacher(s)`
	- 各位置`i`を中心とした最長奇数長回文の片側長さ(回文長`L`に対して`L/2+1`)の配列を返す。

## Requirements

## Notes

## Problems

## References
