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


# :warning: Mylib/Number/euler_phi_function.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/euler_phi_function.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-01 07:59:09+09:00


* see: <a href="https://codeforces.com/contest/1208/submission/59824476">https://codeforces.com/contest/1208/submission/59824476</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <numeric>

/**
 * @see https://codeforces.com/contest/1208/submission/59824476
 * @note phi(nm) = phi(n) * phi(m) if nとmが互いに素
 */
auto phi_function(int n){
  std::vector<int> ret(n+1);
  std::iota(ret.begin(), ret.end(), 0);

  for(int i = 2; i <= n; ++i){
    if(ret[i] == i){
      for(int j = i; j <= n; j += i){
        ret[j] = ret[j] / i * (i-1);
      }
    }
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/euler_phi_function.cpp"
#include <vector>
#include <numeric>

/**
 * @see https://codeforces.com/contest/1208/submission/59824476
 * @note phi(nm) = phi(n) * phi(m) if nとmが互いに素
 */
auto phi_function(int n){
  std::vector<int> ret(n+1);
  std::iota(ret.begin(), ret.end(), 0);

  for(int i = 2; i <= n; ++i){
    if(ret[i] == i){
      for(int j = i; j <= n; j += i){
        ret[j] = ret[j] / i * (i-1);
      }
    }
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

