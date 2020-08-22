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


# :heavy_check_mark: test/yosupo-judge/static_range_sum/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e057ba653ff4e1918cbb7491bf73d8e0">test/yosupo-judge/static_range_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/static_range_sum/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_sum">https://judge.yosupo.jp/problem/static_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp.html">1D cumulative sum</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :question: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#include "Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int64_t>(N);

  auto c = CumulativeSum1D(a).build();

  for(auto [l, r] : input_tuples<int, int>(Q)){
    std::cout << c.get(l, r) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/static_range_sum/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#line 2 "Mylib/Algorithm/CumulativeSum/cumulative_sum_1d.cpp"
#include <vector>
#include <functional>
#include <cassert>

/**
 * @title 1D cumulative sum
 * @docs cumulative_sum_1d.md
 */
template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
class CumulativeSum1D{
  std::vector<T> data;
  const int N;
  const Add add;
  const Minus minus;
  bool is_built = false;

public:
  CumulativeSum1D(const std::vector<T> &a, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(a.size()), add(add), minus(minus)
  {
    data.assign(N+1, e);
    for(int i = 0; i < N; ++i) data[i+1] = a[i];
  }

  CumulativeSum1D(int N, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(N), add(add), minus(minus)
  {
    data.assign(N+1, e);
  }

  auto& update(int i, const T &val){
    assert(not is_built);
    data[i+1] = add(data[i+1], val);
    return *this;
  }

  auto& build(){
    assert(not is_built);
    for(int i = 0; i < N; ++i) data[i+1] = add(data[i+1], data[i]);
    is_built = true;
    return *this;
  }
  
  /**
   * @attention [i, j)
   */
  T get(int i, int j) const {
    assert(is_built);
    return minus(data[j], data[i]);
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
#line 7 "test/yosupo-judge/static_range_sum/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int N, Q; std::cin >> N >> Q;

  auto a = input_vector<int64_t>(N);

  auto c = CumulativeSum1D(a).build();

  for(auto [l, r] : input_tuples<int, int>(Q)){
    std::cout << c.get(l, r) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

