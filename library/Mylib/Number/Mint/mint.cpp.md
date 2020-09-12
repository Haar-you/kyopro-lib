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


# :x: Modint

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ed8374f4a8b62e2301eb75f9564224fe">Mylib/Number/Mint</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Mint/mint.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Required by

* :x: <a href="../../Convolution/ntt_convolution.cpp.html">Number theoretic transform</a>


## Verified with

* :x: <a href="../../../../verify/test/aoj/3119/main.test.cpp.html">test/aoj/3119/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DPL_5_G/main.table.test.cpp.html">test/aoj/DPL_5_G/main.table.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DPL_5_G/main.test.cpp.html">test/aoj/DPL_5_G/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DPL_5_I/main.table.test.cpp.html">test/aoj/DPL_5_I/main.table.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DPL_5_I/main.test.cpp.html">test/aoj/DPL_5_I/main.test.cpp</a>
* :x: <a href="../../../../verify/test/aoj/DPL_5_J/main.test.cpp.html">test/aoj/DPL_5_J/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/bernoulli_number/main.test.cpp.html">test/yosupo-judge/bernoulli_number/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/convolution_mod/main.test.cpp.html">test/yosupo-judge/convolution_mod/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/convolution_mod_1000000007/main.test.cpp.html">test/yosupo-judge/convolution_mod_1000000007/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/enumerate_triangles/main.test.cpp.html">test/yosupo-judge/enumerate_triangles/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/exp_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/exp_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/inv_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/inv_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/log_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/log_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/matrix_det/main.test.cpp.html">test/yosupo-judge/matrix_det/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/partition_function/main.fps.test.cpp.html">test/yosupo-judge/partition_function/main.fps.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/partition_function/main.test.cpp.html">test/yosupo-judge/partition_function/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/point_set_range_composite/main.test.cpp.html">test/yosupo-judge/point_set_range_composite/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/polynomial_taylor_shift/main.test.cpp.html">test/yosupo-judge/polynomial_taylor_shift/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/pow_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/pow_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/queue_operate_all_composite/main.test.cpp.html">test/yosupo-judge/queue_operate_all_composite/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/range_affine_range_sum/main.test.cpp.html">test/yosupo-judge/range_affine_range_sum/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/sharp_p_subset_sum/main.test.cpp.html">test/yosupo-judge/sharp_p_subset_sum/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp.html">test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp.html">test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp.html">test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/system_of_linear_equations/main.test.cpp.html">test/yosupo-judge/system_of_linear_equations/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yosupo-judge/vertex_set_path_composite/main.test.cpp.html">test/yosupo-judge/vertex_set_path_composite/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/1084/main.test.cpp.html">test/yukicoder/1084/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/117/main.test.cpp.html">test/yukicoder/117/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/194/main.test.cpp.html">test/yukicoder/194/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/510/main.test.cpp.html">test/yukicoder/510/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/658/main.test.cpp.html">test/yukicoder/658/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/660/main.test.cpp.html">test/yukicoder/660/main.test.cpp</a>
* :x: <a href="../../../../verify/test/yukicoder/665/main.test.cpp.html">test/yukicoder/665/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>
#include <utility>

/**
 * @title Modint
 * @docs mint.md
 */
namespace haar_lib {
  template <int32_t M>
  class modint {
  public:
    constexpr static int32_t MOD = M;
    uint32_t val;

    constexpr modint(): val(0){}
    constexpr modint(int64_t n){
      if(n >= M) val = n % M;
      else if(n < 0) val = n % M + M;
      else val = n;
    }

    constexpr auto& operator=(const modint &a){val = a.val; return *this;}
    constexpr auto& operator+=(const modint &a){
      if(val + a.val >= M) val = (uint64_t)val + a.val - M;
      else val += a.val;
      return *this;
    }
    constexpr auto& operator-=(const modint &a){
      if(val < a.val) val += M;
      val -= a.val;
      return *this;
    }
    constexpr auto& operator*=(const modint &a){
      val = (uint64_t)val * a.val % M;
      return *this;
    }
    constexpr auto& operator/=(const modint &a){
      val = (uint64_t)val * a.inv().val % M;
      return *this;
    }

    constexpr auto operator+(const modint &a) const {return modint(*this) += a;}
    constexpr auto operator-(const modint &a) const {return modint(*this) -= a;}
    constexpr auto operator*(const modint &a) const {return modint(*this) *= a;}
    constexpr auto operator/(const modint &a) const {return modint(*this) /= a;}

    constexpr bool operator==(const modint &a) const {return val == a.val;}
    constexpr bool operator!=(const modint &a) const {return val != a.val;}

    constexpr auto& operator++(){*this += 1; return *this;}
    constexpr auto& operator--(){*this -= 1; return *this;}

    constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
    constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}

    constexpr static modint power(int64_t n, int64_t p){
      if(p < 0) return power(n, -p).inv();

      int64_t ret = 1, e = n % M;
      for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
      return ret;
    }

    constexpr static modint inv(int64_t a){
      int64_t b = M, u = 1, v = 0;

      while(b){
        int64_t t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
      }

      u %= M;
      if(u < 0) u += M;

      return u;
    }

    constexpr static auto frac(int64_t a, int64_t b){return modint(a) / modint(b);}

    constexpr auto power(int64_t p) const {return power(val, p);}
    constexpr auto inv() const {return inv(val);}

    friend constexpr auto operator-(const modint &a){return modint(M - a.val);}

    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a) + b;}
    friend constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}
    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a) * b;}
    friend constexpr auto operator/(int64_t a, const modint &b){return modint(a) / b;}

    friend std::istream& operator>>(std::istream &s, modint<M> &a){s >> a.val; return s;}
    friend std::ostream& operator<<(std::ostream &s, const modint<M> &a){s << a.val; return s;}

    template <int N>
    static auto div(){
      static auto value = inv(N);
      return value;
    }

    explicit operator int32_t() const noexcept {return val;}
    explicit operator int64_t() const noexcept {return val;}
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Mint/mint.cpp"
#include <iostream>
#include <utility>

/**
 * @title Modint
 * @docs mint.md
 */
namespace haar_lib {
  template <int32_t M>
  class modint {
  public:
    constexpr static int32_t MOD = M;
    uint32_t val;

    constexpr modint(): val(0){}
    constexpr modint(int64_t n){
      if(n >= M) val = n % M;
      else if(n < 0) val = n % M + M;
      else val = n;
    }

    constexpr auto& operator=(const modint &a){val = a.val; return *this;}
    constexpr auto& operator+=(const modint &a){
      if(val + a.val >= M) val = (uint64_t)val + a.val - M;
      else val += a.val;
      return *this;
    }
    constexpr auto& operator-=(const modint &a){
      if(val < a.val) val += M;
      val -= a.val;
      return *this;
    }
    constexpr auto& operator*=(const modint &a){
      val = (uint64_t)val * a.val % M;
      return *this;
    }
    constexpr auto& operator/=(const modint &a){
      val = (uint64_t)val * a.inv().val % M;
      return *this;
    }

    constexpr auto operator+(const modint &a) const {return modint(*this) += a;}
    constexpr auto operator-(const modint &a) const {return modint(*this) -= a;}
    constexpr auto operator*(const modint &a) const {return modint(*this) *= a;}
    constexpr auto operator/(const modint &a) const {return modint(*this) /= a;}

    constexpr bool operator==(const modint &a) const {return val == a.val;}
    constexpr bool operator!=(const modint &a) const {return val != a.val;}

    constexpr auto& operator++(){*this += 1; return *this;}
    constexpr auto& operator--(){*this -= 1; return *this;}

    constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
    constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}

    constexpr static modint power(int64_t n, int64_t p){
      if(p < 0) return power(n, -p).inv();

      int64_t ret = 1, e = n % M;
      for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
      return ret;
    }

    constexpr static modint inv(int64_t a){
      int64_t b = M, u = 1, v = 0;

      while(b){
        int64_t t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
      }

      u %= M;
      if(u < 0) u += M;

      return u;
    }

    constexpr static auto frac(int64_t a, int64_t b){return modint(a) / modint(b);}

    constexpr auto power(int64_t p) const {return power(val, p);}
    constexpr auto inv() const {return inv(val);}

    friend constexpr auto operator-(const modint &a){return modint(M - a.val);}

    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a) + b;}
    friend constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}
    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a) * b;}
    friend constexpr auto operator/(int64_t a, const modint &b){return modint(a) / b;}

    friend std::istream& operator>>(std::istream &s, modint<M> &a){s >> a.val; return s;}
    friend std::ostream& operator<<(std::ostream &s, const modint<M> &a){s << a.val; return s;}

    template <int N>
    static auto div(){
      static auto value = inv(N);
      return value;
    }

    explicit operator int32_t() const noexcept {return val;}
    explicit operator int64_t() const noexcept {return val;}
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
