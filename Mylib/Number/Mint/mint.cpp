#pragma once
#include <iostream>
#include <utility>

namespace haar_lib {
  template <int32_t M>
  class modint {
    uint32_t val_;

  public:
    constexpr static auto mod(){return M;}

    constexpr modint(): val_(0){}
    constexpr modint(int64_t n){
      if(n >= M) val_ = n % M;
      else if(n < 0) val_ = n % M + M;
      else val_ = n;
    }

    constexpr auto& operator=(const modint &a){val_ = a.val_; return *this;}
    constexpr auto& operator+=(const modint &a){
      if(val_ + a.val_ >= M) val_ = (uint64_t)val_ + a.val_ - M;
      else val_ += a.val_;
      return *this;
    }
    constexpr auto& operator-=(const modint &a){
      if(val_ < a.val_) val_ += M;
      val_ -= a.val_;
      return *this;
    }
    constexpr auto& operator*=(const modint &a){
      val_ = (uint64_t)val_ * a.val_ % M;
      return *this;
    }
    constexpr auto& operator/=(const modint &a){
      val_ = (uint64_t)val_ * a.inv().val_ % M;
      return *this;
    }

    constexpr auto operator+(const modint &a) const {return modint(*this) += a;}
    constexpr auto operator-(const modint &a) const {return modint(*this) -= a;}
    constexpr auto operator*(const modint &a) const {return modint(*this) *= a;}
    constexpr auto operator/(const modint &a) const {return modint(*this) /= a;}

    constexpr bool operator==(const modint &a) const {return val_ == a.val_;}
    constexpr bool operator!=(const modint &a) const {return val_ != a.val_;}

    constexpr auto& operator++(){*this += 1; return *this;}
    constexpr auto& operator--(){*this -= 1; return *this;}

    constexpr auto operator++(int){auto t = *this; *this += 1; return t;}
    constexpr auto operator--(int){auto t = *this; *this -= 1; return t;}

    constexpr static modint pow(int64_t n, int64_t p){
      if(p < 0) return pow(n, -p).inv();

      int64_t ret = 1, e = n % M;
      for(; p; (e *= e) %= M, p >>= 1) if(p & 1) (ret *= e) %= M;
      return ret;
    }

    constexpr static modint inv(int64_t a){
      int64_t b = M, u = 1, v = 0;

      while(b){
        int64_t t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
      }

      u %= M;
      if(u < 0) u += M;

      return u;
    }

    constexpr static auto frac(int64_t a, int64_t b){return modint(a) / modint(b);}

    constexpr auto pow(int64_t p) const {return pow(val_, p);}
    constexpr auto inv() const {return inv(val_);}

    friend constexpr auto operator-(const modint &a){return modint(M - a.val_);}

    friend constexpr auto operator+(int64_t a, const modint &b){return modint(a) + b;}
    friend constexpr auto operator-(int64_t a, const modint &b){return modint(a) - b;}
    friend constexpr auto operator*(int64_t a, const modint &b){return modint(a) * b;}
    friend constexpr auto operator/(int64_t a, const modint &b){return modint(a) / b;}

    friend std::istream& operator>>(std::istream &s, modint<M> &a){s >> a.val_; return s;}
    friend std::ostream& operator<<(std::ostream &s, const modint<M> &a){s << a.val_; return s;}

    template <int N>
    static auto div(){
      static auto value = inv(N);
      return value;
    }

    explicit operator int32_t() const noexcept {return val_;}
    explicit operator int64_t() const noexcept {return val_;}
  };
}
