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


# :x: Count coprime

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/count_coprime.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `count_coprime(n, m)`
	- `[1, n]`を満たす自然数で`m`と互いに素であるものの個数

## Requirements

## Notes

## Problems

## References


## Depends on

* :x: <a href="prime_factorize.cpp.html">Prime factorization</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/NTL_1_D/main.test.cpp.html">test/aoj/NTL_1_D/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "Mylib/Number/Prime/prime_factorize.cpp"

/**
 * @title Count coprime
 * @docs count_coprime.md
 */
int64_t count_coprime(int64_t n, int64_t m){
  const auto p = prime_factorize(m);
  int k = p.size();

  int64_t ret = 0;

  for(int i = 0; i < 1<<k; ++i){
    int64_t s = 1;
    
    for(int j = 0; j < k; ++j){
      if(i & (1 << j)) s *= p[j].first;
    }

    if(__builtin_popcount(i) % 2 == 1) ret -= n / s;
    else ret += n / s;
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/count_coprime.cpp"

#line 2 "Mylib/Number/Prime/prime_factorize.cpp"
#include <vector>
#include <utility>

/**
 * @title Prime factorization
 * @docs prime_factorize.md
 */
auto prime_factorize(int64_t n){
  std::vector<std::pair<int64_t,int64_t>> ret;
  for(int64_t i = 2LL; i * i <= n; ++i){
    if(n % i == 0){
      int64_t c = 0;
      while(n % i == 0){
        n /= i;
        ++c;
      }
      ret.emplace_back(i, c);
    }
  }
  if(n != 1) ret.emplace_back(n, 1);
  return ret;
}
#line 4 "Mylib/Number/Prime/count_coprime.cpp"

/**
 * @title Count coprime
 * @docs count_coprime.md
 */
int64_t count_coprime(int64_t n, int64_t m){
  const auto p = prime_factorize(m);
  int k = p.size();

  int64_t ret = 0;

  for(int i = 0; i < 1<<k; ++i){
    int64_t s = 1;
    
    for(int j = 0; j < k; ++j){
      if(i & (1 << j)) s *= p[j].first;
    }

    if(__builtin_popcount(i) % 2 == 1) ret -= n / s;
    else ret += n / s;
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

