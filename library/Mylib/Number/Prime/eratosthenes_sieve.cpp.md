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


# :x: Eratosthenesの篩

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/eratosthenes_sieve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Required by

* :warning: <a href="../mobius_function.cpp.html">Möbius関数</a>


## Verified with

* :x: <a href="../../../../verify/test/yukicoder/843/main.eratosthenes.test.cpp.html">test/yukicoder/843/main.eratosthenes.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bitset>

/**
 * @title Eratosthenesの篩
 * @docs eratosthenes_sieve.md
 */
template <int MAX>
struct EratosthenesSieve{
  static std::bitset<MAX+1> is_prime;
  
  static void init(){
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
};

template <int MAX> std::bitset<MAX+1> EratosthenesSieve<MAX>::is_prime;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/eratosthenes_sieve.cpp"
#include <bitset>

/**
 * @title Eratosthenesの篩
 * @docs eratosthenes_sieve.md
 */
template <int MAX>
struct EratosthenesSieve{
  static std::bitset<MAX+1> is_prime;
  
  static void init(){
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
};

template <int MAX> std::bitset<MAX+1> EratosthenesSieve<MAX>::is_prime;

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

