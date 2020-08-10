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


# :heavy_check_mark: Bernoulli number (FPS)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8fcb53b240254087f9d87015c4533bd0">Mylib/Combinatorics</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Combinatorics/bernoulli_number_fps.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-10 21:40:43+09:00




## Depends on

* :heavy_check_mark: <a href="factorial_table.cpp.html">Factorial table</a>
* :heavy_check_mark: <a href="../Convolution/formal_power_series.cpp.html">Formal power series</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/bernoulli_number/main.test.cpp.html">test/yosupo-judge/bernoulli_number/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/Convolution/formal_power_series.cpp"

/**
 * @title Bernoulli number (FPS)
 * @docs bernoulli_number_fps.md
 */
template <typename Fps, typename Ft>
auto bernoulli_number_fps(int N){
  Fps x(N + 1);

  for(int i = 0; i <= N; ++i) x[i] = Ft::inv_factorial(i + 1);
  x = x.inv();

  for(int i = 0; i <= N; ++i) x[i] *= Ft::factorial(i);

  return x;
}

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
 * @attention 使用前にinit関数を呼び出す
 */
template <typename T> class FactorialTable{
public:
  static std::vector<T> f_table;
  static std::vector<T> if_table;

  static void init(int N){
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
  
  static T factorial(int64_t i){
    assert(i < (int)f_table.size());
    return f_table[i];
  }
  
  static T inv_factorial(int64_t i){
    assert(i < (int)if_table.size());
    return if_table[i];
  }

  static T P(int64_t n, int64_t k);
  static T C(int64_t n, int64_t k);
  static T H(int64_t n, int64_t k);
  static T stirling_number(int64_t n, int64_t k);
  static T bell_number(int64_t n, int64_t k);
  static std::vector<T> bernoulli_number(int64_t n);
  static T catalan_number(int64_t n);
};

template <typename T> std::vector<T> FactorialTable<T>::f_table = std::vector<T>();
template <typename T> std::vector<T> FactorialTable<T>::if_table = std::vector<T>();

template <typename T> T FactorialTable<T>::P(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return factorial(n) * inv_factorial(n-k);
}

template <typename T> T FactorialTable<T>::C(int64_t n, int64_t k){
  if(n < k or n < 0 or k < 0) return 0;
  return P(n,k) * inv_factorial(k);
}

template <typename T> T FactorialTable<T>::H(int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  return C(n+k-1, k);
}
#line 2 "Mylib/Convolution/formal_power_series.cpp"

#include <functional>
#line 5 "Mylib/Convolution/formal_power_series.cpp"
#include <initializer_list>

/**
 * @title Formal power series
 * @docs formal_power_series.md
 */
template <typename T>
struct FormalPowerSeries{
  static std::function<std::vector<T>(std::vector<T>, std::vector<T>)> convolve;

  std::vector<T> data;

  FormalPowerSeries(const std::vector<T> &data): data(data){}
  FormalPowerSeries(std::initializer_list<T> init): data(init.begin(), init.end()){}
  FormalPowerSeries(int N): data(N){}
  
  int size() const {
    return data.size();
  }

  const T& operator[](int i) const {
    return data[i];
  }

  T& operator[](int i){
    return data[i];
  }

  auto begin() {return data.begin();}
  auto end() {return data.end();}

  void resize(int n){
    data.resize(n);
  }
  
  auto operator+(const FormalPowerSeries &rhs) const {
    std::vector<T> ret(data);
    ret.resize(rhs.size());
    for(int i = 0; i < (int)rhs.size(); ++i) ret[i] += rhs[i];
    return FormalPowerSeries(ret);
  }

  auto operator-(const FormalPowerSeries &rhs) const {
    std::vector<T> ret(data);
    ret.resize(rhs.size());
    for(int i = 0; i < (int)rhs.size(); ++i) ret[i] -= rhs[i];
    return FormalPowerSeries(ret);
  }

  auto operator*(const FormalPowerSeries &rhs) const {
    auto ret = convolve(data, rhs.data);
    return FormalPowerSeries(ret);
  }

  auto operator*(T b) const {
    std::vector<T> ret(data);
    for(auto &x : ret) x *= b;
    return FormalPowerSeries(ret);
  }

  auto differentiate() const {
    const int n = data.size();
    std::vector<T> ret(n-1);
    for(int i = 0; i < n-1; ++i){
      ret[i] = data[i+1] * (i + 1);
    }
    
    return FormalPowerSeries(ret);
  }

  auto integrate() const {
    const int n = data.size();
    std::vector<T> ret(n+1);
    for(int i = 0; i < n; ++i){
      ret[i+1] = data[i] / (i + 1);
    }

    return FormalPowerSeries(ret);
  }

  auto inv() const {
    assert(data[0] != 0);
    const int n = data.size();
    
    int t = 1;
    std::vector<T> ret = {data[0].inv()};
    ret.reserve(n * 2);
    
    while(t <= n * 2){
      std::vector<T> c(data.begin(), data.begin() + std::min(t, n));
      c = convolve(c, convolve(ret, ret));

      c.resize(t);
      ret.resize(t);

      for(int i = 0; i < t; ++i){
        ret[i] = ret[i] * 2 - c[i];
      }
      
      t <<= 1;
    }
    
    ret.resize(n);

    return FormalPowerSeries(ret);
  }

  auto log() const {
    assert(data[0] == 1);
    const int n = data.size();
    auto ret = (differentiate() * inv()).integrate();
    ret.resize(n);
    return ret;
  }

  auto exp() const {
    const int n = data.size();

    int t = 1;
    FormalPowerSeries b({1});

    while(t <= n * 2){
      t <<= 1;
      auto temp = b.log();
      temp.resize(t);

      for(int i = 0; i < t; ++i) temp[i] = -temp[i];
      temp[0] += 1;
      for(int i = 0; i < std::min(t, n); ++i) temp[i] += data[i];
      
      b = b * temp;
      b.resize(t);
    }
    
    b.resize(n);

    return b;
  }
};


template <typename T>
std::function<std::vector<T>(std::vector<T>, std::vector<T>)> FormalPowerSeries<T>::convolve;
#line 4 "Mylib/Combinatorics/bernoulli_number_fps.cpp"

/**
 * @title Bernoulli number (FPS)
 * @docs bernoulli_number_fps.md
 */
template <typename Fps, typename Ft>
auto bernoulli_number_fps(int N){
  Fps x(N + 1);

  for(int i = 0; i <= N; ++i) x[i] = Ft::inv_factorial(i + 1);
  x = x.inv();

  for(int i = 0; i <= N; ++i) x[i] *= Ft::factorial(i);

  return x;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

