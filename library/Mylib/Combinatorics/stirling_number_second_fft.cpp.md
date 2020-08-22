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


# :x: Stirling numbers of the second kind (FFT)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/stirling_number_second_fft.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-19 18:49:32+09:00




## Verified with

* :x: <a href="../../../verify/test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp.html">test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>

/**
 * @title Stirling numbers of the second kind (FFT)
 * @docs stirling_number_second_fft.md
 */
template <typename T, typename Conv>
auto stirling_number_of_second_kind(int N, const Conv &convolve){
  std::vector<T> a(N+1), b(N+1);

  std::vector<int> m(N+1, 0);
  for(int i = 2; i <= N; ++i){
    if(m[i] != 0) continue;
    for(int j = 2 * i; j <= N; j += i){
      m[j] = i;
    }
  }

  for(int i = 0; i <= N; ++i){
    if(m[i] == 0){
      a[i] = T::power(i, N);
    }else{
      a[i] = a[m[i]] * a[i / m[i]];
    }
  }
    
  T f = 1;
  for(int i = 1; i <= N; ++i) f *= i;
  f = f.inv();

  for(int i = N; i >= 0; --i){
    a[i] *= f;
    b[i] = f;
    f *= i;

    if(i % 2 == 1){
      b[i] = -b[i];
    }
  }

  auto ret = convolve(a, b);
  ret.resize(N + 1);
  
  return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Combinatorics/stirling_number_second_fft.cpp"
#include <vector>

/**
 * @title Stirling numbers of the second kind (FFT)
 * @docs stirling_number_second_fft.md
 */
template <typename T, typename Conv>
auto stirling_number_of_second_kind(int N, const Conv &convolve){
  std::vector<T> a(N+1), b(N+1);

  std::vector<int> m(N+1, 0);
  for(int i = 2; i <= N; ++i){
    if(m[i] != 0) continue;
    for(int j = 2 * i; j <= N; j += i){
      m[j] = i;
    }
  }

  for(int i = 0; i <= N; ++i){
    if(m[i] == 0){
      a[i] = T::power(i, N);
    }else{
      a[i] = a[m[i]] * a[i / m[i]];
    }
  }
    
  T f = 1;
  for(int i = 1; i <= N; ++i) f *= i;
  f = f.inv();

  for(int i = N; i >= 0; --i){
    a[i] *= f;
    b[i] = f;
    f *= i;

    if(i % 2 == 1){
      b[i] = -b[i];
    }
  }

  auto ret = convolve(a, b);
  ret.resize(N + 1);
  
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

