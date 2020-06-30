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


# :warning: Mylib/AlgebraicStructure/MonoidAction/multiply_sum.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7bd9a37defae28fe1746a7ffe2a62491">Mylib/AlgebraicStructure/MonoidAction</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/MonoidAction/multiply_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-28 03:01:30+09:00




## Depends on

* :heavy_check_mark: <a href="../Monoid/product.cpp.html">Mylib/AlgebraicStructure/Monoid/product.cpp</a>
* :question: <a href="../Monoid/sum.cpp.html">Mylib/AlgebraicStructure/Monoid/sum.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/Monoid/product.cpp"

/**
 * @docs multiply_sum.md
 */
template <typename T, typename U>
struct MultiplySum{
  using monoid_get = SumMonoid<T>;
  using monoid_update = ProductMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  static value_type_get id_get(){return monoid_get::id();}
  static value_type_update id_update(){return monoid_update::id();}

  static value_type_get op_get(value_type_get a, value_type_get b){return monoid_get::op(a, b);}
  static value_type_update op_update(value_type_update a, value_type_update b){return monoid_update::op(a, b);}

  static value_type_get op(value_type_get &a, value_type_update &b, int len){
    return a * b;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @docs sum.md
 */
template <typename T>
struct SumMonoid{
  using value_type = T;
  static value_type id(){return 0;}
  static value_type op(value_type a, value_type b){return a + b;}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/product.cpp"

/**
 * @docs product.md
 */
template <typename T>
struct ProductMonoid{
  using value_type = T;
  static value_type id(){return 1;}
  static value_type op(value_type a, value_type b){return a * b;}
};
#line 4 "Mylib/AlgebraicStructure/MonoidAction/multiply_sum.cpp"

/**
 * @docs multiply_sum.md
 */
template <typename T, typename U>
struct MultiplySum{
  using monoid_get = SumMonoid<T>;
  using monoid_update = ProductMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  static value_type_get id_get(){return monoid_get::id();}
  static value_type_update id_update(){return monoid_update::id();}

  static value_type_get op_get(value_type_get a, value_type_get b){return monoid_get::op(a, b);}
  static value_type_update op_update(value_type_update a, value_type_update b){return monoid_update::op(a, b);}

  static value_type_get op(value_type_get &a, value_type_update &b, int len){
    return a * b;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

