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


# :heavy_check_mark: Bernoulli数

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/bernoulli_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-26 15:25:30+09:00




## Operations

- $\mathtt{bernoulli\_number(int\ n)}$
	- $B_0$ ~ $B_n$を列挙する。
	- Time complexity $O(N^2)$

## References

- [https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0](https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0)


## Depends on

* :heavy_check_mark: <a href="combinatorics.cpp.html">組み合わせ計算用の前計算クラス</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yukicoder/665/main.test.cpp.html">test/yukicoder/665/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include "Mylib/Combinatorics/combinatorics.cpp"

/**
 * @title Bernoulli数
 * @docs bernoulli_number.md
 */
template <typename T>
std::vector<T> Combinatorics<T>::bernoulli_number(int64_t n){
  std::vector<T> ret(n+1);

  ret[0] = 1;

  for(int64_t i = 1; i <= n; ++i){
    for(int k = 0; k <= i-1; ++k){
      ret[i] += C(i+1,k) * ret[k];
    }
    ret[i] /= i+1;
    ret[i] = -ret[i];
  }
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/bernoulli_number.cpp"
#include <vector>
#line 3 "Mylib/Combinatorics/combinatorics.cpp"
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
#line 4 "Mylib/Combinatorics/bernoulli_number.cpp"

/**
 * @title Bernoulli数
 * @docs bernoulli_number.md
 */
template <typename T>
std::vector<T> Combinatorics<T>::bernoulli_number(int64_t n){
  std::vector<T> ret(n+1);

  ret[0] = 1;

  for(int64_t i = 1; i <= n; ++i){
    for(int k = 0; k <= i-1; ++k){
      ret[i] += C(i+1,k) * ret[k];
    }
    ret[i] /= i+1;
    ret[i] = -ret[i];
  }
  
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

