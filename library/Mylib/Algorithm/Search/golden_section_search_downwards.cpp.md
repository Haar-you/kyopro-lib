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


# :x: 下に凸の黄金分割探索

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#a7582795d3062b8fdf2ece0fd4f2d90d">Mylib/Algorithm/Search</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/Search/golden_section_search_downwards.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-15 00:08:08+09:00




## Verified with

* :x: <a href="../../../../verify/test/yukicoder/306/main.golden.test.cpp.html">test/yukicoder/306/main.golden.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <functional>
#include <cmath>

/**
 * @title 下に凸の黄金分割探索
 */
template <typename T = double, typename Func = std::function<T(T)>>
T golden_section_search_downwards(T lb, T ub, const Func &f, int LOOP_COUNT = 100){
  constexpr T phi = (1.0 + std::sqrt(5)) / 2;
  
  T t1, t2;

  while(LOOP_COUNT--){
    t1 = (lb * phi + ub) / (phi + 1.0);
    t2 = (lb + ub * phi) / (phi + 1.0);

    if(f(t1) < f(t2)){
      ub = t2;
    }else{
      lb = t1;
    }
  }

  return lb;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/Search/golden_section_search_downwards.cpp"
#include <functional>
#include <cmath>

/**
 * @title 下に凸の黄金分割探索
 */
template <typename T = double, typename Func = std::function<T(T)>>
T golden_section_search_downwards(T lb, T ub, const Func &f, int LOOP_COUNT = 100){
  constexpr T phi = (1.0 + std::sqrt(5)) / 2;
  
  T t1, t2;

  while(LOOP_COUNT--){
    t1 = (lb * phi + ub) / (phi + 1.0);
    t2 = (lb + ub * phi) / (phi + 1.0);

    if(f(t1) < f(t2)){
      ub = t2;
    }else{
      lb = t1;
    }
  }

  return lb;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

