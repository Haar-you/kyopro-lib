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


# :warning: Gaussian elimination (Mod2)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4efd5e2a9807175bf43e4c1857b5bc52">Mylib/LinearAlgebra/GaussianElimination</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/GaussianElimination/binary_gaussian_elimination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

## Requirements

## Notes

## Problems

- [codeFlyer D - 数列 XOR](https://atcoder.jp/contests/bitflyer2018-final-open/tasks/bitflyer2018_final_d)
- [CSA Xor Closure](https://csacademy.com/contest/archive/task/xor-closure/)

## References



## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <bitset>
#include <utility>

/**
 * @title Gaussian elimination (Mod2)
 * @docs binary_gaussian_elimination.md
 */
template <size_t N> int gaussian_elimination(std::vector<std::bitset<N>> &m){
  int n = m.size();
  int rank = 0;

  for(int j = 0; j < N; ++j){
    int pivot = -1;

    for(int i = rank; i < n; ++i){
      if(m[i][j]){
        pivot = i;
        break;
      }
    }

    if(pivot == -1) continue;

    std::swap(m[pivot], m[rank]);

    for(int i = 0; i < n; ++i){
      if(i != rank and m[i][j]) m[i] ^= m[rank];
    }
    ++rank;
  }
  
  return rank;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/GaussianElimination/binary_gaussian_elimination.cpp"
#include <vector>
#include <bitset>
#include <utility>

/**
 * @title Gaussian elimination (Mod2)
 * @docs binary_gaussian_elimination.md
 */
template <size_t N> int gaussian_elimination(std::vector<std::bitset<N>> &m){
  int n = m.size();
  int rank = 0;

  for(int j = 0; j < N; ++j){
    int pivot = -1;

    for(int i = rank; i < n; ++i){
      if(m[i][j]){
        pivot = i;
        break;
      }
    }

    if(pivot == -1) continue;

    std::swap(m[pivot], m[rank]);

    for(int i = 0; i < n; ++i){
      if(i != rank and m[i][j]) m[i] ^= m[rank];
    }
    ++rank;
  }
  
  return rank;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

