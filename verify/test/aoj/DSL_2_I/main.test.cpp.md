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


# :heavy_check_mark: test/aoj/DSL_2_I/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#9c22eeac342a6663d77c7166ac847eb0">test/aoj/DSL_2_I</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_I/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp.html">Range update / Range sum</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp.html">Lazy segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <iostream>
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  LazySegmentTree<UpdateSum<int64_t,int64_t>> seg(n);
  
  for(auto [type, s, t] : input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t+1, x);
    }else{
      std::cout << seg.get(s, t+1) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_I/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <iostream>
#line 2 "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include <vector>

/**
 * @title Lazy segment tree
 * @docs lazy_segment_tree.md
 */
template <typename Monoid>
class LazySegmentTree{
  using value_type_get = typename Monoid::value_type_get;
  using value_type_update = typename Monoid::value_type_update;
  Monoid M;
  
  const int depth, size, hsize;
  std::vector<value_type_get> data;
  std::vector<value_type_update> lazy;

  void propagate(int i){
    if(lazy[i] == M.id_update()) return;
    if(i < hsize){
      lazy[i << 1 | 0] = M.op_update(lazy[i], lazy[i << 1 | 0]);
      lazy[i << 1 | 1] = M.op_update(lazy[i], lazy[i << 1 | 1]);
    }
    int len = hsize >> (31 - __builtin_clz(i));
    data[i] = M.op(data[i], lazy[i], len);
    lazy[i] = M.id_update();
  }

  value_type_get update_aux(int i, int l, int r, int s, int t, const value_type_update &x){
    propagate(i);
    if(r <= s || t <= l) return data[i];
    else if(s <= l && r <= t){
      lazy[i] = M.op_update(x, lazy[i]);
      propagate(i);
      return data[i];
    }
    else return data[i] = M.op_get(update_aux(i << 1 | 0, l, (l+r) / 2, s, t, x), update_aux(i << 1 | 1, (l+r) / 2, r, s, t, x));
  }
  
  value_type_get get_aux(int i, int l, int r, int x, int y){
    propagate(i);
    if(r <= x || y <= l) return M.id_get();
    else if(x <= l && r <= y) return data[i];
    else return M.op_get(get_aux(i << 1 | 0, l, (l+r) / 2, x, y), get_aux(i << 1 | 1, (l+r) / 2, r, x, y));
  }

public:
  LazySegmentTree(){}
  LazySegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data(size, M.id_get()),
    lazy(size, M.id_update())
  {}

  void update(int l, int r, const value_type_update &x){update_aux(1, 0, hsize, l, r, x);}
  void update_at(int i, const value_type_update &x){update(i, i+1, x);}
  value_type_get get(int l, int r){return get_aux(1, 0, hsize, l, r);}
  value_type_get at(int i){return get(i, i+1);}

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<T>(hsize, val));
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &val){
    data.assign(size, M.id_get());
    lazy.assign(size, M.id_update());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i > 0; --i) data[i] = M.op_get(data[i << 1 | 0], data[i << 1 | 1]);
  }
};
#line 2 "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"
#include <optional>

/**
 * @title Range update / Range sum
 * @docs update_sum.md
 */
template <typename T, typename U>
struct UpdateSum{
  using value_type_get = T;
  using value_type_update = std::optional<U>;

  value_type_get id_get() const {return 0;}
  value_type_update id_update() const {return {};}

  value_type_get op_get(value_type_get a, value_type_get b) const {return a + b;}
  value_type_update op_update(value_type_update a, value_type_update b) const {return (a ? a : b);}

  value_type_get op(value_type_get a, value_type_update b, int len) const {
    return b ? *b * len : a;
  }
};
#line 4 "Mylib/IO/input_tuples.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>
#line 6 "Mylib/IO/input_tuple.cpp"

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
#line 8 "Mylib/IO/input_tuples.cpp"

/**
 * @docs input_tuples.md
 */
template <typename ... Args>
class InputTuples{
  struct iter{
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
#line 7 "test/aoj/DSL_2_I/main.test.cpp"

int main(){
  int n, q; std::cin >> n >> q;

  LazySegmentTree<UpdateSum<int64_t,int64_t>> seg(n);
  
  for(auto [type, s, t] : input_tuples<int, int, int>(q)){
    if(type == 0){
      int x; std::cin >> x;
      seg.update(s, t+1, x);
    }else{
      std::cout << seg.get(s, t+1) << std::endl;
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

