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


# :warning: Mylib/AlgebraicStructure/Monoid/pair.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/pair.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

/**
 * @docs pair.md
 */
template <typename Monoid1, typename Monoid2>
struct PairMonoid{
  using value_type = std::pair<typename Monoid1::value_type, typename Monoid2::value_type>;
  Monoid1 M1;
  Monoid2 M2;

  value_type id() const {
    return {M1.id(), M2id()};
  }

  value_type op(const value_type &a, const value_type &b) const {
    return {M1.op(a.first, b.first), M2.op(a.second, b.second)};
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/pair.cpp"
#include <utility>

/**
 * @docs pair.md
 */
template <typename Monoid1, typename Monoid2>
struct PairMonoid{
  using value_type = std::pair<typename Monoid1::value_type, typename Monoid2::value_type>;
  Monoid1 M1;
  Monoid2 M2;

  value_type id() const {
    return {M1.id(), M2id()};
  }

  value_type op(const value_type &a, const value_type &b) const {
    return {M1.op(a.first, b.first), M2.op(a.second, b.second)};
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

