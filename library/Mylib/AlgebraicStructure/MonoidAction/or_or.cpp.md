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


# :warning: Range bitor / Range bitor

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#7bd9a37defae28fe1746a7ffe2a62491">Mylib/AlgebraicStructure/MonoidAction</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/MonoidAction/or_or.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 14:07:48+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Range bitor / Range bitor
 * @docs or_or.md
 */
template <typename T, typename U>
struct OrOr{
  using value_type_get = T;
  using value_type_update = U;

  value_type_get id_get() const {return 0;}
  value_type_update id_update() const {return 0;}

  value_type_get op_get(value_type_get a, value_type_get b) const {return a | b;}
  value_type_update op_update(value_type_update a, value_type_update b) const {return a | b;}

  value_type_get op(value_type_get a, value_type_update b, int len) const {
    return a | b;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/MonoidAction/or_or.cpp"

/**
 * @title Range bitor / Range bitor
 * @docs or_or.md
 */
template <typename T, typename U>
struct OrOr{
  using value_type_get = T;
  using value_type_update = U;

  value_type_get id_get() const {return 0;}
  value_type_update id_update() const {return 0;}

  value_type_get op_get(value_type_get a, value_type_get b) const {return a | b;}
  value_type_update op_update(value_type_update a, value_type_update b) const {return a | b;}

  value_type_get op(value_type_get a, value_type_update b, int len) const {
    return a | b;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

