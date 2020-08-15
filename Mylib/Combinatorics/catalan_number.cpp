#pragma once
#include "Mylib/Combinatorics/factorial_table.cpp"

/**
 * @title Catalan number
 * @docs catalan_number.md
 */
template <typename T, typename Ft>
T catalan_number(const Ft &ft, int64_t n){
  return ft.C(2 * n, n) - ft.C(2 * n, n - 1);
}
