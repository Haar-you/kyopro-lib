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


# :warning: ends_with

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/ends_with.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-03 01:42:28+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <string>

/**
 * @title ends_with
 */
bool ends_with(const std::string &str, const std::string &suffix){
  if(str.size() < suffix.size()) return false;
  int n = str.size(), m = suffix.size();
  for(size_t i = 0; i < suffix.size(); ++i){
    if(str[n-1-i] != suffix[m-1-i]) return false;
  }
  return true;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/ends_with.cpp"
#include <string>

/**
 * @title ends_with
 */
bool ends_with(const std::string &str, const std::string &suffix){
  if(str.size() < suffix.size()) return false;
  int n = str.size(), m = suffix.size();
  for(size_t i = 0; i < suffix.size(); ++i){
    if(str[n-1-i] != suffix[m-1-i]) return false;
  }
  return true;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

