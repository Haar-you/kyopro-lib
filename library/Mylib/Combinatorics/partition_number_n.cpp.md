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


# :x: Partition number (Enumerate $P(n, n)$)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/partition_number_n.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `partition_number(int n)`
	- $P(0)$ ~ $P(n)$を列挙する。
	- Time complexity $O(n\sqrt{n})$

## Problems

- [Partition Function](https://judge.yosupo.jp/problem/partition_function)


## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/partition_function/main.test.cpp.html">test/yosupo-judge/partition_function/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cmath>
#include <vector>

/**
 * @title Partition number (Enumerate $P(n, n)$)
 * @docs partition_number_n.md
 */
template <typename T>
auto partition_number(int N){
  std::vector<T> p(N+1);
  
  p[0] = 1;

  for(int i = 1; i <= N; ++i){
    int s = sqrt(1+24*i);

    for(int j = 1; j <= (1+s)/6; ++j){
      p[i] += p[i-j*(3*j-1)/2] * (j % 2 ? 1 : -1);
    }
    
    for(int j = 1; j <= (-1+s)/6; ++j){
      p[i] += p[i-j*(3*j+1)/2] * (j % 2 ? 1 : -1);
    }
  }

  return p;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/partition_number_n.cpp"
#include <cmath>
#include <vector>

/**
 * @title Partition number (Enumerate $P(n, n)$)
 * @docs partition_number_n.md
 */
template <typename T>
auto partition_number(int N){
  std::vector<T> p(N+1);
  
  p[0] = 1;

  for(int i = 1; i <= N; ++i){
    int s = sqrt(1+24*i);

    for(int j = 1; j <= (1+s)/6; ++j){
      p[i] += p[i-j*(3*j-1)/2] * (j % 2 ? 1 : -1);
    }
    
    for(int j = 1; j <= (-1+s)/6; ++j){
      p[i] += p[i-j*(3*j+1)/2] * (j % 2 ? 1 : -1);
    }
  }

  return p;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
