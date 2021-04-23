#pragma once
#include <algorithm>

namespace haar_lib {
  template <typename Iter>
  void rotate_right(Iter first, Iter last, int d) {
    std::rotate(first, last - d, last);
  }

  template <typename Iter>
  void rotate_left(Iter first, Iter last, int d) {
    std::rotate(first, first + d, last);
  }
}  // namespace haar_lib
