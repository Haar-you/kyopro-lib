#pragma once
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/DataStructure/WaveletMatrix/range_freq.cpp"

// BEGIN

/**
 * @return data[l, r)のlb以上で最小の値
 */
template <typename T, int B>
T WaveletMatrix<T,B>::next_value(int l, int r, T lb) const {
  int c = range_freq_lt(l, r, lb);
  return quantile(l, r, c+1);
}
  
/**
 * @return data[l, r)のub未満で最大の値
 */
template <typename T, int B>
T WaveletMatrix<T,B>::prev_value(int l, int r, T ub) const {
  int c = range_freq_lt(l, r, ub);
  return quantile(l, r, c);
}

