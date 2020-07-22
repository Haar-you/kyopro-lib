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


# :heavy_check_mark: Prime factorization (Pollard's rho algorithm)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/pollard_rho.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-08 12:08:32+09:00




## Depends on

* :heavy_check_mark: <a href="../../Misc/int128.cpp.html">128-bit int</a>
* :heavy_check_mark: <a href="miller_rabin.cpp.html">Primality test (Miller-Rabin algorithm)</a>


## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yosupo-judge/factorize/main.test.cpp.html">test/yosupo-judge/factorize/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <optional>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <cassert>
#include "Mylib/Misc/int128.cpp"
#include "Mylib/Number/Prime/miller_rabin.cpp"

/**
 * @title Prime factorization (Pollard's rho algorithm)
 * @docs pollard_rho.md
 */
struct PollardRho{
  static int128_t f(int128_t x){
    return x * x + 1;
  }

  static std::optional<int64_t> rho(int64_t n){
    int64_t x = 2, y = 2, d = 1;

    while(d == 1){
      x = f(x) % n;
      y = f(f(y) % n) % n;
      d = std::gcd(std::abs(x - y), n);
      if(d == n) return {};
    }

    return {d};
  }

  static auto prime_factorize(int64_t n){
    std::vector<std::pair<int64_t,int64_t>> ret;

    for(int i = 2; i <= 1000000; ++i){
      if(n % i == 0){
        int c = 0;
        while(n % i == 0){
          n /= i;
          ++c;
        }
        ret.emplace_back(i, c);
      }
      if(i > n) break;
    }
  
    while(n > 1){
      if(MillerRabin::is_prime(n)){
        ret.emplace_back(n, 1);
        break;
      }
    
      auto res = rho(n);
      if(not res){
        assert(false);
      }

      auto r = *res;
      if(r == 1) break;

      int c = 0;
      while(n % r == 0){
        n /= r;
        ++c;
      }
    
      ret.emplace_back(r, c);
    }

    std::sort(ret.begin(), ret.end());
  
    return ret;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/pollard_rho.cpp"
#include <optional>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <cassert>
#line 2 "Mylib/Misc/int128.cpp"

/**
 * @title 128-bit int
 * @docs int128.md
 */
#ifdef __SIZEOF_INT128__
using uint128_t = __uint128_t;
using int128_t = __int128_t;
#else
#include <boost/multiprecision/cpp_int.hpp>
using uint128_t = boost::multiprecision::uint128_t;
using int128_t = boost::multiprecision::int128_t;
#endif
#line 3 "Mylib/Number/Prime/miller_rabin.cpp"

/**
 * @title Primality test (Miller-Rabin algorithm)
 * @docs miller_rabin.md
 */
class MillerRabin{
  static uint128_t power(uint128_t a, uint128_t b, uint128_t p){
    uint128_t ret = 1;

    while(b > 0){
      if(b & 1) ret = ret * a % p;
      a = a * a % p;
      b >>= 1;
    }
    
    return ret;
  }
  
  static bool is_composite(uint64_t a, uint64_t p, int s, uint64_t d){
    uint128_t x = power(a, d, p);

    if(x == 1) return false;

    for(int i = 0; i < s; ++i){
      if(x == p-1) return false;
      x = x * x % p;
    }

    return true;
  }

public:
  static bool is_prime(uint64_t n){
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    int s = 0;
    uint64_t d = n-1;
    while((d & 1) == 0){
      s += 1;
      d >>= 1;
    }

    if(n < 4759123141){
      for(uint64_t x : {2, 7, 61}){
        if(x < n and is_composite(x, n, s, d)) return false;
      }

      return true;
    }

    for(uint64_t x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
      if(x < n and is_composite(x, n, s, d)) return false;
    }
    
    return true;
  }
};
#line 10 "Mylib/Number/Prime/pollard_rho.cpp"

/**
 * @title Prime factorization (Pollard's rho algorithm)
 * @docs pollard_rho.md
 */
struct PollardRho{
  static int128_t f(int128_t x){
    return x * x + 1;
  }

  static std::optional<int64_t> rho(int64_t n){
    int64_t x = 2, y = 2, d = 1;

    while(d == 1){
      x = f(x) % n;
      y = f(f(y) % n) % n;
      d = std::gcd(std::abs(x - y), n);
      if(d == n) return {};
    }

    return {d};
  }

  static auto prime_factorize(int64_t n){
    std::vector<std::pair<int64_t,int64_t>> ret;

    for(int i = 2; i <= 1000000; ++i){
      if(n % i == 0){
        int c = 0;
        while(n % i == 0){
          n /= i;
          ++c;
        }
        ret.emplace_back(i, c);
      }
      if(i > n) break;
    }
  
    while(n > 1){
      if(MillerRabin::is_prime(n)){
        ret.emplace_back(n, 1);
        break;
      }
    
      auto res = rho(n);
      if(not res){
        assert(false);
      }

      auto r = *res;
      if(r == 1) break;

      int c = 0;
      while(n % r == 0){
        n /= r;
        ++c;
      }
    
      ret.emplace_back(r, c);
    }

    std::sort(ret.begin(), ret.end());
  
    return ret;
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

