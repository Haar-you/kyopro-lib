#pragma once
#include <vector>

/**
 * @title Dual segment tree
 * @docs dual_segment_tree.md
 */
template <typename Monoid>
class DualSegmentTree{
  using value_type = typename Monoid::value_type;
  const static Monoid M;

  const int depth, size, hsize;
  std::vector<value_type> data;
  
  void propagate(int i){
    if(i < hsize){
      data[i << 1 | 0] = M(data[i], data[i << 1 | 0]);
      data[i << 1 | 1] = M(data[i], data[i << 1 | 1]);
      data[i] = M();
    }
  }

  void propagate_top_down(int i){
    std::vector<int> temp;
    while(i > 1){
      i >>= 1;
      temp.push_back(i);
    }

    for(auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
  }
  
public:
  DualSegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, M())
  {}

  void update(int l, int r, const value_type &x){
    propagate_top_down(l + hsize);
    propagate_top_down(r + hsize);

    int L = l + hsize;
    int R = r + hsize;
    
    while(L < R){
      if(R & 1) --R, data[R] = M(x, data[R]);
      if(L & 1) data[L] = M(x, data[L]), ++L;
      L >>= 1, R >>= 1;
    }
  }

  value_type get(int i){
    propagate_top_down(i + hsize);
    return data[i + hsize];
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &a){
    data.assign(size, M());
    for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];
  }

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }
};
