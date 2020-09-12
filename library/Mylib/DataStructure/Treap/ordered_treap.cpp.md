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


# :warning: Treap (Ordered set)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f1faa641fd949a91e292dddd575fe73e">Mylib/DataStructure/Treap</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Treap/ordered_treap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :heavy_check_mark: <a href="treap.cpp.html">Treap</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include "Mylib/DataStructure/Treap/treap.cpp"

/**
 * @title Treap (Ordered set)
 * @docs ordered_treap.md
 */
namespace haar_lib {
  template <typename Monoid>
  class ordered_treap : public treap<Monoid> {
    using value_type = typename Monoid::value_type;
    using node = treap_node<Monoid>;
    using super = treap<Monoid>;

  public:
    ordered_treap(): super(){}

  protected:
    int lower_bound(node *t, const value_type &val){
      if(!t) return 0;
      int c = super::count(t->left);
      if(t->value >= val) return std::min(c, lower_bound(t->left, val));
      else return c + 1 + lower_bound(t->right, val);
    }

  public:
    int lower_bound(const value_type &val){
      return lower_bound(super::root, val);
    }

  protected:
    int upper_bound(node *t, const value_type &val){
      if(!t) return 0;
      int c = super::count(t->left);
      if(t->val > val) return std::min(c, upper_bound(t->left, val));
      else return c + 1 + upper_bound(t->right, val);
    }

  public:
    int upper_bound(const value_type &val){
      return upper_bound(super::root, val);
    }

  public:
    void insert_by_order(const value_type &val){
      int k = lower_bound(val);
      super::insert(k, val);
    }

  public:
    int find_by_order(const value_type &val){
      int k = lower_bound(super::root, val);
      if(k >= super::size()) return -1;
      auto t = super::get(k);
      return t == val ? k : -1;
    }

  public:
    void erase_by_order(const value_type &val){
      int k = find_by_order(val);
      if(k == -1) return;
      super::erase(k);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Treap/ordered_treap.cpp"
#include <algorithm>
#line 2 "Mylib/DataStructure/Treap/treap.cpp"
#include <random>
#include <utility>
#include <tuple>

/**
 * @title Treap
 * @docs treap.md
 */
namespace haar_lib {
  template <typename Monoid>
  struct treap_node {
    using node = treap_node<Monoid>;
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    static std::mt19937 rand;

    value_type value, result;
    node *left = nullptr, *right = nullptr;
    int priority, size = 1;
    bool rev = false;

    treap_node(): priority(rand()){}
    treap_node(const value_type &value): value(value), result(value), priority(rand()){}

    static int count(node *t) {return !t ? 0 : t->size;}
    static value_type sum(node *t) {return !t ? M() : t->result;}

    static node* update_node_status(node *t){
      t->size = count(t->right) + count(t->left) + 1;
      t->result = M(M(sum(t->right), sum(t->left)), t->value);
      return t;
    }

    static void pushdown(node *t){
      if(!t) return;
      if(t->rev){
        std::swap(t->left, t->right);
        if(t->left) t->left->rev ^= true;
        if(t->right) t->right->rev ^= true;
        t->rev = false;
      }
      update_node_status(t);
    }

    static node* insert(node *t, int k, const value_type &val){
      auto s = split(t, k);
      return merge(s.first, merge(new node(val), s.second));
    }

    static node* erase(node *t, int k){
      node *l, *r, *m;
      std::tie(l, r) = split(t, k);
      std::tie(m, r) = split(r, 1);
      return merge(l, r);
    }

    static std::pair<node*, node*> split(node *t, int k){
      if(!t) return std::make_pair(nullptr, nullptr);
      pushdown(t);
      const int c = count(t->left);
      if(k <= c){
        auto s = split(t->left, k);
        t->left = s.second;
        return std::make_pair(s.first, update_node_status(t));
      }else{
        auto s = split(t->right, k - (c + 1));
        t->right = s.first;
        return std::make_pair(update_node_status(t), s.second);
      }
    }

    static node* merge(node *l, node *r){
      pushdown(l);
      pushdown(r);
      if(!l || !r) return !l ? r : l;
      if(l->priority > r->priority){
        l->right = merge(l->right, r);
        return update_node_status(l);
      }else{
        r->left = merge(l, r->left);
        return update_node_status(r);
      }
    }

    static node* reverse(node *t, int l, int r){
      node *a, *b, *c;
      std::tie(a, c) = split(t, l);
      std::tie(b, c) = split(c, r - l);
      b->rev ^= true;
      return t = merge(merge(a, b), c);
    }

    static void update_node(node *t, int k, const value_type &value){
      const int c = count(t->left);
      if(k == c) t->value = value;
      else if(k > c) update_node(t->right, k - (c + 1), value);
      else update_node(t->left, k, value);
      update_node_status(t);
    }

    static node* get_node(node *t, int k){
      if(!t) return t;
      pushdown(t);
      int c = count(t->left);
      if(k == c) return t;
      if(k > c) return get_node(t->right, k - (c + 1));
      else return get_node(t->left, k);
    }

    template <typename Func>
    static void traverse(node *t, const Func &f){
      if(t){
        pushdown(t);
        traverse(t->left, f);
        f(*t);
        traverse(t->right, f);
      }
    }
  };

  template <typename Monoid> std::mt19937 treap_node<Monoid>::rand;

  template <typename Monoid>
  class treap {
  protected:
    using node = treap_node<Monoid>;
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    node *root = nullptr;

  public:
    treap(){}
    treap(int n){for(int i = 0; i < n; ++i) push_back(M());}
    treap(node *t): root(t){}

    int size() const {return node::count(root);}
    bool empty() const {return !root;}

    void insert(int k, const value_type &val = M()){
      root = node::insert(root, k, val);
    }

    void erase(int k){root = node::erase(root, k);}

    void merge_left(treap &left){
      root = node::merge(left.root, root); left.root = nullptr;
    }

    void merge_right(treap &right){
      root = node::merge(root, right.root); right.root = nullptr;
    }

    std::pair<treap, treap> split(int k){
      node *l, *r; std::tie(l, r) = node::split(root, k);
      return std::make_pair(treap(l), treap(r));
    }

    void reverse(int l, int r){node::reverse(root, l, r);}

    void update(int k, const value_type &value){node::update_node(root, k, value);}

    value_type get(int k){return (node::get_node(root, k))->value;}
    value_type operator[](int k){return get(k);}

    value_type fold(){return node::sum(root);}
    value_type fold(int l, int r){
      node *left, *mid, *right;
      std::tie(mid, right) = node::split(root, r);
      std::tie(left, mid) = node::split(mid, l);

      auto ret = node::sum(mid);

      mid = node::merge(left, mid);
      root = node::merge(mid, right);

      return ret;
    }

    template <typename Func>
    void traverse(const Func &f){
      node::traverse(root, f);
    }

    void push_front(const value_type &val){insert(0, val);}
    void push_back(const value_type &val){insert(size(), val);}

    void pop_front(){erase(0);}
    void pop_back(){erase(size() - 1);}

    const value_type& front(){return get(0);}
    const value_type& back(){return get(size() - 1);}
  };
}
#line 4 "Mylib/DataStructure/Treap/ordered_treap.cpp"

/**
 * @title Treap (Ordered set)
 * @docs ordered_treap.md
 */
namespace haar_lib {
  template <typename Monoid>
  class ordered_treap : public treap<Monoid> {
    using value_type = typename Monoid::value_type;
    using node = treap_node<Monoid>;
    using super = treap<Monoid>;

  public:
    ordered_treap(): super(){}

  protected:
    int lower_bound(node *t, const value_type &val){
      if(!t) return 0;
      int c = super::count(t->left);
      if(t->value >= val) return std::min(c, lower_bound(t->left, val));
      else return c + 1 + lower_bound(t->right, val);
    }

  public:
    int lower_bound(const value_type &val){
      return lower_bound(super::root, val);
    }

  protected:
    int upper_bound(node *t, const value_type &val){
      if(!t) return 0;
      int c = super::count(t->left);
      if(t->val > val) return std::min(c, upper_bound(t->left, val));
      else return c + 1 + upper_bound(t->right, val);
    }

  public:
    int upper_bound(const value_type &val){
      return upper_bound(super::root, val);
    }

  public:
    void insert_by_order(const value_type &val){
      int k = lower_bound(val);
      super::insert(k, val);
    }

  public:
    int find_by_order(const value_type &val){
      int k = lower_bound(super::root, val);
      if(k >= super::size()) return -1;
      auto t = super::get(k);
      return t == val ? k : -1;
    }

  public:
    void erase_by_order(const value_type &val){
      int k = find_by_order(val);
      if(k == -1) return;
      super::erase(k);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

