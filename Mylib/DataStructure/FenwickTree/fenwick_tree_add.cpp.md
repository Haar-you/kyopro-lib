---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Mylib/Typical/RangeCountQuery/range_count_query.cpp
    title: Range count query
  - icon: ':x:'
    path: Mylib/Typical/InversionNumber/range_inversions_query.cpp
    title: Range inversions query
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/static_range_inversions_query/main.test.cpp
    title: test/yosupo-judge/static_range_inversions_query/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  class fenwick_tree_add\
    \ {\n    using value_type = T;\n\n    int size;\n    std::vector<value_type> data;\n\
    \n  public:\n    fenwick_tree_add(){}\n    fenwick_tree_add(int size): size(size),\
    \ data(size + 1, 0){}\n\n    void update(int i, value_type val){\n      i += 1;\
    \ // 1-index\n\n      while(i <= size){\n        data[i] = data[i] + val;\n  \
    \      i += i & (-i);\n      }\n    }\n\n    value_type fold(int i) const { //\
    \ [0, i)\n      value_type ret = 0;\n\n      while(i > 0){\n        ret = ret\
    \ + data[i];\n        i -= i & (-i);\n      }\n\n      return ret;\n    }\n\n\
    \    value_type fold(int l, int r) const { // [l, r)\n      return fold(r) - fold(l);\n\
    \    }\n\n    value_type operator[](int x) const {\n      return fold(x, x + 1);\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class fenwick_tree_add {\n    using value_type = T;\n\n    int size;\n\
    \    std::vector<value_type> data;\n\n  public:\n    fenwick_tree_add(){}\n  \
    \  fenwick_tree_add(int size): size(size), data(size + 1, 0){}\n\n    void update(int\
    \ i, value_type val){\n      i += 1; // 1-index\n\n      while(i <= size){\n \
    \       data[i] = data[i] + val;\n        i += i & (-i);\n      }\n    }\n\n \
    \   value_type fold(int i) const { // [0, i)\n      value_type ret = 0;\n\n  \
    \    while(i > 0){\n        ret = ret + data[i];\n        i -= i & (-i);\n   \
    \   }\n\n      return ret;\n    }\n\n    value_type fold(int l, int r) const {\
    \ // [l, r)\n      return fold(r) - fold(l);\n    }\n\n    value_type operator[](int\
    \ x) const {\n      return fold(x, x + 1);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
  requiredBy:
  - Mylib/Typical/RangeCountQuery/range_count_query.cpp
  - Mylib/Typical/InversionNumber/range_inversions_query.cpp
  timestamp: '2020-09-26 08:06:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/static_range_inversions_query/main.test.cpp
documentation_of: Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
layout: document
title: Fenwick tree (Add)
---

## Operations

## Requirements

## Notes

## Problems

## References
