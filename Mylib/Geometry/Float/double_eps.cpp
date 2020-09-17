#pragma once
#include <iostream>
#include <limits>
#include <cmath>

namespace haar_lib {
  template <typename T, const T &eps>
  struct double_eps {
    using value_type = T;

    T value;

    double_eps(): value(0){}
    double_eps(T value): value(value){}

    auto& operator=(const double_eps &rhs){this->value = rhs.value; return *this;}
    auto& operator+=(const double_eps &rhs){this->value += rhs.value; return *this;}
    auto& operator-=(const double_eps &rhs){this->value -= rhs.value; return *this;}
    auto& operator*=(const double_eps &rhs){this->value *= rhs.value; return *this;}
    auto& operator/=(const double_eps &rhs){this->value /= rhs.value; return *this;}

    auto operator+(const double_eps &rhs) const {return double_eps(this->value + rhs.value);}
    auto operator-(const double_eps &rhs) const {return double_eps(this->value - rhs.value);}
    auto operator*(const double_eps &rhs) const {return double_eps(this->value * rhs.value);}
    auto operator/(const double_eps &rhs) const {return double_eps(this->value / rhs.value);}

    bool operator==(const double_eps &rhs) const {return std::abs(this->value - rhs.value) < eps;}
    bool operator!=(const double_eps &rhs) const {return !(*this == rhs);}
    bool operator<(const double_eps &rhs) const {return this->value - rhs.value < -eps;}
    bool operator<=(const double_eps &rhs) const {return this->value - rhs.value < eps;}
    bool operator>(const double_eps &rhs) const {return !(*this <= rhs);}
    bool operator>=(const double_eps &rhs) const {return !(*this < rhs);}

    auto operator-() const {return double_eps(-(this->value));}

    explicit operator double() const noexcept {return value;}
    explicit operator long double() const noexcept {return value;}

    friend std::ostream& operator<<(std::ostream &s, const double_eps &rhs){s << rhs.value; return s;}
    friend std::istream& operator>>(std::istream &s, double_eps &rhs){s >> rhs.value; return s;}

    friend double_eps sin(double_eps x){return std::sin((T)x);}
    friend double_eps cos(double_eps x){return std::cos((T)x);}
    friend double_eps tan(double_eps x){return std::tan((T)x);}
    friend double_eps acos(double_eps x){return std::acos((T)x);}
    friend double_eps atan2(double_eps y, double_eps x){return std::atan2((T)y, (T)x);}
    friend double_eps abs(double_eps x){return std::abs((T)x);}
    friend double_eps sqrt(double_eps x){return std::sqrt(std::max<T>(0, (T)x));}
  };
}

namespace std {
  template <typename T, const T &eps>
  class numeric_limits<haar_lib::double_eps<T, eps>> {
  public:
    static haar_lib::double_eps<T, eps> infinity() {return numeric_limits<T>::infinity();}
    static haar_lib::double_eps<T, eps> min() {return numeric_limits<T>::min();}
    static haar_lib::double_eps<T, eps> max() {return numeric_limits<T>::max();}
    static haar_lib::double_eps<T, eps> lowest() {return numeric_limits<T>::lowest();}
  };
}
