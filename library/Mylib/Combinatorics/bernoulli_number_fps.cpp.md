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


# :heavy_check_mark: Bernoulli number (FPS)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/bernoulli_number_fps.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 09:35:37+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/bernoulli_number/main.test.cpp.html">test/yosupo-judge/bernoulli_number/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Bernoulli number (FPS)
 * @docs bernoulli_number_fps.md
 */
template <typename Fps, typename Ft>
auto bernoulli_number_fps(int N, const Ft &ft){
  Fps x(N + 1);

  for(int i = 0; i <= N; ++i) x[i] = ft.inv_factorial(i + 1);
  x = x.inv();

  for(int i = 0; i <= N; ++i) x[i] *= ft.factorial(i);

  return x;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/bernoulli_number_fps.cpp"

/**
 * @title Bernoulli number (FPS)
 * @docs bernoulli_number_fps.md
 */
template <typename Fps, typename Ft>
auto bernoulli_number_fps(int N, const Ft &ft){
  Fps x(N + 1);

  for(int i = 0; i <= N; ++i) x[i] = ft.inv_factorial(i + 1);
  x = x.inv();

  for(int i = 0; i <= N; ++i) x[i] *= ft.factorial(i);

  return x;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

