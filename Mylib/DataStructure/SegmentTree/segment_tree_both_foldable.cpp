#pragma once
#include <vector>

namespace haar_lib {
  template <typename Monoid>
  class segment_tree_both_foldable {
  public:
    using value_type = typename Monoid::value_type;

  private:
    Monoid M_;
    int depth_, size_, hsize_;
    std::vector<value_type> data_left_, data_right_;

  public:
    segment_tree_both_foldable(){}
    segment_tree_both_foldable(int n):
      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
      size_(1 << depth_),
      hsize_(size_ / 2),
      data_left_(size_, M_()),
      data_right_(size_, M_())
    {}

    auto operator[](int i) const {return data_left_[hsize_ + i];}

    auto fold_left(int x, int y) const {
      value_type ret_left = M_();
      value_type ret_right = M_();

      int l = x + hsize_, r = y + hsize_;
      while(l < r){
        if(r & 1) ret_right = M_(data_left_[--r], ret_right);
        if(l & 1) ret_left = M_(ret_left, data_left_[l++]);
        l >>= 1, r >>= 1;
      }

      return M_(ret_left, ret_right);
    }

    auto fold_right(int x, int y) const {
      value_type ret_left = M_();
      value_type ret_right = M_();

      int l = x + hsize_, r = y + hsize_;
      while(l < r){
        if(r & 1) ret_right = M_(ret_right, data_right_[--r]);
        if(l & 1) ret_left = M_(data_right_[l++], ret_left);
        l >>= 1, r >>= 1;
      }

      return M_(ret_right, ret_left);
    }

    void set(int i, const value_type &x){
      i += hsize_;
      data_left_[i] = data_right_[i] = x;
      while(i > 1){
        i >>= 1;
        data_left_[i] = M_(data_left_[i << 1 | 0], data_left_[i << 1 | 1]);
        data_right_[i] = M_(data_right_[i << 1 | 1], data_right_[i << 1 | 0]);
      }
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &val){
      data_left_.assign(size_, M_());
      data_right_.assign(size_, M_());

      for(int i = 0; i < (int)val.size(); ++i){
        data_left_[hsize_ + i] = val[i];
        data_right_[hsize_ + i] = val[i];
      }
      for(int i = hsize_; --i >= 1;){
        data_left_[i] = M_(data_left_[i << 1 | 0], data_left_[i << 1 | 1]);
        data_right_[i] = M_(data_right_[i << 1 | 1], data_right_[i << 1 | 0]);
      }
    }

    template <typename T>
    void init(const T &val){
      init_with_vector(std::vector<value_type>(hsize_, val));
    }
  };
}
