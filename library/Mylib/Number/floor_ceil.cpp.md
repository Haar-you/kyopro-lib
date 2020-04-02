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


# :warning: 床関数・天井関数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/floor_ceil.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title 床関数・天井関数
 */
int64_t ceil(int64_t a, int64_t b){
  if((a <= 0 and b < 0) or (a >= 0 and b > 0)) return (abs(a) + abs(b) - 1) / abs(b);
  return - (abs(a) / abs(b));
}

int64_t floor(int64_t a, int64_t b){
  if((a <= 0 and b < 0) or (a >= 0 and b > 0)) return a / b;
  return - (abs(a) + abs(b) - 1) / abs(b);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/floor_ceil.cpp"

/**
 * @title 床関数・天井関数
 */
int64_t ceil(int64_t a, int64_t b){
  if((a <= 0 and b < 0) or (a >= 0 and b > 0)) return (abs(a) + abs(b) - 1) / abs(b);
  return - (abs(a) / abs(b));
}

int64_t floor(int64_t a, int64_t b){
  if((a <= 0 and b < 0) or (a >= 0 and b > 0)) return a / b;
  return - (abs(a) + abs(b) - 1) / abs(b);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

