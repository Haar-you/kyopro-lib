#pragma once
#include <cstddef>

namespace haar_lib {
  template <typename Container, typename T = typename Container::value_type>
  bool ends_with(const Container &str, const Container &suffix) {
    if (str.size() < suffix.size()) return false;
    int n = str.size(), m = suffix.size();
    for (size_t i = 0; i < suffix.size(); ++i) {
      if (str[n - 1 - i] != suffix[m - 1 - i]) return false;
    }
    return true;
  }
}  // namespace haar_lib
