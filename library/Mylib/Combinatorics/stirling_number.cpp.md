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


# :heavy_check_mark: Stirling numbers of second kind

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/stirling_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-30 03:19:03+09:00




## Operations

- `stirling_number(int n, int k)`
	- n個の区別するボールをk個の区別しない箱に分配する(但し、すべての箱には1つ以上のボールが入る)ような方法の総数。
	- Time complexity $O(k\log n)$

## References

- [drken1215.hatenablog.com/entry/2018/02/01/200628](drken1215.hatenablog.com/entry/2018/02/01/200628)


## Depends on

* :heavy_check_mark: <a href="factorial_table.cpp.html">Factorial table</a>


## Required by

* :heavy_check_mark: <a href="bell_number.cpp.html">Bell number</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_G/main.test.cpp.html">test/aoj/DPL_5_G/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_I/main.test.cpp.html">test/aoj/DPL_5_I/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Stirling numbers of second kind
 * @docs stirling_number.md
 */
template <typename T>
T FactorialTable<T>::stirling_number(int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  
  T ret = 0;
  for(int i = 1; i <= k; ++i){
    if((k-i) % 2 == 0) ret += C(k,i) * T::power(i,n);
    else ret -= C(k,i) * T::power(i,n);
  }
  ret *= inv_factorial(k);
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/factorial_table.cpp"
#include <vector>
#include <cassert>

/**
 * @title Factorial table
 * @docs factorial_table.md
 * @attention 使用前にinit関数を呼び出す
 */
template <typename T> class FactorialTable{
public:
  static std::vector<T> f_table;
  static std::vector<T> if_table;

  static void init(int N){
    f_table.assign(N+1, 1);
    if_table.assign(N+1, 1);
    
    for(int i = 1; i <= N; ++i){
      f_table[i] = f_table[i-1] * i;
    }
    
    if_table[N] = f_table[N].inv();

    for(int i = N-1; i >= 0; --i){
      if_table[i] = if_table[i+1] * (i+1);
    }
  }
  
  static T factorial(int64_t i){
    assert(i < (int)f_table.size());
    return f_table[i];
  }
  
  static T inv_factorial(int64_t i){
    assert(i < (int)if_table.size());
    return if_table[i];
  }

  static T P(int64_t n, int64_t k);
  static T C(int64_t n, int64_t k);
  static T H(int64_t n, int64_t k);
  static T stirling_number(int64_t n, int64_t k);
  static T bell_number(int64_t n, int64_t k);
  static std::vector<T> bernoulli_number(int64_t n);
  static T catalan_number(int64_t n);
};

template <typename T> std::vector<T> FactorialTable<T>::f_table = std::vector<T>();
template <typename T> std::vector<T> FactorialTable<T>::if_table = std::vector<T>();

template <typename T> T FactorialTable<T>::P(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return factorial(n) * inv_factorial(n-k);
}

template <typename T> T FactorialTable<T>::C(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return P(n,k) * inv_factorial(k);
}

template <typename T> T FactorialTable<T>::H(int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  return C(n+k-1, k);
}
#line 3 "Mylib/Combinatorics/stirling_number.cpp"

/**
 * @title Stirling numbers of second kind
 * @docs stirling_number.md
 */
template <typename T>
T FactorialTable<T>::stirling_number(int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  
  T ret = 0;
  for(int i = 1; i <= k; ++i){
    if((k-i) % 2 == 0) ret += C(k,i) * T::power(i,n);
    else ret -= C(k,i) * T::power(i,n);
  }
  ret *= inv_factorial(k);
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

