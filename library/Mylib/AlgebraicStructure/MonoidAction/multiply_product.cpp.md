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


# :warning: Range multiply / Range product

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7bd9a37defae28fe1746a7ffe2a62491">Mylib/AlgebraicStructure/MonoidAction</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Depends on

* :warning: <a href="../Monoid/monoid_utils.cpp.html">Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp</a>
* :x: <a href="../Monoid/product.cpp.html">Product monoid</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/AlgebraicStructure/Monoid/product.cpp"
#include "Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp"

/**
 * @title Range multiply / Range product
 * @docs multiply_product.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct multiply_product {
    using monoid_get = product_monoid<T>;
    using monoid_update = product_monoid<U>;
    using value_type_get = typename monoid_get::value_type;
    using value_type_update = typename monoid_update::value_type;
    monoid_get M1;
    monoid_update M2;

    value_type_get id_get() const {return M1.id();}
    value_type_update id_update() const {return M2.id();}

    value_type_get op_get(value_type_get a, value_type_get b) const {return M1.op(a, b);}
    value_type_update op_update(value_type_update a, value_type_update b) const {return M2.op(a, b);}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return a * times<monoid_update>(b, len);
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/product.cpp"

/**
 * @title Product monoid
 * @docs product.md
 */
namespace haar_lib {
  template <typename T>
  struct product_monoid {
    using value_type = T;
    value_type operator()() const {return 1;}
    value_type operator()(value_type a, value_type b) const {return a * b;}
  };
}
#line 2 "Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp"
#include <cstdint>

/**
 * @docs monoid_utils.md
 */
namespace haar_lib {
  template <typename Monoid, typename value_type = typename Monoid::value_type>
  value_type times(value_type a, int64_t p){
    Monoid M;
    auto ret = M.id();

    while(p > 0){
      if(p & 1) ret = M.op(ret, a);
      a = M.op(a, a);
      p >>= 1;
    }

    return ret;
  }
}
#line 4 "Mylib/AlgebraicStructure/MonoidAction/multiply_product.cpp"

/**
 * @title Range multiply / Range product
 * @docs multiply_product.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct multiply_product {
    using monoid_get = product_monoid<T>;
    using monoid_update = product_monoid<U>;
    using value_type_get = typename monoid_get::value_type;
    using value_type_update = typename monoid_update::value_type;
    monoid_get M1;
    monoid_update M2;

    value_type_get id_get() const {return M1.id();}
    value_type_update id_update() const {return M2.id();}

    value_type_get op_get(value_type_get a, value_type_get b) const {return M1.op(a, b);}
    value_type_update op_update(value_type_update a, value_type_update b) const {return M2.op(a, b);}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return a * times<monoid_update>(b, len);
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

