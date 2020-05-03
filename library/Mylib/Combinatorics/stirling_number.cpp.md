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


# :heavy_check_mark: 第2種Stirling数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/stirling_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:25:30+09:00




## Operations

- `stirling_number(int n, int k)`
	- n個の区別するボールをk個の区別しない箱に分配する(但し、すべての箱には1つ以上のボールが入る)ような方法の総数。
	- Time complexity $O(k\log n)$

## References

- [drken1215.hatenablog.com/entry/2018/02/01/200628](drken1215.hatenablog.com/entry/2018/02/01/200628)


## Depends on

* :question: <a href="combinatorics.cpp.html">組み合わせ計算用の前計算クラス</a>


## Required by

* :heavy_check_mark: <a href="bell_number.cpp.html">Bell数</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_G/main.test.cpp.html">test/aoj/DPL_5_G/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_I/main.test.cpp.html">test/aoj/DPL_5_I/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/Combinatorics/combinatorics.cpp"

/**
 * @title 第2種Stirling数
 * @docs stirling_number.md
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/combinatorics.cpp"
#include <vector>
#include <cassert>

/**
 * @title 組み合わせ計算用の前計算クラス
 * @docs combinatorics.md
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
 * @docs stirling_number.md
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

