#pragma once
#include <cassert>
#include <functional>
#include <vector>

namespace haar_lib {
  template <typename T, typename Func = std::minus<T>>
  std::vector<T> fast_mobius_transform_subset(std::vector<T> f, const Func &op = std::minus<T>()) {
    const int N = f.size();
    assert((N & (N - 1)) == 0 && "N must be a power of 2");
    for (int i = 1; i < N; i <<= 1) {
      for (int j = 0; j < N; ++j) {
        if (j & i) f[j] = op(f[j], f[j ^ i]);
      }
    }
    return f;
  }
}  // namespace haar_lib
