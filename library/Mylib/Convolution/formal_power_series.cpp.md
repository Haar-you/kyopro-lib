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


# :heavy_check_mark: Formal power series

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d1ac32c11c508fec0764fa012d8d2913">Mylib/Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Convolution/formal_power_series.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-10 20:50:39+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://www.hamayanhamayan.com/entry/2019/12/07/000441](https://www.hamayanhamayan.com/entry/2019/12/07/000441)
- [https://www.hamayanhamayan.com/entry/2019/12/14/221205](https://www.hamayanhamayan.com/entry/2019/12/14/221205)
- [https://maspypy.com/多項式・形式的べき級数数え上げとの対応付け](https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e6%95%b0%e3%81%88%e4%b8%8a%e3%81%92%e3%81%a8%e3%81%ae%e5%af%be%e5%bf%9c%e4%bb%98%e3%81%91)
- [https://codeforces.com/blog/entry/56422](https://codeforces.com/blog/entry/56422)
- [https://beet-aizu.hatenablog.com/entry/2019/09/27/224701](https://beet-aizu.hatenablog.com/entry/2019/09/27/224701)
- [https://kopricky.github.io/code/FFTs/polynomial_division.html](https://kopricky.github.io/code/FFTs/polynomial_division.html)
- [https://kopricky.github.io/code/FFTs/polynomial_exp.html](https://kopricky.github.io/code/FFTs/polynomial_exp.html)
- [https://kopricky.github.io/code/FFTs/polynomial_inverse.html](https://kopricky.github.io/code/FFTs/polynomial_inverse.html)
- [https://kopricky.github.io/code/FFTs/polynomial_log.html](https://kopricky.github.io/code/FFTs/polynomial_log.html)



## Required by

* :heavy_check_mark: <a href="../Combinatorics/bernoulli_number_fps.cpp.html">Bernoulli number (FPS)</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/bernoulli_number/main.test.cpp.html">test/yosupo-judge/bernoulli_number/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/exp_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/exp_of_formal_power_series/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/inv_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/inv_of_formal_power_series/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../verify/test/yosupo-judge/log_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/log_of_formal_power_series/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <functional>
#include <vector>
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Convolution/formal_power_series.cpp"

#include <functional>
#include <vector>
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

