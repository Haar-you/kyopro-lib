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


# :x: Range add / Range max

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7bd9a37defae28fe1746a7ffe2a62491">Mylib/AlgebraicStructure/MonoidAction</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/MonoidAction/add_max.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :x: <a href="../../../../verify/test/yukicoder/631/main.test.cpp.html">test/yukicoder/631/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <optional>

/**
 * @title Range add / Range max
 * @docs add_max.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct add_max {
    using value_type_get = std::optional<T>;
    using value_type_update = U;

    value_type_get id_get() const {return {};}
    value_type_update id_update() const {return 0;}

    value_type_get op_get(value_type_get a, value_type_get b) const {
      if(not a) return b;
      if(not b) return a;
      return {std::max(*a, *b)};
    }
    value_type_update op_update(value_type_update a, value_type_update b) const {return a + b;}

    value_type_get op(value_type_get a, value_type_update b, int) const {
      if(a) return {*a + b};
      return {};
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/MonoidAction/add_max.cpp"
#include <optional>

/**
 * @title Range add / Range max
 * @docs add_max.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct add_max {
    using value_type_get = std::optional<T>;
    using value_type_update = U;

    value_type_get id_get() const {return {};}
    value_type_update id_update() const {return 0;}

    value_type_get op_get(value_type_get a, value_type_get b) const {
      if(not a) return b;
      if(not b) return a;
      return {std::max(*a, *b)};
    }
    value_type_update op_update(value_type_update a, value_type_update b) const {return a + b;}

    value_type_get op(value_type_get a, value_type_update b, int) const {
      if(a) return {*a + b};
      return {};
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

