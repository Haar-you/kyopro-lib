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


# :warning: Segmented sieve

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/segmented_sieve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00




## Operations

## Requirements

- `Checker`は`sqrt(r)`以下の素数判定が可能である。

## Notes

## Problems

- [SPOJ PRIME1](https://www.spoj.com/problems/PRIME1/)

## References

- [http://www.prefield.com/algorithm/math/segment_sieve.html](http://www.prefield.com/algorithm/math/segment_sieve.html)


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cstdint>
#include <cassert>

/**
 * @title Segmented sieve
 * @docs segmented_sieve.md
 */
template <typename Checker>
class SegmentedSieve {
  int L, R, D;
  std::vector<bool> data;

public:
  // [l, r]
  SegmentedSieve(int l, int r, Checker is_prime): L(l), R(r), D(R - L + 1), data(D, true){
    std::vector<int> primes;
    for(int64_t i = 2; i * i <= R; ++i){
      if(is_prime(i)) primes.push_back(i);
    }

    for(int64_t i = 0; i < D; ++i){
      const int64_t x = L + i;

      if(x == 1){
        data[i] = false;
        continue;
      }

      for(auto p : primes){
        if(x == p) break;
        if(x % p == 0){
          data[i] = false;
          break;
        }
      }
    }
  }

  bool operator()(int i) const {
    assert(L <= i and i <= R);
    return data[i - L];
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/segmented_sieve.cpp"
#include <vector>
#include <cstdint>
#include <cassert>

/**
 * @title Segmented sieve
 * @docs segmented_sieve.md
 */
template <typename Checker>
class SegmentedSieve {
  int L, R, D;
  std::vector<bool> data;

public:
  // [l, r]
  SegmentedSieve(int l, int r, Checker is_prime): L(l), R(r), D(R - L + 1), data(D, true){
    std::vector<int> primes;
    for(int64_t i = 2; i * i <= R; ++i){
      if(is_prime(i)) primes.push_back(i);
    }

    for(int64_t i = 0; i < D; ++i){
      const int64_t x = L + i;

      if(x == 1){
        data[i] = false;
        continue;
      }

      for(auto p : primes){
        if(x == p) break;
        if(x % p == 0){
          data[i] = false;
          break;
        }
      }
    }
  }

  bool operator()(int i) const {
    assert(L <= i and i <= R);
    return data[i - L];
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

