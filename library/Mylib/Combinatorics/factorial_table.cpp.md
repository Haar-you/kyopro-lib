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


# :question: Factorial table

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/factorial_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 09:35:37+09:00




## Operations

- `FactorialTable(int N)`
	- $0!$ ~ $N!$とその逆数を計算する。
	- Time complexity $O(N)$
- `factorial(int i)` : return $i!$
- `inv_factorial(int i)` : return $\frac{1}{i!}$
- `P(int n, int k)` : return $_nP_k$
- `C(int n, int k)` : return $_nC_k$
- `H(int n, int k)` : return $_nH_k = _{n+k-1}C_k$


## Required by

* :heavy_check_mark: <a href="bell_number.cpp.html">Bell number</a>
* :x: <a href="bernoulli_number.cpp.html">Bernoulli number</a>
* :x: <a href="catalan_number.cpp.html">Catalan number</a>
* :heavy_check_mark: <a href="stirling_number_second.cpp.html">Stirling numbers of the second kind</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_G/main.test.cpp.html">test/aoj/DPL_5_G/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/aoj/DPL_5_I/main.test.cpp.html">test/aoj/DPL_5_I/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/bernoulli_number/main.test.cpp.html">test/yosupo-judge/bernoulli_number/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/117/main.test.cpp.html">test/yukicoder/117/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/660/main.test.cpp.html">test/yukicoder/660/main.test.cpp</a>
* :x: <a href="../../../verify/test/yukicoder/665/main.test.cpp.html">test/yukicoder/665/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cassert>

/**
 * @title Factorial table
 * @docs factorial_table.md
 */
template <typename T>
class FactorialTable{
public:
  using value_type = T;

private:
  std::vector<T> f_table;
  std::vector<T> if_table;

public:
  FactorialTable(int N){
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
  
  T factorial(int64_t i) const {
    assert(i < (int)f_table.size());
    return f_table[i];
  }
  
  T inv_factorial(int64_t i) const {
    assert(i < (int)if_table.size());
    return if_table[i];
  }

  T P(int64_t n, int64_t k) const {
    if(n < k or n < 0 or k < 0) return 0;
    return factorial(n) * inv_factorial(n-k);
  }

  T C(int64_t n, int64_t k) const {
    if(n < k or n < 0 or k < 0) return 0;
    return P(n,k) * inv_factorial(k);
  }

  T H(int64_t n, int64_t k) const {
    if(n == 0 and k == 0) return 1;
    return C(n+k-1, k);
  }
};

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
 */
template <typename T>
class FactorialTable{
public:
  using value_type = T;

private:
  std::vector<T> f_table;
  std::vector<T> if_table;

public:
  FactorialTable(int N){
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
  
  T factorial(int64_t i) const {
    assert(i < (int)f_table.size());
    return f_table[i];
  }
  
  T inv_factorial(int64_t i) const {
    assert(i < (int)if_table.size());
    return if_table[i];
  }

  T P(int64_t n, int64_t k) const {
    if(n < k or n < 0 or k < 0) return 0;
    return factorial(n) * inv_factorial(n-k);
  }

  T C(int64_t n, int64_t k) const {
    if(n < k or n < 0 or k < 0) return 0;
    return P(n,k) * inv_factorial(k);
  }

  T H(int64_t n, int64_t k) const {
    if(n == 0 and k == 0) return 1;
    return C(n+k-1, k);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

