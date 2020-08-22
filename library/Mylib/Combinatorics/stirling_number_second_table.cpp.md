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


# :heavy_check_mark: Stirling numbers of the second kind (Table)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/stirling_number_second_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-21 11:48:40+09:00




## Operations

- `stirling_number_table(int n)`
	- $S(0,0)$ ~ $S(n,n)$を列挙する。
	- Time complexity $O(n^2)$


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_I/main.table.test.cpp.html">test/aoj/DPL_5_I/main.table.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Stirling numbers of the second kind (Table)
 * @docs stirling_number_second_table.md 
 */
template <typename T>
auto stirling_number_table(int n){
  std::vector<std::vector<T>> ret(n+1, std::vector<T>(n+1));

  ret[0][0] = 1;

  for(int i = 1; i <= n; ++i) ret[i][1] = ret[i][i] = 1;

  for(int i = 3; i <= n; ++i){
    for(int j = 2; j < i; ++j){
      ret[i][j] = ret[i-1][j-1] + j * ret[i-1][j];
    }
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/stirling_number_second_table.cpp"
#include <vector>

/**
 * @title Stirling numbers of the second kind (Table)
 * @docs stirling_number_second_table.md 
 */
template <typename T>
auto stirling_number_table(int n){
  std::vector<std::vector<T>> ret(n+1, std::vector<T>(n+1));

  ret[0][0] = 1;

  for(int i = 1; i <= n; ++i) ret[i][1] = ret[i][i] = 1;

  for(int i = 3; i <= n; ++i){
    for(int j = 2; j < i; ++j){
      ret[i][j] = ret[i-1][j-1] + j * ret[i-1][j];
    }
  }

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

