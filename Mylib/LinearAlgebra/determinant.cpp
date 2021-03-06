#pragma once
#include <utility>

namespace haar_lib {
  template <typename M, typename T = typename M::value_type>
  T determinant(M m) {
    const int N = m.size();

    int s = 0;
    for (int i = 0; i < N; ++i) {
      if (m[i][i] == 0) {
        for (int j = i + 1; j < N; ++j) {
          if (m[j][i] != 0) {
            std::swap(m[i], m[j]);
            (s += 1) %= 2;
            break;
          }
          if (j == N - 1) return 0;
        }
      }

      for (int j = i + 1; j < N; ++j) {
        T t = m[j][i] / m[i][i];
        for (int k = 0; k < N; ++k) m[j][k] -= m[i][k] * t;
      }
    }

    T ret = s ? -1 : 1;
    for (int i = 0; i < N; ++i) ret *= m[i][i];
    return ret;
  }
}  // namespace haar_lib
