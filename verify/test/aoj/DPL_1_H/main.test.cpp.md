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


# :x: test/aoj/DPL_1_H/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#209a8b7f1b4449e911e26d3b013a1582">test/aoj/DPL_1_H</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_1_H/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp.html">0-1 Knapsack problem (Small quantity)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

int main(){
  int N; std::cin >> N;
  int64_t W; std::cin >> W;

  auto [v, w] = hl::input_tuple_vector<int64_t, int64_t>(N);

  auto ans = hl::knapsack_small_quantity(N, W, w, v);

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_1_H/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_quantity.cpp"
#include <map>
#include <algorithm>
#include <iterator>

/**
 * @title 0-1 Knapsack problem (Small quantity)
 * @docs knapsack_small_quantity.md
 */
namespace haar_lib {
  template <typename Weight, typename Value>
  Value knapsack_small_quantity(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
    Value ret = 0;

    const int p = N / 2;
    const int q = N - p;

    std::map<Weight, Value> a;
    for(int i = 0; i < 1 << p; ++i){
      Weight weight = 0;
      Value value = 0;
      for(int j = 0; j < p; ++j){
        if(i & (1 << j)){
          weight += w[j];
          value += v[j];
        }
      }

      a[weight] = std::max(a[weight], value);
    }

    Value m = 0;
    for(auto &kv : a){
      kv.second = std::max(kv.second, m);
      m = kv.second;
    }

    for(int i = 0; i < 1 << q; ++i){
      Weight weight = 0;
      Value value = 0;
      for(int j = 0; j < q; ++j){
        if(i & (1 << j)){
          weight += w[j + p];
          value += v[j + p];
        }
      }

      auto itr = a.upper_bound(std::max((Weight)0, cap - weight));

      itr = std::prev(itr);
      if(weight + itr->first <= cap) ret = std::max(ret, value + itr->second);
    }

    return ret;
  }
}
#line 4 "Mylib/IO/input_tuple_vector.cpp"
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
namespace haar_lib {
  template <typename T, size_t ... I>
  void input_tuple_vector_init(T &val, int N, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)), 0) ...};
  }

  template <typename T, size_t ... I>
  void input_tuple_vector_helper(T &val, int i, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::cin >> std::get<I>(val)[i]), 0) ...};
  }

  template <typename ... Args>
  auto input_tuple_vector(int N){
    std::tuple<std::vector<Args> ...> ret;

    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());
    for(int i = 0; i < N; ++i){
      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof ... (Args)>());
    }

    return ret;
  }
}
#line 7 "test/aoj/DPL_1_H/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int N; std::cin >> N;
  int64_t W; std::cin >> W;

  auto [v, w] = hl::input_tuple_vector<int64_t, int64_t>(N);

  auto ans = hl::knapsack_small_quantity(N, W, w, v);

  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

