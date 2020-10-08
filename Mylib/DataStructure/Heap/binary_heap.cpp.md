---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_9_C/main.binary.test.cpp
    title: test/aoj/ALDS1_9_C/main.binary.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Heap/binary_heap.cpp\"\n#include <vector>\n\
    #include <functional>\n#include <utility>\n\nnamespace haar_lib {\n  template\
    \ <typename T, typename Compare = std::less<T>>\n  class binary_heap {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    std::vector<T> data_;\n    Compare\
    \ compare_;\n\n    int left(int i) const {return i * 2 + 1;}\n    int right(int\
    \ i) const {return i * 2 + 2;}\n    int parent(int i) const {return (i - 1) >>\
    \ 1;}\n\n  public:\n    binary_heap(): compare_(Compare()){}\n    binary_heap(size_t\
    \ capacity): compare_(Compare()){data_.reserve(capacity);}\n\n    void push(T\
    \ value){\n      data_.emplace_back(value);\n\n      int i = (int)data_.size()\
    \ - 1;\n\n      while(i > 0){\n        int p = parent(i);\n        if(compare_(data_[i],\
    \ data_[p])) break;\n        std::swap(data_[i], data_[p]);\n        i = p;\n\
    \      }\n    }\n\n    T top() const {\n      return data_.front();\n    }\n\n\
    \    void pop(){\n      data_.front() = data_.back();\n      data_.pop_back();\n\
    \n      int i = 0;\n\n      while(1){\n        int l = left(i);\n        int r\
    \ = right(i);\n\n        if((int)data_.size() <= l) break;\n        if((int)data_.size()\
    \ <= r){\n          if(compare_(data_[l], data_[i])) break;\n          std::swap(data_[l],\
    \ data_[i]);\n          i = l;\n        }else{\n          if(compare_(data_[l],\
    \ data_[i]) and compare_(data_[r], data_[i])) break;\n          if(compare_(data_[r],\
    \ data_[l])){\n            std::swap(data_[l], data_[i]);\n            i = l;\n\
    \          }else{\n            std::swap(data_[r], data_[i]);\n            i =\
    \ r;\n          }\n        }\n      }\n    }\n\n    bool empty() const {\n   \
    \   return data_.empty();\n    }\n\n    size_t size() const {\n      return data_.size();\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <functional>\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Compare = std::less<T>>\n\
    \  class binary_heap {\n  public:\n    using value_type = T;\n\n  private:\n \
    \   std::vector<T> data_;\n    Compare compare_;\n\n    int left(int i) const\
    \ {return i * 2 + 1;}\n    int right(int i) const {return i * 2 + 2;}\n    int\
    \ parent(int i) const {return (i - 1) >> 1;}\n\n  public:\n    binary_heap():\
    \ compare_(Compare()){}\n    binary_heap(size_t capacity): compare_(Compare()){data_.reserve(capacity);}\n\
    \n    void push(T value){\n      data_.emplace_back(value);\n\n      int i = (int)data_.size()\
    \ - 1;\n\n      while(i > 0){\n        int p = parent(i);\n        if(compare_(data_[i],\
    \ data_[p])) break;\n        std::swap(data_[i], data_[p]);\n        i = p;\n\
    \      }\n    }\n\n    T top() const {\n      return data_.front();\n    }\n\n\
    \    void pop(){\n      data_.front() = data_.back();\n      data_.pop_back();\n\
    \n      int i = 0;\n\n      while(1){\n        int l = left(i);\n        int r\
    \ = right(i);\n\n        if((int)data_.size() <= l) break;\n        if((int)data_.size()\
    \ <= r){\n          if(compare_(data_[l], data_[i])) break;\n          std::swap(data_[l],\
    \ data_[i]);\n          i = l;\n        }else{\n          if(compare_(data_[l],\
    \ data_[i]) and compare_(data_[r], data_[i])) break;\n          if(compare_(data_[r],\
    \ data_[l])){\n            std::swap(data_[l], data_[i]);\n            i = l;\n\
    \          }else{\n            std::swap(data_[r], data_[i]);\n            i =\
    \ r;\n          }\n        }\n      }\n    }\n\n    bool empty() const {\n   \
    \   return data_.empty();\n    }\n\n    size_t size() const {\n      return data_.size();\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Heap/binary_heap.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_9_C/main.binary.test.cpp
documentation_of: Mylib/DataStructure/Heap/binary_heap.cpp
layout: document
title: Binary heap
---

## Operations

## Requirements

## Notes

## Problems

## References
