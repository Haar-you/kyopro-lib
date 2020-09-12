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


# :x: Dynamic lazy segment tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7a59141fbb54053c332fbe894553f051">Mylib/DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:14:08+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/DSL_2_F/main.dynamic.test.cpp.html">test/aoj/DSL_2_F/main.dynamic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>

/**
 * @title Dynamic lazy segment tree
 * @docs dynamic_lazy_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class dynamic_lazy_segment_tree {
    using value_type_get = typename Monoid::value_type_get;
    using value_type_update = typename Monoid::value_type_update;
    const static Monoid M;

    struct node {
      value_type_get value;
      value_type_update lazy;
      node *left = nullptr, *right = nullptr;
      node(){}
      node(const value_type_get &value, const value_type_update &lazy): value(value), lazy(lazy){}
    };

    int64_t depth, size, hsize;
    node *root = nullptr;

    void propagate(node *t, int64_t l, int64_t r){
      if(t->lazy == M.id_update()) return;
      if(r - l > 1){
        if(not t->left) t->left = new node(M.id_get(), M.id_update());
        t->left->lazy = M.op_update(t->lazy, t->left->lazy);
        if(not t->right) t->right = new node(M.id_get(), M.id_update());
        t->right->lazy = M.op_update(t->lazy, t->right->lazy);
      }
      int64_t len = r - l;
      t->value = M.op(t->value, t->lazy, len);
      t->lazy = M.id_update();
    }

    node* update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, value_type_update value){
      if(not t) t = new node(M.id_get(), M.id_update());

      propagate(t, l, r);
      if(r - l == 1){
        if(x <= l and r <= y) t->lazy = M.op_update(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      if(r < x or y < l) return t;
      if(x <= l and r <= y){
        t->lazy = M.op_update(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      t->left = update(t->left, l, (l + r) / 2, x, y, value);
      t->right = update(t->right, (l + r) / 2, r, x, y, value);
      t->value = M.op_get(t->left->value, t->right->value);

      return t;
    }

    value_type_get get(node *t, int64_t l, int64_t r, int64_t x, int64_t y){
      if(not t) return M.id_get();

      propagate(t, l, r);
      if(r <= x or y <= l) return M.id_get();
      if(x <= l and r <= y) return t->value;

      return M.op_get(
        get(t->left, l, (l + r) / 2, x, y),
        get(t->right, (l + r) / 2, r, x, y)
      );
    }

  public:
    dynamic_lazy_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M.id_get(), M.id_update());
    }

    void update(int64_t l, int64_t r, value_type_update value){
      update(root, 0, hsize, l, r, value);
    }

    value_type_get get(int64_t l, int64_t r){
      return get(root, 0, hsize, l, r);
    }

    value_type_get operator[](int64_t i){
      return get(i, i + 1);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp"
#include <cstdint>

/**
 * @title Dynamic lazy segment tree
 * @docs dynamic_lazy_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class dynamic_lazy_segment_tree {
    using value_type_get = typename Monoid::value_type_get;
    using value_type_update = typename Monoid::value_type_update;
    const static Monoid M;

    struct node {
      value_type_get value;
      value_type_update lazy;
      node *left = nullptr, *right = nullptr;
      node(){}
      node(const value_type_get &value, const value_type_update &lazy): value(value), lazy(lazy){}
    };

    int64_t depth, size, hsize;
    node *root = nullptr;

    void propagate(node *t, int64_t l, int64_t r){
      if(t->lazy == M.id_update()) return;
      if(r - l > 1){
        if(not t->left) t->left = new node(M.id_get(), M.id_update());
        t->left->lazy = M.op_update(t->lazy, t->left->lazy);
        if(not t->right) t->right = new node(M.id_get(), M.id_update());
        t->right->lazy = M.op_update(t->lazy, t->right->lazy);
      }
      int64_t len = r - l;
      t->value = M.op(t->value, t->lazy, len);
      t->lazy = M.id_update();
    }

    node* update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, value_type_update value){
      if(not t) t = new node(M.id_get(), M.id_update());

      propagate(t, l, r);
      if(r - l == 1){
        if(x <= l and r <= y) t->lazy = M.op_update(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      if(r < x or y < l) return t;
      if(x <= l and r <= y){
        t->lazy = M.op_update(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      t->left = update(t->left, l, (l + r) / 2, x, y, value);
      t->right = update(t->right, (l + r) / 2, r, x, y, value);
      t->value = M.op_get(t->left->value, t->right->value);

      return t;
    }

    value_type_get get(node *t, int64_t l, int64_t r, int64_t x, int64_t y){
      if(not t) return M.id_get();

      propagate(t, l, r);
      if(r <= x or y <= l) return M.id_get();
      if(x <= l and r <= y) return t->value;

      return M.op_get(
        get(t->left, l, (l + r) / 2, x, y),
        get(t->right, (l + r) / 2, r, x, y)
      );
    }

  public:
    dynamic_lazy_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M.id_get(), M.id_update());
    }

    void update(int64_t l, int64_t r, value_type_update value){
      update(root, 0, hsize, l, r, value);
    }

    value_type_get get(int64_t l, int64_t r){
      return get(root, 0, hsize, l, r);
    }

    value_type_get operator[](int64_t i){
      return get(i, i + 1);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

