#pragma once
#include "Mylib/Combinatorics/combinatorics.cpp"

/**
 * @title Stirling numbers of second kind
 * @docs stirling_number.md
 */
template <typename T>
T Combinatorics<T>::stirling_number(int64_t n, int64_t k){
  if(n == 0 and k == 0) return 1;
  
  T ret = 0;
  for(int i = 1; i <= k; ++i){
    if((k-i) % 2 == 0) ret += C(k,i) * T::power(i,n);
    else ret -= C(k,i) * T::power(i,n);
  }
  ret *= finv(k);
  return ret;
}
