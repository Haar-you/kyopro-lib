#pragma once
#include "Mylib/Combinatorics/combinatorics.cpp"

/**
 * @title Catalan数
 * @see https://en.wikipedia.org/wiki/Catalan_number
 * @see https://mathtrain.jp/catalan
 * @note c_0 = 1, c_{n+1} = ∑_{i=0}^n c_i * c_{n-i} を満たす数列の第n項。
 */
template <typename T> T Combinatorics<T>::catalan_number(int64_t n){
  return C(2*n,n) - C(2*n,n-1);
}
