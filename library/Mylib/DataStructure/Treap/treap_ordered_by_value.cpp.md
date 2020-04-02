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


# :warning: Mylib/DataStructure/Treap/treap_ordered_by_value.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f1faa641fd949a91e292dddd575fe73e">Mylib/DataStructure/Treap</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Treap/treap_ordered_by_value.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 10:19:12+09:00




## Depends on

* :heavy_check_mark: <a href="treap_ordered_by_index.cpp.html">Mylib/DataStructure/Treap/treap_ordered_by_index.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include "Mylib/DataStructure/Treap/treap_ordered_by_index.cpp"

namespace treap{
  template <typename Monoid>
  class OrderedTreap : public Treap<Monoid>{
    using value_type = typename Monoid::value_type;
    using node = TreapNode<Monoid>;
    using super = Treap<Monoid>;
    
  protected:
  
  public:
    OrderedTreap(): super(){}
    
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
#line 2 "Mylib/DataStructure/Treap/treap_ordered_by_value.cpp"
#include <algorithm>
#line 2 "Mylib/DataStructure/Treap/treap_ordered_by_index.cpp"
#include <random>
#include <utility>
#include <tuple>

namespace treap{
  template <typename Monoid>
  struct TreapNode{
    using value_type = typename Monoid::value_type;
    using node = TreapNode<Monoid>;
    
    static std::mt19937 rand;
  
    value_type value, result;
    node *left = nullptr, *right = nullptr;
    int priority, size = 1;
    bool rev = false;

    TreapNode(): priority(rand()){}
    TreapNode(const value_type &value): value(value), result(value), priority(rand()){}

    inline static int count(node *t) {return !t ? 0 : t->size;}
    inline static value_type sum(node *t) {return !t ? Monoid::id() : t->result;}
    
    inline static node* update_node_status(node *t){
      t->size = count(t->right) + count(t->left) + 1;
      t->result = Monoid::op(Monoid::op(sum(t->right), sum(t->left)), t->value);
      return t;
    }

    inline static void pushdown(node *t){
      if(!t) return;
      if(t->rev){
        std::swap(t->left, t->right);
        if(t->left) t->left->rev ^= true;
        if(t->right) t->right->rev ^= true;
        t->rev = false;
      }
      update_node_status(t);
    }
  
    inline static node* insert(node *t, int k, const value_type &val){
      auto s = split(t, k);
      return merge(s.first, merge(new node(val), s.second));
    }
    
    inline static node* erase(node *t, int k){
      node *l, *r, *m;
      std::tie(l,r) = split(t, k);
      std::tie(m,r) = split(r, 1);
      return merge(l,r);
    }

    inline static std::pair<node*,node*> split(node *t, int k){
      if(!t) return std::make_pair(nullptr, nullptr);
      pushdown(t);
      const int c = count(t->left);
      if(k <= c){
        auto s = split(t->left, k);
        t->left = s.second;
        return std::make_pair(s.first, update_node_status(t));
      }else{
        auto s = split(t->right, k-(c+1));
        t->right = s.first;
        return std::make_pair(update_node_status(t), s.second);
      }
    }

    inline static node* merge(node *l, node *r){
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

    inline static node* reverse(node *t, int l, int r){
      node *a, *b, *c;
      std::tie(a,c) = split(t, l);
      std::tie(b,c) = split(c, r-l);
      b->rev ^= true;
      return t = merge(merge(a,b),c);
    }

    inline static void update_node(node *t, int k, const value_type &value){
      const int c = count(t->left);
      if(k == c) t->value = value;
      else if(k > c) update_node(t->right, k-(c+1), value);
      else update_node(t->left, k, value);
      update_node_status(t);
    }

    inline static node* get_node(node *t, int k){
      if(!t) return t;
      pushdown(t);
      int c = count(t->left);
      if(k == c) return t;
      if(k > c) return get_node(t->right, k-(c+1));
      else return get_node(t->left, k);
    }

    template <typename Func>
    inline static void traverse(node *t, const Func &f){
      if(t){
        pushdown(t);
        traverse(t->left, f);
        f(*t);
        traverse(t->right, f);
      }
    }
  };

  template <typename Monoid> std::mt19937 TreapNode<Monoid>::rand;

  
  template <typename Monoid>
  class Treap{
  protected:
    using value_type = typename Monoid::value_type;
    using node = TreapNode<Monoid>;

    node *root = nullptr;

  public:
    Treap(){}
    Treap(int n){for(int i = 0; i < n; ++i) push_back(Monoid::id());}
    Treap(node *t): root(t){}
  
    inline int size() const {return node::count(root);}
    inline bool empty() const {return !root;}

    inline void insert(int k, const value_type &val = Monoid::id()){
      root = node::insert(root, k, val);
    }

    inline void erase(int k){root = node::erase(root, k);}
  
    inline void merge_left(Treap &left){
      root = node::merge(left.root, root); left.root = nullptr;
    }
    inline void merge_right(Treap &right){
      root = node::merge(root, right.root); right.root = nullptr;
    }

    inline std::pair<Treap, Treap> split(int k){
      node *l, *r; std::tie(l, r) = node::split(root, k);
      return std::make_pair(Treap(l), Treap(r));
    }

    inline void reverse(int l, int r){node::reverse(root, l, r);}

    inline void update(int k, const value_type &value){node::update_node(root, k, value);}

    inline value_type get(int k){return (node::get_node(root, k))->value;}
    inline value_type operator[](int k){return get(k);}

    inline value_type fold(){return node::sum(root);}
    inline value_type fold(int l, int r){ // [l,r)
      node *left, *mid, *right;
      std::tie(mid, right) = node::split(root, r);
      std::tie(left, mid) = node::split(mid, l);

      auto ret = node::sum(mid);

      mid = node::merge(left, mid);
      root = node::merge(mid, right);

      return ret;
    } 

    template <typename Func>
    inline void traverse(const Func &f){
      node::traverse(root, f);
    }

    inline void push_front(const value_type &val){insert(0, val);}
    inline void push_back(const value_type &val){insert(size(), val);}

    inline void pop_front(){erase(0);}
    inline void pop_back(){erase(size()-1);}

    inline const value_type& front(){return get(0);}
    inline const value_type& back(){return get(size()-1);}
  };
}
#line 4 "Mylib/DataStructure/Treap/treap_ordered_by_value.cpp"

namespace treap{
  template <typename Monoid>
  class OrderedTreap : public Treap<Monoid>{
    using value_type = typename Monoid::value_type;
    using node = TreapNode<Monoid>;
    using super = Treap<Monoid>;
    
  protected:
  
  public:
    OrderedTreap(): super(){}
    
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

