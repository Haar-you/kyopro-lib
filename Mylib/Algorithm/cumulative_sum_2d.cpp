#pragma once
#include <cassert>
#include <functional>
#include <vector>

namespace haar_lib {
  template <typename T>
  class cumulative_sum_2d {
  public:
    using value_type = T;

  private:
    template <typename>
    friend class cumulative_sum_2d_builder;
    int N_, M_;
    std::vector<std::vector<T>> data_;

  public:
    T fold(std::pair<int, int> p1, std::pair<int, int> p2) const {
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      assert(0 <= x1 and x1 <= x2 and x2 <= N_);
      assert(0 <= y1 and y1 <= y2 and y2 <= M_);
      return data_[x2][y2] - data_[x1][y2] - data_[x2][y1] + data_[x1][y1];
    }
  };

  template <typename T>
  class cumulative_sum_2d_builder {
    int N_, M_;
    std::vector<std::vector<T>> data_;

  public:
    cumulative_sum_2d_builder() {}
    cumulative_sum_2d_builder(int N, int M) : N_(N), M_(M), data_(N + 1, std::vector<T>(M + 1)) {}

    auto& update(const std::vector<std::vector<T>>& a) {
      for (int i = 0; i < N_; ++i) {
        for (int j = 0; j < M_; ++j) {
          data_[i + 1][j + 1] += a[i][j];
        }
      }
      return *this;
    }

    auto& update(int i, int j, const T& val) {
      data_[i + 1][j + 1] += val;
      return *this;
    }

    auto build() const {
      cumulative_sum_2d<T> ret;
      ret.data_ = data_;
      ret.N_    = N_;
      ret.M_    = M_;

      for (int i = 1; i <= N_; ++i)
        for (int j = 0; j <= M_; ++j)
          ret.data_[i][j] += ret.data_[i - 1][j];
      for (int i = 0; i <= N_; ++i)
        for (int j = 1; j <= M_; ++j)
          ret.data_[i][j] += ret.data_[i][j - 1];
      return ret;
    }
  };
}  // namespace haar_lib
