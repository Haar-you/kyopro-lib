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


# :warning: 有理数クラス

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e55110d6133c602b43ca77c4caba1f06">Mylib/Number/Rational</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Number/Rational/rational.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 16:54:34+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <numeric>
#include <iostream>

/**
 * @title 有理数クラス
 */
class Rational{
public:
  int64_t nume, deno;
  Rational(): nume(0), deno(1){}
  Rational(int64_t num): nume(num), deno(1){} 
  Rational(int64_t num, int64_t den){
    int64_t g = std::gcd(num,den);
    nume = num/g;
    deno = den/g;
    if(deno < 0){
      nume = -nume;
      deno = -deno;
    }
  }
  Rational& operator+=(const Rational &a);
  Rational& operator-=(const Rational &a);
  Rational& operator*=(const Rational &a);
  Rational& operator/=(const Rational &a);
};

std::ostream& operator<<(std::ostream &os, const Rational &r){
  if(r.deno == 1){
    os << r.nume;
  }else{
    os << r.nume << "/" << r.deno;
  }
  
  return os;
}

Rational operator-(const Rational &a){return Rational(-a.nume, a.deno);}

Rational operator+(const Rational &a, const Rational &b){int64_t l = std::lcm(a.deno,b.deno); return Rational(l/a.deno*a.nume + l/b.deno*b.nume, l);}
Rational operator-(const Rational &a, const Rational &b){int64_t l = std::lcm(a.deno,b.deno); return Rational(l/a.deno*a.nume - l/b.deno*b.nume, l);}
Rational operator*(const Rational &a, const Rational &b){return Rational(a.nume*b.nume, a.deno*b.deno);}
Rational operator/(const Rational &a, const Rational &b){return Rational(a.nume*b.deno, a.deno*b.nume);}

bool operator==(const Rational &a, const Rational &b){return a.nume == b.nume && a.deno == b.deno;}
bool operator!=(const Rational &a, const Rational &b){return !(a==b);}
bool operator<(const Rational &a, const Rational &b){return a.nume*b.deno < b.nume*a.deno;}
bool operator<=(const Rational &a, const Rational &b){return a.nume*b.deno <= b.nume*a.deno;}
bool operator>(const Rational &a, const Rational &b){return !(a<=b);}
bool operator>=(const Rational &a, const Rational &b){return !(a<b);}

double to_double(const Rational &a){return (double)a.nume/a.deno;}

Rational& Rational::operator+=(const Rational &a){*this = *this+a; return *this;}
Rational& Rational::operator-=(const Rational &a){*this = *this-a; return *this;}
Rational& Rational::operator*=(const Rational &a){*this = *this*a; return *this;}
Rational& Rational::operator/=(const Rational &a){*this = *this/a; return *this;}

Rational abs(const Rational &a){return Rational(abs(a.nume), abs(a.deno));}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Number/Rational/rational.cpp"
#include <numeric>
#include <iostream>

/**
 * @title 有理数クラス
 */
class Rational{
public:
  int64_t nume, deno;
  Rational(): nume(0), deno(1){}
  Rational(int64_t num): nume(num), deno(1){} 
  Rational(int64_t num, int64_t den){
    int64_t g = std::gcd(num,den);
    nume = num/g;
    deno = den/g;
    if(deno < 0){
      nume = -nume;
      deno = -deno;
    }
  }
  Rational& operator+=(const Rational &a);
  Rational& operator-=(const Rational &a);
  Rational& operator*=(const Rational &a);
  Rational& operator/=(const Rational &a);
};

std::ostream& operator<<(std::ostream &os, const Rational &r){
  if(r.deno == 1){
    os << r.nume;
  }else{
    os << r.nume << "/" << r.deno;
  }
  
  return os;
}

Rational operator-(const Rational &a){return Rational(-a.nume, a.deno);}

Rational operator+(const Rational &a, const Rational &b){int64_t l = std::lcm(a.deno,b.deno); return Rational(l/a.deno*a.nume + l/b.deno*b.nume, l);}
Rational operator-(const Rational &a, const Rational &b){int64_t l = std::lcm(a.deno,b.deno); return Rational(l/a.deno*a.nume - l/b.deno*b.nume, l);}
Rational operator*(const Rational &a, const Rational &b){return Rational(a.nume*b.nume, a.deno*b.deno);}
Rational operator/(const Rational &a, const Rational &b){return Rational(a.nume*b.deno, a.deno*b.nume);}

bool operator==(const Rational &a, const Rational &b){return a.nume == b.nume && a.deno == b.deno;}
bool operator!=(const Rational &a, const Rational &b){return !(a==b);}
bool operator<(const Rational &a, const Rational &b){return a.nume*b.deno < b.nume*a.deno;}
bool operator<=(const Rational &a, const Rational &b){return a.nume*b.deno <= b.nume*a.deno;}
bool operator>(const Rational &a, const Rational &b){return !(a<=b);}
bool operator>=(const Rational &a, const Rational &b){return !(a<b);}

double to_double(const Rational &a){return (double)a.nume/a.deno;}

Rational& Rational::operator+=(const Rational &a){*this = *this+a; return *this;}
Rational& Rational::operator-=(const Rational &a){*this = *this-a; return *this;}
Rational& Rational::operator*=(const Rational &a){*this = *this*a; return *this;}
Rational& Rational::operator/=(const Rational &a){*this = *this/a; return *this;}

Rational abs(const Rational &a){return Rational(abs(a.nume), abs(a.deno));}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

