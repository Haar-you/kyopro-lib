#pragma once
#include <vector>

namespace haar_lib {
  template <typename T>
  class fenwick_tree_add {
    using value_type = T;

    int size;
    std::vector<value_type> data;

  public:
    fenwick_tree_add(){}
    fenwick_tree_add(int size): size(size), data(size + 1, 0){}

    void update(int i, value_type val){
      i += 1; // 1-index

      while(i <= size){
        data[i] = data[i] + val;
        i += i & (-i);
      }
    }

    value_type fold(int i) const { // [0, i)
      value_type ret = 0;
      i += 1; // 1-index

      while(i > 0){
        ret = ret + data[i];
        i -= i & (-i);
      }

      return ret;
    }

    value_type fold(int l, int r) const { // [l, r)
      return fold(r - 1) - fold(l - 1);
    }

    value_type operator[](int x) const {
      return fold(x, x + 1);
    }
  };
}
