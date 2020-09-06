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


# :x: test/aoj/1508/main.splay_tree.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#21b2d97411100b8521da1b9c251ad9c2">test/aoj/1508</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1508/main.splay_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/min.cpp.html">Min monoid</a>
* :x: <a href="../../../../library/Mylib/DataStructure/SplayTree/splay_tree.cpp.html">Splay tree</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples_with_index.cpp.html">Mylib/IO/input_tuples_with_index.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <iostream>
#include "Mylib/DataStructure/SplayTree/splay_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  splay_tree::SplayTree<MinMonoid<int>> s(n);

  for(auto [i, a] : input_tuples_with_index<int>(n)){
    s.update(i, {a});
  }

  for(auto [x, y, z] : input_tuples<int, int, int>(q)){
    if(x == 0){
      auto temp = s.get(z).value();
      s.erase(z);
      s.insert(y, {temp});
    }else if(x == 1){
      auto ans = s.fold(y, z + 1).value();
      std::cout << ans << std::endl;
    }else{
      s.update(y, z);
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/1508/main.splay_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <iostream>
#line 2 "Mylib/DataStructure/SplayTree/splay_tree.cpp"
#include <utility>
#include <tuple>

/**
 * @title Splay tree
 * @docs splay_tree.md
 */
namespace splay_tree {
  template <typename Monoid>
  struct SplayNode {
    using node = SplayNode<Monoid>;
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    node *left = nullptr, *right = nullptr, *parent = nullptr;
    int size;
    value_type value = M(), result = M();

    SplayNode(): size(1){}
    SplayNode(const value_type &value): size(1), value(value){}

    void rotate(){
      node *p, *pp, *c;

      p = this->parent;
      pp = p->parent;

      if(p->left == this){
        c = this->right;
        p->set_left(c);
        this->set_right(p);
      }else{
        c = this->left;
        p->set_right(c);
        this->set_left(p);
      }

      if(pp){
        if(pp->left == p) pp->left = this;
        if(pp->right == p) pp->right = this;
      }

      this->parent = pp;

      p->update();
      this->update();
    }

    int status(){
      if(!this->parent) return 0;
      if(this->parent->left == this) return 1;
      if(this->parent->right == this) return -1;
      return 0;
    }

    void splay(){
      while(status() != 0){
        if(this->parent->status() == 0){
          this->rotate();
        }else if(this->status() == this->parent->status()){
          this->parent->rotate();
          this->rotate();
        }else{
          this->rotate();
          this->rotate();
        }
      }
    }

    void update(){
      this->size = 1;
      if(this->left) this->size += this->left->size;
      if(this->right) this->size += this->right->size;

      this->result = this->value;
      if(this->left) this->result = M(this->result, this->left->result);
      if(this->right) this->result = M(this->result, this->right->result);
    }

    void set_left(node *l){
      this->left = l;
      if(l) l->parent = this;
    }

    void set_right(node *r){
      this->right = r;
      if(r) r->parent = this;
    }

    static node* get(node *root, int index){
      if(!root) return root;
      node *cur = root;

      while(1){
        int lsize = cur->left ? cur->left->size : 0;

        if(index < lsize){
          cur = cur->left;
        }else if(index == lsize){
          cur->splay();
          return cur;
        }else{
          cur = cur->right;
          index -= lsize + 1;
        }
      }
    }

    static node* merge(node *left, node *right){
      if(!left) return right;
      if(!right) return left;

      node *cur = node::get(left, left->size - 1);

      cur->right = right;
      right->parent = cur;

      right->update();
      cur->update();

      return cur;
    }

    static std::pair<node*, node*> split(node *root, int index){
      if(!root) return std::make_pair(nullptr, nullptr);
      if(index >= root->size) return std::make_pair(root, nullptr);

      auto *cur = node::get(root, index);
      auto *left = cur->left;

      if(left) left->parent = nullptr;
      cur->left = nullptr;

      if(left) left->update();
      cur->update();

      return std::make_pair(left, cur);
    }

    template <typename Func>
    static void traverse(node *cur, const Func &f){
      if(cur){
        traverse(cur->left, f);
        f(*cur);
        traverse(cur->right, f);
      }
    }
  };

  template <typename Monoid>
  struct SplayTree {
    using node = SplayNode<Monoid>;
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    node *root;

    SplayTree(): root(nullptr){}
    SplayTree(node *root): root(root){}
    SplayTree(int N): root(nullptr){
      for(int i = 0; i < N; ++i) push_back(M());
    }

    static auto singleton(const value_type &value){return SplayTree(new node(value));}

    int size() const {return root ? root->size : 0;}
    bool empty() const {return !root;}

    const value_type get(int index){root = node::get(root, index); return root->value;}
    const value_type operator[](int index){return get(index);}

    void update(int index, const value_type &value){
      root = node::get(root, index); root->value = value; root->update();
    }

    void merge_right(SplayTree &right){
      root = node::merge(root, right.root); right.root = nullptr;
    }

    void merge_left(SplayTree &left){
      root = node::merge(left.root, root); left.root = nullptr;
    }

    auto split(int index){
      node *left, *right; std::tie(left, right) = node::split(root, index);
      return std::make_pair(SplayTree(left), SplayTree(right));
    }

    void insert(int index, const value_type &value){
      auto s = node::split(root, index);
      root = node::merge(s.first, node::merge(new node(value), s.second));
    }

    void erase(int index){
      node *left, *right;
      std::tie(left, right) = node::split(root, index);
      std::tie(std::ignore, right) = node::split(right, 1);
      root = node::merge(left, right);
    }

    const value_type fold(){return root->result;}
    const value_type fold(int l, int r){ // [l, r)
      node *left, *mid, *right;
      std::tie(mid, right) = node::split(root, r);
      std::tie(left, mid) = node::split(mid, l);

      auto ret = mid->result;

      mid = node::merge(left, mid);
      root = node::merge(mid, right);

      return ret;
    }

    void push_back(const value_type &value){insert(size(), value);}
    void push_front(const value_type &value){insert(0, value);}

    void pop_back(){erase(size() - 1);}
    void pop_front(){erase(0);}

    template <typename Func>
    void traverse(const Func &f) const {
      node::traverse(root, f);
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include <algorithm>
#include <optional>

/**
 * @title Min monoid
 * @docs min.md
 */
template <typename T>
struct MinMonoid {
  using value_type = std::optional<T>;

  value_type operator()() const {return {};}
  value_type operator()(const value_type &a, const value_type &b) const {
    if(not a) return b;
    if(not b) return a;
    return {std::min(*a, *b)};
  }
};
#line 3 "Mylib/IO/input_tuples.cpp"
#include <vector>
#line 6 "Mylib/IO/input_tuples.cpp"
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());
  return s;
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples {
  struct iter {
    using value_type = std::tuple<Args ...>;
    value_type value;
    bool fetched = false;
    int N, c = 0;

    value_type operator*(){
      if(not fetched){
        std::cin >> value;
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
  InputTuples(int N): N(N){}

  iter begin() const {return iter(N);}
  iter end() const {return iter(N);}
};

template <typename ... Args>
auto input_tuples(int N){
  return InputTuples<Args ...>(N);
}
#line 8 "Mylib/IO/input_tuples_with_index.cpp"

/**
 * @docs input_tuples_with_index.md
 */
template <typename ... Args>
class InputTuplesWithIndex {
  struct iter {
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
#line 8 "test/aoj/1508/main.splay_tree.test.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  splay_tree::SplayTree<MinMonoid<int>> s(n);

  for(auto [i, a] : input_tuples_with_index<int>(n)){
    s.update(i, {a});
  }

  for(auto [x, y, z] : input_tuples<int, int, int>(q)){
    if(x == 0){
      auto temp = s.get(z).value();
      s.erase(z);
      s.insert(y, {temp});
    }else if(x == 1){
      auto ans = s.fold(y, z + 1).value();
      std::cout << ans << std::endl;
    }else{
      s.update(y, z);
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

