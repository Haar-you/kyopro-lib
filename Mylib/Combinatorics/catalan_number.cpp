#pragma once
#include "Mylib/Combinatorics/combinatorics.cpp"

/**
 * @title Catalan number
 * @docs catalan_number.md
 */
template <typename T> T Combinatorics<T>::catalan_number(int64_t n){
  return C(2*n,n) - C(2*n,n-1);
}
