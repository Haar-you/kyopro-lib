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


# :heavy_check_mark: Link/cut tree

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a178be27fdfe56586a4fa516e8dee442">Mylib/DataStructure/LinkCutTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp.html">test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Link/cut tree
 * @docs link_cut_tree.md
 */
template <typename Monoid>
struct LinkCutNode{
  using value_type = typename Monoid::value_type;
  using node = LinkCutNode;

  int subsize;
  node *left, *right, *parent;
  bool rev;
  value_type value, result;

  LinkCutNode():
    subsize(1),
    left(nullptr),
    right(nullptr),
    parent(nullptr),
    rev(false),
    value(Monoid::id()),
    result(Monoid::id())
  {}

  bool is_root() const {
    return !parent or (parent->left != this and parent->right != this); 
  }

  void update_node_status(){
    subsize = 1;
    result = value;

    if(left){
      left->push_down();
      subsize += left->subsize;
      result = Monoid::op(result, left->result);
    }

    if(right){
      right->push_down();
      subsize += right->subsize;
      result = Monoid::op(result, right->result);
    }
  }

  void push_down(){
    if(rev){
      std::swap(left, right);
      if(left) left->rev ^= true;
      if(right) right->rev ^= true;
      rev = false;
    }
  }

  
  void rot(int dir_right){
    node *p = parent, *g = p->parent;

    if(dir_right){
      if((p->left = right)) right->parent = p;
      right = p;
      p->parent = this;
    }else{
      if((p->right = left)) left->parent = p;
      left = p;
      p->parent = this;
    }

    p->update_node_status();
    update_node_status();
    parent = g;

    if(!g) return;

    if(g->left == p) g->left = this;
    if(g->right == p) g->right = this;
    g->update_node_status();
  }
  
  void splay(){
    while(not is_root()){
      node *p = parent, *gp = p->parent;

      if(p->is_root()){
        p->push_down();
        push_down();
        rot(this == p->left);
      }else{
        gp->push_down();
        p->push_down();
        push_down();
        bool flag = this == p->left;
        if((this == p->left) == (p == gp->left)){
          p->rot(flag);
          rot(flag);
        }else{
          rot(flag);
          rot(!flag);
        }
      }
    }
    push_down();
  }

  static void expose(node *u){
    node* rp = nullptr;

    for(node* p = u; p; p = p->parent){
      p->splay();
      p->right = rp;
      p->update_node_status();
      rp = p;
    }
    
    u->splay();
  }

  static void link(node *u, node *v){
    evert(u);
    u->parent = v;
  }
  
  static void cut(node *u){
    expose(u);
    u->left->parent = nullptr;
    u->left = nullptr;
    u->update_node_status();
  }

  static void cut(node *u, node *v){
    expose(u);
    expose(v);
    if(u->is_root()) u->parent = nullptr;
    else{
      v->left->parent = nullptr;
      v->left = nullptr;
      v->update_node_status();
    }
  }

  static void evert(node *u){
    expose(u);
    u->rev ^= true;
    u->push_down();
  }
};





template <typename Monoid>
class LinkCutTree{
  using value_type = typename Monoid::value_type;
  using node = LinkCutNode<Monoid>;

  int N;
  std::vector<node*> nodes;

public:
  LinkCutTree(int N): N(N), nodes(N){
    for(int i = 0; i < N; ++i){
      nodes[i] = new node();
    }
  }

  void expose(int k){
    node::expose(nodes[k]);
  }
  
  void cut(int i, int j){
    node::cut(nodes[i], nodes[j]);
  }

  void link(int i, int j){
    node::link(nodes[i], nodes[j]);
  }

  void evert(int k){
    node::evert(nodes[k]);
  }

  void update(int k, value_type x){
    node::evert(nodes[k]);
    nodes[k]->value = x;
    nodes[k]->push_down();
  }

  value_type at(int k){
    return nodes[k]->value;
  }

  value_type get(int i, int j){
    node::evert(nodes[i]);
    node::expose(nodes[j]);
    return nodes[j]->result;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/LinkCutTree/link_cut_tree.cpp"
#include <vector>

/**
 * @title Link/cut tree
 * @docs link_cut_tree.md
 */
template <typename Monoid>
struct LinkCutNode{
  using value_type = typename Monoid::value_type;
  using node = LinkCutNode;

  int subsize;
  node *left, *right, *parent;
  bool rev;
  value_type value, result;

  LinkCutNode():
    subsize(1),
    left(nullptr),
    right(nullptr),
    parent(nullptr),
    rev(false),
    value(Monoid::id()),
    result(Monoid::id())
  {}

  bool is_root() const {
    return !parent or (parent->left != this and parent->right != this); 
  }

  void update_node_status(){
    subsize = 1;
    result = value;

    if(left){
      left->push_down();
      subsize += left->subsize;
      result = Monoid::op(result, left->result);
    }

    if(right){
      right->push_down();
      subsize += right->subsize;
      result = Monoid::op(result, right->result);
    }
  }

  void push_down(){
    if(rev){
      std::swap(left, right);
      if(left) left->rev ^= true;
      if(right) right->rev ^= true;
      rev = false;
    }
  }

  
  void rot(int dir_right){
    node *p = parent, *g = p->parent;

    if(dir_right){
      if((p->left = right)) right->parent = p;
      right = p;
      p->parent = this;
    }else{
      if((p->right = left)) left->parent = p;
      left = p;
      p->parent = this;
    }

    p->update_node_status();
    update_node_status();
    parent = g;

    if(!g) return;

    if(g->left == p) g->left = this;
    if(g->right == p) g->right = this;
    g->update_node_status();
  }
  
  void splay(){
    while(not is_root()){
      node *p = parent, *gp = p->parent;

      if(p->is_root()){
        p->push_down();
        push_down();
        rot(this == p->left);
      }else{
        gp->push_down();
        p->push_down();
        push_down();
        bool flag = this == p->left;
        if((this == p->left) == (p == gp->left)){
          p->rot(flag);
          rot(flag);
        }else{
          rot(flag);
          rot(!flag);
        }
      }
    }
    push_down();
  }

  static void expose(node *u){
    node* rp = nullptr;

    for(node* p = u; p; p = p->parent){
      p->splay();
      p->right = rp;
      p->update_node_status();
      rp = p;
    }
    
    u->splay();
  }

  static void link(node *u, node *v){
    evert(u);
    u->parent = v;
  }
  
  static void cut(node *u){
    expose(u);
    u->left->parent = nullptr;
    u->left = nullptr;
    u->update_node_status();
  }

  static void cut(node *u, node *v){
    expose(u);
    expose(v);
    if(u->is_root()) u->parent = nullptr;
    else{
      v->left->parent = nullptr;
      v->left = nullptr;
      v->update_node_status();
    }
  }

  static void evert(node *u){
    expose(u);
    u->rev ^= true;
    u->push_down();
  }
};





template <typename Monoid>
class LinkCutTree{
  using value_type = typename Monoid::value_type;
  using node = LinkCutNode<Monoid>;

  int N;
  std::vector<node*> nodes;

public:
  LinkCutTree(int N): N(N), nodes(N){
    for(int i = 0; i < N; ++i){
      nodes[i] = new node();
    }
  }

  void expose(int k){
    node::expose(nodes[k]);
  }
  
  void cut(int i, int j){
    node::cut(nodes[i], nodes[j]);
  }

  void link(int i, int j){
    node::link(nodes[i], nodes[j]);
  }

  void evert(int k){
    node::evert(nodes[k]);
  }

  void update(int k, value_type x){
    node::evert(nodes[k]);
    nodes[k]->value = x;
    nodes[k]->push_down();
  }

  value_type at(int k){
    return nodes[k]->value;
  }

  value_type get(int i, int j){
    node::evert(nodes[i]);
    node::expose(nodes[j]);
    return nodes[j]->result;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

