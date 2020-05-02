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


# :heavy_check_mark: 掃き出し法

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4efd5e2a9807175bf43e4c1857b5bc52">Mylib/LinearAlgebra/GaussianElimination</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/1300/main.test.cpp.html">test/aoj/1300/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>

/**
 * @title 掃き出し法
 * @docs gaussian_elimination.md
 */
template <typename T> int gaussian_elimination(std::vector<std::vector<T>> &a){
  const int h = a.size();
  const int w = a[0].size();
  int rank = 0;
  
  for(int j = 0; j < w; ++j){
    int pivot = -1;
    
    for(int i = rank; i < h; ++i){
      if(a[i][j] != 0){
        pivot = i;
        break;
      }
    }

    if(pivot == -1) continue;

    std::swap(a[pivot], a[rank]);

    auto d = a[rank][j];
    for(int k = 0; k < w; ++k) a[rank][k] /= d;

    for(int i = 0; i < h; ++i){
      if(i == rank or a[i][j] == 0) continue;
      auto d = a[i][j];
      for(int k = 0; k < w; ++k){
        a[i][k] -= a[rank][k] * d;
      }
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
#line 2 "Mylib/LinearAlgebra/GaussianElimination/gaussian_elimination.cpp"
#include <vector>
#include <utility>

/**
 * @title 掃き出し法
 * @docs gaussian_elimination.md
 */
template <typename T> int gaussian_elimination(std::vector<std::vector<T>> &a){
  const int h = a.size();
  const int w = a[0].size();
  int rank = 0;
  
  for(int j = 0; j < w; ++j){
    int pivot = -1;
    
    for(int i = rank; i < h; ++i){
      if(a[i][j] != 0){
        pivot = i;
        break;
      }
    }

    if(pivot == -1) continue;

    std::swap(a[pivot], a[rank]);

    auto d = a[rank][j];
    for(int k = 0; k < w; ++k) a[rank][k] /= d;

    for(int i = 0; i < h; ++i){
      if(i == rank or a[i][j] == 0) continue;
      auto d = a[i][j];
      for(int k = 0; k < w; ++k){
        a[i][k] -= a[rank][k] * d;
      }
    }

    ++rank;
  }

  return rank;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

