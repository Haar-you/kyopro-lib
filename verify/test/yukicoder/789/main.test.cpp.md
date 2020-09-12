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


# :x: test/yukicoder/789/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f2dc228f845da8f438899cc780c48dec">test/yukicoder/789</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/789/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:14:08+09:00


* see: <a href="https://yukicoder.me/problems/no/789">https://yukicoder.me/problems/no/789</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Sum monoid</a>
* :x: <a href="../../../../library/Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp.html">Dynamic segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/789"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;

  hl::dynamic_segment_tree<hl::sum_monoid<int64_t>> seg(1000000001);

  int64_t ans = 0;

  for(auto [q, x, y] : hl::input_tuples<int, int, int>(n)){
    if(q == 0){
      seg.update(x, seg[x] + y);
    }else{
      ans += seg.get(x, y + 1);
    }
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/789/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/789"

#include <iostream>
#line 2 "Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp"
#include <cstdint>

/**
 * @title Dynamic segment tree
 * @docs dynamic_segment_tree.md
 */
namespace haar_lib {
  template <typename Monoid>
  class dynamic_segment_tree {
    using value_type = typename Monoid::value_type;
    const static Monoid M;

    struct node {
      value_type val;
      node *left = nullptr, *right = nullptr;
      node(const value_type &val): val(val) {}
    };

    int64_t depth, size, hsize;
    node *root = nullptr;

    value_type eval(node *t) const {
      return t ? t->val : M();
    }

    node* update(node *t, int64_t l, int64_t r, int64_t pos, const value_type &val){
      if(r - l == 1){
        if(t) t->val = val;
        else t = new node(val);
      }else{
        const int64_t m = (l + r) / 2;
        if(not t) t = new node(val);
        if(pos < m) t->left = update(t->left, l, m, pos, val);
        else t->right = update(t->right, m, r, pos, val);
        t->val = M(eval(t->left), eval(t->right));
      }
      return t;
    }

    value_type get(node* t, int64_t l, int64_t r, int64_t x, int64_t y) const {
      if(not t) return M();
      if(x <= l && r <= y) return t ? t->val : M();
      if(r < x || y < l) return M();
      int64_t m = (l + r) >> 1;
      return M(get(t->left, l, m, x, y), get(t->right, m, r, x, y));
    }

  public:
    dynamic_segment_tree(int64_t n):
      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),
      size(1LL << depth),
      hsize(size / 2)
    {
      root = new node(M());
    }

    void update(int64_t i, const value_type &x){
      update(root, 0, hsize, i, x);
    }

    value_type get(int64_t l, int64_t r) const {
      return get(root, 0, hsize, l, r);
    }

    value_type operator[](int64_t i) const {
      return get(i, i + 1);
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
#line 7 "test/yukicoder/789/main.test.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;

  hl::dynamic_segment_tree<hl::sum_monoid<int64_t>> seg(1000000001);

  int64_t ans = 0;

  for(auto [q, x, y] : hl::input_tuples<int, int, int>(n)){
    if(q == 0){
      seg.update(x, seg[x] + y);
    }else{
      ans += seg.get(x, y + 1);
    }
  }

  std::cout << ans << "\n";

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

