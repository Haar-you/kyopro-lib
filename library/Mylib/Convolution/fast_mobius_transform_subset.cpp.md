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


# :heavy_check_mark: Fast Möbius transform (Subsets)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d1ac32c11c508fec0764fa012d8d2913">Mylib/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Convolution/fast_mobius_transform_subset.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `fast_mobius_transform_subset(f[N], op = std::minus())`
	- `N`は2の累乗
	- $g(S) = \sum_{T \subseteq S} f(T) * (-1) ^ {\vert S \vert - \vert T \vert}$

## Requirements

## Notes

## Problems

- [AOJ 2446 Enumeration](https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2446)

## References


## Required by

* :warning: <a href="convolution_or.cpp.html">Convolution (Index bitwise OR)</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2446/main.test.cpp.html">test/aoj/2446/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <functional>

/**
 * @title Fast Möbius transform (Subsets)
 * @docs fast_mobius_transform_subset.md
 */
template <typename T, typename Func = std::minus<T>>
std::vector<T> fast_mobius_transform_subset(std::vector<T> f, const Func &op = std::minus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(j & (1<<i)) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Convolution/fast_mobius_transform_subset.cpp"
#include <vector>
#include <functional>

/**
 * @title Fast Möbius transform (Subsets)
 * @docs fast_mobius_transform_subset.md
 */
template <typename T, typename Func = std::minus<T>>
std::vector<T> fast_mobius_transform_subset(std::vector<T> f, const Func &op = std::minus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(j & (1<<i)) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

