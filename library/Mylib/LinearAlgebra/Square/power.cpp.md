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


# :x: Power of a matrix

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b58b3fdb1287502881e9117a37552614">Mylib/LinearAlgebra/Square</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/LinearAlgebra/Square/power.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/1327/main.test.cpp.html">test/aoj/1327/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/194/main.test.cpp.html">test/yukicoder/194/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>

/**
 * @title Power of a matrix
 * @docs power.md
 */
template <typename M>
M power(M a, uint64_t p){
  if(p == 0) return M::make_unit();
  if(p == 1) return a;

  M temp = power(a, p >> 1);
  auto ret = temp * temp;

  if(p & 1) ret *= a;

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/LinearAlgebra/Square/power.cpp"
#include <cstdint>

/**
 * @title Power of a matrix
 * @docs power.md
 */
template <typename M>
M power(M a, uint64_t p){
  if(p == 0) return M::make_unit();
  if(p == 1) return a;

  M temp = power(a, p >> 1);
  auto ret = temp * temp;

  if(p & 1) ret *= a;

  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

