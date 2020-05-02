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


# :heavy_check_mark: 文字列のsplit関数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d75653ebf9facf6e669959c8c0d9cbcf">Mylib/String</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/String/split.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1300/main.test.cpp.html">test/aoj/1300/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <string>
#include <vector>

/**
 * @title 文字列のsplit関数
 * @docs split.md
 */
auto split(const std::string &s, const std::string &delim){
  std::vector<std::string> ret;

  size_t i = 0;
  while(1){
    size_t j = s.find(delim, i);
    if(j == std::string::npos) break;

    ret.push_back(s.substr(i,j-i));

    i = j + delim.size();
  }

  ret.push_back(s.substr(i,s.size()-i));

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/String/split.cpp"
#include <string>
#include <vector>

/**
 * @title 文字列のsplit関数
 * @docs split.md
 */
auto split(const std::string &s, const std::string &delim){
  std::vector<std::string> ret;

  size_t i = 0;
  while(1){
    size_t j = s.find(delim, i);
    if(j == std::string::npos) break;

    ret.push_back(s.substr(i,j-i));

    i = j + delim.size();
  }

  ret.push_back(s.substr(i,s.size()-i));

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

