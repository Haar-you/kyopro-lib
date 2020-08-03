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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Mylib/IO/input_tuple.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f8c074a28e3c2f263a02491ce2132dd">Mylib/IO</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/IO/input_tuple.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 05:13:49+09:00




## Required by

* :heavy_check_mark: <a href="input_tuples.cpp.html">Mylib/IO/input_tuples.cpp</a>
* :heavy_check_mark: <a href="input_tuples_with_index.cpp.html">Mylib/IO/input_tuples_with_index.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0502/main.test.cpp.html">test/aoj/0502/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1508/main.splay_tree.test.cpp.html">test/aoj/1508/main.splay_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1508/main.treap.test.cpp.html">test/aoj/1508/main.treap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1549/main.test.cpp.html">test/aoj/1549/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2136/main.test.cpp.html">test/aoj/2136/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2426/main.test.cpp.html">test/aoj/2426/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2667/main.test.cpp.html">test/aoj/2667/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2674/main.test.cpp.html">test/aoj/2674/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2842/main.fenwick_tree.test.cpp.html">test/aoj/2842/main.fenwick_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2842/main.segment_tree.test.cpp.html">test/aoj/2842/main.segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2891/main.test.cpp.html">test/aoj/2891/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3058/main.test.cpp.html">test/aoj/3058/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3132/main.test.cpp.html">test/aoj/3132/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_10_C/main.test.cpp.html">test/aoj/ALDS1_10_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_1_C/main.test.cpp.html">test/aoj/ALDS1_1_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_1_A/main.test.cpp.html">test/aoj/CGL_1_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_1_B/main.test.cpp.html">test/aoj/CGL_1_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_1_C/main.test.cpp.html">test/aoj/CGL_1_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_2_A/main.test.cpp.html">test/aoj/CGL_2_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_2_B/main.test.cpp.html">test/aoj/CGL_2_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_2_C/main.test.cpp.html">test/aoj/CGL_2_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_2_D/main.test.cpp.html">test/aoj/CGL_2_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_3_C/main.test.cpp.html">test/aoj/CGL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_4_C/main.test.cpp.html">test/aoj/CGL_4_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_7_D/main.test.cpp.html">test/aoj/CGL_7_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_1_B/main.test.cpp.html">test/aoj/DSL_1_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_A/main.test.cpp.html">test/aoj/DSL_2_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_B/main.fenwick_tree.test.cpp.html">test/aoj/DSL_2_B/main.fenwick_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_B/main.test.cpp.html">test/aoj/DSL_2_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_C/main.test.cpp.html">test/aoj/DSL_2_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_D/main.test.cpp.html">test/aoj/DSL_2_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_E/main.test.cpp.html">test/aoj/DSL_2_E/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_F/main.test.cpp.html">test/aoj/DSL_2_F/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_G/main.test.cpp.html">test/aoj/DSL_2_G/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_H/main.starry_sky.test.cpp.html">test/aoj/DSL_2_H/main.starry_sky.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_H/main.test.cpp.html">test/aoj/DSL_2_H/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_2_I/main.test.cpp.html">test/aoj/DSL_2_I/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_5_A/main.test.cpp.html">test/aoj/DSL_5_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_5_B/main.test.cpp.html">test/aoj/DSL_5_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_3_C/main.test.cpp.html">test/aoj/GRL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_C/main.doubling.test.cpp.html">test/aoj/GRL_5_C/main.doubling.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_5_C/main.hld.test.cpp.html">test/aoj/GRL_5_C/main.hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_6_A/main.dinic.test.cpp.html">test/aoj/GRL_6_A/main.dinic.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp.html">test/aoj/GRL_6_A/main.ford_fulkerson.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_6_B/main.test.cpp.html">test/aoj/GRL_6_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_7_A/main.hopcroft_karp.test.cpp.html">test/aoj/GRL_7_A/main.hopcroft_karp.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/GRL_7_A/main.test.cpp.html">test/aoj/GRL_7_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/bipartitematching/main.test.cpp.html">test/yosupo-judge/bipartitematching/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/discrete_logarithm_mod/main.test.cpp.html">test/yosupo-judge/discrete_logarithm_mod/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp.html">test/yosupo-judge/dynamic_tree_vertex_add_path_sum/main.link_cut_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/factorize/main.test.cpp.html">test/yosupo-judge/factorize/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/kth_root_integer/main.test.cpp.html">test/yosupo-judge/kth_root_integer/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/line_add_get_min/main.test.cpp.html">test/yosupo-judge/line_add_get_min/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/maximum_independent_set/main.test.cpp.html">test/yosupo-judge/maximum_independent_set/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/persistent_queue/main.test.cpp.html">test/yosupo-judge/persistent_queue/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/persistent_unionfind/main.test.cpp.html">test/yosupo-judge/persistent_unionfind/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/point_set_range_composite/main.test.cpp.html">test/yosupo-judge/point_set_range_composite/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/queue_operate_all_composite/main.test.cpp.html">test/yosupo-judge/queue_operate_all_composite/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/range_affine_range_sum/main.test.cpp.html">test/yosupo-judge/range_affine_range_sum/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp.html">test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/range_kth_smallest/main.test.cpp.html">test/yosupo-judge/range_kth_smallest/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/segment_add_get_min/main.test.cpp.html">test/yosupo-judge/segment_add_get_min/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/set_xor_min/main.test.cpp.html">test/yosupo-judge/set_xor_min/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/sqrt_mod/main.test.cpp.html">test/yosupo-judge/sqrt_mod/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/static_range_inversions_query/main.test.cpp.html">test/yosupo-judge/static_range_inversions_query/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/static_range_sum/main.test.cpp.html">test/yosupo-judge/static_range_sum/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/staticrmq/main.sparse_table.test.cpp.html">test/yosupo-judge/staticrmq/main.sparse_table.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/tetration_mod/main.test.cpp.html">test/yosupo-judge/tetration_mod/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/two_sat/main.test.cpp.html">test/yosupo-judge/two_sat/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/unionfind/main.test.cpp.html">test/yosupo-judge/unionfind/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_add_path_sum/main.test.cpp.html">test/yosupo-judge/vertex_add_path_sum/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1030/main.test.cpp.html">test/yukicoder/1030/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1069/main.test.cpp.html">test/yukicoder/1069/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/1099/main.test.cpp.html">test/yukicoder/1099/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/117/main.test.cpp.html">test/yukicoder/117/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/3030/main.test.cpp.html">test/yukicoder/3030/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/510/main.test.cpp.html">test/yukicoder/510/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/631/main.starry_sky.test.cpp.html">test/yukicoder/631/main.starry_sky.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/631/main.test.cpp.html">test/yukicoder/631/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/658/main.test.cpp.html">test/yukicoder/658/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/755/main.test.cpp.html">test/yukicoder/755/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/776/main.test.cpp.html">test/yukicoder/776/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/782/main.test.cpp.html">test/yukicoder/782/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/789/main.test.cpp.html">test/yukicoder/789/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/875/main.test.cpp.html">test/yukicoder/875/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/899/main.test.cpp.html">test/yukicoder/899/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/922/main.test.cpp.html">test/yukicoder/922/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/IO/input_tuple.cpp"
#include <iostream>
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuple.md
 */
template <typename T, size_t ... I>
static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>){
  (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};
}

template <typename T, typename U>
std::istream& operator>>(std::istream &s, std::pair<T, U> &value){
  s >> value.first >> value.second;
  return s;
}

template <typename ... Args>
std::istream& operator>>(std::istream &s, std::tuple<Args...> &value){
  input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());
  return s;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

