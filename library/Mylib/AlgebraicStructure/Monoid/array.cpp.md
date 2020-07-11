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


# :warning: Mylib/AlgebraicStructure/Monoid/array.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <array>

/**
 * @docs array.md
 */
template <typename Monoid, int B>
struct ArrayMonoid{
  using value_type = std::array<typename Monoid::value_type, B>;
  Monoid M;

  value_type id() const {
    value_type ret;
    ret.fill(M.id());
    return ret;
  }

  value_type op(const value_type &a, const value_type &b) const {
    value_type ret;
    for(int i = 0; i < B; ++i) ret[i] = M.op(a[i], b[i]);
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/array.cpp"
#include <array>

/**
 * @docs array.md
 */
template <typename Monoid, int B>
struct ArrayMonoid{
  using value_type = std::array<typename Monoid::value_type, B>;
  Monoid M;

  value_type id() const {
    value_type ret;
    ret.fill(M.id());
    return ret;
  }

  value_type op(const value_type &a, const value_type &b) const {
    value_type ret;
    for(int i = 0; i < B; ++i) ret[i] = M.op(a[i], b[i]);
    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

