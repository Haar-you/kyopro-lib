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
  bundledCode: "#line 2 \"Mylib/DataStructure/Heap/interval_heap.cpp\"\n#include <array>\n\
    #include <utility>\n#include <functional>\n\nnamespace haar_lib {\n  template\
    \ <typename T, typename Compare = std::less<T>>\n  class interval_heap {\n  public:\n\
    \    using value_type = T;\n\n  private:\n    Compare compare_;\n    std::vector<T>\
    \ data_;\n\n    int left(int i) const {return i * 2 + 1;}\n    int right(int i)\
    \ const {return i * 2 + 2;}\n    int parent(int i) const {return (i - 1) >> 1;}\n\
    \    bool check(int i) const {return i < ((int)data_.size() + 1) / 2;}\n    int\
    \ back() const {return ((int)data_.size() - 1) / 2;}\n    bool is_singleton(int\
    \ i) const {return i == back() and data_.size() % 2 == 1;}\n    int get_min_element(int\
    \ i) const {return is_singleton(i) ? (int)data_.size() - 1 : 2 * i;}\n    int\
    \ get_max_element(int i) const {return is_singleton(i) ? (int)data_.size() - 1\
    \ : 2 * i + 1;}\n\n    bool merge(int &parent, int &child){\n      if(is_singleton(child)){\n\
    \        auto &a = data_[get_min_element(parent)];\n        auto &b = data_[get_max_element(parent)];\n\
    \        auto &x = data_[get_min_element(child)];\n\n        if(compare_(x, a)){\n\
    \          std::swap(x, a);\n        }else if(compare_(b, x)){\n          std::swap(b,\
    \ x);\n        }else{\n          return false;\n        }\n      }else{\n    \
    \    std::array<int, 4> a =\n          {\n           get_min_element(parent),\n\
    \           get_min_element(child),\n           get_max_element(child),\n    \
    \       get_max_element(parent)\n          };\n\n        if(compare_(data_[a[0]],\
    \ data_[a[1]]) and\n           compare_(data_[a[1]], data_[a[2]]) and\n      \
    \     compare_(data_[a[2]], data_[a[3]])) return false;\n\n        for(int i =\
    \ 0; i < 4; ++i){\n          for(int j = i + 1; j < 4; ++j){\n            if(not\
    \ compare_(data_[a[i]], data_[a[j]])) std::swap(data_[a[i]], data_[a[j]]);\n \
    \         }\n        }\n      }\n\n      return true;\n    }\n\n    void top_down(int\
    \ i, bool is_min_modified){\n      while(1){\n        int l = left(i), r = right(i);\n\
    \n        if(not check(l)) break;\n\n        if(check(r)){\n          if(is_min_modified){\n\
    \            if(compare_(data_[get_min_element(l)], data_[get_min_element(r)])){\n\
    \              if(not merge(i, l)) break;\n              i = l;\n            }else{\n\
    \              if(not merge(i, r)) break;\n              i = r;\n            }\n\
    \n          }else{\n            if(compare_(data_[get_max_element(l)], data_[get_max_element(r)])){\n\
    \              if(not merge(i, r)) break;\n              i = r;\n            }else{\n\
    \              if(not merge(i, l)) break;\n              i = l;\n            }\n\
    \          }\n        }else{\n          if(not merge(i, l)) break;\n         \
    \ i = l;\n        }\n      }\n    }\n\n    void bottom_up(int i){\n      while(i\
    \ > 0){\n        int p = parent(i);\n        if(not merge(p, i)) break;\n    \
    \    i = p;\n      }\n    }\n\n  public:\n    interval_heap(): compare_(Compare()){}\n\
    \n    const T& get_min() const {\n      return data_[get_min_element(0)];\n  \
    \  }\n\n    const T& get_max() const {\n      return data_[get_max_element(0)];\n\
    \    }\n\n    void push(T value){\n      if(data_.size() % 2 == 1 and compare_(value,\
    \ data_.back())) std::swap(value, data_.back());\n      data_.push_back(value);\n\
    \      bottom_up(back());\n    }\n\n    void pop_min(){\n      std::swap(data_[get_min_element(0)],\
    \ data_.back());\n      data_.pop_back();\n      top_down(0, true);\n    }\n\n\
    \    void pop_max(){\n      std::swap(data_[get_max_element(0)], data_.back());\n\
    \      data_.pop_back();\n      top_down(0, false);\n    }\n\n    bool empty()\
    \ const {\n      return data_.empty();\n    }\n\n    int size() const {\n    \
    \  return data_.size();\n    }\n  };\n}\n"
  code: "#pragma once\n#include <array>\n#include <utility>\n#include <functional>\n\
    \nnamespace haar_lib {\n  template <typename T, typename Compare = std::less<T>>\n\
    \  class interval_heap {\n  public:\n    using value_type = T;\n\n  private:\n\
    \    Compare compare_;\n    std::vector<T> data_;\n\n    int left(int i) const\
    \ {return i * 2 + 1;}\n    int right(int i) const {return i * 2 + 2;}\n    int\
    \ parent(int i) const {return (i - 1) >> 1;}\n    bool check(int i) const {return\
    \ i < ((int)data_.size() + 1) / 2;}\n    int back() const {return ((int)data_.size()\
    \ - 1) / 2;}\n    bool is_singleton(int i) const {return i == back() and data_.size()\
    \ % 2 == 1;}\n    int get_min_element(int i) const {return is_singleton(i) ? (int)data_.size()\
    \ - 1 : 2 * i;}\n    int get_max_element(int i) const {return is_singleton(i)\
    \ ? (int)data_.size() - 1 : 2 * i + 1;}\n\n    bool merge(int &parent, int &child){\n\
    \      if(is_singleton(child)){\n        auto &a = data_[get_min_element(parent)];\n\
    \        auto &b = data_[get_max_element(parent)];\n        auto &x = data_[get_min_element(child)];\n\
    \n        if(compare_(x, a)){\n          std::swap(x, a);\n        }else if(compare_(b,\
    \ x)){\n          std::swap(b, x);\n        }else{\n          return false;\n\
    \        }\n      }else{\n        std::array<int, 4> a =\n          {\n      \
    \     get_min_element(parent),\n           get_min_element(child),\n         \
    \  get_max_element(child),\n           get_max_element(parent)\n          };\n\
    \n        if(compare_(data_[a[0]], data_[a[1]]) and\n           compare_(data_[a[1]],\
    \ data_[a[2]]) and\n           compare_(data_[a[2]], data_[a[3]])) return false;\n\
    \n        for(int i = 0; i < 4; ++i){\n          for(int j = i + 1; j < 4; ++j){\n\
    \            if(not compare_(data_[a[i]], data_[a[j]])) std::swap(data_[a[i]],\
    \ data_[a[j]]);\n          }\n        }\n      }\n\n      return true;\n    }\n\
    \n    void top_down(int i, bool is_min_modified){\n      while(1){\n        int\
    \ l = left(i), r = right(i);\n\n        if(not check(l)) break;\n\n        if(check(r)){\n\
    \          if(is_min_modified){\n            if(compare_(data_[get_min_element(l)],\
    \ data_[get_min_element(r)])){\n              if(not merge(i, l)) break;\n   \
    \           i = l;\n            }else{\n              if(not merge(i, r)) break;\n\
    \              i = r;\n            }\n\n          }else{\n            if(compare_(data_[get_max_element(l)],\
    \ data_[get_max_element(r)])){\n              if(not merge(i, r)) break;\n   \
    \           i = r;\n            }else{\n              if(not merge(i, l)) break;\n\
    \              i = l;\n            }\n          }\n        }else{\n          if(not\
    \ merge(i, l)) break;\n          i = l;\n        }\n      }\n    }\n\n    void\
    \ bottom_up(int i){\n      while(i > 0){\n        int p = parent(i);\n       \
    \ if(not merge(p, i)) break;\n        i = p;\n      }\n    }\n\n  public:\n  \
    \  interval_heap(): compare_(Compare()){}\n\n    const T& get_min() const {\n\
    \      return data_[get_min_element(0)];\n    }\n\n    const T& get_max() const\
    \ {\n      return data_[get_max_element(0)];\n    }\n\n    void push(T value){\n\
    \      if(data_.size() % 2 == 1 and compare_(value, data_.back())) std::swap(value,\
    \ data_.back());\n      data_.push_back(value);\n      bottom_up(back());\n  \
    \  }\n\n    void pop_min(){\n      std::swap(data_[get_min_element(0)], data_.back());\n\
    \      data_.pop_back();\n      top_down(0, true);\n    }\n\n    void pop_max(){\n\
    \      std::swap(data_[get_max_element(0)], data_.back());\n      data_.pop_back();\n\
    \      top_down(0, false);\n    }\n\n    bool empty() const {\n      return data_.empty();\n\
    \    }\n\n    int size() const {\n      return data_.size();\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Heap/interval_heap.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/Heap/interval_heap.cpp
layout: document
title: Interval heap
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://natsugiri.hatenablog.com/entry/2016/10/10/035445](https://natsugiri.hatenablog.com/entry/2016/10/10/035445)
