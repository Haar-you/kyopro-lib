#pragma once
#include <cassert>
#include <vector>
#include "Mylib/Convolution/fast_mobius_transform_subset.cpp"
#include "Mylib/Convolution/fast_zeta_transform_subset.cpp"

namespace haar_lib {
  template <typename T>
  std::vector<T> subset_convolution(std::vector<T> f, std::vector<T> g) {
    const int N = f.size();
    assert((N & (N - 1)) == 0 && "N must be a power of 2");
    assert(f.size() == g.size());

    const int K = __builtin_ctz(N);

    std::vector<std::vector<T>> F(K + 1), G(K + 1);

    for (int i = 0; i <= K; ++i) {
      F[i].resize(N);
      G[i].resize(N);

      for (int j = 0; j < N; ++j) {
        if (__builtin_popcount(j) == i) {
          F[i][j] = f[j];
          G[i][j] = g[j];
        }
      }

      F[i] = fast_zeta_transform_subset(F[i]);
      G[i] = fast_zeta_transform_subset(G[i]);
    }

    std::vector<std::vector<T>> H(K + 1, std::vector<T>(N));
    for (int i = 0; i <= K; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int s = 0; s <= i; ++s) {
          H[i][j] += F[s][j] * G[i - s][j];
        }
      }
    }

    std::vector<T> ret(N);

    for (int i = 0; i <= K; ++i) {
      auto h = fast_mobius_transform_subset(H[i]);
      for (int j = 0; j < N; ++j) {
        if (__builtin_popcount(j) == i) ret[j] += h[j];
      }
    }

    return ret;
  }
}  // namespace haar_lib
