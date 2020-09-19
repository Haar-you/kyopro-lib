---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
    title: Fenwick tree (Add)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Algorithm/Query/range_count_query.cpp\"\n#include\
    \ <vector>\n#include <tuple>\n#include <algorithm>\n#line 3 \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class fenwick_tree_add {\n\
    \    using value_type = T;\n\n    int size;\n    std::vector<value_type> data;\n\
    \n  public:\n    fenwick_tree_add(){}\n    fenwick_tree_add(int size): size(size),\
    \ data(size + 1, 0){}\n\n    void update(int i, value_type val){\n      i += 1;\
    \ // 1-index\n\n      while(i <= size){\n        data[i] = data[i] + val;\n  \
    \      i += i & (-i);\n      }\n    }\n\n    value_type get(int i) const { //\
    \ [0, i)\n      value_type ret = 0;\n      i += 1; // 1-index\n\n      while(i\
    \ > 0){\n        ret = ret + data[i];\n        i -= i & (-i);\n      }\n\n   \
    \   return ret;\n    }\n\n    value_type get(int l, int r) const { // [l, r)\n\
    \      return get(r - 1) - get(l - 1);\n    }\n  };\n}\n#line 6 \"Mylib/Algorithm/Query/range_count_query.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct range_count_query\
    \ {\n    std::vector<int> a;\n    std::vector<std::tuple<int, int, int>> qs;\n\
    \    int N;\n\n    range_count_query(std::vector<T> a_): N(a_.size()){\n     \
    \ auto temp = a_;\n      std::sort(temp.begin(), temp.end());\n      temp.erase(std::unique(temp.begin(),\
    \ temp.end()), temp.end());\n\n      for(auto x : a_){\n        int i = std::lower_bound(temp.begin(),\
    \ temp.end(), x) - temp.begin();\n        a.push_back(i);\n      }\n    }\n\n\
    \    void add(int l, int r){ // [l, r)\n      const int i = qs.size();\n     \
    \ qs.emplace_back(r, l, i);\n    }\n\n    auto solve(){\n      std::sort(qs.begin(),\
    \ qs.end());\n\n      fenwick_tree_add<int> b(N);\n\n      const int Q = qs.size();\n\
    \      std::vector<int> last_index(N, -1);\n      std::vector<int> ret(Q);\n\n\
    \      int cur = 0;\n      for(auto [r, l, i] : qs){\n        while(cur < r){\n\
    \          if(last_index[a[cur]] != -1){\n            b.update(last_index[a[cur]],\
    \ -1);\n          }\n\n          last_index[a[cur]] = cur;\n          b.update(last_index[a[cur]],\
    \ 1);\n\n          ++cur;\n        }\n\n        ret[i] = b.get(l, r);\n      }\n\
    \n      return ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <tuple>\n#include <algorithm>\n\
    #include \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct range_count_query {\n    std::vector<int>\
    \ a;\n    std::vector<std::tuple<int, int, int>> qs;\n    int N;\n\n    range_count_query(std::vector<T>\
    \ a_): N(a_.size()){\n      auto temp = a_;\n      std::sort(temp.begin(), temp.end());\n\
    \      temp.erase(std::unique(temp.begin(), temp.end()), temp.end());\n\n    \
    \  for(auto x : a_){\n        int i = std::lower_bound(temp.begin(), temp.end(),\
    \ x) - temp.begin();\n        a.push_back(i);\n      }\n    }\n\n    void add(int\
    \ l, int r){ // [l, r)\n      const int i = qs.size();\n      qs.emplace_back(r,\
    \ l, i);\n    }\n\n    auto solve(){\n      std::sort(qs.begin(), qs.end());\n\
    \n      fenwick_tree_add<int> b(N);\n\n      const int Q = qs.size();\n      std::vector<int>\
    \ last_index(N, -1);\n      std::vector<int> ret(Q);\n\n      int cur = 0;\n \
    \     for(auto [r, l, i] : qs){\n        while(cur < r){\n          if(last_index[a[cur]]\
    \ != -1){\n            b.update(last_index[a[cur]], -1);\n          }\n\n    \
    \      last_index[a[cur]] = cur;\n          b.update(last_index[a[cur]], 1);\n\
    \n          ++cur;\n        }\n\n        ret[i] = b.get(l, r);\n      }\n\n  \
    \    return ret;\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
  isVerificationFile: false
  path: Mylib/Algorithm/Query/range_count_query.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/Algorithm/Query/range_count_query.cpp
layout: document
title: Range count query
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
