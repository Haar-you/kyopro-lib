#pragma once
#include <cstdint>
#include "Mylib/Combinatorics/factorial_table.cpp"

namespace haar_lib {
  template <
    const auto &ft,
    typename T = typename std::remove_reference_t<decltype(ft)>::value_type
    >
  T stirling_number_of_second_kind(int64_t n, int64_t k){
    if(n == 0 and k == 0) return T(1);

    T ret = 0;
    for(int i = 1; i <= k; ++i){
      if((k - i) % 2 == 0) ret += ft.C(k, i) * T::pow(i, n);
      else ret -= ft.C(k, i) * T::pow(i, n);
    }
    ret *= ft.inv_factorial(k);
    return ret;
  }
}
