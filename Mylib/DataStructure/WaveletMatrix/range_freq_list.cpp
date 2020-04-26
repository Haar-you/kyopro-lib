#pragma once
#include <vector>
#include <utility>
#include <tuple>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"

/**
 * @title range_freq_list
 * @return data[l, r)で[lb, ub)を満たすものを出現頻度と値のpairで返す。
 * @docs wavelet_matrix.md
 */
template <typename T, int B>
auto range_freq_list(const WaveletMatrix<T, B> &wm, int l, int r, T lb, T ub){
  std::vector<std::pair<int, T>> ret;

  std::queue<std::tuple<int,int,int,T>> q;

  q.emplace(l, r, 0, 0);

  while(not q.empty()){
    int l, r, d;
    T val;
    std::tie(l, r, d, val) = q.front(); q.pop();

    if(d == B){
      if(lb <= val and val < ub){
        ret.emplace_back(r-l, val);
      }
      continue;
    }

    const T mask = ~(T)0 ^ (((T)1 << (B-d))-1);
    const T b = (T)1 << (B-d-1);

    if(wm.sdict[d].count(l, r, 0) != 0){
      if(val != (lb & mask) or not (lb & b)){
        int L = wm.sdict[d].rank(l, 0);
        int R = wm.sdict[d].rank(r, 0);
        q.emplace(L, R, d+1, val);
      }
    }

    if(wm.sdict[d].count(l, r, 1) != 0){
      if(val != (ub & mask) or (ub & b)){
        int L = wm.sdict[d].rank(l, 1) + wm.zero_pos[d];
        int R = wm.sdict[d].rank(r, 1) + wm.zero_pos[d];
        q.emplace(L, R, d+1, val | b);
      }
    }
  }
  
  return ret;
}
