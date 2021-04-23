#pragma once
#include <vector>

namespace haar_lib {
  template <typename T>
  std::vector<T> montmort_number(int n) {
    std::vector<T> ret(n + 1);

    ret[0] = 1;
    ret[1] = 0;
    ret[2] = 1;

    for (int i = 3; i <= n; ++i) {
      ret[i] = (ret[i - 1] + ret[i - 2]) * (i - 1);
    }

    return ret;
  }
}  // namespace haar_lib
