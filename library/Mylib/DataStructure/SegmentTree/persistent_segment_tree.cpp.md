---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :x: Persistent segment tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7a59141fbb54053c332fbe894553f051">Mylib/DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




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


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Persistent segment tree
 * @docs persistent_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class persistent_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type value;
      node *left = nullptr, *right = nullptr;
      node(const value_type &value): value(value){}
    };

    int depth;
    node *root = nullptr;

    persistent_segment_tree(int depth, node *root): depth(depth), root(root){}

    node* init(node *t, const std::vector<value_type> &init_list, int d, int &pos){
      if(d == depth){
        t = new node(pos < (int)init_list.size() ? init_list[pos] : M());
        ++pos;
      }else{
        t = new node(M());
        t->left = init(t->left, init_list, d + 1, pos);
        t->right = init(t->right, init_list, d + 1, pos);
        t->value = M(t->left->value, t->right->value);
      }
      return t;
    }

  public:
    persistent_segment_tree(const std::vector<value_type> &init_list){
      const int size = init_list.size();
      depth = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;
      int pos = 0;
      root = init(root, init_list, 1, pos);
    }

    persistent_segment_tree(int size, const value_type &value = M()){
      depth = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;
      int pos = 0;
      root = init(root, std::vector<value_type>(size, value), 1, pos);
    }

  protected:
    node* update(node *t, int l, int r, int pos, const value_type &val) const {
      if(r <= pos or pos + 1 <= l){
        return t;
      }else if(pos <= l and r <= pos + 1){
        return new node(val);
      }else{
        const int m = (l + r) >> 1;
        auto lp = update(t->left, l, m, pos, val);
        auto rp = update(t->right, m, r, pos, val);

        node *s = new node(M(lp->value, rp->value));

        s->left = lp;
        s->right = rp;

        return s;
      }
    }

  public:
    persistent_segment_tree update(int i, const value_type &val) const {
      node *t = update(root, 0, 1 << (depth - 1), i, val);
      return persistent_segment_tree(depth, t);
    }

  protected:
    value_type get(node *t, int i, int j, int l, int r) const {
      if(i <= l and r <= j) return t->value;
      if(r <= i or j <= l) return M();
      const int m = (l + r) >> 1;
      return M(get(t->left, i, j, l, m), get(t->right, i, j, m, r));
    }

  public:
    value_type get(int i, int j) const {
      return get(root, i, j, 0, 1 << (depth - 1));
    }

    value_type operator[](int i) const {
      return get(i, i + 1);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/persistent_segment_tree.cpp"
#include <vector>

/**
 * @title Persistent segment tree
 * @docs persistent_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class persistent_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type value;
      node *left = nullptr, *right = nullptr;
      node(const value_type &value): value(value){}
    };

    int depth;
    node *root = nullptr;

    persistent_segment_tree(int depth, node *root): depth(depth), root(root){}

    node* init(node *t, const std::vector<value_type> &init_list, int d, int &pos){
      if(d == depth){
        t = new node(pos < (int)init_list.size() ? init_list[pos] : M());
        ++pos;
      }else{
        t = new node(M());
        t->left = init(t->left, init_list, d + 1, pos);
        t->right = init(t->right, init_list, d + 1, pos);
        t->value = M(t->left->value, t->right->value);
      }
      return t;
    }

  public:
    persistent_segment_tree(const std::vector<value_type> &init_list){
      const int size = init_list.size();
      depth = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;
      int pos = 0;
      root = init(root, init_list, 1, pos);
    }

    persistent_segment_tree(int size, const value_type &value = M()){
      depth = size == 1 ? 1 : 32 - __builtin_clz(size - 1) + 1;
      int pos = 0;
      root = init(root, std::vector<value_type>(size, value), 1, pos);
    }

  protected:
    node* update(node *t, int l, int r, int pos, const value_type &val) const {
      if(r <= pos or pos + 1 <= l){
        return t;
      }else if(pos <= l and r <= pos + 1){
        return new node(val);
      }else{
        const int m = (l + r) >> 1;
        auto lp = update(t->left, l, m, pos, val);
        auto rp = update(t->right, m, r, pos, val);

        node *s = new node(M(lp->value, rp->value));

        s->left = lp;
        s->right = rp;

        return s;
      }
    }

  public:
    persistent_segment_tree update(int i, const value_type &val) const {
      node *t = update(root, 0, 1 << (depth - 1), i, val);
      return persistent_segment_tree(depth, t);
    }

  protected:
    value_type get(node *t, int i, int j, int l, int r) const {
      if(i <= l and r <= j) return t->value;
      if(r <= i or j <= l) return M();
      const int m = (l + r) >> 1;
      return M(get(t->left, i, j, l, m), get(t->right, i, j, m, r));
    }

  public:
    value_type get(int i, int j) const {
      return get(root, i, j, 0, 1 << (depth - 1));
    }

    value_type operator[](int i) const {
      return get(i, i + 1);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
