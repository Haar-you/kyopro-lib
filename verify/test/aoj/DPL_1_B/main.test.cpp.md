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


# :x: test/aoj/DPL_1_B/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#06e75b3853179fe775851b53e9e59b30">test/aoj/DPL_1_B</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DPL_1_B/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B</a>


## Depends on

* :question: <a href="../../../../library/Mylib/IO/input_tuple_vector.cpp.html">Mylib/IO/input_tuple_vector.cpp</a>
* :x: <a href="../../../../library/Mylib/TypicalProblem/KnapsackProblem/knapsack_small_weight.cpp.html">0-1 Knapsack problem (Small weight)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_weight.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

int main(){
  int N, W; std::cin >> N >> W;

  auto [v, w] = hl::input_tuple_vector<int, int>(N);

  auto ans = hl::knapsack_small_weight(N, W, w, v);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DPL_1_B/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B"

#include <iostream>
#include <vector>
#line 3 "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_weight.cpp"
#include <algorithm>

/**
 * @title 0-1 Knapsack problem (Small weight)
 * @docs knapsack_small_weight.md
 */
namespace haar_lib {
  template <typename Weight, typename Value>
  Value knapsack_small_weight(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
    std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(cap + 1));

    for(int i = 0; i < N; ++i){
      for(int j = 0; j <= cap; ++j){
        dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
        if(j + w[i] <= cap) dp[i + 1][j + w[i]] = std::max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
      }
    }

    return dp[N][cap];
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
#line 7 "test/aoj/DPL_1_B/main.test.cpp"

namespace hl = haar_lib;

int main(){
  int N, W; std::cin >> N >> W;

  auto [v, w] = hl::input_tuple_vector<int, int>(N);

  auto ans = hl::knapsack_small_weight(N, W, w, v);
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

