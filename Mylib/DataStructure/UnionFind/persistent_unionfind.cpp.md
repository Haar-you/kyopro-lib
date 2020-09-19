---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/Array/persistent_array.cpp
    title: Persistent array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/persistent_unionfind/main.test.cpp
    title: test/yosupo-judge/persistent_unionfind/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/UnionFind/persistent_unionfind.cpp\"\
    \n#include <vector>\n#line 2 \"Mylib/DataStructure/Array/persistent_array.cpp\"\
    \n#include <memory>\n#line 4 \"Mylib/DataStructure/Array/persistent_array.cpp\"\
    \n#include <iostream>\n\nnamespace haar_lib {\n  template <typename T>\n  class\
    \ persistent_array {\n    struct node {\n      bool is_terminal;\n      int size\
    \ = 1;\n      node *left = nullptr, *right = nullptr;\n      std::unique_ptr<T>\
    \ value;\n\n      node(): is_terminal(false){}\n      node(T v): is_terminal(true),\
    \ value(new T(v)){}\n    };\n\n    size_t size;\n    int depth;\n\n    node* root\
    \ = nullptr;\n\n    int get_size(node *t) const {\n      return !t ? 0 : t->size;\n\
    \    }\n\n    node* init(int s, int d){\n      if(s == 0) return nullptr;\n  \
    \    if(d == depth){\n        return new node(T());\n      }else{\n        node\
    \ *t = new node();\n        t->left = init(s / 2, d + 1);\n        t->right =\
    \ init(s - s / 2, d + 1);\n        t->size = get_size(t->left) + get_size(t->right);\n\
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
    \ i);\n    }\n\n  protected:\n    node* update(node *prev, int i, const T &val)\
    \ const {\n      if(prev->is_terminal) return new node(val);\n\n      int k =\
    \ get_size(prev->left);\n\n      node *t = new node();\n      if(i < k){\n   \
    \     t->right = prev->right;\n        t->left = update(prev->left, i, val);\n\
    \        t->size = get_size(t->right) + get_size(t->left);\n      }else{\n   \
    \     t->left = prev->left;\n        t->right = update(prev->right, i - k, val);\n\
    \        t->size = get_size(t->right) + get_size(t->left);\n      }\n      return\
    \ t;\n    }\n\n  public:\n    persistent_array update(int i, const T &val) const\
    \ {\n      node *ret = update(root, i, val);\n      return persistent_array(ret);\n\
    \    }\n\n  protected:\n    void traverse(node *t, std::vector<T> &ret) const\
    \ {\n      if(!t) return;\n\n      if(t->is_terminal){\n        ret.push_back(*(t->value));\n\
    \        return;\n      }\n\n      traverse(t->left, ret);\n      traverse(t->right,\
    \ ret);\n    }\n\n  public:\n    std::vector<T> traverse() const {\n      std::vector<T>\
    \ ret;\n      traverse(root, ret);\n      return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream &s, const persistent_array &a){\n      auto v = a.traverse();\n\
    \      s << \"{\";\n      for(auto it = v.begin(); it != v.end(); ++it){\n   \
    \     if(it != v.begin()) s << \", \";\n        s << *it;\n      }\n      s <<\
    \ \"}\";\n      return s;\n    }\n  };\n}\n#line 4 \"Mylib/DataStructure/UnionFind/persistent_unionfind.cpp\"\
    \n\nnamespace haar_lib {\n  class persistent_unionfind {\n    persistent_array<int>\
    \ par;\n\n    persistent_unionfind(persistent_array<int> par): par(par){}\n\n\
    \  public:\n    persistent_unionfind(){}\n    persistent_unionfind(int n): par(persistent_array<int>(std::vector<int>(n,\
    \ -1))){}\n\n    int root_of(int i) const {\n      const int p = par[i];\n   \
    \   if(p < 0) return i;\n      return root_of(p);\n    }\n\n    bool is_same(int\
    \ i, int j) const {\n      return root_of(i) == root_of(j);\n    }\n\n    int\
    \ size_of(int i) const {\n      return -par[root_of(i)];\n    }\n\n    persistent_unionfind\
    \ merge(int i, int j) const {\n      const int ri = root_of(i), rj = root_of(j);\n\
    \      if(ri == rj) return *this;\n\n      const int size_i = -par[ri];\n    \
    \  const int size_j = -par[rj];\n\n      persistent_array<int> ret = par;\n\n\
    \      if(size_i > size_j){\n        ret = ret.update(ri, -(size_i + size_j));\n\
    \        ret = ret.update(rj, ri);\n      }else{\n        ret = ret.update(rj,\
    \ -(size_i + size_j));\n        ret = ret.update(ri, rj);\n      }\n\n      return\
    \ persistent_unionfind(ret);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"Mylib/DataStructure/Array/persistent_array.cpp\"\
    \n\nnamespace haar_lib {\n  class persistent_unionfind {\n    persistent_array<int>\
    \ par;\n\n    persistent_unionfind(persistent_array<int> par): par(par){}\n\n\
    \  public:\n    persistent_unionfind(){}\n    persistent_unionfind(int n): par(persistent_array<int>(std::vector<int>(n,\
    \ -1))){}\n\n    int root_of(int i) const {\n      const int p = par[i];\n   \
    \   if(p < 0) return i;\n      return root_of(p);\n    }\n\n    bool is_same(int\
    \ i, int j) const {\n      return root_of(i) == root_of(j);\n    }\n\n    int\
    \ size_of(int i) const {\n      return -par[root_of(i)];\n    }\n\n    persistent_unionfind\
    \ merge(int i, int j) const {\n      const int ri = root_of(i), rj = root_of(j);\n\
    \      if(ri == rj) return *this;\n\n      const int size_i = -par[ri];\n    \
    \  const int size_j = -par[rj];\n\n      persistent_array<int> ret = par;\n\n\
    \      if(size_i > size_j){\n        ret = ret.update(ri, -(size_i + size_j));\n\
    \        ret = ret.update(rj, ri);\n      }else{\n        ret = ret.update(rj,\
    \ -(size_i + size_j));\n        ret = ret.update(ri, rj);\n      }\n\n      return\
    \ persistent_unionfind(ret);\n    }\n  };\n}\n"
  dependsOn:
  - Mylib/DataStructure/Array/persistent_array.cpp
  isVerificationFile: false
  path: Mylib/DataStructure/UnionFind/persistent_unionfind.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/persistent_unionfind/main.test.cpp
documentation_of: Mylib/DataStructure/UnionFind/persistent_unionfind.cpp
layout: document
title: Persistent union-find
---

## Operations

## Requirements

## Notes

## Problems

- [Persistent UnionFind](https://judge.yosupo.jp/problem/persistent_unionfind)

## References

- [https://ei1333.github.io/luzhiled/snippets/structure/union-find.html](https://ei1333.github.io/luzhiled/snippets/structure/union-find.html)
