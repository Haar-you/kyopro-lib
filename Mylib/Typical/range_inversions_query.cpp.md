---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Algorithm/Mo/mo_algorithm.cpp
    title: Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
    title: Fenwick tree (Add)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/static_range_inversions_query/main.test.cpp
    title: test/yosupo-judge/static_range_inversions_query/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/range_inversions_query.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <algorithm>\n#line 3 \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\
    \n#include <cassert>\n\nnamespace haar_lib {\n  template <typename T>\n  class\
    \ fenwick_tree_add {\n  public:\n    using value_type = T;\n\n  private:\n   \
    \ int size_;\n    std::vector<value_type> data_;\n\n  public:\n    fenwick_tree_add(){}\n\
    \    fenwick_tree_add(int size): size_(size), data_(size + 1, 0){}\n\n    void\
    \ update(int i, value_type val){\n      assert(0 <= i and i < size_);\n      i\
    \ += 1; // 1-index\n\n      while(i <= size_){\n        data_[i] = data_[i] +\
    \ val;\n        i += i & (-i);\n      }\n    }\n\n    value_type fold(int i) const\
    \ { // [0, i)\n      assert(0 <= i and i <= size_);\n      value_type ret = 0;\n\
    \n      while(i > 0){\n        ret = ret + data_[i];\n        i -= i & (-i);\n\
    \      }\n\n      return ret;\n    }\n\n    value_type fold(int l, int r) const\
    \ { // [l, r)\n      assert(0 <= l and l <= r and r <= size_);\n      return fold(r)\
    \ - fold(l);\n    }\n\n    value_type operator[](int x) const {\n      return\
    \ fold(x, x + 1);\n    }\n  };\n}\n#line 5 \"Mylib/Algorithm/Mo/mo_algorithm.cpp\"\
    \n#include <cmath>\n\nnamespace haar_lib {\n  template <typename AppendLeft, typename\
    \ AppendRight, typename RemoveLeft, typename RemoveRight, typename Query>\n  class\
    \ mo_algorithm {\n    int N_, Q_, index_, width_;\n    std::vector<int> left_,\
    \ right_, ord_;\n\n    AppendLeft append_left_;\n    AppendRight append_right_;\n\
    \    RemoveLeft remove_left_;\n    RemoveRight remove_right_;\n    Query query_;\n\
    \n    bool is_built_ = false;\n\n  public:\n    mo_algorithm(){}\n    mo_algorithm(\n\
    \      int N, int Q,\n      const AppendLeft &append_left, const AppendRight &append_right,\n\
    \      const RemoveLeft &remove_left, const RemoveRight &remove_right,\n     \
    \ const Query &query\n    ):\n      N_(N), Q_(Q), index_(0), width_(std::sqrt(N)),\n\
    \      left_(Q), right_(Q), ord_(Q),\n      append_left_(append_left), append_right_(append_right),\n\
    \      remove_left_(remove_left), remove_right_(remove_right),\n      query_(query)\n\
    \    {}\n\n    // [l, r)\n    void add(int l, int r){\n      left_[index_] = l;\n\
    \      right_[index_] = r;\n      ord_[index_] = index_;\n      ++index_;\n  \
    \  }\n\n    void run(){\n      std::sort(\n        ord_.begin(), ord_.end(),\n\
    \        [&](int i, int j){\n          const int a = left_[i] / width_, b = left_[j]\
    \ / width_;\n          if(a == b){\n            if(a & 1) return right_[i] < right_[j];\n\
    \            else return right_[i] > right_[j];\n          }else{\n          \
    \  return a < b;\n          }\n        }\n      );\n\n      int q = 0;\n     \
    \ int l = left_[ord_[0]], r = left_[ord_[0]];\n\n      for(int i = 0; i < Q_;\
    \ ++i){\n        int id = ord_[q++];\n\n        while(l != left_[id] or r != right_[id]){\n\
    \          if(l > left_[id]) append_left_(--l);\n          if(l < left_[id]) remove_left_(l++);\n\
    \          if(r < right_[id]) append_right_(r++);\n          if(r > right_[id])\
    \ remove_right_(--r);\n        }\n\n        query_(id);\n      }\n    }\n  };\n\
    }\n#line 7 \"Mylib/Typical/range_inversions_query.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  class range_inversions_query {\n    std::vector<int>\
    \ data_;\n    int N_;\n    std::vector<std::pair<int, int>> qs_;\n\n  public:\n\
    \    range_inversions_query(){}\n    range_inversions_query(std::vector<T> a):\
    \ N_(a.size()){\n      auto b = a;\n      std::sort(b.begin(), b.end());\n   \
    \   b.erase(std::unique(b.begin(), b.end()), b.end());\n\n      for(auto x : a){\n\
    \        const int i = std::lower_bound(b.begin(), b.end(), x) - b.begin();\n\
    \        data_.push_back(i);\n      }\n    }\n\n    void add(int l, int r){ //\
    \ [l, r)\n      qs_.emplace_back(l, r);\n    }\n\n    auto solve(){\n      const\
    \ int Q = qs_.size();\n      fenwick_tree_add<int64_t> b(N_);\n\n      int64_t\
    \ t = 0;\n      std::vector<int64_t> ans(Q);\n\n      auto append_left =\n   \
    \     [&](int i){\n          t += b.fold(0, data_[i]);\n          b.update(data_[i],\
    \ 1);\n        };\n\n      auto append_right =\n        [&](int i){\n        \
    \  t += b.fold(data_[i] + 1, N_);\n          b.update(data_[i], 1);\n        };\n\
    \n      auto remove_left =\n        [&](int i){\n          t -= b.fold(0, data_[i]);\n\
    \          b.update(data_[i], -1);\n        };\n\n      auto remove_right =\n\
    \        [&](int i){\n          t -= b.fold(data_[i] + 1, N_);\n          b.update(data_[i],\
    \ -1);\n        };\n\n      auto query = [&](int i){ans[i] = t;};\n\n      auto\
    \ mo =\n        mo_algorithm(\n          N_, Q, append_left, append_right, remove_left,\
    \ remove_right, query\n        );\n\n      for(auto [l, r] : qs_){\n        mo.add(l,\
    \ r);\n      }\n\n      mo.run();\n\n      return ans;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\n#include \"\
    Mylib/Algorithm/Mo/mo_algorithm.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class range_inversions_query {\n    std::vector<int> data_;\n    int N_;\n\
    \    std::vector<std::pair<int, int>> qs_;\n\n  public:\n    range_inversions_query(){}\n\
    \    range_inversions_query(std::vector<T> a): N_(a.size()){\n      auto b = a;\n\
    \      std::sort(b.begin(), b.end());\n      b.erase(std::unique(b.begin(), b.end()),\
    \ b.end());\n\n      for(auto x : a){\n        const int i = std::lower_bound(b.begin(),\
    \ b.end(), x) - b.begin();\n        data_.push_back(i);\n      }\n    }\n\n  \
    \  void add(int l, int r){ // [l, r)\n      qs_.emplace_back(l, r);\n    }\n\n\
    \    auto solve(){\n      const int Q = qs_.size();\n      fenwick_tree_add<int64_t>\
    \ b(N_);\n\n      int64_t t = 0;\n      std::vector<int64_t> ans(Q);\n\n     \
    \ auto append_left =\n        [&](int i){\n          t += b.fold(0, data_[i]);\n\
    \          b.update(data_[i], 1);\n        };\n\n      auto append_right =\n \
    \       [&](int i){\n          t += b.fold(data_[i] + 1, N_);\n          b.update(data_[i],\
    \ 1);\n        };\n\n      auto remove_left =\n        [&](int i){\n         \
    \ t -= b.fold(0, data_[i]);\n          b.update(data_[i], -1);\n        };\n\n\
    \      auto remove_right =\n        [&](int i){\n          t -= b.fold(data_[i]\
    \ + 1, N_);\n          b.update(data_[i], -1);\n        };\n\n      auto query\
    \ = [&](int i){ans[i] = t;};\n\n      auto mo =\n        mo_algorithm(\n     \
    \     N_, Q, append_left, append_right, remove_left, remove_right, query\n   \
    \     );\n\n      for(auto [l, r] : qs_){\n        mo.add(l, r);\n      }\n\n\
    \      mo.run();\n\n      return ans;\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
  - Mylib/Algorithm/Mo/mo_algorithm.cpp
  isVerificationFile: false
  path: Mylib/Typical/range_inversions_query.cpp
  requiredBy: []
  timestamp: '2020-11-07 03:03:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-judge/static_range_inversions_query/main.test.cpp
documentation_of: Mylib/Typical/range_inversions_query.cpp
layout: document
title: Range inversions query
---

## Operations

## Requirements

## Notes

## Problems

## References
