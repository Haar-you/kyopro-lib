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


# :warning: Mylib/Bit/for_each_subset_between.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fe4a83e4dc2a7f834ed4cd85d6972a53">Mylib/Bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Bit/for_each_subset_between.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 09:18:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @note for each subset x : a ⊆ x ⊆ b
 */
template <typename Func>
void for_each_subset_between(int a, int b, const Func &f){
  int x = b^(a&b);
  for(int t=x; ; t=(t-1)&x){
    f(t|a);
    if(t==0) break;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Bit/for_each_subset_between.cpp"

/**
 * @note for each subset x : a ⊆ x ⊆ b
 */
template <typename Func>
void for_each_subset_between(int a, int b, const Func &f){
  int x = b^(a&b);
  for(int t=x; ; t=(t-1)&x){
    f(t|a);
    if(t==0) break;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

