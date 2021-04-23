#pragma once
#include <cassert>
#include <functional>
#include <vector>

namespace haar_lib {
  template <typename T>
  class cumulative_sum_1d {
  public:
    using value_type = T;

  private:
    template <typename>
    friend class cumulative_sum_1d_builder;
    int N_;
    std::vector<T> data_;

  public:
    T fold(int l, int r) const {
      assert(0 <= l and l <= r and r <= N_);
      return data_[r] - data_[l];
    }
  };

  template <typename T>
  class cumulative_sum_1d_builder {
    int N_;
    std::vector<T> data_;

  public:
    cumulative_sum_1d_builder() {}
    cumulative_sum_1d_builder(int N) : N_(N), data_(N + 1) {}

    auto& update(const std::vector<T>& a) {
      for (int i = 0; i < N_; ++i) data_[i + 1] += a[i];
      return *this;
    }

    auto& update(int i, const T& val) {
      assert(0 <= i and i < N_);
      data_[i + 1] += val;
      return *this;
    }

    auto build() const {
      cumulative_sum_1d<T> ret;
      ret.data_ = data_;
      ret.N_    = N_;
      for (int i = 0; i < N_; ++i) ret.data_[i + 1] += ret.data_[i];
      return ret;
    }
  };
}  // namespace haar_lib
