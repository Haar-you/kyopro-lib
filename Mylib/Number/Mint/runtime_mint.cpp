#pragma once
#include <iostream>
#include <utility>

namespace haar_lib {
  template <const int &M>
  class runtime_modint {
    int64_t val_;

  public:
    runtime_modint() : val_(0) {}
    runtime_modint(int64_t n) {
      if (n >= M)
        val_ = n % M;
      else if (n < 0)
        val_ = n % M + M;
      else
        val_ = n;
    }

    static auto mod() { return M; }

    auto operator+(const runtime_modint &a) const { return runtime_modint(val_ + a.val_); }
    auto operator-(const runtime_modint &a) const { return runtime_modint(val_ - a.val_); }
    auto operator*(const runtime_modint &a) const { return runtime_modint(val_ * a.val_); }
    auto operator/(const runtime_modint &a) const { return runtime_modint(val_ * a.inv().val_); }

    const auto &operator=(const runtime_modint &a) {
      val_ = a.val_;
      return *this;
    }
    const auto &operator+=(const runtime_modint &a) {
      if ((val_ += a.val_) >= M) val_ -= M;
      return *this;
    }
    const auto &operator-=(const runtime_modint &a) {
      if (val_ < a.val_) val_ += M;
      val_ -= a.val_;
      return *this;
    }
    const auto &operator*=(const runtime_modint &a) {
      (val_ *= a.val_) %= M;
      return *this;
    }
    const auto &operator/=(const runtime_modint &a) {
      (val_ *= a.inv().val_) %= M;
      return *this;
    }

    bool operator==(const runtime_modint &a) const { return val_ == a.val_; }
    bool operator!=(const runtime_modint &a) const { return val_ != a.val_; }

    static auto pow(int64_t n, int64_t p) {
      runtime_modint ret = 1, e = n;
      for (; p; e *= e, p >>= 1)
        if (p & 1) ret *= e;
      return ret;
    }

    auto pow(int64_t p) const {
      runtime_modint ret = 1, e = val_;
      for (; p; e *= e, p >>= 1)
        if (p & 1) ret *= e;
      return ret;
    }

    runtime_modint inv() const {
      int64_t a = val_, b = M, u = 1, v = 0;

      while (b) {
        int64_t t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
      }
      u %= M;
      if (u < 0) u += M;

      return u;
    }

    explicit operator int32_t() const noexcept { return val_; }
    explicit operator int64_t() const noexcept { return val_; }

    friend auto operator-(const runtime_modint &a) { return runtime_modint(-a.val_); }

    friend auto operator+(int64_t a, const runtime_modint &b) { return runtime_modint(a) + b; }
    friend auto operator-(int64_t a, const runtime_modint &b) { return runtime_modint(a) - b; }
    friend auto operator*(int64_t a, const runtime_modint &b) { return runtime_modint(a) * b; }
    friend auto operator/(int64_t a, const runtime_modint &b) { return runtime_modint(a) / b; }

    friend std::istream &operator>>(std::istream &is, runtime_modint &a) {
      is >> a.val_;
      return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const runtime_modint &a) {
      os << a.val_;
      return os;
    }
  };
}  // namespace haar_lib
