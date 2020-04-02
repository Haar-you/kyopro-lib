#pragma once
#include <vector>

/**
 * @title 双対セグメント木
 */
template <typename Monoid>
class DualSegmentTree{
  using value_type = typename Monoid::value_type;
  
private:
  const int depth, size, hsize;
  std::vector<value_type> data;
  
  inline void propagate(int i){
    if(i < hsize){
      data[i << 1 | 0] = Monoid::op(data[i], data[i << 1 | 0]);
      data[i << 1 | 1] = Monoid::op(data[i], data[i << 1 | 1]);
      data[i] = Monoid::id();
    }
  }

  inline void propagate_top_down(int i){
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
    data(size, Monoid::id())
  {}

  inline void update(int l, int r, const value_type &x){
    propagate_top_down(l + hsize);
    propagate_top_down(r + hsize);

    int L = l + hsize;
    int R = r + hsize;
    
    while(L < R){
      if(R & 1) --R, data[R] = Monoid::op(x, data[R]);
      if(L & 1) data[L] = Monoid::op(x, data[L]), ++L;
      L >>= 1, R >>= 1;
    }
  }

  inline value_type get(int i){
    propagate_top_down(i + hsize);
    return data[i + hsize];
  }

  template <typename T>
  inline void init_with_vector(const std::vector<T> &a){
    data.assign(size, Monoid::id());
    for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];
  }

  template <typename T>
  inline void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }
};
