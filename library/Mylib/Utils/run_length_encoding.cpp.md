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


# :warning: Run length encoding

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cf1ec978dae666792e23e53a3672d204">Mylib/Utils</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Utils/run_length_encoding.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 20:11:20+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <utility>

/**
 * @title Run length encoding
 * @docs run_length_encoding.md
 */
template <typename Container, typename T = typename Container::value_type>
auto run_length_encoding(const Container &v){
  std::vector<std::pair<T,int64_t>> ret;

  for(auto &x : v){
    if(ret.empty()) ret.emplace_back(x, 1);
    else if(ret.back().first == x) ++ret.back().second;
    else ret.emplace_back(x, 1);
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Utils/run_length_encoding.cpp"
#include <vector>
#include <utility>

/**
 * @title Run length encoding
 * @docs run_length_encoding.md
 */
template <typename Container, typename T = typename Container::value_type>
auto run_length_encoding(const Container &v){
  std::vector<std::pair<T,int64_t>> ret;

  for(auto &x : v){
    if(ret.empty()) ret.emplace_back(x, 1);
    else if(ret.back().first == x) ++ret.back().second;
    else ret.emplace_back(x, 1);
  }

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

