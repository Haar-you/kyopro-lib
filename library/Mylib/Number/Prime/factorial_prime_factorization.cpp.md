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


# :warning: Count number of prime factor p of $a!$

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#26f1f261bc4e83492156752f5caf0111">Mylib/Number/Prime</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Prime/factorial_prime_factorization.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00




## Operations

## Requirements

## Notes

## Problems

- [Codeforces Round #589 (Div. 2) C. Primes and Multiplication](https://codeforces.com/contest/1228/problem/C)

## References


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Count number of prime factor p of $a!$
 * @docs factorial_prime_factorization.md
 */
int64_t factorial_prime_factorization(int64_t a, int64_t p){
  int64_t ret = 0, q = p;

  while(q <= a){
    int64_t t = a / q;

    ret += t;

    int64_t k;
    if(__builtin_smulll_overflow(q, p, &k)) break;
    
    q = k;
  }
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Prime/factorial_prime_factorization.cpp"

/**
 * @title Count number of prime factor p of $a!$
 * @docs factorial_prime_factorization.md
 */
int64_t factorial_prime_factorization(int64_t a, int64_t p){
  int64_t ret = 0, q = p;

  while(q <= a){
    int64_t t = a / q;

    ret += t;

    int64_t k;
    if(__builtin_smulll_overflow(q, p, &k)) break;
    
    q = k;
  }
  return ret;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

