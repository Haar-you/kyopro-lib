#pragma once
#include <vector>
#include "Mylib/Combinatorics/combinatorics.cpp"

/**
 * @title Bernoulli数
 * @docs bernoulli_number.md
 */
template <typename T>
std::vector<T> Combinatorics<T>::bernoulli_number(int64_t n){
  std::vector<T> ret(n+1);

  ret[0] = 1;

  for(int64_t i = 1; i <= n; ++i){
    for(int k = 0; k <= i-1; ++k){
      ret[i] += C(i+1,k) * ret[k];
    }
    ret[i] /= i+1;
    ret[i] = -ret[i];
  }
  
  return ret;
}
