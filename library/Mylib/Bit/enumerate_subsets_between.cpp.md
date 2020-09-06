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


# :warning: Enumerate subsets (Between)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fe4a83e4dc2a7f834ed4cd85d6972a53">Mylib/Bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Bit/enumerate_subsets_between.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 04:37:36+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Enumerate subsets (Between)
 * @docs enumerate_subsets_between.md
 */
template <typename Func>
void enumerate_subsets_between(int a, int b, const Func &f){
  const int x = b ^ (a & b);
  for(int t = x; ; t = (t - 1) & x){
    if(not f(t | a)) break;
    if(t == 0) break;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Bit/enumerate_subsets_between.cpp"

/**
 * @title Enumerate subsets (Between)
 * @docs enumerate_subsets_between.md
 */
template <typename Func>
void enumerate_subsets_between(int a, int b, const Func &f){
  const int x = b ^ (a & b);
  for(int t = x; ; t = (t - 1) & x){
    if(not f(t | a)) break;
    if(t == 0) break;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

