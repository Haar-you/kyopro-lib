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


# :warning: Convolution (Index bitwise AND)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d1ac32c11c508fec0764fa012d8d2913">Mylib/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Convolution/convolution_and.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Operations

- `convolution_and(f[N], g[N])`
	- `N`は2の累乗
	- `k in [0, N)`について、$h_k = \sum_{k=i \cap j} f_i * g_j$を求める。

## Requirements

## Notes

## Problems

## References


## Depends on

* :x: <a href="fast_mobius_transform_superset.cpp.html">Fast Möbius transform (Supersets)</a>
* :x: <a href="fast_zeta_transform_superset.cpp.html">Fast Zeta transform (Supersets)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Convolution/fast_zeta_transform_superset.cpp"
#include "Mylib/Convolution/fast_mobius_transform_superset.cpp"

/**
 * @title Convolution (Index bitwise AND)
 * @docs convolution_and.md
 */
template <typename T>
std::vector<T> convolution_and(std::vector<T> f, std::vector<T> g){
  f = fast_zeta_transform_superset(f);
  g = fast_zeta_transform_superset(g);
  for(size_t i = 0; i < f.size(); ++i) f[i] *= g[i];
  f = fast_mobius_transform_superset(f);
  return f;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Convolution/convolution_and.cpp"
#include <vector>
#line 3 "Mylib/Convolution/fast_zeta_transform_superset.cpp"
#include <functional>

/**
 * @title Fast Zeta transform (Supersets)
 * @docs fast_zeta_transform_superset.md
 */
template <typename T, typename Func = std::plus<T>>
std::vector<T> fast_zeta_transform_superset(std::vector<T> f, const Func &op = std::plus<T>()){
  for(int i = 0; (1 << i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(!(j & (1 << i))) f[j] = op(f[j], f[j ^ (1 << i)]);
    }
  }
  return f;
}
#line 4 "Mylib/Convolution/fast_mobius_transform_superset.cpp"

/**
 * @title Fast Möbius transform (Supersets)
 * @docs fast_mobius_transform_superset.md
 */
template <typename T, typename Func = std::minus<T>>
std::vector<T> fast_mobius_transform_superset(std::vector<T> f, const Func &op = std::minus<T>()){
  for(int i = 0; (1 << i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(!(j & (1 << i))) f[j] = op(f[j], f[j ^ (1 << i)]);
    }
  }
  return f;
}
#line 5 "Mylib/Convolution/convolution_and.cpp"

/**
 * @title Convolution (Index bitwise AND)
 * @docs convolution_and.md
 */
template <typename T>
std::vector<T> convolution_and(std::vector<T> f, std::vector<T> g){
  f = fast_zeta_transform_superset(f);
  g = fast_zeta_transform_superset(g);
  for(size_t i = 0; i < f.size(); ++i) f[i] *= g[i];
  f = fast_mobius_transform_superset(f);
  return f;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

