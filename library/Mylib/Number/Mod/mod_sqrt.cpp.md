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


# :x: Mod sqrt

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#795ab137908c82fc28acbcffe5b1c757">Mylib/Number/Mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Mod/mod_sqrt.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00




## Operations

- `mod_sqrt(a, p)`
	- $x ^ 2 = a \pmod p$を満たす`x`を求める。

## Requirements

## Notes

## Problems

## References

- [https://ja.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E5%89%B0%E4%BD%99%E3%81%AE%E7%9B%B8%E4%BA%92%E6%B3%95%E5%89%87](https://ja.wikipedia.org/wiki/%E5%B9%B3%E6%96%B9%E5%89%B0%E4%BD%99%E3%81%AE%E7%9B%B8%E4%BA%92%E6%B3%95%E5%89%87)
- [https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a](https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a)
- [https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm](https://en.wikipedia.org/wiki/Tonelli%E2%80%93Shanks_algorithm)


## Depends on

* :x: <a href="mod_power.cpp.html">Mod power</a>


## Verified with

* :x: <a href="../../../../verify/test/yosupo-judge/sqrt_mod/main.test.cpp.html">test/yosupo-judge/sqrt_mod/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <random>
#include <optional>
#include "Mylib/Number/Mod/mod_power.cpp"

/**
 * @title Mod sqrt
 * @docs mod_sqrt.md
 */
std::optional<int64_t> mod_sqrt(int64_t a, int64_t p){
  if(p == 2) return a % 2;
  if(a == 0) return 0;

  int64_t b = power(a, (p - 1) / 2, p);

  if(b == p - 1) return {};
  if(p % 4 == 3) return power(a, (p + 1) / 4, p);

  int64_t q = p - 1, s = 0;
  while(q % 2 == 0){
    q /= 2;
    s += 1;
  }

  static std::mt19937_64 rand(time(0));
  std::uniform_int_distribution<> dist(0, p - 1);

  int64_t z;
  while(1){
    z = dist(rand);
    if(power(z, (p - 1) / 2, p) == p - 1) break;
  }

  int64_t m = s;
  int64_t c = power(z, q, p);
  int64_t t = power(a, q, p);
  int64_t r = power(a, (q + 1) / 2, p);

  while(1){
    if(t == 0) return 0;
    if(t == 1) return r;

    int i = 1;
    for(int64_t T = t; i < m; ++i){
      (T *= T) %= p;
      if(T == 1) break;
    }

    int64_t b = power(c, 1LL << (m - i - 1), p);

    m = i;
    c = b * b % p;
    (t *= b * b % p) %= p;
    (r *= b) %= p;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Mod/mod_sqrt.cpp"
#include <random>
#include <optional>
#line 2 "Mylib/Number/Mod/mod_power.cpp"
#include <cstdint>

/**
 * @title Mod power
 * @docs mod_power.md
 */
int64_t power(int64_t n, int64_t p, int64_t m){
  int64_t ret = 1;
  while(p > 0){
    if(p & 1) (ret *= n) %= m;
    (n *= n) %= m;
    p >>= 1;
  }
  return ret;
}
#line 5 "Mylib/Number/Mod/mod_sqrt.cpp"

/**
 * @title Mod sqrt
 * @docs mod_sqrt.md
 */
std::optional<int64_t> mod_sqrt(int64_t a, int64_t p){
  if(p == 2) return a % 2;
  if(a == 0) return 0;

  int64_t b = power(a, (p - 1) / 2, p);

  if(b == p - 1) return {};
  if(p % 4 == 3) return power(a, (p + 1) / 4, p);

  int64_t q = p - 1, s = 0;
  while(q % 2 == 0){
    q /= 2;
    s += 1;
  }

  static std::mt19937_64 rand(time(0));
  std::uniform_int_distribution<> dist(0, p - 1);

  int64_t z;
  while(1){
    z = dist(rand);
    if(power(z, (p - 1) / 2, p) == p - 1) break;
  }

  int64_t m = s;
  int64_t c = power(z, q, p);
  int64_t t = power(a, q, p);
  int64_t r = power(a, (q + 1) / 2, p);

  while(1){
    if(t == 0) return 0;
    if(t == 1) return r;

    int i = 1;
    for(int64_t T = t; i < m; ++i){
      (T *= T) %= p;
      if(T == 1) break;
    }

    int64_t b = power(c, 1LL << (m - i - 1), p);

    m = i;
    c = b * b % p;
    (t *= b * b % p) %= p;
    (r *= b) %= p;
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

