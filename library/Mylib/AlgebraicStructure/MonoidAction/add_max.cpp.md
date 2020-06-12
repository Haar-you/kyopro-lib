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


# :x: Mylib/AlgebraicStructure/MonoidAction/add_max.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7bd9a37defae28fe1746a7ffe2a62491">Mylib/AlgebraicStructure/MonoidAction</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/MonoidAction/add_max.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 19:38:51+09:00




## Depends on

* :x: <a href="../Monoid/max.cpp.html">Mylib/AlgebraicStructure/Monoid/max.cpp</a>
* :question: <a href="../Monoid/sum.cpp.html">Mylib/AlgebraicStructure/Monoid/sum.cpp</a>


## Verified with

* :x: <a href="../../../../verify/test/yukicoder/631/main.test.cpp.html">test/yukicoder/631/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/Monoid/max.cpp"

/**
 * @docs add_max.md
 */
template <typename T, typename U>
struct AddMax{
  using monoid_get = MaxMonoid<T>;
  using monoid_update = SumMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    if(a) return {*a + b};
    return {};
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
  constexpr inline static value_type id(){return 0;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return a + b;}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/max.cpp"
#include <algorithm>
#include <optional>

/**
 * @docs max.md
 */
template <typename T>
struct MaxMonoid{
  using value_type = std::optional<T>;
  
  static value_type id(){return {};}
  static value_type op(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;
    return {std::max(*a, *b)};
  }
};
#line 4 "Mylib/AlgebraicStructure/MonoidAction/add_max.cpp"

/**
 * @docs add_max.md
 */
template <typename T, typename U>
struct AddMax{
  using monoid_get = MaxMonoid<T>;
  using monoid_update = SumMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int len){
    if(a) return {*a + b};
    return {};
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
