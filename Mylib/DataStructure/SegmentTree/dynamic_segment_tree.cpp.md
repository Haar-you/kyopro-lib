---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/789/main.test.cpp
    title: test/yukicoder/789/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename Monoid>\n \
    \ class dynamic_segment_tree {\n  public:\n    using value_type = typename Monoid::value_type;\n\
    \n  private:\n    struct node {\n      value_type val;\n      node *left = nullptr,\
    \ *right = nullptr;\n      node(const value_type &val) : val(val) {}\n    };\n\
    \n    Monoid M_;\n    int64_t depth_, size_, hsize_;\n    node *root_ = nullptr;\n\
    \n    value_type eval(node *t) const {\n      return t ? t->val : M_();\n    }\n\
    \n    node *update(node *t, int64_t l, int64_t r, int64_t pos, const value_type\
    \ &val) {\n      if (r - l == 1) {\n        if (t)\n          t->val = val;\n\
    \        else\n          t = new node(val);\n      } else {\n        const int64_t\
    \ m = (l + r) / 2;\n        if (not t) t = new node(val);\n        if (pos < m)\n\
    \          t->left = update(t->left, l, m, pos, val);\n        else\n        \
    \  t->right = update(t->right, m, r, pos, val);\n        t->val = M_(eval(t->left),\
    \ eval(t->right));\n      }\n      return t;\n    }\n\n    value_type get(node\
    \ *t, int64_t l, int64_t r, int64_t x, int64_t y) const {\n      if (not t) return\
    \ M_();\n      if (x <= l and r <= y) return t ? t->val : M_();\n      if (r <\
    \ x or y < l) return M_();\n      int64_t m = (l + r) >> 1;\n      return M_(get(t->left,\
    \ l, m, x, y), get(t->right, m, r, x, y));\n    }\n\n  public:\n    dynamic_segment_tree()\
    \ {}\n    dynamic_segment_tree(int64_t n) : depth_(n > 1 ? 64 - __builtin_clzll(n\
    \ - 1) + 1 : 1),\n                                      size_(1LL << depth_),\n\
    \                                      hsize_(size_ / 2) {\n      root_ = new\
    \ node(M_());\n    }\n\n    void set(int64_t i, const value_type &x) {\n     \
    \ update(root_, 0, hsize_, i, x);\n    }\n\n    void update(int64_t i, const value_type\
    \ &x) {\n      set(i, M_((*this)[i], x));\n    }\n\n    value_type fold(int64_t\
    \ l, int64_t r) const {\n      return get(root_, 0, hsize_, l, r);\n    }\n\n\
    \    value_type operator[](int64_t i) const {\n      return fold(i, i + 1);\n\
    \    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class dynamic_segment_tree {\n  public:\n    using value_type = typename\
    \ Monoid::value_type;\n\n  private:\n    struct node {\n      value_type val;\n\
    \      node *left = nullptr, *right = nullptr;\n      node(const value_type &val)\
    \ : val(val) {}\n    };\n\n    Monoid M_;\n    int64_t depth_, size_, hsize_;\n\
    \    node *root_ = nullptr;\n\n    value_type eval(node *t) const {\n      return\
    \ t ? t->val : M_();\n    }\n\n    node *update(node *t, int64_t l, int64_t r,\
    \ int64_t pos, const value_type &val) {\n      if (r - l == 1) {\n        if (t)\n\
    \          t->val = val;\n        else\n          t = new node(val);\n      }\
    \ else {\n        const int64_t m = (l + r) / 2;\n        if (not t) t = new node(val);\n\
    \        if (pos < m)\n          t->left = update(t->left, l, m, pos, val);\n\
    \        else\n          t->right = update(t->right, m, r, pos, val);\n      \
    \  t->val = M_(eval(t->left), eval(t->right));\n      }\n      return t;\n   \
    \ }\n\n    value_type get(node *t, int64_t l, int64_t r, int64_t x, int64_t y)\
    \ const {\n      if (not t) return M_();\n      if (x <= l and r <= y) return\
    \ t ? t->val : M_();\n      if (r < x or y < l) return M_();\n      int64_t m\
    \ = (l + r) >> 1;\n      return M_(get(t->left, l, m, x, y), get(t->right, m,\
    \ r, x, y));\n    }\n\n  public:\n    dynamic_segment_tree() {}\n    dynamic_segment_tree(int64_t\
    \ n) : depth_(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),\n                \
    \                      size_(1LL << depth_),\n                               \
    \       hsize_(size_ / 2) {\n      root_ = new node(M_());\n    }\n\n    void\
    \ set(int64_t i, const value_type &x) {\n      update(root_, 0, hsize_, i, x);\n\
    \    }\n\n    void update(int64_t i, const value_type &x) {\n      set(i, M_((*this)[i],\
    \ x));\n    }\n\n    value_type fold(int64_t l, int64_t r) const {\n      return\
    \ get(root_, 0, hsize_, l, r);\n    }\n\n    value_type operator[](int64_t i)\
    \ const {\n      return fold(i, i + 1);\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/789/main.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp
layout: document
title: Dynamic segment tree
---

## Operations

## Requirements

## Notes

## Problems

## References
