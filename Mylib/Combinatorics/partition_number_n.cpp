#pragma once
#include <cmath>
#include <vector>

namespace haar_lib {
  template <typename T>
  std::vector<T> partition_number_n(int N){
    std::vector<T> p(N + 1);

    p[0] = 1;

    for(int i = 1; i <= N; ++i){
      int s = std::sqrt(1 + 24 * i);

      for(int j = 1; j <= (s + 1) / 6; ++j){
        p[i] += p[i - j * (3 * j - 1) / 2] * (j % 2 ? 1 : -1);
      }

      for(int j = 1; j <= (s - 1) / 6; ++j){
        p[i] += p[i - j * (3 * j + 1) / 2] * (j % 2 ? 1 : -1);
      }
    }

    return p;
  }
}
