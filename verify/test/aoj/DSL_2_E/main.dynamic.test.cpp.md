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


# :x: test/aoj/DSL_2_E/main.dynamic.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5d35c06ff9ff8df734499811915aeac0">test/aoj/DSL_2_E</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_E/main.dynamic.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:14:08+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Sum monoid</a>
* :x: <a href="../../../../library/Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp.html">Dynamic dual segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  auto seg = hl::dynamic_dual_segment_tree<hl::sum_monoid<int>>(n);

  for(auto [type] : hl::input_tuples<int>(q)){
    if(type == 0){
      int s, t, x; std::cin >> s >> t >> x;
      seg.update(s - 1, t, x);
    }else{
      int t; std::cin >> t;
      std::cout << seg[t - 1] << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_E/main.dynamic.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <iostream>
#line 2 "Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp"
#include <unordered_map>

/**
 * @title Dynamic dual segment tree
 * @docs dynamic_dual_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class dynamic_dual_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type val;
      node *left = nullptr, *right = nullptr;
      node(const value_type &val): val(val) {}
    };

    const int64_t depth, size, hsize;
    node *root = nullptr;
    std::unordered_map<int64_t, node*> umap;

    void propagate(node *t, int64_t l, int64_t r){
      if(r - l > 1){
        if(not t->left) t->left = new node(M());
        t->left->val = M(t->val, t->left->val);

        if(not t->right) t->right = new node(M());
        t->right->val = M(t->val, t->right->val);

        t->val = M();
      }
    }

    void update(node *t, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val){
      if(r - l == 1){
        if(x <= l && r <= y) t->val = M(t->val, val);
        umap[l] = t;
        return;
      }
      if(r < x || y < l) return;
      else if(x <= l && r <= y) t->val = M(t->val, val);
      else{
        const int64_t m = (l + r) / 2;
        propagate(t, l, r);
        update(t->left, l, m, x, y, val);
        update(t->right, m, r, x, y, val);
      }
    }

    void get(node* t, int64_t l, int64_t r, int64_t x){
      if(r - l == 1){
        umap[l] = t;
        return;
      }
      propagate(t, l, r);
      int m = (l + r) / 2;
      if(x < m) get(t->left, l, m, x);
      else get(t->right, m, r, x);
    }

  public:
    dynamic_dual_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M());
    }

    void update(int64_t s, int64_t t, value_type &x){
      update(root, 0, hsize, s, t, x);
    }

    value_type operator[](int64_t x){
      get(root, 0, hsize, x);
      return umap[x]->val;
    }
  };
}
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @title Sum monoid
 * @docs sum.md
 */
namespace haar_lib {
  template <typename T>
  struct sum_monoid {
    using value_type = T;
    value_type operator()() const {return 0;}
    value_type operator()(value_type a, value_type b) const {return a + b;}
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
#line 7 "test/aoj/DSL_2_E/main.dynamic.test.cpp"

namespace hl = haar_lib;

int main(){
  int n, q; std::cin >> n >> q;

  auto seg = hl::dynamic_dual_segment_tree<hl::sum_monoid<int>>(n);

  for(auto [type] : hl::input_tuples<int>(q)){
    if(type == 0){
      int s, t, x; std::cin >> s >> t >> x;
      seg.update(s - 1, t, x);
    }else{
      int t; std::cin >> t;
      std::cout << seg[t - 1] << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

