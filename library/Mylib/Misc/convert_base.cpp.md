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


# :warning: 進数変換

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/convert_base.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 進数変換
 * @docs convert_base.md
 */
std::vector<int64_t> convert_base_to(int64_t val, int64_t base){
  if(val == 0) return {0};

  std::vector<int64_t> ret;
  while(val){
    if(val < base){
      ret.push_back(val);
      break;
    }
    ret.push_back(val % base);
    val /= base;
  }
 
  return ret;
}

int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base){
  int64_t ret = 0;
  for(auto it = val.rbegin(); it != val.rend(); ++it){
    (ret *= base) += *it;
  }

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/convert_base.cpp"
#include <vector>

/**
 * @title 進数変換
 * @docs convert_base.md
 */
std::vector<int64_t> convert_base_to(int64_t val, int64_t base){
  if(val == 0) return {0};

  std::vector<int64_t> ret;
  while(val){
    if(val < base){
      ret.push_back(val);
      break;
    }
    ret.push_back(val % base);
    val /= base;
  }
 
  return ret;
}

int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base){
  int64_t ret = 0;
  for(auto it = val.rbegin(); it != val.rend(); ++it){
    (ret *= base) += *it;
  }

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
