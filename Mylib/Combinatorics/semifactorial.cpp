#pragma once
#include <vector>
#include <cassert>

namespace haar_lib {
  template <typename T>
  class semifactorial {
  public:
    using value_type = T;

  private:
    int N_;
    std::vector<T> data_;

  public:
    semifactorial(){}
    semifactorial(int N): N_(N), data_(N + 1, 1){
      for(int i = 2; i <= N_; i += 2) data_[i] = data_[i - 2] * i;
      for(int i = 3; i <= N_; i += 2) data_[i] = data_[i - 2] * i;
    }

    T operator()(int i) const {
      assert(0 <= i and i <= N_);
      return data_[i];
    }
  };
}
