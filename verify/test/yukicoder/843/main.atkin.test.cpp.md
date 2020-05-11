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


# :heavy_check_mark: test/yukicoder/843/main.atkin.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#05b6faf184ccb3df7524a3ce68064b76">test/yukicoder/843</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yukicoder/843/main.atkin.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="https://yukicoder.me/problems/no/843">https://yukicoder.me/problems/no/843</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Prime/atkin_sieve.cpp.html">Atkinの篩</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://yukicoder.me/problems/no/843"

#include <iostream>
#include "Mylib/Number/Prime/atkin_sieve.cpp"

using P = AtkinSieve<500000>;

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
#line 1 "test/yukicoder/843/main.atkin.test.cpp"
#define PROBLEM "https://yukicoder.me/problems/no/843"

#include <iostream>
#line 2 "Mylib/Number/Prime/atkin_sieve.cpp"
#include <bitset>
#include <vector>

/**
 * @title Atkinの篩
 * @docs atkin_sieve.md
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
#line 5 "test/yukicoder/843/main.atkin.test.cpp"

using P = AtkinSieve<500000>;

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

