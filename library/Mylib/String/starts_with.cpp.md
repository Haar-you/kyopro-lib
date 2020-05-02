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


# :warning: starts_with

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/starts_with.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title starts_with
 * @docs starts_with.md
 */
template <typename Container, typename T = typename Container::value_type>
bool starts_with(const Container &str, const Container &prefix){
  if(str.size() < prefix.size()) return false;
  for(size_t i = 0; i < prefix.size(); ++i){
    if(str[i] != prefix[i]) return false;
  }
  return true;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/starts_with.cpp"

/**
 * @title starts_with
 * @docs starts_with.md
 */
template <typename Container, typename T = typename Container::value_type>
bool starts_with(const Container &str, const Container &prefix){
  if(str.size() < prefix.size()) return false;
  for(size_t i = 0; i < prefix.size(); ++i){
    if(str[i] != prefix[i]) return false;
  }
  return true;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

