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
    int64_t g = std::gcd(num, den);
    nume = num / g ;
    deno = den / g;
    if(deno < 0){
      nume = -nume;
      deno = -deno;
    }
  }

  auto operator+(const Rational &b){
    int64_t l = std::lcm((*this).deno, b.deno);
    return Rational(l / (*this).deno * (*this).nume + l / b.deno * b.nume, l);
  }
  
  auto operator-(const Rational &b){
    int64_t l = std::lcm((*this).deno, b.deno);
    return Rational(l / (*this).deno * (*this).nume - l / b.deno * b.nume, l);
  }
  
  auto operator*(const Rational &b){
    return Rational((*this).nume * b.nume, (*this).deno * b.deno);
  }
  
  auto operator/(const Rational &b){
    return Rational((*this).nume * b.deno, (*this).deno * b.nume);
  }
  
  auto& operator+=(const Rational &a){*this = *this + a; return *this;}
  auto& operator-=(const Rational &a){*this = *this - a; return *this;}
  auto& operator*=(const Rational &a){*this = *this * a; return *this;}
  auto& operator/=(const Rational &a){*this = *this / a; return *this;}
};

std::ostream& operator<<(std::ostream &os, const Rational &r){
  if(r.deno == 1) os << r.nume;
  else os << r.nume << "/" << r.deno;
  return os;
}

auto operator-(const Rational &a){return Rational(-a.nume, a.deno);}

bool operator==(const Rational &a, const Rational &b){return a.nume == b.nume && a.deno == b.deno;}
bool operator!=(const Rational &a, const Rational &b){return !(a == b);}
bool operator<(const Rational &a, const Rational &b){return a.nume * b.deno < b.nume * a.deno;}
bool operator<=(const Rational &a, const Rational &b){return a.nume * b.deno <= b.nume * a.deno;}
bool operator>(const Rational &a, const Rational &b){return !(a <= b);}
bool operator>=(const Rational &a, const Rational &b){return !(a < b);}

double to_double(const Rational &a){return (double)a.nume/a.deno;}

auto abs(const Rational &a){return Rational(abs(a.nume), abs(a.deno));}
