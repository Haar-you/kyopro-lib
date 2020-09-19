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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Heap/binomial_heap.cpp\"\n#include <vector>\n\
    #include <array>\n#include <functional>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Compare = std::less<T>>\n  class binomial_heap\
    \ {\n    struct node {\n      T value;\n      std::vector<node*> children;\n \
    \     node(T value): value(value){}\n    };\n\n    constexpr static int MAX =\
    \ 31;\n\n    std::array<node*, MAX> roots;\n    Compare compare;\n    int top_index\
    \ = -1;\n    int heap_size = 0;\n\n    node* merge(node *a, node *b){\n      if(compare(a->value,\
    \ b->value)) std::swap(a, b);\n      a->children.push_back(b);\n      return a;\n\
    \    }\n\n    template <typename Container>\n    void meld(Container c){\n   \
    \   node *s = nullptr;\n\n      for(int i = 0; i < MAX; ++i){\n        std::vector<node*>\
    \ temp;\n        if(s){temp.push_back(s); s = nullptr;}\n        if(roots[i]){temp.push_back(roots[i]);\
    \ roots[i] = nullptr;}\n        if(i < (int)c.size() and c[i]){temp.push_back(c[i]);\
    \ c[i] = nullptr;}\n\n        switch(temp.size()){\n        case 1: roots[i] =\
    \ temp[0]; break;\n        case 2: s = merge(temp[0], temp[1]); break;\n     \
    \   case 3: roots[i] = temp[0]; s = merge(temp[1], temp[2]); break;\n        }\n\
    \      }\n\n      top_index = -1;\n      for(int i = 0; i < MAX; ++i){\n     \
    \   if(roots[i]){\n          if(top_index == -1 or compare(roots[top_index]->value,\
    \ roots[i]->value)){\n            top_index = i;\n          }\n        }\n   \
    \   }\n    }\n\n  public:\n    binomial_heap(){\n      roots.fill(nullptr);\n\
    \      compare = Compare();\n    }\n\n    int size() const {\n      return heap_size;\n\
    \    }\n\n    bool empty() const {\n      return heap_size == 0;\n    }\n\n  \
    \  void push(const T &value){\n      heap_size += 1;\n      node *t = new node(value);\n\
    \n      meld(std::vector<node*>({t}));\n    }\n\n    const T& top() const {\n\
    \      return roots[top_index]->value;\n    }\n\n    void pop(){\n      heap_size\
    \ -= 1;\n\n      node *t = roots[top_index];\n      roots[top_index] = nullptr;\n\
    \      meld(t->children);\n\n      delete t;\n    }\n\n    void meld(binomial_heap\
    \ &rhs){\n      heap_size += rhs.heap_size;\n      meld(rhs.roots);\n      rhs.roots.fill(nullptr);\n\
    \    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <array>\n#include <functional>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  template <typename T, typename Compare\
    \ = std::less<T>>\n  class binomial_heap {\n    struct node {\n      T value;\n\
    \      std::vector<node*> children;\n      node(T value): value(value){}\n   \
    \ };\n\n    constexpr static int MAX = 31;\n\n    std::array<node*, MAX> roots;\n\
    \    Compare compare;\n    int top_index = -1;\n    int heap_size = 0;\n\n   \
    \ node* merge(node *a, node *b){\n      if(compare(a->value, b->value)) std::swap(a,\
    \ b);\n      a->children.push_back(b);\n      return a;\n    }\n\n    template\
    \ <typename Container>\n    void meld(Container c){\n      node *s = nullptr;\n\
    \n      for(int i = 0; i < MAX; ++i){\n        std::vector<node*> temp;\n    \
    \    if(s){temp.push_back(s); s = nullptr;}\n        if(roots[i]){temp.push_back(roots[i]);\
    \ roots[i] = nullptr;}\n        if(i < (int)c.size() and c[i]){temp.push_back(c[i]);\
    \ c[i] = nullptr;}\n\n        switch(temp.size()){\n        case 1: roots[i] =\
    \ temp[0]; break;\n        case 2: s = merge(temp[0], temp[1]); break;\n     \
    \   case 3: roots[i] = temp[0]; s = merge(temp[1], temp[2]); break;\n        }\n\
    \      }\n\n      top_index = -1;\n      for(int i = 0; i < MAX; ++i){\n     \
    \   if(roots[i]){\n          if(top_index == -1 or compare(roots[top_index]->value,\
    \ roots[i]->value)){\n            top_index = i;\n          }\n        }\n   \
    \   }\n    }\n\n  public:\n    binomial_heap(){\n      roots.fill(nullptr);\n\
    \      compare = Compare();\n    }\n\n    int size() const {\n      return heap_size;\n\
    \    }\n\n    bool empty() const {\n      return heap_size == 0;\n    }\n\n  \
    \  void push(const T &value){\n      heap_size += 1;\n      node *t = new node(value);\n\
    \n      meld(std::vector<node*>({t}));\n    }\n\n    const T& top() const {\n\
    \      return roots[top_index]->value;\n    }\n\n    void pop(){\n      heap_size\
    \ -= 1;\n\n      node *t = roots[top_index];\n      roots[top_index] = nullptr;\n\
    \      meld(t->children);\n\n      delete t;\n    }\n\n    void meld(binomial_heap\
    \ &rhs){\n      heap_size += rhs.heap_size;\n      meld(rhs.roots);\n      rhs.roots.fill(nullptr);\n\
    \    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Heap/binomial_heap.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
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
