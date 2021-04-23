#pragma once
#include <algorithm>
#include <tuple>
#include <vector>

namespace haar_lib {
  template <typename... Args>
  auto zip(std::vector<Args>... a) {
    const int N = std::min({a.size()...});
    std::vector<std::tuple<Args...>> ret(N);

    for (int i = 0; i < N; ++i) {
      ret[i] = std::make_tuple(a[i]...);
    }

    return ret;
  }
}  // namespace haar_lib
