#pragma once
#include <cstdint>
#include "Mylib/Combinatorics/factorial_table.cpp"

namespace haar_lib {
  template <const auto &ft>
  auto catalan_number(int64_t n) {
    return ft.C(2 * n, n) - ft.C(2 * n, n - 1);
  }
}  // namespace haar_lib
