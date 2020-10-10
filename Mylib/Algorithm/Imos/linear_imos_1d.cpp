#pragma once
#include <vector>
#include <cassert>

namespace haar_lib {
  template <typename T>
  class linear_imos_1d {
  public:
    using value_type = T;

  private:
    int n_;
    std::vector<T> vec_a_, vec_a_end_, vec_b_, data_;

  public:
    linear_imos_1d(int n):
      n_(n), vec_a_(n_ + 1), vec_a_end_(n_ + 1), vec_b_(n_ + 1), data_(n_){}

    void update(int s, int t, const T &a, const T &b){
      assert(0 <= s and s <= t and t <= n_);
      vec_a_[s + 1] += a;
      vec_a_[t] -= a;

      vec_a_end_[t] -= a * (t - s - 1);

      vec_b_[s] += b;
      vec_b_[t] -= b;
    }

    auto build() const {
      std::vector<T> ret(vec_a_);
      for(int i = 0; i < n_; ++i) ret[i + 1] += ret[i];
      for(int i = 0; i < n_; ++i) ret[i] += vec_a_end_[i];
      for(int i = 0; i < n_; ++i) ret[i + 1] += ret[i];

      std::vector<T> temp(vec_b_);
      for(int i = 0; i < n_; ++i) temp[i + 1] += temp[i];
      for(int i = 0; i < n_; ++i) ret[i] += temp[i];

      ret.pop_back();

      return ret;
    }
  };
}
