#pragma once
#include <cstdint>
#include <cassert>

namespace haar_lib {
  template <typename Monoid, typename value_type = typename Monoid::value_type>
  value_type pow(value_type a, int64_t p){
    assert(p >= 0);
    const Monoid M;
    auto ret = M();

    while(p > 0){
      if(p & 1) ret = M(ret, a);
      a = M(a, a);
      p >>= 1;
    }

    return ret;
  }
}
