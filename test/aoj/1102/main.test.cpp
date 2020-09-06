#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102"

#include <iostream>
#include <string>
#include "Mylib/Parser/parser.cpp"

struct Complex {
  int real, imag;
  bool overflow;

  Complex(): real(0), imag(0), overflow(false){}
  Complex(int real, int imag = 0): real(real), imag(imag), overflow(false){
    if(abs(real) > 10000 or abs(imag) > 10000) overflow = true;
  }
  Complex(bool overflow): real(0), imag(0), overflow(true){}

  friend Complex operator+(const Complex &a, const Complex &b){
    if(a.overflow or b.overflow) return Complex(true);
    return Complex(a.real + b.real, a.imag + b.imag);
  }

  friend Complex operator-(const Complex &a, const Complex &b){
    if(a.overflow or b.overflow) return Complex(true);
    return Complex(a.real - b.real, a.imag - b.imag);
  }

  friend Complex operator-(const Complex &a){
    if(a.overflow) return Complex(true);
    return Complex(-a.real, -a.imag);
  }

  friend Complex operator*(const Complex &a, const Complex &b){
    if(a.overflow or b.overflow) return Complex(true);
    return Complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
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


struct parser : Parser {
  parser(const std::string &s): Parser(s){}

  Complex number(){
    bool neg = false;
    if(check_and_ignore('-')) neg = true;

    Complex ret;

    if(digit()){
      ret = get_number<Complex>();

      if(check_and_ignore('i')){
        ret *= Complex(0, 1);
      }
    }else{
      if(check_and_ignore('i')){
        ret = Complex(0, 1);
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
