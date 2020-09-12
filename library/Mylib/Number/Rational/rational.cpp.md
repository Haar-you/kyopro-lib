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


# :heavy_check_mark: Rational number

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e55110d6133c602b43ca77c4caba1f06">Mylib/Number/Rational</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Rational/rational.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../../../verify/test/aoj/1300/main.test.cpp.html">test/aoj/1300/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <numeric>
#include <iostream>
#include <cmath>

/**
 * @title Rational number
 * @docs rational.md
 */
namespace haar_lib {
  class rational {
  public:
    int64_t nume, deno;
    rational(): nume(0), deno(1){}
    rational(int64_t num): nume(num), deno(1){}
    rational(int64_t num, int64_t den){
      int64_t g = std::gcd(num, den);
      nume = num / g;
      deno = den / g;
      if(deno < 0){
        nume = -nume;
        deno = -deno;
      }
    }

    auto operator+(const rational &b){
      int64_t l = std::lcm((*this).deno, b.deno);
      return rational(l / (*this).deno * (*this).nume + l / b.deno * b.nume, l);
    }

    auto operator-(const rational &b){
      int64_t l = std::lcm((*this).deno, b.deno);
      return rational(l / (*this).deno * (*this).nume - l / b.deno * b.nume, l);
    }

    auto operator*(const rational &b){
      return rational((*this).nume * b.nume, (*this).deno * b.deno);
    }

    auto operator/(const rational &b){
      return rational((*this).nume * b.deno, (*this).deno * b.nume);
    }

    auto& operator+=(const rational &a){*this = *this + a; return *this;}
    auto& operator-=(const rational &a){*this = *this - a; return *this;}
    auto& operator*=(const rational &a){*this = *this * a; return *this;}
    auto& operator/=(const rational &a){*this = *this / a; return *this;}

    explicit operator double() const {return (double)nume / deno;}
    explicit operator long double() const {return (long double)nume / deno;}
  };

  std::ostream& operator<<(std::ostream &os, const rational &r){
    if(r.deno == 1) os << r.nume;
    else os << r.nume << "/" << r.deno;
    return os;
  }

  auto operator-(const rational &a){return rational(-a.nume, a.deno);}

  bool operator==(const rational &a, const rational &b){return a.nume == b.nume && a.deno == b.deno;}
  bool operator!=(const rational &a, const rational &b){return !(a == b);}
  bool operator<(const rational &a, const rational &b){return a.nume * b.deno < b.nume * a.deno;}
  bool operator<=(const rational &a, const rational &b){return a.nume * b.deno <= b.nume * a.deno;}
  bool operator>(const rational &a, const rational &b){return !(a <= b);}
  bool operator>=(const rational &a, const rational &b){return !(a < b);}

  auto abs(const rational &a){return rational(std::abs(a.nume), std::abs(a.deno));}
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Rational/rational.cpp"
#include <numeric>
#include <iostream>
#include <cmath>

/**
 * @title Rational number
 * @docs rational.md
 */
namespace haar_lib {
  class rational {
  public:
    int64_t nume, deno;
    rational(): nume(0), deno(1){}
    rational(int64_t num): nume(num), deno(1){}
    rational(int64_t num, int64_t den){
      int64_t g = std::gcd(num, den);
      nume = num / g;
      deno = den / g;
      if(deno < 0){
        nume = -nume;
        deno = -deno;
      }
    }

    auto operator+(const rational &b){
      int64_t l = std::lcm((*this).deno, b.deno);
      return rational(l / (*this).deno * (*this).nume + l / b.deno * b.nume, l);
    }

    auto operator-(const rational &b){
      int64_t l = std::lcm((*this).deno, b.deno);
      return rational(l / (*this).deno * (*this).nume - l / b.deno * b.nume, l);
    }

    auto operator*(const rational &b){
      return rational((*this).nume * b.nume, (*this).deno * b.deno);
    }

    auto operator/(const rational &b){
      return rational((*this).nume * b.deno, (*this).deno * b.nume);
    }

    auto& operator+=(const rational &a){*this = *this + a; return *this;}
    auto& operator-=(const rational &a){*this = *this - a; return *this;}
    auto& operator*=(const rational &a){*this = *this * a; return *this;}
    auto& operator/=(const rational &a){*this = *this / a; return *this;}

    explicit operator double() const {return (double)nume / deno;}
    explicit operator long double() const {return (long double)nume / deno;}
  };

  std::ostream& operator<<(std::ostream &os, const rational &r){
    if(r.deno == 1) os << r.nume;
    else os << r.nume << "/" << r.deno;
    return os;
  }

  auto operator-(const rational &a){return rational(-a.nume, a.deno);}

  bool operator==(const rational &a, const rational &b){return a.nume == b.nume && a.deno == b.deno;}
  bool operator!=(const rational &a, const rational &b){return !(a == b);}
  bool operator<(const rational &a, const rational &b){return a.nume * b.deno < b.nume * a.deno;}
  bool operator<=(const rational &a, const rational &b){return a.nume * b.deno <= b.nume * a.deno;}
  bool operator>(const rational &a, const rational &b){return !(a <= b);}
  bool operator>=(const rational &a, const rational &b){return !(a < b);}

  auto abs(const rational &a){return rational(std::abs(a.nume), std::abs(a.deno));}
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

