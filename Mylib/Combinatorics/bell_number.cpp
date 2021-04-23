#pragma once
#include <algorithm>
#include <vector>
#include "Mylib/Combinatorics/factorial_table.cpp"

namespace haar_lib {
  template <
      const auto &ft,
      typename T = typename std::remove_reference_t<decltype(ft)>::value_type>
  T bell_number(int n, int k) {
    if (n == 0) return T(1);

    k = std::min(k, n);

    std::vector<T> t(k, 1);

    for (int i = 1; i < k; ++i) {
      if (i % 2 == 0)
        t[i] = t[i - 1] + ft.inv_factorial(i);
      else
        t[i] = t[i - 1] - ft.inv_factorial(i);
    }

    T ret = 0;
    for (int i = 1; i <= k; ++i) {
      ret += t[k - i] * T::pow(i, n) * ft.inv_factorial(i);
    }

    return ret;
  }
}  // namespace haar_lib
