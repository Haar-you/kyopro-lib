#pragma once
#include <vector>

namespace haar_lib {
  template <typename T>
  class fenwick_tree_add {
  public:
    using value_type = T;

  private:
    int size_;
    std::vector<value_type> data_;

  public:
    fenwick_tree_add(){}
    fenwick_tree_add(int size): size_(size), data_(size + 1, 0){}

    void update(int i, value_type val){
      i += 1; // 1-index

      while(i <= size_){
        data_[i] = data_[i] + val;
        i += i & (-i);
      }
    }

    value_type fold(int i) const { // [0, i)
      value_type ret = 0;

      while(i > 0){
        ret = ret + data_[i];
        i -= i & (-i);
      }

      return ret;
    }

    value_type fold(int l, int r) const { // [l, r)
      return fold(r) - fold(l);
    }

    value_type operator[](int x) const {
      return fold(x, x + 1);
    }
  };
}
