#pragma once
#include <bitset>
#include <utility>
#include <vector>

namespace haar_lib {
  template <size_t N>
  int gaussian_elimination(std::vector<std::bitset<N>> &m) {
    const int n = m.size();
    int rank    = 0;

    for (size_t j = 0; j < N; ++j) {
      int pivot = -1;

      for (int i = rank; i < n; ++i) {
        if (m[i][j]) {
          pivot = i;
          break;
        }
      }

      if (pivot == -1) continue;

      std::swap(m[pivot], m[rank]);

      for (int i = 0; i < n; ++i) {
        if (i != rank and m[i][j]) m[i] ^= m[rank];
      }
      ++rank;
    }

    return rank;
  }

  template <size_t N>
  int gaussian_elimination(std::vector<std::bitset<N>> &&m) {
    return gaussian_elimination(m);
  }
}  // namespace haar_lib
