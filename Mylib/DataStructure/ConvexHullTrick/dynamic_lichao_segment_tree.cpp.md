---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/line_add_get_min/main.dynamic.test.cpp
    title: test/yosupo-judge/line_add_get_min/main.dynamic.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp
    title: test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp\"\
    \n#include <utility>\n#include <optional>\n\nnamespace haar_lib {\n  template\
    \ <typename T, typename Comparator>\n  class dynamic_lichao_segment_tree {\n \
    \ public:\n    using value_type = T;\n\n  private:\n    using line = std::pair<T,\
    \ T>;\n\n    struct node {\n      std::optional<line> value;\n      int64_t l,\
    \ r;\n      node *l_child = nullptr, *r_child = nullptr;\n      node(std::optional<line>\
    \ value, int64_t l, int64_t r): value(value), l(l), r(r){}\n    };\n\n    Comparator\
    \ cmp_ = Comparator();\n    int64_t MIN_, MAX_;\n    node *root_ = nullptr;\n\n\
    \    T chm(const T &a, const T &b) const {\n      return cmp_(a, b) ? a : b;\n\
    \    }\n\n  public:\n    dynamic_lichao_segment_tree(){}\n    dynamic_lichao_segment_tree(int64_t\
    \ MIN, int64_t MAX): MIN_(MIN), MAX_(MAX){}\n\n    T apply(const line &l, const\
    \ T &x) const {\n      return l.first * x + l.second;\n    }\n\n  private:\n \
    \   node* update(node *t, line new_line, int64_t l, int64_t r){\n      if(not\
    \ t){\n        return t = new node(new_line, l, r);\n      }\n\n      if(not t->value){\n\
    \        t->value = new_line;\n        return t;\n      }\n\n      if(l + 1 ==\
    \ r){\n        if(cmp_(apply(new_line, l), apply(*(t->value), l))){\n        \
    \  t->value = new_line;\n        }\n        return t;\n      }\n\n      const\
    \ auto m = (l + r) / 2;\n\n      bool left = cmp_(apply(new_line, l), apply(*(t->value),\
    \ l));\n      bool mid = cmp_(apply(new_line, m), apply(*(t->value), m));\n  \
    \    bool right = cmp_(apply(new_line, r), apply(*(t->value), r));\n\n      if(left\
    \ and right){\n        t->value = new_line;\n        return t;\n      }\n\n  \
    \    if(not left and not right){\n        return t;\n      }\n\n      if(mid){\n\
    \        std::swap(*(t->value), new_line);\n      }\n\n      if(left != mid){\n\
    \        t->l_child = update(t->l_child, new_line, l, m);\n      }else{\n    \
    \    t->r_child = update(t->r_child, new_line, m, r);\n      }\n\n      return\
    \ t;\n    }\n\n    node* update_segment(node *t, line new_line, int64_t l, int64_t\
    \ r, int64_t sl, int64_t sr){\n      if(r < sl or sr < l) return t;\n      if(sl\
    \ <= l and r <= sr){\n        return t = update(t, new_line, l, r);\n      }\n\
    \n      if(l + 1 == r){\n        return t;\n      }\n\n      if(not t) t = new\
    \ node(std::nullopt, l, r);\n      else{\n        if(t->value){\n          if(\n\
    \            cmp_(apply(*(t->value), l), apply(new_line, l)) and\n           \
    \ cmp_(apply(*(t->value), r), apply(new_line, r))\n          ){\n            return\
    \ t;\n          }\n        }\n      }\n\n      const auto m = (l + r) / 2;\n\n\
    \      t->l_child = update_segment(t->l_child, new_line, l, m, sl, sr);\n    \
    \  t->r_child = update_segment(t->r_child, new_line, m, r, sl, sr);\n\n      return\
    \ t;\n    }\n\n  public:\n    void add_line(T a, T b){\n      root_ = update(root_,\
    \ std::make_pair(a, b), MIN_, MAX_);\n    }\n\n    void add_segment(int64_t l,\
    \ int64_t r, T a, T b){\n      root_ = update_segment(root_, std::make_pair(a,\
    \ b), MIN_, MAX_, l, r);\n    }\n\n    auto operator()(const int64_t &x) const\
    \ {\n      std::optional<T> ret;\n      node *cur = root_;\n\n      while(cur){\n\
    \        if(cur->value){\n          if(not ret) ret = apply(*(cur->value), x);\n\
    \          else ret = chm(*ret, apply(*(cur->value), x));\n        }\n\n     \
    \   const auto m = (cur->l + cur->r) / 2;\n        if(x < m) cur = cur->l_child;\n\
    \        else cur = cur->r_child;\n      }\n\n      return ret;\n    }\n  };\n\
    }\n"
  code: "#pragma once\n#include <utility>\n#include <optional>\n\nnamespace haar_lib\
    \ {\n  template <typename T, typename Comparator>\n  class dynamic_lichao_segment_tree\
    \ {\n  public:\n    using value_type = T;\n\n  private:\n    using line = std::pair<T,\
    \ T>;\n\n    struct node {\n      std::optional<line> value;\n      int64_t l,\
    \ r;\n      node *l_child = nullptr, *r_child = nullptr;\n      node(std::optional<line>\
    \ value, int64_t l, int64_t r): value(value), l(l), r(r){}\n    };\n\n    Comparator\
    \ cmp_ = Comparator();\n    int64_t MIN_, MAX_;\n    node *root_ = nullptr;\n\n\
    \    T chm(const T &a, const T &b) const {\n      return cmp_(a, b) ? a : b;\n\
    \    }\n\n  public:\n    dynamic_lichao_segment_tree(){}\n    dynamic_lichao_segment_tree(int64_t\
    \ MIN, int64_t MAX): MIN_(MIN), MAX_(MAX){}\n\n    T apply(const line &l, const\
    \ T &x) const {\n      return l.first * x + l.second;\n    }\n\n  private:\n \
    \   node* update(node *t, line new_line, int64_t l, int64_t r){\n      if(not\
    \ t){\n        return t = new node(new_line, l, r);\n      }\n\n      if(not t->value){\n\
    \        t->value = new_line;\n        return t;\n      }\n\n      if(l + 1 ==\
    \ r){\n        if(cmp_(apply(new_line, l), apply(*(t->value), l))){\n        \
    \  t->value = new_line;\n        }\n        return t;\n      }\n\n      const\
    \ auto m = (l + r) / 2;\n\n      bool left = cmp_(apply(new_line, l), apply(*(t->value),\
    \ l));\n      bool mid = cmp_(apply(new_line, m), apply(*(t->value), m));\n  \
    \    bool right = cmp_(apply(new_line, r), apply(*(t->value), r));\n\n      if(left\
    \ and right){\n        t->value = new_line;\n        return t;\n      }\n\n  \
    \    if(not left and not right){\n        return t;\n      }\n\n      if(mid){\n\
    \        std::swap(*(t->value), new_line);\n      }\n\n      if(left != mid){\n\
    \        t->l_child = update(t->l_child, new_line, l, m);\n      }else{\n    \
    \    t->r_child = update(t->r_child, new_line, m, r);\n      }\n\n      return\
    \ t;\n    }\n\n    node* update_segment(node *t, line new_line, int64_t l, int64_t\
    \ r, int64_t sl, int64_t sr){\n      if(r < sl or sr < l) return t;\n      if(sl\
    \ <= l and r <= sr){\n        return t = update(t, new_line, l, r);\n      }\n\
    \n      if(l + 1 == r){\n        return t;\n      }\n\n      if(not t) t = new\
    \ node(std::nullopt, l, r);\n      else{\n        if(t->value){\n          if(\n\
    \            cmp_(apply(*(t->value), l), apply(new_line, l)) and\n           \
    \ cmp_(apply(*(t->value), r), apply(new_line, r))\n          ){\n            return\
    \ t;\n          }\n        }\n      }\n\n      const auto m = (l + r) / 2;\n\n\
    \      t->l_child = update_segment(t->l_child, new_line, l, m, sl, sr);\n    \
    \  t->r_child = update_segment(t->r_child, new_line, m, r, sl, sr);\n\n      return\
    \ t;\n    }\n\n  public:\n    void add_line(T a, T b){\n      root_ = update(root_,\
    \ std::make_pair(a, b), MIN_, MAX_);\n    }\n\n    void add_segment(int64_t l,\
    \ int64_t r, T a, T b){\n      root_ = update_segment(root_, std::make_pair(a,\
    \ b), MIN_, MAX_, l, r);\n    }\n\n    auto operator()(const int64_t &x) const\
    \ {\n      std::optional<T> ret;\n      node *cur = root_;\n\n      while(cur){\n\
    \        if(cur->value){\n          if(not ret) ret = apply(*(cur->value), x);\n\
    \          else ret = chm(*ret, apply(*(cur->value), x));\n        }\n\n     \
    \   const auto m = (cur->l + cur->r) / 2;\n        if(x < m) cur = cur->l_child;\n\
    \        else cur = cur->r_child;\n      }\n\n      return ret;\n    }\n  };\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo-judge/line_add_get_min/main.dynamic.test.cpp
  - test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp
documentation_of: Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp
layout: document
title: Dynamic LiChao segment tree
---

## Operations

## Requirements

## Notes

- 最悪ケースではメモリ使用量・実行時間が共に悪い。

## Problems

## References

- [https://ei1333.github.io/library/library/structure/convex-hull-trick/dynamic-li-chao-tree.cpp.html](https://ei1333.github.io/library/library/structure/convex-hull-trick/dynamic-li-chao-tree.cpp.html)
