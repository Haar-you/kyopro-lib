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


# :x: test/aoj/0323/main.ternary.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#64b51258818892ff133e88d4c55d7a44">test/aoj/0323</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/0323/main.ternary.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0323">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0323</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Algorithm/Search/ternary_search_upwards.cpp.html">Ternary search (Convex upwards)</a>
* :question: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0323"
#define ERROR 0.001

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include "Mylib/Algorithm/Search/ternary_search_upwards.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"


int main(){
  int N; std::cin >> N;

  auto [x, r] = input_tuple_vector<int64_t, int64_t>(N);

  std::vector<std::pair<int64_t,int>> p;
  for(int i = 0; i < N; ++i){
    p.emplace_back(x[i] - r[i], -1);
    p.emplace_back(x[i] + r[i], 1);
  }

  std::sort(p.begin(), p.end());
  
  double left, right;

  int c = 0;
  for(auto &a : p){
    if(c == N){
      right = a.first;
    }
    
    c -= a.second;

    if(c == N){
      left = a.first;
    }
  }

  auto f =
    [&](double p){
      double ret = 1e9;
      
      for(int i = 0; i < N; ++i){
        double l = std::abs(x[i] - p);
        ret = std::min(ret, std::sqrt(r[i] * r[i] - l * l));
      }

      return ret;
    };

  auto a = ternary_search_upwards<double>(left, right, f);

  std::cout << std::fixed << std::setprecision(12) << f(a) << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/0323/main.ternary.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0323"
#define ERROR 0.001

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#line 2 "Mylib/Algorithm/Search/ternary_search_upwards.cpp"
#include <functional>

/**
 * @title Ternary search (Convex upwards)
 * @docs ternary_search_upwards.md
 */
template <typename T = double, typename Func = std::function<T(T)>>
T ternary_search_upwards(T lb, T ub, const Func &f, int LOOP_COUNT = 100){
  T t1,t2;
  
  while(LOOP_COUNT--){
    t1 = lb + (ub-lb) / 3;
    t2 = lb + (ub-lb) / 3 * 2;
    
    if(f(t1) > f(t2)){
      ub = t2;
    }else{
      lb = t1;
    }
  }
 
  return lb;
}
#line 3 "Mylib/IO/input_tuple_vector.cpp"
#include <vector>
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
#line 10 "test/aoj/0323/main.ternary.test.cpp"


int main(){
  int N; std::cin >> N;

  auto [x, r] = input_tuple_vector<int64_t, int64_t>(N);

  std::vector<std::pair<int64_t,int>> p;
  for(int i = 0; i < N; ++i){
    p.emplace_back(x[i] - r[i], -1);
    p.emplace_back(x[i] + r[i], 1);
  }

  std::sort(p.begin(), p.end());
  
  double left, right;

  int c = 0;
  for(auto &a : p){
    if(c == N){
      right = a.first;
    }
    
    c -= a.second;

    if(c == N){
      left = a.first;
    }
  }

  auto f =
    [&](double p){
      double ret = 1e9;
      
      for(int i = 0; i < N; ++i){
        double l = std::abs(x[i] - p);
        ret = std::min(ret, std::sqrt(r[i] * r[i] - l * l));
      }

      return ret;
    };

  auto a = ternary_search_upwards<double>(left, right, f);

  std::cout << std::fixed << std::setprecision(12) << f(a) << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
