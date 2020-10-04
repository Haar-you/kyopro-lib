---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.skew_heap.test.cpp
    title: test/aoj/2559/main.skew_heap.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Heap/skew_heap.cpp\"\n#include <functional>\n\
    #include <utility>\n\nnamespace haar_lib {\n  template <typename T, class Compare\
    \ = std::less<T>>\n  class skew_heap {\n  public:\n    using value_type = T;\n\
    \n  private:\n    struct node {\n      T val;\n      node *left, *right;\n   \
    \   int size;\n      node(const T &val): val(val), left(nullptr), right(nullptr),\
    \ size(1){}\n    };\n\n    node *root_;\n    Compare compare_;\n\n  public:\n\
    \    skew_heap(): root_(nullptr), compare_(Compare()){}\n    skew_heap(const Compare\
    \ &compare_): root_(nullptr), compare_(compare_){}\n\n  protected:\n    node*\
    \ meld(node *a, node *b){\n      if(not a) return b;\n      if(not b) return a;\n\
    \n      if(compare_(a->val, b->val)) std::swap(a, b);\n\n      a->size += b->size;\n\
    \      a->right = meld(a->right, b);\n      std::swap(a->left, a->right);\n\n\
    \      return a;\n    }\n\n  public:\n    void meld(skew_heap &heap){root_ = meld(root_,\
    \ heap.root_); heap.root_ = nullptr;}\n    void push(const T &val){root_ = meld(root_,\
    \ new node(val));}\n    const T& top() const {return root_->val;}\n    void pop(){node\
    \ *temp = root_; root_ = meld(root_->left, root_->right); delete temp;}\n    bool\
    \ empty() const {return root_ == nullptr;}\n    size_t size() const {return root_\
    \ ? root_->size : 0;}\n  };\n}\n"
  code: "#pragma once\n#include <functional>\n#include <utility>\n\nnamespace haar_lib\
    \ {\n  template <typename T, class Compare = std::less<T>>\n  class skew_heap\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    struct node {\n \
    \     T val;\n      node *left, *right;\n      int size;\n      node(const T &val):\
    \ val(val), left(nullptr), right(nullptr), size(1){}\n    };\n\n    node *root_;\n\
    \    Compare compare_;\n\n  public:\n    skew_heap(): root_(nullptr), compare_(Compare()){}\n\
    \    skew_heap(const Compare &compare_): root_(nullptr), compare_(compare_){}\n\
    \n  protected:\n    node* meld(node *a, node *b){\n      if(not a) return b;\n\
    \      if(not b) return a;\n\n      if(compare_(a->val, b->val)) std::swap(a,\
    \ b);\n\n      a->size += b->size;\n      a->right = meld(a->right, b);\n    \
    \  std::swap(a->left, a->right);\n\n      return a;\n    }\n\n  public:\n    void\
    \ meld(skew_heap &heap){root_ = meld(root_, heap.root_); heap.root_ = nullptr;}\n\
    \    void push(const T &val){root_ = meld(root_, new node(val));}\n    const T&\
    \ top() const {return root_->val;}\n    void pop(){node *temp = root_; root_ =\
    \ meld(root_->left, root_->right); delete temp;}\n    bool empty() const {return\
    \ root_ == nullptr;}\n    size_t size() const {return root_ ? root_->size : 0;}\n\
    \  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Heap/skew_heap.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2559/main.skew_heap.test.cpp
documentation_of: Mylib/DataStructure/Heap/skew_heap.cpp
layout: document
title: Skew heap
---

## Operations

## Requirements

## Notes

## Problems

## References
