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


# :heavy_check_mark: test/yukicoder/843/main.eratosthenes.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#05b6faf184ccb3df7524a3ce68064b76">test/yukicoder/843</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/843/main.eratosthenes.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-09 17:11:56+09:00


* see: <a href="https://yukicoder.me/problems/no/843">https://yukicoder.me/problems/no/843</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Prime/eratosthenes_sieve.cpp.html">Eratosthenesの篩</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/843"

#include <iostream>
#include "Mylib/Number/Prime/eratosthenes_sieve.cpp"

using P = EratosthenesSieve<500000>;

int main(){
  P::init();
  
  int N; std::cin >> N;

  int64_t ans = 0;

  if(N >= 2){
    ans += 1;

    int t = 0;
    for(int64_t r = 3; r <= N; ++r){
      int64_t q = r * r - 2;
      if(q <= N and P::is_prime[r] and P::is_prime[q]) ++t;
    }

    ans += t * 2;
  }
  
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yukicoder/843/main.eratosthenes.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/843"

#include <iostream>
#line 2 "Mylib/Number/Prime/eratosthenes_sieve.cpp"
#include <bitset>

/**
 * @title Eratosthenesの篩
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
#line 5 "test/yukicoder/843/main.eratosthenes.test.cpp"

using P = EratosthenesSieve<500000>;

int main(){
  P::init();
  
  int N; std::cin >> N;

  int64_t ans = 0;

  if(N >= 2){
    ans += 1;

    int t = 0;
    for(int64_t r = 3; r <= N; ++r){
      int64_t q = r * r - 2;
      if(q <= N and P::is_prime[r] and P::is_prime[q]) ++t;
    }

    ans += t * 2;
  }
  
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
