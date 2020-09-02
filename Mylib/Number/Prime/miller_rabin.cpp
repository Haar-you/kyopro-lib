#pragma once
#include "Mylib/Misc/int128.cpp"

/**
 * @title Primality test (Miller-Rabin algorithm)
 * @docs miller_rabin.md
 */
class MillerRabin {
  uint128_t power(uint128_t a, uint128_t b, uint128_t p) const {
    uint128_t ret = 1;

    while(b > 0){
      if(b & 1) ret = ret * a % p;
      a = a * a % p;
      b >>= 1;
    }

    return ret;
  }

  bool is_composite(uint64_t a, uint64_t p, int s, uint64_t d) const {
    uint128_t x = power(a, d, p);

    if(x == 1) return false;

    for(int i = 0; i < s; ++i){
      if(x == p - 1) return false;
      x = x * x % p;
    }

    return true;
  }

public:
  bool operator()(uint64_t n) const {
    if(n <= 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    int s = 0;
    uint64_t d = n - 1;
    while((d & 1) == 0){
      s += 1;
      d >>= 1;
    }

    if(n < 4759123141){
      for(uint64_t x : {2, 7, 61}){
        if(x < n and is_composite(x, n, s, d)) return false;
      }

      return true;
    }

    for(uint64_t x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
      if(x < n and is_composite(x, n, s, d)) return false;
    }

    return true;
  }
};
