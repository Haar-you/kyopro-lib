#pragma once
#include <vector>
#include <cstdint>
#include "Mylib/Combinatorics/factorial_table.cpp"

namespace haar_lib {
  template <const auto &ft>
  auto bernoulli_number(int64_t n){
    using T = typename std::remove_reference_t<decltype(ft)>::value_type;
    std::vector<T> ret(n + 1);

    ret[0] = 1;

    for(int64_t i = 1; i <= n; ++i){
      for(int k = 0; k <= i - 1; ++k){
        ret[i] += ft.C(i + 1, k) * ret[k];
      }
      ret[i] /= i + 1;
      ret[i] = -ret[i];
    }

    return ret;
  }
}
