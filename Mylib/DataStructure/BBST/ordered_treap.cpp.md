---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/BBST/treap.cpp
    title: Treap
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/BBST/ordered_treap.cpp\"\n#include <algorithm>\n\
    #line 2 \"Mylib/DataStructure/BBST/treap.cpp\"\n#include <random>\n#include <tuple>\n\
    #include <utility>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  struct\
    \ treap_node {\n    using node       = treap_node<Monoid>;\n    using value_type\
    \ = typename Monoid::value_type;\n    const static Monoid M;\n\n    static std::mt19937\
    \ rand;\n\n    value_type value, result;\n    node *left = nullptr, *right = nullptr;\n\
    \    int priority, size           = 1;\n    bool rev = false;\n\n    treap_node()\
    \ : priority(rand()) {}\n    treap_node(const value_type &value) : value(value),\
    \ result(value), priority(rand()) {}\n\n    static int count(node *t) { return\
    \ t ? t->size : 0; }\n    static value_type sum(node *t) { return t ? t->result\
    \ : M(); }\n\n    static node *update_node_status(node *t) {\n      t->size  \
    \ = count(t->right) + count(t->left) + 1;\n      t->result = M(M(sum(t->right),\
    \ sum(t->left)), t->value);\n      return t;\n    }\n\n    static void pushdown(node\
    \ *t) {\n      if (not t) return;\n      if (t->rev) {\n        std::swap(t->left,\
    \ t->right);\n        if (t->left) t->left->rev ^= true;\n        if (t->right)\
    \ t->right->rev ^= true;\n        t->rev = false;\n      }\n      update_node_status(t);\n\
    \    }\n\n    static node *insert(node *t, int k, const value_type &val) {\n \
    \     auto s = split(t, k);\n      return merge(s.first, merge(new node(val),\
    \ s.second));\n    }\n\n    static node *erase(node *t, int k) {\n      node *l,\
    \ *r, *m;\n      std::tie(l, r) = split(t, k);\n      std::tie(m, r) = split(r,\
    \ 1);\n      return merge(l, r);\n    }\n\n    static std::pair<node *, node *>\
    \ split(node *t, int k) {\n      if (not t) return std::make_pair(nullptr, nullptr);\n\
    \      pushdown(t);\n      const int c = count(t->left);\n      if (k <= c) {\n\
    \        auto s  = split(t->left, k);\n        t->left = s.second;\n        return\
    \ std::make_pair(s.first, update_node_status(t));\n      } else {\n        auto\
    \ s   = split(t->right, k - (c + 1));\n        t->right = s.first;\n        return\
    \ std::make_pair(update_node_status(t), s.second);\n      }\n    }\n\n    static\
    \ node *merge(node *l, node *r) {\n      pushdown(l);\n      pushdown(r);\n  \
    \    if (not l or not r) return l ? l : r;\n      if (l->priority > r->priority)\
    \ {\n        l->right = merge(l->right, r);\n        return update_node_status(l);\n\
    \      } else {\n        r->left = merge(l, r->left);\n        return update_node_status(r);\n\
    \      }\n    }\n\n    static node *reverse(node *t, int l, int r) {\n      node\
    \ *a, *b, *c;\n      std::tie(a, c) = split(t, l);\n      std::tie(b, c) = split(c,\
    \ r - l);\n      b->rev ^= true;\n      return t = merge(merge(a, b), c);\n  \
    \  }\n\n    static void update_node(node *t, int k, const value_type &value) {\n\
    \      const int c = count(t->left);\n      if (k == c)\n        t->value = value;\n\
    \      else if (k > c)\n        update_node(t->right, k - (c + 1), value);\n \
    \     else\n        update_node(t->left, k, value);\n      update_node_status(t);\n\
    \    }\n\n    static node *get_node(node *t, int k) {\n      if (not t) return\
    \ t;\n      pushdown(t);\n      int c = count(t->left);\n      if (k == c) return\
    \ t;\n      if (k > c)\n        return get_node(t->right, k - (c + 1));\n    \
    \  else\n        return get_node(t->left, k);\n    }\n\n    template <typename\
    \ Func>\n    static void traverse(node *t, const Func &f) {\n      if (t) {\n\
    \        pushdown(t);\n        traverse(t->left, f);\n        f(*t);\n       \
    \ traverse(t->right, f);\n      }\n    }\n  };\n\n  template <typename Monoid>\n\
    \  std::mt19937 treap_node<Monoid>::rand;\n\n  template <typename Monoid>\n  class\
    \ treap {\n  public:\n    using value_type = typename Monoid::value_type;\n\n\
    \  protected:\n    using node = treap_node<Monoid>;\n    Monoid M_;\n    node\
    \ *root_ = nullptr;\n\n    treap(node *t) : root_(t) {}\n\n  public:\n    treap()\
    \ {}\n    treap(int n) {\n      for (int i = 0; i < n; ++i) push_back(M_());\n\
    \    }\n\n    int size() const { return node::count(root_); }\n    bool empty()\
    \ const { return not root_; }\n\n    void insert(int k, const value_type &val)\
    \ {\n      root_ = node::insert(root_, k, val);\n    }\n\n    void erase(int k)\
    \ { root_ = node::erase(root_, k); }\n\n    void merge_left(treap &left) {\n \
    \     root_      = node::merge(left.root_, root_);\n      left.root_ = nullptr;\n\
    \    }\n\n    void merge_right(treap &right) {\n      root_       = node::merge(root_,\
    \ right.root_);\n      right.root_ = nullptr;\n    }\n\n    std::pair<treap, treap>\
    \ split(int k) {\n      node *l, *r;\n      std::tie(l, r) = node::split(root_,\
    \ k);\n      return std::make_pair(treap(l), treap(r));\n    }\n\n    void reverse(int\
    \ l, int r) { node::reverse(root_, l, r); }\n\n    void set(int k, const value_type\
    \ &value) { node::update_node(root_, k, value); }\n\n    value_type get(int k)\
    \ { return (node::get_node(root_, k))->value; }\n    value_type operator[](int\
    \ k) { return get(k); }\n\n    value_type fold() { return node::sum(root_); }\n\
    \    value_type fold(int l, int r) {\n      node *left, *mid, *right;\n      std::tie(mid,\
    \ right) = node::split(root_, r);\n      std::tie(left, mid)  = node::split(mid,\
    \ l);\n\n      auto ret = node::sum(mid);\n\n      mid   = node::merge(left, mid);\n\
    \      root_ = node::merge(mid, right);\n\n      return ret;\n    }\n\n    template\
    \ <typename Func>\n    void traverse(const Func &f) {\n      node::traverse(root_,\
    \ f);\n    }\n\n    void push_front(const value_type &val) { insert(0, val); }\n\
    \    void push_back(const value_type &val) { insert(size(), val); }\n\n    void\
    \ pop_front() { erase(0); }\n    void pop_back() { erase(size() - 1); }\n\n  \
    \  const value_type &front() { return get(0); }\n    const value_type &back()\
    \ { return get(size() - 1); }\n  };\n}  // namespace haar_lib\n#line 4 \"Mylib/DataStructure/BBST/ordered_treap.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  class ordered_treap\
    \ : public treap<Monoid> {\n  public:\n    using value_type = typename Monoid::value_type;\n\
    \n  private:\n    using node  = treap_node<Monoid>;\n    using super = treap<Monoid>;\n\
    \n  public:\n    ordered_treap() : super() {}\n\n  protected:\n    int lower_bound(node\
    \ *t, const value_type &val) {\n      if (not t) return 0;\n      int c = super::count(t->left);\n\
    \      if (t->value >= val)\n        return std::min(c, lower_bound(t->left, val));\n\
    \      else\n        return c + 1 + lower_bound(t->right, val);\n    }\n\n  public:\n\
    \    int lower_bound(const value_type &val) {\n      return lower_bound(super::root,\
    \ val);\n    }\n\n  protected:\n    int upper_bound(node *t, const value_type\
    \ &val) {\n      if (not t) return 0;\n      int c = super::count(t->left);\n\
    \      if (t->val > val)\n        return std::min(c, upper_bound(t->left, val));\n\
    \      else\n        return c + 1 + upper_bound(t->right, val);\n    }\n\n  public:\n\
    \    int upper_bound(const value_type &val) {\n      return upper_bound(super::root,\
    \ val);\n    }\n\n  public:\n    void insert_by_order(const value_type &val) {\n\
    \      int k = lower_bound(val);\n      super::insert(k, val);\n    }\n\n  public:\n\
    \    int find_by_order(const value_type &val) {\n      int k = lower_bound(super::root,\
    \ val);\n      if (k >= super::size()) return -1;\n      auto t = super::get(k);\n\
    \      return t == val ? k : -1;\n    }\n\n  public:\n    void erase_by_order(const\
    \ value_type &val) {\n      int k = find_by_order(val);\n      if (k == -1) return;\n\
    \      super::erase(k);\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include \"Mylib/DataStructure/BBST/treap.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  class ordered_treap\
    \ : public treap<Monoid> {\n  public:\n    using value_type = typename Monoid::value_type;\n\
    \n  private:\n    using node  = treap_node<Monoid>;\n    using super = treap<Monoid>;\n\
    \n  public:\n    ordered_treap() : super() {}\n\n  protected:\n    int lower_bound(node\
    \ *t, const value_type &val) {\n      if (not t) return 0;\n      int c = super::count(t->left);\n\
    \      if (t->value >= val)\n        return std::min(c, lower_bound(t->left, val));\n\
    \      else\n        return c + 1 + lower_bound(t->right, val);\n    }\n\n  public:\n\
    \    int lower_bound(const value_type &val) {\n      return lower_bound(super::root,\
    \ val);\n    }\n\n  protected:\n    int upper_bound(node *t, const value_type\
    \ &val) {\n      if (not t) return 0;\n      int c = super::count(t->left);\n\
    \      if (t->val > val)\n        return std::min(c, upper_bound(t->left, val));\n\
    \      else\n        return c + 1 + upper_bound(t->right, val);\n    }\n\n  public:\n\
    \    int upper_bound(const value_type &val) {\n      return upper_bound(super::root,\
    \ val);\n    }\n\n  public:\n    void insert_by_order(const value_type &val) {\n\
    \      int k = lower_bound(val);\n      super::insert(k, val);\n    }\n\n  public:\n\
    \    int find_by_order(const value_type &val) {\n      int k = lower_bound(super::root,\
    \ val);\n      if (k >= super::size()) return -1;\n      auto t = super::get(k);\n\
    \      return t == val ? k : -1;\n    }\n\n  public:\n    void erase_by_order(const\
    \ value_type &val) {\n      int k = find_by_order(val);\n      if (k == -1) return;\n\
    \      super::erase(k);\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/DataStructure/BBST/treap.cpp
  isVerificationFile: false
  path: Mylib/DataStructure/BBST/ordered_treap.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Mylib/DataStructure/BBST/ordered_treap.cpp
layout: document
title: Treap (Ordered set)
---

## Operations

## Requirements

## Notes

## Problems

## References
