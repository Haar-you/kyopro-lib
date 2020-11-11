---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/range_mode_query.cpp\"\n#include <vector>\n\
    #include <algorithm>\n#include <utility>\n#include <cmath>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class range_mode_query {\n    std::vector<T> a_,\
    \ D_;\n    std::vector<int> b_, b_index_;\n    int N_, block_size_, block_num_,\
    \ K_;\n    std::vector<std::vector<int>> index_, mode_, freq_;\n\n  public:\n\
    \    range_mode_query(){}\n    range_mode_query(std::vector<T> a):\n      a_(a),\
    \ D_(a), N_(a.size()), block_size_(std::sqrt(N_)),\n      block_num_((N_ + block_size_\
    \ - 1) / block_size_),\n      mode_(block_num_, std::vector<int>(block_num_)),\n\
    \      freq_(block_num_, std::vector<int>(block_num_))\n    {\n      std::sort(D_.begin(),\
    \ D_.end());\n      D_.erase(std::unique(D_.begin(), D_.end()), D_.end());\n\n\
    \      b_.resize(N_);\n      for(int i = 0; i < N_; ++i){\n        b_[i] = std::lower_bound(D_.begin(),\
    \ D_.end(), a_[i]) - D_.begin();\n      }\n\n      K_ = D_.size();\n\n      index_.resize(K_);\n\
    \      b_index_.resize(N_);\n      for(int i = 0; i < N_; ++i){\n        b_index_[i]\
    \ = index_[b_[i]].size();\n        index_[b_[i]].push_back(i);\n      }\n\n  \
    \    for(int i = 0; i < block_num_; ++i){\n        std::vector<int> temp(K_);\n\
    \        int md = 0, fr = 0;\n\n        for(int j = i; j < block_num_; ++j){\n\
    \          int R = std::min(N_, block_size_ * (j + 1));\n          for(int x =\
    \ block_size_ * j; x < R; ++x){\n            temp[b_[x]] += 1;\n\n           \
    \ if(temp[b_[x]] > fr){\n              md = b_[x];\n              fr = temp[b_[x]];\n\
    \            }\n          }\n\n          mode_[i][j] = md;\n          freq_[i][j]\
    \ = fr;\n        }\n      }\n    }\n\n    std::pair<int, T> query(int l, int r){\
    \ // [l, r)\n      std::pair<int, T> ret = std::make_pair(0, 0);\n\n      const\
    \ int span_l = (l + block_size_ - 1) / block_size_, span_r = r / block_size_ -\
    \ 1;\n\n      if(span_l <= span_r){\n        ret = std::make_pair(freq_[span_l][span_r],\
    \ D_[mode_[span_l][span_r]]);\n      }\n\n      // prefix\n      for(int i = l;\
    \ i < std::min(r, span_l * block_size_); ++i){\n        if(b_index_[i] - 1 >=\
    \ 0 and index_[b_[i]][b_index_[i] - 1] >= l) continue;\n\n        if(b_index_[i]\
    \ + ret.first - 1 < 0 or\n           (b_index_[i] + ret.first - 1 < (int)index_[b_[i]].size()\n\
    \            and index_[b_[i]][b_index_[i] + ret.first - 1] < r)){\n         \
    \ int fr = ret.first;\n\n          for(int j = b_index_[i] + ret.first; j < (int)index_[b_[i]].size();\
    \ ++j){\n            if(index_[b_[i]][j] < r) ++fr;\n            else break;\n\
    \          }\n\n          if(fr > ret.first){\n            ret = std::make_pair(fr,\
    \ D_[b_[i]]);\n          }\n        }\n      }\n\n      // suffix\n      for(int\
    \ i = r - 1; i >= std::max(l, (span_r + 1) * block_size_); --i){\n        if(b_index_[i]\
    \ + 1 < (int)index_[b_[i]].size() and index_[b_[i]][b_index_[i] + 1] < r) continue;\n\
    \n        if(b_index_[i] - ret.first + 1 >= (int)index_[b_[i]].size() or\n   \
    \        (b_index_[i] - ret.first + 1 >= 0 and index_[b_[i]][b_index_[i] - ret.first\
    \ + 1] >= l)){\n          int fr = ret.first;\n\n          for(int j = b_index_[i]\
    \ - ret.first; j >= 0; --j){\n            if(index_[b_[i]][j] >= l) ++fr;\n  \
    \          else break;\n          }\n\n          if(fr > ret.first){\n       \
    \     ret = std::make_pair(fr, D_[b_[i]]);\n          }\n        }\n      }\n\n\
    \      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <utility>\n\
    #include <cmath>\n\nnamespace haar_lib {\n  template <typename T>\n  class range_mode_query\
    \ {\n    std::vector<T> a_, D_;\n    std::vector<int> b_, b_index_;\n    int N_,\
    \ block_size_, block_num_, K_;\n    std::vector<std::vector<int>> index_, mode_,\
    \ freq_;\n\n  public:\n    range_mode_query(){}\n    range_mode_query(std::vector<T>\
    \ a):\n      a_(a), D_(a), N_(a.size()), block_size_(std::sqrt(N_)),\n      block_num_((N_\
    \ + block_size_ - 1) / block_size_),\n      mode_(block_num_, std::vector<int>(block_num_)),\n\
    \      freq_(block_num_, std::vector<int>(block_num_))\n    {\n      std::sort(D_.begin(),\
    \ D_.end());\n      D_.erase(std::unique(D_.begin(), D_.end()), D_.end());\n\n\
    \      b_.resize(N_);\n      for(int i = 0; i < N_; ++i){\n        b_[i] = std::lower_bound(D_.begin(),\
    \ D_.end(), a_[i]) - D_.begin();\n      }\n\n      K_ = D_.size();\n\n      index_.resize(K_);\n\
    \      b_index_.resize(N_);\n      for(int i = 0; i < N_; ++i){\n        b_index_[i]\
    \ = index_[b_[i]].size();\n        index_[b_[i]].push_back(i);\n      }\n\n  \
    \    for(int i = 0; i < block_num_; ++i){\n        std::vector<int> temp(K_);\n\
    \        int md = 0, fr = 0;\n\n        for(int j = i; j < block_num_; ++j){\n\
    \          int R = std::min(N_, block_size_ * (j + 1));\n          for(int x =\
    \ block_size_ * j; x < R; ++x){\n            temp[b_[x]] += 1;\n\n           \
    \ if(temp[b_[x]] > fr){\n              md = b_[x];\n              fr = temp[b_[x]];\n\
    \            }\n          }\n\n          mode_[i][j] = md;\n          freq_[i][j]\
    \ = fr;\n        }\n      }\n    }\n\n    std::pair<int, T> query(int l, int r){\
    \ // [l, r)\n      std::pair<int, T> ret = std::make_pair(0, 0);\n\n      const\
    \ int span_l = (l + block_size_ - 1) / block_size_, span_r = r / block_size_ -\
    \ 1;\n\n      if(span_l <= span_r){\n        ret = std::make_pair(freq_[span_l][span_r],\
    \ D_[mode_[span_l][span_r]]);\n      }\n\n      // prefix\n      for(int i = l;\
    \ i < std::min(r, span_l * block_size_); ++i){\n        if(b_index_[i] - 1 >=\
    \ 0 and index_[b_[i]][b_index_[i] - 1] >= l) continue;\n\n        if(b_index_[i]\
    \ + ret.first - 1 < 0 or\n           (b_index_[i] + ret.first - 1 < (int)index_[b_[i]].size()\n\
    \            and index_[b_[i]][b_index_[i] + ret.first - 1] < r)){\n         \
    \ int fr = ret.first;\n\n          for(int j = b_index_[i] + ret.first; j < (int)index_[b_[i]].size();\
    \ ++j){\n            if(index_[b_[i]][j] < r) ++fr;\n            else break;\n\
    \          }\n\n          if(fr > ret.first){\n            ret = std::make_pair(fr,\
    \ D_[b_[i]]);\n          }\n        }\n      }\n\n      // suffix\n      for(int\
    \ i = r - 1; i >= std::max(l, (span_r + 1) * block_size_); --i){\n        if(b_index_[i]\
    \ + 1 < (int)index_[b_[i]].size() and index_[b_[i]][b_index_[i] + 1] < r) continue;\n\
    \n        if(b_index_[i] - ret.first + 1 >= (int)index_[b_[i]].size() or\n   \
    \        (b_index_[i] - ret.first + 1 >= 0 and index_[b_[i]][b_index_[i] - ret.first\
    \ + 1] >= l)){\n          int fr = ret.first;\n\n          for(int j = b_index_[i]\
    \ - ret.first; j >= 0; --j){\n            if(index_[b_[i]][j] >= l) ++fr;\n  \
    \          else break;\n          }\n\n          if(fr > ret.first){\n       \
    \     ret = std::make_pair(fr, D_[b_[i]]);\n          }\n        }\n      }\n\n\
    \      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Typical/range_mode_query.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Typical/range_mode_query.cpp
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
