---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.pairing_heap.test.cpp
    title: test/aoj/2559/main.pairing_heap.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Heap/pairing_heap.cpp\"\n#include <functional>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename T, typename Compare\
    \ = std::less<T>>\n  class pairing_heap {\n  public:\n    using value_type = T;\n\
    \n  private:\n    struct node_ {\n      T value;\n      std::vector<node_*> ch;\n\
    \      node_(const T &value): value(value){}\n    };\n\n    Compare compare_;\n\
    \    node_ *root_ = nullptr;\n    size_t size_ = 0;\n\n    node_* merge_(node_\
    \ *a, node_ *b){\n      if(not a) return b;\n      if(not b) return a;\n     \
    \ if(compare_(b->value, a->value)){\n        a->ch.push_back(b);\n        return\
    \ a;\n      }else{\n        b->ch.push_back(a);\n        return b;\n      }\n\
    \    }\n\n    node_* merge_list_(node_ *a){\n      if((a->ch.size() & 1) == 1)\
    \ a->ch.push_back(nullptr);\n\n      for(size_t i = 0; i < a->ch.size(); i +=\
    \ 2){\n        a->ch[i >> 1] = merge_(a->ch[i], a->ch[i + 1]);\n      }\n\n  \
    \    a->ch.resize(a->ch.size() / 2);\n\n      node_ *ret = nullptr;\n      for(int\
    \ i = a->ch.size(); --i >= 0;){\n        ret = merge_(ret, a->ch[i]);\n      }\n\
    \n      return ret;\n    }\n\n  public:\n    pairing_heap(): compare_(Compare()){}\n\
    \    pairing_heap(const Compare &compare_): compare_(compare_){}\n\n    void meld(pairing_heap\
    \ &that){\n      root_ = merge_(root_, that.root_);\n      that.root_ = nullptr;\n\
    \      size_ += that.size_;\n      that.size_ = 0;\n    }\n    void push(const\
    \ T &val){root_ = merge_(root_, new node_(val)); ++size_;}\n    void pop(){root_\
    \ = merge_list_(root_); --size_;}\n    const T& top() const {return root_->value;}\n\
    \    bool empty() const {return root_ == nullptr;}\n    size_t size() const {return\
    \ size_;}\n  };\n}\n"
  code: "#pragma once\n#include <functional>\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare = std::less<T>>\n  class pairing_heap\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    struct node_ {\n\
    \      T value;\n      std::vector<node_*> ch;\n      node_(const T &value): value(value){}\n\
    \    };\n\n    Compare compare_;\n    node_ *root_ = nullptr;\n    size_t size_\
    \ = 0;\n\n    node_* merge_(node_ *a, node_ *b){\n      if(not a) return b;\n\
    \      if(not b) return a;\n      if(compare_(b->value, a->value)){\n        a->ch.push_back(b);\n\
    \        return a;\n      }else{\n        b->ch.push_back(a);\n        return\
    \ b;\n      }\n    }\n\n    node_* merge_list_(node_ *a){\n      if((a->ch.size()\
    \ & 1) == 1) a->ch.push_back(nullptr);\n\n      for(size_t i = 0; i < a->ch.size();\
    \ i += 2){\n        a->ch[i >> 1] = merge_(a->ch[i], a->ch[i + 1]);\n      }\n\
    \n      a->ch.resize(a->ch.size() / 2);\n\n      node_ *ret = nullptr;\n     \
    \ for(int i = a->ch.size(); --i >= 0;){\n        ret = merge_(ret, a->ch[i]);\n\
    \      }\n\n      return ret;\n    }\n\n  public:\n    pairing_heap(): compare_(Compare()){}\n\
    \    pairing_heap(const Compare &compare_): compare_(compare_){}\n\n    void meld(pairing_heap\
    \ &that){\n      root_ = merge_(root_, that.root_);\n      that.root_ = nullptr;\n\
    \      size_ += that.size_;\n      that.size_ = 0;\n    }\n    void push(const\
    \ T &val){root_ = merge_(root_, new node_(val)); ++size_;}\n    void pop(){root_\
    \ = merge_list_(root_); --size_;}\n    const T& top() const {return root_->value;}\n\
    \    bool empty() const {return root_ == nullptr;}\n    size_t size() const {return\
    \ size_;}\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Heap/pairing_heap.cpp
  requiredBy: []
  timestamp: '2021-03-04 03:07:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2559/main.pairing_heap.test.cpp
documentation_of: Mylib/DataStructure/Heap/pairing_heap.cpp
layout: document
title: Pairing heap
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://scrapbox.io/data-structures/Pairing_Heap](https://scrapbox.io/data-structures/Pairing_Heap)
- [https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120929/1348886107.html](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120929/1348886107.html)
