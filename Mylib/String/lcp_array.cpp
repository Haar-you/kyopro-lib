#pragma once
#include <vector>
#include "Mylib/String/suffix_array.cpp"

namespace haar_lib {
  template <typename T>
  auto lcp_array(const suffix_array<T> &sa) {
    const int n = sa.size();
    std::vector<int> rank(n), ret(n);

    for (int i = 0; i < n; ++i) rank[sa[i]] = i;

    int h = 0;
    for (int i = 0; i < n; ++i) {
      if (rank[i] == 0) continue;
      const int j = sa[rank[i] - 1];

      if (h) --h;
      while (j + h < n and i + h < n) {
        if (sa.str()[j + h] != sa.str()[i + h]) break;
        ++h;
      }

      ret[rank[i]] = h;
    }

    return ret;
  }
}  // namespace haar_lib
