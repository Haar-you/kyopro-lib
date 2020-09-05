#pragma once
#include "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Stirling numbers of the second kind
 * @docs stirling_number_second.md
 */
template <typename Ft, typename T = typename Ft::value_type>
T stirling_number_of_second_kind(int64_t n, int64_t k, const Ft &ft){
  if(n == 0 and k == 0) return 1;

  T ret = 0;
  for(int i = 1; i <= k; ++i){
    if((k-i) % 2 == 0) ret += ft.C(k, i) * T::power(i, n);
    else ret -= ft.C(k, i) * T::power(i, n);
  }
  ret *= ft.inv_factorial(k);
  return ret;
}
