#pragma once
#include <utility>
#include <cstdint>

namespace haar_lib {
  int64_t mod_inv(int64_t a, int64_t m){
    int64_t b = m, u = 1, v = 0;

    while(b){
      int64_t t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }

    u %= m;
    if(u < 0) u += m;

    return u;
  }
}
