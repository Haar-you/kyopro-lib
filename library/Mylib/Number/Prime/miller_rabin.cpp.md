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


# :x: Primality test (Miller-Rabin algorithm)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/miller_rabin.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Depends on

* :x: <a href="../../Misc/int128.cpp.html">128-bit int</a>


## Required by

* :x: <a href="pollard_rho.cpp.html">Prime factorization (Pollard's rho algorithm)</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/factorize/main.test.cpp.html">test/yosupo-judge/factorize/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/3030/main.test.cpp.html">test/yukicoder/3030/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include <initializer_list>
#include "Mylib/Misc/int128.cpp"

/**
 * @title Primality test (Miller-Rabin algorithm)
 * @docs miller_rabin.md
 */
namespace haar_lib {
  namespace miller_rabin_impl {
    uint128_t power(uint128_t a, uint128_t b, uint128_t p){
      uint128_t ret = 1;

      while(b > 0){
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
      }

      return ret;
    }

    bool is_composite(uint64_t a, uint64_t p, int s, uint64_t d){
      uint128_t x = power(a, d, p);

      if(x == 1) return false;

      for(int i = 0; i < s; ++i){
        if(x == p - 1) return false;
        x = x * x % p;
      }

      return true;
    }
  }

  bool miller_rabin(uint64_t n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    int s = 0;
    uint64_t d = n - 1;
    while((d & 1) == 0){
      s += 1;
      d >>= 1;
    }

    if(n < 4759123141){
      for(uint64_t x : {2, 7, 61}){
        if(x < n and miller_rabin_impl::is_composite(x, n, s, d)) return false;
      }

      return true;
    }

    for(uint64_t x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
      if(x < n and miller_rabin_impl::is_composite(x, n, s, d)) return false;
    }

    return true;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/miller_rabin.cpp"
#include <cstdint>
#include <initializer_list>
#line 2 "Mylib/Misc/int128.cpp"

/**
 * @title 128-bit int
 * @docs int128.md
 */
namespace haar_lib {
#ifdef __SIZEOF_INT128__
  using uint128_t = __uint128_t;
  using int128_t = __int128_t;
#else
#include <boost/multiprecision/cpp_int.hpp>
  using uint128_t = boost::multiprecision::uint128_t;
  using int128_t = boost::multiprecision::int128_t;
#endif
}
#line 5 "Mylib/Number/Prime/miller_rabin.cpp"

/**
 * @title Primality test (Miller-Rabin algorithm)
 * @docs miller_rabin.md
 */
namespace haar_lib {
  namespace miller_rabin_impl {
    uint128_t power(uint128_t a, uint128_t b, uint128_t p){
      uint128_t ret = 1;

      while(b > 0){
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
      }

      return ret;
    }

    bool is_composite(uint64_t a, uint64_t p, int s, uint64_t d){
      uint128_t x = power(a, d, p);

      if(x == 1) return false;

      for(int i = 0; i < s; ++i){
        if(x == p - 1) return false;
        x = x * x % p;
      }

      return true;
    }
  }

  bool miller_rabin(uint64_t n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    int s = 0;
    uint64_t d = n - 1;
    while((d & 1) == 0){
      s += 1;
      d >>= 1;
    }

    if(n < 4759123141){
      for(uint64_t x : {2, 7, 61}){
        if(x < n and miller_rabin_impl::is_composite(x, n, s, d)) return false;
      }

      return true;
    }

    for(uint64_t x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
      if(x < n and miller_rabin_impl::is_composite(x, n, s, d)) return false;
    }

    return true;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

