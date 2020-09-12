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


# :x: Dynamic dual segment tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7a59141fbb54053c332fbe894553f051">Mylib/DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:14:08+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/DSL_2_E/main.dynamic.test.cpp.html">test/aoj/DSL_2_E/main.dynamic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <unordered_map>

/**
 * @title Dynamic dual segment tree
 * @docs dynamic_dual_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class dynamic_dual_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type val;
      node *left = nullptr, *right = nullptr;
      node(const value_type &val): val(val) {}
    };

    const int64_t depth, size, hsize;
    node *root = nullptr;
    std::unordered_map<int64_t, node*> umap;

    void propagate(node *t, int64_t l, int64_t r){
      if(r - l > 1){
        if(not t->left) t->left = new node(M());
        t->left->val = M(t->val, t->left->val);

        if(not t->right) t->right = new node(M());
        t->right->val = M(t->val, t->right->val);

        t->val = M();
      }
    }

    void update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val){
      if(r - l == 1){
        if(x <= l && r <= y) t->val = M(t->val, val);
        umap[l] = t;
        return;
      }
      if(r < x || y < l) return;
      else if(x <= l && r <= y) t->val = M(t->val, val);
      else{
        const int64_t m = (l + r) / 2;
        propagate(t, l, r);
        update(t->left, l, m, x, y, val);
        update(t->right, m, r, x, y, val);
      }
    }

    void get(node* t, int64_t l, int64_t r, int64_t x){
      if(r - l == 1){
        umap[l] = t;
        return;
      }
      propagate(t, l, r);
      int m = (l + r) / 2;
      if(x < m) get(t->left, l, m, x);
      else get(t->right, m, r, x);
    }

  public:
    dynamic_dual_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M());
    }

    void update(int64_t s, int64_t t, value_type &x){
      update(root, 0, hsize, s, t, x);
    }

    value_type operator[](int64_t x){
      get(root, 0, hsize, x);
      return umap[x]->val;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp"
#include <unordered_map>

/**
 * @title Dynamic dual segment tree
 * @docs dynamic_dual_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class dynamic_dual_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type val;
      node *left = nullptr, *right = nullptr;
      node(const value_type &val): val(val) {}
    };

    const int64_t depth, size, hsize;
    node *root = nullptr;
    std::unordered_map<int64_t, node*> umap;

    void propagate(node *t, int64_t l, int64_t r){
      if(r - l > 1){
        if(not t->left) t->left = new node(M());
        t->left->val = M(t->val, t->left->val);

        if(not t->right) t->right = new node(M());
        t->right->val = M(t->val, t->right->val);

        t->val = M();
      }
    }

    void update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val){
      if(r - l == 1){
        if(x <= l && r <= y) t->val = M(t->val, val);
        umap[l] = t;
        return;
      }
      if(r < x || y < l) return;
      else if(x <= l && r <= y) t->val = M(t->val, val);
      else{
        const int64_t m = (l + r) / 2;
        propagate(t, l, r);
        update(t->left, l, m, x, y, val);
        update(t->right, m, r, x, y, val);
      }
    }

    void get(node* t, int64_t l, int64_t r, int64_t x){
      if(r - l == 1){
        umap[l] = t;
        return;
      }
      propagate(t, l, r);
      int m = (l + r) / 2;
      if(x < m) get(t->left, l, m, x);
      else get(t->right, m, r, x);
    }

  public:
    dynamic_dual_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M());
    }

    void update(int64_t s, int64_t t, value_type &x){
      update(root, 0, hsize, s, t, x);
    }

    value_type operator[](int64_t x){
      get(root, 0, hsize, x);
      return umap[x]->val;
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

