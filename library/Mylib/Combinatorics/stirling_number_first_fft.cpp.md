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


# :x: Stirling numbers of the first kind (FFT)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/stirling_number_first_fft.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-21 11:48:40+09:00




## Depends on

* :question: <a href="../Math/polynomial_taylor_shift.cpp.html">polynomial_taylor_shift.md</a>


## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp.html">test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Math/polynomial_taylor_shift.cpp"

/**
 * @title Stirling numbers of the first kind (FFT)
 * @docs stirling_number_first_fft.md
 */
template <typename T, typename Conv>
std::vector<T> stirling_number_of_first_kind(int N, const Conv &convolve){
  if(N == 0) return {1};
  
  std::vector<int> p;
  {
    int a = N;

    while(a > 0){
      if(a & 1) p.push_back(1);
      p.push_back(2);
      a >>= 1;
    }
  }

  std::vector<T> ret = {1};

  std::reverse(p.begin(), p.end());
  int t = 0;
  for(int x : p){
    if(x == 1){
      std::vector<T> a = {-t, 1};
      ret = convolve(ret, a);
      
      t += 1;
    }else{
      auto s = polynomial_taylor_shift<T>(ret, -t, convolve);
      ret = convolve(ret, s);
      ret.resize(t * 2 + 1);

      t *= 2;
    }
  }

  ret.resize(N + 1);

  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/stirling_number_first_fft.cpp"
#include <vector>
#include <algorithm>
#line 3 "Mylib/Math/polynomial_taylor_shift.cpp"

/**
 * @docs Polynomial Taylor shift
 * @title polynomial_taylor_shift.md
 */
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

#line 5 "Mylib/Combinatorics/stirling_number_first_fft.cpp"

/**
 * @title Stirling numbers of the first kind (FFT)
 * @docs stirling_number_first_fft.md
 */
template <typename T, typename Conv>
std::vector<T> stirling_number_of_first_kind(int N, const Conv &convolve){
  if(N == 0) return {1};
  
  std::vector<int> p;
  {
    int a = N;

    while(a > 0){
      if(a & 1) p.push_back(1);
      p.push_back(2);
      a >>= 1;
    }
  }

  std::vector<T> ret = {1};

  std::reverse(p.begin(), p.end());
  int t = 0;
  for(int x : p){
    if(x == 1){
      std::vector<T> a = {-t, 1};
      ret = convolve(ret, a);
      
      t += 1;
    }else{
      auto s = polynomial_taylor_shift<T>(ret, -t, convolve);
      ret = convolve(ret, s);
      ret.resize(t * 2 + 1);

      t *= 2;
    }
  }

  ret.resize(N + 1);

  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

