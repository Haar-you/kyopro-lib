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


# :heavy_check_mark: test/yukicoder/755/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ee474aa687e73628de0ff7ea7a02b81b">test/yukicoder/755</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/755/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="https://yukicoder.me/problems/no/755">https://yukicoder.me/problems/no/755</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp.html">2D cumulative sum</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_vector.cpp.html">Mylib/IO/input_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/755"

#include <iostream>
#include <vector>

#include "Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;

  auto A = input_vector<int64_t>(M, M);

  auto c = CumulativeSum2D(A).build();

  for(auto [x, y] : input_tuples<int, int>(N)){
    --x, --y;

    int ans = 0;
    
    for(int x1 = 0; x1 <= x; ++x1){
      for(int y1 = 0; y1 <= y; ++y1){
        for(int x2 = x; x2 < M; ++x2){
          for(int y2 = y; y2 < M; ++y2){
            if(c.get(x1, y1, x2 + 1, y2 + 1) == 0) ++ans;
          }
        }
      }  
    }

    std::cout << ans << std::endl;
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/755/main.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/755"

#include <iostream>
#include <vector>

#line 3 "Mylib/Algorithm/CumulativeSum/cumulative_sum_2d.cpp"
#include <functional>
#include <cassert>

/**
 * @title 2D cumulative sum
 * @docs cumulative_sum_2d.md
 */
template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
class CumulativeSum2D{
  std::vector<std::vector<T>> data;
  const int N, M;
  const Add add;
  const Minus minus;
  bool is_built = false;

public:
  CumulativeSum2D(const std::vector<std::vector<T>> &a, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(a.size()), M(a[0].size()), add(add), minus(minus)
  {
    data.assign(N+1, std::vector<T>(M+1, e));
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < M; ++j){
        data[i+1][j+1] = a[i][j];
      }
    }
  }

  CumulativeSum2D(int N, int M, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(N), M(M), add(add), minus(minus)
  {
    data.assign(N+1, std::vector<T>(M+1, e));
  }

  auto& update(int i, int j, const T &val){
    assert(not is_built);
    data[i+1][j+1] = add(data[i+1][j+1], val);
    return *this;
  }

  auto& build(){
    assert(not is_built);
    for(int i = 1; i <= N; ++i) for(int j = 0; j <= M; ++j) data[i][j] = add(data[i][j], data[i-1][j]);
    for(int i = 0; i <= N; ++i) for(int j = 1; j <= M; ++j) data[i][j] = add(data[i][j], data[i][j-1]);
    is_built = true;
    return *this;
  }

  T get(int x1, int y1, int x2, int y2) const { // [x1,x2), [y1,y2)
    assert(is_built);
    return add(minus(data[x2][y2], add(data[x1][y2], data[x2][y1])), data[x1][y1]);
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
#line 9 "test/yukicoder/755/main.test.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M; std::cin >> N >> M;

  auto A = input_vector<int64_t>(M, M);

  auto c = CumulativeSum2D(A).build();

  for(auto [x, y] : input_tuples<int, int>(N)){
    --x, --y;

    int ans = 0;
    
    for(int x1 = 0; x1 <= x; ++x1){
      for(int y1 = 0; y1 <= y; ++y1){
        for(int x2 = x; x2 < M; ++x2){
          for(int y2 = y; y2 < M; ++y2){
            if(c.get(x1, y1, x2 + 1, y2 + 1) == 0) ++ans;
          }
        }
      }  
    }

    std::cout << ans << std::endl;
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

