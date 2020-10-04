---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2559/main.binomial_heap.test.cpp
    title: test/aoj/2559/main.binomial_heap.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Heap/binomial_heap.cpp\"\n#include <vector>\n\
    #include <array>\n#include <functional>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare = std::less<T>>\n  class binomial_heap\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    struct node {\n \
    \     T value;\n      std::vector<node*> children;\n      node(T value): value(value){}\n\
    \    };\n\n    constexpr static int MAX = 31;\n\n    std::array<node*, MAX> roots_;\n\
    \    Compare compare_;\n    int top_index_ = -1;\n    int heap_size_ = 0;\n\n\
    \    node* merge(node *a, node *b){\n      if(compare_(a->value, b->value)) std::swap(a,\
    \ b);\n      a->children.push_back(b);\n      return a;\n    }\n\n    template\
    \ <typename Container>\n    void meld(Container c){\n      node *s = nullptr;\n\
    \n      for(int i = 0; i < MAX; ++i){\n        std::vector<node*> temp;\n    \
    \    if(s){temp.push_back(s); s = nullptr;}\n        if(roots_[i]){temp.push_back(roots_[i]);\
    \ roots_[i] = nullptr;}\n        if(i < (int)c.size() and c[i]){temp.push_back(c[i]);\
    \ c[i] = nullptr;}\n\n        switch(temp.size()){\n        case 1: roots_[i]\
    \ = temp[0]; break;\n        case 2: s = merge(temp[0], temp[1]); break;\n   \
    \     case 3: roots_[i] = temp[0]; s = merge(temp[1], temp[2]); break;\n     \
    \   }\n      }\n\n      top_index_ = -1;\n      for(int i = 0; i < MAX; ++i){\n\
    \        if(roots_[i]){\n          if(top_index_ == -1 or compare_(roots_[top_index_]->value,\
    \ roots_[i]->value)){\n            top_index_ = i;\n          }\n        }\n \
    \     }\n    }\n\n  public:\n    binomial_heap(){\n      roots_.fill(nullptr);\n\
    \      compare_ = Compare();\n    }\n\n    int size() const {\n      return heap_size_;\n\
    \    }\n\n    bool empty() const {\n      return heap_size_ == 0;\n    }\n\n \
    \   void push(const T &value){\n      heap_size_ += 1;\n      node *t = new node(value);\n\
    \n      meld(std::vector<node*>({t}));\n    }\n\n    const T& top() const {\n\
    \      return roots_[top_index_]->value;\n    }\n\n    void pop(){\n      heap_size_\
    \ -= 1;\n\n      node *t = roots_[top_index_];\n      roots_[top_index_] = nullptr;\n\
    \      meld(t->children);\n\n      delete t;\n    }\n\n    void meld(binomial_heap\
    \ &rhs){\n      heap_size_ += rhs.heap_size_;\n      meld(rhs.roots_);\n     \
    \ rhs.roots_.fill(nullptr);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <array>\n#include <functional>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  template <typename T, typename Compare\
    \ = std::less<T>>\n  class binomial_heap {\n  public:\n    using value_type =\
    \ T;\n\n  private:\n    struct node {\n      T value;\n      std::vector<node*>\
    \ children;\n      node(T value): value(value){}\n    };\n\n    constexpr static\
    \ int MAX = 31;\n\n    std::array<node*, MAX> roots_;\n    Compare compare_;\n\
    \    int top_index_ = -1;\n    int heap_size_ = 0;\n\n    node* merge(node *a,\
    \ node *b){\n      if(compare_(a->value, b->value)) std::swap(a, b);\n      a->children.push_back(b);\n\
    \      return a;\n    }\n\n    template <typename Container>\n    void meld(Container\
    \ c){\n      node *s = nullptr;\n\n      for(int i = 0; i < MAX; ++i){\n     \
    \   std::vector<node*> temp;\n        if(s){temp.push_back(s); s = nullptr;}\n\
    \        if(roots_[i]){temp.push_back(roots_[i]); roots_[i] = nullptr;}\n    \
    \    if(i < (int)c.size() and c[i]){temp.push_back(c[i]); c[i] = nullptr;}\n\n\
    \        switch(temp.size()){\n        case 1: roots_[i] = temp[0]; break;\n \
    \       case 2: s = merge(temp[0], temp[1]); break;\n        case 3: roots_[i]\
    \ = temp[0]; s = merge(temp[1], temp[2]); break;\n        }\n      }\n\n     \
    \ top_index_ = -1;\n      for(int i = 0; i < MAX; ++i){\n        if(roots_[i]){\n\
    \          if(top_index_ == -1 or compare_(roots_[top_index_]->value, roots_[i]->value)){\n\
    \            top_index_ = i;\n          }\n        }\n      }\n    }\n\n  public:\n\
    \    binomial_heap(){\n      roots_.fill(nullptr);\n      compare_ = Compare();\n\
    \    }\n\n    int size() const {\n      return heap_size_;\n    }\n\n    bool\
    \ empty() const {\n      return heap_size_ == 0;\n    }\n\n    void push(const\
    \ T &value){\n      heap_size_ += 1;\n      node *t = new node(value);\n\n   \
    \   meld(std::vector<node*>({t}));\n    }\n\n    const T& top() const {\n    \
    \  return roots_[top_index_]->value;\n    }\n\n    void pop(){\n      heap_size_\
    \ -= 1;\n\n      node *t = roots_[top_index_];\n      roots_[top_index_] = nullptr;\n\
    \      meld(t->children);\n\n      delete t;\n    }\n\n    void meld(binomial_heap\
    \ &rhs){\n      heap_size_ += rhs.heap_size_;\n      meld(rhs.roots_);\n     \
    \ rhs.roots_.fill(nullptr);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Heap/binomial_heap.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2559/main.binomial_heap.test.cpp
documentation_of: Mylib/DataStructure/Heap/binomial_heap.cpp
layout: document
title: Binomial heap
---

## Operations

## Requirements

## Notes

## Problems

## References
