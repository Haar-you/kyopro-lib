#pragma once
#include <vector>

namespace haar_lib {
  template <typename T>
  T sum_of_exponential_times_polynomial_limit(int64_t r, int d) {
    T ret   = 0;
    T r_pow = 1;
    int m   = T::mod();

    std::vector<T> s(d + 1);
    std::vector<T> invs(d + 2);
    invs[1] = 1;

    for (int i = 2; i <= d + 1; ++i) {
      invs[i] = (m / i) * (m - invs[m % i]);
    }

    for (int i = 0; i <= d; ++i) {
      if (i > 0) s[i] += s[i - 1];
      s[i] += T::pow(i, d) * r_pow;
      r_pow *= r;
    }

    T t = 1;
    for (int i = 0; i <= d; ++i) {
      ret += t * s[d - i];
      t *= invs[i + 1] * (-r) * (d + 1 - i);
    }

    ret /= T::pow(1 - r, d + 1);

    return ret;
  }
}  // namespace haar_lib
