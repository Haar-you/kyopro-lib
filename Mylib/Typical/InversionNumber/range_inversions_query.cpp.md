---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
    title: Fenwick tree (Add)
  - icon: ':question:'
    path: Mylib/Algorithm/Mo/mo_algorithm.cpp
    title: Mo's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/static_range_inversions_query/main.test.cpp
    title: test/yosupo-judge/static_range_inversions_query/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Typical/InversionNumber/range_inversions_query.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <algorithm>\n#line 3 \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class fenwick_tree_add {\n\
    \    using value_type = T;\n\n    int size;\n    std::vector<value_type> data;\n\
    \n  public:\n    fenwick_tree_add(){}\n    fenwick_tree_add(int size): size(size),\
    \ data(size + 1, 0){}\n\n    void update(int i, value_type val){\n      i += 1;\
    \ // 1-index\n\n      while(i <= size){\n        data[i] = data[i] + val;\n  \
    \      i += i & (-i);\n      }\n    }\n\n    value_type fold(int i) const { //\
    \ [0, i)\n      value_type ret = 0;\n\n      while(i > 0){\n        ret = ret\
    \ + data[i];\n        i -= i & (-i);\n      }\n\n      return ret;\n    }\n\n\
    \    value_type fold(int l, int r) const { // [l, r)\n      return fold(r) - fold(l);\n\
    \    }\n\n    value_type operator[](int x) const {\n      return fold(x, x + 1);\n\
    \    }\n  };\n}\n#line 4 \"Mylib/Algorithm/Mo/mo_algorithm.cpp\"\n#include <cassert>\n\
    #include <cmath>\n\nnamespace haar_lib {\n  template <typename AppendLeft, typename\
    \ AppendRight, typename RemoveLeft, typename RemoveRight, typename Query>\n  class\
    \ mo_algorithm {\n    int N, Q, index, width;\n    std::vector<int> left, right,\
    \ ord;\n\n    const AppendLeft append_left;\n    const AppendRight append_right;\n\
    \    const RemoveLeft remove_left;\n    const RemoveRight remove_right;\n    const\
    \ Query query;\n\n    bool is_built = false;\n\n  public:\n    mo_algorithm(\n\
    \      int N, int Q,\n      const AppendLeft &append_left, const AppendRight &append_right,\n\
    \      const RemoveLeft &remove_left, const RemoveRight &remove_right,\n     \
    \ const Query &query\n    ):\n      N(N), Q(Q), index(0), width(std::sqrt(N)),\n\
    \      left(Q), right(Q), ord(Q),\n      append_left(append_left), append_right(append_right),\n\
    \      remove_left(remove_left), remove_right(remove_right),\n      query(query)\n\
    \    {}\n\n    // [l, r)\n    void add(int l, int r){\n      left[index] = l;\n\
    \      right[index] = r;\n      ord[index] = index;\n      ++index;\n    }\n\n\
    \    void run(){\n      std::sort(\n        ord.begin(), ord.end(),\n        [&](int\
    \ i, int j){\n          const int a = left[i] / width, b = left[j] / width;\n\
    \          if(a == b){\n            if(a & 1) return right[i] < right[j];\n  \
    \          else return right[i] > right[j];\n          }else{\n            return\
    \ a < b;\n          }\n        }\n      );\n\n      int q = 0;\n      int l =\
    \ left[ord[0]], r = left[ord[0]];\n\n      for(int i = 0; i < Q; ++i){\n     \
    \   int id = ord[q++];\n\n        while(l != left[id] or r != right[id]){\n  \
    \        if(l > left[id]) append_left(--l);\n          if(l < left[id]) remove_left(l++);\n\
    \          if(r < right[id]) append_right(r++);\n          if(r > right[id]) remove_right(--r);\n\
    \        }\n\n        query(id);\n      }\n    }\n  };\n}\n#line 7 \"Mylib/Typical/InversionNumber/range_inversions_query.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class range_inversions_query\
    \ {\n    std::vector<int> a;\n    int N;\n    std::vector<std::pair<int, int>>\
    \ qs;\n\n  public:\n    range_inversions_query(std::vector<T> a_): N(a_.size()){\n\
    \      auto b = a_;\n      std::sort(b.begin(), b.end());\n      b.erase(std::unique(b.begin(),\
    \ b.end()), b.end());\n\n      for(auto x : a_){\n        const int i = std::lower_bound(b.begin(),\
    \ b.end(), x) - b.begin();\n        a.push_back(i);\n      }\n    }\n\n    void\
    \ add(int l, int r){ // [l, r)\n      qs.emplace_back(l, r);\n    }\n\n    auto\
    \ solve(){\n      const int Q = qs.size();\n      fenwick_tree_add<int64_t> b(N);\n\
    \n      int64_t t = 0;\n      std::vector<int64_t> ans(Q);\n\n      auto append_left\
    \ =\n        [&](int i){\n          t += b.fold(0, a[i]);\n          b.update(a[i],\
    \ 1);\n        };\n\n      auto append_right =\n        [&](int i){\n        \
    \  t += b.fold(a[i] + 1, N);\n          b.update(a[i], 1);\n        };\n\n   \
    \   auto remove_left =\n        [&](int i){\n          t -= b.fold(0, a[i]);\n\
    \          b.update(a[i], -1);\n        };\n\n      auto remove_right =\n    \
    \    [&](int i){\n          t -= b.fold(a[i] + 1, N);\n          b.update(a[i],\
    \ -1);\n        };\n\n      auto query = [&](int i){ans[i] = t;};\n\n      auto\
    \ mo =\n        mo_algorithm(\n          N, Q, append_left, append_right, remove_left,\
    \ remove_right, query\n        );\n\n      for(auto [l, r] : qs){\n        mo.add(l,\
    \ r);\n      }\n\n      mo.run();\n\n      return ans;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\n#include \"\
    Mylib/Algorithm/Mo/mo_algorithm.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class range_inversions_query {\n    std::vector<int> a;\n    int N;\n\
    \    std::vector<std::pair<int, int>> qs;\n\n  public:\n    range_inversions_query(std::vector<T>\
    \ a_): N(a_.size()){\n      auto b = a_;\n      std::sort(b.begin(), b.end());\n\
    \      b.erase(std::unique(b.begin(), b.end()), b.end());\n\n      for(auto x\
    \ : a_){\n        const int i = std::lower_bound(b.begin(), b.end(), x) - b.begin();\n\
    \        a.push_back(i);\n      }\n    }\n\n    void add(int l, int r){ // [l,\
    \ r)\n      qs.emplace_back(l, r);\n    }\n\n    auto solve(){\n      const int\
    \ Q = qs.size();\n      fenwick_tree_add<int64_t> b(N);\n\n      int64_t t = 0;\n\
    \      std::vector<int64_t> ans(Q);\n\n      auto append_left =\n        [&](int\
    \ i){\n          t += b.fold(0, a[i]);\n          b.update(a[i], 1);\n       \
    \ };\n\n      auto append_right =\n        [&](int i){\n          t += b.fold(a[i]\
    \ + 1, N);\n          b.update(a[i], 1);\n        };\n\n      auto remove_left\
    \ =\n        [&](int i){\n          t -= b.fold(0, a[i]);\n          b.update(a[i],\
    \ -1);\n        };\n\n      auto remove_right =\n        [&](int i){\n       \
    \   t -= b.fold(a[i] + 1, N);\n          b.update(a[i], -1);\n        };\n\n \
    \     auto query = [&](int i){ans[i] = t;};\n\n      auto mo =\n        mo_algorithm(\n\
    \          N, Q, append_left, append_right, remove_left, remove_right, query\n\
    \        );\n\n      for(auto [l, r] : qs){\n        mo.add(l, r);\n      }\n\n\
    \      mo.run();\n\n      return ans;\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
  - Mylib/Algorithm/Mo/mo_algorithm.cpp
  isVerificationFile: false
  path: Mylib/Typical/InversionNumber/range_inversions_query.cpp
  requiredBy: []
  timestamp: '2020-09-26 08:06:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/static_range_inversions_query/main.test.cpp
documentation_of: Mylib/Typical/InversionNumber/range_inversions_query.cpp
layout: document
title: Range inversions query
---

## Operations

## Requirements

## Notes

## Problems

## References
