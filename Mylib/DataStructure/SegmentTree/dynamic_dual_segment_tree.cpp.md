---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_E/main.dynamic.test.cpp
    title: test/aoj/DSL_2_E/main.dynamic.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp\"\
    \n#include <unordered_map>\n\nnamespace haar_lib {\n  template <typename Monoid>\n\
    \  class dynamic_dual_segment_tree {\n  public:\n    using value_type = typename\
    \ Monoid::value_type;\n\n  private:\n    struct node {\n      value_type val;\n\
    \      node *left = nullptr, *right = nullptr;\n      node(const value_type &val)\
    \ : val(val) {}\n    };\n\n    Monoid M_;\n    int64_t depth_, size_, hsize_;\n\
    \    node *root_ = nullptr;\n    std::unordered_map<int64_t, node *> umap_;\n\n\
    \    void propagate(node *t, int64_t l, int64_t r) {\n      if (r - l > 1) {\n\
    \        if (not t->left) t->left = new node(M_());\n        t->left->val = M_(t->val,\
    \ t->left->val);\n\n        if (not t->right) t->right = new node(M_());\n   \
    \     t->right->val = M_(t->val, t->right->val);\n\n        t->val = M_();\n \
    \     }\n    }\n\n    void update(node *t, int64_t l, int64_t r, int64_t x, int64_t\
    \ y, const value_type &val) {\n      if (r - l == 1) {\n        if (x <= l and\
    \ r <= y) t->val = M_(t->val, val);\n        umap_[l] = t;\n        return;\n\
    \      }\n      if (r < x or y < l)\n        return;\n      else if (x <= l and\
    \ r <= y)\n        t->val = M_(t->val, val);\n      else {\n        const int64_t\
    \ m = (l + r) / 2;\n        propagate(t, l, r);\n        update(t->left, l, m,\
    \ x, y, val);\n        update(t->right, m, r, x, y, val);\n      }\n    }\n\n\
    \    void get(node *t, int64_t l, int64_t r, int64_t x) {\n      if (r - l ==\
    \ 1) {\n        umap_[l] = t;\n        return;\n      }\n      propagate(t, l,\
    \ r);\n      int m = (l + r) / 2;\n      if (x < m)\n        get(t->left, l, m,\
    \ x);\n      else\n        get(t->right, m, r, x);\n    }\n\n  public:\n    dynamic_dual_segment_tree()\
    \ {}\n    dynamic_dual_segment_tree(int64_t n) : depth_(n > 1 ? 64 - __builtin_clzll(n\
    \ - 1) + 1 : 1),\n                                           size_(1LL << depth_),\n\
    \                                           hsize_(size_ / 2) {\n      root_ =\
    \ new node(M_());\n    }\n\n    void update(int64_t s, int64_t t, value_type &x)\
    \ {\n      update(root_, 0, hsize_, s, t, x);\n    }\n\n    value_type operator[](int64_t\
    \ x) {\n      get(root_, 0, hsize_, x);\n      return umap_[x]->val;\n    }\n\
    \  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <unordered_map>\n\nnamespace haar_lib {\n  template\
    \ <typename Monoid>\n  class dynamic_dual_segment_tree {\n  public:\n    using\
    \ value_type = typename Monoid::value_type;\n\n  private:\n    struct node {\n\
    \      value_type val;\n      node *left = nullptr, *right = nullptr;\n      node(const\
    \ value_type &val) : val(val) {}\n    };\n\n    Monoid M_;\n    int64_t depth_,\
    \ size_, hsize_;\n    node *root_ = nullptr;\n    std::unordered_map<int64_t,\
    \ node *> umap_;\n\n    void propagate(node *t, int64_t l, int64_t r) {\n    \
    \  if (r - l > 1) {\n        if (not t->left) t->left = new node(M_());\n    \
    \    t->left->val = M_(t->val, t->left->val);\n\n        if (not t->right) t->right\
    \ = new node(M_());\n        t->right->val = M_(t->val, t->right->val);\n\n  \
    \      t->val = M_();\n      }\n    }\n\n    void update(node *t, int64_t l, int64_t\
    \ r, int64_t x, int64_t y, const value_type &val) {\n      if (r - l == 1) {\n\
    \        if (x <= l and r <= y) t->val = M_(t->val, val);\n        umap_[l] =\
    \ t;\n        return;\n      }\n      if (r < x or y < l)\n        return;\n \
    \     else if (x <= l and r <= y)\n        t->val = M_(t->val, val);\n      else\
    \ {\n        const int64_t m = (l + r) / 2;\n        propagate(t, l, r);\n   \
    \     update(t->left, l, m, x, y, val);\n        update(t->right, m, r, x, y,\
    \ val);\n      }\n    }\n\n    void get(node *t, int64_t l, int64_t r, int64_t\
    \ x) {\n      if (r - l == 1) {\n        umap_[l] = t;\n        return;\n    \
    \  }\n      propagate(t, l, r);\n      int m = (l + r) / 2;\n      if (x < m)\n\
    \        get(t->left, l, m, x);\n      else\n        get(t->right, m, r, x);\n\
    \    }\n\n  public:\n    dynamic_dual_segment_tree() {}\n    dynamic_dual_segment_tree(int64_t\
    \ n) : depth_(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),\n                \
    \                           size_(1LL << depth_),\n                          \
    \                 hsize_(size_ / 2) {\n      root_ = new node(M_());\n    }\n\n\
    \    void update(int64_t s, int64_t t, value_type &x) {\n      update(root_, 0,\
    \ hsize_, s, t, x);\n    }\n\n    value_type operator[](int64_t x) {\n      get(root_,\
    \ 0, hsize_, x);\n      return umap_[x]->val;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_E/main.dynamic.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp
layout: document
title: Dynamic dual segment tree
---

## Operations

## Requirements

## Notes

## Problems

## References
