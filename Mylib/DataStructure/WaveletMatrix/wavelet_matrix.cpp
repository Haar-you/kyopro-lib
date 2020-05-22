#pragma once
#include <vector>
#include <utility>
#include <tuple>
#include <cassert>
#include <optional>
#include <queue>
#include "Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp"

/**
 * @title WaveletMatrix
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

  /**
   * @return data[index]
   */
  inline T access(int index){
    assert(0 <= index and index < N);
    T ret = 0;

    int p = index;
    for(int i = 0; i < B; ++i){
      int t = sdict[i].access(p);
      ret |= ((T)t << (B-1-i));
      p = sdict[i].rank(p, t) + t * zero_pos[i];
    }
    
    return ret;
  }

  inline std::pair<int,int> rank_aux(int index, const T &val){
    int l = 0, r = index;

    for(int i = 0; i < B; ++i){
      int t = (val >> (B-i-1)) & 1;
      l = sdict[i].rank(l, t) + t * zero_pos[i];
      r = sdict[i].rank(r, t) + t * zero_pos[i];
    }

    return std::make_pair(l, r);
  }

  /**
   * @return data[0, index)に含まれるvalの個数
   */
  inline int rank(int index, const T &val){
    auto [l, r] = rank_aux(index, val);
    return r - l;
  }  

  /*
   * @return data[l, r)に含まれるvalの個数
   */
  inline int count(int l, int r, const T &val){
    assert(0 <= l and l <= r and r <= N);
    return rank(r, val) - rank(l, val);
  }

  /**
   * @return count(1-indexed)番目のvalの位置
   */
  std::optional<int> select(int count, const T &val){
    assert(1 <= count);
    
    auto [l, r] = rank_aux(N, val);
    if(r - l < count) return {};

    int p = l + count - 1;

    for(int i = B-1; i >= 0; --i){
      int t = (val >> (B-i-1)) & 1;
      p = *sdict[i].select(p - t * zero_pos[i] + 1, t);
    }
    
    return {p};
  }
  
  /**
   * @return data[l, r)でk(1-index)番目に小さい値
   */
  std::optional<T> quantile(int l, int r, int k){
    assert(0 <= l and l < r and r <= N);
    if(k == 0) return {};

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
    
    return {ret};
  }

  T maximum(int l, int r){
    assert(l < r);
    return *quantile(l, r, r-l);
  }

  T minimum(int l, int r){
    assert(l < r);
    return *quantile(l, r, 1);
  }

  /**
   * @return data[l, r)のlb以上で最小の値
   */
  std::optional<T> next_value(int l, int r, T lb){
    int c = range_freq_lt(l, r, lb);
    return quantile(l, r, c+1);
  }
  
  /**
   * @return data[l, r)のub未満で最大の値
   */
  std::optional<T> prev_value(int l, int r, T ub){
    int c = range_freq_lt(l, r, ub);
    return quantile(l, r, c);
  }

  int range_freq_lt(int l, int r, T ub){
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
  int range_freq(int l, int r, T lb, T ub){
    return range_freq_lt(l, r, ub) - range_freq_lt(l, r, lb);
  }

  /**
   * @return data[l, r)で[lb, ub)を満たすものを出現頻度と値のpairで返す。
   */
  auto range_freq_list(int l, int r, T lb, T ub){
    std::vector<std::pair<int, T>> ret;
    std::queue<std::tuple<int,int,int,T>> q;

    q.emplace(l, r, 0, 0);

    while(not q.empty()){
      auto [l, r, d, val] = q.front(); q.pop();

      if(d == B){
        if(lb <= val and val < ub){
          ret.emplace_back(r-l, val);
        }
        continue;
      }

      const T mask = ~(T)0 ^ (((T)1 << (B-d))-1);
      const T b = (T)1 << (B-d-1);

      if(sdict[d].count(l, r, 0) != 0){
        if(val != (lb & mask) or not (lb & b)){
          int L = sdict[d].rank(l, 0);
          int R = sdict[d].rank(r, 0);
          q.emplace(L, R, d+1, val);
        }
      }

      if(sdict[d].count(l, r, 1) != 0){
        if(val != (ub & mask) or (ub & b)){
          int L = sdict[d].rank(l, 1) + zero_pos[d];
          int R = sdict[d].rank(r, 1) + zero_pos[d];
          q.emplace(L, R, d+1, val | b);
        }
      }
    }
    
    return ret;
  }
  
  /**
   * @return data[l, r)で出現頻度が高い順にk個を返す
   */
  auto top_k(int l, int r, int k) const {
    std::priority_queue<std::tuple<int,int,int,int,T>> q;
    std::vector<std::pair<int,T>> ret;

    q.emplace(r-l, l, r, 0, 0);

    while(not q.empty()){
      auto [len, l, r, d, val] = q.top(); q.pop();

      if(d == B){
        ret.emplace_back(len, val);
        if((int)ret.size() >= k) break;
        continue;
      }
      
      if(sdict[d].count(l, r, 0) != 0){
        int L = sdict[d].rank(l, 0);
        int R = sdict[d].rank(r, 0);
        q.emplace(R-L, L, R, d+1, val);
      }
      
      if(sdict[d].count(l, r, 1) != 0){
        int L = sdict[d].rank(l, 1) + zero_pos[d];
        int R = sdict[d].rank(r, 1) + zero_pos[d];
        q.emplace(R-L, L, R, d+1, val | ((T)1 << (B-d-1)));
      }
    }
    
    return ret;
  }
};

WaveletMatrix<uint32_t,32> make_wavelet_matrix_int(const std::vector<uint32_t> &data){
  return WaveletMatrix<uint32_t, 32>(data);
}
