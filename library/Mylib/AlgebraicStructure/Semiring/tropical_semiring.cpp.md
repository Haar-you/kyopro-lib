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


# :warning: Mylib/AlgebraicStructure/Semiring/tropical_semiring.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#3df95940e092844fc072dd50b6844b29">Mylib/AlgebraicStructure/Semiring</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Semiring/tropical_semiring.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 08:05:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <optional>
#include <algorithm>

template <typename T>
struct TropicalSemiring{
  using value_type = std::optional<T>;

  constexpr inline static value_type id_add(){return std::nullopt;}
  constexpr inline static value_type id_mul(){return 0;}

  constexpr inline static value_type add(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;
    return {std::min(*a, *b)};
  }
  constexpr inline static value_type mul(const value_type &a, const value_type &b){
    if(not a or not b) return {};
    return {*a + *b};
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Semiring/tropical_semiring.cpp"
#include <optional>
#include <algorithm>

template <typename T>
struct TropicalSemiring{
  using value_type = std::optional<T>;

  constexpr inline static value_type id_add(){return std::nullopt;}
  constexpr inline static value_type id_mul(){return 0;}

  constexpr inline static value_type add(const value_type &a, const value_type &b){
    if(not a) return b;
    if(not b) return a;
    return {std::min(*a, *b)};
  }
  constexpr inline static value_type mul(const value_type &a, const value_type &b){
    if(not a or not b) return {};
    return {*a + *b};
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
