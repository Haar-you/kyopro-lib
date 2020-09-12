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


# :warning: Pair monoid

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/pair.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

/**
 * @title Pair monoid
 * @docs pair.md
 */
namespace haar_lib {
  template <typename Monoid1, typename Monoid2>
  struct pair_monoid {
    using value_type = std::pair<typename Monoid1::value_type, typename Monoid2::value_type>;
    const static Monoid1 M1;
    const static Monoid2 M2;

    value_type operator()() const {
      return {M1(), M2()};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      return {M1(a.first, b.first), M2(a.second, b.second)};
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/pair.cpp"
#include <utility>

/**
 * @title Pair monoid
 * @docs pair.md
 */
namespace haar_lib {
  template <typename Monoid1, typename Monoid2>
  struct pair_monoid {
    using value_type = std::pair<typename Monoid1::value_type, typename Monoid2::value_type>;
    const static Monoid1 M1;
    const static Monoid2 M2;

    value_type operator()() const {
      return {M1(), M2()};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      return {M1(a.first, b.first), M2(a.second, b.second)};
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

