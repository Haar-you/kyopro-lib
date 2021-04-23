#pragma once
#include <cassert>
#include <vector>

namespace haar_lib {
  template <typename T>
  class matrix {
    std::vector<std::vector<T>> data_;
    size_t R_, C_;

  public:
    matrix() : data_(), R_(0), C_(0) {}
    matrix(size_t R, size_t C, T value = T()) : data_(R, std::vector<T>(C, value)), R_(R), C_(C) {}
    matrix(std::vector<std::vector<T>> data) : data_(data), R_(data.size()), C_(data[0].size()) {}

    const auto &operator[](size_t i) const {
      return data_[i];
    }

    friend auto operator*(const matrix<T> &a, const matrix<T> &b) {
      assert(a.C_ == b.R_);

      matrix ret(a.R_, b.C_);

      for (size_t i = 0; i < a.R_; ++i) {
        for (size_t k = 0; k < a.C_; ++k) {
          for (size_t j = 0; j < b.C_; ++j) {
            ret.data_[i][j] += a.data_[i][k] * b.data_[k][j];
          }
        }
      }

      return ret;
    }
  };
}  // namespace haar_lib
