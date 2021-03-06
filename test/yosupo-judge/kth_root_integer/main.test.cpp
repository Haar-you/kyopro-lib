#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Number/kth_root_integer.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T;
  std::cin >> T;

  for (auto [A, K] : hl::input_tuples<uint64_t, uint64_t>(T)) {
    std::cout << hl::kth_root(A, K) << "\n";
  }

  return 0;
}
