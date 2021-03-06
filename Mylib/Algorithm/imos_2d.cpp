#pragma once
#include <cassert>
#include <vector>

namespace haar_lib {
  template <typename T>
  struct imos_2d {
    using value_type = T;

  private:
    std::vector<std::vector<T>> data_;
    int n_, m_;

  public:
    imos_2d() {}
    imos_2d(int n, int m) : data_(n, std::vector<T>(m)), n_(n), m_(m) {}

    void update(std::pair<int, int> p1, std::pair<int, int> p2, T val) {
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      assert(0 <= x1 and x1 <= x2 and x2 <= n_);
      assert(0 <= y1 and y1 <= y2 and y2 <= m_);

      data_[x1][y1] += val;
      if (x2 < n_ and y2 < m_) data_[x2][y2] += val;
      if (y2 < m_) data_[x1][y2] -= val;
      if (x2 < n_) data_[x2][y1] -= val;
    }

    auto build() const {
      std::vector<std::vector<T>> ret(data_);
      for (int i = 1; i < n_; ++i) {
        for (int j = 0; j < m_; ++j) {
          ret[i][j] += ret[i - 1][j];
        }
      }

      for (int i = 0; i < n_; ++i) {
        for (int j = 1; j < m_; ++j) {
          ret[i][j] += ret[i][j - 1];
        }
      }
      return ret;
    }
  };
}  // namespace haar_lib
