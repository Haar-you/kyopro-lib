---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/DataStructure/UnionFind/persistent_unionfind.cpp
    title: Persistent union-find
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/persistent_unionfind/main.test.cpp
    title: test/yosupo-judge/persistent_unionfind/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Array/persistent_array.cpp\"\n#include\
    \ <memory>\n#include <vector>\n#include <iostream>\n\nnamespace haar_lib {\n \
    \ template <typename T>\n  class persistent_array {\n  public:\n    using value_type\
    \ = T;\n\n  private:\n    struct node {\n      bool is_terminal;\n      int size\
    \ = 1;\n      node *left = nullptr, *right = nullptr;\n      std::unique_ptr<T>\
    \ value;\n\n      node(): is_terminal(false){}\n      node(T v): is_terminal(true),\
    \ value(new T(v)){}\n    };\n\n    size_t size_;\n    int depth_;\n    node* root_\
    \ = nullptr;\n\n    int get_size(node *t) const {\n      return t ? t->size :\
    \ 0;\n    }\n\n    node* init(int s, int d){\n      if(s == 0) return nullptr;\n\
    \      if(d == depth_){\n        return new node(T());\n      }else{\n       \
    \ node *t = new node();\n        t->left = init(s / 2, d + 1);\n        t->right\
    \ = init(s - s / 2, d + 1);\n        t->size = get_size(t->left) + get_size(t->right);\n\
    \        return t;\n      }\n    }\n\n    void apply_init(node *t, const std::vector<T>\
    \ &ret, int &i) {\n      if(not t) return;\n\n      if(t->is_terminal){\n    \
    \    *(t->value) = ret[i];\n        ++i;\n        return;\n      }\n\n      apply_init(t->left,\
    \ ret, i);\n      apply_init(t->right, ret, i);\n    }\n\n    persistent_array(node\
    \ *root): root_(root){}\n\n    void calc_depth(){\n      depth_ = 1;\n      while((int)size_\
    \ > (1 << depth_)) depth_ += 1;\n      depth_ += 1;\n    }\n\n  public:\n    persistent_array(){}\n\
    \    persistent_array(size_t size): size_(size){\n      calc_depth();\n      root_\
    \ = init(size_, 1);\n    }\n\n    persistent_array(const std::vector<T> &v): size_(v.size()){\n\
    \      calc_depth();\n      root_ = init(size_, 1);\n\n      int i = 0;\n    \
    \  apply_init(root_, v, i);\n    }\n\n    persistent_array(const persistent_array\
    \ &v){\n      this->root_ = v.root_;\n      this->size_ = v.size_;\n      this->depth_\
    \ = v.depth_;\n    }\n\n  protected:\n    T get(node *t, int i) const {\n    \
    \  if(t->is_terminal) return *(t->value);\n\n      int k = get_size(t->left);\n\
    \      if(i < k) return get(t->left, i);\n      else return get(t->right, i -\
    \ k);\n    }\n\n  public:\n    T operator[](int i) const {\n      return get(root_,\
    \ i);\n    }\n\n  protected:\n    node* set(node *prev, int i, const T &val) const\
    \ {\n      if(prev->is_terminal) return new node(val);\n\n      int k = get_size(prev->left);\n\
    \n      node *t = new node();\n      if(i < k){\n        t->right = prev->right;\n\
    \        t->left = set(prev->left, i, val);\n        t->size = get_size(t->right)\
    \ + get_size(t->left);\n      }else{\n        t->left = prev->left;\n        t->right\
    \ = set(prev->right, i - k, val);\n        t->size = get_size(t->right) + get_size(t->left);\n\
    \      }\n      return t;\n    }\n\n  public:\n    persistent_array set(int i,\
    \ const T &val) const {\n      node *ret = set(root_, i, val);\n      return persistent_array(ret);\n\
    \    }\n\n  protected:\n    void traverse(node *t, std::vector<T> &ret) const\
    \ {\n      if(not t) return;\n\n      if(t->is_terminal){\n        ret.push_back(*(t->value));\n\
    \        return;\n      }\n\n      traverse(t->left, ret);\n      traverse(t->right,\
    \ ret);\n    }\n\n  public:\n    std::vector<T> traverse() const {\n      std::vector<T>\
    \ ret;\n      traverse(root_, ret);\n      return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream &s, const persistent_array &a){\n      auto v = a.traverse();\n\
    \      s << \"{\";\n      for(auto it = v.begin(); it != v.end(); ++it){\n   \
    \     if(it != v.begin()) s << \", \";\n        s << *it;\n      }\n      s <<\
    \ \"}\";\n      return s;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <memory>\n#include <vector>\n#include <iostream>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  class persistent_array {\n\
    \  public:\n    using value_type = T;\n\n  private:\n    struct node {\n     \
    \ bool is_terminal;\n      int size = 1;\n      node *left = nullptr, *right =\
    \ nullptr;\n      std::unique_ptr<T> value;\n\n      node(): is_terminal(false){}\n\
    \      node(T v): is_terminal(true), value(new T(v)){}\n    };\n\n    size_t size_;\n\
    \    int depth_;\n    node* root_ = nullptr;\n\n    int get_size(node *t) const\
    \ {\n      return t ? t->size : 0;\n    }\n\n    node* init(int s, int d){\n \
    \     if(s == 0) return nullptr;\n      if(d == depth_){\n        return new node(T());\n\
    \      }else{\n        node *t = new node();\n        t->left = init(s / 2, d\
    \ + 1);\n        t->right = init(s - s / 2, d + 1);\n        t->size = get_size(t->left)\
    \ + get_size(t->right);\n        return t;\n      }\n    }\n\n    void apply_init(node\
    \ *t, const std::vector<T> &ret, int &i) {\n      if(not t) return;\n\n      if(t->is_terminal){\n\
    \        *(t->value) = ret[i];\n        ++i;\n        return;\n      }\n\n   \
    \   apply_init(t->left, ret, i);\n      apply_init(t->right, ret, i);\n    }\n\
    \n    persistent_array(node *root): root_(root){}\n\n    void calc_depth(){\n\
    \      depth_ = 1;\n      while((int)size_ > (1 << depth_)) depth_ += 1;\n   \
    \   depth_ += 1;\n    }\n\n  public:\n    persistent_array(){}\n    persistent_array(size_t\
    \ size): size_(size){\n      calc_depth();\n      root_ = init(size_, 1);\n  \
    \  }\n\n    persistent_array(const std::vector<T> &v): size_(v.size()){\n    \
    \  calc_depth();\n      root_ = init(size_, 1);\n\n      int i = 0;\n      apply_init(root_,\
    \ v, i);\n    }\n\n    persistent_array(const persistent_array &v){\n      this->root_\
    \ = v.root_;\n      this->size_ = v.size_;\n      this->depth_ = v.depth_;\n \
    \   }\n\n  protected:\n    T get(node *t, int i) const {\n      if(t->is_terminal)\
    \ return *(t->value);\n\n      int k = get_size(t->left);\n      if(i < k) return\
    \ get(t->left, i);\n      else return get(t->right, i - k);\n    }\n\n  public:\n\
    \    T operator[](int i) const {\n      return get(root_, i);\n    }\n\n  protected:\n\
    \    node* set(node *prev, int i, const T &val) const {\n      if(prev->is_terminal)\
    \ return new node(val);\n\n      int k = get_size(prev->left);\n\n      node *t\
    \ = new node();\n      if(i < k){\n        t->right = prev->right;\n        t->left\
    \ = set(prev->left, i, val);\n        t->size = get_size(t->right) + get_size(t->left);\n\
    \      }else{\n        t->left = prev->left;\n        t->right = set(prev->right,\
    \ i - k, val);\n        t->size = get_size(t->right) + get_size(t->left);\n  \
    \    }\n      return t;\n    }\n\n  public:\n    persistent_array set(int i, const\
    \ T &val) const {\n      node *ret = set(root_, i, val);\n      return persistent_array(ret);\n\
    \    }\n\n  protected:\n    void traverse(node *t, std::vector<T> &ret) const\
    \ {\n      if(not t) return;\n\n      if(t->is_terminal){\n        ret.push_back(*(t->value));\n\
    \        return;\n      }\n\n      traverse(t->left, ret);\n      traverse(t->right,\
    \ ret);\n    }\n\n  public:\n    std::vector<T> traverse() const {\n      std::vector<T>\
    \ ret;\n      traverse(root_, ret);\n      return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream &s, const persistent_array &a){\n      auto v = a.traverse();\n\
    \      s << \"{\";\n      for(auto it = v.begin(); it != v.end(); ++it){\n   \
    \     if(it != v.begin()) s << \", \";\n        s << *it;\n      }\n      s <<\
    \ \"}\";\n      return s;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Array/persistent_array.cpp
  requiredBy:
  - Mylib/DataStructure/UnionFind/persistent_unionfind.cpp
  timestamp: '2020-09-30 02:01:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/persistent_unionfind/main.test.cpp
documentation_of: Mylib/DataStructure/Array/persistent_array.cpp
layout: document
title: Persistent array
---

## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #368 (Div. 2) D. Persistent Bookcase](https://codeforces.com/contest/707/problem/D)

## References
