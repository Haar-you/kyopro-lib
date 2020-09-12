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


# :x: 1D Imos algorithm (Linear addition)

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#6dc6d5a2cac82b39a08fd9ff32ab6e48">Mylib/Algorithm/Imos</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Algorithm/Imos/linear_imos_1d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

- [ARC 077 E - guruguru](https://atcoder.jp/contests/arc077/tasks/arc077_c)

## References



## Verified with

* :x: <a href="../../../../verify/test/yukicoder/1084/main.test.cpp.html">test/yukicoder/1084/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title 1D Imos algorithm (Linear addition)
 * @docs linear_imos_1d.md
 */
namespace haar_lib {
  template <typename T>
  struct linear_imos_1d {
    using value_type = T;

    std::vector<T> vec_a, vec_a_end, vec_b, vec;
    int n;

    linear_imos_1d(int n):
      vec_a(n + 1), vec_a_end(n + 1), vec_b(n + 1), vec(n + 1), n(n){}

    void add(int s, int t, const T &a, const T &b){ // x ∈ [s, t)にax+bを加算する。
      vec_a[s + 1] += a;
      vec_a[t] -= a;

      vec_a_end[t] -= a * (t - s - 1);

      vec_b[s] += a * s + b;
      vec_b[t] -= a * s + b;
    }

    void build(){
      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];
      for(int i = 0; i <= n; ++i) vec_a[i] += vec_a_end[i];
      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];

      for(int i = 0; i < n; ++i) vec_b[i + 1] += vec_b[i];

      for(int i = 0; i <= n; ++i) vec[i] = vec_a[i] + vec_b[i];
    }

    T operator[](size_t i) const {return vec[i];}
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Algorithm/Imos/linear_imos_1d.cpp"
#include <vector>

/**
 * @title 1D Imos algorithm (Linear addition)
 * @docs linear_imos_1d.md
 */
namespace haar_lib {
  template <typename T>
  struct linear_imos_1d {
    using value_type = T;

    std::vector<T> vec_a, vec_a_end, vec_b, vec;
    int n;

    linear_imos_1d(int n):
      vec_a(n + 1), vec_a_end(n + 1), vec_b(n + 1), vec(n + 1), n(n){}

    void add(int s, int t, const T &a, const T &b){ // x ∈ [s, t)にax+bを加算する。
      vec_a[s + 1] += a;
      vec_a[t] -= a;

      vec_a_end[t] -= a * (t - s - 1);

      vec_b[s] += a * s + b;
      vec_b[t] -= a * s + b;
    }

    void build(){
      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];
      for(int i = 0; i <= n; ++i) vec_a[i] += vec_a_end[i];
      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];

      for(int i = 0; i < n; ++i) vec_b[i + 1] += vec_b[i];

      for(int i = 0; i <= n; ++i) vec[i] = vec_a[i] + vec_b[i];
    }

    T operator[](size_t i) const {return vec[i];}
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

