#pragma once
#include <vector>
#include <cassert>
#include <cstdint>

/**
 * @title Factorial table
 * @docs factorial_table.md
 */
namespace haar_lib {
  template <typename T>
  class factorial_table {
  public:
    using value_type = T;

  private:
    std::vector<T> f_table;
    std::vector<T> if_table;

  public:
    factorial_table(int N){
      f_table.assign(N + 1, 1);
      if_table.assign(N + 1, 1);

      for(int i = 1; i <= N; ++i){
        f_table[i] = f_table[i - 1] * i;
      }

      if_table[N] = f_table[N].inv();

      for(int i = N; --i >= 0;){
        if_table[i] = if_table[i + 1] * (i + 1);
      }
    }

    T factorial(int64_t i) const {
      assert(i < (int)f_table.size());
      return f_table[i];
    }

    T inv_factorial(int64_t i) const {
      assert(i < (int)if_table.size());
      return if_table[i];
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
