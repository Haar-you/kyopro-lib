#pragma once
#include <vector>
#include <utility>
#include <tuple>
#include <cassert>
#include "Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp"

/**
 * @title Wavelet matrix
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549 (prev_value, next_value)
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2674 (range_freq)
 * @see https://www.spoj.com/problems/MKTHNUM/ (quantile)
 */

template <typename T, int B>
class WaveletMatrix{
  const int N;

  SuccinctDict sdict[B];
  int zero_pos[B];

public:
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

public:
  /**
   * @return data[index]
   */
  inline T access(int index) const {
    T ret = 0;

    int p = index;
    for(int i = 0; i < B; ++i){
      int t = sdict[i].access(p);
      ret |= ((T)t << (B-1-i));
      p = sdict[i].rank(p, t) + t * zero_pos[i];
    }
    
    return ret;
  }

private:
  inline std::pair<int,int> rank_aux(int index, const T &val) const {
    int l = 0, r = index;

    for(int i = 0; i < B; ++i){
      int t = (val >> (B-i-1)) & 1;
      l = sdict[i].rank(l, t) + t * zero_pos[i];
      r = sdict[i].rank(r, t) + t * zero_pos[i];
    }

    return std::make_pair(l, r);
  }

public:
  /**
   * @return data[0,index)に含まれるvalの個数
   */
  inline int rank(int index, const T &val) const {
    int l, r; std::tie(l, r) = rank_aux(index, val);
    return r - l;
  }

public:
  /*
   * @return data[s,e)に含まれるvalの個数
   */
  inline int count(int s, int e, const T &val) const {
    return rank(e, val) - rank(s, val);
  }
  
public:
  /**
   * @retval 0<= count番目のvalの位置
   * @retval -1 count番目のvalが存在しない
   */
  int select(int count, const T &val) const {
    if(count <= 0) return -1;
    
    int l, r; std::tie(l, r) = rank_aux(N, val);
    if(r - l < count) return -1;

    int p = l + count - 1;

    for(int i = B-1; i >= 0; --i){
      int t = (val >> (B-i-1)) & 1;
      p = sdict[i].select(p - t * zero_pos[i] + 1, t);
    }
    
    return p;
  }

public:
  /**
   * @return data[l,r)でk(1-index)番目に小さい値
   */
  T quantile(int l, int r, int k) const {
    assert(0 <= l and l < r and r <= N);
    if(k == 0) return -1;

    T ret = 0;

    for(int i = 0; i < B; ++i){
      const int count_1 = sdict[i].rank(r, 1) - sdict[i].rank(l, 1);
      const int count_0 = r - l - count_1;

      int t = 0;

      if(k > count_0){
        t = 1;
        ret |= ((T)t << (B-i-1));
        k -= count_0;
      }
      
      l = sdict[i].rank(l, t) + t * zero_pos[i];
      r = sdict[i].rank(r, t) + t * zero_pos[i];
    }
    
    return ret;
  }

public:
  T maximum(int s, int e) const {
    return quantile(s, e, e-s);
  }

public:
  T minimum(int s, int e) const {
    return quantile(s, e, 1);
  }

public:
  int range_freq_lt(int, int, T) const;
  int range_freq(int, int, T, T) const;
  std::vector<std::pair<int,T>> range_freq_list(int, int, T, T) const;
  T next_value(int, int, T) const;
  T prev_value(int, int, T) const;
  std::vector<std::pair<int,T>> top_k(int, int, int) const;
};


WaveletMatrix<uint32_t,32> make_wavelet_matrix_int(const std::vector<uint32_t> &data){
  return WaveletMatrix<uint32_t, 32>(data);
}
