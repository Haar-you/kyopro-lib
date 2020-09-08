#pragma once
#include <iostream>
#include <utility>

/**
 * @title Modint (Runtime mod)
 * @docs runtime_mint.md
 */
namespace haar_lib {
  template <typename Tag>
  class runtime_modint {
  public:
    static uint32_t M;

    uint64_t val;
    runtime_modint(): val(0){}
    runtime_modint(int64_t n){
      if(n >= M) val = n % M;
      else if(n < 0) val = n % M + M;
      else val = n;
    }

    auto operator+(const runtime_modint &a) const {return runtime_modint(val + a.val);}
    auto operator-(const runtime_modint &a) const {return runtime_modint(val - a.val);}
    auto operator*(const runtime_modint &a) const {return runtime_modint(val * a.val);}
    auto operator/(const runtime_modint &a) const {return runtime_modint(val * a.inv().val);}

    const auto& operator=(const runtime_modint &a){val = a.val; return *this;}
    const auto& operator+=(const runtime_modint &a){if((val += a.val) >= M) val -= M; return *this;}
    const auto& operator-=(const runtime_modint &a){if(val < a.val) val += M; val -= a.val; return *this;}
    const auto& operator*=(const runtime_modint &a){(val *= a.val) %= M; return *this;}
    const auto& operator/=(const runtime_modint &a){(val *= a.inv().val) %= M; return *this;}

    bool operator==(const runtime_modint &a) const {return val == a.val;}
    bool operator!=(const runtime_modint &a) const {return val != a.val;}

    static auto power(int64_t n, int64_t p){
      runtime_modint ret = 1, e = n;
      for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
      return ret;
    }

    auto power(int64_t p) const {
      runtime_modint ret = 1, e = val;
      for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
      return ret;
    }

    runtime_modint inv() const {
      int64_t a = val, b = M, u = 1, v = 0;

      while(b){
        int64_t t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
      }
      u %= M;
      if(u < 0) u += M;

      return u;
    }

    explicit operator int32_t() const noexcept {return val;}
    explicit operator int64_t() const noexcept {return val;}

    static void init(uint32_t m){M = m;}
  };

  template <typename Tag> auto operator-(const runtime_modint<Tag> &a){return runtime_modint(-a.val);}

  template <typename Tag> auto operator+(int64_t a, const runtime_modint<Tag> &b){return runtime_modint(a) + b;}
  template <typename Tag> auto operator-(int64_t a, const runtime_modint<Tag> &b){return runtime_modint(a) - b;}
  template <typename Tag> auto operator*(int64_t a, const runtime_modint<Tag> &b){return runtime_modint(a) * b;}
  template <typename Tag> auto operator/(int64_t a, const runtime_modint<Tag> &b){return runtime_modint(a) / b;}

  template <typename Tag> uint32_t runtime_modint<Tag>::M;

  template <typename Tag> std::istream& operator>>(std::istream &is, runtime_modint<Tag> &a){is >> a.val; return is;}
  template <typename Tag> std::ostream& operator<<(std::ostream &os, const runtime_modint<Tag> &a){os << a.val; return os;}
}
