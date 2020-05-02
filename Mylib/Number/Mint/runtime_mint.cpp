#pragma once
#include <iostream>
#include <utility>

/**
 * @title 実行時mod指定modint
 * @docs runtime_mint.md
 */
class RuntimeModInt{
public:
  static uint32_t M;
  
  uint64_t val;
  RuntimeModInt(): val(0){}
  RuntimeModInt(int64_t n){
    if(n >= M) val = n % M;
    else if(n < 0) val = n % M + M;
    else val = n;
  }
  
  const auto operator+(const RuntimeModInt &a) const {return RuntimeModInt(val + a.val);}
  const auto operator-(const RuntimeModInt &a) const {return RuntimeModInt(val - a.val);}
  const auto operator*(const RuntimeModInt &a) const {return RuntimeModInt(val * a.val);}
  const auto operator/(const RuntimeModInt &a) const {return RuntimeModInt(val * a.inv().val);}
  
  const auto& operator=(const RuntimeModInt &a){val = a.val; return *this;}
  const auto& operator+=(const RuntimeModInt &a){if((val += a.val) >= M) val -= M; return *this;}
  const auto& operator-=(const RuntimeModInt &a){if(val < a.val) val += M; val -= a.val; return *this;}
  const auto& operator*=(const RuntimeModInt &a){(val *= a.val) %= M; return *this;}
  const auto& operator/=(const RuntimeModInt &a){(val *= a.inv().val) %= M; return *this;}

  const bool operator==(const RuntimeModInt &a) const {return val == a.val;}
  const bool operator!=(const RuntimeModInt &a) const {return val != a.val;}

  const static auto power(int64_t n, int64_t p){
    RuntimeModInt ret = 1, e = n;
    for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
    return ret;
  }

  const auto power(int64_t p) const {
    RuntimeModInt ret = 1, e = val;
    for(; p; e *= e, p >>= 1) if(p & 1) ret *= e;
    return ret;
  }
  
  const RuntimeModInt inv() const {
    int64_t a = val, b = M, u = 1, v = 0;

    while(b){
      int64_t t = a/b;
      a -= t*b; std::swap(a,b);
      u -= t*v; std::swap(u,v);
    }
    u %= M;
    if(u < 0) u += M;
    
    return u;
  }
};

auto operator-(const RuntimeModInt &a){return RuntimeModInt(-a.val);}

auto operator+(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) + b;}
auto operator-(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) - b;}
auto operator*(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) * b;}
auto operator/(int64_t a, const RuntimeModInt &b){return RuntimeModInt(a) / b;}

uint32_t RuntimeModInt::M;

std::istream& operator>>(std::istream &is, RuntimeModInt &a){is >> a.val; return is;}
std::ostream& operator<<(std::ostream &os, const RuntimeModInt &a){os << a.val; return os;}
