#pragma once
#include <cassert>
#include <vector>

namespace haar_lib {
  template <typename T>
  std::vector<T> convolution_xor(std::vector<T> f, std::vector<T> g) {
    const int n = f.size();
    assert((int) f.size() == n and (int) g.size() == n and (n & (n - 1)) == 0);

    auto fwt =
        [n](std::vector<T> f) {
          for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; ++j) {
              if ((j & i) == 0) {
                auto x = f[j], y = f[j | i];
                f[j]     = x + y;
                f[j | i] = x - y;
              }
            }
          }
          return f;
        };

    auto ifwt =
        [n](std::vector<T> f) {
          for (int i = 1; i < n; i <<= 1) {
            for (int j = 0; j < n; ++j) {
              if ((j & i) == 0) {
                auto x = f[j], y = f[j | i];
                f[j]     = (x + y) / 2;
                f[j | i] = (x - y) / 2;
              }
            }
          }
          return f;
        };

    f = fwt(f);
    g = fwt(g);

    for (int i = 0; i < n; ++i) f[i] *= g[i];

    f = ifwt(f);

    return f;
  }
}  // namespace haar_lib
