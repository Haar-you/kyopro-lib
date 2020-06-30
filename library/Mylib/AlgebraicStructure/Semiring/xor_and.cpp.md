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


# :warning: Mylib/AlgebraicStructure/Semiring/xor_and.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3df95940e092844fc072dd50b6844b29">Mylib/AlgebraicStructure/Semiring</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Semiring/xor_and.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-28 03:01:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @docs xor_and.md
 */
template <typename T>
struct XorAndSemiring{
  using value_type = T;
  static value_type id_add(){return 0;}
  static value_type id_mul(){return ~(T)0;}
  static value_type add(value_type a, value_type b){return a ^ b;}
  static value_type mul(value_type a, value_type b){return a & b;}
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Semiring/xor_and.cpp"

/**
 * @docs xor_and.md
 */
template <typename T>
struct XorAndSemiring{
  using value_type = T;
  static value_type id_add(){return 0;}
  static value_type id_mul(){return ~(T)0;}
  static value_type add(value_type a, value_type b){return a ^ b;}
  static value_type mul(value_type a, value_type b){return a & b;}
};


```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

