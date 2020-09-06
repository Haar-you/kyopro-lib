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


# :x: 0-1 Knapsack problem (Small value)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4bc951e5ca9130b2259fc85dc53eb972">Mylib/TypicalProblem/KnapsackProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/KnapsackProblem/knapsack_small_value.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Operations

- `knapsack_small_value(int N, Weight cap, Weight w[N], Value v[N])`
	- 0-1ナップサック問題を解く。
	- Time complexity $O(N \sum v)$

## Requirements

## Problems

- [EDPC E - Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e)

## References



## Verified with

* :x: <a href="../../../../verify/test/aoj/DPL_1_F/main.test.cpp.html">test/aoj/DPL_1_F/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

/**
 * @title 0-1 Knapsack problem (Small value)
 * @docs knapsack_small_value.md
 */
template <typename Weight, typename Value>
Value knapsack_small_value(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
  const Value MAX_V = std::accumulate(v.begin(), v.end(), 0);
  std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(MAX_V + 1, LLONG_MAX));

  dp[0][0] = 0;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= MAX_V; ++j){
      dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
      if(j + v[i] <= MAX_V and dp[i][j] < LLONG_MAX){
        dp[i + 1][j + v[i]] = std::min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
      }
    }
  }

  Value ret = 0;

  for(int i = 0; i <= MAX_V; ++i){
    if(dp[N][i] <= cap) ret = i;
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/KnapsackProblem/knapsack_small_value.cpp"
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

/**
 * @title 0-1 Knapsack problem (Small value)
 * @docs knapsack_small_value.md
 */
template <typename Weight, typename Value>
Value knapsack_small_value(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v){
  const Value MAX_V = std::accumulate(v.begin(), v.end(), 0);
  std::vector<std::vector<Value>> dp(N + 1, std::vector<Value>(MAX_V + 1, LLONG_MAX));

  dp[0][0] = 0;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= MAX_V; ++j){
      dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
      if(j + v[i] <= MAX_V and dp[i][j] < LLONG_MAX){
        dp[i + 1][j + v[i]] = std::min(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
      }
    }
  }

  Value ret = 0;

  for(int i = 0; i <= MAX_V; ++i){
    if(dp[N][i] <= cap) ret = i;
  }

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

