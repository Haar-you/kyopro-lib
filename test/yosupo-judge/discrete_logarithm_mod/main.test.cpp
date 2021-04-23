#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Number/Mod/mod_log.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T;
  std::cin >> T;

  for (auto [X, Y, M] : hl::input_tuples<int, int, int>(T)) {
    std::cout << hl::mod_log(X, Y, M).value_or(-1) << "\n";
  }

  return 0;
}
