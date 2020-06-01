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


# :warning: Euler's totient function (Enumerate)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5fda78fda98ef9fc0f87c6b50d529f19">Mylib/Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/euler_phi_function_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

- `totient_table(n)`
	- `i in [0, n]`について$\varphi(i)$を求める。
	- $\varphi(nm) = \varphi(n) * \varphi(m)$ if nとmが互いに素

## Requirements

## Notes

## Problems

- [Manthan, Codefest 19 G. Polygons](https://codeforces.com/contest/1208/problem/G)

## References


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <numeric>

/**
 * @title Euler's totient function (Enumerate)
 * @docs euler_phi_function_table.md
 */
auto totient_table(int n){
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
#line 2 "Mylib/Number/euler_phi_function_table.cpp"
#include <vector>
#include <numeric>

/**
 * @title Euler's totient function (Enumerate)
 * @docs euler_phi_function_table.md
 */
auto totient_table(int n){
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

