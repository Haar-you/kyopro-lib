#pragma once
#include <vector>

namespace haar_lib {
  template <typename T, typename Poly>
  auto multipoint_evaluation(Poly a, std::vector<T> p) {
    const int M = p.size();
    std::vector<T> ret(M);

    int k = 1;
    while (k < M) k *= 2;

    std::vector<Poly> f(k * 2, {1});

    for (int i = 0; i < M; ++i) f[i + k] = {-p[i], 1};
    for (int i = k - 1; i >= 1; --i) f[i] = f[i << 1 | 0] * f[i << 1 | 1];

    f[1] = a % f[1];

    for (int i = 2; i < k + M; ++i) f[i] = f[i >> 1] % f[i];
    for (int i = 0; i < M; ++i) ret[i] = f[k + i][0];

    return ret;
  }
}  // namespace haar_lib
