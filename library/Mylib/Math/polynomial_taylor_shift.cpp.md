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


# :x: polynomial_taylor_shift.md

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c20232aa0a6a3c1c77a782d17f007d0b">Mylib/Math</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Math/polynomial_taylor_shift.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 17:46:14+09:00




## Required by

* :x: <a href="../Combinatorics/stirling_number_first_fft.cpp.html">Stirling numbers of the first kind (FFT)</a>


## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/polynomial_taylor_shift/main.test.cpp.html">test/yosupo-judge/polynomial_taylor_shift/main.test.cpp</a>
* :x: <a href="../../../verify/test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp.html">test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @docs Polynomial Taylor shift
 * @title polynomial_taylor_shift.md
 */
namespace haar_lib {
  template <typename T, typename Conv>
  auto polynomial_taylor_shift(std::vector<T> a, T c, const Conv &convolve){
    const int N = a.size();
    T f = 1;
    std::vector<T> A(2 * N - 1);
    for(int i = 0; i < N; ++i){
      if(i) f *= i;
      A[i + N - 1] = a[i] * f;
    }

    T d = 1;

    std::vector<T> g(N);
    g[N - 1] = f.inv();
    for(int i = N - 2; i >= 0; --i) g[i] = g[i + 1] * (i + 1);

    std::vector<T> B(2 * N - 1);
    for(int i = 0; i < N; ++i){
      B[N - i - 1] = d * g[i];
      d *= c;
    }

    auto C = convolve(A, B);

    std::vector<T> ret(N);
    for(int i = 0; i < N; ++i) ret[i] = C[(N - 1) * 2 + i] * g[i];

    return ret;
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Math/polynomial_taylor_shift.cpp"
#include <vector>

/**
 * @docs Polynomial Taylor shift
 * @title polynomial_taylor_shift.md
 */
namespace haar_lib {
  template <typename T, typename Conv>
  auto polynomial_taylor_shift(std::vector<T> a, T c, const Conv &convolve){
    const int N = a.size();
    T f = 1;
    std::vector<T> A(2 * N - 1);
    for(int i = 0; i < N; ++i){
      if(i) f *= i;
      A[i + N - 1] = a[i] * f;
    }

    T d = 1;

    std::vector<T> g(N);
    g[N - 1] = f.inv();
    for(int i = N - 2; i >= 0; --i) g[i] = g[i + 1] * (i + 1);

    std::vector<T> B(2 * N - 1);
    for(int i = 0; i < N; ++i){
      B[N - i - 1] = d * g[i];
      d *= c;
    }

    auto C = convolve(A, B);

    std::vector<T> ret(N);
    for(int i = 0; i < N; ++i) ret[i] = C[(N - 1) * 2 + i] * g[i];

    return ret;
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

