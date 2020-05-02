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


# :heavy_check_mark: 個数制限付き部分和問題

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2e380218d9fd214c2f91a8ade734af1c">Mylib/TypicalProblem/SubsetSumProblem</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

- `subset_sum_limited(N, K, a[N], m[N])`
	- Time complexity $O(NK)$

## Requirements

## Notes

## Problems

- [AOJ 2955 Two Colors Sort](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2955)

## References

- 蟻本第2版 P62~63


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2955/main.test.cpp.html">test/aoj/2955/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 個数制限付き部分和問題
 * @docs subset_sum_limited.md
 */
bool subset_sum_limited(int N, int K, const std::vector<int> &a, const std::vector<int> &m){
  std::vector<int> dp(K+1, -1);

  dp[0] = 0;
  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(dp[j] >= 0){
        dp[j] = m[i];
      }else if(j < a[i] or dp[j-a[i]] <= 0){
        dp[j] = -1;
      }else{
        dp[j] = dp[j-a[i]]-1;
      }
    }
  }

  return dp[K] >= 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/TypicalProblem/SubsetSumProblem/subset_sum_limited.cpp"
#include <vector>

/**
 * @title 個数制限付き部分和問題
 * @docs subset_sum_limited.md
 */
bool subset_sum_limited(int N, int K, const std::vector<int> &a, const std::vector<int> &m){
  std::vector<int> dp(K+1, -1);

  dp[0] = 0;
  for(int i = 0; i < N; ++i){
    for(int j = 0; j <= K; ++j){
      if(dp[j] >= 0){
        dp[j] = m[i];
      }else if(j < a[i] or dp[j-a[i]] <= 0){
        dp[j] = -1;
      }else{
        dp[j] = dp[j-a[i]]-1;
      }
    }
  }

  return dp[K] >= 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

