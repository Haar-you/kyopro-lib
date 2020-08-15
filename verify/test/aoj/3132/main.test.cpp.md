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


# :heavy_check_mark: test/aoj/3132/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5df7098d8629f5dad4d475167fe60fb9">test/aoj/3132</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/3132/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3132">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3132</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/product.cpp.html">Mylib/AlgebraicStructure/Monoid/product.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SegmentTree/segment_tree.cpp.html">Segment tree</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3132"
#define ERROR 1e-7

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Mylib/AlgebraicStructure/Monoid/product.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int N; std::cin >> N;
  
  auto seg = SegmentTree<ProductMonoid<double>>(N);

  auto [T, A] = input_tuple_vector<int, int>(N);
  
  for(int i = 0; i < N; ++i){
    seg.update(i, 0.1 * (10 - A[i]));
  }

  int Q; std::cin >> Q;

  for(auto [L, R] : input_tuples<int, int>(Q)){
    int l = std::lower_bound(T.begin(), T.end(), L) - T.begin();
    int r = std::lower_bound(T.begin(), T.end(), R) - T.begin();
    
    auto ans = seg.get(l, r) * 1e9;
    
    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/3132/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3132"
#define ERROR 1e-7

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#line 2 "Mylib/AlgebraicStructure/Monoid/product.cpp"

/**
 * @docs product.md
 */
template <typename T>
struct ProductMonoid{
  using value_type = T;
  value_type id() const {return 1;}
  value_type op(value_type a, value_type b) const {return a * b;}
};
#line 3 "Mylib/DataStructure/SegmentTree/segment_tree.cpp"

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
template <typename Monoid>
class SegmentTree{
  using value_type = typename Monoid::value_type;
  Monoid M;
  
  int depth, size, hsize;
  std::vector<value_type> data;

public:
  SegmentTree(){}
  SegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, M.id())
  {}

  auto operator[](int i) const {return at(i);}
  auto at(int i) const {return data[hsize + i];}
  
  auto get(int x, int y) const { // [x,y)
    value_type ret_left = M.id();
    value_type ret_right = M.id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = M.op(data[--r], ret_right);
      if(l & 1) ret_left = M.op(ret_left, data[l++]);
      l >>= 1, r >>= 1;
    }
    
    return M.op(ret_left, ret_right);
  }

  void update(int i, const value_type &x){
    i += hsize;
    data[i] = x;
    while(i > 1) i >>= 1, data[i] = M.op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &val){
    data.assign(size, M.id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i >= 1; --i) data[i] = M.op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }  
};
#line 4 "Mylib/IO/input_tuple_vector.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
template <typename T, size_t ... I>
void input_tuple_vector_init(T &val, int N, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)), 0)...};
}

template <typename T, size_t ... I>
void input_tuple_vector_helper(T &val, int i, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)[i]), 0)...};
}

template <typename ... Args>
auto input_tuple_vector(int N){
  std::tuple<std::vector<Args>...> ret;

  input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());
  for(int i = 0; i < N; ++i){
    input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());
  }

  return ret;
}
#line 6 "Mylib/IO/input_tuples.cpp"
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
#line 12 "test/aoj/3132/main.test.cpp"

int main(){
  int N; std::cin >> N;
  
  auto seg = SegmentTree<ProductMonoid<double>>(N);

  auto [T, A] = input_tuple_vector<int, int>(N);
  
  for(int i = 0; i < N; ++i){
    seg.update(i, 0.1 * (10 - A[i]));
  }

  int Q; std::cin >> Q;

  for(auto [L, R] : input_tuples<int, int>(Q)){
    int l = std::lower_bound(T.begin(), T.end(), L) - T.begin();
    int r = std::lower_bound(T.begin(), T.end(), R) - T.begin();
    
    auto ans = seg.get(l, r) * 1e9;
    
    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

