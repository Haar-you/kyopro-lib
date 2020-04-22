#pragma once
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"

/**
 * @title range_freq
 */

template <typename T, int B>
int range_freq_lt(const WaveletMatrix<T, B> &wm, int l, int r, T ub){
  int ret = 0;

  for(int i = 0; i < B; ++i){
    int t = (ub >> (B-i-1)) & 1;

    if(t){
      ret += wm.sdict[i].count(l, r, 0);
    }

    l = wm.sdict[i].rank(l, t) + t * wm.zero_pos[i];
    r = wm.sdict[i].rank(r, t) + t * wm.zero_pos[i];
  }
    
  return ret;
}

/**
 * @return data[l, r)内で[lb, ub)であるような値の個数
 */
template <typename T, int B>
int range_freq(const WaveletMatrix<T, B> &wm, int l, int r, T lb, T ub){
  return range_freq_lt(wm, l, r, ub) - range_freq_lt(wm, l, r, lb);
}
