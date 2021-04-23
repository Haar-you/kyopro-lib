#pragma once
#include <cassert>
#include <vector>

namespace haar_lib {
  template <typename T>
  class lazy_segment_tree_with_coefficients {
  public:
    using value_type = T;

  private:
    int depth_, size_, hsize_;
    std::vector<T> data_, lazy_, coeff_;

    void propagate(int i) {
      if (lazy_[i] == 0) return;
      if (i < hsize_) {
        lazy_[i << 1 | 0] = lazy_[i] + lazy_[i << 1 | 0];
        lazy_[i << 1 | 1] = lazy_[i] + lazy_[i << 1 | 1];
      }
      data_[i] = data_[i] + lazy_[i] * coeff_[i];
      lazy_[i] = 0;
    }

    T update(int i, int l, int r, int s, int t, const T &x) {
      propagate(i);
      if (r <= s or t <= l) return data_[i];
      if (s <= l and r <= t) {
        lazy_[i] += x;
        propagate(i);
        return data_[i];
      }
      return data_[i] =
                 update(i << 1 | 0, l, (l + r) / 2, s, t, x) +
                 update(i << 1 | 1, (l + r) / 2, r, s, t, x);
    }

    T get(int i, int l, int r, int x, int y) {
      propagate(i);
      if (r <= x or y <= l) return 0;
      if (x <= l and r <= y) return data_[i];
      return get(i << 1 | 0, l, (l + r) / 2, x, y) + get(i << 1 | 1, (l + r) / 2, r, x, y);
    }

  public:
    lazy_segment_tree_with_coefficients() {}
    lazy_segment_tree_with_coefficients(int n, std::vector<T> coeff) : depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),
                                                                       size_(1 << depth_),
                                                                       hsize_(size_ / 2),
                                                                       data_(size_, 0),
                                                                       lazy_(size_, 0),
                                                                       coeff_(size_, 0) {
      for (int i = hsize_; i < size_; ++i) coeff_[i] = coeff[i - hsize_];
      for (int i = hsize_; --i >= 1;) coeff_[i] = coeff_[i << 1 | 0] + coeff_[i << 1 | 1];
    }

    void update(int l, int r, const T &x) {
      assert(0 <= l and l <= r and r <= hsize_);
      update(1, 0, hsize_, l, r, x);
    }
    void update(int i, const T &x) { update(i, i + 1, x); }

    T fold(int l, int r) {
      assert(0 <= l and l <= r and r <= hsize_);
      return get(1, 0, hsize_, l, r);
    }
    T fold_all() { return fold(0, hsize_); }
    T operator[](int i) { return fold(i, i + 1); }

    void init(const T &val) {
      init_with_vector(std::vector<T>(hsize_, val));
    }

    void init_with_vector(const std::vector<T> &val) {
      data_.assign(size_, 0);
      lazy_.assign(size_, 0);
      for (int i = 0; i < (int) val.size(); ++i) data_[hsize_ + i] = val[i];
      for (int i = hsize_; --i >= 0;) data_[i] = data_[i << 1 | 0] + data_[i << 1 | 1];
    }
  };
}  // namespace haar_lib
