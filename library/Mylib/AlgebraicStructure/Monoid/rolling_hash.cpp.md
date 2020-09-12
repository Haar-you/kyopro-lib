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


# :heavy_check_mark: Rolling hash monoid

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#b9ce8b1117f3871719e4d3859e7574c9">Mylib/AlgebraicStructure/Monoid</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2444/main.test.cpp.html">test/aoj/2444/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <array>
#include <utility>

/**
 * @title Rolling hash monoid
 * @docs rolling_hash.md
 */
namespace haar_lib {
  template <size_t N>
  struct rolling_hash_monoid {
    static std::array<int64_t, N> base;
    static int64_t mod;

    using value_type = std::pair<std::array<int64_t, N>, std::array<int64_t, N>>;

    value_type operator()() const {
      value_type ret;
      for(size_t i = 0; i < N; ++i){
        ret.first[i] = 0LL;
        ret.second[i] = 1LL;
      }
      return ret;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      value_type ret;
      for(size_t i = 0; i < N; ++i){
        ret.first[i] = (a.first[i] + b.first[i] * a.second[i] % mod) % mod;
        ret.second[i] = a.second[i] * b.second[i] % mod;
      }
      return ret;
    }

    template <typename T>
    static value_type make(T a){
      value_type ret;
      for(size_t i = 0; i < N; ++i){
        ret.first[i] = (int64_t)a % mod;
        ret.second[i] = base[i];
      }
      return ret;
    }
  };

  template <size_t N> std::array<int64_t, N> rolling_hash_monoid<N>::base;
  template <size_t N> int64_t rolling_hash_monoid<N>::mod;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp"
#include <array>
#include <utility>

/**
 * @title Rolling hash monoid
 * @docs rolling_hash.md
 */
namespace haar_lib {
  template <size_t N>
  struct rolling_hash_monoid {
    static std::array<int64_t, N> base;
    static int64_t mod;

    using value_type = std::pair<std::array<int64_t, N>, std::array<int64_t, N>>;

    value_type operator()() const {
      value_type ret;
      for(size_t i = 0; i < N; ++i){
        ret.first[i] = 0LL;
        ret.second[i] = 1LL;
      }
      return ret;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      value_type ret;
      for(size_t i = 0; i < N; ++i){
        ret.first[i] = (a.first[i] + b.first[i] * a.second[i] % mod) % mod;
        ret.second[i] = a.second[i] * b.second[i] % mod;
      }
      return ret;
    }

    template <typename T>
    static value_type make(T a){
      value_type ret;
      for(size_t i = 0; i < N; ++i){
        ret.first[i] = (int64_t)a % mod;
        ret.second[i] = base[i];
      }
      return ret;
    }
  };

  template <size_t N> std::array<int64_t, N> rolling_hash_monoid<N>::base;
  template <size_t N> int64_t rolling_hash_monoid<N>::mod;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

