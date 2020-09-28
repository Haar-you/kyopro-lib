#pragma once
#include <vector>
#include <functional>
#include <cassert>

namespace haar_lib {
  template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
  class cumulative_sum_1d {
  public:
    using value_type = T;

  private:
    std::vector<T> data_;
    int N_;
    Add add_;
    Minus minus_;
    bool is_built_ = false;

  public:
    cumulative_sum_1d(){}
    cumulative_sum_1d(
      int N, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()
    ): N_(N), add_(add), minus_(minus)
    {
      data_.assign(N_ + 1, e);
    }

    auto& update(const std::vector<T> &a){
      assert(not is_built_);
      for(int i = 0; i < N_; ++i) data_[i + 1] = add_(data_[i + 1], a[i]);
      return *this;
    }

    auto& update(int i, const T &val){
      assert(not is_built_);
      data_[i + 1] = add_(data_[i + 1], val);
      return *this;
    }

    auto& build(){
      assert(not is_built_);
      for(int i = 0; i < N_; ++i) data_[i + 1] = add_(data_[i + 1], data_[i]);
      is_built_ = true;
      return *this;
    }

    T fold(int l, int r) const {
      assert(is_built_);
      return minus_(data_[r], data_[l]);
    }
  };
}
