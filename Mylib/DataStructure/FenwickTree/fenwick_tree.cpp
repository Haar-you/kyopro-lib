#pragma once
#include <vector>

namespace haar_lib {
  template <typename AbelianGroup>
  class fenwick_tree {
  public:
    using value_type = typename AbelianGroup::value_type;

  private:
    AbelianGroup G_;
    int size_;
    std::vector<value_type> data_;

  public:
    fenwick_tree(){}
    fenwick_tree(int size):
      size_(size), data_(size + 1, G_()){}

    void update(int i, const value_type &val){
      i += 1; // 1-index

      while(i <= size_){
        data_[i] = G_(data_[i], val);
        i += i & (-i);
      }
    }

    value_type fold(int i) const { // [0, i)
      value_type ret = G_();

      while(i > 0){
        ret = G_(ret, data_[i]);
        i -= i & (-i);
      }

      return ret;
    }

    value_type fold(int l, int r) const { // [l, r)
      return G_(fold(r), G_.inv(fold(l)));
    }

    value_type operator[](int x) const {
      return fold(x, x + 1);
    }
  };
}
