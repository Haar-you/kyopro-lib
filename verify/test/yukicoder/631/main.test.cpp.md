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


# :x: test/yukicoder/631/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0b2f27755ad8078580256305f9366a63">test/yukicoder/631</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/631/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 19:38:51+09:00


* see: <a href="https://yukicoder.me/problems/no/631">https://yukicoder.me/problems/no/631</a>


## Depends on

* :x: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/max.cpp.html">Mylib/AlgebraicStructure/Monoid/max.cpp</a>
* :question: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/sum.cpp.html">Mylib/AlgebraicStructure/Monoid/sum.cpp</a>
* :x: <a href="../../../../library/Mylib/AlgebraicStructure/MonoidAction/add_max.cpp.html">Mylib/AlgebraicStructure/MonoidAction/add_max.cpp</a>
* :question: <a href="../../../../library/Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp.html">Lazy segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/631"

#include <iostream>
#include <vector>

#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_max.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;
  auto seg = LazySegmentTree<AddMax<int64_t,int64_t>>(N-1);

  auto T = input_vector<int64_t>(N-1);
    
  for(int i = 0; i < N-1; ++i){
    T[i] += 3 * (N-1-i);
  }

  seg.init_with_vector(T);
    
  int M; std::cin >> M;

  for(auto [L, R, D] : input_tuples<int, int, int>(M)){
    --L, --R;

    seg.update(L, R+1, D);
      
    auto ans = seg.get(0, N-1).value();
    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/631/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/631"

#include <iostream>
#include <vector>

#line 3 "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"

/**
 * @title Lazy segment tree
 * @docs lazy_segment_tree.md
 */
template <typename Monoid>
class LazySegmentTree{
  using value_type_get = typename Monoid::value_type_get;
  using value_type_update = typename Monoid::value_type_update;
  using monoid_get = typename Monoid::monoid_get;
  using monoid_update = typename Monoid::monoid_update;
  
  const int depth, size, hsize;
  std::vector<value_type_get> data;
  std::vector<value_type_update> lazy;

  inline void propagate(int i){
    if(lazy[i] == monoid_update::id()) return;
    if(i < hsize){
      lazy[i << 1 | 0] = monoid_update::op(lazy[i], lazy[i << 1 | 0]);
      lazy[i << 1 | 1] = monoid_update::op(lazy[i], lazy[i << 1 | 1]);
    }
    int len = hsize >> (31 - __builtin_clz(i));
    data[i] = Monoid::op(data[i], lazy[i], len);
    lazy[i] = monoid_update::id();
  }

  inline value_type_get update_aux(int i, int l, int r, int s, int t, const value_type_update &x){
    propagate(i);
    if(r <= s || t <= l) return data[i];
    else if(s <= l && r <= t){
      lazy[i] = monoid_update::op(x, lazy[i]);
      propagate(i);
      return data[i];
    }
    else return data[i] = monoid_get::op(update_aux(i << 1 | 0, l, (l+r) / 2, s, t, x), update_aux(i << 1 | 1, (l+r) / 2, r, s, t, x));
  }
  
  inline value_type_get get_aux(int i, int l, int r, int x, int y){
    propagate(i);
    if(r <= x || y <= l) return monoid_get::id();
    else if(x <= l && r <= y) return data[i];
    else return monoid_get::op(get_aux(i << 1 | 0, l, (l+r) / 2, x, y), get_aux(i << 1 | 1, (l+r) / 2, r, x, y));
  }

public:
  LazySegmentTree(){}
  LazySegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth),
    hsize(size / 2),
    data(size, monoid_get::id()),
    lazy(size, monoid_update::id())
  {}

  inline void update(int l, int r, const value_type_update &x){update_aux(1, 0, hsize, l, r, x);}
  inline void update_at(int i, const value_type_update &x){update(i, i+1, x);}
  inline value_type_get get(int l, int r){return get_aux(1, 0, hsize, l, r);}
  inline value_type_get at(int i){return get(i, i+1);}

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<T>(hsize, val));
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &val){
    data.assign(size, monoid_get::id());
    lazy.assign(size, monoid_update::id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i > 0; --i) data[i] = monoid_get::op(data[i << 1 | 0], data[i << 1 | 1]);
  }
};
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @docs sum.md
 */
template <typename T>
struct SumMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a + b;}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/max.cpp"
#include <algorithm>
#include <optional>

/**
 * @docs max.md
 */
template <typename T>
struct MaxMonoid{
  using value_type = std::optional<T>;
  
  static value_type id(){return {};}
  static value_type op(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;
    return {std::max(*a, *b)};
  }
};
#line 4 "Mylib/AlgebraicStructure/MonoidAction/add_max.cpp"

/**
 * @docs add_max.md
 */
template <typename T, typename U>
struct AddMax{
  using monoid_get = MaxMonoid<T>;
  using monoid_update = SumMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    if(a) return {*a + b};
    return {};
  }
};
#line 4 "Mylib/IO/input_vector.cpp"

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}
#line 4 "Mylib/IO/input_tuples.cpp"
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
#line 10 "test/yukicoder/631/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N; std::cin >> N;
  auto seg = LazySegmentTree<AddMax<int64_t,int64_t>>(N-1);

  auto T = input_vector<int64_t>(N-1);
    
  for(int i = 0; i < N-1; ++i){
    T[i] += 3 * (N-1-i);
  }

  seg.init_with_vector(T);
    
  int M; std::cin >> M;

  for(auto [L, R, D] : input_tuples<int, int, int>(M)){
    --L, --R;

    seg.update(L, R+1, D);
      
    auto ans = seg.get(0, N-1).value();
    std::cout << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
