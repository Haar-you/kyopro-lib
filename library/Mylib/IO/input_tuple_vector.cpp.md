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


# :question: Mylib/IO/input_tuple_vector.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7f8c074a28e3c2f263a02491ce2132dd">Mylib/IO</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/IO/input_tuple_vector.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-31 20:10:49+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/0575/main.test.cpp.html">test/aoj/0575/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/1337/main.test.cpp.html">test/aoj/1337/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2293/main.test.cpp.html">test/aoj/2293/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/2426/main.test.cpp.html">test/aoj/2426/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/3132/main.test.cpp.html">test/aoj/3132/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/ALDS1_15_C/main.test.cpp.html">test/aoj/ALDS1_15_C/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DPL_1_B/main.test.cpp.html">test/aoj/DPL_1_B/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DPL_1_C/main.test.cpp.html">test/aoj/DPL_1_C/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DPL_1_F/main.test.cpp.html">test/aoj/DPL_1_F/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DPL_1_G/main.test.cpp.html">test/aoj/DPL_1_G/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DPL_1_H/main.test.cpp.html">test/aoj/DPL_1_H/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/DPL_2_C/main.test.cpp.html">test/aoj/DPL_2_C/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.persistent_segment_tree.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp.html">test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
template <typename T, size_t ... I>
void input_tuple_vector_init(T &val, int N, std::index_sequence<I...>){
  (void)std::initializer_list<int>{
    (void(std::get<I>(val).resize(N)), 0)...
  };
}

template <typename T, size_t ... I>
void input_tuple_vector_helper(T &val, int i, std::index_sequence<I...>){
  (void)std::initializer_list<int>{
    (void(std::cin >> std::get<I>(val)[i]), 0)...
  };
}

template <typename ... Args>
auto input_tuple_vector(int N){
  std::tuple<std::vector<Args>...> ret;

  input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());
  for(int i = 0; i < N; ++i){
    input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/IO/input_tuple_vector.cpp"
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <initializer_list>

/**
 * @docs input_tuple_vector.md
 */
template <typename T, size_t ... I>
void input_tuple_vector_init(T &val, int N, std::index_sequence<I...>){
  (void)std::initializer_list<int>{
    (void(std::get<I>(val).resize(N)), 0)...
  };
}

template <typename T, size_t ... I>
void input_tuple_vector_helper(T &val, int i, std::index_sequence<I...>){
  (void)std::initializer_list<int>{
    (void(std::cin >> std::get<I>(val)[i]), 0)...
  };
}

template <typename ... Args>
auto input_tuple_vector(int N){
  std::tuple<std::vector<Args>...> ret;

  input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());
  for(int i = 0; i < N; ++i){
    input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());
  }

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

