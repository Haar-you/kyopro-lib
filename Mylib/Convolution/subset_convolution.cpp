#pragma once
#include <vector>
#include <cassert>
#include "Mylib/Convolution/fast_mobius_transform_subset.cpp"

namespace haar_lib {
  template <typename T>
  auto ranked_zeta_transform_subset(std::vector<T> f, int k){
    const int N = f.size();
    assert((N & (N - 1)) == 0 && "N must be a power of 2");
    for(int i = 0; i < N; ++i) if(__builtin_popcount(i) != k) f[i] = 0;
    for(int i = 1; i < N; i <<= 1){
      for(int j = 0; j < N; ++j){
        if((j & i)){
          f[j] = f[j] + f[j ^ i];
        }
      }
    }
    return f;
  }

  template <typename T>
  std::vector<T> subset_convolution(std::vector<T> f, std::vector<T> g){
    const int N = f.size();
    assert((N & (N - 1)) == 0 && "N must be a power of 2");
    assert(f.size() == g.size());

    const int K = __builtin_ctz(N);

    std::vector<std::vector<T>> F(K + 1), G(K + 1);

    for(int i = 0; i <= K; ++i){
      F[i] = ranked_zeta_transform_subset(f, i);
      G[i] = ranked_zeta_transform_subset(g, i);
    }

    std::vector<std::vector<T>> H(K + 1, std::vector<T>(N));
    for(int i = 0; i <= K; ++i){
      for(int j = 0; j < N; ++j){
        for(int s = 0; s <= i; ++s){
          H[i][j] += F[s][j] * G[i - s][j];
        }
      }
    }

    std::vector<T> ret(N);

    for(int i = 0; i <= K; ++i){
      auto h = fast_mobius_transform_subset(H[i]);
      for(int j = 0; j < N; ++j){
        if(__builtin_popcount(j) == i) ret[j] += h[j];
      }
    }

    return ret;
  }
}
