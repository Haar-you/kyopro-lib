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


# :warning: Zip function

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/zip.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 09:10:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <tuple>
#include <algorithm>

/**
 * @title Zip function
 * @docs zip.md
 */
template <typename ... Args>
auto zip(std::vector<Args> ... a){
  const int N = std::min({a.size() ...});
  std::vector<std::tuple<Args ...>> ret(N);

  for(int i = 0; i < N; ++i){
    ret[i] = std::make_tuple(a[i] ...);
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/zip.cpp"
#include <vector>
#include <tuple>
#include <algorithm>

/**
 * @title Zip function
 * @docs zip.md
 */
template <typename ... Args>
auto zip(std::vector<Args> ... a){
  const int N = std::min({a.size() ...});
  std::vector<std::tuple<Args ...>> ret(N);

  for(int i = 0; i < N; ++i){
    ret[i] = std::make_tuple(a[i] ...);
  }

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

