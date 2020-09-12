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


# :warning: Mylib/AlgebraicStructure/Monoid/with_max_index.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/with_max_index.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>
#include <limits>
#include <algorithm>

/**
 * @docs with_max_index.md
 */
namespace haar_lib {
  template <typename Monoid>
  struct with_max_index {
    using value_type = std::pair<typename Monoid::value_type, int64_t>;
    const static Monoid M;

    value_type operator()() const {
      return {M(), 0};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(a.first == b.first) return {a.first, std::max(a.second, b.second)};
      if(M(a.first, b.first) == a.first) return a;
      else return b;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/with_max_index.cpp"
#include <utility>
#include <limits>
#include <algorithm>

/**
 * @docs with_max_index.md
 */
namespace haar_lib {
  template <typename Monoid>
  struct with_max_index {
    using value_type = std::pair<typename Monoid::value_type, int64_t>;
    const static Monoid M;

    value_type operator()() const {
      return {M(), 0};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if(a.first == b.first) return {a.first, std::max(a.second, b.second)};
      if(M(a.first, b.first) == a.first) return a;
      else return b;
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

