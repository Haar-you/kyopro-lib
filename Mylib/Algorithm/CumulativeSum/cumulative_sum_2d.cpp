#pragma once
#include <vector>
#include <functional>
#include <cassert>

namespace haar_lib {
  template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
  class cumulative_sum_2d {
  public:
    using value_type = T;

  private:
    std::vector<std::vector<T>> data_;
    int N_, M_;
    Add add_;
    Minus minus_;
    bool is_built_ = false;

  public:
    cumulative_sum_2d(){}
    cumulative_sum_2d(int N, int M, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
      N_(N), M_(M), add_(add), minus_(minus)
    {
      data_.assign(N_ + 1, std::vector<T>(M_ + 1, e));
    }

    auto& update(const std::vector<std::vector<T>> &a){
      assert(not is_built_);
      for(int i = 0; i < N_; ++i){
        for(int j = 0; j < M_; ++j){
          data_[i + 1][j + 1] = add_(data_[i + 1][j + 1], a[i][j]);
        }
      }
      return *this;
    }

    auto& update(int i, int j, const T &val){
      assert(not is_built_);
      data_[i + 1][j + 1] = add_(data_[i + 1][j + 1], val);
      return *this;
    }

    auto& build(){
      assert(not is_built_);
      for(int i = 1; i <= N_; ++i)
        for(int j = 0; j <= M_; ++j)
          data_[i][j] = add_(data_[i][j], data_[i - 1][j]);
      for(int i = 0; i <= N_; ++i)
        for(int j = 1; j <= M_; ++j)
          data_[i][j] = add_(data_[i][j], data_[i][j - 1]);
      is_built_ = true;
      return *this;
    }

    T fold(std::pair<int, int> p1, std::pair<int, int> p2) const {
      assert(is_built_);
      const auto [x1, y1] = p1;
      const auto [x2, y2] = p2;
      return add_(minus_(data_[x2][y2], add_(data_[x1][y2], data_[x2][y1])), data_[x1][y1]);
    }
  };
}
