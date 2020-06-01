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


# :warning: Binomial coefficients table

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/binomial_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `binomial_table(int n, int k)`
	- $\binom{0}{0}$ ~ $\binom{n}{k}$を列挙する。
	- Time complexity $O(nk)$


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Binomial coefficients table
 * @docs binomial_table.md
 */
template <typename T>
auto binomial_table(int n, int k){
  std::vector<std::vector<T>> ret(n+1, std::vector<T>(k+1));
  ret[0][0] = 1;
  
  for(int i = 1; i <= n; ++i){
    ret[i][0] = 1;
    
    for(int j = 1; j <= k; ++j){
      ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/binomial_table.cpp"
#include <vector>

/**
 * @title Binomial coefficients table
 * @docs binomial_table.md
 */
template <typename T>
auto binomial_table(int n, int k){
  std::vector<std::vector<T>> ret(n+1, std::vector<T>(k+1));
  ret[0][0] = 1;
  
  for(int i = 1; i <= n; ++i){
    ret[i][0] = 1;
    
    for(int j = 1; j <= k; ++j){
      ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

