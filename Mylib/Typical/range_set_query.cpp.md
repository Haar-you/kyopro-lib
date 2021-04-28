---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
    title: Fenwick tree (Add)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/range_set_query.cpp\"\n#include <algorithm>\n\
    #include <tuple>\n#include <vector>\n#line 2 \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\
    \n#include <cassert>\n#line 4 \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class fenwick_tree_add {\n\
    \  public:\n    using value_type = T;\n\n  private:\n    int size_;\n    std::vector<value_type>\
    \ data_;\n\n  public:\n    fenwick_tree_add() {}\n    fenwick_tree_add(int size)\
    \ : size_(size), data_(size + 1, 0) {}\n\n    void update(int i, value_type val)\
    \ {\n      assert(0 <= i and i < size_);\n      i += 1;  // 1-index\n\n      while\
    \ (i <= size_) {\n        data_[i] = data_[i] + val;\n        i += i & (-i);\n\
    \      }\n    }\n\n    value_type fold(int i) const {  // [0, i)\n      assert(0\
    \ <= i and i <= size_);\n      value_type ret = 0;\n\n      while (i > 0) {\n\
    \        ret = ret + data_[i];\n        i -= i & (-i);\n      }\n\n      return\
    \ ret;\n    }\n\n    value_type fold(int l, int r) const {  // [l, r)\n      assert(0\
    \ <= l and l <= r and r <= size_);\n      return fold(r) - fold(l);\n    }\n\n\
    \    value_type operator[](int x) const {\n      return fold(x, x + 1);\n    }\n\
    \  };\n}  // namespace haar_lib\n#line 6 \"Mylib/Typical/range_set_query.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class range_set_query {\n\
    \    std::vector<int> a_;\n    std::vector<std::tuple<int, int, int>> qs_;\n \
    \   int N_;\n\n  public:\n    range_set_query() {}\n    range_set_query(std::vector<T>\
    \ a) : N_(a.size()) {\n      auto temp = a;\n      std::sort(temp.begin(), temp.end());\n\
    \      temp.erase(std::unique(temp.begin(), temp.end()), temp.end());\n\n    \
    \  for (auto x : a) {\n        const int i = std::lower_bound(temp.begin(), temp.end(),\
    \ x) - temp.begin();\n        a_.push_back(i);\n      }\n    }\n\n    void add(int\
    \ l, int r) {  // [l, r)\n      const int i = qs_.size();\n      qs_.emplace_back(r,\
    \ l, i);\n    }\n\n    auto solve() {\n      std::sort(qs_.begin(), qs_.end());\n\
    \n      fenwick_tree_add<int> b(N_);\n\n      const int Q = qs_.size();\n    \
    \  std::vector<int> last_index(N_, -1), ret(Q);\n\n      int cur = 0;\n      for\
    \ (auto [r, l, i] : qs_) {\n        while (cur < r) {\n          if (last_index[a_[cur]]\
    \ != -1) {\n            b.update(last_index[a_[cur]], -1);\n          }\n\n  \
    \        last_index[a_[cur]] = cur;\n          b.update(last_index[a_[cur]], 1);\n\
    \n          ++cur;\n        }\n\n        ret[i] = b.fold(l, r);\n      }\n\n \
    \     return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <tuple>\n#include <vector>\n\
    #include \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class range_set_query {\n    std::vector<int>\
    \ a_;\n    std::vector<std::tuple<int, int, int>> qs_;\n    int N_;\n\n  public:\n\
    \    range_set_query() {}\n    range_set_query(std::vector<T> a) : N_(a.size())\
    \ {\n      auto temp = a;\n      std::sort(temp.begin(), temp.end());\n      temp.erase(std::unique(temp.begin(),\
    \ temp.end()), temp.end());\n\n      for (auto x : a) {\n        const int i =\
    \ std::lower_bound(temp.begin(), temp.end(), x) - temp.begin();\n        a_.push_back(i);\n\
    \      }\n    }\n\n    void add(int l, int r) {  // [l, r)\n      const int i\
    \ = qs_.size();\n      qs_.emplace_back(r, l, i);\n    }\n\n    auto solve() {\n\
    \      std::sort(qs_.begin(), qs_.end());\n\n      fenwick_tree_add<int> b(N_);\n\
    \n      const int Q = qs_.size();\n      std::vector<int> last_index(N_, -1),\
    \ ret(Q);\n\n      int cur = 0;\n      for (auto [r, l, i] : qs_) {\n        while\
    \ (cur < r) {\n          if (last_index[a_[cur]] != -1) {\n            b.update(last_index[a_[cur]],\
    \ -1);\n          }\n\n          last_index[a_[cur]] = cur;\n          b.update(last_index[a_[cur]],\
    \ 1);\n\n          ++cur;\n        }\n\n        ret[i] = b.fold(l, r);\n     \
    \ }\n\n      return ret;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
  isVerificationFile: false
  path: Mylib/Typical/range_set_query.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Typical/range_set_query.cpp
layout: document
title: Range set query
---

## Operations

区間に含まれる要素の種類数を求めるクエリを処理する。

## Requirements

## Notes

## Problems

- [SPOJ DQUERY](https://www.spoj.com/problems/DQUERY/)
- [ABC174 F - Range Set Query](https://atcoder.jp/contests/abc174/tasks/abc174_f)

## References

- [https://hama-du-competitive.hatenablog.com/entry/2016/10/01/001418](https://hama-du-competitive.hatenablog.com/entry/2016/10/01/001418)
