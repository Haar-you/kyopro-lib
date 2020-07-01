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


# :heavy_check_mark: Inverse matrix

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b58b3fdb1287502881e9117a37552614">Mylib/LinearAlgebra/Square</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/Square/inverse_matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yukicoder/194/main.test.cpp.html">test/yukicoder/194/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

/**
 * @title Inverse matrix
 * @docs inverse_matrix.md
 */
template <typename M, typename T = typename M::value_type>
bool inverse_matrix(M m, M &ret){
  const int N = m.size();

  ret = M::make_unit();

  for(int i = 0; i < N; ++i){
    int p = i;
    for(int j = i; j < N; ++j){
      if(m[i][j] != 0){
        p = j;
        break;
      }
    }

    std::swap(m[i], m[p]);
    std::swap(ret[i], ret[p]);
    
    {
      T d = m[i][i];

      if(d == 0) return false;
    
      for(int j = 0; j < N; ++j){
        m[i][j] /= d;
        ret[i][j] /= d;
      }
    }
    
    for(int j = 0; j < N; ++j){
      if(i == j) continue;
      T d = m[j][i] / m[i][i];
      for(int k = 0; k < N; ++k){
        m[j][k] -= m[i][k] * d;
        ret[j][k] -= ret[i][k] * d;
      }
    }
  }

  return true;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/Square/inverse_matrix.cpp"
#include <utility>

/**
 * @title Inverse matrix
 * @docs inverse_matrix.md
 */
template <typename M, typename T = typename M::value_type>
bool inverse_matrix(M m, M &ret){
  const int N = m.size();

  ret = M::make_unit();

  for(int i = 0; i < N; ++i){
    int p = i;
    for(int j = i; j < N; ++j){
      if(m[i][j] != 0){
        p = j;
        break;
      }
    }

    std::swap(m[i], m[p]);
    std::swap(ret[i], ret[p]);
    
    {
      T d = m[i][i];

      if(d == 0) return false;
    
      for(int j = 0; j < N; ++j){
        m[i][j] /= d;
        ret[i][j] /= d;
      }
    }
    
    for(int j = 0; j < N; ++j){
      if(i == j) continue;
      T d = m[j][i] / m[i][i];
      for(int k = 0; k < N; ++k){
        m[j][k] -= m[i][k] * d;
        ret[j][k] -= ret[i][k] * d;
      }
    }
  }

  return true;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

