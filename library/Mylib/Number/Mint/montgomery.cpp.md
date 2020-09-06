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


# :warning: Montgomery multiplication

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#ed8374f4a8b62e2301eb75f9564224fe">Mylib/Number/Mint</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Mint/montgomery.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>

/**
 * @title Montgomery multiplication
 * @docs montgomery.md
 */
template <int64_t M_>
struct Montgomery {
  constexpr static int64_t MOD = M_;
  constexpr static int b = 64 - __builtin_clzll(MOD);
  constexpr static int64_t R = 1LL << b;
  constexpr static int64_t R2 = (R % MOD) * (R % MOD) % MOD;

  constexpr static int64_t mask = R - 1;

  constexpr static int64_t init(){
    int64_t ret = 0, r = R, i = 1, t = 0;
    while(r > 1){
      if(t % 2 == 0) t += MOD, ret += i;
      t >>= 1, r >>= 1, i <<= 1;
    }
    return ret;
  }

  constexpr static int64_t m = init();

  static_assert(R > MOD, "R > MOD");
  static_assert((R & (R - 1)) == 0, "R must be power of 2");

  static int64_t reduce(int64_t T){
    int64_t ret = ((((T & mask) * m) & mask) * MOD + T) >> b;
    if(ret >= MOD) ret -= MOD;
    return ret;
  }

  int64_t val;

  Montgomery(): val(0){}
  Montgomery(int64_t a){
    if(a < 0){
      if(a < -MOD) a = a % MOD + MOD;
      else a += MOD;
    }else if(a >= MOD){
      if(a < 2 * MOD) a -= MOD;
      else a %= MOD;
    }

    val = reduce(a * R2);
  }
  Montgomery(const Montgomery &that): val(that.val){}

  auto& operator+=(const Montgomery &that){
    val += that.val;
    if(val >= MOD) val -= MOD;
    return *this;
  }

  auto& operator-=(const Montgomery &that){
    val -= that.val;
    if(val < 0) val += MOD;
    return *this;
  }

  auto& operator*=(const Montgomery &that){
    val = reduce(val * that.val);
    return *this;
  }

  auto& operator/=(const Montgomery &that){
    *this *= that.inv();
    return *this;
  }

  auto operator-() const {
    Montgomery ret(0);
    ret -= *this;
    return ret;
  }

  auto operator+(const Montgomery &that) const {auto ret = *this; return ret += that;}
  auto operator-(const Montgomery &that) const {auto ret = *this; return ret -= that;}
  auto operator*(const Montgomery &that) const {auto ret = *this; return ret *= that;}
  auto operator/(const Montgomery &that) const {auto ret = *this; return ret /= that;}

  auto power(int64_t p) const {
    Montgomery ret = 1, e = *this;

    while(p > 0){
      if(p & 1) ret *= e;
      e *= e;
      p >>= 1;
    }

    return ret;
  }

  static auto power(int64_t n, int64_t p){return Montgomery(n).power(p);}

  auto inv() const {return power(MOD - 2);}
  static auto inv(int64_t n){return Montgomery(n).inv();}

  friend auto operator+(int64_t a, const Montgomery &b) {return Montgomery(a) + b;}
  friend auto operator-(int64_t a, const Montgomery &b) {return Montgomery(a) - b;}
  friend auto operator*(int64_t a, const Montgomery &b) {return Montgomery(a) * b;}
  friend auto operator/(int64_t a, const Montgomery &b) {return Montgomery(a) / b;}

  bool operator==(const Montgomery &that) const {
    return (val >= MOD ? val - MOD : val) == (that.val >= MOD ? that.val - MOD : that.val);
  }

  bool operator!=(const Montgomery &that) const {return !(*this == that);}

  friend std::ostream& operator<<(std::ostream& s, const Montgomery &a){
    return s << reduce(a.val);
  }

  friend std::istream& operator>>(std::istream& s, Montgomery &a){
    int64_t t; s >> t;
    a = Montgomery(t);
    return s;
  }

  explicit operator int32_t() const {return reduce(val);}
  explicit operator int64_t() const {return reduce(val);}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Mint/montgomery.cpp"
#include <iostream>

/**
 * @title Montgomery multiplication
 * @docs montgomery.md
 */
template <int64_t M_>
struct Montgomery {
  constexpr static int64_t MOD = M_;
  constexpr static int b = 64 - __builtin_clzll(MOD);
  constexpr static int64_t R = 1LL << b;
  constexpr static int64_t R2 = (R % MOD) * (R % MOD) % MOD;

  constexpr static int64_t mask = R - 1;

  constexpr static int64_t init(){
    int64_t ret = 0, r = R, i = 1, t = 0;
    while(r > 1){
      if(t % 2 == 0) t += MOD, ret += i;
      t >>= 1, r >>= 1, i <<= 1;
    }
    return ret;
  }

  constexpr static int64_t m = init();

  static_assert(R > MOD, "R > MOD");
  static_assert((R & (R - 1)) == 0, "R must be power of 2");

  static int64_t reduce(int64_t T){
    int64_t ret = ((((T & mask) * m) & mask) * MOD + T) >> b;
    if(ret >= MOD) ret -= MOD;
    return ret;
  }

  int64_t val;

  Montgomery(): val(0){}
  Montgomery(int64_t a){
    if(a < 0){
      if(a < -MOD) a = a % MOD + MOD;
      else a += MOD;
    }else if(a >= MOD){
      if(a < 2 * MOD) a -= MOD;
      else a %= MOD;
    }

    val = reduce(a * R2);
  }
  Montgomery(const Montgomery &that): val(that.val){}

  auto& operator+=(const Montgomery &that){
    val += that.val;
    if(val >= MOD) val -= MOD;
    return *this;
  }

  auto& operator-=(const Montgomery &that){
    val -= that.val;
    if(val < 0) val += MOD;
    return *this;
  }

  auto& operator*=(const Montgomery &that){
    val = reduce(val * that.val);
    return *this;
  }

  auto& operator/=(const Montgomery &that){
    *this *= that.inv();
    return *this;
  }

  auto operator-() const {
    Montgomery ret(0);
    ret -= *this;
    return ret;
  }

  auto operator+(const Montgomery &that) const {auto ret = *this; return ret += that;}
  auto operator-(const Montgomery &that) const {auto ret = *this; return ret -= that;}
  auto operator*(const Montgomery &that) const {auto ret = *this; return ret *= that;}
  auto operator/(const Montgomery &that) const {auto ret = *this; return ret /= that;}

  auto power(int64_t p) const {
    Montgomery ret = 1, e = *this;

    while(p > 0){
      if(p & 1) ret *= e;
      e *= e;
      p >>= 1;
    }

    return ret;
  }

  static auto power(int64_t n, int64_t p){return Montgomery(n).power(p);}

  auto inv() const {return power(MOD - 2);}
  static auto inv(int64_t n){return Montgomery(n).inv();}

  friend auto operator+(int64_t a, const Montgomery &b) {return Montgomery(a) + b;}
  friend auto operator-(int64_t a, const Montgomery &b) {return Montgomery(a) - b;}
  friend auto operator*(int64_t a, const Montgomery &b) {return Montgomery(a) * b;}
  friend auto operator/(int64_t a, const Montgomery &b) {return Montgomery(a) / b;}

  bool operator==(const Montgomery &that) const {
    return (val >= MOD ? val - MOD : val) == (that.val >= MOD ? that.val - MOD : that.val);
  }

  bool operator!=(const Montgomery &that) const {return !(*this == that);}

  friend std::ostream& operator<<(std::ostream& s, const Montgomery &a){
    return s << reduce(a.val);
  }

  friend std::istream& operator>>(std::istream& s, Montgomery &a){
    int64_t t; s >> t;
    a = Montgomery(t);
    return s;
  }

  explicit operator int32_t() const {return reduce(val);}
  explicit operator int64_t() const {return reduce(val);}
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

