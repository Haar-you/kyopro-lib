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


# :heavy_check_mark: mod累乗

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#795ab137908c82fc28acbcffe5b1c757">Mylib/Number/Mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Mod/mod_power.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-05 15:40:57+09:00




## Required by

* :heavy_check_mark: <a href="../../Convolution/ntt_convolution.cpp.html">Number Theoretic Transform</a>
* :heavy_check_mark: <a href="../../Graph/Coloring/chromatic_number.cpp.html">グラフ頂点彩色数</a>
* :heavy_check_mark: <a href="mod_log.cpp.html">離散対数</a>
* :heavy_check_mark: <a href="mod_sqrt.cpp.html">平方剰余</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2136/main.test.cpp.html">test/aoj/2136/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/2530/main.test.cpp.html">test/aoj/2530/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/convolution_mod/main.test.cpp.html">test/yosupo-judge/convolution_mod/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/convolution_mod_1000000007/main.test.cpp.html">test/yosupo-judge/convolution_mod_1000000007/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/discrete_logarithm_mod/main.test.cpp.html">test/yosupo-judge/discrete_logarithm_mod/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/sqrt_mod/main.test.cpp.html">test/yosupo-judge/sqrt_mod/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp.html">test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title mod累乗
 */
int64_t power(int64_t n, int64_t p, int64_t m){
  int64_t ret = 1;
  while(p > 0){
    if(p & 1) (ret *= n) %= m;
    (n *= n) %= m;
    p >>= 1;
  }
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Mod/mod_power.cpp"

/**
 * @title mod累乗
 */
int64_t power(int64_t n, int64_t p, int64_t m){
  int64_t ret = 1;
  while(p > 0){
    if(p & 1) (ret *= n) %= m;
    (n *= n) %= m;
    p >>= 1;
  }
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

