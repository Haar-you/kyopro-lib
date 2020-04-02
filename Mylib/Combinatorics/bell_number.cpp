#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Combinatorics/combinatorics.cpp"
#include "Mylib/Combinatorics/stirling_number.cpp"

/**
 * @title Bell数
 * @note n個の区別するボールをk個の区別しない箱に分配するような方法の総数。
 * @attention O(min(k, n) log n)
 */
template <typename T>
T Combinatorics<T>::bell_number(int64_t n, int64_t k){
  if(n == 0) return 1;
  
  k = std::min(k, n);

  std::vector<T> t(k, 1);
  
  for(int i = 1; i < k; ++i){
    if(i % 2 == 0) t[i] = t[i-1] + finv(i);
    else t[i] = t[i-1] - finv(i);
  }

  T ret = 0;
  for(int i = 1; i <= k; ++i){
    ret += t[k-i] * T::power(i, n) * finv(i);
  }
  
  return ret;
}
