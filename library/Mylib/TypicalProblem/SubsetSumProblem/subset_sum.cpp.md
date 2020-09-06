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


# :warning: Subset sum problem

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2e380218d9fd214c2f91a8ade734af1c">Mylib/TypicalProblem/SubsetSumProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/SubsetSumProblem/subset_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Operations

- `subset_sum(N, K, a[N])`
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
 * @title Subset sum problem
 * @docs subset_sum.md
 */
auto subset_sum(int N, int K, const std::vector<int> &a){
  std::vector<std::vector<bool>> dp(2, std::vector<bool>(K + 1));

  dp[0][0] = true;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(j >= a[i]) dp[(i + 1) & 1][j] = dp[i & 1][j - a[i]] or dp[i & 1][j];
      else dp[(i + 1) & 1][j] = dp[i & 1][j];
    }
  }

  return dp[N & 1];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/SubsetSumProblem/subset_sum.cpp"
#include <vector>

/**
 * @title Subset sum problem
 * @docs subset_sum.md
 */
auto subset_sum(int N, int K, const std::vector<int> &a){
  std::vector<std::vector<bool>> dp(2, std::vector<bool>(K + 1));

  dp[0][0] = true;

  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(j >= a[i]) dp[(i + 1) & 1][j] = dp[i & 1][j - a[i]] or dp[i & 1][j];
      else dp[(i + 1) & 1][j] = dp[i & 1][j];
    }
  }

  return dp[N & 1];
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

