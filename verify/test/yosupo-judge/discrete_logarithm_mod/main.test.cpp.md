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


# :heavy_check_mark: test/yosupo-judge/discrete_logarithm_mod/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2163f1b495697e10d51593b9d528fe28">test/yosupo-judge/discrete_logarithm_mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo-judge/discrete_logarithm_mod/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00


* see: <a href="https://judge.yosupo.jp/problem/discrete_logarithm_mod">https://judge.yosupo.jp/problem/discrete_logarithm_mod</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mod/mod_inv.cpp.html">mod逆数</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mod/mod_log.cpp.html">離散対数</a>
* :heavy_check_mark: <a href="../../../../library/Mylib/Number/Mod/mod_power.cpp.html">mod累乗</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>
#include "Mylib/Number/Mod/mod_log.cpp"

void solve(){
  int X, Y, M; scanf("%d%d%d", &X, &Y, &M);
  auto ans = mod_log(X, Y, M);
  
  printf("%lld\n", ans.value_or(-1));
}


int main(){
  int T; scanf("%d", &T);
  
  while(T--){
    solve();
  }

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo-judge/discrete_logarithm_mod/main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>
#line 2 "Mylib/Number/Mod/mod_log.cpp"
#include <unordered_map>
#include <optional>
#include <numeric>
#include <cmath>
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
#line 2 "Mylib/Number/Mod/mod_inv.cpp"
#include <utility>

/**
 * @title mod逆数
 * @docs mod_inv.md
 */
int64_t mod_inv(int64_t a, int64_t m){
  int64_t b = m, u = 1, v = 0;

  while(b){
    int64_t t = a / b;
    a -= t * b; std::swap(a, b);
    u -= t * v; std::swap(u, v);
  }

  u %= m;
  if(u < 0) u += m;

  return u;
}
#line 8 "Mylib/Number/Mod/mod_log.cpp"

/**
 * @title 離散対数
 * @docs mod_log.md
 */
std::optional<int64_t> mod_log(int64_t a, int64_t b, int64_t m){
  if(b == 1) return 0;
  
  int64_t d = 0;
  
  while(1){
    if(auto g = std::gcd(a, m); g != 1){
      if(b % g != 0) return {};
      
      d += 1;
      m /= g;
      b /= g;
      (b *= mod_inv(a/g, m)) %= m;

      if(b == 1) return d;
    }else{
      break;
    }
  }

  const int64_t sq = sqrt(m) + 1;
  
  std::unordered_map<int64_t,int64_t> mp;
  {
    int64_t t = 1 % m;
  
    for(int i = 0; i < sq; ++i){
      if(mp.find(t) == mp.end()) mp[t] = i;
      (t *= a) %= m;
    }
  }
  
  {
    int64_t A = power(mod_inv(a, m), sq, m);
    int64_t t = b % m;
    
    for(int i = 0; i < sq; ++i){
      if(mp.find(t) != mp.end()){
        int64_t ret = i * sq + mp[t] + d;

        return ret;
      }

      (t *= A) %= m;
    }
  }
  
  return {};
}
#line 5 "test/yosupo-judge/discrete_logarithm_mod/main.test.cpp"

void solve(){
  int X, Y, M; scanf("%d%d%d", &X, &Y, &M);
  auto ans = mod_log(X, Y, M);
  
  printf("%lld\n", ans.value_or(-1));
}


int main(){
  int T; scanf("%d", &T);
  
  while(T--){
    solve();
  }

  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
