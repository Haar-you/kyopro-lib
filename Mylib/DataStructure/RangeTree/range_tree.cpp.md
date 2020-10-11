---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C/main.test.cpp
    title: test/aoj/DSL_2_C/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/RangeTree/range_tree.cpp\"\n#include\
    \ <vector>\n#include <utility>\n#include <algorithm>\n#include <iterator>\n\n\
    namespace haar_lib {\n  class range_tree {\n    int N_ = 0, size_;\n    std::vector<int64_t>\
    \ xs_, ys_, c_xs_;\n    std::vector<std::vector<std::pair<int64_t, int>>> data_;\n\
    \n  public:\n    range_tree(){}\n\n    void add(int64_t x, int64_t y){\n     \
    \ ++N_;\n      xs_.push_back(x);\n      ys_.push_back(y);\n    }\n\n    void build(){\n\
    \      c_xs_ = xs_;\n      std::sort(c_xs_.begin(), c_xs_.end());\n      c_xs_.erase(std::unique(c_xs_.begin(),\
    \ c_xs_.end()), c_xs_.end());\n\n      int M = c_xs_.size();\n      size_ = 1\
    \ << (M > 1 ? 32 - __builtin_clz(M - 1) + 1 : 1);\n\n      data_.resize(size_);\n\
    \n      for(int i = 0; i < N_; ++i){\n        int j = std::lower_bound(c_xs_.begin(),\
    \ c_xs_.end(), xs_[i]) - c_xs_.begin();\n        data_[size_ / 2 + j].emplace_back(ys_[i],\
    \ j);\n      }\n\n      for(int i = size_ / 2; i < size_; ++i){\n        std::sort(data_[i].begin(),\
    \ data_[i].end());\n      }\n\n      for(int i = size_ / 2 - 1; i > 0; --i){\n\
    \        auto &a = data_[i << 1 | 0];\n        auto &b = data_[i << 1 | 1];\n\n\
    \        std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(data_[i]));\n\
    \      }\n    }\n\n    /**\n     * @attention [sx, tx), [sy, ty)\n     */\n  \
    \  std::vector<std::pair<int64_t, int64_t>> get(int64_t sx, int64_t sy, int64_t\
    \ tx, int64_t ty) const {\n      std::vector<std::pair<int64_t, int64_t>> ret;\n\
    \n      int L = std::lower_bound(c_xs_.begin(), c_xs_.end(), sx) - c_xs_.begin();\n\
    \      int R = std::lower_bound(c_xs_.begin(), c_xs_.end(), tx) - c_xs_.begin();\n\
    \n      L += size_ / 2;\n      R += size_ / 2;\n\n      while(L < R){\n      \
    \  if(R & 1){\n          auto &a = data_[--R];\n\n          auto it = std::lower_bound(a.begin(),\
    \ a.end(), std::make_pair(sy, 0));\n\n          while(it != a.end()){\n      \
    \      if(it->first >= ty) break;\n\n            ret.emplace_back(c_xs_[it->second],\
    \ it->first);\n\n            ++it;\n          }\n        }\n\n        if(L & 1){\n\
    \          auto &a = data_[L++];\n\n          auto it = std::lower_bound(a.begin(),\
    \ a.end(), std::make_pair(sy, 0));\n\n          while(it != a.end()){\n      \
    \      if(it->first >= ty) break;\n\n            ret.emplace_back(c_xs_[it->second],\
    \ it->first);\n\n            ++it;\n          }\n        }\n\n        L >>= 1;\n\
    \        R >>= 1;\n      }\n\n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <iterator>\n\nnamespace haar_lib {\n  class range_tree {\n    int N_\
    \ = 0, size_;\n    std::vector<int64_t> xs_, ys_, c_xs_;\n    std::vector<std::vector<std::pair<int64_t,\
    \ int>>> data_;\n\n  public:\n    range_tree(){}\n\n    void add(int64_t x, int64_t\
    \ y){\n      ++N_;\n      xs_.push_back(x);\n      ys_.push_back(y);\n    }\n\n\
    \    void build(){\n      c_xs_ = xs_;\n      std::sort(c_xs_.begin(), c_xs_.end());\n\
    \      c_xs_.erase(std::unique(c_xs_.begin(), c_xs_.end()), c_xs_.end());\n\n\
    \      int M = c_xs_.size();\n      size_ = 1 << (M > 1 ? 32 - __builtin_clz(M\
    \ - 1) + 1 : 1);\n\n      data_.resize(size_);\n\n      for(int i = 0; i < N_;\
    \ ++i){\n        int j = std::lower_bound(c_xs_.begin(), c_xs_.end(), xs_[i])\
    \ - c_xs_.begin();\n        data_[size_ / 2 + j].emplace_back(ys_[i], j);\n  \
    \    }\n\n      for(int i = size_ / 2; i < size_; ++i){\n        std::sort(data_[i].begin(),\
    \ data_[i].end());\n      }\n\n      for(int i = size_ / 2 - 1; i > 0; --i){\n\
    \        auto &a = data_[i << 1 | 0];\n        auto &b = data_[i << 1 | 1];\n\n\
    \        std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(data_[i]));\n\
    \      }\n    }\n\n    /**\n     * @attention [sx, tx), [sy, ty)\n     */\n  \
    \  std::vector<std::pair<int64_t, int64_t>> get(int64_t sx, int64_t sy, int64_t\
    \ tx, int64_t ty) const {\n      std::vector<std::pair<int64_t, int64_t>> ret;\n\
    \n      int L = std::lower_bound(c_xs_.begin(), c_xs_.end(), sx) - c_xs_.begin();\n\
    \      int R = std::lower_bound(c_xs_.begin(), c_xs_.end(), tx) - c_xs_.begin();\n\
    \n      L += size_ / 2;\n      R += size_ / 2;\n\n      while(L < R){\n      \
    \  if(R & 1){\n          auto &a = data_[--R];\n\n          auto it = std::lower_bound(a.begin(),\
    \ a.end(), std::make_pair(sy, 0));\n\n          while(it != a.end()){\n      \
    \      if(it->first >= ty) break;\n\n            ret.emplace_back(c_xs_[it->second],\
    \ it->first);\n\n            ++it;\n          }\n        }\n\n        if(L & 1){\n\
    \          auto &a = data_[L++];\n\n          auto it = std::lower_bound(a.begin(),\
    \ a.end(), std::make_pair(sy, 0));\n\n          while(it != a.end()){\n      \
    \      if(it->first >= ty) break;\n\n            ret.emplace_back(c_xs_[it->second],\
    \ it->first);\n\n            ++it;\n          }\n        }\n\n        L >>= 1;\n\
    \        R >>= 1;\n      }\n\n      return ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/RangeTree/range_tree.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_C/main.test.cpp
documentation_of: Mylib/DataStructure/RangeTree/range_tree.cpp
layout: document
title: Range tree
---

## Operations

- `add(int x, int y)`
	- 点`(x, y)`を追加する。
- `build()`
	- `RangeTree`を構築する。
	- Time complexity $O(N \log N)$
- `get(int sx, int sy, int tx, int ty)`
	- `[sx, tx), [sy, ty)`内の点を列挙する。
	- Time complexity $O(\log^2 N + K)$

## Requirements

- `build`は唯一回だけ呼び出される。
- 必ず`add`, `build`, `get`の順で実行する。

## Notes

## Problems

- [AOJ DSL_2_C Range Search (kD Tree)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)

## References
