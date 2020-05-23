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


# :heavy_check_mark: Mylib/AlgebraicStructure/MonoidAction/update_min.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7bd9a37defae28fe1746a7ffe2a62491">Mylib/AlgebraicStructure/MonoidAction</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/MonoidAction/update_min.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-12 08:15:26+09:00




## Depends on

* :heavy_check_mark: <a href="../Monoid/min.cpp.html">Mylib/AlgebraicStructure/Monoid/min.cpp</a>
* :question: <a href="../Monoid/update.cpp.html">Mylib/AlgebraicStructure/Monoid/update.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/DSL_2_F/main.test.cpp.html">test/aoj/DSL_2_F/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/AlgebraicStructure/Monoid/update.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"

/**
 * @docs update_min.md
 */
template <typename T, typename U>
struct UpdateMin{
  using monoid_get = MinMonoid<T>;
  using monoid_update = UpdateMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int){
    return b ? *b : a;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/update.cpp"
#include <optional>

/**
 * @docs update.md
 */
template <typename T>
struct UpdateMonoid{
  using value_type = std::optional<T>;
  constexpr inline static value_type id(){return std::nullopt;}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return (a ? a : b);}
};
#line 2 "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include <algorithm>

/**
 * @docs min.md
 */
template <typename T>
struct MinMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return std::numeric_limits<T>::max();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::min(a, b);}
};
#line 4 "Mylib/AlgebraicStructure/MonoidAction/update_min.cpp"

/**
 * @docs update_min.md
 */
template <typename T, typename U>
struct UpdateMin{
  using monoid_get = MinMonoid<T>;
  using monoid_update = UpdateMonoid<U>;
  using value_type_get = typename monoid_get::value_type;
  using value_type_update = typename monoid_update::value_type;

  constexpr inline static value_type_get op(const value_type_get &a, const value_type_update &b, int){
    return b ? *b : a;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

