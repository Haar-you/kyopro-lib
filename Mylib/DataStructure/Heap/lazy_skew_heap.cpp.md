---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Heap/lazy_skew_heap.cpp\"\n#include\
    \ <functional>\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ T, class Compare = std::less<T>>\n  class lazy_skew_heap {\n  public:\n    using\
    \ value_type = T;\n\n  private:\n    struct node {\n      T val, lazy;\n     \
    \ node *left, *right;\n      int size;\n      node(const T &val) : val(val), lazy(0),\
    \ left(nullptr), right(nullptr), size(1) {}\n    };\n\n    node *root_;\n    Compare\
    \ compare_;\n\n  public:\n    lazy_skew_heap() : root_(nullptr), compare_(Compare())\
    \ {}\n    lazy_skew_heap(const Compare &compare_) : root_(nullptr), compare_(compare_)\
    \ {}\n\n  protected:\n    node *propagate(node *a) {\n      if (a) {\n       \
    \ a->val += a->lazy;\n        if (a->left) a->left->lazy += a->lazy;\n       \
    \ if (a->right) a->right->lazy += a->lazy;\n        a->lazy = 0;\n      }\n\n\
    \      return a;\n    }\n\n    node *meld(node *a, node *b) {\n      if (not a)\
    \ return propagate(b);\n      if (not b) return propagate(a);\n\n      propagate(a);\n\
    \      propagate(b);\n\n      if (compare_(a->val, b->val)) std::swap(a, b);\n\
    \n      a->size += b->size;\n      a->right = meld(a->right, b);\n      std::swap(a->left,\
    \ a->right);\n\n      return a;\n    }\n\n  public:\n    void meld(lazy_skew_heap\
    \ &heap) {\n      root_      = meld(root_, heap.root_);\n      heap.root_ = nullptr;\n\
    \    }\n    void push(const T &val) { root_ = meld(root_, new node(val)); }\n\
    \    const T &top() const { return root_->val; }\n    void pop() {\n      propagate(root_);\n\
    \      node *temp = root_;\n      root_      = meld(root_->left, root_->right);\n\
    \      delete temp;\n    }\n    bool empty() const { return root_ == nullptr;\
    \ }\n    size_t size() const { return root_ ? root_->size : 0; }\n    void add(T\
    \ v) {\n      if (root_) {\n        root_->lazy += v;\n        propagate(root_);\n\
    \      }\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <functional>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <typename T, class Compare = std::less<T>>\n  class lazy_skew_heap\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    struct node {\n \
    \     T val, lazy;\n      node *left, *right;\n      int size;\n      node(const\
    \ T &val) : val(val), lazy(0), left(nullptr), right(nullptr), size(1) {}\n   \
    \ };\n\n    node *root_;\n    Compare compare_;\n\n  public:\n    lazy_skew_heap()\
    \ : root_(nullptr), compare_(Compare()) {}\n    lazy_skew_heap(const Compare &compare_)\
    \ : root_(nullptr), compare_(compare_) {}\n\n  protected:\n    node *propagate(node\
    \ *a) {\n      if (a) {\n        a->val += a->lazy;\n        if (a->left) a->left->lazy\
    \ += a->lazy;\n        if (a->right) a->right->lazy += a->lazy;\n        a->lazy\
    \ = 0;\n      }\n\n      return a;\n    }\n\n    node *meld(node *a, node *b)\
    \ {\n      if (not a) return propagate(b);\n      if (not b) return propagate(a);\n\
    \n      propagate(a);\n      propagate(b);\n\n      if (compare_(a->val, b->val))\
    \ std::swap(a, b);\n\n      a->size += b->size;\n      a->right = meld(a->right,\
    \ b);\n      std::swap(a->left, a->right);\n\n      return a;\n    }\n\n  public:\n\
    \    void meld(lazy_skew_heap &heap) {\n      root_      = meld(root_, heap.root_);\n\
    \      heap.root_ = nullptr;\n    }\n    void push(const T &val) { root_ = meld(root_,\
    \ new node(val)); }\n    const T &top() const { return root_->val; }\n    void\
    \ pop() {\n      propagate(root_);\n      node *temp = root_;\n      root_   \
    \   = meld(root_->left, root_->right);\n      delete temp;\n    }\n    bool empty()\
    \ const { return root_ == nullptr; }\n    size_t size() const { return root_ ?\
    \ root_->size : 0; }\n    void add(T v) {\n      if (root_) {\n        root_->lazy\
    \ += v;\n        propagate(root_);\n      }\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Heap/lazy_skew_heap.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/Heap/lazy_skew_heap.cpp
layout: document
title: Lazy skew heap
---

## Operations

## Requirements

## Notes

## Problems

## References
