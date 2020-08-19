#pragma once
#include "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Stirling numbers of second kind
 * @docs stirling_number_second.md
 */
template <typename T, typename Ft>
T stirling_number(const Ft &ft, int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  
  T ret = 0;
  for(int i = 1; i <= k; ++i){
    if((k-i) % 2 == 0) ret += ft.C(k, i) * T::power(i, n);
    else ret -= ft.C(k, i) * T::power(i, n);
  }
  ret *= ft.inv_factorial(k);
  return ret;
}