#pragma once
#include <cstdint>
#include <utility>
#include <vector>

namespace haar_lib {
  template <typename Container, typename T = typename Container::value_type>
  auto run_length_encoding(const Container &v) -> std::vector<std::pair<T, int64_t>> {
    std::vector<std::pair<T, int64_t>> ret;

    for (auto &x : v) {
      if (ret.empty())
        ret.emplace_back(x, 1);
      else if (ret.back().first == x)
        ++ret.back().second;
      else
        ret.emplace_back(x, 1);
    }

    return ret;
  }
}  // namespace haar_lib
