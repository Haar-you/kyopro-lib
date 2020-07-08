#pragma once
#include <vector>

/**
 * @title Fenwick tree
 * @docs fenwick_tree.md
 */
template <typename AbelianGroup>
class FenwickTree{
  using value_type = typename AbelianGroup::value_type;
  
  int size;
  std::vector<value_type> data;
  
public:
  FenwickTree(){}
  FenwickTree(int size):
    size(size), data(size + 1, AbelianGroup::id())
  {}
  
  void update(int i, const value_type &val){
    i += 1; // 1-index
    
    while(i <= size){
      data[i] = AbelianGroup::op(data[i], val);
      i += i & (-i);
    }
  }
  
  value_type get(int i) const { // [0, i)
    value_type ret = AbelianGroup::id();
    i += 1; // 1-index

    while(i > 0){
      ret = AbelianGroup::op(ret, data[i]);
      i -= i & (-i);
    }

    return ret;
  }

  value_type get(int l, int r) const { // [l, r)
    return AbelianGroup::op(get(r-1), AbelianGroup::inv(get(l-1)));
  }
  
  value_type at(int x) const {
    return get(x, x+1);
  }
};
