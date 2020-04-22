#pragma once
#include <optional>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/DataStructure/WaveletMatrix/range_freq.cpp"

/**
 * @title prev_value / next_value
 */

/**
 * @return data[l, r)のlb以上で最小の値
 */
template <typename T, int B>
std::optional<T> next_value(const WaveletMatrix<T, B> &wm, int l, int r, T lb){
  int c = range_freq_lt(wm, l, r, lb);
  return quantile(wm, l, r, c+1);
}
  
/**
 * @return data[l, r)のub未満で最大の値
 */
template <typename T, int B>
std::optional<T> prev_value(const WaveletMatrix<T, B> &wm, int l, int r, T ub){
  int c = range_freq_lt(wm, l, r, ub);
  return quantile(wm, l, r, c);
}
