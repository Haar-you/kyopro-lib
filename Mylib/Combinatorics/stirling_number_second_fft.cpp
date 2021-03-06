#pragma once
#include <vector>

namespace haar_lib {
  template <typename T, const auto &convolve>
  std::vector<T> stirling_number_of_second_kind_fft(int N) {
    std::vector<T> a(N + 1), b(N + 1);

    std::vector<int> m(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
      if (m[i] != 0) continue;
      for (int j = 2 * i; j <= N; j += i) {
        m[j] = i;
      }
    }

    for (int i = 0; i <= N; ++i) {
      if (m[i] == 0) {
        a[i] = T::pow(i, N);
      } else {
        a[i] = a[m[i]] * a[i / m[i]];
      }
    }

    T f = 1;
    for (int i = 1; i <= N; ++i) f *= i;
    f = f.inv();

    for (int i = N; i >= 0; --i) {
      a[i] *= f;
      b[i] = f;
      f *= i;

      if (i % 2 == 1) {
        b[i] = -b[i];
      }
    }

    auto ret = convolve(a, b);
    ret.resize(N + 1);

    return ret;
  }
}  // namespace haar_lib
