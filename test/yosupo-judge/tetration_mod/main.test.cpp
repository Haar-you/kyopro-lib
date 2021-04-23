#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Number/tetration.cpp"

namespace hl = haar_lib;

int main() {
  int T;
  std::cin >> T;

  for (auto [A, B, M] : hl::input_tuples<int, int, int>(T)) {
    auto ans = hl::tetration(A, B, M);
    std::cout << ans << "\n";
  }

  return 0;
}
