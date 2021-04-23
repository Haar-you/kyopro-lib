#pragma once
#include <algorithm>
#include <vector>

namespace haar_lib {
  std::vector<int64_t> convert_base_to(int64_t val, int64_t base) {
    if (val == 0) return {0};

    int b = std::abs(base);

    std::vector<int64_t> ret;
    while (val != 0) {
      int r = val % b;
      if (r < 0) r += b;
      val = (val - r) / base;
      ret.push_back(r);
    }

    std::reverse(ret.begin(), ret.end());

    return ret;
  }

  int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base) {
    int64_t ret = 0;
    for (auto it = val.begin(); it != val.end(); ++it) {
      (ret *= base) += *it;
    }

    return ret;
  }
}  // namespace haar_lib
