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


# :x: Binary GCD

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/binary_gcd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Verified with

* :x: <a href="../../../verify/test/aoj/NTL_1_C/main.test.cpp.html">test/aoj/NTL_1_C/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <utility>
#include <cmath>

/**
 * @title Binary GCD
 * @docs binary_gcd.md
 */
namespace haar_lib {
  int64_t binary_gcd(int64_t a, int64_t b){
    int64_t g = 1;

    while(1){
      if(a > b) std::swap(a, b);

      if(a == 0){
        break;
      }else{
        if((a & 1) == 0 and (b & 1) == 0){
          a >>= 1;
          b >>= 1;
          g <<= 1;
        }else if((a & 1) == 0){
          a >>= 1;
        }else if((b & 1) == 0){
          b >>= 1;
        }else{
          int64_t t = std::abs(a - b) >> 1;
          b = t;
        }
      }
    }

    return g * b;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/binary_gcd.cpp"
#include <utility>
#include <cmath>

/**
 * @title Binary GCD
 * @docs binary_gcd.md
 */
namespace haar_lib {
  int64_t binary_gcd(int64_t a, int64_t b){
    int64_t g = 1;

    while(1){
      if(a > b) std::swap(a, b);

      if(a == 0){
        break;
      }else{
        if((a & 1) == 0 and (b & 1) == 0){
          a >>= 1;
          b >>= 1;
          g <<= 1;
        }else if((a & 1) == 0){
          a >>= 1;
        }else if((b & 1) == 0){
          b >>= 1;
        }else{
          int64_t t = std::abs(a - b) >> 1;
          b = t;
        }
      }
    }

    return g * b;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

