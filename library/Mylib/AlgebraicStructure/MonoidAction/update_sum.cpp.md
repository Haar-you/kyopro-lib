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


# :x: Range update / Range sum

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7bd9a37defae28fe1746a7ffe2a62491">Mylib/AlgebraicStructure/MonoidAction</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/DSL_2_I/main.test.cpp.html">test/aoj/DSL_2_I/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/899/main.test.cpp.html">test/yukicoder/899/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <optional>

/**
 * @title Range update / Range sum
 * @docs update_sum.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct update_sum {
    using value_type_get = T;
    using value_type_update = std::optional<U>;

    value_type_get id_get() const {return 0;}
    value_type_update id_update() const {return {};}

    value_type_get op_get(value_type_get a, value_type_get b) const {return a + b;}
    value_type_update op_update(value_type_update a, value_type_update b) const {return (a ? a : b);}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return b ? *b * len : a;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/MonoidAction/update_sum.cpp"
#include <optional>

/**
 * @title Range update / Range sum
 * @docs update_sum.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct update_sum {
    using value_type_get = T;
    using value_type_update = std::optional<U>;

    value_type_get id_get() const {return 0;}
    value_type_update id_update() const {return {};}

    value_type_get op_get(value_type_get a, value_type_get b) const {return a + b;}
    value_type_update op_update(value_type_update a, value_type_update b) const {return (a ? a : b);}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return b ? *b * len : a;
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

