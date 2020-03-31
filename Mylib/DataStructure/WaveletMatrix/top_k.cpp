#pragma once
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"

/**
 * @return data[l, r)で出現頻度が高い順にk個を返す
 */
template <typename T, int B>
std::vector<std::pair<int,T>> WaveletMatrix<T,B>::top_k(int l, int r, int k) const {
  std::priority_queue<std::tuple<int,int,int,int,T>> q;
  std::vector<std::pair<int,T>> ret;

  q.push(std::make_tuple(r-l, l, r, 0, 0));

  while(not q.empty()){
    int len, l, r, d;
    T val;
    std::tie(len, l, r, d, val) = q.top(); q.pop();

    if(d == B){
      ret.push_back(std::make_pair(len, val));
      if((int)ret.size() >= k) break;
      continue;
    }
      
    if(sdict[d].count(l, r, 0) != 0){
      int L = sdict[d].rank(l, 0);
      int R = sdict[d].rank(r, 0);
      q.push(std::make_tuple(R-L, L, R, d+1, val));
    }
      
    if(sdict[d].count(l, r, 1) != 0){
      int L = sdict[d].rank(l, 1) + zero_pos[d];
      int R = sdict[d].rank(r, 1) + zero_pos[d];
      q.push(std::make_tuple(R-L, L, R, d+1, val | ((T)1 << (B-d-1))));
    }
  }
    
  return ret;
}
