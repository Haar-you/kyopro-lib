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


# :warning: Mylib/AlgebraicStructure/Monoid/transformation_monoid.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/transformation_monoid.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 06:18:07+09:00


* see: <a href="https://codeforces.com/contest/911/submission/63237734 (TLE)">https://codeforces.com/contest/911/submission/63237734 (TLE)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <array>

/**
 * @see https://codeforces.com/contest/911/submission/63237734 (TLE)
 */
template <size_t N>
struct TransformationMonoid{
  using value_type = std::array<int,N>;

  inline static value_type id(){
    value_type ret;
    for(int i = 0; i < (int)N; ++i) ret[i] = i;
    return ret;
  }

  inline static value_type op(const value_type &a, const value_type &b){
    value_type ret;
    for(int i = 0; i < (int)N; ++i) ret[i] = a[b[i]];
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/transformation_monoid.cpp"
#include <array>

/**
 * @see https://codeforces.com/contest/911/submission/63237734 (TLE)
 */
template <size_t N>
struct TransformationMonoid{
  using value_type = std::array<int,N>;

  inline static value_type id(){
    value_type ret;
    for(int i = 0; i < (int)N; ++i) ret[i] = i;
    return ret;
  }

  inline static value_type op(const value_type &a, const value_type &b){
    value_type ret;
    for(int i = 0; i < (int)N; ++i) ret[i] = a[b[i]];
    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

