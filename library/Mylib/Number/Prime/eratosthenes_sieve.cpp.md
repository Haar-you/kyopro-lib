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


# :x: Sieve of Eratosthenes

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/eratosthenes_sieve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Verified with

* :x: <a href="../../../../verify/test/yukicoder/843/main.eratosthenes.test.cpp.html">test/yukicoder/843/main.eratosthenes.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Sieve of Eratosthenes
 * @docs eratosthenes_sieve.md
 */
class EratosthenesSieve {
  std::vector<bool> is_prime;

public:
  EratosthenesSieve(int MAX): is_prime(MAX + 1){
    is_prime.flip();
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= MAX; ++i){
      if(is_prime[i]){
        for(int j = 2 * i; j <= MAX; j += i){
          is_prime[j] = false;
        }
      }
    }
  }

  bool operator()(int i) const {
    return is_prime[i];
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/eratosthenes_sieve.cpp"
#include <vector>

/**
 * @title Sieve of Eratosthenes
 * @docs eratosthenes_sieve.md
 */
class EratosthenesSieve {
  std::vector<bool> is_prime;

public:
  EratosthenesSieve(int MAX): is_prime(MAX + 1){
    is_prime.flip();
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= MAX; ++i){
      if(is_prime[i]){
        for(int j = 2 * i; j <= MAX; j += i){
          is_prime[j] = false;
        }
      }
    }
  }

  bool operator()(int i) const {
    return is_prime[i];
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

