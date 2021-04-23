#pragma once
#include <cassert>
#include <vector>

namespace haar_lib {
  template <typename T>
  struct imos_1d {
    using value_type = T;

  private:
    std::vector<T> data_;
    int n_;

  public:
    imos_1d() {}
    imos_1d(int n) : data_(n), n_(n) {}

    void update(int l, int r, T val) {  // [l, r)
      assert(0 <= l and l <= r and r <= n_);
      data_[l] += val;
      if (r < n_) data_[r] -= val;
    }

    auto build() const {
      std::vector<T> ret(data_);
      for (int i = 1; i < n_; ++i) {
        ret[i] += ret[i - 1];
      }
      return ret;
    }
  };
}  // namespace haar_lib
