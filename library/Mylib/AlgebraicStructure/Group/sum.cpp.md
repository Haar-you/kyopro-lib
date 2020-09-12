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


# :x: Sum group

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a11cf6f4bd6e76e33e4d7136e3eb98bc">Mylib/AlgebraicStructure/Group</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Group/sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/2842/main.fenwick_tree.test.cpp.html">test/aoj/2842/main.fenwick_tree.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DSL_2_B/main.fenwick_tree.test.cpp.html">test/aoj/DSL_2_B/main.fenwick_tree.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Sum group
 * @docs sum.md
 */
namespace haar_lib {
  template <typename T>
  struct sum_group {
    using value_type = T;

    value_type operator()() const {return 0;}
    value_type operator()(const value_type &a, const value_type &b) const {return a + b;}
    value_type inv(const value_type &a) const {return -a;}
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Group/sum.cpp"

/**
 * @title Sum group
 * @docs sum.md
 */
namespace haar_lib {
  template <typename T>
  struct sum_group {
    using value_type = T;

    value_type operator()() const {return 0;}
    value_type operator()(const value_type &a, const value_type &b) const {return a + b;}
    value_type inv(const value_type &a) const {return -a;}
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
