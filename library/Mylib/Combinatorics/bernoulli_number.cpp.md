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


# :x: Bernoulli number

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/bernoulli_number.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

- `bernoulli_number(Ft, int n)`
	- $B_0$ ~ $B_n$を列挙する。
	- Time complexity $O(N^2)$

## References

- [https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0](https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0)


## Depends on

* :x: <a href="factorial_table.cpp.html">Factorial table</a>


## Verified with

* :x: <a href="../../../verify/test/yukicoder/665/main.test.cpp.html">test/yukicoder/665/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <cstdint>
#include "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Bernoulli number
 * @docs bernoulli_number.md
 */
namespace haar_lib {
  template <typename Ft, typename T = typename Ft::value_type>
  std::vector<T> bernoulli_number(int64_t n, const Ft &ft){
    std::vector<T> ret(n + 1);

    ret[0] = 1;

    for(int64_t i = 1; i <= n; ++i){
      for(int k = 0; k <= i - 1; ++k){
        ret[i] += ft.C(i + 1, k) * ret[k];
      }
      ret[i] /= i + 1;
      ret[i] = -ret[i];
    }

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/bernoulli_number.cpp"
#include <vector>
#include <cstdint>
#line 3 "Mylib/Combinatorics/factorial_table.cpp"
#include <cassert>
#line 5 "Mylib/Combinatorics/factorial_table.cpp"

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
#line 5 "Mylib/Combinatorics/bernoulli_number.cpp"

/**
 * @title Bernoulli number
 * @docs bernoulli_number.md
 */
namespace haar_lib {
  template <typename Ft, typename T = typename Ft::value_type>
  std::vector<T> bernoulli_number(int64_t n, const Ft &ft){
    std::vector<T> ret(n + 1);

    ret[0] = 1;

    for(int64_t i = 1; i <= n; ++i){
      for(int k = 0; k <= i - 1; ++k){
        ret[i] += ft.C(i + 1, k) * ret[k];
      }
      ret[i] /= i + 1;
      ret[i] = -ret[i];
    }

    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
