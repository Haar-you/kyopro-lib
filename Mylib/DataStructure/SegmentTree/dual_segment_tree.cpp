#pragma once
#include <cassert>
#include <vector>

namespace haar_lib {
  template <typename Monoid>
  class dual_segment_tree {
  public:
    using value_type = typename Monoid::value_type;

  private:
    Monoid M_;
    int depth_, size_, hsize_;
    std::vector<value_type> data_;

    void propagate(int i) {
      if (i < hsize_) {
        data_[i << 1 | 0] = M_(data_[i], data_[i << 1 | 0]);
        data_[i << 1 | 1] = M_(data_[i], data_[i << 1 | 1]);
        data_[i]          = M_();
      }
    }

    void propagate_top_down(int i) {
      std::vector<int> temp;
      while (i > 1) {
        i >>= 1;
        temp.push_back(i);
      }

      for (auto it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);
    }

  public:
    dual_segment_tree() {}
    dual_segment_tree(int n) : depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
                               size_(1 << depth_),
                               hsize_(size_ / 2),
                               data_(size_, M_()) {}

    void update(int l, int r, const value_type &x) {
      assert(0 <= l and l <= r and r <= hsize_);
      propagate_top_down(l + hsize_);
      propagate_top_down(r + hsize_);

      int L = l + hsize_;
      int R = r + hsize_;

      while (L < R) {
        if (R & 1) --R, data_[R] = M_(x, data_[R]);
        if (L & 1) data_[L] = M_(x, data_[L]), ++L;
        L >>= 1, R >>= 1;
      }
    }

    value_type operator[](int i) {
      assert(0 <= i and i < hsize_);
      propagate_top_down(i + hsize_);
      return data_[i + hsize_];
    }

    template <typename T>
    void init_with_vector(const std::vector<T> &a) {
      data_.assign(size_, M_());
      for (int i = 0; i < (int) a.size(); ++i) data_[hsize_ + i] = a[i];
    }

    template <typename T>
    void init(const T &val) {
      init_with_vector(std::vector<value_type>(hsize_, val));
    }
  };
}  // namespace haar_lib
