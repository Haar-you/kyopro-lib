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


# :x: Tetration

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/tetration.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-16 23:16:56+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://kopricky.github.io/code/Computation_Advanced/tetration.html](https://kopricky.github.io/code/Computation_Advanced/tetration.html)


## Depends on

* :x: <a href="euler_phi_function.cpp.html">Euler's totient function</a>


## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/tetration_mod/main.test.cpp.html">test/yosupo-judge/tetration_mod/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "Mylib/Number/euler_phi_function.cpp"

/**
 * @title Tetration
 * @docs tetration.md
 */
int tetration(int64_t a, int64_t b, int64_t m){
  auto rec =
    [](auto &rec, int64_t a, int64_t b, int64_t m) -> int {
      if(b == 1) return a % m;
      if(b == 0) return 1 % m;
      if(b == 2){
        bool c = a >= m;
        int64_t ret = 1;
        int64_t p = a;
        a %= m;

        while(p > 0){
          if(p & 1) if((ret *= a) >= m) ret %= m, c = true;
          if((a *= a) >= m) a %= m, c = true;
          p >>= 1;
        }

        if(c) ret += m;
        return ret;
      }
      if(a == 0) return b % 2 == 1 ? 0 : 1;
      if(m == 1) return 1;
      
      int phi = totient(m);
      int p = rec(rec, a, b-1, phi);

      bool c = p >= phi;
      int64_t ret = 1;

      while(p > 0){
        if(p & 1) if((ret *= a) >= m) ret %= m, c = true;
        if((a *= a) >= m) a %= m, c = true;
        p >>= 1;
      }

      if(c) ret += m;
      return ret;
    };

  return rec(rec, a, b, m) % m;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/tetration.cpp"

#line 2 "Mylib/Number/euler_phi_function.cpp"

/**
 * @title Euler's totient function
 * @docs euler_phi_function.md
 */
int64_t totient(int64_t n){
  int64_t ret = n;

  for(int64_t i = 2; i * i <= n; ++i){
    if(n % i == 0){
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }

  if(n != 1) ret -= ret / n;

  return ret;
}
#line 4 "Mylib/Number/tetration.cpp"

/**
 * @title Tetration
 * @docs tetration.md
 */
int tetration(int64_t a, int64_t b, int64_t m){
  auto rec =
    [](auto &rec, int64_t a, int64_t b, int64_t m) -> int {
      if(b == 1) return a % m;
      if(b == 0) return 1 % m;
      if(b == 2){
        bool c = a >= m;
        int64_t ret = 1;
        int64_t p = a;
        a %= m;

        while(p > 0){
          if(p & 1) if((ret *= a) >= m) ret %= m, c = true;
          if((a *= a) >= m) a %= m, c = true;
          p >>= 1;
        }

        if(c) ret += m;
        return ret;
      }
      if(a == 0) return b % 2 == 1 ? 0 : 1;
      if(m == 1) return 1;
      
      int phi = totient(m);
      int p = rec(rec, a, b-1, phi);

      bool c = p >= phi;
      int64_t ret = 1;

      while(p > 0){
        if(p & 1) if((ret *= a) >= m) ret %= m, c = true;
        if((a *= a) >= m) a %= m, c = true;
        p >>= 1;
      }

      if(c) ret += m;
      return ret;
    };

  return rec(rec, a, b, m) % m;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

