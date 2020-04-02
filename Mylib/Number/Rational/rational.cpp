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
