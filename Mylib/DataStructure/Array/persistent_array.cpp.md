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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/Array/persistent_array.cpp\"\n#include\
    \ <memory>\n#include <vector>\n#include <iostream>\n\nnamespace haar_lib {\n \
    \ template <typename T>\n  class persistent_array {\n    struct node {\n     \
    \ bool is_terminal;\n      int size = 1;\n      node *left = nullptr, *right =\
    \ nullptr;\n      std::unique_ptr<T> value;\n\n      node(): is_terminal(false){}\n\
    \      node(T v): is_terminal(true), value(new T(v)){}\n    };\n\n    size_t size;\n\
    \    int depth;\n\n    node* root = nullptr;\n\n    int get_size(node *t) const\
    \ {\n      return !t ? 0 : t->size;\n    }\n\n    node* init(int s, int d){\n\
    \      if(s == 0) return nullptr;\n      if(d == depth){\n        return new node(T());\n\
    \      }else{\n        node *t = new node();\n        t->left = init(s / 2, d\
    \ + 1);\n        t->right = init(s - s / 2, d + 1);\n        t->size = get_size(t->left)\
    \ + get_size(t->right);\n        return t;\n      }\n    }\n\n    void apply_init(node\
    \ *t, const std::vector<T> &ret, int &i) {\n      if(!t) return;\n\n      if(t->is_terminal){\n\
    \        *(t->value) = ret[i];\n        ++i;\n        return;\n      }\n\n   \
    \   apply_init(t->left, ret, i);\n      apply_init(t->right, ret, i);\n    }\n\
    \n    persistent_array(node *root): root(root){}\n\n    void calc_depth(int size){\n\
    \      depth = 1;\n      while((int)size > (1 << depth)) depth += 1;\n      depth\
    \ += 1;\n    }\n\n  public:\n    persistent_array(){}\n    persistent_array(size_t\
    \ size): size(size){\n      calc_depth(size);\n      root = init(size, 1);\n \
    \   }\n\n    persistent_array(const std::vector<T> &v): size(v.size()){\n    \
    \  calc_depth(size);\n      root = init(size, 1);\n\n      int i = 0;\n      apply_init(root,\
    \ v, i);\n    }\n\n    persistent_array(const persistent_array &v){\n      this->root\
    \ = v.root;\n      this->size = v.size;\n      this->depth = v.depth;\n    }\n\
    \n  protected:\n    T get(node *t, int i) const {\n      if(t->is_terminal) return\
    \ *(t->value);\n\n      int k = get_size(t->left);\n      if(i < k) return get(t->left,\
    \ i);\n      else return get(t->right, i - k);\n    }\n\n  public:\n    T operator[](int\
    \ i) const {\n      return get(root, i);\n    }\n\n  protected:\n    node* set(node\
    \ *prev, int i, const T &val) const {\n      if(prev->is_terminal) return new\
    \ node(val);\n\n      int k = get_size(prev->left);\n\n      node *t = new node();\n\
    \      if(i < k){\n        t->right = prev->right;\n        t->left = set(prev->left,\
    \ i, val);\n        t->size = get_size(t->right) + get_size(t->left);\n      }else{\n\
    \        t->left = prev->left;\n        t->right = set(prev->right, i - k, val);\n\
    \        t->size = get_size(t->right) + get_size(t->left);\n      }\n      return\
    \ t;\n    }\n\n  public:\n    persistent_array set(int i, const T &val) const\
    \ {\n      node *ret = set(root, i, val);\n      return persistent_array(ret);\n\
    \    }\n\n  protected:\n    void traverse(node *t, std::vector<T> &ret) const\
    \ {\n      if(!t) return;\n\n      if(t->is_terminal){\n        ret.push_back(*(t->value));\n\
    \        return;\n      }\n\n      traverse(t->left, ret);\n      traverse(t->right,\
    \ ret);\n    }\n\n  public:\n    std::vector<T> traverse() const {\n      std::vector<T>\
    \ ret;\n      traverse(root, ret);\n      return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream &s, const persistent_array &a){\n      auto v = a.traverse();\n\
    \      s << \"{\";\n      for(auto it = v.begin(); it != v.end(); ++it){\n   \
    \     if(it != v.begin()) s << \", \";\n        s << *it;\n      }\n      s <<\
    \ \"}\";\n      return s;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <memory>\n#include <vector>\n#include <iostream>\n\
    \nnamespace haar_lib {\n  template <typename T>\n  class persistent_array {\n\
    \    struct node {\n      bool is_terminal;\n      int size = 1;\n      node *left\
    \ = nullptr, *right = nullptr;\n      std::unique_ptr<T> value;\n\n      node():\
    \ is_terminal(false){}\n      node(T v): is_terminal(true), value(new T(v)){}\n\
    \    };\n\n    size_t size;\n    int depth;\n\n    node* root = nullptr;\n\n \
    \   int get_size(node *t) const {\n      return !t ? 0 : t->size;\n    }\n\n \
    \   node* init(int s, int d){\n      if(s == 0) return nullptr;\n      if(d ==\
    \ depth){\n        return new node(T());\n      }else{\n        node *t = new\
    \ node();\n        t->left = init(s / 2, d + 1);\n        t->right = init(s -\
    \ s / 2, d + 1);\n        t->size = get_size(t->left) + get_size(t->right);\n\
    \        return t;\n      }\n    }\n\n    void apply_init(node *t, const std::vector<T>\
    \ &ret, int &i) {\n      if(!t) return;\n\n      if(t->is_terminal){\n       \
    \ *(t->value) = ret[i];\n        ++i;\n        return;\n      }\n\n      apply_init(t->left,\
    \ ret, i);\n      apply_init(t->right, ret, i);\n    }\n\n    persistent_array(node\
    \ *root): root(root){}\n\n    void calc_depth(int size){\n      depth = 1;\n \
    \     while((int)size > (1 << depth)) depth += 1;\n      depth += 1;\n    }\n\n\
    \  public:\n    persistent_array(){}\n    persistent_array(size_t size): size(size){\n\
    \      calc_depth(size);\n      root = init(size, 1);\n    }\n\n    persistent_array(const\
    \ std::vector<T> &v): size(v.size()){\n      calc_depth(size);\n      root = init(size,\
    \ 1);\n\n      int i = 0;\n      apply_init(root, v, i);\n    }\n\n    persistent_array(const\
    \ persistent_array &v){\n      this->root = v.root;\n      this->size = v.size;\n\
    \      this->depth = v.depth;\n    }\n\n  protected:\n    T get(node *t, int i)\
    \ const {\n      if(t->is_terminal) return *(t->value);\n\n      int k = get_size(t->left);\n\
    \      if(i < k) return get(t->left, i);\n      else return get(t->right, i -\
    \ k);\n    }\n\n  public:\n    T operator[](int i) const {\n      return get(root,\
    \ i);\n    }\n\n  protected:\n    node* set(node *prev, int i, const T &val) const\
    \ {\n      if(prev->is_terminal) return new node(val);\n\n      int k = get_size(prev->left);\n\
    \n      node *t = new node();\n      if(i < k){\n        t->right = prev->right;\n\
    \        t->left = set(prev->left, i, val);\n        t->size = get_size(t->right)\
    \ + get_size(t->left);\n      }else{\n        t->left = prev->left;\n        t->right\
    \ = set(prev->right, i - k, val);\n        t->size = get_size(t->right) + get_size(t->left);\n\
    \      }\n      return t;\n    }\n\n  public:\n    persistent_array set(int i,\
    \ const T &val) const {\n      node *ret = set(root, i, val);\n      return persistent_array(ret);\n\
    \    }\n\n  protected:\n    void traverse(node *t, std::vector<T> &ret) const\
    \ {\n      if(!t) return;\n\n      if(t->is_terminal){\n        ret.push_back(*(t->value));\n\
    \        return;\n      }\n\n      traverse(t->left, ret);\n      traverse(t->right,\
    \ ret);\n    }\n\n  public:\n    std::vector<T> traverse() const {\n      std::vector<T>\
    \ ret;\n      traverse(root, ret);\n      return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream &s, const persistent_array &a){\n      auto v = a.traverse();\n\
    \      s << \"{\";\n      for(auto it = v.begin(); it != v.end(); ++it){\n   \
    \     if(it != v.begin()) s << \", \";\n        s << *it;\n      }\n      s <<\
    \ \"}\";\n      return s;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/Array/persistent_array.cpp
  requiredBy:
  - Mylib/DataStructure/UnionFind/persistent_unionfind.cpp
  timestamp: '2020-09-25 01:38:58+09:00'
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
