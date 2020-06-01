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


# :x: Persistent union-find

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3ff74e8366c88d06b530f361450b1117">Mylib/DataStructure/UnionFind</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/UnionFind/persistent_unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Problems

- [Persistent UnionFind](https://judge.yosupo.jp/problem/persistent_unionfind)

## References

- [https://ei1333.github.io/luzhiled/snippets/structure/union-find.html](https://ei1333.github.io/luzhiled/snippets/structure/union-find.html)


## Depends on

* :x: <a href="../Array/persistent_array.cpp.html">Persistent array</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/persistent_unionfind/main.test.cpp.html">test/yosupo-judge/persistent_unionfind/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/DataStructure/Array/persistent_array.cpp"

/**
 * @title Persistent union-find
 * @docs persistent_unionfind.md
 */
class PersistentUnionFind{
  PersistentArray<int> par;

  PersistentUnionFind(PersistentArray<int> par): par(par){}

public:
  PersistentUnionFind(){}
  PersistentUnionFind(int n): par(PersistentArray<int>(std::vector<int>(n, -1))){}
  
  int get_root(int i) const {
    int p = par.get(i);
    if(p < 0) return i;
    return get_root(p);
  }
  
  bool is_same(int i, int j) const {
    return get_root(i) == get_root(j);
  }

  int size(int i) const {
    return -par.get(get_root(i));
  }
  
  PersistentUnionFind merge(int i, int j) const {
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return *this;

    int size_i = -par.get(ri);
    int size_j = -par.get(rj);

    PersistentArray<int> ret = par;

    if(size_i > size_j){
      ret = ret.update(ri, -(size_i + size_j));
      ret = ret.update(rj, ri);
    }else{
      ret = ret.update(rj, -(size_i + size_j));
      ret = ret.update(ri, rj);
    }
    
    return PersistentUnionFind(ret);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/UnionFind/persistent_unionfind.cpp"
#include <vector>
#line 2 "Mylib/DataStructure/Array/persistent_array.cpp"
#include <memory>
#line 4 "Mylib/DataStructure/Array/persistent_array.cpp"

/**
 * @title Persistent array
 * @docs persistent_array.md
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
  PersistentArray(){}
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

  PersistentArray(const PersistentArray &v){
    this->root = v.root;
    this->size = v.size;
    this->depth = v.depth;
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
  node* update(node *prev, int i, const T &val) const {
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
  PersistentArray update(int i, const T &val) const {
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
#line 4 "Mylib/DataStructure/UnionFind/persistent_unionfind.cpp"

/**
 * @title Persistent union-find
 * @docs persistent_unionfind.md
 */
class PersistentUnionFind{
  PersistentArray<int> par;

  PersistentUnionFind(PersistentArray<int> par): par(par){}

public:
  PersistentUnionFind(){}
  PersistentUnionFind(int n): par(PersistentArray<int>(std::vector<int>(n, -1))){}
  
  int get_root(int i) const {
    int p = par.get(i);
    if(p < 0) return i;
    return get_root(p);
  }
  
  bool is_same(int i, int j) const {
    return get_root(i) == get_root(j);
  }

  int size(int i) const {
    return -par.get(get_root(i));
  }
  
  PersistentUnionFind merge(int i, int j) const {
    int ri = get_root(i), rj = get_root(j);
    if(ri == rj) return *this;

    int size_i = -par.get(ri);
    int size_j = -par.get(rj);

    PersistentArray<int> ret = par;

    if(size_i > size_j){
      ret = ret.update(ri, -(size_i + size_j));
      ret = ret.update(rj, ri);
    }else{
      ret = ret.update(rj, -(size_i + size_j));
      ret = ret.update(ri, rj);
    }
    
    return PersistentUnionFind(ret);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

