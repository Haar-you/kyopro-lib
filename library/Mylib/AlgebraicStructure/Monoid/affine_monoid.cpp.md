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


# :question: Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

- `id()`
	- 恒等関数 $f(x) = x$ を返す。
	- `return (1, 0)`
- `op(a, b)`
	- 合成した関数 $a \circ b$ を返す。

## Requirements

## Notes

## Problems

- [ARC 008 D - タコヤキオイシクナール](https://atcoder.jp/contests/arc008/tasks/arc008_4)
- [Point Set Range Composite](https://judge.yosupo.jp/problem/point_set_range_composite)

## References



## Required by

* :heavy_check_mark: <a href="../MonoidAction/affine_sum.cpp.html">Mylib/AlgebraicStructure/MonoidAction/affine_sum.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/point_set_range_composite/main.test.cpp.html">test/yosupo-judge/point_set_range_composite/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/range_affine_range_sum/main.test.cpp.html">test/yosupo-judge/range_affine_range_sum/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

/**
 * @docs affine_monoid.md
 */
template <typename T>
struct AffineMonoid{
  using value_type = std::pair<T, T>;
  constexpr inline static value_type id(){return std::make_pair(1, 0);}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::make_pair(a.first * b.first, a.first * b.second + a.second);}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/affine_monoid.cpp"
#include <utility>

/**
 * @docs affine_monoid.md
 */
template <typename T>
struct AffineMonoid{
  using value_type = std::pair<T, T>;
  constexpr inline static value_type id(){return std::make_pair(1, 0);}
  constexpr inline static value_type op(const value_type &a, const value_type &b){return std::make_pair(a.first * b.first, a.first * b.second + a.second);}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

