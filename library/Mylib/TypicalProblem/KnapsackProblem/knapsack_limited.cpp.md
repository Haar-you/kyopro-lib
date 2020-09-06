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


# :x: Knapsack problem (With quantity limitations)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4bc951e5ca9130b2259fc85dc53eb972">Mylib/TypicalProblem/KnapsackProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/KnapsackProblem/knapsack_limited.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00




## Operations

- `knapsack_limited(int N, Weight cap, Weight w[N], Value v[N], int m[N])`
	- 個数制限ナップサック問題を解く。
	- Time complexity $O(N cap \log \max m)$

## Requirements

## Problems

- [AOJ DPL_1_G Knapsack Problem with Limitations](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G)

## References



## Verified with

* :x: <a href="../../../../verify/test/aoj/DPL_1_G/main.test.cpp.html">test/aoj/DPL_1_G/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Knapsack problem (With quantity limitations)
 * @docs knapsack_limited.md
 */
template <typename Weight, typename Value>
Value knapsack_limited(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v, const std::vector<int> &m){
  std::vector<Value> dp(cap + 1);

  for(int i = 0; i < N; ++i){
    for(int64_t a = 1, x = m[i], k; k = std::min(x, a), x > 0; x -= k, a *= 2){
      for(int j = cap; j >= 0; --j){
        if(j - k * w[i] >= 0){
          dp[j] = std::max(dp[j], dp[j - k * w[i]] + (Weight)k * v[i]);
        }
      }
    }
  }

  return dp[cap];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/KnapsackProblem/knapsack_limited.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Knapsack problem (With quantity limitations)
 * @docs knapsack_limited.md
 */
template <typename Weight, typename Value>
Value knapsack_limited(int N, Weight cap, const std::vector<Weight> &w, const std::vector<Value> &v, const std::vector<int> &m){
  std::vector<Value> dp(cap + 1);

  for(int i = 0; i < N; ++i){
    for(int64_t a = 1, x = m[i], k; k = std::min(x, a), x > 0; x -= k, a *= 2){
      for(int j = cap; j >= 0; --j){
        if(j - k * w[i] >= 0){
          dp[j] = std::max(dp[j], dp[j - k * w[i]] + (Weight)k * v[i]);
        }
      }
    }
  }

  return dp[cap];
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

