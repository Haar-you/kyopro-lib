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


# :warning: Mylib/AlgebraicStructure/Monoid/with_count.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/with_count.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-28 03:01:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>

/**
 * @docs with_count.md
 */
template <typename Monoid>
struct WithCount{
  using value_type = std::pair<typename Monoid::value_type, int64_t>;

  static value_type id(){
    return {Monoid::id(), 1};
  }

  static value_type op(const value_type &a, const value_type &b){
    if(a.first == b.first) return {a.first, a.second + b.second};
    if(Monoid::op(a.first, b.first) == a.first) return a;
    else return b;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/with_count.cpp"
#include <utility>

/**
 * @docs with_count.md
 */
template <typename Monoid>
struct WithCount{
  using value_type = std::pair<typename Monoid::value_type, int64_t>;

  static value_type id(){
    return {Monoid::id(), 1};
  }

  static value_type op(const value_type &a, const value_type &b){
    if(a.first == b.first) return {a.first, a.second + b.second};
    if(Monoid::op(a.first, b.first) == a.first) return a;
    else return b;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

