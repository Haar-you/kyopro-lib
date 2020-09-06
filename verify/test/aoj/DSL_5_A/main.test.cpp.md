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


# :x: test/aoj/DSL_5_A/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#59b5a0a6c0973fef022e4b1a7cf092fc">test/aoj/DSL_5_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_5_A/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Algorithm/Imos/imos_1d.cpp.html">1D Imos algorithm</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuple.cpp.html">Mylib/IO/input_tuple.cpp</a>
* :x: <a href="../../../../library/Mylib/IO/input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"

#include <iostream>
#include <algorithm>
#include "Mylib/Algorithm/Imos/imos_1d.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int N, T; std::cin >> N >> T;
  Imos1D<int> imos(T + 1);

  for(auto [l, r] : input_tuples<int, int>(N)){
    imos.add(l, r, 1);
  }

  imos.build();

  int ans = 0;

  for(int i = 0; i <= T; ++i){
    ans = std::max(ans, imos[i]);
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_5_A/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_A"

#include <iostream>
#include <algorithm>
#line 2 "Mylib/Algorithm/Imos/imos_1d.cpp"
#include <vector>

/**
 * @title 1D Imos algorithm
 * @docs imos_1d.md
 */
template <typename T>
struct Imos1D {
  using value_type = T;

  std::vector<T> data;
  Imos1D(int n): data(n + 1){}

  void add(int a, int b, const T& val){ // [a, b)
    data[a] += 1;
    data[b] -= 1;
  }

  void build(){
    for(int i = 0; i < (int)data.size() - 1; ++i){
      data[i + 1] += data[i];
    }
  }

  T operator[](size_t i) const {return data[i];}
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
#line 7 "test/aoj/DSL_5_A/main.test.cpp"

int main(){
  int N, T; std::cin >> N >> T;
  Imos1D<int> imos(T + 1);

  for(auto [l, r] : input_tuples<int, int>(N)){
    imos.add(l, r, 1);
  }

  imos.build();

  int ans = 0;

  for(int i = 0; i <= T; ++i){
    ans = std::max(ans, imos[i]);
  }

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

