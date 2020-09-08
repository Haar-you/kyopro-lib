#pragma once
#include <cmath>
#include <vector>

/**
 * @title Partition number (Enumerate $P(n, n)$)
 * @docs partition_number_n.md
 */
namespace haar_lib {
  template <typename T>
  auto partition_number(int N){
    std::vector<T> p(N + 1);

    p[0] = 1;

    for(int i = 1; i <= N; ++i){
      int s = sqrt(1 + 24 * i);

      for(int j = 1; j <= (1 + s) / 6; ++j){
        p[i] += p[i - j * (3 * j - 1) / 2] * (j % 2 ? 1 : -1);
      }

      for(int j = 1; j <= (-1 + s) / 6; ++j){
        p[i] += p[i - j * (3 * j + 1) / 2] * (j % 2 ? 1 : -1);
      }
    }

    return p;
  }
}
