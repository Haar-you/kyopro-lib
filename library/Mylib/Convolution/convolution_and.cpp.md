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


# :warning: Mylib/Convolution/convolution_and.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d1ac32c11c508fec0764fa012d8d2913">Mylib/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Convolution/convolution_and.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 01:42:28+09:00




## Depends on

* :heavy_check_mark: <a href="fast_mobius_transform_superset.cpp.html">上位集合に対する高速Möbius変換</a>
* :heavy_check_mark: <a href="fast_zeta_transform_superset.cpp.html">上位集合に対する高速Zeta変換</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Convolution/fast_zeta_transform_superset.cpp"
#include "Mylib/Convolution/fast_mobius_transform_superset.cpp"

/**
 * @note h_k = ∑_{k=i∩j} f(i) * g(j)
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
 * @title 上位集合に対する高速Zeta変換
 * @see https://codeforces.com/contest/1208/submission/59501702 (最大値2つを保持)
 * @note f(S) = ∑_{S⊆T} g(T)
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
#line 4 "Mylib/Convolution/fast_mobius_transform_superset.cpp"

/**
 * @title 上位集合に対する高速Möbius変換
 * @note f(S) = ∑_{S⊆T} g(T) * (-1)^(|T|-|S|)
 */
template <typename T, typename Func = std::minus<T>>
std::vector<T> fast_mobius_transform_superset(std::vector<T> f, const Func &op = std::minus<T>()){
  for(int i = 0; (1<<i) < (int)f.size(); ++i){
    for(int j = 0; j < (int)f.size(); ++j){
      if(!(j & (1<<i))) f[j] = op(f[j], f[j ^ (1<<i)]);
    }
  }
  return f;
}
#line 5 "Mylib/Convolution/convolution_and.cpp"

/**
 * @note h_k = ∑_{k=i∩j} f(i) * g(j)
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

