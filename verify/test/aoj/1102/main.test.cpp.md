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


# :heavy_check_mark: test/aoj/1102/main.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#4598a1e201d64d438fead37b702299e0">test/aoj/1102</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/1102/main.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 05:58:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/Mylib/Parser/parser.cpp.html">Parsing</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102"

#include <iostream>
#include <string>
#include "Mylib/Parser/parser.cpp"

struct Complex{
  int real, imag;
  bool overflow;

  Complex(): real(0), imag(0), overflow(false){}
  Complex(int real, int imag = 0): real(real), imag(imag), overflow(false){
    if(abs(real) > 10000 or abs(imag) > 10000) overflow = true;
  }
  Complex(bool overflow): real(0), imag(0), overflow(true){}

  friend Complex operator+(const Complex &a, const Complex &b){
    if(a.overflow or b.overflow) return Complex(true);
    return Complex(a.real+b.real, a.imag+b.imag);
  }

  friend Complex operator-(const Complex &a, const Complex &b){
    if(a.overflow or b.overflow) return Complex(true);
    return Complex(a.real-b.real, a.imag-b.imag);
  }

  friend Complex operator-(const Complex &a){
    if(a.overflow) return Complex(true);
    return Complex(-a.real, -a.imag);
  }

  friend Complex operator*(const Complex &a, const Complex &b){
    if(a.overflow or b.overflow) return Complex(true);
    return Complex(a.real*b.real-a.imag*b.imag, a.real*b.imag+a.imag*b.real);
  }

  Complex& operator=(const Complex &a){
    this->real = a.real;
    this->imag = a.imag;
    this->overflow = a.overflow;
    return *this;
  }

  Complex& operator+=(const Complex &a){
    *this = *this + a;
    return *this;
  }

  Complex& operator-=(const Complex &a){
    *this = *this - a;
    return *this;
  }

  Complex& operator*=(const Complex &a){
    *this = *this * a;
    return *this;
  }
};


std::ostream& operator<<(std::ostream &os, const Complex &a){
  if(a.overflow) os << "overflow";
  else{
    if(a.real == 0 and a.imag == 0) os << 0;
    else{
      if(a.real){
        os << a.real;
      }
      if(a.imag){
        if(a.imag > 0 and a.real) os << "+"; 
        os << a.imag;
        os << "i";
      }
    }
  }
  return os;
}


struct parser : Parser{
  parser(const std::string &s): Parser(s){}

  Complex number(){
    bool neg = false;
    if(check_and_ignore('-')) neg = true;
    
    Complex ret;

    if(digit()){
      ret = get_number<Complex>();
      
      if(check_and_ignore('i')){
        ret *= Complex(0,1);
      }
    }else{
      if(check_and_ignore('i')){
        ret = Complex(0,1);
      }
    }

    if(neg) ret = -ret;
    
    return ret;
  }

  Complex factor(){
    Complex ret;

    if(check_and_ignore('(')){
      ret = expression();
      ignore(')');
    }else{
      ret = number();
    }
    
    return ret;
  }

  Complex term(){
    Complex ret = factor();

    while(1){
      if(check_and_ignore('*')){
        ret *= factor();
      }else{
        break;
      }
    }

    return ret;
  }
  
  Complex expression(){
    Complex ret = term();
    
    while(1){
      if(check_and_ignore('+')){
        ret += term();
      }else if(check_and_ignore('-')){
        ret -= term();
      }else{
        break;
      }
    }

    return ret;
  }
  
  Complex run(){
    return expression();
  }
};




int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  while(std::cin >> s){
    std::cout << parser(s).run() << "\n";
  }
  
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/1102/main.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102"

#include <iostream>
#include <string>
#line 2 "Mylib/Parser/parser.cpp"

#line 4 "Mylib/Parser/parser.cpp"
#include <cassert>

/**
 * @title Parsing
 * @docs parser.md
 */
struct Parser{
  using state = std::string::const_iterator;
  
  state cur, first, last;

  Parser(){}
  Parser(const std::string &s): cur(s.cbegin()), first(s.cbegin()), last(s.cend()){}
  
  inline char peek() const {return *cur;}
  
  inline bool check(char c) const {
    return *cur == c;
  }
  
  inline bool check(const std::string &s) const {
    state temp = cur;
    for(auto c : s){
      if(c != *temp) return false;
      ++temp;
    }
    return true;
  }
  
  inline void ignore(char c){
    assert(*cur == c);
    ++cur;
  }
  
  inline void ignore(){
    ++cur;
  }
  
  inline void ignore(const std::string &s){
    for(auto c : s){
      assert(*cur == c);
      ++cur;
    }
  }
  
  template <class Checker>
  inline void ignore_if(const Checker &f){
    assert(f(*cur));
    ++cur;
  }

  inline bool check_and_ignore(char c){
    if(*cur != c) return false;
    ++cur;
    return true;
  }

  inline bool end() const {return cur == last;}
  inline bool digit() const {return isdigit(*cur);}
  inline bool alpha() const {return isalpha(*cur);}
  inline bool lower() const {return islower(*cur);}
  inline bool upper() const {return isupper(*cur);}
    
  inline char get_char(){
    return *(cur++);
  }
  
  inline int get_digit(){
    return (int)(*(cur++)-'0');
  }
  
  template <typename Checker>
  inline auto get_string(const Checker &f){
    std::string ret;
    while(f(peek())){
      ret += peek();
      ignore();
    }
    return ret;
  }
  
  inline auto get_string_alpha(){
    std::string ret;
    while(isalpha(*cur)){
      ret += *cur;
      ++cur;
    }
    return ret;
  }
  
  inline auto get_string_alnum(){
    std::string ret;
    while(isalnum(*cur)){
      ret += *cur;
      ++cur;
    }
    return ret;
  }
  
  template <typename T>
  inline T get_number(){
    T ret = get_digit();
    while(digit()){
      (ret *= 10) += (T)(get_digit());
    }
    return ret;
  }
};
#line 6 "test/aoj/1102/main.test.cpp"

struct Complex{
  int real, imag;
  bool overflow;

  Complex(): real(0), imag(0), overflow(false){}
  Complex(int real, int imag = 0): real(real), imag(imag), overflow(false){
    if(abs(real) > 10000 or abs(imag) > 10000) overflow = true;
  }
  Complex(bool overflow): real(0), imag(0), overflow(true){}

  friend Complex operator+(const Complex &a, const Complex &b){
    if(a.overflow or b.overflow) return Complex(true);
    return Complex(a.real+b.real, a.imag+b.imag);
  }

  friend Complex operator-(const Complex &a, const Complex &b){
    if(a.overflow or b.overflow) return Complex(true);
    return Complex(a.real-b.real, a.imag-b.imag);
  }

  friend Complex operator-(const Complex &a){
    if(a.overflow) return Complex(true);
    return Complex(-a.real, -a.imag);
  }

  friend Complex operator*(const Complex &a, const Complex &b){
    if(a.overflow or b.overflow) return Complex(true);
    return Complex(a.real*b.real-a.imag*b.imag, a.real*b.imag+a.imag*b.real);
  }

  Complex& operator=(const Complex &a){
    this->real = a.real;
    this->imag = a.imag;
    this->overflow = a.overflow;
    return *this;
  }

  Complex& operator+=(const Complex &a){
    *this = *this + a;
    return *this;
  }

  Complex& operator-=(const Complex &a){
    *this = *this - a;
    return *this;
  }

  Complex& operator*=(const Complex &a){
    *this = *this * a;
    return *this;
  }
};


std::ostream& operator<<(std::ostream &os, const Complex &a){
  if(a.overflow) os << "overflow";
  else{
    if(a.real == 0 and a.imag == 0) os << 0;
    else{
      if(a.real){
        os << a.real;
      }
      if(a.imag){
        if(a.imag > 0 and a.real) os << "+"; 
        os << a.imag;
        os << "i";
      }
    }
  }
  return os;
}


struct parser : Parser{
  parser(const std::string &s): Parser(s){}

  Complex number(){
    bool neg = false;
    if(check_and_ignore('-')) neg = true;
    
    Complex ret;

    if(digit()){
      ret = get_number<Complex>();
      
      if(check_and_ignore('i')){
        ret *= Complex(0,1);
      }
    }else{
      if(check_and_ignore('i')){
        ret = Complex(0,1);
      }
    }

    if(neg) ret = -ret;
    
    return ret;
  }

  Complex factor(){
    Complex ret;

    if(check_and_ignore('(')){
      ret = expression();
      ignore(')');
    }else{
      ret = number();
    }
    
    return ret;
  }

  Complex term(){
    Complex ret = factor();

    while(1){
      if(check_and_ignore('*')){
        ret *= factor();
      }else{
        break;
      }
    }

    return ret;
  }
  
  Complex expression(){
    Complex ret = term();
    
    while(1){
      if(check_and_ignore('+')){
        ret += term();
      }else if(check_and_ignore('-')){
        ret -= term();
      }else{
        break;
      }
    }

    return ret;
  }
  
  Complex run(){
    return expression();
  }
};




int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  while(std::cin >> s){
    std::cout << parser(s).run() << "\n";
  }
  
  return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>
