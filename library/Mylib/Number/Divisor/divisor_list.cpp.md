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


# :heavy_check_mark: 約数列挙

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e1d7bebd3991495167778e37d1d75d40">Mylib/Number/Divisor</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Divisor/divisor_list.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/ITP1_3_D/main.test.cpp.html">test/aoj/ITP1_3_D/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 約数列挙
 * @docs divisor_list.md
 */
std::vector<std::int64_t> divisor_list(std::int64_t n){
  std::vector<std::int64_t> temp, ret;

  {
    std::int64_t i;
    for(i = 1LL; i * i < n; ++i){
      if(n%i == 0){
        temp.push_back(n / i);
        ret.push_back(i);
      }
    }
    if(i * i == n) ret.push_back(i);
  }

  std::reverse(temp.begin(), temp.end());
  ret.insert(ret.end(), temp.begin(), temp.end());
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Divisor/divisor_list.cpp"
#include <vector>
#include <algorithm>

/**
 * @title 約数列挙
 * @docs divisor_list.md
 */
std::vector<std::int64_t> divisor_list(std::int64_t n){
  std::vector<std::int64_t> temp, ret;

  {
    std::int64_t i;
    for(i = 1LL; i * i < n; ++i){
      if(n%i == 0){
        temp.push_back(n / i);
        ret.push_back(i);
      }
    }
    if(i * i == n) ret.push_back(i);
  }

  std::reverse(temp.begin(), temp.end());
  ret.insert(ret.end(), temp.begin(), temp.end());
  
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

