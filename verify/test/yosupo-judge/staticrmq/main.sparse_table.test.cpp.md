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


# :heavy_check_mark: test/yosupo-judge/staticrmq/main.sparse_table.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5680c9d4a5622c4318d3dde130a2c657">test/yosupo-judge/staticrmq</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/staticrmq/main.sparse_table.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/AlgebraicStructure/Monoid/min.cpp.html">Mylib/AlgebraicStructure/Monoid/min.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/DataStructure/SparseTable/sparse_table.cpp.html">Sparse table</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>

#include "Mylib/DataStructure/SparseTable/sparse_table.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int>(N);

  SparseTable<MinMonoid<int>> s(a);

  for(auto [l, r] : input_tuples<int, int>(Q)){
    std::cout << s.get(l, r).value() << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/staticrmq/main.sparse_table.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>

#line 3 "Mylib/DataStructure/SparseTable/sparse_table.cpp"
#include <utility>
#include <algorithm>

/**
 * @title Sparse table
 * @docs sparse_table.md
 */
template <typename Semilattice>
class SparseTable{
  using value_type = typename Semilattice::value_type;
  Semilattice S;
  
  std::vector<std::vector<value_type>> a;
  std::vector<int> log_table;
  
public:
  template <typename T>
  SparseTable(const std::vector<T> &v){
    int n = v.size();
    int logn = 0;
    while((1 << logn) <= n) ++logn;
    
    a.assign(n, std::vector<value_type>(logn));
    for(int i = 0; i < n; ++i) a[i][0] = v[i];
    for(int j = 1; j < logn; ++j){
      for(int i = 0; i < n; ++i){
        a[i][j] = S.op(a[i][j-1], a[std::min<int>(n-1, i+(1<<(j-1)))][j-1]);
      }
    }

    log_table.assign(n+1, 0);
    for(int i = 2; i < n+1; ++i) log_table[i] = log_table[i>>1] + 1;
  }
  
  value_type get(int s, int t) const { // [s,t)
    int k = log_table[t-s];
    return S.op(a[s][k], a[t-(1<<k)][k]);
  }

  value_type get(std::vector<std::pair<int,int>> st) const {
    value_type ret;
    bool t = true;

    for(const auto &p : st){
      if(p.first < p.second){
        if(t){
          ret = get(p.first, p.second);
          t = false;
        }else{
          ret = S.op(ret, get(p.first, p.second));
        }
      }
    }

    return ret;
  }
};
#line 3 "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include <optional>

/**
 * @docs min.md
 */
template <typename T>
struct MinMonoid{
  using value_type = std::optional<T>;
  
  value_type id() const {return {};}
  value_type op(const value_type &a, const value_type &b) const {
    if(not a) return b;
    if(not b) return a;
    return {std::min(*a, *b)};
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
#line 6 "Mylib/IO/input_tuples.cpp"
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
#line 10 "test/yosupo-judge/staticrmq/main.sparse_table.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int>(N);

  SparseTable<MinMonoid<int>> s(a);

  for(auto [l, r] : input_tuples<int, int>(Q)){
    std::cout << s.get(l, r).value() << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

