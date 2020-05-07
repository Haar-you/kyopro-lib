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


# :warning: 部分和数え上げ問題

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2e380218d9fd214c2f91a8ade734af1c">Mylib/TypicalProblem/SubsetSumProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/SubsetSumProblem/subset_sum_count.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

- `subset_sum_count(N, K, a[N])`
	- Time complexity $O(NK)$

## Requirements

## Notes

## Problems

## References



## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 部分和数え上げ問題
 * @docs subset_sum_count.md
 */
template <typename T>
T subset_sum_count(int N, int K, const std::vector<int> &a){
  std::vector<std::vector<T>> dp(2, std::vector<T>(K+1));

  dp[0][0] = 1;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(j >= a[i]) dp[(i+1)&1][j] = dp[i&1][j-a[i]] + dp[i&1][j];
      else dp[(i+1)&1][j] = dp[i&1][j];
    }
  }

  return dp[N&1][K];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_count.cpp"
#include <vector>

/**
 * @title 部分和数え上げ問題
 * @docs subset_sum_count.md
 */
template <typename T>
T subset_sum_count(int N, int K, const std::vector<int> &a){
  std::vector<std::vector<T>> dp(2, std::vector<T>(K+1));

  dp[0][0] = 1;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(j >= a[i]) dp[(i+1)&1][j] = dp[i&1][j-a[i]] + dp[i&1][j];
      else dp[(i+1)&1][j] = dp[i&1][j];
    }
  }

  return dp[N&1][K];
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
