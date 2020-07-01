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


# :heavy_check_mark: Convert base

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/convert_base.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yukicoder/499/main.test.cpp.html">test/yukicoder/499/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yukicoder/782/main.test.cpp.html">test/yukicoder/782/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title Convert base
 * @docs convert_base.md
 */
std::vector<int64_t> convert_base_to(int64_t val, int64_t base){
  if(val == 0) return {0};

  int b = std::abs(base);

  std::vector<int64_t> ret;
  while(val != 0){
    int r = val % b;
    if(r < 0) r += b;
    val = (val - r) / base;
    ret.push_back(r);
  }

  std::reverse(ret.begin(), ret.end());
  
  return ret;
}

int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base){
  int64_t ret = 0;
  for(auto it = val.begin(); it != val.end(); ++it){
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
#include <algorithm>

/**
 * @title Convert base
 * @docs convert_base.md
 */
std::vector<int64_t> convert_base_to(int64_t val, int64_t base){
  if(val == 0) return {0};

  int b = std::abs(base);

  std::vector<int64_t> ret;
  while(val != 0){
    int r = val % b;
    if(r < 0) r += b;
    val = (val - r) / base;
    ret.push_back(r);
  }

  std::reverse(ret.begin(), ret.end());
  
  return ret;
}

int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base){
  int64_t ret = 0;
  for(auto it = val.begin(); it != val.end(); ++it){
    (ret *= base) += *it;
  }

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

