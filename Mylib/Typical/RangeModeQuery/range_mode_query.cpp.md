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
  bundledCode: "#line 2 \"Mylib/Typical/RangeModeQuery/range_mode_query.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <utility>\n#include <cmath>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class range_mode_query {\n    std::vector<T>\
    \ a, D;\n    std::vector<int> b, b_index;\n\n    const int N;\n    const int block_size;\n\
    \    const int block_num;\n\n    int K;\n\n    std::vector<std::vector<int>> index;\n\
    \    std::vector<std::vector<int>> mode, freq;\n\n  public:\n    range_mode_query(std::vector<T>\
    \ a):\n      a(a), D(a), N(a.size()), block_size(std::sqrt(N)), block_num((N +\
    \ block_size - 1) / block_size),\n      mode(block_num, std::vector<int>(block_num)),\n\
    \      freq(block_num, std::vector<int>(block_num))\n    {\n      std::sort(D.begin(),\
    \ D.end());\n      D.erase(std::unique(D.begin(), D.end()), D.end());\n\n    \
    \  b.resize(N);\n      for(int i = 0; i < N; ++i){\n        b[i] = std::lower_bound(D.begin(),\
    \ D.end(), a[i]) - D.begin();\n      }\n\n      K = D.size();\n\n      index.resize(K);\n\
    \      b_index.resize(N);\n      for(int i = 0; i < N; ++i){\n        b_index[i]\
    \ = index[b[i]].size();\n        index[b[i]].push_back(i);\n      }\n\n      for(int\
    \ i = 0; i < block_num; ++i){\n        std::vector<int> temp(K);\n        int\
    \ md = 0, fr = 0;\n\n        for(int j = i; j < block_num; ++j){\n          int\
    \ R = std::min(N, block_size * (j + 1));\n          for(int x = block_size * j;\
    \ x < R; ++x){\n            temp[b[x]] += 1;\n\n            if(temp[b[x]] > fr){\n\
    \              md = b[x];\n              fr = temp[b[x]];\n            }\n   \
    \       }\n\n          mode[i][j] = md;\n          freq[i][j] = fr;\n        }\n\
    \      }\n    }\n\n    std::pair<int, T> query(int l, int r){ // [l, r)\n    \
    \  std::pair<int, T> ret = std::make_pair(0, 0);\n\n      int span_l = (l + block_size\
    \ - 1) / block_size, span_r = r / block_size - 1;\n\n      if(span_l <= span_r){\n\
    \        ret = std::make_pair(freq[span_l][span_r], D[mode[span_l][span_r]]);\n\
    \      }\n\n      // prefix\n      for(int i = l; i < std::min(r, span_l * block_size);\
    \ ++i){\n        if(b_index[i] - 1 >= 0 and index[b[i]][b_index[i] - 1] >= l)\
    \ continue;\n\n        if(b_index[i] + ret.first - 1 < 0 or (b_index[i] + ret.first\
    \ - 1 < (int)index[b[i]].size() and index[b[i]][b_index[i] + ret.first - 1] <\
    \ r)){\n          int fr = ret.first;\n\n          for(int j = b_index[i] + ret.first;\
    \ j < (int)index[b[i]].size(); ++j){\n            if(index[b[i]][j] < r) ++fr;\n\
    \            else break;\n          }\n\n          if(fr > ret.first){\n     \
    \       ret = std::make_pair(fr, D[b[i]]);\n          }\n        }\n      }\n\n\
    \      // suffix\n      for(int i = r - 1; i >= std::max(l, (span_r + 1) * block_size);\
    \ --i){\n        if(b_index[i] + 1 < (int)index[b[i]].size() and index[b[i]][b_index[i]\
    \ + 1] < r) continue;\n\n        if(b_index[i] - ret.first + 1 >= (int)index[b[i]].size()\
    \ or (b_index[i] - ret.first + 1 >= 0 and index[b[i]][b_index[i] - ret.first +\
    \ 1] >= l)){\n          int fr = ret.first;\n\n          for(int j = b_index[i]\
    \ - ret.first; j >= 0; --j){\n            if(index[b[i]][j] >= l) ++fr;\n    \
    \        else break;\n          }\n\n          if(fr > ret.first){\n         \
    \   ret = std::make_pair(fr, D[b[i]]);\n          }\n        }\n      }\n\n  \
    \    return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <utility>\n\
    #include <cmath>\n\nnamespace haar_lib {\n  template <typename T>\n  class range_mode_query\
    \ {\n    std::vector<T> a, D;\n    std::vector<int> b, b_index;\n\n    const int\
    \ N;\n    const int block_size;\n    const int block_num;\n\n    int K;\n\n  \
    \  std::vector<std::vector<int>> index;\n    std::vector<std::vector<int>> mode,\
    \ freq;\n\n  public:\n    range_mode_query(std::vector<T> a):\n      a(a), D(a),\
    \ N(a.size()), block_size(std::sqrt(N)), block_num((N + block_size - 1) / block_size),\n\
    \      mode(block_num, std::vector<int>(block_num)),\n      freq(block_num, std::vector<int>(block_num))\n\
    \    {\n      std::sort(D.begin(), D.end());\n      D.erase(std::unique(D.begin(),\
    \ D.end()), D.end());\n\n      b.resize(N);\n      for(int i = 0; i < N; ++i){\n\
    \        b[i] = std::lower_bound(D.begin(), D.end(), a[i]) - D.begin();\n    \
    \  }\n\n      K = D.size();\n\n      index.resize(K);\n      b_index.resize(N);\n\
    \      for(int i = 0; i < N; ++i){\n        b_index[i] = index[b[i]].size();\n\
    \        index[b[i]].push_back(i);\n      }\n\n      for(int i = 0; i < block_num;\
    \ ++i){\n        std::vector<int> temp(K);\n        int md = 0, fr = 0;\n\n  \
    \      for(int j = i; j < block_num; ++j){\n          int R = std::min(N, block_size\
    \ * (j + 1));\n          for(int x = block_size * j; x < R; ++x){\n          \
    \  temp[b[x]] += 1;\n\n            if(temp[b[x]] > fr){\n              md = b[x];\n\
    \              fr = temp[b[x]];\n            }\n          }\n\n          mode[i][j]\
    \ = md;\n          freq[i][j] = fr;\n        }\n      }\n    }\n\n    std::pair<int,\
    \ T> query(int l, int r){ // [l, r)\n      std::pair<int, T> ret = std::make_pair(0,\
    \ 0);\n\n      int span_l = (l + block_size - 1) / block_size, span_r = r / block_size\
    \ - 1;\n\n      if(span_l <= span_r){\n        ret = std::make_pair(freq[span_l][span_r],\
    \ D[mode[span_l][span_r]]);\n      }\n\n      // prefix\n      for(int i = l;\
    \ i < std::min(r, span_l * block_size); ++i){\n        if(b_index[i] - 1 >= 0\
    \ and index[b[i]][b_index[i] - 1] >= l) continue;\n\n        if(b_index[i] + ret.first\
    \ - 1 < 0 or (b_index[i] + ret.first - 1 < (int)index[b[i]].size() and index[b[i]][b_index[i]\
    \ + ret.first - 1] < r)){\n          int fr = ret.first;\n\n          for(int\
    \ j = b_index[i] + ret.first; j < (int)index[b[i]].size(); ++j){\n           \
    \ if(index[b[i]][j] < r) ++fr;\n            else break;\n          }\n\n     \
    \     if(fr > ret.first){\n            ret = std::make_pair(fr, D[b[i]]);\n  \
    \        }\n        }\n      }\n\n      // suffix\n      for(int i = r - 1; i\
    \ >= std::max(l, (span_r + 1) * block_size); --i){\n        if(b_index[i] + 1\
    \ < (int)index[b[i]].size() and index[b[i]][b_index[i] + 1] < r) continue;\n\n\
    \        if(b_index[i] - ret.first + 1 >= (int)index[b[i]].size() or (b_index[i]\
    \ - ret.first + 1 >= 0 and index[b[i]][b_index[i] - ret.first + 1] >= l)){\n \
    \         int fr = ret.first;\n\n          for(int j = b_index[i] - ret.first;\
    \ j >= 0; --j){\n            if(index[b[i]][j] >= l) ++fr;\n            else break;\n\
    \          }\n\n          if(fr > ret.first){\n            ret = std::make_pair(fr,\
    \ D[b[i]]);\n          }\n        }\n      }\n\n      return ret;\n    }\n  };\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/RangeModeQuery/range_mode_query.cpp
  requiredBy: []
  timestamp: '2020-09-25 06:14:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Typical/RangeModeQuery/range_mode_query.cpp
layout: document
title: Range mode query
---

## Operations

- `range_mode_query(a)`
- `query(int l, int r)`
	- `[l, r)`での最頻値とその頻度を返す。
	- Time complexity $O(\sqrt{N})$

## Requirements

## Notes

## Problems

- [SPOJ FREQ2](https://www.spoj.com/problems/FREQ2/)

## References

- [https://scrapbox.io/data-structures/Range_Mode_Query](https://scrapbox.io/data-structures/Range_Mode_Query)
