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


# :heavy_check_mark: Levenshtein distance / Edit distance

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/levenshtein_distance.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_1_E/main.test.cpp.html">test/aoj/DPL_1_E/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Levenshtein distance / Edit distance
 * @docs levenshtein_distance.md
 */
template <typename Container, typename T = typename Container::value_type>
int levenshtein_distance(const Container &a, const Container &b){
  int n = a.size(), m = b.size();
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
  
  for(int i = 0; i <= n; ++i) dp[i][0] = i;
  for(int i = 0; i <= m; ++i) dp[0][i] = i;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      dp[i+1][j+1] = std::min(dp[i][j+1]+1, dp[i+1][j]+1);
      
      if(a[i] == b[j]){
        dp[i+1][j+1] = std::min(dp[i+1][j+1], dp[i][j]);
      }else{
        dp[i+1][j+1] = std::min(dp[i+1][j+1], dp[i][j]+1);
      }
    }
  }
  return dp[n][m];
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/levenshtein_distance.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Levenshtein distance / Edit distance
 * @docs levenshtein_distance.md
 */
template <typename Container, typename T = typename Container::value_type>
int levenshtein_distance(const Container &a, const Container &b){
  int n = a.size(), m = b.size();
  std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));
  
  for(int i = 0; i <= n; ++i) dp[i][0] = i;
  for(int i = 0; i <= m; ++i) dp[0][i] = i;

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      dp[i+1][j+1] = std::min(dp[i][j+1]+1, dp[i+1][j]+1);
      
      if(a[i] == b[j]){
        dp[i+1][j+1] = std::min(dp[i+1][j+1], dp[i][j]);
      }else{
        dp[i+1][j+1] = std::min(dp[i+1][j+1], dp[i][j]+1);
      }
    }
  }
  return dp[n][m];
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

