#pragma once
#include <vector>
#include "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Bernoulli number
 * @docs bernoulli_number.md
 */
template <typename Ft, typename T = typename Ft::value_type>
std::vector<T> bernoulli_number(int64_t n, const Ft &ft){
  std::vector<T> ret(n+1);

  ret[0] = 1;

  for(int64_t i = 1; i <= n; ++i){
    for(int k = 0; k <= i-1; ++k){
      ret[i] += ft.C(i+1,k) * ret[k];
    }
    ret[i] /= i+1;
    ret[i] = -ret[i];
  }
  
  return ret;
}
