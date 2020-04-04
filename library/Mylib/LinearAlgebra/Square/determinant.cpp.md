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


# :x: 行列式 (01)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b58b3fdb1287502881e9117a37552614">Mylib/LinearAlgebra/Square</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/Square/determinant.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 01:42:28+09:00




## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/matrix_det/main.test.cpp.html">test/yosupo-judge/matrix_det/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title 行列式
 */
template <typename M, typename T = typename M::value_type>
T determinant(M m){
  const int N = m.size();
  
  int s = 0;
  for(int i = 0; i < N; ++i){
    if(m[i][i] == 0){
      for(int j = i+1; j < N; ++j){
        if(m[j][i] != 0){
          m[i].swap(m[j]);
          (s += 1) %= 2;
          break;
        }
        if(j == N-1) return 0;
      }
    }
    
    for(int j = i+1; j < N; ++j){
      T t = m[j][i] / m[i][i];
      for(int k = 0; k < N; ++k) m[j][k] -= m[i][k] * t;
    }
  }
  
  T ret = s ? -1 : 1;
  for(int i = 0; i < N; ++i) ret *= m[i][i];
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/Square/determinant.cpp"

/**
 * @title 行列式
 */
template <typename M, typename T = typename M::value_type>
T determinant(M m){
  const int N = m.size();
  
  int s = 0;
  for(int i = 0; i < N; ++i){
    if(m[i][i] == 0){
      for(int j = i+1; j < N; ++j){
        if(m[j][i] != 0){
          m[i].swap(m[j]);
          (s += 1) %= 2;
          break;
        }
        if(j == N-1) return 0;
      }
    }
    
    for(int j = i+1; j < N; ++j){
      T t = m[j][i] / m[i][i];
      for(int k = 0; k < N; ++k) m[j][k] -= m[i][k] * t;
    }
  }
  
  T ret = s ? -1 : 1;
  for(int i = 0; i < N; ++i) ret *= m[i][i];
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

