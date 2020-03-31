#pragma once
#include <vector>
#include "Mylib/Combinatorics/combinatorics.cpp"

/**
 * @attention O(n^2 logn)
 */
template <typename T>
auto Combinatorics<T>::bernoulli_number(int64_t n){
  std::vector<T> ret(n+1);

  ret[0] = 1;

  for(int i = 1; i <= n; ++i){
    for(int k = 0; k <= i-1; ++k){
      ret[i] += C(i+1,k) * ret[k];
    }
    ret[i] /= i+1;
    ret[i] = -ret[i];
  }
  
  return ret;
}
