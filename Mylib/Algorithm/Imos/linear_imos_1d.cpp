#pragma once
#include <vector>

namespace haar_lib {
  template <typename T>
  class linear_imos_1d {
  public:
    using value_type = T;

  private:
    int n_;
    std::vector<T> vec_a_, vec_a_end_, vec_b_, vec_;

  public:
    linear_imos_1d(int n):
      n_(n), vec_a_(n_ + 1), vec_a_end_(n_ + 1), vec_b_(n_ + 1), vec_(n_ + 1){}

    void add(int s, int t, const T &a, const T &b){ // x ∈ [s, t)にax+bを加算する。
      vec_a_[s + 1] += a;
      vec_a_[t] -= a;

      vec_a_end_[t] -= a * (t - s - 1);

      vec_b_[s] += a * s + b;
      vec_b_[t] -= a * s + b;
    }

    void build(){
      for(int i = 0; i < n_; ++i) vec_a_[i + 1] += vec_a_[i];
      for(int i = 0; i <= n_; ++i) vec_a_[i] += vec_a_end_[i];
      for(int i = 0; i < n_; ++i) vec_a_[i + 1] += vec_a_[i];

      for(int i = 0; i < n_; ++i) vec_b_[i + 1] += vec_b_[i];

      for(int i = 0; i <= n_; ++i) vec_[i] = vec_a_[i] + vec_b_[i];
    }

    T operator[](size_t i) const {return vec_[i];}
  };
}
