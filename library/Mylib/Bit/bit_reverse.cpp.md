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


# :warning: ビット逆転

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fe4a83e4dc2a7f834ed4cd85d6972a53">Mylib/Bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Bit/bit_reverse.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 18:35:49+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title ビット逆転
 */
int32_t bit_reverse(int32_t a){
  a = ((a & 0x55555555) << 1) | ((a & 0xaaaaaaaa) >> 1);
  a = ((a & 0x33333333) << 2) | ((a & 0xcccccccc) >> 2);
  a = ((a & 0x0f0f0f0f) << 4) | ((a & 0xf0f0f0f0) >> 4);
  a = ((a & 0x00ff00ff) << 8) | ((a & 0xff00ff00) >> 8);
  a = (a << 16) | (a >> 16);
  return a;
}

int64_t bit_reverse_ll(int64_t a){
  a = ((a & 0x5555555555555555) << 1) | ((a & 0xaaaaaaaaaaaaaaaa) >> 1);
  a = ((a & 0x3333333333333333) << 2) | ((a & 0xcccccccccccccccc) >> 2);
  a = ((a & 0x0f0f0f0f0f0f0f0f) << 4) | ((a & 0xf0f0f0f0f0f0f0f0) >> 4);
  a = ((a & 0x00ff00ff00ff00ff) << 8) | ((a & 0xff00ff00ff00ff00) >> 8);
  a = ((a & 0x0000ffff0000ffff) << 16) | ((a & 0xffff0000ffff0000) >> 16);
  a = (a << 32) | (a >> 32);
  return a;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Bit/bit_reverse.cpp"

/**
 * @title ビット逆転
 */
int32_t bit_reverse(int32_t a){
  a = ((a & 0x55555555) << 1) | ((a & 0xaaaaaaaa) >> 1);
  a = ((a & 0x33333333) << 2) | ((a & 0xcccccccc) >> 2);
  a = ((a & 0x0f0f0f0f) << 4) | ((a & 0xf0f0f0f0) >> 4);
  a = ((a & 0x00ff00ff) << 8) | ((a & 0xff00ff00) >> 8);
  a = (a << 16) | (a >> 16);
  return a;
}

int64_t bit_reverse_ll(int64_t a){
  a = ((a & 0x5555555555555555) << 1) | ((a & 0xaaaaaaaaaaaaaaaa) >> 1);
  a = ((a & 0x3333333333333333) << 2) | ((a & 0xcccccccccccccccc) >> 2);
  a = ((a & 0x0f0f0f0f0f0f0f0f) << 4) | ((a & 0xf0f0f0f0f0f0f0f0) >> 4);
  a = ((a & 0x00ff00ff00ff00ff) << 8) | ((a & 0xff00ff00ff00ff00) >> 8);
  a = ((a & 0x0000ffff0000ffff) << 16) | ((a & 0xffff0000ffff0000) >> 16);
  a = (a << 32) | (a >> 32);
  return a;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

