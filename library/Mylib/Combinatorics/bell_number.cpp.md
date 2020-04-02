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


# :heavy_check_mark: Bell数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/bell_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00




## Depends on

* :heavy_check_mark: <a href="combinatorics.cpp.html">組み合わせ計算用の前計算クラス</a>
* :heavy_check_mark: <a href="stirling_number.cpp.html">第2種Stirling数</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_G/main.test.cpp.html">test/aoj/DPL_5_G/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Combinatorics/combinatorics.cpp"
#include "Mylib/Combinatorics/stirling_number.cpp"

/**
 * @title Bell数
 * @note n個の区別するボールをk個の区別しない箱に分配するような方法の総数。
 * @attention O(min(k, n) log n)
 */
template <typename T>
T Combinatorics<T>::bell_number(int64_t n, int64_t k){
  if(n == 0) return 1;
  
  k = std::min(k, n);

  std::vector<T> t(k, 1);
  
  for(int i = 1; i < k; ++i){
    if(i % 2 == 0) t[i] = t[i-1] + finv(i);
    else t[i] = t[i-1] - finv(i);
  }

  T ret = 0;
  for(int i = 1; i <= k; ++i){
    ret += t[k-i] * T::power(i, n) * finv(i);
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/bell_number.cpp"
#include <vector>
#include <algorithm>
#line 3 "Mylib/Combinatorics/combinatorics.cpp"
#include <cassert>

/**
 * @title 組み合わせ計算用の前計算クラス
 * @attention 使用前にinit関数を呼び出す
 */
template <typename T> class Combinatorics{
public:
  static std::vector<T> facto;
  static std::vector<T> ifacto;

  static void init(int N){
    facto.assign(N+1, 1);
    ifacto.assign(N+1, 1);
    
    for(int i = 1; i <= N; ++i){
      facto[i] = facto[i-1] * i;
    }
    
    ifacto[N] = facto[N].inv();

    for(int i = N-1; i >= 0; --i){
      ifacto[i] = ifacto[i+1] * (i+1);
    }
  }
  
  static T f(int64_t i){
    assert(i < facto.size());
    return facto[i];
  }
  
  static T finv(int64_t i){
    assert(i < ifacto.size());
    return ifacto[i];
  }

  static T P(int64_t n, int64_t k);
  static T C(int64_t n, int64_t k);
  static T H(int64_t n, int64_t k);
  static T stirling_number(int64_t n, int64_t k);
  static T bell_number(int64_t n, int64_t k);
  static std::vector<T> bernoulli_number(int64_t n);
  static T catalan_number(int64_t n);
};

template <typename T> std::vector<T> Combinatorics<T>::facto = std::vector<T>();
template <typename T> std::vector<T> Combinatorics<T>::ifacto = std::vector<T>();

template <typename T> T Combinatorics<T>::P(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return f(n) * finv(n-k);
}

template <typename T> T Combinatorics<T>::C(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return P(n,k) * finv(k);
}

template <typename T> T Combinatorics<T>::H(int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  return C(n+k-1, k);
}
#line 3 "Mylib/Combinatorics/stirling_number.cpp"

/**
 * @title 第2種Stirling数
 * @note n個の区別するボールをk個の区別しない箱に分配する(但し、すべての箱には1つ以上のボールがある)ような方法の総数。
 * @attention O(k log n)
 */
template <typename T>
T Combinatorics<T>::stirling_number(int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  
  T ret = 0;
  for(int i = 1; i <= k; ++i){
    if((k-i) % 2 == 0) ret += C(k,i) * T::power(i,n);
    else ret -= C(k,i) * T::power(i,n);
  }
  ret *= finv(k);
  return ret;
}
#line 6 "Mylib/Combinatorics/bell_number.cpp"

/**
 * @title Bell数
 * @note n個の区別するボールをk個の区別しない箱に分配するような方法の総数。
 * @attention O(min(k, n) log n)
 */
template <typename T>
T Combinatorics<T>::bell_number(int64_t n, int64_t k){
  if(n == 0) return 1;
  
  k = std::min(k, n);

  std::vector<T> t(k, 1);
  
  for(int i = 1; i < k; ++i){
    if(i % 2 == 0) t[i] = t[i-1] + finv(i);
    else t[i] = t[i-1] - finv(i);
  }

  T ret = 0;
  for(int i = 1; i <= k; ++i){
    ret += t[k-i] * T::power(i, n) * finv(i);
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

