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


# :heavy_check_mark: 誤差許容浮動小数点数

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#090220fbd726178f7b9d402d3ae3f683">Mylib/Geometry/Float</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Geometry/Float/double_eps.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/2136/main.test.cpp.html">test/aoj/2136/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/3034/main.test.cpp.html">test/aoj/3034/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_1_A/main.test.cpp.html">test/aoj/CGL_1_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_1_B/main.test.cpp.html">test/aoj/CGL_1_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_1_C/main.test.cpp.html">test/aoj/CGL_1_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_2_A/main.test.cpp.html">test/aoj/CGL_2_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_2_B/main.test.cpp.html">test/aoj/CGL_2_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_2_C/main.test.cpp.html">test/aoj/CGL_2_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_2_D/main.test.cpp.html">test/aoj/CGL_2_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_3_A/main.test.cpp.html">test/aoj/CGL_3_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_3_B/main.test.cpp.html">test/aoj/CGL_3_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_3_C/main.test.cpp.html">test/aoj/CGL_3_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_4_A/main.test.cpp.html">test/aoj/CGL_4_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_4_B/main.test.cpp.html">test/aoj/CGL_4_B/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_4_C/main.test.cpp.html">test/aoj/CGL_4_C/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_5_A/main.test.cpp.html">test/aoj/CGL_5_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_A/main.test.cpp.html">test/aoj/CGL_7_A/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_D/main.test.cpp.html">test/aoj/CGL_7_D/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_E/main.test.cpp.html">test/aoj/CGL_7_E/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_F/main.test.cpp.html">test/aoj/CGL_7_F/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_G/main.test.cpp.html">test/aoj/CGL_7_G/main.test.cpp</a>
* :heavy_check_mark: <a href="../../../../verify/test/aoj/CGL_7_H/main.test.cpp.html">test/aoj/CGL_7_H/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <limits>

/**
 * @title 誤差許容浮動小数点数
 * @docs double_eps.md
 */
template <typename T>
struct DoubleEps{
  using value_type = T;
  
  static T eps;

  T value;

  DoubleEps(): value(0){}
  DoubleEps(T value): value(value){}
  
  auto& operator=(const DoubleEps &rhs){this->value = rhs.value; return *this;}
  auto& operator+=(const DoubleEps &rhs){this->value += rhs.value; return *this;}
  auto& operator-=(const DoubleEps &rhs){this->value -= rhs.value; return *this;}
  auto& operator*=(const DoubleEps &rhs){this->value *= rhs.value; return *this;}
  auto& operator/=(const DoubleEps &rhs){this->value /= rhs.value; return *this;}

  auto operator+(const DoubleEps &rhs) const {return DoubleEps(this->value + rhs.value);}
  auto operator-(const DoubleEps &rhs) const {return DoubleEps(this->value - rhs.value);}
  auto operator*(const DoubleEps &rhs) const {return DoubleEps(this->value * rhs.value);}
  auto operator/(const DoubleEps &rhs) const {return DoubleEps(this->value / rhs.value);}

  bool operator==(const DoubleEps &rhs) const {return std::abs(this->value - rhs.value) < eps;}
  bool operator!=(const DoubleEps &rhs) const {return !(*this == rhs);}
  bool operator<(const DoubleEps &rhs) const {return this->value - rhs.value < -eps;}
  bool operator<=(const DoubleEps &rhs) const {return this->value - rhs.value < eps;}
  bool operator>(const DoubleEps &rhs) const {return !(*this <= rhs);}
  bool operator>=(const DoubleEps &rhs) const {return !(*this < rhs);}

  auto operator-() const {return DoubleEps(-(this->value));}
  
  explicit operator double() const noexcept {return value;}
  explicit operator long double() const noexcept {return value;}

  friend std::ostream& operator<<(std::ostream &s, const DoubleEps &rhs){s << rhs.value; return s;}
  friend std::istream& operator>>(std::istream &s, DoubleEps &rhs){s >> rhs.value; return s;}
};

template <typename T> T DoubleEps<T>::eps;

namespace std{
  template <typename T>
  class numeric_limits<DoubleEps<T>>{
  public:
    static DoubleEps<T> infinity() {return numeric_limits<T>::infinity();}
    static DoubleEps<T> min() {return numeric_limits<T>::min();}
    static DoubleEps<T> max() {return numeric_limits<T>::max();}
    static DoubleEps<T> lowest() {return numeric_limits<T>::lowest();}
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Geometry/Float/double_eps.cpp"
#include <iostream>
#include <limits>

/**
 * @title 誤差許容浮動小数点数
 * @docs double_eps.md
 */
template <typename T>
struct DoubleEps{
  using value_type = T;
  
  static T eps;

  T value;

  DoubleEps(): value(0){}
  DoubleEps(T value): value(value){}
  
  auto& operator=(const DoubleEps &rhs){this->value = rhs.value; return *this;}
  auto& operator+=(const DoubleEps &rhs){this->value += rhs.value; return *this;}
  auto& operator-=(const DoubleEps &rhs){this->value -= rhs.value; return *this;}
  auto& operator*=(const DoubleEps &rhs){this->value *= rhs.value; return *this;}
  auto& operator/=(const DoubleEps &rhs){this->value /= rhs.value; return *this;}

  auto operator+(const DoubleEps &rhs) const {return DoubleEps(this->value + rhs.value);}
  auto operator-(const DoubleEps &rhs) const {return DoubleEps(this->value - rhs.value);}
  auto operator*(const DoubleEps &rhs) const {return DoubleEps(this->value * rhs.value);}
  auto operator/(const DoubleEps &rhs) const {return DoubleEps(this->value / rhs.value);}

  bool operator==(const DoubleEps &rhs) const {return std::abs(this->value - rhs.value) < eps;}
  bool operator!=(const DoubleEps &rhs) const {return !(*this == rhs);}
  bool operator<(const DoubleEps &rhs) const {return this->value - rhs.value < -eps;}
  bool operator<=(const DoubleEps &rhs) const {return this->value - rhs.value < eps;}
  bool operator>(const DoubleEps &rhs) const {return !(*this <= rhs);}
  bool operator>=(const DoubleEps &rhs) const {return !(*this < rhs);}

  auto operator-() const {return DoubleEps(-(this->value));}
  
  explicit operator double() const noexcept {return value;}
  explicit operator long double() const noexcept {return value;}

  friend std::ostream& operator<<(std::ostream &s, const DoubleEps &rhs){s << rhs.value; return s;}
  friend std::istream& operator>>(std::istream &s, DoubleEps &rhs){s >> rhs.value; return s;}
};

template <typename T> T DoubleEps<T>::eps;

namespace std{
  template <typename T>
  class numeric_limits<DoubleEps<T>>{
  public:
    static DoubleEps<T> infinity() {return numeric_limits<T>::infinity();}
    static DoubleEps<T> min() {return numeric_limits<T>::min();}
    static DoubleEps<T> max() {return numeric_limits<T>::max();}
    static DoubleEps<T> lowest() {return numeric_limits<T>::lowest();}
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

