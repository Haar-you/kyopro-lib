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


# :x: Sum monoid

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Verified with

* :x: <a href="../../../../verify/test/aoj/2842/main.segment_tree.test.cpp.html">test/aoj/2842/main.segment_tree.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DSL_2_B/main.test.cpp.html">test/aoj/DSL_2_B/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DSL_2_E/main.test.cpp.html">test/aoj/DSL_2_E/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp.html">test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/point_add_rectangle_sum/main.test.cpp.html">test/yosupo-judge/point_add_rectangle_sum/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_add_path_sum/main.test.cpp.html">test/yosupo-judge/vertex_add_path_sum/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/789/main.test.cpp.html">test/yukicoder/789/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Sum monoid
 * @docs sum.md
 */
template <typename T>
struct SumMonoid {
  using value_type = T;
  value_type operator()() const {return 0;}
  value_type operator()(value_type a, value_type b) const {return a + b;}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/sum.cpp"

/**
 * @title Sum monoid
 * @docs sum.md
 */
template <typename T>
struct SumMonoid {
  using value_type = T;
  value_type operator()() const {return 0;}
  value_type operator()(value_type a, value_type b) const {return a + b;}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

