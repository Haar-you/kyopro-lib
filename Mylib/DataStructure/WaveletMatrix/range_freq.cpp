#pragma once
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"

/**
 * @title range_freq
 */

template <typename T, int B>
int WaveletMatrix<T,B>::range_freq_lt(int l, int r, T ub) const {
  int ret = 0;

  for(int i = 0; i < B; ++i){
    int t = (ub >> (B-i-1)) & 1;

    if(t){
      ret += sdict[i].count(l, r, 0);
    }

    l = sdict[i].rank(l, t) + t * zero_pos[i];
    r = sdict[i].rank(r, t) + t * zero_pos[i];
  }
    
  return ret;
}

/**
 * @return data[l, r)内で[lb, ub)であるような値の個数
 */
template <typename T, int B>
int WaveletMatrix<T,B>::range_freq(int l, int r, T lb, T ub) const {
  return range_freq_lt(l, r, ub) - range_freq_lt(l, r, lb);
}
