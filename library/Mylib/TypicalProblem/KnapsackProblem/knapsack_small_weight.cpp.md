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


# :x: 0-1 Knapsack problem (Small weight)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4bc951e5ca9130b2259fc85dc53eb972">Mylib/TypicalProblem/KnapsackProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/KnapsackProblem/knapsack_small_weight.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Operations

- `knapsack_small_weight(int N, Weight cap, Weight w[N], Value v[N])`
	- 0-1ナップサック問題を解く。
	- Time complexity $O(N * cap)$

## Requirements

## Problems

- [EDPC D - Knapsack 1](https://atcoder.jp/contests/dp/tasks/dp_d)

## References


## Verified with

* :x: <a href="../../../../verify/test/aoj/DPL_1_B/main.test.cpp.html">test/aoj/DPL_1_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_weight.cpp"
#include <vector>
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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

