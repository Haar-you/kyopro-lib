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


# :heavy_check_mark: 最長共通部分列

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3a96c66483797c15eff4c0c3d8733619">Mylib/DynamicProgramming</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DynamicProgramming/longest_common_subsequence.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

- `lcs(a[N], b[M])`
	- `a`と`b`の最長共通部分列の長さを返す。
	- Time complexity $O(NM)$

## Requirements

## Notes

## Problems

## References
 


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_10_C/main.test.cpp.html">test/aoj/ALDS1_10_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 最長共通部分列
 * @docs longest_common_subsequence.md
 */
template <typename Container, typename T = typename Container::value_type>
int lcs(const Container &a, const Container &b){
  const int n = a.size(), m = b.size();
  
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : std::max(dp[i-1][j], dp[i][j-1]);
    }
  }
    
  return dp[n][m];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DynamicProgramming/longest_common_subsequence.cpp"
#include <vector>
#include <algorithm>

/**
 * @title 最長共通部分列
 * @docs longest_common_subsequence.md
 */
template <typename Container, typename T = typename Container::value_type>
int lcs(const Container &a, const Container &b){
  const int n = a.size(), m = b.size();
  
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : std::max(dp[i-1][j], dp[i][j-1]);
    }
  }
    
  return dp[n][m];
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

