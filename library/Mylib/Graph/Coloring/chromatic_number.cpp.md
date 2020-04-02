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


# :warning: グラフ頂点彩色数

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#acf9ec20eaed2eb3d3c1a731ebc2fbe1">Mylib/Graph/Coloring</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Graph/Coloring/chromatic_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136</a>
* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1254">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1254</a>


## Depends on

* :heavy_check_mark: <a href="../../Number/Mod/mod_power.cpp.html">Mylib/Number/Mod/mod_power.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Number/Mod/mod_power.cpp"

/**
 * @title グラフ頂点彩色数
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1254
 * @attention 時間計算量 O(2^n log^2 n)
 */
int chromatic_number(const std::vector<std::vector<int>> &graph){
  const int mod = 1000000007;
  const int N = graph.size();
 
  std::vector<int> g(N);
  for(int i = 0; i < N; ++i){
    for(auto j : graph[i]){
      g[i] |= (1<<j);
    }
  }
  
  std::vector<int64_t> I(1<<N);
  I[0] = 1;
  for(int i = 1; i < (1<<N); ++i){
    int c = __builtin_ctz(i);
    I[i] = I[i-(1<<c)] + I[(i-(1<<c))&(~g[c])];
    if(I[i] >= mod) I[i] -= mod;
  }
  
  const auto check =
    [&](int k){
      int64_t t = 0;
      for(int i = 0; i < (1<<N); ++i){
        if(__builtin_popcount(i) % 2 == 1) t -= power(I[i],k,mod);
        else t += power(I[i],k,mod);
        if(t < 0) t += mod;
        if(t >= mod) t -= mod;
      }
      return (t % mod != 0);
    };
  
  int lb = 0, ub = N;
  while(abs(lb-ub) > 1){
    const auto mid = (lb+ub)/2;
 
    if(check(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  
  return ub;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Graph/Coloring/chromatic_number.cpp"
#include <vector>
#line 2 "Mylib/Number/Mod/mod_power.cpp"

int64_t power(int64_t n, int64_t p, int64_t m){
  int64_t ret = 1;
  while(p > 0){
    if(p & 1) (ret *= n) %= m;
    (n *= n) %= m;
    p >>= 1;
  }
  return ret;
}
#line 4 "Mylib/Graph/Coloring/chromatic_number.cpp"

/**
 * @title グラフ頂点彩色数
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1254
 * @attention 時間計算量 O(2^n log^2 n)
 */
int chromatic_number(const std::vector<std::vector<int>> &graph){
  const int mod = 1000000007;
  const int N = graph.size();
 
  std::vector<int> g(N);
  for(int i = 0; i < N; ++i){
    for(auto j : graph[i]){
      g[i] |= (1<<j);
    }
  }
  
  std::vector<int64_t> I(1<<N);
  I[0] = 1;
  for(int i = 1; i < (1<<N); ++i){
    int c = __builtin_ctz(i);
    I[i] = I[i-(1<<c)] + I[(i-(1<<c))&(~g[c])];
    if(I[i] >= mod) I[i] -= mod;
  }
  
  const auto check =
    [&](int k){
      int64_t t = 0;
      for(int i = 0; i < (1<<N); ++i){
        if(__builtin_popcount(i) % 2 == 1) t -= power(I[i],k,mod);
        else t += power(I[i],k,mod);
        if(t < 0) t += mod;
        if(t >= mod) t -= mod;
      }
      return (t % mod != 0);
    };
  
  int lb = 0, ub = N;
  while(abs(lb-ub) > 1){
    const auto mid = (lb+ub)/2;
 
    if(check(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  
  return ub;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

