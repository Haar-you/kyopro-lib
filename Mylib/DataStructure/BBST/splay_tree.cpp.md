---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508/main.splay_tree.test.cpp
    title: test/aoj/1508/main.splay_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/BBST/splay_tree.cpp\"\n#include <utility>\n\
    #include <tuple>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  struct\
    \ splay_node {\n    using node = splay_node<Monoid>;\n    using value_type = typename\
    \ Monoid::value_type;\n    const static Monoid M;\n\n    node *left = nullptr,\
    \ *right = nullptr, *parent = nullptr;\n    int size;\n    value_type value =\
    \ M(), result = M();\n\n    splay_node(): size(1){}\n    splay_node(const value_type\
    \ &value): size(1), value(value){}\n\n    void rotate(){\n      node *p, *pp,\
    \ *c;\n\n      p = this->parent;\n      pp = p->parent;\n\n      if(p->left ==\
    \ this){\n        c = this->right;\n        p->set_left(c);\n        this->set_right(p);\n\
    \      }else{\n        c = this->left;\n        p->set_right(c);\n        this->set_left(p);\n\
    \      }\n\n      if(pp){\n        if(pp->left == p) pp->left = this;\n      \
    \  if(pp->right == p) pp->right = this;\n      }\n\n      this->parent = pp;\n\
    \n      p->update();\n      this->update();\n    }\n\n    int status(){\n    \
    \  if(not this->parent) return 0;\n      if(this->parent->left == this) return\
    \ 1;\n      if(this->parent->right == this) return -1;\n      return 0;\n    }\n\
    \n    void splay(){\n      while(status() != 0){\n        if(this->parent->status()\
    \ == 0){\n          this->rotate();\n        }else if(this->status() == this->parent->status()){\n\
    \          this->parent->rotate();\n          this->rotate();\n        }else{\n\
    \          this->rotate();\n          this->rotate();\n        }\n      }\n  \
    \  }\n\n    void update(){\n      this->size = 1;\n      if(this->left) this->size\
    \ += this->left->size;\n      if(this->right) this->size += this->right->size;\n\
    \n      this->result = this->value;\n      if(this->left) this->result = M(this->result,\
    \ this->left->result);\n      if(this->right) this->result = M(this->result, this->right->result);\n\
    \    }\n\n    void set_left(node *l){\n      this->left = l;\n      if(l) l->parent\
    \ = this;\n    }\n\n    void set_right(node *r){\n      this->right = r;\n   \
    \   if(r) r->parent = this;\n    }\n\n    static node* get(node *root, int index){\n\
    \      if(not root) return root;\n      node *cur = root;\n\n      while(1){\n\
    \        int lsize = cur->left ? cur->left->size : 0;\n\n        if(index < lsize){\n\
    \          cur = cur->left;\n        }else if(index == lsize){\n          cur->splay();\n\
    \          return cur;\n        }else{\n          cur = cur->right;\n        \
    \  index -= lsize + 1;\n        }\n      }\n    }\n\n    static node* merge(node\
    \ *left, node *right){\n      if(not left) return right;\n      if(not right)\
    \ return left;\n\n      node *cur = node::get(left, left->size - 1);\n\n     \
    \ cur->right = right;\n      right->parent = cur;\n\n      right->update();\n\
    \      cur->update();\n\n      return cur;\n    }\n\n    static std::pair<node*,\
    \ node*> split(node *root, int index){\n      if(not root) return std::make_pair(nullptr,\
    \ nullptr);\n      if(index >= root->size) return std::make_pair(root, nullptr);\n\
    \n      auto *cur = node::get(root, index);\n      auto *left = cur->left;\n\n\
    \      if(left) left->parent = nullptr;\n      cur->left = nullptr;\n\n      if(left)\
    \ left->update();\n      cur->update();\n\n      return std::make_pair(left, cur);\n\
    \    }\n\n    template <typename Func>\n    static void traverse(node *cur, const\
    \ Func &f){\n      if(cur){\n        traverse(cur->left, f);\n        f(*cur);\n\
    \        traverse(cur->right, f);\n      }\n    }\n  };\n\n  template <typename\
    \ Monoid>\n  class splay_tree {\n  public:\n    using value_type = typename Monoid::value_type;\n\
    \n  private:\n    using node = splay_node<Monoid>;\n    Monoid M_;\n    node *root_;\n\
    \n    splay_tree(node *root): root_(root){}\n\n  public:\n    splay_tree(): root_(nullptr){}\n\
    \    splay_tree(int N): root_(nullptr){\n      for(int i = 0; i < N; ++i) push_back(M_());\n\
    \    }\n\n    static auto singleton(const value_type &value){return splay_tree(new\
    \ node(value));}\n\n    int size() const {return root_ ? root_->size : 0;}\n \
    \   bool empty() const {return not root_;}\n\n    const value_type get(int index){root_\
    \ = node::get(root_, index); return root_->value;}\n    const value_type operator[](int\
    \ index){return get(index);}\n\n    void set(int index, const value_type &value){\n\
    \      root_ = node::get(root_, index); root_->value = value; root_->update();\n\
    \    }\n\n    void merge_right(splay_tree &right){\n      root_ = node::merge(root_,\
    \ right.root); right.root_ = nullptr;\n    }\n\n    void merge_left(splay_tree\
    \ &left){\n      root_ = node::merge(left.root_, root_); left.root_ = nullptr;\n\
    \    }\n\n    auto split(int index){\n      node *left, *right; std::tie(left,\
    \ right) = node::split(root_, index);\n      return std::make_pair(splay_tree(left),\
    \ splay_tree(right));\n    }\n\n    void insert(int index, const value_type &value){\n\
    \      auto s = node::split(root_, index);\n      root_ = node::merge(s.first,\
    \ node::merge(new node(value), s.second));\n    }\n\n    void erase(int index){\n\
    \      node *left, *right;\n      std::tie(left, right) = node::split(root_, index);\n\
    \      std::tie(std::ignore, right) = node::split(right, 1);\n      root_ = node::merge(left,\
    \ right);\n    }\n\n    const value_type fold(){return root_->result;}\n    const\
    \ value_type fold(int l, int r){ // [l, r)\n      node *left, *mid, *right;\n\
    \      std::tie(mid, right) = node::split(root_, r);\n      std::tie(left, mid)\
    \ = node::split(mid, l);\n\n      auto ret = mid->result;\n\n      mid = node::merge(left,\
    \ mid);\n      root_ = node::merge(mid, right);\n\n      return ret;\n    }\n\n\
    \    void push_back(const value_type &value){insert(size(), value);}\n    void\
    \ push_front(const value_type &value){insert(0, value);}\n\n    void pop_back(){erase(size()\
    \ - 1);}\n    void pop_front(){erase(0);}\n\n    template <typename Func>\n  \
    \  void traverse(const Func &f) const {\n      node::traverse(root_, f);\n   \
    \ }\n  };\n}\n"
  code: "#pragma once\n#include <utility>\n#include <tuple>\n\nnamespace haar_lib\
    \ {\n  template <typename Monoid>\n  struct splay_node {\n    using node = splay_node<Monoid>;\n\
    \    using value_type = typename Monoid::value_type;\n    const static Monoid\
    \ M;\n\n    node *left = nullptr, *right = nullptr, *parent = nullptr;\n    int\
    \ size;\n    value_type value = M(), result = M();\n\n    splay_node(): size(1){}\n\
    \    splay_node(const value_type &value): size(1), value(value){}\n\n    void\
    \ rotate(){\n      node *p, *pp, *c;\n\n      p = this->parent;\n      pp = p->parent;\n\
    \n      if(p->left == this){\n        c = this->right;\n        p->set_left(c);\n\
    \        this->set_right(p);\n      }else{\n        c = this->left;\n        p->set_right(c);\n\
    \        this->set_left(p);\n      }\n\n      if(pp){\n        if(pp->left ==\
    \ p) pp->left = this;\n        if(pp->right == p) pp->right = this;\n      }\n\
    \n      this->parent = pp;\n\n      p->update();\n      this->update();\n    }\n\
    \n    int status(){\n      if(not this->parent) return 0;\n      if(this->parent->left\
    \ == this) return 1;\n      if(this->parent->right == this) return -1;\n     \
    \ return 0;\n    }\n\n    void splay(){\n      while(status() != 0){\n       \
    \ if(this->parent->status() == 0){\n          this->rotate();\n        }else if(this->status()\
    \ == this->parent->status()){\n          this->parent->rotate();\n          this->rotate();\n\
    \        }else{\n          this->rotate();\n          this->rotate();\n      \
    \  }\n      }\n    }\n\n    void update(){\n      this->size = 1;\n      if(this->left)\
    \ this->size += this->left->size;\n      if(this->right) this->size += this->right->size;\n\
    \n      this->result = this->value;\n      if(this->left) this->result = M(this->result,\
    \ this->left->result);\n      if(this->right) this->result = M(this->result, this->right->result);\n\
    \    }\n\n    void set_left(node *l){\n      this->left = l;\n      if(l) l->parent\
    \ = this;\n    }\n\n    void set_right(node *r){\n      this->right = r;\n   \
    \   if(r) r->parent = this;\n    }\n\n    static node* get(node *root, int index){\n\
    \      if(not root) return root;\n      node *cur = root;\n\n      while(1){\n\
    \        int lsize = cur->left ? cur->left->size : 0;\n\n        if(index < lsize){\n\
    \          cur = cur->left;\n        }else if(index == lsize){\n          cur->splay();\n\
    \          return cur;\n        }else{\n          cur = cur->right;\n        \
    \  index -= lsize + 1;\n        }\n      }\n    }\n\n    static node* merge(node\
    \ *left, node *right){\n      if(not left) return right;\n      if(not right)\
    \ return left;\n\n      node *cur = node::get(left, left->size - 1);\n\n     \
    \ cur->right = right;\n      right->parent = cur;\n\n      right->update();\n\
    \      cur->update();\n\n      return cur;\n    }\n\n    static std::pair<node*,\
    \ node*> split(node *root, int index){\n      if(not root) return std::make_pair(nullptr,\
    \ nullptr);\n      if(index >= root->size) return std::make_pair(root, nullptr);\n\
    \n      auto *cur = node::get(root, index);\n      auto *left = cur->left;\n\n\
    \      if(left) left->parent = nullptr;\n      cur->left = nullptr;\n\n      if(left)\
    \ left->update();\n      cur->update();\n\n      return std::make_pair(left, cur);\n\
    \    }\n\n    template <typename Func>\n    static void traverse(node *cur, const\
    \ Func &f){\n      if(cur){\n        traverse(cur->left, f);\n        f(*cur);\n\
    \        traverse(cur->right, f);\n      }\n    }\n  };\n\n  template <typename\
    \ Monoid>\n  class splay_tree {\n  public:\n    using value_type = typename Monoid::value_type;\n\
    \n  private:\n    using node = splay_node<Monoid>;\n    Monoid M_;\n    node *root_;\n\
    \n    splay_tree(node *root): root_(root){}\n\n  public:\n    splay_tree(): root_(nullptr){}\n\
    \    splay_tree(int N): root_(nullptr){\n      for(int i = 0; i < N; ++i) push_back(M_());\n\
    \    }\n\n    static auto singleton(const value_type &value){return splay_tree(new\
    \ node(value));}\n\n    int size() const {return root_ ? root_->size : 0;}\n \
    \   bool empty() const {return not root_;}\n\n    const value_type get(int index){root_\
    \ = node::get(root_, index); return root_->value;}\n    const value_type operator[](int\
    \ index){return get(index);}\n\n    void set(int index, const value_type &value){\n\
    \      root_ = node::get(root_, index); root_->value = value; root_->update();\n\
    \    }\n\n    void merge_right(splay_tree &right){\n      root_ = node::merge(root_,\
    \ right.root); right.root_ = nullptr;\n    }\n\n    void merge_left(splay_tree\
    \ &left){\n      root_ = node::merge(left.root_, root_); left.root_ = nullptr;\n\
    \    }\n\n    auto split(int index){\n      node *left, *right; std::tie(left,\
    \ right) = node::split(root_, index);\n      return std::make_pair(splay_tree(left),\
    \ splay_tree(right));\n    }\n\n    void insert(int index, const value_type &value){\n\
    \      auto s = node::split(root_, index);\n      root_ = node::merge(s.first,\
    \ node::merge(new node(value), s.second));\n    }\n\n    void erase(int index){\n\
    \      node *left, *right;\n      std::tie(left, right) = node::split(root_, index);\n\
    \      std::tie(std::ignore, right) = node::split(right, 1);\n      root_ = node::merge(left,\
    \ right);\n    }\n\n    const value_type fold(){return root_->result;}\n    const\
    \ value_type fold(int l, int r){ // [l, r)\n      node *left, *mid, *right;\n\
    \      std::tie(mid, right) = node::split(root_, r);\n      std::tie(left, mid)\
    \ = node::split(mid, l);\n\n      auto ret = mid->result;\n\n      mid = node::merge(left,\
    \ mid);\n      root_ = node::merge(mid, right);\n\n      return ret;\n    }\n\n\
    \    void push_back(const value_type &value){insert(size(), value);}\n    void\
    \ push_front(const value_type &value){insert(0, value);}\n\n    void pop_back(){erase(size()\
    \ - 1);}\n    void pop_front(){erase(0);}\n\n    template <typename Func>\n  \
    \  void traverse(const Func &f) const {\n      node::traverse(root_, f);\n   \
    \ }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/BBST/splay_tree.cpp
  requiredBy: []
  timestamp: '2020-09-29 00:55:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1508/main.splay_tree.test.cpp
documentation_of: Mylib/DataStructure/BBST/splay_tree.cpp
layout: document
title: Splay tree
---

## Operations

## Requirements

## Notes

## Problems

## References
