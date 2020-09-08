#pragma once
#include <cstdint>
#include "Mylib/Number/Prime/prime_factorize.cpp"

/**
 * @title Count coprime
 * @docs count_coprime.md
 */
namespace haar_lib {
  int64_t count_coprime(int64_t n, int64_t m){
    const auto p = prime_factorize(m);
    const int k = p.size();

    int64_t ret = 0;

    for(int i = 0; i < 1 << k; ++i){
      int64_t s = 1;

      for(int j = 0; j < k; ++j){
        if(i & (1 << j)) s *= p[j].first;
      }

      if(__builtin_popcount(i) % 2 == 1) ret -= n / s;
      else ret += n / s;
    }

    return ret;
  }
}
