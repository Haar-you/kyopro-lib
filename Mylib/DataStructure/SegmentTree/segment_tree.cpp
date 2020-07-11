#pragma once
#include <vector>

/**
 * @title Segment tree
 * @docs segment_tree.md
 */
template <typename Monoid>
class SegmentTree{
  using value_type = typename Monoid::value_type;
  Monoid M;
  
  int depth, size, hsize;
  std::vector<value_type> data;

public:
  SegmentTree(){}
  SegmentTree(int n):
    depth(n > 1 ? 32-__builtin_clz(n-1) + 1 : 1),
    size(1 << depth), hsize(size / 2),
    data(size, M.id())
  {}

  auto operator[](int i) const {return at(i);}
  auto at(int i) const {return data[hsize + i];}
  
  auto get(int x, int y) const { // [x,y)
    value_type ret_left = M.id();
    value_type ret_right = M.id();
    
    int l = x + hsize, r = y + hsize;
    while(l < r){
      if(r & 1) ret_right = M.op(data[--r], ret_right);
      if(l & 1) ret_left = M.op(ret_left, data[l++]);
      l >>= 1, r >>= 1;
    }
    
    return M.op(ret_left, ret_right);
  }

  void update(int i, const value_type &x){
    i += hsize;
    data[i] = x;
    while(i > 1) i >>= 1, data[i] = M.op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init_with_vector(const std::vector<T> &val){
    data.assign(size, M.id());
    for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = val[i];
    for(int i = hsize-1; i >= 1; --i) data[i] = M.op(data[i << 1 | 0], data[i << 1 | 1]);
  }

  template <typename T>
  void init(const T &val){
    init_with_vector(std::vector<value_type>(hsize, val));
  }  
};
