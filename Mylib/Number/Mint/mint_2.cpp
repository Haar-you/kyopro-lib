#pragma once
#include <iostream>

class modint2 {
  uint32_t val_;

public:
  constexpr static int mod() { return 2; }

  constexpr modint2() : val_(0) {}
  constexpr modint2(int64_t n) : val_(n & 1) {}

  constexpr auto &operator=(const modint2 &a) {
    val_ = a.val_;
    return *this;
  }
  constexpr auto &operator+=(const modint2 &a) {
    val_ ^= a.val_;
    return *this;
  }
  constexpr auto &operator-=(const modint2 &a) {
    val_ ^= a.val_;
    return *this;
  }
  constexpr auto &operator*=(const modint2 &a) {
    val_ &= a.val_;
    return *this;
  }
  constexpr auto &operator/=(const modint2 &a) {
    val_ &= a.val_;
    return *this;
  }

  constexpr auto operator+(const modint2 &a) const { return modint2(*this) += a; }
  constexpr auto operator-(const modint2 &a) const { return modint2(*this) -= a; }
  constexpr auto operator*(const modint2 &a) const { return modint2(*this) *= a; }
  constexpr auto operator/(const modint2 &a) const { return modint2(*this) /= a; }

  constexpr bool operator==(const modint2 &a) const { return val_ == a.val_; }
  constexpr bool operator!=(const modint2 &a) const { return val_ != a.val_; }

  constexpr auto &operator++() {
    *this += 1;
    return *this;
  }
  constexpr auto &operator--() {
    *this -= 1;
    return *this;
  }

  constexpr auto operator++(int) {
    auto t = *this;
    *this += 1;
    return t;
  }
  constexpr auto operator--(int) {
    auto t = *this;
    *this -= 1;
    return t;
  }

  constexpr static modint2 pow(int64_t n, int64_t) { return n; }
  constexpr static modint2 inv(int64_t a) { return a; }

  constexpr static auto frac(int64_t a, int64_t b) { return modint2(a) / modint2(b); }

  constexpr auto pow(int64_t) const { return *this; }
  constexpr auto inv() const { return *this; }

  friend constexpr auto operator-(const modint2 &a) { return a; }

  friend constexpr auto operator+(int64_t a, const modint2 &b) { return modint2(a) + b; }
  friend constexpr auto operator-(int64_t a, const modint2 &b) { return modint2(a) - b; }
  friend constexpr auto operator*(int64_t a, const modint2 &b) { return modint2(a) * b; }
  friend constexpr auto operator/(int64_t a, const modint2 &b) { return modint2(a) / b; }

  friend std::istream &operator>>(std::istream &s, modint2 &a) {
    s >> a.val_;
    return s;
  }
  friend std::ostream &operator<<(std::ostream &s, const modint2 &a) {
    s << a.val_;
    return s;
  }

  explicit operator int32_t() const noexcept { return val_; }
  explicit operator int64_t() const noexcept { return val_; }
};
