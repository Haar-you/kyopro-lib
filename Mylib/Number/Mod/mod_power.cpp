#pragma once
#include <cstdint>

/**
 * @title Mod power
 * @docs mod_power.md
 */
namespace haar_lib {
  int64_t power(int64_t n, int64_t p, int64_t m){
    int64_t ret = 1;
    while(p > 0){
      if(p & 1) (ret *= n) %= m;
      (n *= n) %= m;
      p >>= 1;
    }
    return ret;
  }
}
