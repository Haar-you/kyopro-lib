---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_E/main.dynamic.test.cpp
    title: test/aoj/DSL_2_E/main.dynamic.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp\"\
    \n#include <unordered_map>\n\nnamespace haar_lib {\n  template <typename Monoid>\n\
    \  class dynamic_dual_segment_tree {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    struct node {\n      value_type val;\n    \
    \  node *left = nullptr, *right = nullptr;\n      node(const value_type &val):\
    \ val(val) {}\n    };\n\n    const int64_t depth, size, hsize;\n    node *root\
    \ = nullptr;\n    std::unordered_map<int64_t, node*> umap;\n\n    void propagate(node\
    \ *t, int64_t l, int64_t r){\n      if(r - l > 1){\n        if(not t->left) t->left\
    \ = new node(M());\n        t->left->val = M(t->val, t->left->val);\n\n      \
    \  if(not t->right) t->right = new node(M());\n        t->right->val = M(t->val,\
    \ t->right->val);\n\n        t->val = M();\n      }\n    }\n\n    void update(node\
    \ *t, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val){\n  \
    \    if(r - l == 1){\n        if(x <= l && r <= y) t->val = M(t->val, val);\n\
    \        umap[l] = t;\n        return;\n      }\n      if(r < x || y < l) return;\n\
    \      else if(x <= l && r <= y) t->val = M(t->val, val);\n      else{\n     \
    \   const int64_t m = (l + r) / 2;\n        propagate(t, l, r);\n        update(t->left,\
    \ l, m, x, y, val);\n        update(t->right, m, r, x, y, val);\n      }\n   \
    \ }\n\n    void get(node* t, int64_t l, int64_t r, int64_t x){\n      if(r - l\
    \ == 1){\n        umap[l] = t;\n        return;\n      }\n      propagate(t, l,\
    \ r);\n      int m = (l + r) / 2;\n      if(x < m) get(t->left, l, m, x);\n  \
    \    else get(t->right, m, r, x);\n    }\n\n  public:\n    dynamic_dual_segment_tree(int64_t\
    \ n):\n      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),\n      size(1LL\
    \ << depth),\n      hsize(size / 2)\n    {\n      root = new node(M());\n    }\n\
    \n    void update(int64_t s, int64_t t, value_type &x){\n      update(root, 0,\
    \ hsize, s, t, x);\n    }\n\n    value_type operator[](int64_t x){\n      get(root,\
    \ 0, hsize, x);\n      return umap[x]->val;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <unordered_map>\n\nnamespace haar_lib {\n  template\
    \ <typename Monoid>\n  class dynamic_dual_segment_tree {\n    using value_type\
    \ = typename Monoid::value_type;\n    const static Monoid M;\n\n    struct node\
    \ {\n      value_type val;\n      node *left = nullptr, *right = nullptr;\n  \
    \    node(const value_type &val): val(val) {}\n    };\n\n    const int64_t depth,\
    \ size, hsize;\n    node *root = nullptr;\n    std::unordered_map<int64_t, node*>\
    \ umap;\n\n    void propagate(node *t, int64_t l, int64_t r){\n      if(r - l\
    \ > 1){\n        if(not t->left) t->left = new node(M());\n        t->left->val\
    \ = M(t->val, t->left->val);\n\n        if(not t->right) t->right = new node(M());\n\
    \        t->right->val = M(t->val, t->right->val);\n\n        t->val = M();\n\
    \      }\n    }\n\n    void update(node *t, int64_t l, int64_t r, int64_t x, int64_t\
    \ y, const value_type &val){\n      if(r - l == 1){\n        if(x <= l && r <=\
    \ y) t->val = M(t->val, val);\n        umap[l] = t;\n        return;\n      }\n\
    \      if(r < x || y < l) return;\n      else if(x <= l && r <= y) t->val = M(t->val,\
    \ val);\n      else{\n        const int64_t m = (l + r) / 2;\n        propagate(t,\
    \ l, r);\n        update(t->left, l, m, x, y, val);\n        update(t->right,\
    \ m, r, x, y, val);\n      }\n    }\n\n    void get(node* t, int64_t l, int64_t\
    \ r, int64_t x){\n      if(r - l == 1){\n        umap[l] = t;\n        return;\n\
    \      }\n      propagate(t, l, r);\n      int m = (l + r) / 2;\n      if(x <\
    \ m) get(t->left, l, m, x);\n      else get(t->right, m, r, x);\n    }\n\n  public:\n\
    \    dynamic_dual_segment_tree(int64_t n):\n      depth(n > 1 ? 64 - __builtin_clzll(n\
    \ - 1) + 1 : 1),\n      size(1LL << depth),\n      hsize(size / 2)\n    {\n  \
    \    root = new node(M());\n    }\n\n    void update(int64_t s, int64_t t, value_type\
    \ &x){\n      update(root, 0, hsize, s, t, x);\n    }\n\n    value_type operator[](int64_t\
    \ x){\n      get(root, 0, hsize, x);\n      return umap[x]->val;\n    }\n  };\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
