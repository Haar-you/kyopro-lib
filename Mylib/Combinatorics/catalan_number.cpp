#pragma once
#include <cstdint>
#include "Mylib/Combinatorics/factorial_table.cpp"

namespace haar_lib {
  template <typename Ft, typename T = typename Ft::value_type>
  T catalan_number(int64_t n, const Ft &ft){
    return ft.C(2 * n, n) - ft.C(2 * n, n - 1);
  }
}
