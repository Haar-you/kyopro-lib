---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
    title: test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp\"\
    \n#include <vector>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class persistent_segment_tree {\n  public:\n    using value_type\
    \ = typename Monoid::value_type;\n\n  private:\n    struct node {\n      value_type\
    \ value;\n      node *left = nullptr, *right = nullptr;\n      node(const value_type\
    \ &value): value(value){}\n    };\n\n    Monoid M_;\n    int depth_, size_;\n\
    \    node *root_ = nullptr;\n\n    persistent_segment_tree(int depth, node *root):\
    \ depth_(depth), root_(root){}\n\n    node* assign(node *t, const std::vector<value_type>\
    \ &init_list, int d, int &pos){\n      if(d == depth_){\n        t = new node(pos\
    \ < (int)init_list.size() ? init_list[pos] : M_());\n        ++pos;\n      }else{\n\
    \        t = new node(M_());\n        t->left = assign(t->left, init_list, d +\
    \ 1, pos);\n        t->right = assign(t->right, init_list, d + 1, pos);\n    \
    \    t->value = M_(t->left->value, t->right->value);\n      }\n      return t;\n\
    \    }\n\n    void init(const std::vector<value_type> &init_list){\n      size_\
    \ = init_list.size();\n      depth_ = size_ == 1 ? 1 : 32 - __builtin_clz(size_\
    \ - 1) + 1;\n      int pos = 0;\n      root_ = assign(root_, init_list, 1, pos);\n\
    \    }\n\n  public:\n    persistent_segment_tree(){}\n    persistent_segment_tree(const\
    \ std::vector<value_type> &init_list){\n      init(init_list);\n    }\n    persistent_segment_tree(int\
    \ size){\n      init(std::vector(size, M_()));\n    }\n    persistent_segment_tree(int\
    \ size, const value_type &value){\n      init(std::vector(size, value));\n   \
    \ }\n\n  protected:\n    node* set(node *t, int l, int r, int pos, const value_type\
    \ &val) const {\n      if(r <= pos or pos + 1 <= l){\n        return t;\n    \
    \  }else if(pos <= l and r <= pos + 1){\n        return new node(val);\n     \
    \ }else{\n        const int m = (l + r) >> 1;\n        auto lp = set(t->left,\
    \ l, m, pos, val);\n        auto rp = set(t->right, m, r, pos, val);\n\n     \
    \   node *s = new node(M_(lp->value, rp->value));\n\n        s->left = lp;\n \
    \       s->right = rp;\n\n        return s;\n      }\n    }\n\n  public:\n   \
    \ persistent_segment_tree set(int i, const value_type &val) const {\n      assert(0\
    \ <= i and i < size_);\n      node *t = set(root_, 0, 1 << (depth_ - 1), i, val);\n\
    \      return persistent_segment_tree(depth_, t);\n    }\n\n    persistent_segment_tree\
    \ update(int i, const value_type &val) const {\n      return set(i, M_((*this)[i],\
    \ val));\n    }\n\n  protected:\n    value_type get(node *t, int i, int j, int\
    \ l, int r) const {\n      if(i <= l and r <= j) return t->value;\n      if(r\
    \ <= i or j <= l) return M_();\n      const int m = (l + r) >> 1;\n      return\
    \ M_(get(t->left, i, j, l, m), get(t->right, i, j, m, r));\n    }\n\n  public:\n\
    \    value_type fold(int l, int r) const {\n      assert(0 <= l and l <= r and\
    \ r <= size_);\n      return get(root_, l, r, 0, 1 << (depth_ - 1));\n    }\n\n\
    \    value_type operator[](int i) const {\n      return fold(i, i + 1);\n    }\n\
    \  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\nnamespace haar_lib\
    \ {\n  template <typename Monoid>\n  class persistent_segment_tree {\n  public:\n\
    \    using value_type = typename Monoid::value_type;\n\n  private:\n    struct\
    \ node {\n      value_type value;\n      node *left = nullptr, *right = nullptr;\n\
    \      node(const value_type &value): value(value){}\n    };\n\n    Monoid M_;\n\
    \    int depth_, size_;\n    node *root_ = nullptr;\n\n    persistent_segment_tree(int\
    \ depth, node *root): depth_(depth), root_(root){}\n\n    node* assign(node *t,\
    \ const std::vector<value_type> &init_list, int d, int &pos){\n      if(d == depth_){\n\
    \        t = new node(pos < (int)init_list.size() ? init_list[pos] : M_());\n\
    \        ++pos;\n      }else{\n        t = new node(M_());\n        t->left =\
    \ assign(t->left, init_list, d + 1, pos);\n        t->right = assign(t->right,\
    \ init_list, d + 1, pos);\n        t->value = M_(t->left->value, t->right->value);\n\
    \      }\n      return t;\n    }\n\n    void init(const std::vector<value_type>\
    \ &init_list){\n      size_ = init_list.size();\n      depth_ = size_ == 1 ? 1\
    \ : 32 - __builtin_clz(size_ - 1) + 1;\n      int pos = 0;\n      root_ = assign(root_,\
    \ init_list, 1, pos);\n    }\n\n  public:\n    persistent_segment_tree(){}\n \
    \   persistent_segment_tree(const std::vector<value_type> &init_list){\n     \
    \ init(init_list);\n    }\n    persistent_segment_tree(int size){\n      init(std::vector(size,\
    \ M_()));\n    }\n    persistent_segment_tree(int size, const value_type &value){\n\
    \      init(std::vector(size, value));\n    }\n\n  protected:\n    node* set(node\
    \ *t, int l, int r, int pos, const value_type &val) const {\n      if(r <= pos\
    \ or pos + 1 <= l){\n        return t;\n      }else if(pos <= l and r <= pos +\
    \ 1){\n        return new node(val);\n      }else{\n        const int m = (l +\
    \ r) >> 1;\n        auto lp = set(t->left, l, m, pos, val);\n        auto rp =\
    \ set(t->right, m, r, pos, val);\n\n        node *s = new node(M_(lp->value, rp->value));\n\
    \n        s->left = lp;\n        s->right = rp;\n\n        return s;\n      }\n\
    \    }\n\n  public:\n    persistent_segment_tree set(int i, const value_type &val)\
    \ const {\n      assert(0 <= i and i < size_);\n      node *t = set(root_, 0,\
    \ 1 << (depth_ - 1), i, val);\n      return persistent_segment_tree(depth_, t);\n\
    \    }\n\n    persistent_segment_tree update(int i, const value_type &val) const\
    \ {\n      return set(i, M_((*this)[i], val));\n    }\n\n  protected:\n    value_type\
    \ get(node *t, int i, int j, int l, int r) const {\n      if(i <= l and r <= j)\
    \ return t->value;\n      if(r <= i or j <= l) return M_();\n      const int m\
    \ = (l + r) >> 1;\n      return M_(get(t->left, i, j, l, m), get(t->right, i,\
    \ j, m, r));\n    }\n\n  public:\n    value_type fold(int l, int r) const {\n\
    \      assert(0 <= l and l <= r and r <= size_);\n      return get(root_, l, r,\
    \ 0, 1 << (depth_ - 1));\n    }\n\n    value_type operator[](int i) const {\n\
    \      return fold(i, i + 1);\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
