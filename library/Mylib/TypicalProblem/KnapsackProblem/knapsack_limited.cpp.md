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


# :heavy_check_mark: 個数制限付きナップサック問題

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4bc951e5ca9130b2259fc85dc53eb972">Mylib/TypicalProblem/KnapsackProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/KnapsackProblem/knapsack_limited.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 08:41:26+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/DPL_1_G/main.test.cpp.html">test/aoj/DPL_1_G/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 個数制限付きナップサック問題
 * @attention 時間計算量 O(NWlog(MaxM))
 */
template <typename Weight, typename Value>
Value knapsack_limited(int N, Weight W, const std::vector<Weight> &w, const std::vector<Value> &v, const std::vector<int> &m){
  std::vector<Value> dp(W+1);

  for(int i = 0; i < N; ++i){
    for(int64_t a = 1, x = m[i], k; k = std::min(x,a), x > 0; x -= k, a *= 2){
      for(int j = W; j >= 0; --j){
        if(j-k*w[i] >= 0){
          dp[j] = std::max(dp[j], dp[j-k*w[i]] + (Weight)k*v[i]);
        }
      }
    }
  }

  return dp[W];
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
 * @title 個数制限付きナップサック問題
 * @attention 時間計算量 O(NWlog(MaxM))
 */
template <typename Weight, typename Value>
Value knapsack_limited(int N, Weight W, const std::vector<Weight> &w, const std::vector<Value> &v, const std::vector<int> &m){
  std::vector<Value> dp(W+1);

  for(int i = 0; i < N; ++i){
    for(int64_t a = 1, x = m[i], k; k = std::min(x,a), x > 0; x -= k, a *= 2){
      for(int j = W; j >= 0; --j){
        if(j-k*w[i] >= 0){
          dp[j] = std::max(dp[j], dp[j-k*w[i]] + (Weight)k*v[i]);
        }
      }
    }
  }

  return dp[W];
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

