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


# :x: test/aoj/DSL_2_F/main.dynamic.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2ac20e439971e957ed6809338e9771d9">test/aoj/DSL_2_F</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_F/main.dynamic.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:14:08+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/MonoidAction/update_min.cpp.html">Range update / Range min</a>
* :x: <a href="../../../../library/Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp.html">Dynamic lazy segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>
#include <climits>
#include "Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_min.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  hl::dynamic_lazy_segment_tree<hl::update_min<int, int>> seg(n);

  for(auto [type, s, t] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t + 1, x);
    }else{
      std::cout << seg.get(s, t + 1).value_or(INT_MAX) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_F/main.dynamic.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>
#include <climits>
#line 2 "Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp"
#include <cstdint>

/**
 * @title Dynamic lazy segment tree
 * @docs dynamic_lazy_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class dynamic_lazy_segment_tree {
    using value_type_get = typename Monoid::value_type_get;
    using value_type_update = typename Monoid::value_type_update;
    const static Monoid M;

    struct node {
      value_type_get value;
      value_type_update lazy;
      node *left = nullptr, *right = nullptr;
      node(){}
      node(const value_type_get &value, const value_type_update &lazy): value(value), lazy(lazy){}
    };

    int64_t depth, size, hsize;
    node *root = nullptr;

    void propagate(node *t, int64_t l, int64_t r){
      if(t->lazy == M.id_update()) return;
      if(r - l > 1){
        if(not t->left) t->left = new node(M.id_get(), M.id_update());
        t->left->lazy = M.op_update(t->lazy, t->left->lazy);
        if(not t->right) t->right = new node(M.id_get(), M.id_update());
        t->right->lazy = M.op_update(t->lazy, t->right->lazy);
      }
      int64_t len = r - l;
      t->value = M.op(t->value, t->lazy, len);
      t->lazy = M.id_update();
    }

    node* update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, value_type_update value){
      if(not t) t = new node(M.id_get(), M.id_update());

      propagate(t, l, r);
      if(r - l == 1){
        if(x <= l and r <= y) t->lazy = M.op_update(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      if(r < x or y < l) return t;
      if(x <= l and r <= y){
        t->lazy = M.op_update(value, t->lazy);
        propagate(t, l, r);
        return t;
      }

      t->left = update(t->left, l, (l + r) / 2, x, y, value);
      t->right = update(t->right, (l + r) / 2, r, x, y, value);
      t->value = M.op_get(t->left->value, t->right->value);

      return t;
    }

    value_type_get get(node *t, int64_t l, int64_t r, int64_t x, int64_t y){
      if(not t) return M.id_get();

      propagate(t, l, r);
      if(r <= x or y <= l) return M.id_get();
      if(x <= l and r <= y) return t->value;

      return M.op_get(
        get(t->left, l, (l + r) / 2, x, y),
        get(t->right, (l + r) / 2, r, x, y)
      );
    }

  public:
    dynamic_lazy_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M.id_get(), M.id_update());
    }

    void update(int64_t l, int64_t r, value_type_update value){
      update(root, 0, hsize, l, r, value);
    }

    value_type_get get(int64_t l, int64_t r){
      return get(root, 0, hsize, l, r);
    }

    value_type_get operator[](int64_t i){
      return get(i, i + 1);
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/MonoidAction/update_min.cpp"
#include <optional>

/**
 * @title Range update / Range min
 * @docs update_min.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct update_min {
    using value_type_get = std::optional<T>;
    using value_type_update = std::optional<U>;

    value_type_get id_get() const {return {};}
    value_type_update id_update() const {return {};}

    value_type_get op_get(value_type_get a, value_type_get b) const {
      if(not a) return b;
      if(not b) return a;
      return {std::min(*a, *b)};
    }
    value_type_update op_update(value_type_update a, value_type_update b) const {return (a ? a : b);}

    value_type_get op(value_type_get a, value_type_update b, int) const {
      return b ? *b : a;
    }
  };
}
#line 3 "Mylib/IO/input_tuples.cpp"
#include <vector>
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

/**
 * @docs input_tuple.md
 */
namespace haar_lib {
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
}
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
namespace haar_lib {
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
}
#line 8 "test/aoj/DSL_2_F/main.dynamic.test.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  hl::dynamic_lazy_segment_tree<hl::update_min<int, int>> seg(n);

  for(auto [type, s, t] : hl::input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t + 1, x);
    }else{
      std::cout << seg.get(s, t + 1).value_or(INT_MAX) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

