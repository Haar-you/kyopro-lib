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


# :warning: Mylib/LinearAlgebra/determinant.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c3630e6b34f6bdce63eb71de0fb5bdd6">Mylib/LinearAlgebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/determinant.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 04:55:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

template <typename T> T determinant(std::vector<std::vector<T>> m){
  const int n = m.size();
  int s = 0;

  for(int i = 0; i < n; ++i){
    if(m[i][i] == 0){
      for(int j = i+1; j < n; ++j){
        if(m[j][i] != 0){
          m[i].swap(m[j]);
          (s += 1) %= 2;
          break; 
        }
        if(j == n-1) return 0;
      }
    }
    
    for(int j = i+1; j < n; ++j){
      T t = m[j][i] / m[i][i];
      for(int k = 0; k < n; ++k) m[j][k] -= m[i][k] * t;
    }
  }

  T ret = s ? -1 : 1;
  for(int i = 0; i < n; ++i) ret *= m[i][i];
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/determinant.cpp"
#include <vector>

template <typename T> T determinant(std::vector<std::vector<T>> m){
  const int n = m.size();
  int s = 0;

  for(int i = 0; i < n; ++i){
    if(m[i][i] == 0){
      for(int j = i+1; j < n; ++j){
        if(m[j][i] != 0){
          m[i].swap(m[j]);
          (s += 1) %= 2;
          break; 
        }
        if(j == n-1) return 0;
      }
    }
    
    for(int j = i+1; j < n; ++j){
      T t = m[j][i] / m[i][i];
      for(int k = 0; k < n; ++k) m[j][k] -= m[i][k] * t;
    }
  }

  T ret = s ? -1 : 1;
  for(int i = 0; i < n; ++i) ret *= m[i][i];
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

