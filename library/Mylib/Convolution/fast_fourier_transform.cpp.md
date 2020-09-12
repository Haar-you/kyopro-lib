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


# :warning: Fast Fourier transform

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d1ac32c11c508fec0764fa012d8d2913">Mylib/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Convolution/fast_fourier_transform.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Operations

## Requirements

## Notes

## Problems

- [ATC 001 C - 高速フーリエ変換](https://atcoder.jp/contests/atc001/tasks/fft_c)

## References


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <complex>
#include <cassert>
#include <utility>

/**
 * @title Fast Fourier transform
 * @docs fast_fourier_transform.md
 */
namespace haar_lib {
  template <typename T = double, bool INVERSE = false>
  auto fast_fourier_transform(std::vector<std::complex<T>> f){
    const int n = f.size();
    assert((n & (n - 1)) == 0); // データ数は2の冪乗個

    const int p = __builtin_ctz(n);

    for(int i = 0; i < n; ++i){
      int j = 0;
      for(int k = 0; k < p; ++k) j |= (i >> k & 1) << (p - 1 - k);
      if(i < j) std::swap(f[i], f[j]);
    }

    for(int b = 1; b < n; b <<= 1){
      for(int i = 0; i < b; ++i){
        T angle = 2.0 * M_PI * i / (2 * b);
        if(INVERSE) angle = -angle;
        std::complex<T> w = std::polar(1.0, angle);

        for(int j = 0; j < n; j += 2 * b){
          auto s = f[i + j];
          auto t = f[i + j + b] * w;

          f[i + j] = s + t;
          f[i + j + b] = s - t;
        }
      }
    }

    if(INVERSE) for(auto &x : f) x /= n;

    return f;
  }

  template <typename T = double>
  std::vector<std::complex<T>> fft_convolution(std::vector<std::complex<T>> f, std::vector<std::complex<T>> g){
    const int m = f.size() + g.size() - 1;
    int n = 1;
    while(n < m) n *= 2;

    f.resize(n);
    g.resize(n);

    f = fast_fourier_transform<T>(f);
    g = fast_fourier_transform<T>(g);

    std::vector<std::complex<T>> ret(n);
    for(int i = 0; i < n; ++i) ret[i] = f[i] * g[i];
    ret = fast_fourier_transform<T, true>(ret);

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Convolution/fast_fourier_transform.cpp"
#include <vector>
#include <complex>
#include <cassert>
#include <utility>

/**
 * @title Fast Fourier transform
 * @docs fast_fourier_transform.md
 */
namespace haar_lib {
  template <typename T = double, bool INVERSE = false>
  auto fast_fourier_transform(std::vector<std::complex<T>> f){
    const int n = f.size();
    assert((n & (n - 1)) == 0); // データ数は2の冪乗個

    const int p = __builtin_ctz(n);

    for(int i = 0; i < n; ++i){
      int j = 0;
      for(int k = 0; k < p; ++k) j |= (i >> k & 1) << (p - 1 - k);
      if(i < j) std::swap(f[i], f[j]);
    }

    for(int b = 1; b < n; b <<= 1){
      for(int i = 0; i < b; ++i){
        T angle = 2.0 * M_PI * i / (2 * b);
        if(INVERSE) angle = -angle;
        std::complex<T> w = std::polar(1.0, angle);

        for(int j = 0; j < n; j += 2 * b){
          auto s = f[i + j];
          auto t = f[i + j + b] * w;

          f[i + j] = s + t;
          f[i + j + b] = s - t;
        }
      }
    }

    if(INVERSE) for(auto &x : f) x /= n;

    return f;
  }

  template <typename T = double>
  std::vector<std::complex<T>> fft_convolution(std::vector<std::complex<T>> f, std::vector<std::complex<T>> g){
    const int m = f.size() + g.size() - 1;
    int n = 1;
    while(n < m) n *= 2;

    f.resize(n);
    g.resize(n);

    f = fast_fourier_transform<T>(f);
    g = fast_fourier_transform<T>(g);

    std::vector<std::complex<T>> ret(n);
    for(int i = 0; i < n; ++i) ret[i] = f[i] * g[i];
    ret = fast_fourier_transform<T, true>(ret);

    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

