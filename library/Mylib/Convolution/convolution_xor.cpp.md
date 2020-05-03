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


# :warning: 添字BitXor畳み込み

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d1ac32c11c508fec0764fa012d8d2913">Mylib/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Convolution/convolution_xor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 14:59:26+09:00




## Operations

- `convolution_xor(f[N], g[N])`
	- `N`は2の累乗
	- `k in [0, N)`について$h_k = \sum_{k=i \oplus j} f_i * g_j$を求める。

## Requirements

## Notes

## Problems

## References

- [https://kazuma8128.hatenablog.com/entry/2018/05/31/144519](https://kazuma8128.hatenablog.com/entry/2018/05/31/144519)


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cassert>

/**
 * @title 添字BitXor畳み込み
 * @docs convolution_xor.md
 */
template <typename T>
std::vector<T> convolution_xor(std::vector<T> f, std::vector<T> g){
  const int n = f.size();
  assert((int)f.size() == n and (int)g.size() == n and (n & (n-1)) == 0);

  auto fwt =
    [n](std::vector<T> f){
      for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; ++j){
          if((j & i) == 0){
            auto x = f[j], y = f[j | i];
            f[j] = x + y;
            f[j | i] = x - y;
          }
        }
      }
      return f;
    };

  auto ifwt =
    [n](std::vector<T> f){
      for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; ++j){
          if((j & i) == 0){
            auto x = f[j], y = f[j | i];
            f[j] = (x + y) / 2;
            f[j | i] = (x - y) / 2;
          }
        }
      }
      return f;
    };

  f = fwt(f);
  g = fwt(g);

  for(int i = 0; i < n; ++i) f[i] *= g[i];

  f = ifwt(f);

  return f;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Convolution/convolution_xor.cpp"
#include <vector>
#include <cassert>

/**
 * @title 添字BitXor畳み込み
 * @docs convolution_xor.md
 */
template <typename T>
std::vector<T> convolution_xor(std::vector<T> f, std::vector<T> g){
  const int n = f.size();
  assert((int)f.size() == n and (int)g.size() == n and (n & (n-1)) == 0);

  auto fwt =
    [n](std::vector<T> f){
      for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; ++j){
          if((j & i) == 0){
            auto x = f[j], y = f[j | i];
            f[j] = x + y;
            f[j | i] = x - y;
          }
        }
      }
      return f;
    };

  auto ifwt =
    [n](std::vector<T> f){
      for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; ++j){
          if((j & i) == 0){
            auto x = f[j], y = f[j | i];
            f[j] = (x + y) / 2;
            f[j | i] = (x - y) / 2;
          }
        }
      }
      return f;
    };

  f = fwt(f);
  g = fwt(g);

  for(int i = 0; i < n; ++i) f[i] *= g[i];

  f = ifwt(f);

  return f;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

