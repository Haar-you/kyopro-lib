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


# :x: Dynamic segment tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7a59141fbb54053c332fbe894553f051">Mylib/DataStructure/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:14:08+09:00




## Verified with

* :x: <a href="../../../../verify/test/yukicoder/789/main.test.cpp.html">test/yukicoder/789/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>

/**
 * @title Dynamic segment tree
 * @docs dynamic_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class dynamic_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type val;
      node *left = nullptr, *right = nullptr;
      node(const value_type &val): val(val) {}
    };

    int64_t depth, size, hsize;
    node *root = nullptr;

    value_type eval(node *t) const {
      return t ? t->val : M();
    }

    node* update(node *t, int64_t l, int64_t r, int64_t pos, const value_type &val){
      if(r - l == 1){
        if(t) t->val = val;
        else t = new node(val);
      }else{
        const int64_t m = (l + r) / 2;
        if(not t) t = new node(val);
        if(pos < m) t->left = update(t->left, l, m, pos, val);
        else t->right = update(t->right, m, r, pos, val);
        t->val = M(eval(t->left), eval(t->right));
      }
      return t;
    }

    value_type get(node* t, int64_t l, int64_t r, int64_t x, int64_t y) const {
      if(not t) return M();
      if(x <= l && r <= y) return t ? t->val : M();
      if(r < x || y < l) return M();
      int64_t m = (l + r) >> 1;
      return M(get(t->left, l, m, x, y), get(t->right, m, r, x, y));
    }

  public:
    dynamic_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M());
    }

    void update(int64_t i, const value_type &x){
      update(root, 0, hsize, i, x);
    }

    value_type get(int64_t l, int64_t r) const {
      return get(root, 0, hsize, l, r);
    }

    value_type operator[](int64_t i) const {
      return get(i, i + 1);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp"
#include <cstdint>

/**
 * @title Dynamic segment tree
 * @docs dynamic_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class dynamic_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type val;
      node *left = nullptr, *right = nullptr;
      node(const value_type &val): val(val) {}
    };

    int64_t depth, size, hsize;
    node *root = nullptr;

    value_type eval(node *t) const {
      return t ? t->val : M();
    }

    node* update(node *t, int64_t l, int64_t r, int64_t pos, const value_type &val){
      if(r - l == 1){
        if(t) t->val = val;
        else t = new node(val);
      }else{
        const int64_t m = (l + r) / 2;
        if(not t) t = new node(val);
        if(pos < m) t->left = update(t->left, l, m, pos, val);
        else t->right = update(t->right, m, r, pos, val);
        t->val = M(eval(t->left), eval(t->right));
      }
      return t;
    }

    value_type get(node* t, int64_t l, int64_t r, int64_t x, int64_t y) const {
      if(not t) return M();
      if(x <= l && r <= y) return t ? t->val : M();
      if(r < x || y < l) return M();
      int64_t m = (l + r) >> 1;
      return M(get(t->left, l, m, x, y), get(t->right, m, r, x, y));
    }

  public:
    dynamic_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M());
    }

    void update(int64_t i, const value_type &x){
      update(root, 0, hsize, i, x);
    }

    value_type get(int64_t l, int64_t r) const {
      return get(root, 0, hsize, l, r);
    }

    value_type operator[](int64_t i) const {
      return get(i, i + 1);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

