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


# :x: Bounded min monoid

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/bounded_min.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 19:04:20+09:00




## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/staticrmq/main.sparse_table.test.cpp.html">test/yosupo-judge/staticrmq/main.sparse_table.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <limits>
#include <algorithm>

/**
 * @title Bounded min monoid
 * @docs bounded_min.md
 */
namespace haar_lib {
  template <typename T>
  struct bounded_min_monoid {
    using value_type = T;

    value_type operator()() const {return std::numeric_limits<T>::max();}
    value_type operator()(const value_type &a, const value_type &b) const {
      return std::min(a, b);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/bounded_min.cpp"
#include <limits>
#include <algorithm>

/**
 * @title Bounded min monoid
 * @docs bounded_min.md
 */
namespace haar_lib {
  template <typename T>
  struct bounded_min_monoid {
    using value_type = T;

    value_type operator()() const {return std::numeric_limits<T>::max();}
    value_type operator()(const value_type &a, const value_type &b) const {
      return std::min(a, b);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

