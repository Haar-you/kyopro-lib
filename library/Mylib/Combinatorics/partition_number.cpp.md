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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: K個以下への分割数の列挙

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/partition_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:25:30+09:00




## Operations

- `partition_number(int n, int k)`
	- $P(0,0)$ ~ $P(n,k)$を列挙する。
	- Time complexity $O(nk)$

## References

- [http://drken1215.hatenablog.com/entry/2018/01/16/222843](http://drken1215.hatenablog.com/entry/2018/01/16/222843)
- [https://mathtrain.jp/bunkatsu](https://mathtrain.jp/bunkatsu)


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_J/main.test.cpp.html">test/aoj/DPL_5_J/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title K個以下への分割数の列挙
 * @docs partition_number.md
 */
template <typename T>
auto partition_number(int n, int k){
  std::vector<std::vector<T>> dp(n+1, std::vector<T>(k+1));
  dp[0][0] = 1;

  for(int i = 0; i <= n; ++i){
    for(int j = 1; j <= k; ++j){
      if(i-j >= 0) dp[i][j] = dp[i][j-1] + dp[i-j][j];
      else dp[i][j] = dp[i][j-1];
    }
  }

  return dp;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/partition_number.cpp"
#include <vector>

/**
 * @title K個以下への分割数の列挙
 * @docs partition_number.md
 */
template <typename T>
auto partition_number(int n, int k){
  std::vector<std::vector<T>> dp(n+1, std::vector<T>(k+1));
  dp[0][0] = 1;

  for(int i = 0; i <= n; ++i){
    for(int j = 1; j <= k; ++j){
      if(i-j >= 0) dp[i][j] = dp[i][j-1] + dp[i-j][j];
      else dp[i][j] = dp[i][j-1];
    }
  }

  return dp;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

