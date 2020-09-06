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


# :x: Kth root integer

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/kth_root_integer.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00




## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/kth_root_integer/main.test.cpp.html">test/yosupo-judge/kth_root_integer/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cassert>
#include <cstdint>

/**
 * @title Kth root integer
 * @docs kth_root_integer.md
 */
uint64_t kth_root(uint64_t a, int k){
  assert(k >= 1);
  if(k == 1) return a;
  if(a == 1) return 1;

  uint64_t lb = 0, ub = a;

  auto check =
    [](uint64_t a, int k, uint64_t n){
      uint64_t r = 1;

      while(k > 0){
        if(k & 1){
          if(__builtin_umulll_overflow(r, a, (unsigned long long int*)&r)) return false;
        }
        if(__builtin_umulll_overflow(a, a, (unsigned long long int*)&a) and k > 1) return false;
        k >>= 1;
      }

      return r <= n;
    };

  while(ub - lb > 1){
    uint64_t mid = lb + (ub - lb) / 2;

    if(check(mid, k, a)){
      lb = mid;
    }else{
      ub = mid;
    }
  }

  return lb;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/kth_root_integer.cpp"
#include <cassert>
#include <cstdint>

/**
 * @title Kth root integer
 * @docs kth_root_integer.md
 */
uint64_t kth_root(uint64_t a, int k){
  assert(k >= 1);
  if(k == 1) return a;
  if(a == 1) return 1;

  uint64_t lb = 0, ub = a;

  auto check =
    [](uint64_t a, int k, uint64_t n){
      uint64_t r = 1;

      while(k > 0){
        if(k & 1){
          if(__builtin_umulll_overflow(r, a, (unsigned long long int*)&r)) return false;
        }
        if(__builtin_umulll_overflow(a, a, (unsigned long long int*)&a) and k > 1) return false;
        k >>= 1;
      }

      return r <= n;
    };

  while(ub - lb > 1){
    uint64_t mid = lb + (ub - lb) / 2;

    if(check(mid, k, a)){
      lb = mid;
    }else{
      ub = mid;
    }
  }

  return lb;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

