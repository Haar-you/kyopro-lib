#pragma once
#include "Mylib/Combinatorics/combinatorics.cpp"

/**
 * @note c_0 = 1, c_{n+1} = ∑_{i=0}^n c_i * c_{n-i} を満たす数列の第n項。
 * @note 長さ2nの対応の取れた括弧列の総数はc_n通り。
 */
template <typename T> T Combinatorics<T>::catalan_number(int64_t n){
  return C(2*n,n) - C(2*n,n-1);
}
