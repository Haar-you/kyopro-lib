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


# :heavy_check_mark: test/aoj/DPL_1_F/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#957906ba4d4b0f9584675f3244cffcf8">test/aoj/DPL_1_F</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_1_F/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/TypicalProblem/KnapsackProblem/knapsack_small_value.cpp.html">0-1 Knapsack problem (Small value)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_value.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

int main(){
  int N; std::cin >> N;
  int64_t W; std::cin >> W;

  auto [v, w] = input_tuple_vector<int64_t, int64_t>(N);
  
  auto ans = knapsack_small_value(N, W, w, v);
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_1_F/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_F"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_value.cpp"
#include <algorithm>
#include <numeric>
#include <climits>

/**
 * @title 0-1 Knapsack problem (Small value)
 * @docs knapsack_small_value.md
 */
template <typename Weight, typename Value>
Value knapsack_small_value(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
  Value MAX_V = std::accumulate(v.begin(), v.end(), 0);
  std::vector<std::vector<Value>> dp(N+1, std::vector<Value>(MAX_V+1, LLONG_MAX));

  dp[0][0] = 0;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= MAX_V; ++j){
      dp[i+1][j] = std::min(dp[i+1][j], dp[i][j]);
      if(j+v[i] <= MAX_V and dp[i][j] < LLONG_MAX) dp[i+1][j+v[i]] = std::min(dp[i+1][j+v[i]], dp[i][j]+w[i]);
    }
  }

  Value ret = 0;

  for(int i = 0; i <= MAX_V; ++i){
    if(dp[N][i] <= cap) ret = i;
  }

  return ret;
}
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
#line 7 "test/aoj/DPL_1_F/main.test.cpp"

int main(){
  int N; std::cin >> N;
  int64_t W; std::cin >> W;

  auto [v, w] = input_tuple_vector<int64_t, int64_t>(N);
  
  auto ans = knapsack_small_value(N, W, w, v);
  
  std::cout << ans << std::endl;
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

