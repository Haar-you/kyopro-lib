#pragma once
#include <vector>
#include <cassert>
#include <cstdint>

namespace haar_lib {
  template <typename T>
  class factorial_table {
  public:
    using value_type = T;

  private:
    int N_;
    std::vector<T> f_table_, if_table_;

  public:
    factorial_table(){}
    factorial_table(int N): N_(N){
      f_table_.assign(N + 1, 1);
      if_table_.assign(N + 1, 1);

      for(int i = 1; i <= N; ++i){
        f_table_[i] = f_table_[i - 1] * i;
      }

      if_table_[N] = f_table_[N].inv();

      for(int i = N; --i >= 0;){
        if_table_[i] = if_table_[i + 1] * (i + 1);
      }
    }

    T factorial(int64_t i) const {
      assert(0 <= i and i <= N_);
      return f_table_[i];
    }

    T inv_factorial(int64_t i) const {
      assert(0 <= i and i <= N_);
      return if_table_[i];
    }

    T P(int64_t n, int64_t k) const {
      if(n < k or n < 0 or k < 0) return 0;
      return factorial(n) * inv_factorial(n - k);
    }

    T C(int64_t n, int64_t k) const {
      if(n < k or n < 0 or k < 0) return 0;
      return P(n, k) * inv_factorial(k);
    }

    T H(int64_t n, int64_t k) const {
      if(n == 0 and k == 0) return 1;
      return C(n + k - 1, k);
    }
  };
}
