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


# :x: Mylib/AlgebraicStructure/Monoid/product.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/product.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-12 08:15:26+09:00




## Required by

* :warning: <a href="../MonoidAction/multiply_product.cpp.html">Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp</a>
* :warning: <a href="../MonoidAction/multiply_sum.cpp.html">Mylib/AlgebraicStructure/MonoidAction/multiply_sum.cpp</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/3132/main.test.cpp.html">test/aoj/3132/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @docs product.md
 */
template <typename T>
struct ProductMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 1;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a * b;}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/product.cpp"

/**
 * @docs product.md
 */
template <typename T>
struct ProductMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return 1;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a * b;}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

