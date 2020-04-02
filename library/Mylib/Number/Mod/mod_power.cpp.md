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


# :question: Mylib/Number/Mod/mod_power.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#795ab137908c82fc28acbcffe5b1c757">Mylib/Number/Mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Mod/mod_power.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 07:59:09+09:00




## Required by

* :x: <a href="../../Convolution/ntt_convolution.cpp.html">Mylib/Convolution/ntt_convolution.cpp</a>
* :warning: <a href="../../Graph/Coloring/chromatic_number.cpp.html">Mylib/Graph/Coloring/chromatic_number.cpp</a>
* :heavy_check_mark: <a href="mod_log.cpp.html">Mylib/Number/Mod/mod_log.cpp</a>
* :heavy_check_mark: <a href="mod_sqrt.cpp.html">Mylib/Number/Mod/mod_sqrt.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2530/main.test.cpp.html">test/aoj/2530/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/convolution_mod/main.test.cpp.html">test/yosupo-judge/convolution_mod/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/convolution_mod_1000000007/main.test.cpp.html">test/yosupo-judge/convolution_mod_1000000007/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/discrete_logarithm_mod/main.test.cpp.html">test/yosupo-judge/discrete_logarithm_mod/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/sqrt_mod/main.test.cpp.html">test/yosupo-judge/sqrt_mod/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp.html">test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

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

