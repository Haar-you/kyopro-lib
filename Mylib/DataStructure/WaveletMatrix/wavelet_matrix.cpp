#pragma once
#include <vector>
#include <utility>
#include <tuple>
#include <cassert>
#include <optional>
#include "Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp"

/**
 * @title Wavelet matrix
 * @docs wavelet_matrix.md
 */

template <typename T, int B>
class WaveletMatrix{
public:
  const int N;

  SuccinctDict sdict[B];
  int zero_pos[B];

  WaveletMatrix(std::vector<T> data): N(data.size()){
    std::vector<bool> s(N);

    for(int k = 0; k < B; ++k){
      std::vector<T> left, right;

      for(int i = 0; i < N; ++i){
        s[i] = (data[i] >> (B-1-k)) & 1;
        if(s[i]){
          right.push_back(data[i]);
        }else{
          left.push_back(data[i]);
        }
      }

      sdict[k] = SuccinctDict(s);
      zero_pos[k] = left.size();

      std::swap(data, left);
      data.insert(data.end(), right.begin(), right.end());
    }
  }
};


/**
 * @return data[index]
 */
template <typename T, int B>
inline T access(const WaveletMatrix<T, B> &wm, int index){
  T ret = 0;

  int p = index;
  for(int i = 0; i < B; ++i){
    int t = wm.sdict[i].access(p);
    ret |= ((T)t << (B-1-i));
    p = wm.sdict[i].rank(p, t) + t * wm.zero_pos[i];
  }
    
  return ret;
}

template <typename T, int B>
inline std::pair<int,int> rank_aux(const WaveletMatrix<T, B> &wm, int index, const T &val){
  int l = 0, r = index;

  for(int i = 0; i < B; ++i){
    int t = (val >> (B-i-1)) & 1;
    l = wm.sdict[i].rank(l, t) + t * wm.zero_pos[i];
    r = wm.sdict[i].rank(r, t) + t * wm.zero_pos[i];
  }

  return std::make_pair(l, r);
}

/**
 * @return data[0, index)に含まれるvalの個数
 */
template <typename T, int B>
inline int rank(const WaveletMatrix<T, B> &wm, int index, const T &val){
  int l, r; std::tie(l, r) = rank_aux(wm, index, val);
  return r - l;
}

/*
 * @return data[l, r)に含まれるvalの個数
 */
template <typename T, int B>
inline int count(const WaveletMatrix<T, B> &wm, int l, int r, const T &val){
  return rank(wm, r, val) - rank(wm, l, val);
}
  
/**
 * @return count番目のvalの位置
 */
template <typename T, int B>
std::optional<int> select(const WaveletMatrix<T, B> &wm, int count, const T &val){
  if(count <= 0) return {};
    
  int l, r; std::tie(l, r) = rank_aux(wm, wm.N, val);
  if(r - l < count) return {};

  int p = l + count - 1;

  for(int i = B-1; i >= 0; --i){
    int t = (val >> (B-i-1)) & 1;
    p = *wm.sdict[i].select(p - t * wm.zero_pos[i] + 1, t);
  }
    
  return {p};
}

/**
 * @return data[l, r)でk(1-index)番目に小さい値
 */
template <typename T, int B>
std::optional<T> quantile(const WaveletMatrix<T, B> &wm, int l, int r, int k){
  assert(0 <= l and l < r and r <= wm.N);
  if(k == 0) return {};

  T ret = 0;

  for(int i = 0; i < B; ++i){
    const int count_1 = wm.sdict[i].rank(r, 1) - wm.sdict[i].rank(l, 1);
    const int count_0 = r - l - count_1;

    int t = 0;

    if(k > count_0){
      t = 1;
      ret |= ((T)t << (B-i-1));
      k -= count_0;
    }
      
    l = wm.sdict[i].rank(l, t) + t * wm.zero_pos[i];
    r = wm.sdict[i].rank(r, t) + t * wm.zero_pos[i];
  }
    
  return {ret};
}

template <typename T, int B>
T maximum(const WaveletMatrix<T, B> &wm, int l, int r){
  return *quantile(wm, l, r, r-l);
}

template <typename T, int B>
T minimum(const WaveletMatrix<T, B> &wm, int l, int r){
  return *quantile(wm, l, r, 1);
}


WaveletMatrix<uint32_t,32> make_wavelet_matrix_int(const std::vector<uint32_t> &data){
  return WaveletMatrix<uint32_t, 32>(data);
}
