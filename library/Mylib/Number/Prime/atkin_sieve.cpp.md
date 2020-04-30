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


# :heavy_check_mark: Atkinの篩

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/atkin_sieve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-09 17:11:56+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/yukicoder/843/main.atkin.test.cpp.html">test/yukicoder/843/main.atkin.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bitset>
#include <vector>

/**
 * @title Atkinの篩
 */
template <int MAX>
struct AtkinSieve{
  static std::bitset<MAX+1> is_prime;
  
  static void init(){
    for(int64_t i = 1; i * i <= MAX; ++i){
      for(int64_t j = 1; j * j <= MAX; ++j){
        {
          auto n = 4LL * i * i + j * j;
          if(n <= MAX and (n % 12 == 1 or n % 12 == 5)){
            is_prime[n] = not is_prime[n];
          }
        }
        {
          auto n = 3LL * i * i + j * j;
          if(n <= MAX and n % 12 == 7){
            is_prime[n] = not is_prime[n];
          }
        }
        if(i > j){
          auto n = 3LL * i * i - j * j;
          if(n <= MAX and n % 12 == 11){
            is_prime[n] = not is_prime[n];
          }
        }
      }
    }

    for(int64_t i = 5; i * i <= MAX; ++i){
      if(is_prime[i]){
        for(int64_t k = i * i, j = k; j <= MAX; j += k){
          is_prime[j] = false;
        }
      }
    }

    is_prime[2] = is_prime[3] = true;
  }
};

template <int MAX> std::bitset<MAX+1> AtkinSieve<MAX>::is_prime;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/atkin_sieve.cpp"
#include <bitset>
#include <vector>

/**
 * @title Atkinの篩
 */
template <int MAX>
struct AtkinSieve{
  static std::bitset<MAX+1> is_prime;
  
  static void init(){
    for(int64_t i = 1; i * i <= MAX; ++i){
      for(int64_t j = 1; j * j <= MAX; ++j){
        {
          auto n = 4LL * i * i + j * j;
          if(n <= MAX and (n % 12 == 1 or n % 12 == 5)){
            is_prime[n] = not is_prime[n];
          }
        }
        {
          auto n = 3LL * i * i + j * j;
          if(n <= MAX and n % 12 == 7){
            is_prime[n] = not is_prime[n];
          }
        }
        if(i > j){
          auto n = 3LL * i * i - j * j;
          if(n <= MAX and n % 12 == 11){
            is_prime[n] = not is_prime[n];
          }
        }
      }
    }

    for(int64_t i = 5; i * i <= MAX; ++i){
      if(is_prime[i]){
        for(int64_t k = i * i, j = k; j <= MAX; j += k){
          is_prime[j] = false;
        }
      }
    }

    is_prime[2] = is_prime[3] = true;
  }
};

template <int MAX> std::bitset<MAX+1> AtkinSieve<MAX>::is_prime;

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
