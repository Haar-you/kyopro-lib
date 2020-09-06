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


# :x: Extended Euclidean algorithm

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/extended_gcd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Required by

* :x: <a href="chinese_remainder_algorithm.cpp.html">Chinese remainder theorem</a>


## Verified with

* :x: <a href="../../../verify/test/aoj/NTL_1_E/main.test.cpp.html">test/aoj/NTL_1_E/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/186/main.test.cpp.html">test/yukicoder/186/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <tuple>

/**
 * @title Extended Euclidean algorithm
 * @docs extended_gcd.md
 */
std::tuple<int64_t, int64_t, int64_t> ext_gcd(int64_t a, int64_t b){
  if(b == 0) return std::make_tuple(a, 1, 0);
  int64_t d, p, q;
  std::tie(d, q, p) = ext_gcd(b, (a + b) % b);
  return std::make_tuple(d, p, q - a / b * p);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/extended_gcd.cpp"
#include <tuple>

/**
 * @title Extended Euclidean algorithm
 * @docs extended_gcd.md
 */
std::tuple<int64_t, int64_t, int64_t> ext_gcd(int64_t a, int64_t b){
  if(b == 0) return std::make_tuple(a, 1, 0);
  int64_t d, p, q;
  std::tie(d, q, p) = ext_gcd(b, (a + b) % b);
  return std::make_tuple(d, p, q - a / b * p);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

