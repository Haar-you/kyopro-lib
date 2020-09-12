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


# :warning: Max contiguous monoid

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/max_contiguous.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

- `id()`
	- 長さ`0`の列を表す。
	- `return (0, 0, 0, 0)`
- `op(a, b)`
	- `a`の右隣に`b`を隣接させる。

## Requirements

## Notes

- 連続する`1`の最大長を管理する。
	- `value_type = (最大連続長, 左側最大連続長, 右側最大連続長, セグメント長)`

## Problems

## References



## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <tuple>
#include <algorithm>

/**
 * @title Max contiguous monoid
 * @docs max_contiguous.md
 */
namespace haar_lib {
  struct max_contiguous_monoid {
    using value_type = std::tuple<int, int, int, int>;

    value_type operator()() const {
      return {0, 0, 0, 0};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      auto [ca, la, ra, lena] = a;
      auto [cb, lb, rb, lenb] = b;

      return {
              std::max({ca, cb, ra + lb}),
              ca == lena ? ca + lb : la,
              cb == lenb ? cb + ra : rb,
              lena + lenb
      };
    }

    static value_type zero(){
      return {0, 0, 0, 1};
    }

    static value_type one(){
      return {1, 1, 1, 1};
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/max_contiguous.cpp"
#include <tuple>
#include <algorithm>

/**
 * @title Max contiguous monoid
 * @docs max_contiguous.md
 */
namespace haar_lib {
  struct max_contiguous_monoid {
    using value_type = std::tuple<int, int, int, int>;

    value_type operator()() const {
      return {0, 0, 0, 0};
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      auto [ca, la, ra, lena] = a;
      auto [cb, lb, rb, lenb] = b;

      return {
              std::max({ca, cb, ra + lb}),
              ca == lena ? ca + lb : la,
              cb == lenb ? cb + ra : rb,
              lena + lenb
      };
    }

    static value_type zero(){
      return {0, 0, 0, 1};
    }

    static value_type one(){
      return {1, 1, 1, 1};
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
