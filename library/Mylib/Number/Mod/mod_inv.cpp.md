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


# :heavy_check_mark: Mod inverse

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#795ab137908c82fc28acbcffe5b1c757">Mylib/Number/Mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Mod/mod_inv.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `mod_inv(a, m)`
	- $ax = 1 \pmod m$を満たす`x`を求める。
	- $gcd(a,  m) = 1$を満たさなければならない。
	- Time complexity $O(\log N)$

## Requirements

## Notes

## Problems

## References


## Required by

* :heavy_check_mark: <a href="mod_log.cpp.html">Mod logarithm</a>
* :warning: <a href="../garner.cpp.html">Garner algorithm</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/discrete_logarithm_mod/main.test.cpp.html">test/yosupo-judge/discrete_logarithm_mod/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

/**
 * @title Mod inverse
 * @docs mod_inv.md
 */
int64_t mod_inv(int64_t a, int64_t m){
  int64_t b = m, u = 1, v = 0;

  while(b){
    int64_t t = a / b;
    a -= t * b; std::swap(a, b);
    u -= t * v; std::swap(u, v);
  }

  u %= m;
  if(u < 0) u += m;

  return u;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Mod/mod_inv.cpp"
#include <utility>

/**
 * @title Mod inverse
 * @docs mod_inv.md
 */
int64_t mod_inv(int64_t a, int64_t m){
  int64_t b = m, u = 1, v = 0;

  while(b){
    int64_t t = a / b;
    a -= t * b; std::swap(a, b);
    u -= t * v; std::swap(u, v);
  }

  u %= m;
  if(u < 0) u += m;

  return u;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

