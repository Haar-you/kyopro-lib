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


# :warning: Prime factorization (Sieve)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/prime_factorize_sieve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 07:08:00+09:00




## Operations

- `PrimeFactorize(int N)`
	- `p[i]` = (`i`の最小の素因数)
	- Time complexity $O(N log N)$

- `factorize(int N)`
	- `N`の素因数を昇順に列挙する。
	- 素因数の個数だけループが回る。


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cstdint>

/**
 * @title Prime factorization (Sieve)
 * @docs prime_factorize_sieve.md
 */
namespace haar_lib {
  struct prime_factorize_sieve {
    std::vector<int> p;

    prime_factorize_sieve(int N): p(N + 1){
      for(int i = 2; i <= N; ++i){
        if(p[i] != 0) continue;
        for(int j = i; j <= N; j += i){
          if(p[j] == 0) p[j] = i;
        }
      }
    }

    auto factorize(int N){
      std::vector<int64_t> ret;

      while(N > 1){
        ret.push_back(p[N]);
        N /= p[N];
      }

      return ret;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/prime_factorize_sieve.cpp"
#include <vector>
#include <cstdint>

/**
 * @title Prime factorization (Sieve)
 * @docs prime_factorize_sieve.md
 */
namespace haar_lib {
  struct prime_factorize_sieve {
    std::vector<int> p;

    prime_factorize_sieve(int N): p(N + 1){
      for(int i = 2; i <= N; ++i){
        if(p[i] != 0) continue;
        for(int j = i; j <= N; j += i){
          if(p[j] == 0) p[j] = i;
        }
      }
    }

    auto factorize(int N){
      std::vector<int64_t> ret;

      while(N > 1){
        ret.push_back(p[N]);
        N /= p[N];
      }

      return ret;
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
