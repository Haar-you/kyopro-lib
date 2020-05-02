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


# :x: test/yosupo-judge/sqrt_mod/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0a1953e1c2bd6e0f6d5a522af5f0929c">test/yosupo-judge/sqrt_mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/sqrt_mod/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="https://judge.yosupo.jp/problem/sqrt_mod">https://judge.yosupo.jp/problem/sqrt_mod</a>


## Depends on

* :question: <a href="../../../../library/Mylib/Number/Mod/mod_power.cpp.html">mod累乗</a>
* :x: <a href="../../../../library/Mylib/Number/Mod/mod_sqrt.cpp.html">平方剰余</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <iostream>
#include "Mylib/Number/Mod/mod_sqrt.cpp"

void solve(){
  int64_t Y, P; scanf("%lld%lld", &Y, &P);

  auto ans = mod_sqrt(Y, P).value_or(-1);
  printf("%lld\n", ans);
}

int main(){
  int T; scanf("%d", &T);
  while(T--) solve();
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/sqrt_mod/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <iostream>
#line 2 "Mylib/Number/Mod/mod_sqrt.cpp"
#include <random>
#include <optional>
#line 2 "Mylib/Number/Mod/mod_power.cpp"

/**
 * @title mod累乗
 * @docs mod_power.md
 */
int64_t power(int64_t n, int64_t p, int64_t m){
  int64_t ret = 1;
  while(p > 0){
    if(p & 1) (ret *= n) %= m;
    (n *= n) %= m;
    p >>= 1;
  }
  return ret;
}
#line 5 "Mylib/Number/Mod/mod_sqrt.cpp"

/**
 * @title 平方剰余
 * @docs mod_sqrt.md
 */
std::optional<int64_t> mod_sqrt(int64_t a, int64_t p){
  if(p == 2) return a % 2;
  if(a == 0) return 0;
  
  int64_t b = power(a, (p-1) / 2, p);

  if(b == p-1) return {};
  if(p % 4 == 3) return power(a, (p+1) / 4, p);

  int64_t q = p - 1, s = 0;
  while(q % 2 == 0){
    q /= 2;
    s += 1;
  }

  static std::mt19937_64 rand(time(0));
  std::uniform_int_distribution<> dist(0, p-1);

  int64_t z;
  while(1){
    z = dist(rand);
    if(power(z, (p-1) / 2, p) == p - 1) break;
  }
  
  int64_t m = s;
  int64_t c = power(z, q, p);
  int64_t t = power(a, q, p);
  int64_t r = power(a, (q+1) / 2, p);

  while(1){
    if(t == 0) return 0;
    if(t == 1) return r;

    int i = 1;
    for(int64_t T = t; i < m; ++i){
      (T *= T) %= p;
      if(T == 1) break;
    }
    
    int64_t b = power(c, 1LL << (m-i-1), p);

    m = i;
    c = b * b % p;
    (t *= b * b % p) %= p;
    (r *= b) %= p;
  }
}
#line 5 "test/yosupo-judge/sqrt_mod/main.test.cpp"

void solve(){
  int64_t Y, P; scanf("%lld%lld", &Y, &P);

  auto ans = mod_sqrt(Y, P).value_or(-1);
  printf("%lld\n", ans);
}

int main(){
  int T; scanf("%d", &T);
  while(T--) solve();
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

