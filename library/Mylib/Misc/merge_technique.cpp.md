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


# :heavy_check_mark: Mylib/Misc/merge_technique.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/merge_technique.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-14 01:02:10+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.binomial_heap.test.cpp.html">test/aoj/2559/main.binomial_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.leftist_heap.test.cpp.html">test/aoj/2559/main.leftist_heap.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/2559/main.skew_heap.test.cpp.html">test/aoj/2559/main.skew_heap.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <set>
#include <utility>

/**
 * @docs merge_technique.md
 */
template <typename T>
void merge_technique(std::set<T> &res, std::set<T> &a, std::set<T> &b){
  if(a.size() > b.size()){
    for(const auto &x : b){
      a.insert(x);
    }
    std::swap(res, a);
  }else{
    for(const auto &x : a){
      b.insert(x);
    }
    std::swap(res, b);
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/merge_technique.cpp"
#include <set>
#include <utility>

/**
 * @docs merge_technique.md
 */
template <typename T>
void merge_technique(std::set<T> &res, std::set<T> &a, std::set<T> &b){
  if(a.size() > b.size()){
    for(const auto &x : b){
      a.insert(x);
    }
    std::swap(res, a);
  }else{
    for(const auto &x : a){
      b.insert(x);
    }
    std::swap(res, b);
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

