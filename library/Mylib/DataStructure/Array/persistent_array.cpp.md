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


# :warning: 永続配列

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0d7e284bb2256ddef55e56b25bfaf3f1">Mylib/DataStructure/Array</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Array/persistent_array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-15 00:08:41+09:00


* see: <a href="https://codeforces.com/contest/707/problem/D">https://codeforces.com/contest/707/problem/D</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <memory>
#include <vector>

/**
 * @title 永続配列
 * @see https://codeforces.com/contest/707/problem/D
 */
template <typename T>
class PersistentArray{
  struct node{
    bool is_terminal;
    int size = 1;
    node *left = nullptr, *right = nullptr;
    std::unique_ptr<T> value;

    node(): is_terminal(false){}
    node(T v): is_terminal(true), value(new T(v)){}
  };

  size_t size;
  int depth;

  node* root = nullptr;

  int get_size(node *t) const {
    return !t ? 0 : t->size;
  }

  node* init(int s, int d){
    if(s == 0) return nullptr;
    if(d == depth){
      return new node(T());
    }else{
      node *t = new node();
      t->left = init(s/2, d+1);
      t->right = init(s-s/2, d+1);
      t->size = get_size(t->left) + get_size(t->right);
      return t;
    }
  }

  void apply_init(node *t, const std::vector<T> &ret, int &i) {
    if(!t) return;

    if(t->is_terminal){
      *(t->value) = ret[i];
      ++i;
      return;
    }
    
    apply_init(t->left, ret, i);
    apply_init(t->right, ret, i);
  }
  
  PersistentArray(node *root): root(root){}

  void calc_depth(int size){
    depth = 1;
    while((int)size > (1<<depth)) depth += 1;
    depth += 1;
  }

public:
  PersistentArray(size_t size): size(size){
    calc_depth(size);
    root = init(size, 1);
  }
  
  PersistentArray(const std::vector<T> &v): size(v.size()){
    calc_depth(size);
    root = init(size, 1);

    int i = 0;
    apply_init(root, v, i);
  }
  
protected:
  T get(node *t, int i) const {
    if(t->is_terminal) return *(t->value);

    int k = get_size(t->left);
    if(i < k) return get(t->left, i);
    else return get(t->right, i-k);
  }
  
public:
  T get(int i) const {
    return get(root, i);
  }

protected:
  node* update(node *prev, int i, const T &val){
    if(prev->is_terminal) return new node(val);

    int k = get_size(prev->left);

    node *t = new node();
    if(i < k){
      t->right = prev->right;
      t->left = update(prev->left, i, val);
      t->size = get_size(t->right) + get_size(t->left);
    }else{
      t->left = prev->left;
      t->right = update(prev->right, i-k, val);
      t->size = get_size(t->right) + get_size(t->left);
    }
    return t;
  }

public:
  PersistentArray update(int i, const T &val){
    node *ret = update(root, i, val);
    return PersistentArray(ret);
  }
  
protected:
  void traverse(node *t, std::vector<T> &ret) const {
    if(!t) return;

    if(t->is_terminal){
      ret.push_back(*(t->value));
      return;
    }

    traverse(t->left, ret);
    traverse(t->right, ret);
  }
  
public:
  std::vector<T> traverse() const {
    std::vector<T> ret;
    traverse(root, ret);
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Array/persistent_array.cpp"
#include <memory>
#include <vector>

/**
 * @title 永続配列
 * @see https://codeforces.com/contest/707/problem/D
 */
template <typename T>
class PersistentArray{
  struct node{
    bool is_terminal;
    int size = 1;
    node *left = nullptr, *right = nullptr;
    std::unique_ptr<T> value;

    node(): is_terminal(false){}
    node(T v): is_terminal(true), value(new T(v)){}
  };

  size_t size;
  int depth;

  node* root = nullptr;

  int get_size(node *t) const {
    return !t ? 0 : t->size;
  }

  node* init(int s, int d){
    if(s == 0) return nullptr;
    if(d == depth){
      return new node(T());
    }else{
      node *t = new node();
      t->left = init(s/2, d+1);
      t->right = init(s-s/2, d+1);
      t->size = get_size(t->left) + get_size(t->right);
      return t;
    }
  }

  void apply_init(node *t, const std::vector<T> &ret, int &i) {
    if(!t) return;

    if(t->is_terminal){
      *(t->value) = ret[i];
      ++i;
      return;
    }
    
    apply_init(t->left, ret, i);
    apply_init(t->right, ret, i);
  }
  
  PersistentArray(node *root): root(root){}

  void calc_depth(int size){
    depth = 1;
    while((int)size > (1<<depth)) depth += 1;
    depth += 1;
  }

public:
  PersistentArray(size_t size): size(size){
    calc_depth(size);
    root = init(size, 1);
  }
  
  PersistentArray(const std::vector<T> &v): size(v.size()){
    calc_depth(size);
    root = init(size, 1);

    int i = 0;
    apply_init(root, v, i);
  }
  
protected:
  T get(node *t, int i) const {
    if(t->is_terminal) return *(t->value);

    int k = get_size(t->left);
    if(i < k) return get(t->left, i);
    else return get(t->right, i-k);
  }
  
public:
  T get(int i) const {
    return get(root, i);
  }

protected:
  node* update(node *prev, int i, const T &val){
    if(prev->is_terminal) return new node(val);

    int k = get_size(prev->left);

    node *t = new node();
    if(i < k){
      t->right = prev->right;
      t->left = update(prev->left, i, val);
      t->size = get_size(t->right) + get_size(t->left);
    }else{
      t->left = prev->left;
      t->right = update(prev->right, i-k, val);
      t->size = get_size(t->right) + get_size(t->left);
    }
    return t;
  }

public:
  PersistentArray update(int i, const T &val){
    node *ret = update(root, i, val);
    return PersistentArray(ret);
  }
  
protected:
  void traverse(node *t, std::vector<T> &ret) const {
    if(!t) return;

    if(t->is_terminal){
      ret.push_back(*(t->value));
      return;
    }

    traverse(t->left, ret);
    traverse(t->right, ret);
  }
  
public:
  std::vector<T> traverse() const {
    std::vector<T> ret;
    traverse(root, ret);
    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

