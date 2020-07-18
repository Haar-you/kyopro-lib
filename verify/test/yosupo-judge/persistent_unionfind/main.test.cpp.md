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


# :heavy_check_mark: test/yosupo-judge/persistent_unionfind/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f0d4a2f821c524efe4216afab062275c">test/yosupo-judge/persistent_unionfind</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/persistent_unionfind/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-06 22:54:09+09:00


* see: <a href="https://judge.yosupo.jp/problem/persistent_unionfind">https://judge.yosupo.jp/problem/persistent_unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/Array/persistent_array.cpp.html">Persistent array</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/UnionFind/persistent_unionfind.cpp.html">Persistent union-find</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples_with_index.cpp.html">Mylib/IO/input_tuples_with_index.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/UnionFind/persistent_unionfind.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<PersistentUnionFind> G(Q+1);

  G[0] = PersistentUnionFind(N);

  for(auto [i, t, k, u, v] : input_tuples_with_index<int, int, int, int>(Q)){
    ++k;
    ++i;
    
    if(t == 0){
      G[i] = G[k].merge(u, v);
    }else{
      std::cout << G[k].is_same(u, v) << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/persistent_unionfind/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
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
  
  int root_of(int i) const {
    int p = par.get(i);
    if(p < 0) return i;
    return root_of(p);
  }
  
  bool is_same(int i, int j) const {
    return root_of(i) == root_of(j);
  }

  int size_of(int i) const {
    return -par.get(root_of(i));
  }
  
  PersistentUnionFind merge(int i, int j) const {
    int ri = root_of(i), rj = root_of(j);
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
#line 4 "Mylib/IO/input_tuples_with_index.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 5 "Mylib/IO/input_tuple.cpp"
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples_with_index.cpp"

/**
 * @docs input_tuples_with_index.md
 */
template <typename ... Args>
class InputTuplesWithIndex{
  struct iter{
    using value_type = std::tuple<int, Args ...>;
    value_type value;
    bool fetched = false;
    int N;
    int c = 0;

    value_type operator*(){
      if(not fetched){
        std::tuple<Args ...> temp; std::cin >> temp;
        value = std::tuple_cat(std::make_tuple(c), temp);
      }
      return value;
    }

    void operator++(){
      ++c;
      fetched = false;
    }

    bool operator!=(iter &) const {
      return c < N;
    }

    iter(int N): N(N){}
  };

  int N;

public:
  InputTuplesWithIndex(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples_with_index(int N){
  return InputTuplesWithIndex<Args ...>(N);
}

#line 7 "test/yosupo-judge/persistent_unionfind/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  std::vector<PersistentUnionFind> G(Q+1);

  G[0] = PersistentUnionFind(N);

  for(auto [i, t, k, u, v] : input_tuples_with_index<int, int, int, int>(Q)){
    ++k;
    ++i;
    
    if(t == 0){
      G[i] = G[k].merge(u, v);
    }else{
      std::cout << G[k].is_same(u, v) << "\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

