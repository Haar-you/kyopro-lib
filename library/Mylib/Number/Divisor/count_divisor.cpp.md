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


# :warning: 約数個数

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e1d7bebd3991495167778e37d1d75d40">Mylib/Number/Divisor</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Divisor/count_divisor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title 約数個数
 * @docs count_divisor.md
 */
int count_divisor(std::int64_t n){
  int count = 0;
  for(std::int64_t i = 1LL; i * i <= n; ++i){
    if(n % i == 0){
      count += 2;
      if(i * i == n) count -= 1;
    }
  }
  return count;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Divisor/count_divisor.cpp"

/**
 * @title 約数個数
 * @docs count_divisor.md
 */
int count_divisor(std::int64_t n){
  int count = 0;
  for(std::int64_t i = 1LL; i * i <= n; ++i){
    if(n % i == 0){
      count += 2;
      if(i * i == n) count -= 1;
    }
  }
  return count;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
