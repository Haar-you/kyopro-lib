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


# :question: Mylib/IO/input_vector.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f8c074a28e3c2f263a02491ce2132dd">Mylib/IO</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/IO/input_vector.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-31 20:10:49+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/0558/main.graph.test.cpp.html">test/aoj/0558/main.graph.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/0558/main.test.cpp.html">test/aoj/0558/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/0575/main.test.cpp.html">test/aoj/0575/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1308/main.test.cpp.html">test/aoj/1308/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1327/main.test.cpp.html">test/aoj/1327/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1549/main.test.cpp.html">test/aoj/1549/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2136/main.test.cpp.html">test/aoj/2136/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2171/main.test.cpp.html">test/aoj/2171/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2446/main.test.cpp.html">test/aoj/2446/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2530/main.test.cpp.html">test/aoj/2530/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2674/main.test.cpp.html">test/aoj/2674/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2903/main.test.cpp.html">test/aoj/2903/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2955/main.test.cpp.html">test/aoj/2955/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3034/main.test.cpp.html">test/aoj/3034/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3058/main.test.cpp.html">test/aoj/3058/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3119/main.test.cpp.html">test/aoj/3119/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/3134/main.test.cpp.html">test/aoj/3134/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_14_C/main.test.cpp.html">test/aoj/ALDS1_14_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/ALDS1_5_D/main.test.cpp.html">test/aoj/ALDS1_5_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_3_A/main.test.cpp.html">test/aoj/CGL_3_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_3_B/main.test.cpp.html">test/aoj/CGL_3_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_3_C/main.test.cpp.html">test/aoj/CGL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_4_A/main.test.cpp.html">test/aoj/CGL_4_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_4_B/main.test.cpp.html">test/aoj/CGL_4_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_4_C/main.test.cpp.html">test/aoj/CGL_4_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_5_A/main.test.cpp.html">test/aoj/CGL_5_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/CGL_7_H/main.test.cpp.html">test/aoj/CGL_7_H/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_1_D/main.test.cpp.html">test/aoj/DPL_1_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_3_B/main.test.cpp.html">test/aoj/DPL_3_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_3_C/main.test.cpp.html">test/aoj/DPL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DSL_3_D/main.test.cpp.html">test/aoj/DSL_3_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/ITP2_11_B/main.asc.test.cpp.html">test/aoj/ITP2_11_B/main.asc.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/ITP2_11_B/main.desc.test.cpp.html">test/aoj/ITP2_11_B/main.desc.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/ITP2_11_C/main.asc.test.cpp.html">test/aoj/ITP2_11_C/main.asc.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/ITP2_11_C/main.desc.test.cpp.html">test/aoj/ITP2_11_C/main.desc.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/NTL_1_C/main.test.cpp.html">test/aoj/NTL_1_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/assignment/main.test.cpp.html">test/yosupo-judge/assignment/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/convolution_mod/main.test.cpp.html">test/yosupo-judge/convolution_mod/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/convolution_mod_1000000007/main.test.cpp.html">test/yosupo-judge/convolution_mod_1000000007/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/enumerate_triangles/main.test.cpp.html">test/yosupo-judge/enumerate_triangles/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/matrix_det/main.test.cpp.html">test/yosupo-judge/matrix_det/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/range_affine_range_sum/main.test.cpp.html">test/yosupo-judge/range_affine_range_sum/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp.html">test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/range_kth_smallest/main.test.cpp.html">test/yosupo-judge/range_kth_smallest/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/static_range_sum/main.test.cpp.html">test/yosupo-judge/static_range_sum/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/staticrmq/main.sparse_table.test.cpp.html">test/yosupo-judge/staticrmq/main.sparse_table.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/system_of_linear_equations/main.test.cpp.html">test/yosupo-judge/system_of_linear_equations/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_add_path_sum/main.test.cpp.html">test/yosupo-judge/vertex_add_path_sum/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.euler_tour.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp.html">test/yosupo-judge/vertex_add_subtree_sum/main.hld.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/1030/main.test.cpp.html">test/yukicoder/1030/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/194/main.test.cpp.html">test/yukicoder/194/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/430/main.aho_corasick.test.cpp.html">test/yukicoder/430/main.aho_corasick.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/631/main.starry_sky.test.cpp.html">test/yukicoder/631/main.starry_sky.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/631/main.test.cpp.html">test/yukicoder/631/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/755/main.test.cpp.html">test/yukicoder/755/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/776/main.test.cpp.html">test/yukicoder/776/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/899/main.test.cpp.html">test/yukicoder/899/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/919/main.test.cpp.html">test/yukicoder/919/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <vector>

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/IO/input_vector.cpp"
#include <iostream>
#include <vector>

/**
 * @docs input_vector.md
 */
template <typename T>
std::vector<T> input_vector(int N){
  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) std::cin >> ret[i];
  return ret;
}

template <typename T>
std::vector<std::vector<T>> input_vector(int N, int M){
  std::vector<std::vector<T>> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

