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


# :warning: Eratosthenesの篩

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/eratosthenes_sieve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00




## Required by

* :warning: <a href="../mobius_function.cpp.html">Möbius関数</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bitset>

/**
 * @title Eratosthenesの篩
 */
namespace eratosthenes_sieve{
  constexpr int MAX = 1000000;
  std::bitset<MAX+1> is_prime;

  __attribute__((constructor)) void init(){
    is_prime.flip();
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2; i <= MAX; ++i){
      if(is_prime[i]){
        for(int j = 2*i; j <= MAX; j += i){
          is_prime[j] = false;
        }
      }
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/eratosthenes_sieve.cpp"
#include <bitset>

/**
 * @title Eratosthenesの篩
 */
namespace eratosthenes_sieve{
  constexpr int MAX = 1000000;
  std::bitset<MAX+1> is_prime;

  __attribute__((constructor)) void init(){
    is_prime.flip();
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2; i <= MAX; ++i){
      if(is_prime[i]){
        for(int j = 2*i; j <= MAX; j += i){
          is_prime[j] = false;
        }
      }
    }
  }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

