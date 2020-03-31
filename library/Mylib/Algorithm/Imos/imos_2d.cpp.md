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


# :heavy_check_mark: Mylib/Algorithm/Imos/imos_2d.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6dc6d5a2cac82b39a08fd9ff32ab6e48">Mylib/Algorithm/Imos</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/Imos/imos_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 11:59:58+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/DSL_5_B/main.test.cpp.html">test/aoj/DSL_5_B/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

template <typename T> struct Imos2D{
  std::vector<std::vector<T>> vec;
  int n, m;
  Imos2D(int n, int m): vec(n+1, std::vector<T>(m+1)), n(n), m(m){}

  void add(int a1, int b1, int a2, int b2){ // [a1,a2) [b1,b2)
    vec[a1][b1] += 1;
    vec[a2][b2] += 1;
    vec[a1][b2] -= 1;
    vec[a2][b1] -= 1;
  }

  void build(){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m+1; ++j){
        vec[i+1][j] += vec[i][j];
      }
    }

    for(int i = 0; i < n+1; ++i){
      for(int j = 0; j < m; ++j){
        vec[i][j+1] += vec[i][j];
      }
    }
  }

  inline const std::vector<T>& operator[](size_t i) const {return vec[i];}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/Imos/imos_2d.cpp"
#include <vector>

template <typename T> struct Imos2D{
  std::vector<std::vector<T>> vec;
  int n, m;
  Imos2D(int n, int m): vec(n+1, std::vector<T>(m+1)), n(n), m(m){}

  void add(int a1, int b1, int a2, int b2){ // [a1,a2) [b1,b2)
    vec[a1][b1] += 1;
    vec[a2][b2] += 1;
    vec[a1][b2] -= 1;
    vec[a2][b1] -= 1;
  }

  void build(){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m+1; ++j){
        vec[i+1][j] += vec[i][j];
      }
    }

    for(int i = 0; i < n+1; ++i){
      for(int j = 0; j < m; ++j){
        vec[i][j+1] += vec[i][j];
      }
    }
  }

  inline const std::vector<T>& operator[](size_t i) const {return vec[i];}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

