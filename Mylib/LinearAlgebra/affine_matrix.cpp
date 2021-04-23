#pragma once
#include <array>
#include <cmath>
#include <initializer_list>
#include <vector>

namespace haar_lib {
  template <typename T>
  class affine_matrix_2d {
  public:
    using value_type = T;

  private:
    std::array<std::array<T, 3>, 3> data_;

  public:
    affine_matrix_2d() {}
    affine_matrix_2d(std::initializer_list<std::initializer_list<T>> list) {
      int i = 0, j = 0;
      for (auto it = list.begin(); it != list.end(); ++it) {
        j = 0;
        for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
          data_[i][j] = *it2;
          ++j;
        }
        ++i;
      }
    }

    const auto& data() const { return data_; }
    auto& data() { return data_; }

    const auto& operator[](size_t i) const { return data_[i]; }
    auto& operator[](size_t i) { return data_[i]; }

    auto& operator*=(const affine_matrix_2d& that) {
      std::array<std::array<T, 3>, 3> ret = {};
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          for (int k = 0; k < 3; ++k)
            ret[i][j] += data_[i][k] * that.data_[k][j];
      data_ = ret;
      return *this;
    }

    auto operator*(const affine_matrix_2d& that) const {
      return affine_matrix_2d(*this) *= that;
    }

    auto operator*(const std::vector<T>& that) const {
      std::array<T, 3> ret = {};
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          ret[i] += data_[i][j] * that[j];
      return ret;
    }

    static auto unit() {
      return affine_matrix_2d({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
    }

    static auto rotate(double a) {
      return affine_matrix_2d(
          {{(T) std::cos(a), -(T) std::sin(a), 0}, {(T) std::sin(a), (T) std::cos(a), 0}, {0, 0, 1}});
    }

    static auto rotate90(int n = 1) {
      const static int c[4] = {1, 0, -1, 0};
      const static int s[4] = {0, 1, 0, -1};
      const int i           = ((n % 4) + 4) % 4;
      return affine_matrix_2d({{c[i], -s[i], 0}, {s[i], c[i], 0}, {0, 0, 1}});
    }

    static auto move(T dx, T dy) {
      return affine_matrix_2d({{1, 0, dx}, {0, 1, dy}, {0, 0, 1}});
    }

    static auto scale(T sx, T sy) {
      return affine_matrix_2d({{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}});
    }
  };
}  // namespace haar_lib
