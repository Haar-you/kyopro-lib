#pragma once
#include <algorithm>
#include <vector>

namespace haar_lib {
  template <typename Container>
  std::vector<int> z_algorithm(const Container &s) {
    const int n = s.size();
    std::vector<int> ret(n, 0);
    int j = 0;

    for (int i = 1; i < n; ++i) {
      if (i + ret[i - j] < j + ret[j]) {
        ret[i] = ret[i - j];
      } else {
        int k = std::max<int>(0, j + ret[j] - i);
        while (i + k < n and s[k] == s[i + k]) ++k;
        ret[i] = k;
        j      = i;
      }
    }

    ret[0] = n;

    return ret;
  }
}  // namespace haar_lib
