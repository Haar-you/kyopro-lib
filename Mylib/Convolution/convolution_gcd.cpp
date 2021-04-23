#pragma once
#include <cassert>
#include <vector>

namespace haar_lib {
  template <typename T>
  auto divisor_zeta_transform(std::vector<T> f) {
    const int N = f.size();
    std::vector<bool> check(N, true);
    for (int i = 2; i < N; ++i) {
      if (check[i]) {
        for (int j = (N - 1) / i; j > 0; --j) {
          check[j * i] = false;
          f[j] += f[j * i];
        }
      }
    }
    return f;
  }

  template <typename T>
  auto divisor_mobius_transform(std::vector<T> f) {
    const int N = f.size();
    std::vector<bool> check(N, true);
    for (int i = 2; i < N; ++i) {
      if (check[i]) {
        for (int j = 1; j * i < N; ++j) {
          check[j * i] = false;
          f[j] -= f[j * i];
        }
      }
    }
    return f;
  }

  template <typename T>
  std::vector<T> convolution_gcd(std::vector<T> f, std::vector<T> g) {
    const int N = f.size();
    assert(f.size() == g.size());

    std::vector<T> ret(N);
    for (int i = 1; i < N; ++i) ret[i] += f[i] + g[i];

    f = divisor_zeta_transform(f);
    g = divisor_zeta_transform(g);
    for (int i = 0; i < N; ++i) f[i] *= g[i];
    f = divisor_mobius_transform(f);
    for (int i = 0; i < N; ++i) ret[i] += f[i];
    return ret;
  }
}  // namespace haar_lib
