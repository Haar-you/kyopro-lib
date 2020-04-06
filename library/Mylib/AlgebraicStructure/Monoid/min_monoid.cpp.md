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


# :question: Mylib/AlgebraicStructure/Monoid/min_monoid.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/min_monoid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 06:18:07+09:00




## Required by

* :heavy_check_mark: <a href="../MonoidAction/add_min.cpp.html">Mylib/AlgebraicStructure/MonoidAction/add_min.cpp</a>
* :heavy_check_mark: <a href="../MonoidAction/update_min.cpp.html">Mylib/AlgebraicStructure/MonoidAction/update_min.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/1508/main.splay_tree.test.cpp.html">test/aoj/1508/main.splay_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/1508/main.treap.test.cpp.html">test/aoj/1508/main.treap.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/DSL_2_A/main.test.cpp.html">test/aoj/DSL_2_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/DSL_2_F/main.test.cpp.html">test/aoj/DSL_2_F/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/DSL_2_H/main.test.cpp.html">test/aoj/DSL_2_H/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/875/main.test.cpp.html">test/yukicoder/875/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>

template <typename T>
struct MinMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return std::numeric_limits<T>::max();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::min(a, b);}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/min_monoid.cpp"
#include <algorithm>

template <typename T>
struct MinMonoid{
  using value_type = T;
  constexpr inline static value_type id(){return std::numeric_limits<T>::max();}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::min(a, b);}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

