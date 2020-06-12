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


# :heavy_check_mark: Fast Zeta transform (Superset)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d1ac32c11c508fec0764fa012d8d2913">Mylib/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Convolution/fast_zeta_transform_superset.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `fast_zeta_transform_superset(f[N], op = std::plus())`
	- `N`は2の累乗
	- $g(S) = \sum_{S \subseteq T} f(T)$

## Requirements

## Notes

## Problems

- [Manthan, Codefest 19 F. Bits And Pieces](https://codeforces.com/contest/1208/problem/F) (最大値2つを保持)

## References


## Required by

* :warning: <a href="convolution_and.cpp.html">Convolution (Index bitwise AND)</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/3119/main.test.cpp.html">test/aoj/3119/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <functional>

/**
 * @title Fast Zeta transform (Superset)
 * @docs fast_zeta_transform_superset.md
 */
template <typename T, typename Func = std::plus<T>>
std::vector<T> fast_zeta_transform_superset(std::vector<T> f, const Func &op = std::plus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(!(j & (1<<i))) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Convolution/fast_zeta_transform_superset.cpp"
#include <vector>
#include <functional>

/**
 * @title Fast Zeta transform (Superset)
 * @docs fast_zeta_transform_superset.md
 */
template <typename T, typename Func = std::plus<T>>
std::vector<T> fast_zeta_transform_superset(std::vector<T> f, const Func &op = std::plus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(!(j & (1<<i))) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
