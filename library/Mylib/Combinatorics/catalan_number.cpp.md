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


# :x: Catalan number

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/catalan_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-06 11:15:59+09:00




## Operations

- `catalan_number(Ft, int n)`
	-  $c_0 = 1, c_{n+1} = \sum_{i=0}^n c_i * c_{n-i}$ を満たす数列の第n項を返す。

## Problems

- [KUPC2019 D - Maximin Game](https://atcoder.jp/contests/kupc2019/tasks/kupc2019_d)
- [yukicoder No.660 家を通り過ぎないランダムウォーク問題](https://yukicoder.me/problems/no/660)

## References

- [https://en.wikipedia.org/wiki/Catalan_number](https://en.wikipedia.org/wiki/Catalan_number)
- [https://mathtrain.jp/catalan](https://mathtrain.jp/catalan)


## Depends on

* :x: <a href="factorial_table.cpp.html">Factorial table</a>


## Verified with

* :x: <a href="../../../verify/test/yukicoder/660/main.test.cpp.html">test/yukicoder/660/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdint>
#include "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Catalan number
 * @docs catalan_number.md
 */
template <typename Ft, typename T = typename Ft::value_type>
T catalan_number(int64_t n, const Ft &ft){
  return ft.C(2 * n, n) - ft.C(2 * n, n - 1);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/catalan_number.cpp"
#include <cstdint>
#line 2 "Mylib/Combinatorics/factorial_table.cpp"
#include <vector>
#include <cassert>
#line 5 "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Factorial table
 * @docs factorial_table.md
 */
template <typename T>
class FactorialTable {
public:
  using value_type = T;

private:
  std::vector<T> f_table;
  std::vector<T> if_table;

public:
  FactorialTable(int N){
    f_table.assign(N + 1, 1);
    if_table.assign(N + 1, 1);

    for(int i = 1; i <= N; ++i){
      f_table[i] = f_table[i - 1] * i;
    }

    if_table[N] = f_table[N].inv();

    for(int i = N; --i >= 0;){
      if_table[i] = if_table[i + 1] * (i + 1);
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
    return factorial(n) * inv_factorial(n - k);
  }

  T C(int64_t n, int64_t k) const {
    if(n < k or n < 0 or k < 0) return 0;
    return P(n, k) * inv_factorial(k);
  }

  T H(int64_t n, int64_t k) const {
    if(n == 0 and k == 0) return 1;
    return C(n + k - 1, k);
  }
};
#line 4 "Mylib/Combinatorics/catalan_number.cpp"

/**
 * @title Catalan number
 * @docs catalan_number.md
 */
template <typename Ft, typename T = typename Ft::value_type>
T catalan_number(int64_t n, const Ft &ft){
  return ft.C(2 * n, n) - ft.C(2 * n, n - 1);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

