#pragma once
#include "Mylib/Number/euler_phi_function.cpp"

/**
 * @title Tetration
 * @docs tetration.md
 */
namespace tetration_impl {
  int rec(int64_t a, int64_t b, int64_t m){
    if(b == 1) return a % m;
    if(b == 0) return 1 % m;
    if(b == 2){
      bool c = a >= m;
      int64_t ret = 1;
      int64_t p = a;
      a %= m;

      while(p > 0){
        if(p & 1) if((ret *= a) >= m) ret %= m, c = true;
        if((a *= a) >= m) a %= m, c = true;
        p >>= 1;
      }

      if(c) ret += m;
      return ret;
    }
    if(a == 0) return b % 2 == 1 ? 0 : 1;
    if(m == 1) return 1;

    int phi = totient(m);
    int p = rec(a, b - 1, phi);

    bool c = p >= phi;
    int64_t ret = 1;

    while(p > 0){
      if(p & 1) if((ret *= a) >= m) ret %= m, c = true;
      if((a *= a) >= m) a %= m, c = true;
      p >>= 1;
    }

    if(c) ret += m;
    return ret;
  }
}

int tetration(int64_t a, int64_t b, int64_t m){
  return tetration_impl::rec(a, b, m) % m;
}
