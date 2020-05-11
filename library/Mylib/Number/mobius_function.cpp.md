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


# :warning: Möbius関数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/mobius_function.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #548 (Div. 2) D. Steps to One](https://codeforces.com/contest/1139/problem/D)

## References

- [https://en.wikipedia.org/wiki/M%C3%B6bius_function](https://en.wikipedia.org/wiki/M%C3%B6bius_function)


## Depends on

* :heavy_check_mark: <a href="Prime/eratosthenes_sieve.cpp.html">Eratosthenesの篩</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Number/Prime/eratosthenes_sieve.cpp"

/**
 * @title Möbius関数
 * @docs mobius_function.md
 */
std::vector<int> mobius_function(int n){
  std::vector<int> ret(n+1);
  std::vector<int> ps;

  ret[1] = 1;

  for(int i = 2; i <= n; ++i){
    if(eratosthenes_sieve::is_prime[i]){
      ps.push_back(i);
      ret[i] = -1;
    }
    for(auto &j : ps){
      if(i*j > n) break;
      if(i%j == 0) ret[i*j] = 0;
      else ret[i*j] = ret[i] * ret[j];
    }
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/mobius_function.cpp"
#include <vector>
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
#line 4 "Mylib/Number/mobius_function.cpp"

/**
 * @title Möbius関数
 * @docs mobius_function.md
 */
std::vector<int> mobius_function(int n){
  std::vector<int> ret(n+1);
  std::vector<int> ps;

  ret[1] = 1;

  for(int i = 2; i <= n; ++i){
    if(eratosthenes_sieve::is_prime[i]){
      ps.push_back(i);
      ret[i] = -1;
    }
    for(auto &j : ps){
      if(i*j > n) break;
      if(i%j == 0) ret[i*j] = 0;
      else ret[i*j] = ret[i] * ret[j];
    }
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

