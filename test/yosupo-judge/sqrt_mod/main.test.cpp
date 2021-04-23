#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Number/Mod/mod_sqrt.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T;
  std::cin >> T;
  for (auto [Y, P] : hl::input_tuples<int64_t, int64_t>(T)) {
    std::cout << hl::mod_sqrt(Y, P).value_or(-1) << "\n";
  }
  return 0;
}
