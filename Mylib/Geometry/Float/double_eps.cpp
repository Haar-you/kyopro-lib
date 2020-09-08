#pragma once
#include <iostream>
#include <limits>
#include <cmath>

/**
 * @title Floating point number with eps
 * @docs double_eps.md
 */
namespace haar_lib {
  template <typename T>
  struct DoubleEps {
    using value_type = T;

    static T eps;

    T value;

    DoubleEps(): value(0){}
    DoubleEps(T value): value(value){}

    auto& operator=(const DoubleEps &rhs){this->value = rhs.value; return *this;}
    auto& operator+=(const DoubleEps &rhs){this->value += rhs.value; return *this;}
    auto& operator-=(const DoubleEps &rhs){this->value -= rhs.value; return *this;}
    auto& operator*=(const DoubleEps &rhs){this->value *= rhs.value; return *this;}
    auto& operator/=(const DoubleEps &rhs){this->value /= rhs.value; return *this;}

    auto operator+(const DoubleEps &rhs) const {return DoubleEps(this->value + rhs.value);}
    auto operator-(const DoubleEps &rhs) const {return DoubleEps(this->value - rhs.value);}
    auto operator*(const DoubleEps &rhs) const {return DoubleEps(this->value * rhs.value);}
    auto operator/(const DoubleEps &rhs) const {return DoubleEps(this->value / rhs.value);}

    bool operator==(const DoubleEps &rhs) const {return std::abs(this->value - rhs.value) < eps;}
    bool operator!=(const DoubleEps &rhs) const {return !(*this == rhs);}
    bool operator<(const DoubleEps &rhs) const {return this->value - rhs.value < -eps;}
    bool operator<=(const DoubleEps &rhs) const {return this->value - rhs.value < eps;}
    bool operator>(const DoubleEps &rhs) const {return !(*this <= rhs);}
    bool operator>=(const DoubleEps &rhs) const {return !(*this < rhs);}

    auto operator-() const {return DoubleEps(-(this->value));}

    explicit operator double() const noexcept {return value;}
    explicit operator long double() const noexcept {return value;}

    friend std::ostream& operator<<(std::ostream &s, const DoubleEps &rhs){s << rhs.value; return s;}
    friend std::istream& operator>>(std::istream &s, DoubleEps &rhs){s >> rhs.value; return s;}
  };

  template <typename T> T DoubleEps<T>::eps;


  template <typename T> DoubleEps<T> sin(DoubleEps<T> x){return std::sin((T)x);}
  template <typename T> DoubleEps<T> cos(DoubleEps<T> x){return std::cos((T)x);}
  template <typename T> DoubleEps<T> tan(DoubleEps<T> x){return std::tan((T)x);}

  template <typename T> DoubleEps<T> acos(DoubleEps<T> x){return std::acos((T)x);}
  template <typename T> DoubleEps<T> atan2(DoubleEps<T> y, DoubleEps<T> x){return std::atan2((T)y, (T)x);}

  template <typename T> DoubleEps<T> abs(DoubleEps<T> x){return std::abs((T)x);}

  template <typename T> DoubleEps<T> sqrt(DoubleEps<T> x){return std::sqrt((T)x);}
}

namespace std {
  template <typename T>
  class numeric_limits<haar_lib::DoubleEps<T>> {
  public:
    static haar_lib::DoubleEps<T> infinity() {return numeric_limits<T>::infinity();}
    static haar_lib::DoubleEps<T> min() {return numeric_limits<T>::min();}
    static haar_lib::DoubleEps<T> max() {return numeric_limits<T>::max();}
    static haar_lib::DoubleEps<T> lowest() {return numeric_limits<T>::lowest();}
  };
}
