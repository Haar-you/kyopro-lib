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


# :warning: 最小個数部分和問題

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2e380218d9fd214c2f91a8ade734af1c">Mylib/TypicalProblem/SubsetSumProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/SubsetSumProblem/subset_sum_minimum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

- `subset_sum_minimum(N, K, a[N])`
	-  和が`K`になる部分集合の最小サイズ。そのような部分集合が存在しないとき-1を返す。
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
#include <algorithm>

/**
 * @title 最小個数部分和問題
 * @docs subset_sum_minimum.md
 */
int64_t subset_sum_minimum(int N, int K, const std::vector<int> &a){
  std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(K+1, INT_MAX));

  dp[0][0] = 0;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(j >= a[i]) dp[(i+1)&1][j] = std::min(dp[i&1][j-a[i]]+1, dp[i&1][j]);
      else dp[(i+1)&1][j] = dp[i&1][j];
    }
  }

  return dp[N&1][K] == INT_MAX ? -1 : dp[N&1][K];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_minimum.cpp"
#include <vector>
#include <algorithm>

/**
 * @title 最小個数部分和問題
 * @docs subset_sum_minimum.md
 */
int64_t subset_sum_minimum(int N, int K, const std::vector<int> &a){
  std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(K+1, INT_MAX));

  dp[0][0] = 0;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(j >= a[i]) dp[(i+1)&1][j] = std::min(dp[i&1][j-a[i]]+1, dp[i&1][j]);
      else dp[(i+1)&1][j] = dp[i&1][j];
    }
  }

  return dp[N&1][K] == INT_MAX ? -1 : dp[N&1][K];
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

