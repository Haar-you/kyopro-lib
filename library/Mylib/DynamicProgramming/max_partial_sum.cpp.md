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


# :warning: Maximum subarray problem

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3a96c66483797c15eff4c0c3d8733619">Mylib/DynamicProgramming</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DynamicProgramming/max_partial_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Maximum subarray problem
 * @docs max_partial_sum.md
 */
namespace haar_lib {
  template <typename T>
  T max_partial_sum(const std::vector<T> &v){
    T t = v[0], ret = t;
    for(int i = 1; i < (int)v.size(); ++i){
      t = std::max(t + v[i], v[i]);
      ret = std::max(ret, t);
    }
    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DynamicProgramming/max_partial_sum.cpp"
#include <vector>
#include <algorithm>

/**
 * @title Maximum subarray problem
 * @docs max_partial_sum.md
 */
namespace haar_lib {
  template <typename T>
  T max_partial_sum(const std::vector<T> &v){
    T t = v[0], ret = t;
    for(int i = 1; i < (int)v.size(); ++i){
      t = std::max(t + v[i], v[i]);
      ret = std::max(ret, t);
    }
    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

