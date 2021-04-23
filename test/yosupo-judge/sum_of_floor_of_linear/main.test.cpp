#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Math/sum_of_floor_of_linear.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int T;
  std::cin >> T;

  for (auto [N, M, A, B] : hl::input_tuples<int64_t, int64_t, int64_t, int64_t>(T)) {
    std::cout << hl::sum_of_floor_of_linear(N, M, A, B) << "\n";
  }

  return 0;
}
