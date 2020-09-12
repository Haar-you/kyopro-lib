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


# :x: Primality test (Trial division)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/is_prime.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/ALDS1_1_C/main.test.cpp.html">test/aoj/ALDS1_1_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Primality test (Trial division)
 * @docs is_prime.md
 */
namespace haar_lib {
  bool is_prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; ++i){
      if(n % i == 0) return false;
    }
    return true;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/is_prime.cpp"

/**
 * @title Primality test (Trial division)
 * @docs is_prime.md
 */
namespace haar_lib {
  bool is_prime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; ++i){
      if(n % i == 0) return false;
    }
    return true;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

