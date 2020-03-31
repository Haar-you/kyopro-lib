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


# :warning: Mylib/Number/mobius_function.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/mobius_function.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 07:59:09+09:00


* see: <a href="https://codeforces.com/contest/1139/problem/D">https://codeforces.com/contest/1139/problem/D</a>
* see: <a href="https://en.wikipedia.org/wiki/M%C3%B6bius_function">https://en.wikipedia.org/wiki/M%C3%B6bius_function</a>


## Depends on

* :warning: <a href="Prime/eratosthenes_sieve.cpp.html">Mylib/Number/Prime/eratosthenes_sieve.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Number/Prime/eratosthenes_sieve.cpp"

/**
 * @see https://codeforces.com/contest/1139/problem/D
 * @see https://en.wikipedia.org/wiki/M%C3%B6bius_function
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
#line 4 "Mylib/Number/mobius_function.cpp"

/**
 * @see https://codeforces.com/contest/1139/problem/D
 * @see https://en.wikipedia.org/wiki/M%C3%B6bius_function
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

