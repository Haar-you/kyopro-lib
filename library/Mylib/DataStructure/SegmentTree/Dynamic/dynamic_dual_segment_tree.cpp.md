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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: 動的双対セグメント木

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#8db11aac103ae486542368bc2b65dfc8">Mylib/DataStructure/SegmentTree/Dynamic</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/SegmentTree/Dynamic/dynamic_dual_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <unordered_map>

/**
 * @title 動的双対セグメント木
 */
template <typename Monoid>
class DynamicDualSegmentTree{
  using value_type = typename Monoid::value_type;

  struct Node{
    value_type val;
    Node *left = nullptr, *right = nullptr;
    Node(const value_type &val): val(val) {}
  };
  
  const int64_t depth, size;
  Node *root = nullptr;
  std::unordered_map<int64_t, Node*> umap;

  Node* propagate(Node *node, int64_t l, int64_t r){
    if(r-l > 1){
      if(not node->left) node->left = new Node(Monoid::id());
      node->left->val = Monoid::op(node->val, node->left->val);

      if(not node->right) node->right = new Node(Monoid::id());
      node->right->val = Monoid::op(node->val, node->right->val);

      node->val = Monoid::id();
    }
    return node;
  }

  void update(Node *node, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val){
    if(r-l == 1){
      if(x <= l && r <= y) node->val = Monoid::op(node->val, val);
      umap[l] = node;
      return;
    }
    if(r < x || y < l) return;
    else if(x <= l && r <= y) node->val = Monoid::op(node->val, val);
    else{
      int64_t m = (l+r)/2;
      propagate(node, l, r);
      update(node->left, l, m, x, y, val);
      update(node->right, m, r, x, y, val);
    }
  }

  void get(Node* node, int64_t l, int64_t r, int64_t x){
    if(r-l == 1){
      umap[l] = node;
      return;
    }
    propagate(node, l, r);
    int m = (l + r) / 2;
    if(x < m) get(node->left, l, m, x);
    else get(node->right, m, r, x);
  }

public:
  DynamicDualSegmentTree(int64_t n):
    depth(n > 1 ? 64-__builtin_clzll(n-1) + 1 : 1),
    size(1LL << depth)
  {
    root = new Node(Monoid::id());
  }

  void update(int64_t s, int64_t t, value_type &x){
    update(root, 0, size, s, t, x);
  }

  value_type get(int64_t x){
    get(root, 0, size, x);
    return umap[x]->val;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/SegmentTree/Dynamic/dynamic_dual_segment_tree.cpp"
#include <unordered_map>

/**
 * @title 動的双対セグメント木
 */
template <typename Monoid>
class DynamicDualSegmentTree{
  using value_type = typename Monoid::value_type;

  struct Node{
    value_type val;
    Node *left = nullptr, *right = nullptr;
    Node(const value_type &val): val(val) {}
  };
  
  const int64_t depth, size;
  Node *root = nullptr;
  std::unordered_map<int64_t, Node*> umap;

  Node* propagate(Node *node, int64_t l, int64_t r){
    if(r-l > 1){
      if(not node->left) node->left = new Node(Monoid::id());
      node->left->val = Monoid::op(node->val, node->left->val);

      if(not node->right) node->right = new Node(Monoid::id());
      node->right->val = Monoid::op(node->val, node->right->val);

      node->val = Monoid::id();
    }
    return node;
  }

  void update(Node *node, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val){
    if(r-l == 1){
      if(x <= l && r <= y) node->val = Monoid::op(node->val, val);
      umap[l] = node;
      return;
    }
    if(r < x || y < l) return;
    else if(x <= l && r <= y) node->val = Monoid::op(node->val, val);
    else{
      int64_t m = (l+r)/2;
      propagate(node, l, r);
      update(node->left, l, m, x, y, val);
      update(node->right, m, r, x, y, val);
    }
  }

  void get(Node* node, int64_t l, int64_t r, int64_t x){
    if(r-l == 1){
      umap[l] = node;
      return;
    }
    propagate(node, l, r);
    int m = (l + r) / 2;
    if(x < m) get(node->left, l, m, x);
    else get(node->right, m, r, x);
  }

public:
  DynamicDualSegmentTree(int64_t n):
    depth(n > 1 ? 64-__builtin_clzll(n-1) + 1 : 1),
    size(1LL << depth)
  {
    root = new Node(Monoid::id());
  }

  void update(int64_t s, int64_t t, value_type &x){
    update(root, 0, size, s, t, x);
  }

  value_type get(int64_t x){
    get(root, 0, size, x);
    return umap[x]->val;
  }
};

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

