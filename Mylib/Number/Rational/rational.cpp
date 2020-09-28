#pragma once
#include <numeric>
#include <iostream>
#include <cmath>

namespace haar_lib {
  class rational {
    int64_t nume_, deno_;

  public:
    rational(): nume_(0), deno_(1){}
    rational(int64_t nume): nume_(nume), deno_(1){}
    rational(int64_t nume, int64_t deno){
      const int64_t g = std::gcd(nume, deno);
      nume_ = nume / g;
      deno_ = deno / g;
      if(deno_ < 0){
        nume_ = -nume_;
        deno_ = -deno_;
      }
    }

    int64_t numerator() const {return nume_;}
    int64_t denominator() const {return deno_;}

    auto operator+(const rational &b){
      int64_t l = std::lcm((*this).deno_, b.deno_);
      return rational(l / (*this).deno_ * (*this).nume_ + l / b.deno_ * b.nume_, l);
    }

    auto operator-(const rational &b){
      int64_t l = std::lcm((*this).deno_, b.deno_);
      return rational(l / (*this).deno_ * (*this).nume_ - l / b.deno_ * b.nume_, l);
    }

    auto operator*(const rational &b){
      return rational((*this).nume_ * b.nume_, (*this).deno_ * b.deno_);
    }

    auto operator/(const rational &b){
      return rational((*this).nume_ * b.deno_, (*this).deno_ * b.nume_);
    }

    auto& operator+=(const rational &a){*this = *this + a; return *this;}
    auto& operator-=(const rational &a){*this = *this - a; return *this;}
    auto& operator*=(const rational &a){*this = *this * a; return *this;}
    auto& operator/=(const rational &a){*this = *this / a; return *this;}

    explicit operator double() const {return (double)nume_ / deno_;}
    explicit operator long double() const {return (long double)nume_ / deno_;}

    auto operator-(){return rational(-nume_, deno_);}

    friend std::ostream& operator<<(std::ostream &os, const rational &r){
      if(r.deno_ == 1) os << r.nume_;
      else os << r.nume_ << "/" << r.deno_;
      return os;
    }

    friend bool operator==(const rational &a, const rational &b){return a.nume_ == b.nume_ && a.deno_ == b.deno_;}
    friend bool operator!=(const rational &a, const rational &b){return !(a == b);}
    friend bool operator<(const rational &a, const rational &b){return a.nume_ * b.deno_ < b.nume_ * a.deno_;}
    friend bool operator<=(const rational &a, const rational &b){return a.nume_ * b.deno_ <= b.nume_ * a.deno_;}
    friend bool operator>(const rational &a, const rational &b){return !(a <= b);}
    friend bool operator>=(const rational &a, const rational &b){return !(a < b);}

    friend auto abs(const rational &a){
      return rational(std::abs(a.nume_), std::abs(a.deno_));
    }
  };
}
