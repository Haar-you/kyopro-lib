---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_F/main.dynamic.test.cpp
    title: test/aoj/DSL_2_F/main.dynamic.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename MonoidGet,\
    \ typename MonoidUpdate, template <typename, typename> typename Connector>\n \
    \ class dynamic_lazy_segment_tree {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n    Connector<MonoidGet,\
    \ MonoidUpdate> M;\n    MonoidGet M_get;\n    MonoidUpdate M_update;\n\n    struct\
    \ node {\n      value_type_get value;\n      value_type_update lazy;\n      node\
    \ *left = nullptr, *right = nullptr;\n      node(){}\n      node(const value_type_get\
    \ &value, const value_type_update &lazy): value(value), lazy(lazy){}\n    };\n\
    \n    int64_t depth, size, hsize;\n    node *root = nullptr;\n\n    void propagate(node\
    \ *t, int64_t l, int64_t r){\n      if(t->lazy == M_update()) return;\n      if(r\
    \ - l > 1){\n        if(not t->left) t->left = new node(M_get(), M_update());\n\
    \        t->left->lazy = M_update(t->lazy, t->left->lazy);\n        if(not t->right)\
    \ t->right = new node(M_get(), M_update());\n        t->right->lazy = M_update(t->lazy,\
    \ t->right->lazy);\n      }\n      int64_t len = r - l;\n      t->value = M(t->value,\
    \ t->lazy, len);\n      t->lazy = M_update();\n    }\n\n    node* update(node\
    \ *t, int64_t l, int64_t r, int64_t x, int64_t y, value_type_update value){\n\
    \      if(not t) t = new node(M_get(), M_update());\n\n      propagate(t, l, r);\n\
    \      if(r - l == 1){\n        if(x <= l and r <= y) t->lazy = M_update(value,\
    \ t->lazy);\n        propagate(t, l, r);\n        return t;\n      }\n\n     \
    \ if(r < x or y < l) return t;\n      if(x <= l and r <= y){\n        t->lazy\
    \ = M_update(value, t->lazy);\n        propagate(t, l, r);\n        return t;\n\
    \      }\n\n      t->left = update(t->left, l, (l + r) / 2, x, y, value);\n  \
    \    t->right = update(t->right, (l + r) / 2, r, x, y, value);\n      t->value\
    \ = M_get(t->left->value, t->right->value);\n\n      return t;\n    }\n\n    value_type_get\
    \ get(node *t, int64_t l, int64_t r, int64_t x, int64_t y){\n      if(not t) return\
    \ M_get();\n\n      propagate(t, l, r);\n      if(r <= x or y <= l) return M_get();\n\
    \      if(x <= l and r <= y) return t->value;\n\n      return M_get(\n       \
    \ get(t->left, l, (l + r) / 2, x, y),\n        get(t->right, (l + r) / 2, r, x,\
    \ y)\n      );\n    }\n\n  public:\n    dynamic_lazy_segment_tree(int64_t n):\n\
    \      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),\n      size(1LL <<\
    \ depth),\n      hsize(size / 2)\n    {\n      root = new node(M_get(), M_update());\n\
    \    }\n\n    void update(int64_t l, int64_t r, value_type_update value){\n  \
    \    update(root, 0, hsize, l, r, value);\n    }\n\n    value_type_get fold(int64_t\
    \ l, int64_t r){\n      return get(root, 0, hsize, l, r);\n    }\n\n    value_type_get\
    \ operator[](int64_t i){\n      return fold(i, i + 1);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename\
    \ MonoidGet, typename MonoidUpdate, template <typename, typename> typename Connector>\n\
    \  class dynamic_lazy_segment_tree {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n    Connector<MonoidGet,\
    \ MonoidUpdate> M;\n    MonoidGet M_get;\n    MonoidUpdate M_update;\n\n    struct\
    \ node {\n      value_type_get value;\n      value_type_update lazy;\n      node\
    \ *left = nullptr, *right = nullptr;\n      node(){}\n      node(const value_type_get\
    \ &value, const value_type_update &lazy): value(value), lazy(lazy){}\n    };\n\
    \n    int64_t depth, size, hsize;\n    node *root = nullptr;\n\n    void propagate(node\
    \ *t, int64_t l, int64_t r){\n      if(t->lazy == M_update()) return;\n      if(r\
    \ - l > 1){\n        if(not t->left) t->left = new node(M_get(), M_update());\n\
    \        t->left->lazy = M_update(t->lazy, t->left->lazy);\n        if(not t->right)\
    \ t->right = new node(M_get(), M_update());\n        t->right->lazy = M_update(t->lazy,\
    \ t->right->lazy);\n      }\n      int64_t len = r - l;\n      t->value = M(t->value,\
    \ t->lazy, len);\n      t->lazy = M_update();\n    }\n\n    node* update(node\
    \ *t, int64_t l, int64_t r, int64_t x, int64_t y, value_type_update value){\n\
    \      if(not t) t = new node(M_get(), M_update());\n\n      propagate(t, l, r);\n\
    \      if(r - l == 1){\n        if(x <= l and r <= y) t->lazy = M_update(value,\
    \ t->lazy);\n        propagate(t, l, r);\n        return t;\n      }\n\n     \
    \ if(r < x or y < l) return t;\n      if(x <= l and r <= y){\n        t->lazy\
    \ = M_update(value, t->lazy);\n        propagate(t, l, r);\n        return t;\n\
    \      }\n\n      t->left = update(t->left, l, (l + r) / 2, x, y, value);\n  \
    \    t->right = update(t->right, (l + r) / 2, r, x, y, value);\n      t->value\
    \ = M_get(t->left->value, t->right->value);\n\n      return t;\n    }\n\n    value_type_get\
    \ get(node *t, int64_t l, int64_t r, int64_t x, int64_t y){\n      if(not t) return\
    \ M_get();\n\n      propagate(t, l, r);\n      if(r <= x or y <= l) return M_get();\n\
    \      if(x <= l and r <= y) return t->value;\n\n      return M_get(\n       \
    \ get(t->left, l, (l + r) / 2, x, y),\n        get(t->right, (l + r) / 2, r, x,\
    \ y)\n      );\n    }\n\n  public:\n    dynamic_lazy_segment_tree(int64_t n):\n\
    \      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),\n      size(1LL <<\
    \ depth),\n      hsize(size / 2)\n    {\n      root = new node(M_get(), M_update());\n\
    \    }\n\n    void update(int64_t l, int64_t r, value_type_update value){\n  \
    \    update(root, 0, hsize, l, r, value);\n    }\n\n    value_type_get fold(int64_t\
    \ l, int64_t r){\n      return get(root, 0, hsize, l, r);\n    }\n\n    value_type_get\
    \ operator[](int64_t i){\n      return fold(i, i + 1);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_F/main.dynamic.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp
layout: document
title: Dynamic lazy segment tree
---

## Operations

## Requirements

## Notes

## Problems

## References
