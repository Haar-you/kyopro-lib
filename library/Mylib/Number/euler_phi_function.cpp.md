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


# :x: Eulerのトーシェント関数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/euler_phi_function.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/NTL_1_D/main.totient.test.cpp.html">test/aoj/NTL_1_D/main.totient.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Eulerのトーシェント関数
 * @docs euler_phi_function.md
 */
int64_t totient(int64_t n){
  int64_t ret = n;

  for(int64_t i = 2; i * i <= n; ++i){
    if(n % i == 0){
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }

  if(n != 1) ret -= ret / n;

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/euler_phi_function.cpp"

/**
 * @title Eulerのトーシェント関数
 * @docs euler_phi_function.md
 */
int64_t totient(int64_t n){
  int64_t ret = n;

  for(int64_t i = 2; i * i <= n; ++i){
    if(n % i == 0){
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }

  if(n != 1) ret -= ret / n;

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

