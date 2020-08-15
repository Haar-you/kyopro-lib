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


# :x: test/yukicoder/843/main.eratosthenes.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#05b6faf184ccb3df7524a3ce68064b76">test/yukicoder/843</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/843/main.eratosthenes.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 08:51:20+09:00


* see: <a href="https://yukicoder.me/problems/no/843">https://yukicoder.me/problems/no/843</a>


## Depends on

* :x: <a href="../../../../library/Mylib/Number/Prime/eratosthenes_sieve.cpp.html">Sieve of Eratosthenes</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/843"

#include <iostream>
#include "Mylib/Number/Prime/eratosthenes_sieve.cpp"

int main(){
  EratosthenesSieve is_prime(500000);
  
  int N; std::cin >> N;

  int64_t ans = 0;

  if(N >= 2){
    ans += 1;

    int t = 0;
    for(int64_t r = 3; r <= N; ++r){
      int64_t q = r * r - 2;
      if(q <= N and is_prime(r) and is_prime(q)) ++t;
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
#include <vector>

/**
 * @title Sieve of Eratosthenes
 * @docs eratosthenes_sieve.md
 */
class EratosthenesSieve{
  std::vector<bool> is_prime;

public:
  EratosthenesSieve(int MAX): is_prime(MAX + 1){
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

  bool operator()(int i) const {
    return is_prime[i];
  }
};
#line 5 "test/yukicoder/843/main.eratosthenes.test.cpp"

int main(){
  EratosthenesSieve is_prime(500000);
  
  int N; std::cin >> N;

  int64_t ans = 0;

  if(N >= 2){
    ans += 1;

    int t = 0;
    for(int64_t r = 3; r <= N; ++r){
      int64_t q = r * r - 2;
      if(q <= N and is_prime(r) and is_prime(q)) ++t;
    }

    ans += t * 2;
  }
  
  std::cout << ans << std::endl;

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

