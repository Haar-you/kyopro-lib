---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  class\
    \ persistent_segment_tree {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    struct node {\n      value_type value;\n  \
    \    node *left = nullptr, *right = nullptr;\n      node(const value_type &value):\
    \ value(value){}\n    };\n\n    int depth;\n    node *root = nullptr;\n\n    persistent_segment_tree(int\
    \ depth, node *root): depth(depth), root(root){}\n\n    node* init(node *t, const\
    \ std::vector<value_type> &init_list, int d, int &pos){\n      if(d == depth){\n\
    \        t = new node(pos < (int)init_list.size() ? init_list[pos] : M());\n \
    \       ++pos;\n      }else{\n        t = new node(M());\n        t->left = init(t->left,\
    \ init_list, d + 1, pos);\n        t->right = init(t->right, init_list, d + 1,\
    \ pos);\n        t->value = M(t->left->value, t->right->value);\n      }\n   \
    \   return t;\n    }\n\n  public:\n    persistent_segment_tree(const std::vector<value_type>\
    \ &init_list){\n      const int size = init_list.size();\n      depth = size ==\
    \ 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;\n      int pos = 0;\n      root =\
    \ init(root, init_list, 1, pos);\n    }\n\n    persistent_segment_tree(int size,\
    \ const value_type &value = M()){\n      depth = size == 1 ? 1 : 32 - __builtin_clz(size\
    \ - 1) + 1;\n      int pos = 0;\n      root = init(root, std::vector<value_type>(size,\
    \ value), 1, pos);\n    }\n\n  protected:\n    node* update(node *t, int l, int\
    \ r, int pos, const value_type &val) const {\n      if(r <= pos or pos + 1 <=\
    \ l){\n        return t;\n      }else if(pos <= l and r <= pos + 1){\n       \
    \ return new node(val);\n      }else{\n        const int m = (l + r) >> 1;\n \
    \       auto lp = update(t->left, l, m, pos, val);\n        auto rp = update(t->right,\
    \ m, r, pos, val);\n\n        node *s = new node(M(lp->value, rp->value));\n\n\
    \        s->left = lp;\n        s->right = rp;\n\n        return s;\n      }\n\
    \    }\n\n  public:\n    persistent_segment_tree update(int i, const value_type\
    \ &val) const {\n      node *t = update(root, 0, 1 << (depth - 1), i, val);\n\
    \      return persistent_segment_tree(depth, t);\n    }\n\n  protected:\n    value_type\
    \ get(node *t, int i, int j, int l, int r) const {\n      if(i <= l and r <= j)\
    \ return t->value;\n      if(r <= i or j <= l) return M();\n      const int m\
    \ = (l + r) >> 1;\n      return M(get(t->left, i, j, l, m), get(t->right, i, j,\
    \ m, r));\n    }\n\n  public:\n    value_type get(int i, int j) const {\n    \
    \  return get(root, i, j, 0, 1 << (depth - 1));\n    }\n\n    value_type operator[](int\
    \ i) const {\n      return get(i, i + 1);\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class persistent_segment_tree {\n    using value_type = typename\
    \ Monoid::value_type;\n    const static Monoid M;\n\n    struct node {\n     \
    \ value_type value;\n      node *left = nullptr, *right = nullptr;\n      node(const\
    \ value_type &value): value(value){}\n    };\n\n    int depth;\n    node *root\
    \ = nullptr;\n\n    persistent_segment_tree(int depth, node *root): depth(depth),\
    \ root(root){}\n\n    node* init(node *t, const std::vector<value_type> &init_list,\
    \ int d, int &pos){\n      if(d == depth){\n        t = new node(pos < (int)init_list.size()\
    \ ? init_list[pos] : M());\n        ++pos;\n      }else{\n        t = new node(M());\n\
    \        t->left = init(t->left, init_list, d + 1, pos);\n        t->right = init(t->right,\
    \ init_list, d + 1, pos);\n        t->value = M(t->left->value, t->right->value);\n\
    \      }\n      return t;\n    }\n\n  public:\n    persistent_segment_tree(const\
    \ std::vector<value_type> &init_list){\n      const int size = init_list.size();\n\
    \      depth = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;\n      int pos\
    \ = 0;\n      root = init(root, init_list, 1, pos);\n    }\n\n    persistent_segment_tree(int\
    \ size, const value_type &value = M()){\n      depth = size == 1 ? 1 : 32 - __builtin_clz(size\
    \ - 1) + 1;\n      int pos = 0;\n      root = init(root, std::vector<value_type>(size,\
    \ value), 1, pos);\n    }\n\n  protected:\n    node* update(node *t, int l, int\
    \ r, int pos, const value_type &val) const {\n      if(r <= pos or pos + 1 <=\
    \ l){\n        return t;\n      }else if(pos <= l and r <= pos + 1){\n       \
    \ return new node(val);\n      }else{\n        const int m = (l + r) >> 1;\n \
    \       auto lp = update(t->left, l, m, pos, val);\n        auto rp = update(t->right,\
    \ m, r, pos, val);\n\n        node *s = new node(M(lp->value, rp->value));\n\n\
    \        s->left = lp;\n        s->right = rp;\n\n        return s;\n      }\n\
    \    }\n\n  public:\n    persistent_segment_tree update(int i, const value_type\
    \ &val) const {\n      node *t = update(root, 0, 1 << (depth - 1), i, val);\n\
    \      return persistent_segment_tree(depth, t);\n    }\n\n  protected:\n    value_type\
    \ get(node *t, int i, int j, int l, int r) const {\n      if(i <= l and r <= j)\
    \ return t->value;\n      if(r <= i or j <= l) return M();\n      const int m\
    \ = (l + r) >> 1;\n      return M(get(t->left, i, j, l, m), get(t->right, i, j,\
    \ m, r));\n    }\n\n  public:\n    value_type get(int i, int j) const {\n    \
    \  return get(root, i, j, 0, 1 << (depth - 1));\n    }\n\n    value_type operator[](int\
    \ i) const {\n      return get(i, i + 1);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
documentation_of: Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp
layout: document
title: Persistent segment tree
---

## Operations
モノイド$(M, \circ, e)$上の列を扱う。
- `PersistentSegmentTree(n)`
- `PersistentSegmentTree(a[n])`
- `update(i, v)`
	- $a_i \leftarrow a_i \circ v$で更新した`PersistentSegmentTree`を返す。
	- Time complexity $O(\log N$)
- `get(i, j)`
	- $a_i \circ \ldots \circ a_{j-1}$を返す。
	- Time complexity $O(\log N$)
- `at(i)`
	- $a_i$を返す。
	- Time complexity $O(\log N$)

## Requirements

## Notes

- 2次元矩形領域中の点の総和を求めるようなクエリを処理できる。
	- 逆元が必要。 (総和, xorなど)

## Problems

- [yukicoder No.877 Range ReLU Query](https://yukicoder.me/problems/no/877)
- [Codeforces Round #276 (Div. 1) E. Sign on Fence](https://codeforces.com/contest/484/problem/E)

## References

- [http://sigma425.hatenablog.com/entry/2014/12/30/164148](http://sigma425.hatenablog.com/entry/2014/12/30/164148)
- [http://omochan.hatenablog.com/entry/2017/09/07/002323](http://omochan.hatenablog.com/entry/2017/09/07/002323)
- [https://qiita.com/hotman78/items/9c643feae1de087e6fc5](https://qiita.com/hotman78/items/9c643feae1de087e6fc5)
