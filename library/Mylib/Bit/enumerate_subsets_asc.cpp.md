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


# :x: Enumerate subsets (Ascending order)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fe4a83e4dc2a7f834ed4cd85d6972a53">Mylib/Bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Bit/enumerate_subsets_asc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 04:37:36+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/3034/main.test.cpp.html">test/aoj/3034/main.test.cpp</a>
* :x: <a href="../../../verify/test/aoj/ITP2_11_C/main.asc.test.cpp.html">test/aoj/ITP2_11_C/main.asc.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Enumerate subsets (Ascending order)
 * @docs enumerate_subsets_asc.md
 */
template <typename Func>
void enumerate_subsets_asc(int a, const Func &f){
  for(int t = 0; ; t = (t - a) & a){
    if(not f(t)) break;
    if(t == a) break;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Bit/enumerate_subsets_asc.cpp"

/**
 * @title Enumerate subsets (Ascending order)
 * @docs enumerate_subsets_asc.md
 */
template <typename Func>
void enumerate_subsets_asc(int a, const Func &f){
  for(int t = 0; ; t = (t - a) & a){
    if(not f(t)) break;
    if(t == a) break;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

