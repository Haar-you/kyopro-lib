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


# :warning: Binary exponentiation

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/power.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <functional>

/**
 * @title Binary exponentiation
 * @docs power.md
 */
template <typename T>
T power(T n, int64_t p, const T &e, const std::function<T(T,T)> &f){
  T ret = e;
  
  while(p > 0){
    if(p & 1) ret = f(ret, n);
    n = f(n, n);
    p >>= 1;
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/power.cpp"
#include <functional>

/**
 * @title Binary exponentiation
 * @docs power.md
 */
template <typename T>
T power(T n, int64_t p, const T &e, const std::function<T(T,T)> &f){
  T ret = e;
  
  while(p > 0){
    if(p & 1) ret = f(ret, n);
    n = f(n, n);
    p >>= 1;
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

