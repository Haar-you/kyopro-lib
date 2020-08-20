#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Bell number
 * @docs bell_number.md
 */
template <typename Ft, typename T = typename Ft::value_type>
T bell_number(int64_t n, int64_t k, const Ft &ft){
  if(n == 0) return 1;
  
  k = std::min(k, n);

  std::vector<T> t(k, 1);
  
  for(int i = 1; i < k; ++i){
    if(i % 2 == 0) t[i] = t[i-1] + ft.inv_factorial(i);
    else t[i] = t[i-1] - ft.inv_factorial(i);
  }

  T ret = 0;
  for(int i = 1; i <= k; ++i){
    ret += t[k-i] * T::power(i, n) * ft.inv_factorial(i);
  }
  
  return ret;
}
