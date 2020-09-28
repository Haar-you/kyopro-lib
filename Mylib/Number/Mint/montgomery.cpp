#pragma once
#include <iostream>

namespace haar_lib {
  template <int64_t M>
  class montgomery {
    constexpr static int64_t MOD = M;
    constexpr static int b = 64 - __builtin_clzll(MOD);
    constexpr static int64_t R = 1LL << b;
    constexpr static int64_t R2 = (R % MOD) * (R % MOD) % MOD;

    constexpr static int64_t mask = R - 1;

    constexpr static int64_t init(){
      int64_t ret = 0, r = R, i = 1, t = 0;
      while(r > 1){
        if(t % 2 == 0) t += MOD, ret += i;
        t >>= 1, r >>= 1, i <<= 1;
      }
      return ret;
    }

    constexpr static int64_t m = init();

    static_assert(R > MOD, "R > MOD");
    static_assert((R & (R - 1)) == 0, "R must be power of 2");

    static int64_t reduce(int64_t T){
      int64_t ret = ((((T & mask) * m) & mask) * MOD + T) >> b;
      if(ret >= MOD) ret -= MOD;
      return ret;
    }

    int64_t val_;

  public:
    montgomery(): val_(0){}
    montgomery(int64_t a){
      if(a < 0){
        if(a < -MOD) a = a % MOD + MOD;
        else a += MOD;
      }else if(a >= MOD){
        if(a < 2 * MOD) a -= MOD;
        else a %= MOD;
      }

      val_ = reduce(a * R2);
    }
    montgomery(const montgomery &that): val_(that.val_){}

    constexpr static auto mod(){return MOD;}

    auto& operator+=(const montgomery &that){
      val_ += that.val_;
      if(val_ >= MOD) val_ -= MOD;
      return *this;
    }

    auto& operator-=(const montgomery &that){
      val_ -= that.val_;
      if(val_ < 0) val_ += MOD;
      return *this;
    }

    auto& operator*=(const montgomery &that){
      val_ = reduce(val_ * that.val_);
      return *this;
    }

    auto& operator/=(const montgomery &that){
      *this *= that.inv();
      return *this;
    }

    auto operator-() const {
      montgomery ret(0);
      ret -= *this;
      return ret;
    }

    auto operator+(const montgomery &that) const {auto ret = *this; return ret += that;}
    auto operator-(const montgomery &that) const {auto ret = *this; return ret -= that;}
    auto operator*(const montgomery &that) const {auto ret = *this; return ret *= that;}
    auto operator/(const montgomery &that) const {auto ret = *this; return ret /= that;}

    auto pow(int64_t p) const {
      montgomery ret = 1, e = *this;

      while(p > 0){
        if(p & 1) ret *= e;
        e *= e;
        p >>= 1;
      }

      return ret;
    }

    static auto pow(int64_t n, int64_t p){return montgomery(n).pow(p);}

    auto inv() const {return pow(MOD - 2);}
    static auto inv(int64_t n){return montgomery(n).inv();}

    friend auto operator+(int64_t a, const montgomery &b) {return montgomery(a) + b;}
    friend auto operator-(int64_t a, const montgomery &b) {return montgomery(a) - b;}
    friend auto operator*(int64_t a, const montgomery &b) {return montgomery(a) * b;}
    friend auto operator/(int64_t a, const montgomery &b) {return montgomery(a) / b;}

    bool operator==(const montgomery &that) const {
      return (val_ >= MOD ? val_ - MOD : val_) == (that.val_ >= MOD ? that.val_ - MOD : that.val_);
    }

    bool operator!=(const montgomery &that) const {return !(*this == that);}

    friend std::ostream& operator<<(std::ostream& s, const montgomery &a){
      return s << reduce(a.val_);
    }

    friend std::istream& operator>>(std::istream& s, montgomery &a){
      int64_t t; s >> t;
      a = montgomery(t);
      return s;
    }

    explicit operator int32_t() const {return reduce(val_);}
    explicit operator int64_t() const {return reduce(val_);}
  };
}
