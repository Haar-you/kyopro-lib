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


# :x: Bell number

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/bell_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

- `bell_number(Ft, int n, int k)`
	- n個の区別するボールをk個の区別しない箱に分配するような方法の総数。
	- Time complexity $O(\min(k, n)\ \log n)$

## References

- [https://mathtrain.jp/zensya](https://mathtrain.jp/zensya)
- [https://mathtrain.jp/twelveway](https://mathtrain.jp/twelveway)
- [https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0](https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E6%95%B0)


## Depends on

* :x: <a href="factorial_table.cpp.html">Factorial table</a>


## Verified with

* :x: <a href="../../../verify/test/aoj/DPL_5_G/main.test.cpp.html">test/aoj/DPL_5_G/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Bell number
 * @docs bell_number.md
 */
namespace haar_lib {
  template <typename Ft, typename T = typename Ft::value_type>
  T bell_number(int64_t n, int64_t k, const Ft &ft){
    if(n == 0) return 1;

    k = std::min(k, n);

    std::vector<T> t(k, 1);

    for(int i = 1; i < k; ++i){
      if(i % 2 == 0) t[i] = t[i - 1] + ft.inv_factorial(i);
      else t[i] = t[i - 1] - ft.inv_factorial(i);
    }

    T ret = 0;
    for(int i = 1; i <= k; ++i){
      ret += t[k - i] * T::power(i, n) * ft.inv_factorial(i);
    }

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/bell_number.cpp"
#include <vector>
#include <algorithm>
#line 3 "Mylib/Combinatorics/factorial_table.cpp"
#include <cassert>
#include <cstdint>

/**
 * @title Factorial table
 * @docs factorial_table.md
 */
namespace haar_lib {
  template <typename T>
  class factorial_table {
  public:
    using value_type = T;

  private:
    std::vector<T> f_table;
    std::vector<T> if_table;

  public:
    factorial_table(int N){
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
}
#line 5 "Mylib/Combinatorics/bell_number.cpp"

/**
 * @title Bell number
 * @docs bell_number.md
 */
namespace haar_lib {
  template <typename Ft, typename T = typename Ft::value_type>
  T bell_number(int64_t n, int64_t k, const Ft &ft){
    if(n == 0) return 1;

    k = std::min(k, n);

    std::vector<T> t(k, 1);

    for(int i = 1; i < k; ++i){
      if(i % 2 == 0) t[i] = t[i - 1] + ft.inv_factorial(i);
      else t[i] = t[i - 1] - ft.inv_factorial(i);
    }

    T ret = 0;
    for(int i = 1; i <= k; ++i){
      ret += t[k - i] * T::power(i, n) * ft.inv_factorial(i);
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

